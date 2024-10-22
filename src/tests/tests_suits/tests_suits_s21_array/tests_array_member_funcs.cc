#include "../../tests_main.h"

TEST(ArrayConstructorsTests, DefaultConstructorTest1) {
  s21::array<int, 5> testing1;
  s21::array<std::string, 5> testing2;

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(5, testing2.size());

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(ArrayConstructorsTests, DefaultConstructorTest2) {
  s21::array<int, 0> testing1;
  s21::array<std::string, 0> testing2;

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());
}

TEST(ArrayConstructorsTests, DefaultConstructorTest3) {
  s21::array<int, 7> testing1;
  s21::array<std::string, 7> testing2;

  std::array<int, 7> check1;
  std::array<std::string, 7> check2;

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.empty(), testing1.empty());
  EXPECT_EQ(check2.empty(), testing2.empty());
}

TEST(ArrayConstructorsTests, ListConstructorTest1) {
  s21::array<int, 5> testing1{123, 329, 98, 545, 232};
  s21::array<std::string, 3> testing2{"qwdqwd", "qwd3", "sdad8jef"};

  std::array<int, 5> check1{123, 329, 98, 545, 232};
  std::array<std::string, 3> check2{"qwdqwd", "qwd3", "sdad8jef"};

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(check1[i], testing1[i]);
  }

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(check2[i], testing2[i]);
  }
}

TEST(ArrayConstructorsTests, ListConstructorTest2) {
  s21::array<int, 3> testing1{34, 54, 2};
  s21::array<std::string, 3> testing2{"qwerty", "1234", "sdcs"};

  EXPECT_EQ(3, testing1.size());
  EXPECT_EQ(3, testing2.size());
}

TEST(ArrayConstructorsTests, CopyConstructorTest1) {
  s21::array<int, 5> base1{23, 545, 0, 1, 999};
  s21::array<std::string, 3> base2{"qwed", "efwse", "ew9fdwe"};

  s21::array<int, 5> testing1(base1);
  s21::array<std::string, 3> testing2(base2);

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(base1[i], testing1[i]);
  }

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(base2[i], testing2[i]);
  }
}

TEST(ArrayConstructorsTests, MoveConstructorTest1) {
  s21::array<int, 5> base1{0, 1, 2, 3, 4};
  s21::array<std::string, 3> base2{"qwerty", "asdfgh", "zxcvbn"};

  s21::array<int, 5> testing1 = std::move(base1);
  s21::array<std::string, 3> testing2 = std::move(base2);

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(i, testing1[i]);
  }

  EXPECT_EQ("qwerty", testing2[0]);
  EXPECT_EQ("asdfgh", testing2[1]);
  EXPECT_EQ("zxcvbn", testing2[2]);
}

TEST(ArrayConstructorsTests, AssignmentOperatorTest1) {
  s21::array<int, 5> base1{0, 1, 2, 3, 4};
  s21::array<std::string, 3> base2{"qwd", "cposd", "dsadc"};

  s21::array<int, 5> testing1;
  testing1 = std::move(base1);
  s21::array<std::string, 3> testing2;
  testing2 = std::move(base2);

  EXPECT_EQ(4, testing1[4]);
  EXPECT_EQ("cposd", testing2[1]);
}