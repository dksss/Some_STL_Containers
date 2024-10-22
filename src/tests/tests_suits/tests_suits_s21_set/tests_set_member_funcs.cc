#include "../../tests_main.h"

TEST(SetConstructorsTests, DefaultConstructorTest1) {
  s21::set<int> test;

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(SetConstructorsTests, ListConstructorTest1) {
  s21::set<int> test{};

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(SetConstructorsTests, ListConstructorTest2) {
  s21::set<int> test{50, 1, 99, 0, 10, 80, 100};

  EXPECT_EQ(7, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetConstructorsTests, ListConstructorTest3) {
  s21::set<int> test{1, 1, 1};

  EXPECT_EQ(1, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetConstructorsTests, CopyConstructorTest1) {
  s21::set<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::set<int> test(check);

  EXPECT_FALSE(check.empty());
  EXPECT_FALSE(test.empty());

  EXPECT_TRUE(check.size() == test.size());

  EXPECT_FALSE(check.begin() == test.begin());
  EXPECT_FALSE(check.end() == test.end());
}

TEST(SetConstructorsTests, MoveConstructorTest1) {
  s21::set<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::set<int> test(std::move(check));

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetConstructorsTests, MoveAssignmentOperatorTest1) {
  s21::set<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::set<int> test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetConstructorsTests, MoveAssignmentOperatorTest2) {
  s21::set<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::set<int> test;
  test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}