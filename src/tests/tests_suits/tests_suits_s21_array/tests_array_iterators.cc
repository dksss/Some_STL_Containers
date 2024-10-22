#include "../../tests_main.h"

TEST(ArrayIteratorsTests, BeginMethodTest1) {
  s21::array<int, 5> testing1{2, 23, 23, 34, 898};
  s21::array<std::string, 3> testing2{"qwedqw", "23dd", "09d0qw"};

  EXPECT_EQ(testing1.data(), testing1.begin());
  EXPECT_EQ(testing2.data(), testing2.begin());
}

TEST(ArrayIteratorsTests, BeginMethodTest2) {
  s21::array<int, 5> testing1{2, 23, 23, 34, 898};
  s21::array<std::string, 3> testing2{"qwedqw", "23dd", "09d0qw"};

  EXPECT_EQ(&testing1[0], testing1.begin());
  EXPECT_EQ(&testing2[0], testing2.begin());

  EXPECT_EQ(testing1[0], *testing1.begin());
  EXPECT_EQ(testing2[0], *testing2.begin());
}

TEST(ArrayIteratorsTests, EndMethodTest1) {
  s21::array<int, 5> testing1{2, 23, 23, 34, 898};
  s21::array<std::string, 3> testing2{"qwedqw", "23dd", "09d0qw"};

  EXPECT_EQ(testing1.data() + 5, testing1.end());
  EXPECT_EQ(testing2.data() + 3, testing2.end());
}

TEST(ArrayIteratorsTests, EndMethodTest2) {
  s21::array<int, 5> testing1{2, 23, 23, 34, 898};
  s21::array<std::string, 3> testing2{"qwedqw", "23dd", "09d0qw"};

  EXPECT_EQ(testing1[4], *(testing1.end() - 1));
  EXPECT_EQ(testing2[2], *(testing2.end() - 1));

  EXPECT_EQ(&testing1[5], testing1.end());
  EXPECT_EQ(&testing2[3], testing2.end());
}