#include "../../tests_main.h"

TEST(SetIteratorsTests, BeginMethodTest1) {
  s21::set<int> test;

  EXPECT_TRUE(test.begin() == test.end());
}

TEST(SetIteratorsTests, BeginMethodTest2) {
  s21::set<int> test{50, 1, 99};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetIteratorsTests, EndMethodTest1) {
  s21::set<int> test{50, 1, 99};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(SetIteratorsTests, IterTest1) {
  s21::set<int> test{50, 1, 99};
  s21::set<int>::iterator iter = test.begin();

  EXPECT_EQ(iter, test.begin());
  EXPECT_FALSE(++iter == test.begin());
  EXPECT_FALSE(test.begin() == iter);

  ++iter;
  ++iter;

  EXPECT_EQ(iter, test.end());
}

TEST(SetIteratorsTests, IterTest2) {
  s21::set<int> test{50, 1, 99};
  s21::set<int>::iterator iter = test.end();

  EXPECT_EQ(iter, test.end());
  EXPECT_FALSE(--iter == test.end());

  --iter;
  --iter;

  EXPECT_EQ(iter, test.begin());
}

TEST(SetIteratorsTests, IterTest3) {
  s21::set<int> test{50, 1, 99};
  s21::set<int>::iterator iter(test.end());

  EXPECT_EQ(iter, test.end());
  EXPECT_TRUE(iter-- == test.end());

  iter--;
  iter--;

  EXPECT_EQ(iter, test.begin());
}

TEST(SetIteratorsTests, IterTest4) {
  s21::set<int> test{50, 1, 99};
  s21::set<int>::iterator iter(test.begin());

  EXPECT_EQ(iter, test.begin());
  EXPECT_TRUE(iter++ == test.begin());

  iter++;
  iter++;

  EXPECT_EQ(iter, test.end());
}

TEST(SetIteratorsTests, IterTest5) {
  s21::set<int> test{21, 50, 10, 60};
  s21::set<int>::iterator iter;

  iter = test.begin();
  EXPECT_EQ(10, *iter);

  ++iter;
  EXPECT_EQ(21, *iter);

  ++iter;
  EXPECT_EQ(50, *iter);

  ++iter;
  EXPECT_EQ(60, *iter);

  ++iter;
  EXPECT_EQ(test.end(), iter);
}