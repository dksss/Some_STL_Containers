#include "../../tests_main.h"

TEST(SetModifiersTests, ClearMethodTest1) {
  s21::set<int> test;

  test.clear();

  EXPECT_EQ(0, test.size());
}

TEST(SetModifiersTests, ClearMethodTest2) {
  s21::set<int> test{38, 1, 40};

  test.clear();

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
}

TEST(SetModifiersTests, EraseMethodTest1) {
  s21::set<int> test{50, 1, 10, 0, 99, 80, 100};
  s21::set<int>::iterator iter = test.end();

  EXPECT_EQ(7, test.size());

  --iter;
  test.erase(iter);
  EXPECT_EQ(6, test.size());

  iter = test.begin();
  test.erase(iter);
  EXPECT_EQ(5, test.size());
}

TEST(SetModifiersTests, EraseMethodTest2) {
  s21::set<int> test{50, 1, 99, 10, 80};
  s21::set<int>::iterator iter = test.end();

  EXPECT_EQ(5, test.size());

  --iter;  // 80
  --iter;  // 99
  --iter;  // 50 (true_root)
  test.erase(iter);
  EXPECT_EQ(4, test.size());
}

TEST(SetModifiersTests, EraseMethodTest3) {
  s21::set<int> test{50, 1, 99, 10, 80};
  s21::set<int>::iterator iter = test.begin();

  EXPECT_EQ(5, test.size());

  test.erase(iter);
  EXPECT_EQ(4, test.size());
}

TEST(SetModifiersTests, SwapMethodTest1) {
  s21::set<int> test1{50, 1, 99, 10, 80};
  s21::set<int> test2;

  s21::set<int>::iterator iter_test1_before = test1.end();

  EXPECT_EQ(5, test1.size());
  EXPECT_TRUE(test2.empty());

  test2.swap(test1);
  s21::set<int>::iterator iter_test1_after = test1.end();

  EXPECT_TRUE(test1.empty());
  EXPECT_EQ(5, test2.size());
  EXPECT_TRUE(iter_test1_before == iter_test1_after);
}

TEST(SetModifiersTests, SwapMethodTest2) {
  s21::set<int> test1{100};
  s21::set<int> test2{50, 1, 99, 10, 80};

  EXPECT_EQ(1, test1.size());
  EXPECT_EQ(5, test2.size());

  test1.swap(test2);

  EXPECT_EQ(5, test1.size());
  EXPECT_EQ(1, test2.size());
}

TEST(SetModifiersTests, MergeMethodTest1) {
  s21::set<int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::set<int> test2;

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
}

TEST(SetModifiersTests, MergeMethodTest2) {
  s21::set<int> test1;
  s21::set<int> test2{50, 1, 10, 0, 90, 80, 100};

  EXPECT_TRUE(test1.empty());
  EXPECT_FALSE(test2.empty());
  EXPECT_EQ(7, test2.size());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
  EXPECT_EQ(7, test1.size());
}

TEST(SetModifiersTests, MergeMethodTest3) {
  s21::set<int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::set<int> test2{50, 1, 10, 0, 90, 80, 100};

  s21::set<int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_EQ(iter_test2_before, test2.begin());
  EXPECT_EQ(check1, test1.size());
  EXPECT_EQ(check2, test2.size());
}

TEST(SetModifiersTests, MergeMethodTest4) {
  s21::set<int> test1{50, 1, 90};
  s21::set<int> test2{50, 1, 10, 0, 90, 80, 100};

  s21::set<int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_FALSE(check1 == test1.size());
  EXPECT_FALSE(check2 == test2.size());

  EXPECT_EQ(7, test1.size());
  EXPECT_EQ(3, test2.size());
}

TEST(SetModifiersTests, MergeMethodTest5) {
  s21::set<int> test1{50, 1, 90, 0, 10, 80, 100};
  s21::set<int> test2{55, 11, 110, 30, 95, 85, 105};

  s21::set<int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_FALSE(check1 == test1.size());
  EXPECT_FALSE(check2 == test2.size());

  EXPECT_EQ(14, test1.size());
  EXPECT_TRUE(test2.empty());
}

TEST(SetModifiersTests, InsertMethodTest1) {
  s21::set<int> test;

  test.insert(21);
  EXPECT_FALSE(test.empty());

  test.insert(0);
  EXPECT_EQ(2, test.size());
}

TEST(SetModifiersTests, InsertMethodTest2) {
  s21::set<int> test{50, 1, 90};
  EXPECT_EQ(3, test.size());

  test.insert(21);
  EXPECT_EQ(4, test.size());

  test.insert(21);
  EXPECT_EQ(4, test.size());
}

TEST(SetModifiersTests, InsertMethodTest3) {
  s21::set<int> test{50, 1, 90};

  auto check = test.insert(21);
  EXPECT_EQ(true, check.second);

  auto iter_check = check.first;

  check = test.insert(21);
  EXPECT_EQ(false, check.second);
  EXPECT_TRUE(iter_check == check.first);
}