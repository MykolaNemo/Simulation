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
//    while(!mInterrupt.load())
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(5));
//        auto now = std::chrono::system_clock::now();
//        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);
//        for(auto blackboardIt : blackboards)
//        {
//            for(auto tree : mTreesList)
//            {
//                tree->execute(tickDuration);
//            }
//        }
//    }
    auto time = std::chrono::system_clock::now();
    while(!m_interrupt.load())
    {
        auto now = std::chrono::system_clock::now();
        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);
        const auto objects = field->getObjects();
        for(const auto& object : objects)
        {
            object->update(*field.get(), tickDuration);
        }
        time = now;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
