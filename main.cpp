#include <QtWidgets/QApplication>

#include "fieldview.h"
#include "models/field.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"
#include "scene.h"
#include "ECS/ecsengine.h"
#include "ECS/Systems/aisystem.h"

ECSEngine Engine;

std::shared_ptr<Field> createField()
{
    const int fieldWidth = 1000;
    const int fieldHeight = 600;

    const auto sheeps = [](){
        std::vector<std::shared_ptr<FieldObject>> v;
        const auto amount = 250;
        v.reserve(amount);
        for(auto i = 0; i < amount; ++i)
        {
            v.emplace_back(std::static_pointer_cast<FieldObject>(Engine.newEntity<Sheep>()));
        }
        return v;
    }();

    const auto grass = []{
        std::vector<std::shared_ptr<FieldObject>> v;
        const auto amount = 500;
        v.reserve(amount);
        for(auto i = 0; i < amount; ++i)
        {
            v.emplace_back(std::static_pointer_cast<FieldObject>(Engine.newEntity<Grass>()));
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

//    SimCore simCore(field);
//    QObject::connect(&view, &FieldView::aboutToClose, [&simCore](){
//        simCore.join();
//    });
//    simCore.start();

    auto aiSystem = std::make_shared<AISystem>();
    aiSystem->setField(field);
    Engine.addSystem(aiSystem, 1);

    QObject::connect(&view, &FieldView::aboutToClose, [](){
        Engine.stop();
    });
    Engine.start();

    return QApplication::exec();
}
