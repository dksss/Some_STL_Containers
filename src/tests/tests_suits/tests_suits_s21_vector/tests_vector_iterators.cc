#include "../../tests_main.h"

TEST(VectorIteratorsTests, BeginMethodTest1) {
  const s21::vector<int> testing1{123, 43, 46};
  s21::vector<std::string> testing2{"sae", "ergre", "erge3"};

  EXPECT_EQ(123, *testing1.begin());
  EXPECT_EQ("sae", *testing2.begin());
}

TEST(VectorIteratorsTests, BeginMethodTest2) {
  s21::vector<int> base;

  s21::vector<int>::iterator iter1 = base.begin();
  s21::vector<int>::const_iterator iter2 = base.begin();

  EXPECT_EQ(iter1, base.end());
  EXPECT_EQ(iter2, base.end());
}

TEST(VectorIteratorsTests, EndMethodTest1) {
  s21::vector<int> base1{123, 43, 46};
  s21::vector<std::string> base2{"sae", "ergre", "erge3"};

  s21::vector<int>::iterator iter1 = base1.end();
  s21::vector<std::string>::iterator iter2 = base2.end();

  EXPECT_EQ(46, *(--iter1));
  EXPECT_EQ("erge3", *(--iter2));
}

TEST(VectorIteratorsTests, EndMethodTest2) {
  const s21::vector<int> base1{123, 43, 46};
  s21::vector<std::string> base2{"sae", "ergre", "erge3"};

  s21::vector<int>::const_iterator iter1 = base1.end();
  s21::vector<std::string>::iterator iter2 = base2.end();

  EXPECT_EQ(base1.begin() + 3, iter1);
  EXPECT_EQ(base2.begin() + 3, iter2);
}

TEST(VectorIteratorsTests, EndMethodTest3) {
  const s21::vector<int> base1;
  s21::vector<std::string> base2;

  s21::vector<int>::const_iterator iter1 = base1.end();
  s21::vector<std::string>::iterator iter2 = base2.end();

  EXPECT_EQ(base1.begin(), iter1);
  EXPECT_EQ(base2.begin(), iter2);
}