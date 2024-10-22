#include "../../tests_main.h"

TEST(SetCapacityTests, EmptyMethodTest1) {
  s21::set<int> test;

  EXPECT_TRUE(test.empty());
}

TEST(SetCapacityTests, EmptyMethodTest2) {
  s21::set<int> test{};

  EXPECT_TRUE(test.empty());
}

TEST(SetCapacityTests, EmptyMethodTest3) {
  s21::set<int> test{321, 43, 1000};

  EXPECT_FALSE(test.empty());
}

TEST(SetCapacityTests, SizeMethodTest1) {
  s21::set<int> test;

  EXPECT_EQ(0, test.size());
}

TEST(SetCapacityTests, SizeMethodTest2) {
  s21::set<int> test{33, 22, 11, 44, 55};

  EXPECT_EQ(5, test.size());
}

TEST(SetCapacityTests, MaxSizeMethodTest) {
  s21::set<int> test{33, 22, 11, 44, 55};

  EXPECT_TRUE(test.max_size() > 0);
}