#include "../../tests_main.h"

TEST(AccessTests, AtMethodTest1) {
  s21::vector<int> testing1{1, 2, 3, 4, 5};
  const s21::vector<std::string> testing2{"sdifc", "sdj", "dscs"};

  EXPECT_ANY_THROW(testing1.at(8));
  EXPECT_ANY_THROW(testing2.at(8));
}

TEST(AccessTests, AtMethodTest2) {
  s21::vector<int> testing1{1, 2, 3, 4, 5};
  const s21::vector<std::string> testing2{"avf", "fhs", "jnkl"};

  EXPECT_ANY_THROW(testing1.at(testing1.size()));
  EXPECT_ANY_THROW(testing2.at(testing2.size()));
}

TEST(AccessTests, AtMethodTest3) {
  s21::vector<int> testing1{1, 22, 3, 4, 5};
  const s21::vector<std::string> testing2{"avf", "fhs", "jnkl"};

  EXPECT_EQ(22, testing1.at(1));
  EXPECT_EQ("jnkl", testing2.at(2));
}

TEST(AccessTests, AtMethodTest4) {
  s21::vector<int> base1{1, 22, 3, 456, 5};
  s21::vector<s21::vector<int>> testing1{base1};

  const s21::vector<std::string> base2{"asdc", "sa", "123"};
  const s21::vector<s21::vector<std::string>> testing2{base2};

  EXPECT_EQ(1, testing1.size());
  EXPECT_EQ(1, testing2.size());

  EXPECT_EQ(456, testing1.at(0).at(3));
  EXPECT_EQ("123", testing2.at(0).at(2));
}

TEST(AccessTests, OperatorSquareBracetsTest1) {
  s21::vector<int> testing1{1, 22, 3, 4, 5};
  s21::vector<std::string> testing2{"asfas", "asfs", "erte"};

  EXPECT_EQ(testing1.data() + 8, &testing1[8]);
  EXPECT_EQ(testing1.data() + 15, &testing1[15]);

  EXPECT_EQ(testing2.data() + 8, &testing2[8]);
  EXPECT_EQ(testing2.data() + 15, &testing2[15]);
}

TEST(AccessTests, OperatorSquareBracetsTest2) {
  s21::vector<int> testing1{1, 22, 3, 4, 5};
  s21::vector<std::string> testing2{"avf", "fhs", "jnkl"};

  EXPECT_EQ(testing1.data() + testing1.size(), &testing1[testing1.size()]);
  EXPECT_EQ(testing2.data() + testing2.size(), &testing2[testing2.size()]);
}

TEST(AccessTests, OperatorSquareBracetsTest3) {
  s21::vector<int> testing1{1, 22, 3, 4, 5};
  const s21::vector<std::string> testing2{"avf", "fhs", "jnkl"};

  EXPECT_EQ(22, testing1[1]);
  EXPECT_EQ("jnkl", testing2[2]);
}

TEST(AccessTests, FrontMethodTest1) {
  s21::vector<int> testing1{12, 3245, 23, 5};
  std::vector<int> vec1{12, 3245, 23, 5};

  s21::vector<std::string> testing2{"adfs", "", "wergf", "123"};
  std::vector<std::string> vec2{"adfs", "", "wergf", "123"};

  EXPECT_EQ(vec1.front(), testing1.front());
  EXPECT_EQ(vec2.front(), testing2.front());
}

TEST(AccessTests, FrontMethodTest2) {
  s21::vector<int> testing1{12, 3245, 23, 5};
  s21::vector<std::string> testing2{"adfs", "", "wergf", "123"};

  EXPECT_EQ(*testing1.begin(), testing1.front());
  EXPECT_EQ(*testing2.begin(), testing2.front());
}

TEST(AccessTests, BackMethodTest1) {
  s21::vector<int> testing1{12, 3245, 23, 5};
  std::vector<int> vec1{12, 3245, 23, 5};

  s21::vector<std::string> testing2{"adfs", "", "wergf", "123"};
  std::vector<std::string> vec2{"adfs", "", "wergf", "123"};

  EXPECT_EQ(vec1.back(), testing1.back());
  EXPECT_EQ(vec2.back(), testing2.back());
}

TEST(AccessTests, BackMethodTest2) {
  s21::vector<int> testing1{12, 3245, 23, 5};
  s21::vector<std::string> testing2{"adfs", "", "wergf", "123"};

  EXPECT_EQ(*(testing1.end() - 1), testing1.back());
  EXPECT_EQ(*(testing2.end() - 1), testing2.back());
}

TEST(AccessTests, DataMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_EQ(nullptr, testing1.data());
  EXPECT_EQ(nullptr, testing2.data());
}

TEST(AccessTests, DataMethodTest2) {
  s21::vector<int> testing1{12, 43, 456, 0};
  std::vector<int> check1{12, 43, 456, 0};

  s21::vector<std::string> testing2{"sads", "erg98", "fwef"};
  std::vector<std::string> check2{"sads", "erg98", "fwef"};

  EXPECT_EQ(*check1.data(), *testing1.data());
  EXPECT_EQ(*check2.data(), *testing2.data());
}

TEST(AccessTests, DataMethodTest3) {
  s21::vector<int> testing1{12, 43, 456, 0};
  s21::vector<std::string> testing2{"sads", "erg98", "fwef"};

  EXPECT_EQ(&testing1.at(0), testing1.data());
  EXPECT_EQ(&testing2.at(0), testing2.data());
}