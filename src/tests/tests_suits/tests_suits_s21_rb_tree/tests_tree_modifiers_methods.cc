#include "../../tests_main.h"

TEST(TreeModifiersTests, ClearMethodTest1) {
  s21::RBTree<int, int> test;

  test.clear();

  EXPECT_EQ(0, test.size());
}

TEST(TreeModifiersTests, ClearMethodTest2) {
  s21::RBTree<int, int> test{38, 1, 40};

  test.clear();

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
}

TEST(TreeModifiersTests, EraseMethodTest1) {
  s21::RBTree<int, int> test{50, 1, 10, 0, 99, 80, 100};
  s21::RBTree<int, int>::iterator iter = test.end();

  EXPECT_EQ(7, test.size());

  --iter;
  test.erase(iter);
  EXPECT_EQ(6, test.size());

  iter = test.begin();
  test.erase(iter);
  EXPECT_EQ(5, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest2) {
  s21::RBTree<int, int> test{50, 1, 99, 10, 80};
  s21::RBTree<int, int>::iterator iter = test.end();

  EXPECT_EQ(5, test.size());

  --iter;  // 80
  --iter;  // 99
  --iter;  // 50 (true_root)
  test.erase(iter);
  EXPECT_EQ(4, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest3) {
  s21::RBTree<int, int> test{50, 1, 99, 10, 80};
  s21::RBTree<int, int>::iterator iter = test.begin();

  EXPECT_EQ(5, test.size());

  test.erase(iter);
  EXPECT_EQ(4, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest4) {
  s21::RBTree<int, int> test{50, 1, 99, 10, 80};
  s21::RBTree<int, int>::iterator iter = test.begin();

  EXPECT_EQ(5, test.size());

  ++iter;
  test.erase(iter);
  EXPECT_EQ(4, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest5) {
  s21::RBTree<int, int> test{50, 1, 99, 10, 80};

  EXPECT_EQ(5, test.size());

  test.erase(test.begin());
  EXPECT_EQ(4, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest6) {
  s21::RBTree<int, int> test{50, 1, 99, 10, 80};

  EXPECT_EQ(5, test.size());

  test.erase(test.end());
  EXPECT_EQ(5, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest7) {
  s21::RBTree<int, int> test{50, 1, 10, 9};
  s21::RBTree<int, int>::iterator iter = test.begin();  // 1

  EXPECT_EQ(4, test.size());

  ++iter;  // 9
  ++iter;  // 10
  test.erase(iter);
  EXPECT_EQ(3, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest8) {
  s21::RBTree<int, int> test{50, 30, 15, 20, 5};
  s21::RBTree<int, int>::iterator iter = test.begin();  // 5

  EXPECT_EQ(5, test.size());

  ++iter;  // 15
  ++iter;  // 20
  ++iter;  // 30
  test.erase(iter);

  EXPECT_EQ(4, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest9) {
  s21::RBTree<int, int> test{50, 30, 70, 20, 40, 60, 80};
  s21::RBTree<int, int>::iterator iter;
  iter = test.end();  // fake_root

  EXPECT_EQ(7, test.size());

  --iter;  // 80
  --iter;  // 70
  test.erase(iter);

  EXPECT_EQ(6, test.size());
}

TEST(TreeModifiersTests, EraseMethodTest10) {
  s21::RBTree<int, int> test{50};
  s21::RBTree<int, int>::iterator iter = test.begin();

  EXPECT_EQ(1, test.size());

  test.erase(iter);

  EXPECT_TRUE(test.empty());
}

/*
 * TestInsert() -- вспомогательный метод-обертка,
 * для проверки работоспособности основного метода TreeInsert()
 */
TEST(TreeModifiersTests, TestInsertMethodTest1) {
  s21::RBTree<int, int> test;

  test.TestInsert(50);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  test.TestInsert(30);
  EXPECT_EQ(2, test.size());

  test.TestInsert(40);
  EXPECT_EQ(3, test.size());

  test.TestInsert(20);
  EXPECT_EQ(4, test.size());

  test.TestInsert(80);
  EXPECT_EQ(5, test.size());

  test.TestInsert(90);
  EXPECT_EQ(6, test.size());

  test.TestInsert(60);
  EXPECT_EQ(7, test.size());
}

TEST(TreeModifiersTests, TestInsertMethodTest2) {
  s21::RBTree<int, int> test;

  test.TestInsert(50);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  test.TestInsert(50);
  EXPECT_EQ(1, test.size());
}

TEST(TreeModifiersTests, SwapMethodTest1) {
  s21::RBTree<int, int> test1{50, 1, 99, 10, 80};
  s21::RBTree<int, int> test2;

  s21::RBTree<int, int>::iterator iter_test1_before = test1.end();

  EXPECT_EQ(5, test1.size());
  EXPECT_TRUE(test2.empty());

  test2.swap(test1);
  s21::RBTree<int, int>::iterator iter_test1_after = test1.end();

  EXPECT_TRUE(test1.empty());
  EXPECT_EQ(5, test2.size());
  EXPECT_TRUE(iter_test1_before == iter_test1_after);
}

TEST(TreeModifiersTests, SwapMethodTest2) {
  s21::RBTree<int, int> test1;
  s21::RBTree<int, int> test2{50, 1, 99, 10, 80};

  EXPECT_EQ(5, test2.size());
  EXPECT_TRUE(test1.empty());

  test2.swap(test1);

  EXPECT_TRUE(test2.empty());
  EXPECT_EQ(5, test1.size());
}

TEST(TreeModifiersTests, SwapMethodTest3) {
  s21::RBTree<int, int> test1{100};
  s21::RBTree<int, int> test2{50, 1, 99, 10, 80};

  EXPECT_EQ(1, test1.size());
  EXPECT_EQ(5, test2.size());

  test1.swap(test2);

  EXPECT_EQ(5, test1.size());
  EXPECT_EQ(1, test2.size());
}

TEST(TreeModifiersTests, MergeMethodTest1) {
  s21::RBTree<int, int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::RBTree<int, int> test2;

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
}

TEST(TreeModifiersTests, MergeMethodTest2) {
  s21::RBTree<int, int> test1;
  s21::RBTree<int, int> test2{50, 1, 10, 0, 90, 80, 100};

  EXPECT_TRUE(test1.empty());
  EXPECT_FALSE(test2.empty());
  EXPECT_EQ(7, test2.size());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
  EXPECT_EQ(7, test1.size());
}

TEST(TreeModifiersTests, MergeMethodTest3) {
  s21::RBTree<int, int> test1{50, 1, 10, 0, 90, 80, 100};
  s21::RBTree<int, int> test2{50, 1, 10, 0, 90, 80, 100};

  s21::RBTree<int, int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_EQ(iter_test2_before, test2.begin());
  EXPECT_EQ(check1, test1.size());
  EXPECT_EQ(check2, test2.size());
}

TEST(TreeModifiersTests, MergeMethodTest4) {
  s21::RBTree<int, int> test1{50, 1, 90};
  s21::RBTree<int, int> test2{50, 1, 10, 0, 90, 80, 100};

  s21::RBTree<int, int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_FALSE(check1 == test1.size());
  EXPECT_FALSE(check2 == test2.size());

  EXPECT_EQ(7, test1.size());
  EXPECT_EQ(3, test2.size());
}

TEST(TreeModifiersTests, MergeMethodTest5) {
  s21::RBTree<int, int> test1{50, 1, 90, 0, 10, 80, 100};
  s21::RBTree<int, int> test2{55, 11, 110, 30, 95, 85, 105};

  s21::RBTree<int, int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_FALSE(check1 == test1.size());
  EXPECT_FALSE(check2 == test2.size());

  EXPECT_EQ(14, test1.size());
  EXPECT_TRUE(test2.empty());
}