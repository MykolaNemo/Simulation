#if 0
#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <functional>
#include <algorithm>

class SlotId
{
public:
    explicit SlotId(int _id):id(_id){}
private:
    int id;
};

template <typename... Args>
class Signal
{
public:
    Signal():currentId(0)
    {}

    template<typename T>
    SlotId connect(T* slotCaller, void(T::*f)(Args...))
    {
        SlotId id(currentId);
        slotsMap.insert(std::make_pair<SlotId, std::function<void(Args...)>>(
        id,[=](Args... args){
            (slotCaller->*f)(args...);
        }));
        return id;
    }

    void disconnectAll()
    {
        slotsVector.clear();
    }

    void disconnect(SlotId& id)
    {
//        slotsVector.erase(std::remove(slotsVector.begin(), slotsVector.end(), f), slotsVector.end());
    }

//    void fire()
//    {
//        for(const auto& f : slotsVector)
//        {
//            f();
//        }
//    }

private:
    int currentId;
    mutable std::map<SlotId, std::function<void(Args...)>> slotsMap;
};

#endif // SIGNAL_H
#endif
