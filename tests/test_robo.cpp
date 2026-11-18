#include <gtest/gtest.h>
#include "robo.hpp"

TEST(Vec3, CrossOfXandYisZ) {
  robo::Vec3 x{1, 0, 0}, y{0, 1, 0};
  auto z = x.cross(y);
  EXPECT_DOUBLE_EQ(z.x, 0);
  EXPECT_DOUBLE_EQ(z.y, 0);
  EXPECT_DOUBLE_EQ(z.z, 1);
}
