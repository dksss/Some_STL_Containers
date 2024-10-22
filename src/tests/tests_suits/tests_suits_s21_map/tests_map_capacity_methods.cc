#include "../../tests_main.h"

TEST(MapCapacityTests, EmptyMethodTest1) {
  s21::map<int, int> test;

  EXPECT_TRUE(test.empty());
}

TEST(MapCapacityTests, EmptyMethodTest2) {
  s21::map<int, int> test{};

  EXPECT_TRUE(test.empty());
}

TEST(MapCapacityTests, EmptyMethodTest3) {
  s21::map<int, int> test{{321, 321}, {43, 43}, {1000, 1000}};

  EXPECT_FALSE(test.empty());
}

TEST(MapCapacityTests, SizeMethodTest1) {
  s21::map<int, int> test;

  EXPECT_EQ(0, test.size());
}

TEST(MapCapacityTests, SizeMethodTest2) {
  s21::map<int, int> test{{33, 33}, {22, 22}, {11, 11}, {44, 44}, {55, 55}};

  EXPECT_EQ(5, test.size());
}

/*
 * Тк использование макросов не поощряется гуглстилем и
 * для реализации универсального наследования дерева
 * было необходимо реализовать доп. поля в нодах,
 * то max_size() выдает другое значение, нежели оригинал
 */
TEST(MapCapacityTests, MaxSizeMethodTest) {
  s21::map<int, int> test{{33, 22}, {11, 44}, {55, 55}};

  EXPECT_TRUE(test.max_size() > 0);
}