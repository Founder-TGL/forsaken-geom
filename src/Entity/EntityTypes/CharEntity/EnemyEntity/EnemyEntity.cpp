#include "EnemyEntity/EnemyEntity.h"

#include <glm/glm.hpp>

EnemyEntity::EnemyEntity(EntityRig entRig, int health , float speed, float detectionRange, glm::vec3 pos , glm::vec3 orient ) 
: CoreCharEntity(entRig, health,speed, pos, orient), detectionRange(detectionRange) {}

