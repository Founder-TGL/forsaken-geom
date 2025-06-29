#include <glm/glm.hpp>

#include "CoreCharEntity.h"
#include "Renderable/Renderable.h"

CoreCharEntity::CoreCharEntity(EntityRig entRig, int health, std::vector<CoreEntity>* collidables, glm::vec3 pos, glm::vec3 orient) : CoreEntity(entRig, pos, orient), health(health){}

