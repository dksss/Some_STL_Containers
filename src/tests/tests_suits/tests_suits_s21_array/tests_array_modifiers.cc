#include "../../tests_main.h"

TEST(ArrayModifiersTests, SwapMethodTest) {
  s21::array<int, 5> testing1{1, 2, 3, 4, 5};
  s21::array<std::string, 3> testing2{"abc", "def", "ghi"};

  s21::array<int, 5> testing11{123, 345, 567, 789, 0};
  s21::array<std::string, 3> testing22{"qwerty", "asdfg", "zxcvb"};

  testing1.swap(testing11);
  testing2.swap(testing22);

  EXPECT_EQ(123, testing1[0]);
  EXPECT_EQ("qwerty", testing2[0]);

  EXPECT_EQ(1, testing11[0]);
  EXPECT_EQ("abc", testing22[0]);
}

TEST(ArrayModifiersTests, FillMethodTest1) {
  s21::array<int, 5> testing1;
  s21::array<std::string, 5> testing2;

  testing1.fill(555);
  testing2.fill("asap");

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(555, testing1[i]);
    EXPECT_EQ("asap", testing2[i]);
  }
}

TEST(ArrayModifiersTests, FillMethodTest2) {
  s21::array<int, 5> testing1{48, 23, 3443, 23, 111};
  s21::array<std::string, 5> testing2{"sad", "qwd", "123", "ascx", "dwe98"};

  testing1.fill(357);
  testing2.fill("gold");

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(357, testing1[i]);
    EXPECT_EQ("gold", testing2[i]);
  }
}