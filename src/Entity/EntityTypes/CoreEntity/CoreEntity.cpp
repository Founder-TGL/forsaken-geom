#include <glm/glm.hpp>

#include "CoreEntity.h"
#include "Renderable/Renderable.h"


CoreEntity::CoreEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient) : entityRig(std::move(entRig)), position(pos), orientation(orient){}

void CoreEntity::Draw(Shader& shader){entityRig.Draw(shader);}