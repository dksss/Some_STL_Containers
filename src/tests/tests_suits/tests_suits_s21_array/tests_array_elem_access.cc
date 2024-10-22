#include "../../tests_main.h"

TEST(ArrayElementAccessTests, AtMethodTest1) {
  s21::array<int, 3> testing1{1, 32, 434};
  s21::array<std::string, 3> testing2{"asd", "qwdda", "asaxcs"};

  EXPECT_ANY_THROW(testing1.at(5));
  EXPECT_ANY_THROW(testing2.at(5));
}

TEST(ArrayElementAccessTests, AtMethodTest2) {
  s21::array<int, 3> testing1{1, 32, 434};
  s21::array<std::string, 3> testing2{"asd", "qwdda", "asaxcs"};

  EXPECT_EQ(32, testing1.at(1));
  EXPECT_EQ("qwdda", testing2.at(1));
}

TEST(ArrayElementAccessTests, BracketsOperatorTest1) {
  s21::array<int, 3> testing1{1, 32, 434};

  EXPECT_EQ(*(testing1.data() + 2), testing1[2]);
}

TEST(ArrayElementAccessTests, BracketsOperatorTest2) {
  s21::array<int, 3> testing1{1, 32, 434};
  s21::array<std::string, 3> testing2{"asd", "qwdda", "asaxcs"};

  EXPECT_EQ(32, testing1[1]);
  EXPECT_EQ("qwdda", testing2[1]);
}

TEST(ArrayElementAccessTests, FrontMethodTest1) {
  s21::array<int, 5> testing1{213, 2, 3, 45, 0};
  s21::array<std::string, 3> testing2{"qwddqw", "wdq", "wde3"};

  EXPECT_EQ(213, testing1.front());
  EXPECT_EQ("qwddqw", testing2.front());
}

TEST(ArrayElementAccessTests, FrontMethodTest2) {
  s21::array<int, 5> testing1{213, 2, 3, 45, 0};
  s21::array<std::string, 3> testing2{"qwddqw", "wdq", "wde3"};

  std::array<int, 5> check1{213, 2, 3, 45, 0};
  std::array<std::string, 3> check2{"qwddqw", "wdq", "wde3"};

  EXPECT_EQ(check1.front(), testing1.front());
  EXPECT_EQ(check2.front(), testing2.front());
}

TEST(ArrayElementAccessTests, BackMethodTest1) {
  s21::array<int, 5> testing1{213, 2, 3, 45, 0};
  s21::array<std::string, 3> testing2{"qwddqw", "wdq", "wde3"};

  EXPECT_EQ(0, testing1.back());
  EXPECT_EQ("wde3", testing2.back());
}

TEST(ArrayElementAccessTests, BackMethodTest2) {
  s21::array<int, 5> testing1{213, 2, 3, 45, 0};
  s21::array<std::string, 3> testing2{"qwddqw", "wdq", "wde3"};

  std::array<int, 5> check1{213, 2, 3, 45, 0};
  std::array<std::string, 3> check2{"qwddqw", "wdq", "wde3"};

  EXPECT_EQ(check1.back(), testing1.back());
  EXPECT_EQ(check2.back(), testing2.back());
}

TEST(ArrayElementAccessTests, DataMethodTest1) {
  s21::array<int, 3> testing1;
  s21::array<std::string, 3> testing2;

  EXPECT_EQ(testing1.begin(), testing1.data());
  EXPECT_EQ(testing2.begin(), testing2.data());
}

TEST(ArrayElementAccessTests, DataMethodTest2) {
  s21::array<int, 3> testing1{1231, 312, 342};
  s21::array<std::string, 3> testing2{"asdqwd", "scascx", "1234"};

  EXPECT_EQ(1231, *testing1.data());
  EXPECT_EQ("asdqwd", *testing2.data());

  EXPECT_EQ(342, *(testing1.data() + 2));
  EXPECT_EQ("1234", *(testing2.data() + 2));
}

TEST(ArrayElementAccessTests, DataMethodTest3) {
  s21::array<int, 3> testing1{1231, 312, 342};
  s21::array<std::string, 3> testing2{"asdqwd", "scascx", "1234"};

  EXPECT_EQ(testing1.begin(), testing1.data());
  EXPECT_EQ(testing2.begin(), testing2.data());
}