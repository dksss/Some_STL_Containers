#include "../../tests_main.h"

TEST(VectorModifiersTests, ClearMethodTest1) {
  s21::vector<int> testing1{0, 23, 54, 66};
  s21::vector<std::string> testing2{"sdfsf", "fsiudf", "fsefs"};

  testing1.clear();
  testing2.clear();

  EXPECT_EQ(0, testing1.size());
  EXPECT_EQ(0, testing2.size());
}

TEST(VectorModifiersTests, ClearMethodTest2) {
  s21::vector<int> testing1(10);
  s21::vector<std::string> testing2(5);

  std::vector<int> check1(10);
  std::vector<std::string> check2(5);

  testing1.clear();
  testing2.clear();

  check1.clear();
  check2.clear();

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());
}

TEST(VectorModifiersTests, InsertMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  testing1.insert(testing1.begin(), 888);
  testing2.insert(testing2.begin(), "aasd");

  EXPECT_FALSE(testing1.empty());
  EXPECT_FALSE(testing2.empty());

  EXPECT_EQ(888, testing1[0]);
  EXPECT_EQ("aasd", testing2[0]);
}

TEST(VectorModifiersTests, InsertMethodTest2) {
  s21::vector<int> testing1{23, 43, 56, 756};
  s21::vector<std::string> testing2{"asd", "", "rgt"};

  auto it1 = testing1.insert(testing1.end(), 12);
  auto it2 = testing2.insert(testing2.end(), "qwerty");

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(4, testing2.size());

  EXPECT_EQ(12, *it1);
  EXPECT_EQ("qwerty", *it2);
}

TEST(VectorModifiersTests, InsertMethodTest3) {
  s21::vector<int> testing1{23, 43, 56, 756};
  s21::vector<std::string> testing2{"asd", "", "rgt"};

  s21::vector<int>::iterator it1 = testing1.begin();
  s21::vector<std::string>::iterator it2 = testing2.begin();

  testing1.insert(testing1.end(), 12);
  testing2.insert(testing2.end(), "qwerty");

  EXPECT_FALSE(it1 == testing1.begin());
  EXPECT_FALSE(it2 == testing2.begin());

  testing1.reserve(8);
  testing2.reserve(5);

  auto it_check1 = testing1.begin();
  auto it_check2 = testing2.begin();

  EXPECT_TRUE(it_check1 == testing1.begin());
  EXPECT_TRUE(it_check2 == testing2.begin());

  EXPECT_EQ(5, testing1.size());
  EXPECT_EQ(4, testing2.size());

  EXPECT_EQ(12, testing1[4]);
  EXPECT_EQ("qwerty", testing2[3]);
}

TEST(VectorModifiersTests, InsertMethodTest4) {
  s21::vector<int> testing1{23, 43, 56, 756};
  s21::vector<std::string> testing2{"asd", "", "rgt", "poi"};

  std::vector<int> check1{23, 43, 56, 756};
  std::vector<std::string> check2{"asd", "", "rgt", "poi"};

  testing1.insert(testing1.begin(), 123);
  check1.insert(check1.begin(), 123);

  testing2.insert(testing2.begin(), "qwerty");
  check2.insert(check2.begin(), "qwerty");

  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(check1[i], testing1[i]);
    EXPECT_EQ(check2[i], testing2[i]);
  }
}

TEST(VectorModifiersTests, EraseMethodTest1) {
  s21::vector<int> testing1{23, 43, 56, 756};
  s21::vector<std::string> testing2{"asd", "", "rgt"};

  EXPECT_ANY_THROW(testing1.erase(testing1.end()));
  EXPECT_ANY_THROW(testing2.erase(testing2.end()));
}

TEST(VectorModifiersTests, EraseMethodTest2) {
  s21::vector<int> testing1{23, 43, 56, 756};
  s21::vector<std::string> testing2{"asd", "", "rgt"};

  testing1.erase(testing1.begin());
  testing2.erase(testing2.begin());

  EXPECT_EQ(3, testing1.size());
  EXPECT_EQ(2, testing2.size());

  EXPECT_EQ(43, testing1[0]);
  EXPECT_EQ("", testing2[0]);
}

TEST(VectorModifiersTests, PushBackMethodTest1) {
  s21::vector<int> testing1;
  s21::vector<std::string> testing2;

  std::vector<int> check1;
  std::vector<std::string> check2;

  testing1.push_back(0);
  check1.push_back(0);

  testing2.push_back("qwerty");
  check2.push_back("qwerty");

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  EXPECT_EQ(check1[0], testing1[0]);
  EXPECT_EQ(check2[0], testing2[0]);
}

TEST(VectorModifiersTests, PushBackMethodTest2) {
  s21::vector<int> testing1{1, 2, 3};
  s21::vector<std::string> testing2{"sa", "asasd", "sadad"};

  std::vector<int> check1{1, 2, 3};
  std::vector<std::string> check2{"sa", "asasd", "sadad"};

  testing1.push_back(0);
  check1.push_back(0);

  testing2.push_back("qwerty");
  check2.push_back("qwerty");

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(check1[i], testing1[i]);
    EXPECT_EQ(check2[i], testing2[i]);
  }
}

TEST(VectorModifiersTests, PopBackMethodTest1) {
  s21::vector<int> testing1{0, 1, 2, 3};
  s21::vector<std::string> testing2{"aboba", "uwu", "asd", "awqeq"};

  std::vector<int> check1{0, 1, 2, 3};
  std::vector<std::string> check2{"aboba", "uwu", "asd", "awqeq"};

  testing1.pop_back();
  check1.pop_back();

  testing2.pop_back();
  check2.pop_back();

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());

  EXPECT_EQ(check1.capacity(), testing1.capacity());
  EXPECT_EQ(check2.capacity(), testing2.capacity());

  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(check1[i], testing1[i]);
    EXPECT_EQ(check2[i], testing2[i]);
  }
}

TEST(VectorModifiersTests, PopBackMethodTest2) {
  s21::vector<int> testing1{0, 1, 2, 3, 4, 5};
  s21::vector<std::string> testing2{"aboba", "uwu", "asd"};

  std::vector<int> check1{0, 1, 2, 3, 4, 5};
  std::vector<std::string> check2{"aboba", "uwu", "asd"};

  for (size_t i = 0; i < testing1.size(); ++i) {
    testing1.pop_back();
    check1.pop_back();
  }

  for (size_t i = 0; i < testing2.size(); ++i) {
    testing2.pop_back();
    check2.pop_back();
  }

  EXPECT_EQ(check1.size(), testing1.size());
  EXPECT_EQ(check2.size(), testing2.size());
}

TEST(VectorModifiersTests, SwapMethodTest1) {
  s21::vector<int> testing1{0, 1, 2, 3, 4, 5};
  s21::vector<std::string> testing2{"aboba", "uwu", "asd"};

  s21::vector<int> testing11;
  s21::vector<std::string> testing22;

  testing11.swap(testing1);
  testing22.swap(testing2);

  EXPECT_TRUE(testing1.empty());
  EXPECT_TRUE(testing2.empty());

  EXPECT_EQ(6, testing11.size());
  EXPECT_EQ(3, testing22.size());

  EXPECT_EQ(6, testing11.capacity());
  EXPECT_EQ(3, testing22.capacity());
}

TEST(VectorModifiersTests, SwapMethodTest2) {
  s21::vector<int> testing1{0, 1, 2, 3, 4, 5};
  s21::vector<std::string> testing2{"aboba", "uwu", "asd"};

  s21::vector<int> testing11{0};
  s21::vector<std::string> testing22{""};

  testing11.swap(testing1);
  testing22.swap(testing2);

  EXPECT_EQ(6, testing11.size());
  EXPECT_EQ(3, testing22.size());

  EXPECT_EQ(6, testing11.capacity());
  EXPECT_EQ(3, testing22.capacity());

  EXPECT_EQ(1, testing1.size());
  EXPECT_EQ(1, testing2.size());

  EXPECT_EQ(1, testing1.capacity());
  EXPECT_EQ(1, testing2.capacity());

  EXPECT_EQ(0, testing1[0]);
  EXPECT_EQ("", testing2[0]);
}