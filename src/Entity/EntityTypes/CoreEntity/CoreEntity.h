#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "Renderable/Renderable.h"
#include "EntityRig.h"
#include "WorldContext.h"

class CoreEntity
{
    protected:
    std::vector<CoreEntity*>& getCollidables()
    {
        return *WorldContext::s_instance->collidables;
    }


    public:
        EntityRig entityRig;
        glm::vec3 position;
        glm::vec3 orientation;    

        CoreEntity(EntityRig entRig, glm::vec3 pos = glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3 orient = glm::vec3{0.0f, 0.0f, 1.0f});
        virtual ~CoreEntity() = default;
        virtual bool isAlive() const { return true; }

        void updatePosition();
        const Hitbox::OBB& getOBB() const { return entityRig.obb;}

        void aimAt(CoreEntity* target);

        void enemyInteraction();
        
        virtual void Draw(Shader& shader);

};

#endif