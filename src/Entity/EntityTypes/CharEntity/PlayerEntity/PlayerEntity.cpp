#include <glm/glm.hpp>

#include "PlayerEntity.h"
#include "Renderable/Renderable.h"

PlayerEntity::PlayerEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient) : CoreCharEntity(entRig, pos, orient){}

