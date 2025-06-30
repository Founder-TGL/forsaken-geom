#include "BulletEntity.h"
#include "WorldContext.h"        
#include "HitBox/hitBox.h"       

BulletEntity::BulletEntity(EntityRig rig,int damage,float speed,const glm::vec3& pos,const glm::vec3& orient)
  : CoreEntity(std::move(rig), pos, orient), damage(damage), speed(speed), lifeTimeSeconds(0.0f)
{
    updatePosition();  
}

void BulletEntity::travel(float dt)
{
    // 1) compute the candidate position
    glm::vec3 projectedPosition = position + orientation * speed * dt;

    // 2) test for any CoreCharEntity collision at that spot
    if (auto* hitChar = entityHit(projectedPosition)) {
        hitChar->health -= damage;
        // you might also mark this bullet “dead” here…
    }

    // 3) commit position & sync the mesh
    position = projectedPosition;
    updatePosition();

    // 4) advance lifetime
    lifeTimeSeconds += dt;
}

CoreCharEntity* BulletEntity::entityHit(const glm::vec3& projectedPosition)
{
    // build a projected OBB
    Hitbox::OBB testOBB = getOBB();
    testOBB.center = projectedPosition;

    // test against every collidable
    for (CoreEntity* ent : WorldContext::Instance()->collidables) {
        if (ent == this) 
            continue;

        if (Hitbox::doOBBsIntersect(testOBB, ent->getOBB())) {
            // only return it if it’s actually a CoreCharEntity
            if (auto* charEnt = dynamic_cast<CoreCharEntity*>(ent))
                return charEnt;
        }
    }

    return nullptr;
}