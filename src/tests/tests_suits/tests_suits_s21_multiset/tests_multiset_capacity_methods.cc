#include "../../tests_main.h"

TEST(MultisetCapacityTests, EmptyMethodTest1) {
  s21::multiset<int> test;

  EXPECT_TRUE(test.empty());
}

TEST(MultisetCapacityTests, EmptyMethodTest2) {
  s21::multiset<int> test{};

  EXPECT_TRUE(test.empty());
}

TEST(MultisetCapacityTests, EmptyMethodTest3) {
  s21::multiset<int> test{321, 43, 1000};

  EXPECT_FALSE(test.empty());
}

TEST(MultisetCapacityTests, SizeMethodTest1) {
  s21::multiset<int> test;

  EXPECT_EQ(0, test.size());
}

TEST(MultisetCapacityTests, SizeMethodTest2) {
  s21::multiset<int> test{33, 22, 11, 44, 55, 55};

  EXPECT_EQ(6, test.size());
}

TEST(MultisetCapacityTests, MaxSizeMethodTest) {
  s21::multiset<int> test{33, 22, 11, 44, 55};

  EXPECT_TRUE(test.max_size() > 0);
}