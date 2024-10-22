#include "../../tests_main.h"

TEST(MultisetModifiersTests, ClearMethodTest1) {
  s21::multiset<int> test;

  test.clear();

  EXPECT_EQ(0, test.size());
}

TEST(MultisetModifiersTests, ClearMethodTest2) {
  s21::multiset<int> test{38, 1, 40, 0, 0};

  test.clear();

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
}

TEST(MultisetModifiersTests, EraseMethodTest1) {
  s21::multiset<int> test{50, 1, 10, 0, 99, 80, 100, 0, 0, 0};

  EXPECT_EQ(10, test.size());

  test.erase(test.begin());
  EXPECT_EQ(9, test.size());

  test.erase(test.begin());
  EXPECT_EQ(8, test.size());
}

TEST(MultisetModifiersTests, EraseMethodTest2) {
  s21::multiset<int> test{50};

  EXPECT_EQ(1, test.size());

  test.erase(test.begin());
  EXPECT_EQ(0, test.size());

  EXPECT_TRUE(test.empty());
}

TEST(MultisetModifiersTests, SwapMethodTest1) {
  s21::multiset<int> test1{50, 1, 99, 10, 80};
  s21::multiset<int> test2;

  s21::multiset<int>::iterator iter_test1_before = test1.end();

  EXPECT_EQ(5, test1.size());
  EXPECT_TRUE(test2.empty());

  test2.swap(test1);
  s21::multiset<int>::iterator iter_test1_after = test1.end();

  EXPECT_TRUE(test1.empty());
  EXPECT_EQ(5, test2.size());
  EXPECT_TRUE(iter_test1_before == iter_test1_after);
}

TEST(MultisetModifiersTests, SwapMethodTest2) {
  s21::multiset<int> test1;
  s21::multiset<int> test2{50, 1, 99, 10, 80};

  EXPECT_TRUE(test1.empty());
  EXPECT_FALSE(test2.empty());

  test2.swap(test1);

  EXPECT_FALSE(test1.empty());
  EXPECT_EQ(5, test1.size());
  EXPECT_TRUE(test2.empty());
}

TEST(MultisetModifiersTests, SwapMethodTest3) {
  s21::multiset<int> test1{100};
  s21::multiset<int> test2{50, 1, 99, 10, 80};

  EXPECT_EQ(1, test1.size());
  EXPECT_EQ(5, test2.size());

  test1.swap(test2);

  EXPECT_EQ(5, test1.size());
  EXPECT_EQ(1, test2.size());
}

TEST(MultisetModifiersTests, MergeMethodTest1) {
  s21::multiset<int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::multiset<int> test2;

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
}

TEST(MultisetModifiersTests, MergeMethodTest2) {
  s21::multiset<int> test1;
  s21::multiset<int> test2{50, 1, 10, 0, 90, 80, 100};

  EXPECT_TRUE(test1.empty());
  EXPECT_FALSE(test2.empty());
  EXPECT_EQ(7, test2.size());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
  EXPECT_EQ(7, test1.size());
}

TEST(MultisetModifiersTests, MergeMethodTest3) {
  s21::multiset<int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::multiset<int> test2{50, 1, 10, 0, 90, 80, 100};

  test1.merge(test2);

  EXPECT_EQ(14, test1.size());
  EXPECT_TRUE(test2.empty());
}

TEST(MultisetModifiersTests, MergeMethodTest4) {
  s21::multiset<int> test1{50, 1, 90};
  s21::multiset<int> test2{50, 1, 10, 0, 90, 80, 100};

  s21::multiset<int>::iterator iter_test2_before = test2.begin();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_EQ(10, test1.size());
  EXPECT_TRUE(test2.empty());
}

TEST(MultisetModifiersTests, MergeMethodTest5) {
  s21::multiset<int> test1{50, 1, 90, 0, 10, 80, 100};
  s21::multiset<int> test2{55, 11, 110, 30, 95, 85, 105};

  s21::multiset<int>::iterator iter_test2_before = test2.begin();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_EQ(14, test1.size());
  EXPECT_TRUE(test2.empty());
}

TEST(MultisetModifiersTests, InsertMethodTest1) {
  s21::multiset<int> test;

  test.insert(21);
  EXPECT_FALSE(test.empty());

  test.insert(0);
  EXPECT_EQ(2, test.size());
}

TEST(MultisetModifiersTests, InsertMethodTest2) {
  s21::multiset<int> test{50, 1, 90};
  EXPECT_EQ(3, test.size());

  test.insert(21);
  EXPECT_EQ(4, test.size());

  test.insert(21);
  EXPECT_EQ(5, test.size());
}

TEST(MultisetModifiersTests, InsertMethodTest3) {
  s21::multiset<int> test{50, 1, 90};

  auto check = test.insert(21);
  EXPECT_EQ(21, *check);

  auto check2 = check;

  check = test.insert(21);
  EXPECT_EQ(21, *check);
  EXPECT_FALSE(check == check2);
}