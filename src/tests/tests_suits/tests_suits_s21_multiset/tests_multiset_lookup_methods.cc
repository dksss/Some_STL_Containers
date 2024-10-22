#include "../../tests_main.h"

TEST(MultisetLookupTests, CountMethodTest1) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  EXPECT_EQ(1, test.count(2));
}

TEST(MultisetLookupTests, CountMethodTest2) {
  s21::multiset<int> test{3, 1, 2, 2, 2, 2, 2};

  EXPECT_EQ(5, test.count(2));
}

TEST(MultisetLookupTests, FindMethodTest1) {
  s21::multiset<int> test{3, 1, 2, 4, 5};
  auto iter = test.find(1);

  EXPECT_EQ(1, *iter);
  EXPECT_TRUE(iter == test.begin());
}

TEST(MultisetLookupTests, FindMethodTest2) {
  s21::multiset<int> test{3, 1, 2, 4, 5};
  auto iter = test.find(8);

  EXPECT_TRUE(iter == test.end());
}

TEST(MultisetLookupTests, LowerBoundTest1) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  auto iter = test.lower_bound(2);
  EXPECT_EQ(2, *iter);

  ++iter;
  EXPECT_EQ(3, *iter);
}

TEST(MultisetLookupTests, LowerBoundTest2) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  auto iter = test.lower_bound(6);
  EXPECT_TRUE(iter == test.end());
}

TEST(MultisetLookupTests, UpperBoundTest1) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  auto iter = test.upper_bound(2);
  EXPECT_EQ(3, *iter);

  ++iter;
  EXPECT_EQ(4, *iter);
}

TEST(MultisetLookupTests, UpperBoundTest2) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  auto iter = test.upper_bound(6);
  EXPECT_TRUE(iter == test.end());
}

TEST(MultisetLookupTests, EqualRangeTest1) {
  s21::multiset<int> test{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto pair_iters = test.equal_range(0);
  EXPECT_TRUE(*pair_iters.first == 0);
  EXPECT_TRUE(*pair_iters.second == 1);
}

TEST(MultisetLookupTests, EqualRangeTest2) {
  s21::multiset<int> test{21, 21, 21, 21, 21};

  auto pair_iters = test.equal_range(21);
  EXPECT_TRUE(*pair_iters.first == 21);
  EXPECT_TRUE(pair_iters.second == test.end());

  int check = 0;
  auto check_iter = pair_iters.first;
  for (; check_iter != test.end(); ++check, ++check_iter)
    ;

  EXPECT_EQ(check, test.size());
}

TEST(MultisetLookupTests, EqualRangeTest3) {
  s21::multiset<int> test{3, 1, 2, 4, 5};

  auto iter = test.equal_range(6);
  EXPECT_TRUE(iter.first == test.end());
  EXPECT_TRUE(iter.second == test.end());
}