#include "../../tests_main.h"

TEST(MapBonusTests, InsertManyTest1) {
  s21::map<int, int> test;

  EXPECT_TRUE(test.empty());

  std::pair<int, int> pair1 = {1, 10};
  std::pair<int, int> pair2 = {9, 90};
  test.insert_many(pair1, pair2);

  EXPECT_EQ(2, test.size());
}

TEST(MapBonusTests, InsertManyTest2) {
  s21::map<int, int> testing_bonus{{5, 50}};

  EXPECT_EQ(1, testing_bonus.size());

  std::pair<int, int> pair1 = {1, 10};
  std::pair<int, int> pair2 = {9, 90};
  testing_bonus.insert_many(pair1, pair2);

  EXPECT_EQ(3, testing_bonus.size());
}

TEST(MapBonusTests, InsertManyTest3) {
  s21::map<int, int> testing_bonus{{5, 50}};

  EXPECT_EQ(1, testing_bonus.size());

  std::pair<int, int> pair0 = {5, 55};
  std::pair<int, int> pair1 = {1, 10};
  std::pair<int, int> pair2 = {9, 90};
  auto result = testing_bonus.insert_many(pair0, pair1, pair2);

  EXPECT_EQ(3, testing_bonus.size());

  EXPECT_EQ(false, result[1].second);

  auto iter = result[1].first;
  EXPECT_EQ(50, *iter);

  EXPECT_EQ(3, result.size());
}