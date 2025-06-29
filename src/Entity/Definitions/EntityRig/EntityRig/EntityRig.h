#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Renderable/Renderable.h"
#include "hitBox.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>


class EntityRig {
public:
  // ctor: takes ownership of a mesh
  EntityRig(Renderable mesh);

  // set transform
  void setPosition(const glm::vec3& p)   { position = p; }
  void setOrientation(const glm::vec3& o){ orientation = o; }
  void setScale(const glm::vec3& s)      { scale = s; }

  // update mesh & hitbox
  void update();

  // draw the mesh
  void Draw(Shader& shader);

  // access for collisions
  const Hitbox::OBB& getOBB() const { return obb; }
  
  void computeLocalBounds();   // read mesh verts → localHalfExtents

  bool wouldCollide(const glm::vec3& newPos, const EntityRig& other);

  Renderable mesh;             // visual
  glm::vec3  position;         // location
  glm::vec3  orientation = glm::vec3(0.0f, 0.0f, 1.0f);      
  glm::vec3  scale {1.0f};     

  glm::vec3  localHalfExtents; // cached from mesh
  Hitbox::OBB obb;             // runtime collision box

};

#endif