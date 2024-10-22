#include "../../tests_main.h"

/*
 * PrintTree() -- вспомогательный метод, для визуализации дерева
 * (глубина принта =3) (оч костыльная штука {это видно по тому, как он написан})
 *         НЕ НУЖДАЕТСЯ В ТЕСТАХ (оставил как пасхалку)
 */

TEST(TreeLookupTests, ContainsMethodTest1) {
  s21::RBTree<int, int> test;

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));
}

TEST(TreeLookupTests, ContainsMethodTest2) {
  s21::RBTree<int, int> test{50, 0, 80};

  EXPECT_FALSE(test.contains(99));
  EXPECT_FALSE(test.contains(333));
  EXPECT_FALSE(test.contains(-585));

  EXPECT_TRUE(test.contains(50));
  EXPECT_TRUE(test.contains(80));
  EXPECT_TRUE(test.contains(0));
}