#include "../../tests_main.h"

TEST(TreeCapacityTests, EmptyMethodTest1) {
  s21::RBTree<int, int> test;

  EXPECT_TRUE(test.empty());
}

TEST(TreeCapacityTests, EmptyMethodTest2) {
  s21::RBTree<int, int> test{};

  EXPECT_TRUE(test.empty());
}

TEST(TreeCapacityTests, EmptyMethodTest3) {
  s21::RBTree<int, int> test{321, 43, 1000};

  EXPECT_FALSE(test.empty());
}

TEST(TreeCapacityTests, SizeMethodTest1) {
  s21::RBTree<int, int> test;

  EXPECT_EQ(0, test.size());
}

TEST(TreeCapacityTests, SizeMethodTest2) {
  s21::RBTree<int, int> test{33, 22, 11, 44, 55};

  EXPECT_EQ(5, test.size());
}

/*
 * Тк использование макросов не поощряется гуглстилем и
 * для реализации универсального наследования дерева
 * было необходимо реализовать доп. поля в нодах,
 * то max_size() выдает меньшее значение, чем оригинал
 */
TEST(TreeCapacityTests, MaxSizeMethodTest) {
  s21::RBTree<int, int> test{33, 22, 11, 44, 55};

  EXPECT_TRUE(test.max_size() > 0);
}