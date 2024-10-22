#include "../../tests_main.h"

TEST(VectorCapacityTests, EmptyMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());
}

TEST(VectorCapacityTests, EmptyMethodTest2) {
  s21::vector<int> testing1{};
  s21::vector<std::string> testing2{};

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());
}

TEST(VectorCapacityTests, EmptyMethodTest3) {
  s21::vector<int> testing1{321, 43, 56, 0};
  s21::vector<std::string> testing2{"asda", "fwefw", ""};

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());
}

TEST(VectorCapacityTests, SizeMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());
}

TEST(VectorCapacityTests, SizeMethodTest2) {
  s21::vector<int> testing1{89, 23, 435, 45, 0};
  s21::vector<std::string> testing2{"asd", "wefw", "UwU"};

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(3, testing2.size());
}

TEST(VectorCapacityTests, MaxSizeMethodTest) {
  s21::vector<int> testing1{1, 2, 3};
  std::vector<int> check1{1, 2, 3};

  s21::vector<std::string> testing2{"asd", "wefw", "UwU"};
  std::vector<std::string> check2{"asd", "wefw", "UwU"};

  EXPECT_EQ(check1.max_size(), testing1.max_size());
  EXPECT_EQ(check2.max_size(), testing2.max_size());
}

TEST(VectorCapacityTests, ReserveMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.reserve(10);
  testing2.reserve(10);

  EXPECT_EQ(10, testing1.capacity());
  EXPECT_EQ(10, testing2.capacity());
}

TEST(VectorCapacityTests, ReserveMethodTest2) {
  s21::vector<int> testing1{1, 2, 3, 45, 76};
  s21::vector<std::string> testing2{"sdf", "skdjfhnhnsk", "asdjnf", "fsiuedh"};

  testing1.reserve(1);
  testing2.reserve(1);

  EXPECT_EQ(5, testing1.capacity());
  EXPECT_EQ(4, testing2.capacity());
}

TEST(VectorCapacityTests, ReserveMethodTest3) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_ANY_THROW(testing1.reserve(testing1.max_size() + 1));
  EXPECT_ANY_THROW(testing2.reserve(testing2.max_size() + 1));
}

TEST(VectorCapacityTests, ReserveMethodTest4) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  s21::vector<int>::iterator iter1 = testing1.begin();
  s21::vector<std::string>::iterator iter2 = testing2.begin();

  testing1.reserve(10);
  testing2.reserve(10);

  EXPECT_FALSE(testing1.begin() == iter1);
  EXPECT_FALSE(testing2.begin() == iter2);
}

TEST(VectorCapacityTests, ReserveMethodTest5) {
  s21::vector<int> testing1{1, 2, 3, 45, 76};
  s21::vector<std::string> testing2{"sdf", "skdjfhnhnsk", "asdjnf", "fsiuedh"};

  testing1.reserve(10);
  testing2.reserve(10);

  EXPECT_EQ(10, testing1.capacity());
  EXPECT_EQ(10, testing2.capacity());

  EXPECT_EQ(1, testing1.at(0));
  EXPECT_EQ("sdf", testing2.at(0));

  EXPECT_EQ(76, testing1.at(testing1.size() - 1));
  EXPECT_EQ("fsiuedh", testing2.at(testing2.size() - 1));
}

TEST(VectorCapacityTests, CapacityMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  EXPECT_EQ(0, testing1.capacity());
  EXPECT_EQ(0, testing2.capacity());
}

TEST(VectorCapacityTests, CapacityMethodTest2) {
  s21::vector<int> testing1{1, 2, 455, 65, 0};
  s21::vector<std::string> testing2{"asd", "ahsnfduoi", "dasda"};

  EXPECT_EQ(5, testing1.capacity());
  EXPECT_EQ(3, testing2.capacity());
}

TEST(VectorCapacityTests, ShrinkToFitMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.reserve(10);
  testing2.reserve(10);

  testing1.shrink_to_fit();
  testing2.shrink_to_fit();

  EXPECT_EQ(0, testing1.capacity());
  EXPECT_EQ(0, testing2.capacity());
}

TEST(VectorCapacityTests, ShrinkToFitMethodTest2) {
  s21::vector<int> testing1{234, 32, 44};
  s21::vector<std::string> testing2{"fsdd", "Asdfa", ""};

  int check1 = testing1.capacity();
  int check2 = testing2.capacity();

  testing1.reserve(5);
  testing2.reserve(5);

  EXPECT_EQ(5, testing1.capacity());
  EXPECT_EQ(5, testing2.capacity());

  testing1.shrink_to_fit();
  testing2.shrink_to_fit();

  EXPECT_EQ(check1, testing1.capacity());
  EXPECT_EQ(check2, testing2.capacity());
}

TEST(VectorCapacityTests, ShrinkToFitMethodTest3) {
  s21::vector<int> testing1{1, 2, 3, 45, 76};
  s21::vector<std::string> testing2{"sdf", "skdjfhnhnsk", "asdjnf", "fsiuedh"};

  testing1.reserve(10);
  testing2.reserve(10);

  testing1.shrink_to_fit();
  testing2.shrink_to_fit();

  EXPECT_EQ(5, testing1.capacity());
  EXPECT_EQ(4, testing2.capacity());

  EXPECT_EQ(1, testing1.at(0));
  EXPECT_EQ("sdf", testing2.at(0));

  EXPECT_EQ(76, testing1.at(testing1.size() - 1));
  EXPECT_EQ("fsiuedh", testing2.at(testing2.size() - 1));
}

TEST(VectorCapacityTests, ShrinkToFitMethodTest4) {
  s21::vector<int> testing1(10);
  s21::vector<std::string> testing2(5);

  std::vector<int> check1(10);
  std::vector<std::string> check2(5);

  testing1[0] = check1[0] = 678;
  testing2[0] = check2[0] = "sdfsdfs";

  testing1.shrink_to_fit();
  check1.shrink_to_fit();
  testing2.shrink_to_fit();
  check2.shrink_to_fit();

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());
}

TEST(VectorCapacityTests, ShrinkToFitMethodTest5) {
  s21::vector<int> testing1{1, 2, 3};

  s21::vector<int>::iterator iter1 = testing1.begin();

  testing1.shrink_to_fit();

  EXPECT_TRUE(iter1 == testing1.begin());
}