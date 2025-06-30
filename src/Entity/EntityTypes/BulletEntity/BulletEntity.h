#ifndef BULLET_ENTITY_H
#define BULLET_ENTITY_H

#include "CoreEntity.h"
#include "CoreCharEntity/CoreCharEntity.h"
#include "EntityRig.h"

class BulletEntity : public CoreEntity {
public:
    BulletEntity(EntityRig rig,int damage,float speed,const glm::vec3& pos,const glm::vec3& orient);

    void travel(float deltaTime);

private:
    int   damage;
    float speed;
    float lifeTimeSeconds = 0.0f;

    CoreCharEntity* entityHit(const glm::vec3& projectedPosition);
};

#endif 