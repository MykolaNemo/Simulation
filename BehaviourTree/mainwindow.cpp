#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"

#include <sstream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#ifdef _WIN64
#include <Windows.h>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->traverseButton, &QPushButton::clicked, [this](){

        std::string generatedString;
        traverseTree(mTreeRoot, generatedString);

        qDebug()<<"=================================";
        qDebug().noquote()<<QString::fromStdString(generatedString);
        qDebug()<<"=================================";
    });
    connect(ui->graphicsView, &GraphicsView::rootWasChanged, this, &MainWindow::onRootChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::tickGeneratorString(const std::string &name) const
{
    std::ostringstream stringStream;
    stringStream << "TickGenerator* " << name << " = new TickGenerator();\n";
    return stringStream.str();
}

std::string MainWindow::sequenceString(const std::string& name) const
{
    std::ostringstream stringStream;
    stringStream << "BehaviourTree* " << name << " = new Sequence(\""<<name<<"\");\n";
    return stringStream.str();
}

std::string MainWindow::fallbackString(const std::string& name) const
{
    std::ostringstream stringStream;
    stringStream << "BehaviourTree* " << name << " = new Fallback(\""<<name<<"\");\n";
    return stringStream.str();
}

std::string MainWindow::leafString(const std::string& name) const
{
    std::ostringstream stringStream;
    stringStream << "BehaviourTree* " << name << " = new Leaf(\""<<name<<"\");\n";
    return stringStream.str();
}

std::string MainWindow::childToParentNodeString(const std::string& parentName, const std::string& childName) const
{
    std::ostringstream stringStream;
    stringStream << parentName<< "->addChild(" << childName << ");\n";
    return stringStream.str();
}

std::string MainWindow::treeToTickGeneratorString(const std::string& generatorName, const std::string& childName) const
{
    std::ostringstream stringStream;
    stringStream << generatorName <<
                    "->addTree(std::shared_ptr<BehaviourTree>(" << childName<< "));\n";
    return stringStream.str();
}

std::string MainWindow::traverseTree(const std::shared_ptr<Tree>& tree, std::string& generatedString)
{
    static int sequenceNumber = 0;
    static int fallbackNumber = 0;
    static int leafNumber = 0;
    if(tree)
    {
        std::string currentName;
        switch (tree->getType())
        {
        case Tree::NodeType::TickGenerator:
        {
            currentName = "tickGenerator";
            generatedString += tickGeneratorString(currentName);
            break;
        }
        case Tree::NodeType::Sequence:
        {
            sequenceNumber++;
            std::ostringstream stream;
            stream << "sequence"<<sequenceNumber;
            currentName = stream.str();
            generatedString += sequenceString(currentName);
            break;
        }
        case Tree::NodeType::Fallback:
        {
            fallbackNumber++;
            std::ostringstream stream;
            stream << "fallback"<<fallbackNumber;
            currentName = stream.str();
            generatedString += fallbackString(currentName);
            break;
        }
        case Tree::NodeType::Leaf:
        {
            leafNumber++;
            std::ostringstream stream;
            stream << "leaf"<<leafNumber;
            currentName = stream.str();
            generatedString += leafString(currentName);
            break;
        }
        }

        for(const auto& child : tree->getChildren())
        {
            std::string childName = traverseTree(child, generatedString);
            if(tree->getType() == Tree::NodeType::TickGenerator)
            {
                generatedString += treeToTickGeneratorString(currentName, childName);
            }
            else
            {
                generatedString += childToParentNodeString(currentName, childName);
            }
        }
        return currentName;
    }
    return "";
}

void MainWindow::onRootChanged(const std::shared_ptr<Tree>& treeRoot)
{
    mTreeRoot = treeRoot;
}
