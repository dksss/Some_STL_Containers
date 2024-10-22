#include "../../tests_main.h"

TEST(MapElementAccessTests, MethodAtTest1) {
  s21::map<int, int> test;

  EXPECT_ANY_THROW(test.at(21));
}

TEST(MapElementAccessTests, MethodAtTest2) {
  s21::map<int, int> test{{55, 55}, {22, 22}, {66, 66}};

  EXPECT_ANY_THROW(test.at(21));
}

TEST(MapElementAccessTests, MethodAtTest3) {
  s21::map<int, int> test{{55, 55}, {21, 2121}, {66, 66}};
  int check = 2121;

  EXPECT_EQ(check, test.at(21));
}

TEST(MapElementAccessTests, MethodAtTest4) {
  s21::map<int, int> test{{55, 55}, {21, 2121}, {66, 66}};
  int check = 3333;

  test.at(21) = 3333;

  EXPECT_EQ(check, test.at(21));
}

TEST(MapElementAccessTests, BracketsOperatorTest1) {
  s21::map<int, int> test{{55, 55}, {21, 2121}, {66, 66}};
  size_t check = test.size();

  test[22] = check;

  EXPECT_FALSE(test.size() == check);
  EXPECT_EQ(4, test.size());
}

TEST(MapElementAccessTests, BracketsOperatorTest2) {
  s21::map<int, int> test{{55, 55}, {21, 2121}, {66, 66}};
  size_t check = test.size();

  test[23] = 555;

  EXPECT_FALSE(test.size() == check);
  EXPECT_EQ(4, test.size());

  EXPECT_EQ(555, test.at(23));
}

TEST(MapElementAccessTests, BracketsOperatorTest3) {
  s21::map<int, int> test;

  EXPECT_TRUE(test.empty());

  test[21] = 21;

  EXPECT_FALSE(test.empty());
  EXPECT_EQ(1, test.size());

  EXPECT_EQ(21, test.at(21));
}

TEST(MapElementAccessTests, BracketsOperatorTest4) {
  s21::map<int, int> test{{55, 55}, {21, 2121}, {66, 66}};
  size_t check = test.size();

  test[21] = 555;

  EXPECT_TRUE(test.size() == check);
  EXPECT_EQ(555, test.at(21));
}