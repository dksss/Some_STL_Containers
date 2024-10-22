#include "../../tests_main.h"

TEST(ArrayCapacityTests, EmptyMethodTest1) {
  s21::array<int, 5> testing1;
  s21::array<std::string, 5> testing2;

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(ArrayCapacityTests, EmptyMethodTest2) {
  s21::array<int, 3> testing1{};
  s21::array<std::string, 3> testing2{};

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(ArrayCapacityTests, EmptyMethodTest3) {
  s21::array<int, 3> testing1{234, 232, 232};
  s21::array<std::string, 3> testing2{"wqdq", "cqwed3", "cacsac"};

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(ArrayCapacityTests, EmptyMethodTest4) {
  s21::array<int, 3> testing1{234, 232, 232};
  s21::array<std::string, 3> testing2{"wqdq", "cqwed3", "cacsac"};

  std::array<int, 3> check1{234, 232, 232};
  std::array<std::string, 3> check2{"wqdq", "cqwed3", "cacsac"};

  EXPECT_EQ(check1.empty(), testing1.empty());
  EXPECT_EQ(check2.empty(), testing2.empty());
}

TEST(ArrayCapacityTests, EmptyMethodTest5) {
  s21::array<int, 0> testing1{};
  s21::array<std::string, 0> testing2{};

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());
}

TEST(ArrayCapacityTests, SizeMethodTest1) {
  s21::array<int, 4> testing1;
  s21::array<std::string, 3> testing2;

  std::array<int, 4> check1;
  std::array<std::string, 3> check2;

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());
}

TEST(ArrayCapacityTests, SizeMethodTest2) {
  s21::array<int, 8> testing1;
  s21::array<std::string, 4> testing2;

  EXPECT_EQ(8, testing1.size());
  EXPECT_EQ(4, testing2.size());
}

TEST(ArrayCapacityTests, MaxSizeMethodTest1) {
  s21::array<int, 5> testing1;
  s21::array<std::string, 5> testing2;

  std::array<int, 5> check1;
  std::array<std::string, 5> check2;

  EXPECT_EQ(check1.max_size(), testing1.max_size());
  EXPECT_EQ(check2.max_size(), testing2.max_size());
}

TEST(ArrayCapacityTests, MaxSizeMethodTest2) {
  s21::array<int, 10> testing1;
  s21::array<std::string, 8> testing2;

  EXPECT_EQ(10, testing1.max_size());
  EXPECT_EQ(8, testing2.max_size());
}

TEST(ArrayCapacityTests, MaxSizeMethodTest3) {
  s21::array<int, 0> testing1;
  s21::array<std::string, 0> testing2;

  EXPECT_EQ(0, testing1.max_size());
  EXPECT_EQ(0, testing2.max_size());
}