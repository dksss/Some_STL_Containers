#include "../../tests_main.h"

/*
 * Тк класс RBTree -- вспомогательный класс
 * для реализации общих методов древовидных контейнеров,
 * то методы итератора operator*() и operator->() для классов наследников
 * реализованы для каждого контейнера-наследника отдельно,
 * а в базовом классе они отсутствуют из-за ненадобности
 */

TEST(TreeIteratorsTests, BeginMethodTest1) {
  s21::RBTree<int, int> test;

  EXPECT_TRUE(test.begin() == test.end());
}

TEST(TreeIteratorsTests, BeginMethodTest2) {
  s21::RBTree<int, int> test{50, 1, 99};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(TreeIteratorsTests, EndMethodTest1) {
  s21::RBTree<int, int> test{50, 1, 99};

  EXPECT_TRUE(test.begin() != test.end());
}

/*
 * Из-за указания того, что некоторые конструкторы генерируются автоматически
 * для итератора (= default), gtest не показывает их покрытие
 */

TEST(TreeIteratorsTests, IterTest1) {
  s21::RBTree<int, int> test{50, 1, 99};
  s21::RBTree<int, int>::iterator iter = test.begin();

  EXPECT_EQ(iter, test.begin());
  EXPECT_FALSE(++iter == test.begin());
  EXPECT_FALSE(test.begin() == iter);

  ++iter;
  ++iter;

  EXPECT_EQ(iter, test.end());
}

TEST(TreeIteratorsTests, IterTest2) {
  s21::RBTree<int, int> test{50, 1, 99};
  s21::RBTree<int, int>::iterator iter = test.end();

  EXPECT_EQ(iter, test.end());
  EXPECT_FALSE(--iter == test.end());

  --iter;
  --iter;

  EXPECT_EQ(iter, test.begin());
}

TEST(TreeIteratorsTests, IterTest3) {
  s21::RBTree<int, int> test{50, 1, 99};
  s21::RBTree<int, int>::const_iterator iter(test.end());

  EXPECT_EQ(iter, test.end());
  EXPECT_FALSE(--iter == test.end());
}

TEST(TreeIteratorsTests, IterTest4) {
  s21::RBTree<int, int> test{50, 1, 99};
  s21::RBTree<int, int>::iterator iter(test.end());

  EXPECT_EQ(iter, test.end());
  EXPECT_TRUE(iter-- == test.end());

  iter--;
  iter--;

  EXPECT_EQ(iter, test.begin());
}

TEST(TreeIteratorsTests, IterTest5) {
  s21::RBTree<int, int> test{50, 1, 99};
  s21::RBTree<int, int>::iterator iter(test.begin());

  EXPECT_EQ(iter, test.begin());
  EXPECT_TRUE(iter++ == test.begin());

  iter++;
  iter++;

  EXPECT_EQ(iter, test.end());
}