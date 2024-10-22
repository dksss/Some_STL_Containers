#include "../../tests_main.h"

TEST(MultisetIteratorsTests, BeginMethodTest1) {
  s21::multiset<int> test;

  EXPECT_TRUE(test.begin() == test.end());
}

TEST(MultisetIteratorsTests, BeginMethodTest2) {
  s21::multiset<int> test{5, 35, -35};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultisetIteratorsTests, EndMethodTest1) {
  s21::multiset<int> test{50, 1, 99, 50};

  EXPECT_TRUE(test.begin() != test.end());
}

TEST(MultisetIteratorsTests, IterTest1) {
  s21::multiset<int> test{35, 12, 34, 56, 13, 5, 1, 1, 1};
  s21::multiset<int>::iterator iter = test.begin();

  for (; iter != test.end(); ++iter) {
    EXPECT_TRUE(*iter > 0);
  }
}

TEST(MultisetIteratorsTests, IterTest2) {
  s21::multiset<int> test{35, 12, 34, 56, 13, 5, 1, 1, 1};
  s21::multiset<int>::iterator iter = test.end();

  iter--;

  for (size_t i = 1; i != test.size(); ++i, --iter) {
    EXPECT_TRUE(*iter > 0);
  }
}

TEST(MultisetIteratorsTests, IterTest3) {
  s21::multiset<int> test{3, 1, 1, 5};
  s21::multiset<int>::iterator iter = test.begin();
  s21::multiset<int>::iterator check = test.end();

  EXPECT_TRUE(iter != check);

  EXPECT_EQ(*iter++, 1);
  EXPECT_EQ(*iter++, 1);
  EXPECT_EQ(*iter++, 3);
  EXPECT_EQ(*iter++, 5);

  EXPECT_TRUE(iter == check);
}

TEST(MultisetIteratorsTests, IterTest4) {
  s21::multiset<int> test{3, 1, 1, 5};
  s21::multiset<int>::iterator iter(test.begin());

  EXPECT_EQ(*iter, 1);
}