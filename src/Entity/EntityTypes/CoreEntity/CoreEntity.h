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

        CoreEntity(EntityRig entRig, glm::vec3 pos, glm::vec3 orient);

        void updatePosition();
        const Hitbox::OBB& getOBB() const { return entityRig.obb;}
        
        virtual void Draw(Shader& shader);

};

#endif