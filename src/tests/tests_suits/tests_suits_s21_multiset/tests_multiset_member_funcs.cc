#include "../../tests_main.h"

TEST(MultisetConstructorsTests, DefaultConstructorTest1) {
  s21::multiset<int> test;

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MultisetConstructorsTests, ListConstructorTest1) {
  s21::multiset<int> test{};

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MultisetConstructorsTests, ListConstructorTest2) {
  s21::multiset<int> test{50, 1, 99, 0, 10, 80, 100};

  EXPECT_EQ(7, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultisetConstructorsTests, ListConstructorTest3) {
  s21::multiset<int> test{1, 1, 1};

  EXPECT_EQ(3, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultisetConstructorsTests, CopyConstructorTest1) {
  s21::multiset<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::multiset<int> test(check);

  EXPECT_FALSE(check.empty());
  EXPECT_FALSE(test.empty());

  EXPECT_TRUE(check.size() == test.size());

  EXPECT_FALSE(check.begin() == test.begin());
  EXPECT_FALSE(check.end() == test.end());
}

TEST(MultisetConstructorsTests, MoveConstructorTest1) {
  s21::multiset<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::multiset<int> test(std::move(check));

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultietConstructorsTests, MoveAssignmentOperatorTest1) {
  s21::multiset<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::multiset<int> test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultietConstructorsTests, MoveAssignmentOperatorTest2) {
  s21::multiset<int> check{50, 1, 99, 0, 10, 80, 100};
  s21::multiset<int> test;
  test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}