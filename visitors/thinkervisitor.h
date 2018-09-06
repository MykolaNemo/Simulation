#ifndef THINKER_H
#define THINKER_H

#include <memory>

class Field;
class FieldObject;
//class Sheep;
//class Grass;
//class StateAbstract;
//class AnimalStateEating;
//class AnimalStateIdle;
//class AnimalStateWalking;
//class PlantStateGrowing;
//class PlantStateNotGrowing;

class ThinkerInfo
{
public:
    ThinkerInfo() = default;
    void setField(const std::shared_ptr<Field>& _field);
    std::shared_ptr<Field> getField() const;
    void setThinkingObject(const std::shared_ptr<FieldObject>& obj);
    std::shared_ptr<FieldObject> getThinkingObject() const;

//    void thinkFor(const std::shared_ptr<Sheep> &sheep) const;
//    void thinkFor(const std::shared_ptr<Grass> &grass) const ;


private:
    std::shared_ptr<Field> m_field;
    std::shared_ptr<FieldObject> m_thinkingObject;

//    std::shared_ptr<StateAbstract> createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                  const std::shared_ptr<AnimalStateEating> &state);
//    std::shared_ptr<StateAbstract> createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                  const std::shared_ptr<AnimalStateIdle> &state);
//    std::shared_ptr<StateAbstract> createStateFor(const std::shared_ptr<Sheep> &sheep,
//                                                  const std::shared_ptr<AnimalStateWalking> &state);

//    std::shared_ptr<StateAbstract> createStateFor(const std::shared_ptr<Grass> &grass,
//                                                  const std::shared_ptr<PlantStateGrowing> &state);
//    std::shared_ptr<StateAbstract> createStateFor(const std::shared_ptr<Grass> &grass,
//                                                  const std::shared_ptr<PlantStateNotGrowing> &state);
};

#endif // THINKER_H
