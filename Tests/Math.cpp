#include <gtest/gtest.h>

#include <Math/Mat4.h>
#include <Math/Vec2.h>
#include <Math/Vec3.h>
#include <Math/Vec4.h>

using namespace eon::math;

// Matrix tests

TEST(Matrix4Test, Multiplication) {
  Mat4 matrix1(1.0f);
  matrix1.Set(0, 1, 5.0f);
  Mat4 matrix2(2.0f);

  Mat4 result = matrix1 * matrix2;

  ASSERT_FLOAT_EQ(result.Get(0, 0), 2.0f);
  ASSERT_FLOAT_EQ(result.Get(0, 1), 10.0f);
}

// Vector tests

TEST(Vec2Test, Addition) {
  Vec2 vec1(1.0f, 0.5f);
  Vec2 vec2(0.6f, 0.6f);

  Vec2 result = vec1 + vec2;

  ASSERT_FLOAT_EQ(result.x, 1.6f);
  ASSERT_FLOAT_EQ(result.y, 1.1f);
}

TEST(Vec3Test, Addition) {
  Vec3 vec1(1.0f, 0.5f, 2.1f);
  Vec3 vec2(0.6f, 0.6f, 5.6f);

  Vec3 result = vec1 + vec2;

  ASSERT_FLOAT_EQ(result.x, 1.6f);
  ASSERT_FLOAT_EQ(result.y, 1.1f);
  ASSERT_FLOAT_EQ(result.z, 7.7f);
}

TEST(Vec4Test, Addition) {
  Vec4 vec1(1.0f, 0.5f, 2.1f, 0.7f);
  Vec4 vec2(0.6f, 0.6f, 5.6f, 0.5f);

  Vec4 result = vec1 + vec2;

  ASSERT_FLOAT_EQ(result.x, 1.6f);
  ASSERT_FLOAT_EQ(result.y, 1.1f);
  ASSERT_FLOAT_EQ(result.z, 7.7f);
  ASSERT_FLOAT_EQ(result.w, 1.2f);
}

TEST(Vec2Test, Subtraction) {
  Vec2 vec1(2.0f, 1.7f);
  Vec2 vec2(0.6f, 0.6f);

  Vec2 result = vec1 - vec2;

  ASSERT_FLOAT_EQ(result.x, 1.4f);
  ASSERT_FLOAT_EQ(result.y, 1.1f);
}

TEST(Vec3Test, Subtraction) {
  Vec3 vec1(2.0f, 1.7f, 2.9f);
  Vec3 vec2(0.6f, 0.6f, 0.6f);

  Vec3 result = vec1 - vec2;

  ASSERT_FLOAT_EQ(result.x, 1.4f);
  ASSERT_FLOAT_EQ(result.y, 1.1f);
  ASSERT_FLOAT_EQ(result.z, 2.3f);
}

TEST(Vec4Test, Subtraction) {
  Vec4 vec1(1.0f, 0.5f, 2.1f, 0.7f);
  Vec4 vec2(0.6f, 0.6f, 5.6f, 0.5f);

  Vec4 result = vec1 - vec2;

  ASSERT_FLOAT_EQ(result.x, 0.4f);
  ASSERT_FLOAT_EQ(result.y, -0.1f);
  ASSERT_FLOAT_EQ(result.z, -3.5f);
  ASSERT_FLOAT_EQ(result.w, 0.2f);
}
