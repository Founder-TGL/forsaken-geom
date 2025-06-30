#ifndef ENEMY_ENTITY_H
#define ENEMY_ENTITY_H

#include "CoreCharEntity/CoreCharEntity.h"
#include "CoreEntity.h"

class EnemyEntity : public CoreCharEntity
{
    public: 
        float detectionRange;
        EnemyEntity(EntityRig entRig, int health , float speed, float detectionRange = 5.0f, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});

        bool targetDetection(CoreEntity* target);

    };

#endif