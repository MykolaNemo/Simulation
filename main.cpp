#include <QtWidgets/QApplication>

#include <iostream>
#include <algorithm>

#include "fieldview.h"
#include "simcore.h"
#include "models/field.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"
#include "scene.h"

std::shared_ptr<Field> createField()
{
    const int fieldWidth = 600;
    const int fieldHeight = 400;

    const auto sheeps = [](){
        std::vector<std::shared_ptr<FieldObject>> v;
        v.reserve(1000);
        for(int i = 0; i < 50; ++i)
        {
            v.emplace_back(Sheep::create());
        }
        return v;
    }();

    const auto grass = []{
        std::vector<std::shared_ptr<FieldObject>> v;
        v.reserve(1000);
        for(int i = 0; i < 150; ++i)
        {
            v.emplace_back(Grass::create());
        }
        return v;
    }();

    auto field = std::make_shared<Field>(fieldWidth, fieldHeight);
    field->addObjects(sheeps);
    field->addObjects(grass);
    return field;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<Field> field = createField();
    std::shared_ptr<Scene> scene = Scene::create(field);

    FieldView view(scene.get());
    view.resize(scene->sceneRect().size().toSize());
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();

    SimCore simCore(field);
    QObject::connect(&view, &FieldView::aboutToClose, [&simCore](){
        simCore.join();
    });

    simCore.start();

    return a.exec();
}
