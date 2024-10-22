#include "../../tests_main.h"

TEST(SetLookupTests, ContainsMethodTest1) {
  s21::set<int> test;

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));
}

TEST(SetLookupTests, ContainsMethodTest2) {
  s21::set<int> test{50, 0, 80};

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));

  EXPECT_TRUE(test.contains(50));
  EXPECT_TRUE(test.contains(80));
  EXPECT_TRUE(test.contains(0));
}

TEST(SetLookupTests, FindMethodTest1) {
  s21::set<int> test{50, 0, 80};
  auto iter_check = test.end();

  auto iter = test.find(21);
  EXPECT_TRUE(iter == iter_check);

  iter = test.find(80);
  --iter_check;
  EXPECT_TRUE(iter == iter_check);

  iter = test.find(50);
  --iter_check;
  EXPECT_TRUE(iter == iter_check);

  iter = test.find(33);
  EXPECT_TRUE(iter == test.end());
}