#include "BulletEntity.h"
#include "WorldContext.h"        
#include "hitBox.h"

BulletEntity::BulletEntity(EntityRig rig,int damage,float speed,const glm::vec3& pos,const glm::vec3& orient, CoreCharEntity* owner)
  : CoreEntity(std::move(rig), pos, orient), damage(damage), speed(speed), lifeTimeSeconds(0.0f) , owner(owner)
{
    updatePosition();  
}

void BulletEntity::travel(float dt)
{
  lifeTimeSeconds += dt;
  glm::vec3 projectedPosition = position + orientation * speed * dt;
  if (auto* hitChar = entityHit(projectedPosition)) {
    hitChar->health -= damage;
    alive = false;
  }
  position = projectedPosition;
  updatePosition();

}

CoreCharEntity* BulletEntity::entityHit(const glm::vec3& projectedPosition)
{
    Hitbox::OBB testOBB = getOBB();
    testOBB.center = projectedPosition;

    // auto& list = *WorldContext::Instance()->collidables;

    for (CoreEntity* ent : *WorldContext::Instance()->collidables) {
    if (ent == this || ent == owner)
        continue;

    if (Hitbox::doOBBsIntersect(testOBB, ent->getOBB())) {
        if (auto* charEnt = dynamic_cast<CoreCharEntity*>(ent))
        return charEnt;
    }
    }


    return nullptr;
}
