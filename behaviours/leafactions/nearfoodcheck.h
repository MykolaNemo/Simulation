#ifndef NEARFOODCHECK_H
#define NEARFOODCHECK_H

#include "../behaviourtree.h"
#include <QRect>

class NearFoodCheck: public BehaviourTree
{
public:
    explicit NearFoodCheck(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &) override;

    void setFoodRect(const QRect &rect);
    void setEaterRect(const QRect &rect);

private:
    QRect foodRect;
    QRect eaterRect;
};

#endif // NEARFOODCHECK_H
