#include "../../tests_main.h"

TEST(BonusMethodsTests, InsertManyTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.insert_many(testing1.begin(), 12, 23, 34, 45, 0);
  testing2.insert_many(testing2.begin(), "asda", "sada", "qwer");

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(3, testing2.size());

  EXPECT_EQ(8, testing1.capacity());
  EXPECT_EQ(4, testing2.capacity());

  EXPECT_EQ(34, testing1[2]);
  EXPECT_EQ("sada", testing2[1]);
}

TEST(BonusMethodsTests, InsertManyTest2) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.insert_many(testing1.begin());
  testing2.insert_many(testing2.begin());

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());

  EXPECT_EQ(0, testing1.capacity());
  EXPECT_EQ(0, testing2.capacity());

  EXPECT_EQ(nullptr, testing1.data());
  EXPECT_EQ(nullptr, testing2.data());
}

TEST(BonusMethodsTests, InsertManyTest3) {
  s21::vector<int> testing1{0, 1, 3, 5, 6};
  s21::vector<std::string> testing2{"UwU", "some"};

  auto it1 = testing1.insert_many(testing1.begin(), 12, 23, 34, 45, 345);
  auto it2 = testing2.insert_many(testing2.begin(), "asda", "sada", "qwer");

  EXPECT_EQ(10, testing1.size());
  EXPECT_EQ(5, testing2.size());

  EXPECT_EQ(10, testing1.capacity());
  EXPECT_EQ(8, testing2.capacity());

  EXPECT_EQ(0, *it1);
  EXPECT_EQ("UwU", *it2);

  EXPECT_EQ(12, *testing1.begin());
  EXPECT_EQ("asda", *testing2.begin());
}

TEST(BonusMethodsTests, InsertManyBackTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.insert_many_back(12, 23, 34, 45, 0);
  testing2.insert_many_back("asda", "sada", "qwer");

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(3, testing2.size());

  EXPECT_EQ(8, testing1.capacity());
  EXPECT_EQ(4, testing2.capacity());

  EXPECT_EQ(34, testing1[2]);
  EXPECT_EQ("sada", testing2[1]);
}

TEST(BonusMethodsTests, InsertManyBackTest2) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.insert_many_back();
  testing2.insert_many_back();

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());

  EXPECT_EQ(0, testing1.capacity());
  EXPECT_EQ(0, testing2.capacity());

  EXPECT_EQ(nullptr, testing1.data());
  EXPECT_EQ(nullptr, testing2.data());
}

TEST(BonusMethodsTests, InsertManyBackTest3) {
  s21::vector<int> testing1{516, 23, 5465};
  s21::vector<std::string> testing2{"qwdq", "e123e"};

  testing1.insert_many_back(0, 1, 2, 3);
  testing2.insert_many_back("sada", "qwerty");

  EXPECT_EQ(7, testing1.size());
  EXPECT_EQ(4, testing2.size());

  EXPECT_EQ(12, testing1.capacity());
  EXPECT_EQ(4, testing2.capacity());

  EXPECT_EQ(3, *(testing1.end() - 1));
  EXPECT_EQ("qwerty", *(testing2.end() - 1));

  EXPECT_EQ(0, testing1[3]);
  EXPECT_EQ("sada", testing2[2]);
}