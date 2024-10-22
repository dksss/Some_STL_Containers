#include "../../tests_main.h"

TEST(MapLookupTests, ContainsMethodTest1) {
  s21::map<int, int> test;

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));
}

TEST(MapLookupTests, ContainsMethodTest2) {
  s21::map<int, int> test{{50, 50}, {0, 0}, {80, 80}};

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));

  EXPECT_TRUE(test.contains(50));
  EXPECT_TRUE(test.contains(80));
  EXPECT_TRUE(test.contains(0));
}