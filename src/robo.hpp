#pragma once
#include <cmath>

namespace robo {
struct Vec3 {
  double x{0}, y{0}, z{0};
  Vec3 operator+(const Vec3& o) const { return {x + o.x, y + o.y, z + o.z}; }
  Vec3 operator-(const Vec3& o) const { return {x - o.x, y - o.y, z - o.z}; }
  Vec3 operator*(double s) const { return {x * s, y * s, z * s}; }
  double dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
  Vec3 cross(const Vec3& o) const;
  double norm() const { return std::sqrt(dot(*this)); }
};
}  // namespace robo
