#include "../../tests_main.h"

TEST(MultisetBonusTests, InsertManyTest1) {
  s21::multiset<int> test;
  EXPECT_TRUE(test.empty());

  test.insert_many(33, 22, 11, 44, 55);
  EXPECT_EQ(5, test.size());
}

TEST(MultisetBonusTests, InsertManyTest2) {
  s21::multiset<int> test{21};
  EXPECT_EQ(1, test.size());

  test.insert_many(33, 21, 11, 44, 55);
  EXPECT_EQ(6, test.size());
}

TEST(MultisetBonusTests, InsertManyTest3) {
  s21::multiset<int> test{21};
  EXPECT_EQ(1, test.size());

  auto checking_iter = test.find(21);

  auto check = test.insert_many(21, 55, 13, 66);
  EXPECT_EQ(4, check.size());
  EXPECT_EQ(5, test.size());

  EXPECT_EQ(true, check[0].second);

  EXPECT_EQ(true, check[1].second);
  EXPECT_TRUE(checking_iter != check[1].first);

  EXPECT_EQ(true, check[2].second);
  EXPECT_EQ(true, check[3].second);
}