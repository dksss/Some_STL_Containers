#include "../../tests_main.h"

TEST(MapIteratorsTests, BeginMethodTest1) {
  s21::map<int, int> test;

  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MapIteratorsTests, BeginMethodTest2) {
  s21::map<int, int> test{{50, 50}, {1, 1}, {99, 99}};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapIteratorsTests, EndMethodTest1) {
  s21::map<int, int> test{{50, 50}, {1, 1}, {99, 99}};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MapIteratorsTests, IterOperatorTest1) {
  s21::map<int, int> test{{33, 33}, {21, 21}, {53, 53}};

  s21::map<int, int>::iterator iter = test.begin();
  EXPECT_EQ(21, *iter);

  ++iter;
  EXPECT_EQ(33, *iter);

  iter++;
  EXPECT_EQ(53, *iter);
}

TEST(MapIteratorsTests, IterOperatorTest2) {
  s21::map<int, int> test{{33, 33}, {21, 21}, {53, 53}};

  s21::map<int, int>::iterator iter = test.end();
  --iter;
  EXPECT_EQ(53, *iter);

  --iter;
  EXPECT_EQ(33, *iter);

  iter--;
  EXPECT_EQ(21, *iter);
}

TEST(MapIteratorsTests, IterTest1) {
  s21::map<int, int> test{{33, 33}, {21, 21}, {53, 53}};

  s21::map<int, int>::iterator iter = test.begin();
  ++iter;
  ++iter;
  ++iter;

  EXPECT_EQ(iter, test.end());
}

TEST(MapIteratorsTests, IterTest2) {
  s21::map<int, int> test;

  s21::map<int, int>::iterator iter = test.begin();
  ++iter;
  ++iter;
  ++iter;

  EXPECT_EQ(iter, test.end());
}

TEST(MapIteratorsTest, IterArrowTest1) {
  s21::map<int, int> testing{{50, 1}, {30, 2}, {60, 3}};
  s21::map<int, int>::iterator iter_test = testing.begin();

  EXPECT_EQ(2, *iter_test);

  iter_test->value = 21;
  EXPECT_EQ(21, *iter_test);
}