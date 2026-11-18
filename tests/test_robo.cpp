#include <gtest/gtest.h>
#include "robo.hpp"

// X × Y should equal Z (right-hand rule)
TEST(Vec3, CrossOfXandYisZ) {
  robo::Vec3 x{1, 0, 0}, y{0, 1, 0};
  auto z = x.cross(y);
  EXPECT_DOUBLE_EQ(z.x, 0);
  EXPECT_DOUBLE_EQ(z.y, 0);
  EXPECT_DOUBLE_EQ(z.z, 1);
}

// Swapping the order flips the sign: a × b = -(b × a)
TEST(Vec3, CrossIsAntiCommutative) {
  robo::Vec3 a{1, 2, 3}, b{4, 5, 6};
  auto ab = a.cross(b);
  auto ba = b.cross(a);
  EXPECT_DOUBLE_EQ(ab.x, -ba.x);
  EXPECT_DOUBLE_EQ(ab.y, -ba.y);
  EXPECT_DOUBLE_EQ(ab.z, -ba.z);
}

// The cross product is perpendicular to both inputs, so its dot with each is 0
TEST(Vec3, CrossIsPerpendicularToBoth) {
  robo::Vec3 a{1, 2, 3}, b{4, 5, 6};
  auto c = a.cross(b);
  EXPECT_NEAR(c.dot(a), 0.0, 1e-12);
  EXPECT_NEAR(c.dot(b), 0.0, 1e-12);
}

// Perpendicular vectors have a dot product of 0
TEST(Vec3, DotOfPerpendicularIsZero) {
  robo::Vec3 a{1, 0, 0}, b{0, 1, 0};
  // TODO: one line. Check that a.dot(b) equals 0
  EXPECT_DOUBLE_EQ(a.dot(b), 0);
}

// A 3-4-5 triangle: the length of {3,4,0} is 5
TEST(Vec3, NormOf345Is5) {
  robo::Vec3 v{3, 4, 0};
  // TODO: one line. Check that v.norm() equals 5
  EXPECT_DOUBLE_EQ(v.norm(), 5);
}

// ({1,2,3} + {1,1,1}) * 2 should be {4,6,8}
TEST(Vec3, AddAndScale) {
  robo::Vec3 a{1, 2, 3}, b{1, 1, 1};
  auto r = (a + b) * 2;
  // TODO: three lines. Check r.x, r.y, r.z
  EXPECT_DOUBLE_EQ(r.x, 4);
  EXPECT_DOUBLE_EQ(r.y, 6);
  EXPECT_DOUBLE_EQ(r.z, 8);
}