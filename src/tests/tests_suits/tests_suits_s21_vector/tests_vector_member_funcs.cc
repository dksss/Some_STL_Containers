#include "../../tests_main.h"

TEST(VectorConstructorsTests, DefaultConstructorTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());

  EXPECT_EQ(nullptr, testing1.data());
  EXPECT_EQ(nullptr, testing2.data());
}

TEST(VectorConstructorsTests, ParamConstructorTest1) {
  int num = 5;

  s21::vector<int> testing1(num);
  s21::vector<std::string> testing2(num);

  EXPECT_EQ(num, testing1.size());
  EXPECT_EQ(num, testing2.size());

  EXPECT_EQ(num, testing1.capacity());
  EXPECT_EQ(num, testing2.capacity());

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());

  EXPECT_NE(nullptr, testing1.data());
  EXPECT_NE(nullptr, testing2.data());
}

TEST(VectorConstructorsTests, ParamConstructorTest2) {
  int num = 5;

  std::vector<int> check1(num);
  std::vector<std::string> check2(num);

  s21::vector<int> testing1(num);
  s21::vector<std::string> testing2(num);

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  EXPECT_EQ(check1.empty(), testing1.empty());
  EXPECT_EQ(check2.empty(), testing2.empty());
}

TEST(VectorConstructorsTests, ParamConstructorTest3) {
  int num = 0;

  std::vector<int> check1(num);
  std::vector<std::string> check2(num);

  s21::vector<int> testing1(num);
  s21::vector<std::string> testing2(num);

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  EXPECT_EQ(check1.empty(), testing1.empty());
  EXPECT_EQ(check2.empty(), testing2.empty());
}

TEST(VectorConstructorsTests, InitListConstructorTest1) {
  std::vector<int> check1{};
  std::vector<std::string> check2{};

  s21::vector<int> testing1{};
  s21::vector<std::string> testing2{};

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());
}

TEST(VectorConstructorsTests, InitListConstructorTest2) {
  std::vector<int> check1{0, 1, 2};
  std::vector<std::string> check2{"abc", "def", "ghi"};

  s21::vector<int> testing1{0, 1, 2};
  s21::vector<std::string> testing2{"abc", "def", "ghi"};

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(check1[i], testing1[i]);
    EXPECT_EQ(check2[i], testing2[i]);
  }
}

TEST(VectorConstructorsTests, CopyConstructorTest1) {
  s21::vector<int> base1;
  s21::vector<std::string> base2;

  s21::vector<int> testing1(base1);
  s21::vector<std::string> testing2(base2);

  EXPECT_EQ(base1.size(), testing1.size());
  EXPECT_EQ(base2.size(), testing2.size());

  EXPECT_EQ(base1.empty(), testing1.empty());
  EXPECT_EQ(base2.empty(), testing2.empty());
}

TEST(VectorConstructorsTests, CopyConstructorTest2) {
  s21::vector<int> base1{0, 1, 2};
  s21::vector<std::string> base2{"abc", "def", "ghi"};

  s21::vector<int> testing1(base1);
  s21::vector<std::string> testing2(base2);

  EXPECT_EQ(base1.size(), testing1.size());
  EXPECT_EQ(base2.size(), testing2.size());

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(base1[i], testing1[i]);
    EXPECT_EQ(base2[i], testing2[i]);
  }
}

TEST(VectorConstructorsTests, MoveConstructorTest1) {
  s21::vector<int> base1{0, 1, 2};
  s21::vector<std::string> base2{"abc", "def", "ghi"};

  s21::vector<int> testing1(std::move(base1));
  s21::vector<std::string> testing2(std::move(base2));

  EXPECT_TRUE(base1.empty());
  EXPECT_TRUE(base2.empty());

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(VectorConstructorsTests, MoveAssignmentOperatorTest1) {
  s21::vector<int> base1{0, 1, 2};
  s21::vector<std::string> base2{"abc", "def", "ghi"};

  s21::vector<int> testing1;
  testing1 = std::move(base1);

  s21::vector<std::string> testing2;
  testing2 = std::move(base2);

  EXPECT_TRUE(base1.empty());
  EXPECT_TRUE(base2.empty());

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}