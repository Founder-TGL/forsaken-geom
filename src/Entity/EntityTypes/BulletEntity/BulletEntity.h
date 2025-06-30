#ifndef BULLET_ENTITY_H
#define BULLET_ENTITY_H

#include "CoreEntity.h"
#include "CoreCharEntity/CoreCharEntity.h"
#include "EntityRig.h"

class BulletEntity : public CoreEntity {
    public:
        BulletEntity(EntityRig rig,int damage,float speed,const glm::vec3& pos,const glm::vec3& orient);

        void travel(float deltaTime);

        bool isAlive() const override {return lifeTimeSeconds < MAX_LIFE;}

    private:
        float lifeTimeSeconds = 0.0f;
        static constexpr float MAX_LIFE = 5.0f;
        int   damage;
        float speed;

        CoreCharEntity* entityHit(const glm::vec3& projectedPosition);
};

#endif 