#include <gtest/gtest.h>

#include <Math/Mat4.h>
#include <Math/Vec2.h>

using namespace eon::math;

TEST(Matrix4Test, Multiplication) {
  Mat4 matrix1(1.0f);
  matrix1.Set(0, 1, 5.0f);
  Mat4 matrix2(2.0f);

  Mat4 result = matrix1 * matrix2;

  EXPECT_EQ(result.Get(0, 0), 2.0f);
  EXPECT_EQ(result.Get(0, 1), 10.0f);
}

TEST(Vec2Test, Addition) {
  Vec2 vec1(1.0f, 0.5f);
  Vec2 vec2(0.6f, 0.6f);

  Vec2 result = vec1 + vec2;

  EXPECT_EQ(result.x, 1.6f);
  EXPECT_EQ(result.y, 1.1f);
}
