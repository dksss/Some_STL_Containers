#include "../../tests_main.h"

TEST(MapConstructorsTests, DefaultConstructorTest1) {
  s21::map<int, int> test;

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MapConstructorsTests, ListConstructorTest1) {
  s21::map<int, int> test{};

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MapConstructorsTests, ListConstructorTest2) {
  s21::map<int, int> test{{15, 15}, {88, 88}, {-33, 33}, {50, 50}, {21, 21}};

  EXPECT_EQ(5, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapConstructorsTests, ListConstructorTest3) {
  s21::map<int, int> test{{21, 21}, {21, 21}, {21, 21}};

  EXPECT_EQ(1, test.size());
  EXPECT_FALSE(test.empty());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapConstructorsTests, CopyConstructorTest1) {
  s21::map<int, int> check{{50, 50}, {1, 1},   {99, 99},  {0, 0},
                           {10, 10}, {80, 80}, {100, 100}};
  s21::map<int, int> test(check);

  EXPECT_FALSE(check.empty());
  EXPECT_FALSE(test.empty());

  EXPECT_TRUE(check.size() == test.size());

  EXPECT_FALSE(check.begin() == test.begin());
  EXPECT_FALSE(check.end() == test.end());
}

TEST(MapConstructorsTests, MoveConstructorTest1) {
  s21::map<int, int> check{{50, 50}, {1, 1},   {99, 99},  {0, 0},
                           {10, 10}, {80, 80}, {100, 100}};
  s21::map<int, int> test(std::move(check));

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapConstructorsTests, MoveAssignmentOperatorTest1) {
  s21::map<int, int> check{{50, 50}, {1, 1},   {99, 99},  {0, 0},
                           {10, 10}, {80, 80}, {100, 100}};
  s21::map<int, int> test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapConstructorsTests, MoveAssignmentOperatorTest2) {
  s21::map<int, int> check{{50, 50}, {1, 1},   {99, 99},  {0, 0},
                           {10, 10}, {80, 80}, {100, 100}};
  s21::map<int, int> test;
  test = std::move(check);

  EXPECT_TRUE(check.empty());
  EXPECT_EQ(0, check.size());
  EXPECT_TRUE(check.begin() == check.end());

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(7, test.size());
  EXPECT_TRUE(test.begin() != test.end());
}