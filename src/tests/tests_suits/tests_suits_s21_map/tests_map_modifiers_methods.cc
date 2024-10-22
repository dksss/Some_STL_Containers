#include "../../tests_main.h"

TEST(MapModifiersTests, ClearMethodTest1) {
  s21::map<int, int> test;

  test.clear();

  EXPECT_EQ(0, test.size());
}

TEST(MapModifiersTests, ClearMethodTest2) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  test.clear();

  EXPECT_EQ(0, test.size());
  EXPECT_TRUE(test.empty());
}

TEST(MapModifiersTests, EraseMethodTest1) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};
  s21::map<int, int>::iterator iter = test.end();

  EXPECT_EQ(3, test.size());

  --iter;
  test.erase(iter);
  EXPECT_EQ(2, test.size());

  iter = test.begin();
  test.erase(iter);
  EXPECT_EQ(1, test.size());
}

TEST(MapModifiersTests, EraseMethodTest2) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};
  s21::map<int, int>::iterator iter = test.end();

  EXPECT_EQ(3, test.size());

  --iter;  // 40
  --iter;  // 1
  test.erase(iter);
  EXPECT_EQ(2, test.size());
}

TEST(MapModifiersTests, Insert1Test1) {
  s21::map<int, int> test;

  test.insert({55, 55});
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  test.insert({30, 30});
  EXPECT_EQ(2, test.size());

  test.insert({30, 30});
  EXPECT_EQ(2, test.size());

  test.insert({60, 60});
  EXPECT_EQ(3, test.size());
}

TEST(MapModifiersTests, Insert1Test2) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  test.insert({55, 55});
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(4, test.size());

  test.insert({30, 30});
  EXPECT_EQ(5, test.size());

  test.insert({30, 30});
  EXPECT_EQ(5, test.size());

  test.insert({60, 60});
  EXPECT_EQ(6, test.size());
}

TEST(MapModifiersTests, Insert1Test3) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  auto res = test.insert({55, 55});
  EXPECT_EQ(55, *(res.first));

  res = test.insert({30, 30});
  EXPECT_EQ(30, *(res.first));

  res = test.insert({30, 30});
  EXPECT_EQ(false, res.second);
}

TEST(MapModifiersTests, Insert2Test1) {
  s21::map<int, int> test;

  test.insert(55, 55);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  test.insert(30, 30);
  EXPECT_EQ(2, test.size());

  test.insert(30, 30);
  EXPECT_EQ(2, test.size());

  test.insert(60, 60);
  EXPECT_EQ(3, test.size());
}

TEST(MapModifiersTests, Insert2Test2) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  test.insert(55, 55);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(4, test.size());

  test.insert(30, 30);
  EXPECT_EQ(5, test.size());

  test.insert(30, 30);
  EXPECT_EQ(5, test.size());

  test.insert(60, 60);
  EXPECT_EQ(6, test.size());
}

TEST(MapModifiersTests, Insert2Test3) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  auto res = test.insert(55, 55);
  EXPECT_EQ(55, *(res.first));

  res = test.insert(30, 30);
  EXPECT_EQ(30, *(res.first));

  res = test.insert(30, 30);
  EXPECT_EQ(false, res.second);
}

TEST(MapModifiersTests, InsertOrAssignTest1) {
  s21::map<int, int> test;

  test.insert_or_assign(55, 55);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  test.insert_or_assign(30, 30);
  EXPECT_EQ(2, test.size());

  test.insert_or_assign(30, 30);
  EXPECT_EQ(2, test.size());

  test.insert_or_assign(60, 60);
  EXPECT_EQ(3, test.size());
}

TEST(MapModifiersTests, InsertOrAssignTest2) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  test.insert_or_assign(55, 55);
  EXPECT_FALSE(test.empty());
  EXPECT_EQ(4, test.size());

  test.insert_or_assign(30, 30);
  EXPECT_EQ(5, test.size());
  EXPECT_EQ(30, test.at(30));

  test.insert_or_assign(30, 40);
  EXPECT_EQ(5, test.size());
  EXPECT_EQ(40, test.at(30));

  test.insert_or_assign(60, 60);
  EXPECT_EQ(6, test.size());
}

TEST(MapModifiersTests, InsertOrAssignTest3) {
  s21::map<int, int> test{{38, 38}, {1, 1}, {40, 40}};

  auto res = test.insert_or_assign(55, 55);
  EXPECT_EQ(55, *(res.first));

  res = test.insert_or_assign(30, 30);
  EXPECT_EQ(30, *(res.first));

  res = test.insert_or_assign(30, 555);
  EXPECT_EQ(false, res.second);
  EXPECT_EQ(555, test.at(30));
}

TEST(MapModifiersTests, SwapMethodTest1) {
  s21::map<int, int> test1{{50, 1}, {99, 10}, {80, 55}};
  s21::map<int, int> test2;

  s21::map<int, int>::iterator iter_test1_before = test1.end();

  EXPECT_EQ(3, test1.size());
  EXPECT_TRUE(test2.empty());

  test2.swap(test1);
  s21::map<int, int>::iterator iter_test1_after = test1.end();

  EXPECT_TRUE(test1.empty());
  EXPECT_EQ(3, test2.size());
  EXPECT_TRUE(iter_test1_before == iter_test1_after);
}

TEST(MapModifiersTests, SwapMethodTest2) {
  s21::map<int, int> test1;
  s21::map<int, int> test2{{50, 1}, {99, 10}, {80, 55}};

  EXPECT_EQ(3, test2.size());
  EXPECT_TRUE(test1.empty());

  test2.swap(test1);

  EXPECT_TRUE(test2.empty());
  EXPECT_EQ(3, test1.size());
}

TEST(MapModifiersTests, SwapMethodTest3) {
  s21::map<int, int> test1{{100, 100}};
  s21::map<int, int> test2{{50, 1}, {99, 10}, {80, 55}};

  EXPECT_EQ(1, test1.size());
  EXPECT_EQ(3, test2.size());

  test1.swap(test2);

  EXPECT_EQ(3, test1.size());
  EXPECT_EQ(1, test2.size());
}

TEST(MapModifiersTests, MergeMethodTest1) {
  s21::map<int, int> test1{{50, 1}, {10, 0}, {90, 80}};
  s21::map<int, int> test2;

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());

  test1.merge(test2);

  EXPECT_FALSE(test1.empty());
  EXPECT_TRUE(test2.empty());
}

TEST(MapModifiersTests, MergeMethodTest2) {
  s21::map<int, int> test1{{50, 1}, {10, 0}, {90, 80}};
  s21::map<int, int> test2{{50, 1}, {10, 0}, {90, 80}};

  s21::map<int, int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_EQ(iter_test2_before, test2.begin());
  EXPECT_EQ(check1, test1.size());
  EXPECT_EQ(check2, test2.size());
}

TEST(MapModifiersTests, MergeMethodTest3) {
  s21::map<int, int> test1{{50, 50}, {1, 1}, {90, 90}};
  s21::map<int, int> test2{{50, 50}, {1, 1}, {90, 90}, {0, 100}};

  s21::map<int, int>::iterator iter_test2_before = test2.begin();
  size_t check1 = test1.size();
  size_t check2 = test2.size();

  test1.merge(test2);

  EXPECT_FALSE(iter_test2_before == test2.begin());
  EXPECT_FALSE(check1 == test1.size());
  EXPECT_FALSE(check2 == test2.size());

  EXPECT_EQ(4, test1.size());
  EXPECT_EQ(3, test2.size());
}