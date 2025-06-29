#include "hitBox.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

namespace Hitbox {

void OBB::setFromTransform(
  const glm::vec3& position,
  const glm::vec3& eulerAngles,
  const glm::vec3& scale,
  const glm::vec3& localHalfExtents
) {
  glm::mat4 model = glm::mat4(1.0f);

  // Apply transformation: T * Rx * Ry * Rz * S
  model = glm::translate(model, position);
  model = glm::rotate(model, eulerAngles.x, glm::vec3(1, 0, 0));
  model = glm::rotate(model, eulerAngles.y, glm::vec3(0, 1, 0));
  model = glm::rotate(model, eulerAngles.z, glm::vec3(0, 0, 1));
  model = glm::scale(model, scale);

  center = glm::vec3(model[3]); // extract translation

  // extract rotated axes from matrix columns 0–2
  for (int i = 0; i < 3; ++i)
    axes[i] = glm::normalize(glm::vec3(model[i]));

  halfExtents = localHalfExtents * scale;
}

bool isOverlappingOnAxis(
  const OBB& a,
  const OBB& b,
  const glm::vec3& axis
) {
  float len2 = glm::dot(axis, axis);
  if (len2 < 1e-8f) return true;

  glm::vec3 n = glm::normalize(axis);

  float rA = 0.0f, rB = 0.0f;
  for (int i = 0; i < 3; ++i) {
    rA += a.halfExtents[i] * std::abs(glm::dot(a.axes[i], n));
    rB += b.halfExtents[i] * std::abs(glm::dot(b.axes[i], n));
  }

  float dist = std::abs(glm::dot(b.center - a.center, n));
  return dist <= (rA + rB);
}

bool doOBBsIntersect(const OBB& a, const OBB& b) {
  for (int i = 0; i < 3; ++i)
    if (!isOverlappingOnAxis(a, b, a.axes[i]))
      return false;

  for (int i = 0; i < 3; ++i)
    if (!isOverlappingOnAxis(a, b, b.axes[i]))
      return false;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      glm::vec3 axis = glm::cross(a.axes[i], b.axes[j]);
      if (!isOverlappingOnAxis(a, b, axis))
        return false;
    }
  }

  return true; // no separating axis found
}

void debugDraw(const OBB& box, const glm::mat4& MVP) // TODO: GET THIS WORKING
{
//   glm::vec3 corners[8];
// for (int i = 0; i < 8; ++i)
// {
//     float sx = (i & 1) ? +1.0f : -1.0f;
//     float sy = (i & 2) ? +1.0f : -1.0f;
//     float sz = (i & 4) ? +1.0f : -1.0f;

//     glm::vec3 offset =
//         sx * box.axes[0] * box.halfExtents.x +
//         sy * box.axes[1] * box.halfExtents.y +
//         sz * box.axes[2] * box.halfExtents.z;

//     corners[i] = box.center + offset;
// }
  
}

} // namespace Hitbox