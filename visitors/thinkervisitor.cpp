#include "visitors/thinkervisitor.h"
#include "models/field.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"
#include "state/animalstates/animalstateeating.h"
#include "state/animalstates/animalstateidle.h"
#include "state/animalstates/animalstatewalking.h"
#include "state/plantstates/plantstategrowing.h"
#include "state/plantstates/plantstatenotgrowing.h"

#include <stdexcept>
#include <iostream>

void ThinkerInfo::setField(const std::shared_ptr<Field> &field)
{
    m_field = field;
}

std::shared_ptr<Field> ThinkerInfo::getField() const
{
    return m_field;
}

void ThinkerInfo::setThinkingObject(const std::shared_ptr<FieldObject> &object)
{
    m_thinkingObject = object;
}

std::shared_ptr<FieldObject> ThinkerInfo::getThinkingObject() const
{
    return m_thinkingObject;
}

//void ThinkerInfo::thinkFor(const std::shared_ptr<Sheep> &sheep) const
//{
//    if(!sheep || !m_field) return;

//    std::shared_ptr<StateAbstract> state = sheep->getState();
//    auto nextState = state->next();
//    createStateFor(sheep, nextState);
//    sheep->setState(nextState);
//}

//std::shared_ptr<StateAbstract> ThinkerVisitor::createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                              const std::shared_ptr<AnimalStateEating>& state)
//{
//    return std::make_shared<AnimalStateEating>();
//}

//std::shared_ptr<StateAbstract> ThinkerVisitor::createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                              const std::shared_ptr<AnimalStateIdle>& state)
//{
//    return std::make_shared<AnimalStateIdle>();
//}

//std::shared_ptr<StateAbstract> ThinkerVisitor::createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                              const std::shared_ptr<AnimalStateWalking>& state)
//{
//    auto closest = m_field->getClosestObject(sheep->getPosition(), typeid(Grass));
//    return std::make_shared<AnimalStateWalking>(sheep->getPosition(), closest->getPosition());
//}

//void ThinkerInfo::thinkFor(const std::shared_ptr<Grass> &grass) const
//{
//    std::shared_ptr<StateAbstract> state = grass->getState();
//    auto nextState = state->next();
//    createStateFor(grass, nextState);
//    grass->setState(nextState);
//}

//std::shared_ptr<StateAbstract> ThinkerVisitor::createStateFor(const std::shared_ptr<Grass> &grass,
//                                                              const std::shared_ptr<PlantStateGrowing>& state)
//{
//    return std::make_shared<PlantStateNotGrowing>();
//}

//std::shared_ptr<StateAbstract> ThinkerVisitor::createStateFor(const std::shared_ptr<Grass> &grass,
//                                                              const std::shared_ptr<PlantStateNotGrowing>& state)
//{
//    return std::make_shared<PlantStateGrowing>();
//}
