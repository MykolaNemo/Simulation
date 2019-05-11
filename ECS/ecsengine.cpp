#include "ecsengine.h"

#include "models/field.h"

#include <iostream>
#include <QElapsedTimer>
#include "ECS/system.h"

ECSEngine::~ECSEngine()
{
    stop();
}

void ECSEngine::start()
{
    m_future = std::async(std::launch::async, [this] {
        this->mainLoop();
    });
}

void ECSEngine::stop()
{
    m_interrupt.store(true);
    std::future_status status;
    do
    {
        status = m_future.wait_for(std::chrono::milliseconds(0));
    }
    while(status != std::future_status::ready);
}

void ECSEngine::mainLoop()
{
    auto time = std::chrono::system_clock::now();
    QElapsedTimer t;
    while(!m_interrupt.load())
    {
        auto now = std::chrono::system_clock::now();
        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);

        t.start();
        for(auto& [priority,system] : systems)
        {
            for(auto& entity : entities)
            {
                system->update(tickDuration, entity);
            }
        }
        std::cout<<"Elapsed: "<<t.elapsed()<<std::endl;

        time = now;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void ECSEngine::addSystem(const std::shared_ptr<ISystem> &system, Priority priority)
{
    auto it = std::find_if(systems.begin(), systems.end(),
              [&priority](const std::pair<Priority, std::shared_ptr<ISystem> >& pair)->bool
    {
        return (pair.first >= priority);
    });

    if(it == systems.end())
    {
        systems.push_back({priority, system});
    }
    else
    {
        it = systems.insert(it, {priority, system});
        it++;
        while(it != systems.end())//update priorities
        {
            it->first++;
            it++;
        }
    }
}
