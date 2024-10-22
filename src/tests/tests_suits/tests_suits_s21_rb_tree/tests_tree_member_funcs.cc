#include "../../tests_main.h"

TEST(TreeConstructorsTests, DefaultConstructorTest1) {
  s21::RBTree<int, int> test;

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(TreeConstructorsTests, ListConstructorTest1) {
  s21::RBTree<int, int> test{};

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(TreeConstructorsTests, ListConstructorTest2) {
  s21::RBTree<int, int> test{50, 1, 99, 0, 10, 80, 100};

  EXPECT_EQ(7, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(TreeConstructorsTests, ListConstructorTest3) {
  s21::RBTree<int, int> test{1, 1, 1};

  EXPECT_EQ(1, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(TreeConstructorsTests, CopyConstructorTest1) {
  s21::RBTree<int, int> check{50, 1, 99, 0, 10, 80, 100};
  s21::RBTree<int, int> test(check);

  EXPECT_FALSE(check.empty());
  EXPECT_FALSE(test.empty());

  EXPECT_TRUE(check.size() == test.size());

  EXPECT_FALSE(check.begin() == test.begin());
  EXPECT_FALSE(check.end() == test.end());
}

TEST(TreeConstructorsTests, MoveConstructorTest1) {
  s21::RBTree<int, int> check{50, 1, 99, 0, 10, 80, 100};
  s21::RBTree<int, int> test(std::move(check));

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(TreeConstructorsTests, MoveAssignmentOperatorTest1) {
  s21::RBTree<int, int> check{50, 1, 99, 0, 10, 80, 100};
  s21::RBTree<int, int> test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(TreeConstructorsTests, MoveAssignmentOperatorTest2) {
  s21::RBTree<int, int> check{50, 1, 99, 0, 10, 80, 100};
  s21::RBTree<int, int> test;
  test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}