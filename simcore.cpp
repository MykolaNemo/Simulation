#include "simcore.h"
#include "models/field.h"

#include <iostream>
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
    auto time = std::chrono::system_clock::now();
    QElapsedTimer t;
    while(!m_interrupt.load())
    {
        auto now = std::chrono::system_clock::now();
        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);
        t.start();
        field->updateObjects(tickDuration);
        std::cout<<"Elapsed: "<<t.elapsed()<<std::endl;
        time = now;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
