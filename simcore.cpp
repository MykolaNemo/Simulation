#include "simcore.h"
#include "models/field.h"
#include "models/fieldobject.h"
#include "models/animal/animal.h"

#include <QDebug>
#include <stdexcept>
#include <iostream>
#include <thread>
#include <QElapsedTimer>

SimCore::SimCore(const std::shared_ptr<Field>& _field)
{
    if(!_field)
    {
        throw std::invalid_argument("SimCore::SimCore(field): field is null");
    }
    field = _field;
}

SimCore::~SimCore()
{
    join();
}

void SimCore::start()
{
    m_future = std::async(std::launch::async, [this] {
        this->mainLoop();
    });
}

void SimCore::join()
{
    m_interrupt.store(true);
    std::future_status status;
    do
    {
        status = m_future.wait_for(std::chrono::milliseconds(0));
    }
    while(status != std::future_status::ready);
}

void SimCore::mainLoop()
{
    while(!m_interrupt.load())
    {
        const auto objects = field->getObjects();
        QElapsedTimer t;
        t.start();
        for(const auto& object : objects)
        {
            object->update(*field.get());
        }
        std::cout<<"Whole update cycle: "<<t.elapsed()<<std::endl;
        std::cout<<"==================================="<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
