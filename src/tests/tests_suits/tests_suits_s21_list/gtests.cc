#include "../../tests_main.h"
class someFixture : public testing::Test {
 protected:
  std::list<float> orig = {-1, -1, 0.99, 1.99, 2.5, 2.5, 0.99, 0.99, -2, -2};
  s21::list<float> myList = {-1, -1, 0.99, 1.99, 2.5, 2.5, 0.99, 0.99, -2, -2};

  std::string captureOutput(std::list<double> &list) {
    testing::internal::CaptureStdout();
    for (double num : list) std::cout << num << " ";
    std::string temp = testing::internal::GetCapturedStdout();
    std::cout << temp << std::endl;
    return temp;
  }

  std::string captureOutput(s21::list<double> &list) {
    testing::internal::CaptureStdout();
    for (double num : list) std::cout << num << " ";
    std::string temp = testing::internal::GetCapturedStdout();
    std::cout << temp << std::endl;
    return temp;
  }

  std::string captureOutput(std::list<float> &list) {
    testing::internal::CaptureStdout();
    for (float num : list) std::cout << num << " ";
    std::string temp = testing::internal::GetCapturedStdout();
    std::cout << temp << std::endl;
    return temp;
  }

  std::string captureOutput(s21::list<float> &list) {
    testing::internal::CaptureStdout();
    for (float num : list) std::cout << num << " ";
    std::string temp = testing::internal::GetCapturedStdout();
    std::cout << temp << std::endl;
    return temp;
  }
};
TEST_F(someFixture, justOutput) {
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}
TEST_F(someFixture, sortFunc) {
  orig.sort();
  myList.sort();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}
TEST_F(someFixture, uniqueFunc) {
  orig.unique();
  myList.unique();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}
TEST_F(someFixture, reverseFunc) {
  orig.reverse();
  myList.reverse();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}
TEST_F(someFixture, spliceFunc) {
  std::list<float> orig2 = {7, 8, 9};
  orig.splice(orig.begin(), orig2);

  s21::list<float> myList2 = {7, 8, 9};
  myList.splice(myList.begin(), myList2);

  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}
TEST_F(someFixture, spliceFunc2) {
  std::list<float> orig2 = {7, 8, 9};
  orig.splice(orig.end(), orig2);

  s21::list<float> myList2 = {7, 8, 9};
  myList.splice(myList.end(), myList2);

  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, mergeFunc) {
  std::list<float> orig2 = {7, 8, 9};
  orig.merge(orig2);

  s21::list<float> myList2 = {7, 8, 9};
  myList.merge(myList2);

  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, swapFunc) {
  std::list<float> orig2 = {7, 8, 9};
  orig.swap(orig2);

  s21::list<float> myList2 = {7, 8, 9};
  myList.swap(myList2);

  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, popFrontFunc) {
  orig.pop_front();
  myList.pop_front();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, pushFrontFunc) {
  orig.push_front(77);
  myList.push_front(77);
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, popBackFunc) {
  orig.pop_back();
  myList.pop_back();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, pushBackFunc) {
  orig.push_back(77);
  myList.push_back(77);
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, eraseFunc) {
  auto iterOrig = orig.begin();
  auto iterMy = myList.begin();
  orig.erase(iterOrig);
  myList.erase(iterMy);
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, insertFunc) {
  auto iterOrig = orig.begin();
  auto iterMy = myList.begin();
  iterOrig++;
  iterMy++;
  orig.insert(iterOrig, 88);
  myList.insert(iterMy, 88);
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, clearFunc) {
  orig.clear();
  myList.clear();
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, sizeFunc) {
  std::cout << orig.size() << "\n";
  std::cout << myList.size() << "\n";
  EXPECT_EQ(orig.size(), myList.size());
}

TEST_F(someFixture, emptyFunc) { EXPECT_EQ(orig.empty(), myList.empty()); }

TEST_F(someFixture, backFunc) {
  std::cout << orig.back() << "\n";
  std::cout << myList.back() << "\n";
  EXPECT_EQ(orig.back(), myList.back());
}
TEST_F(someFixture, frontFunc) {
  std::cout << orig.front() << "\n";
  std::cout << myList.front() << "\n";
  EXPECT_EQ(orig.front(), myList.front());
}

TEST_F(someFixture, assignmentOperator) {
  std::list<float> orig2 = {7, 8, 9};
  orig = std::move(orig2);
  s21::list<float> myList2 = {7, 8, 9};
  myList = std::move(myList2);
  EXPECT_EQ(captureOutput(orig), captureOutput(myList));
}

TEST_F(someFixture, insertManyFunc) {
  std::list<double> orig2 = {-1,  88.0, 99.0, -1,   0.99, 1.99,
                             2.5, 2.5,  0.99, 0.99, -2,   -2};
  s21::list<double> myList2 = {-1,  -1,   0.99, 1.99, 2.5,
                               2.5, 0.99, 0.99, -2,   -2};
  s21::list<double>::ListIterator iterMy = myList2.begin();
  iterMy++;
  iterMy++;
  iterMy--;
  myList2.insert_many(iterMy, 88.0, 99.0);
  EXPECT_EQ(captureOutput(orig2), captureOutput(myList2));
}

TEST_F(someFixture, insertManyFront) {
  std::list<double> orig2 = {88.0, 99.0, -1,   0.99, 1.99, 2.5,
                             2.5,  0.99, 0.99, -2,   -2};
  s21::list<double> myList2 = {-1, 0.99, 1.99, 2.5, 2.5, 0.99, 0.99, -2, -2};
  myList2.insert_many_front(88.0, 99.0);
  EXPECT_EQ(captureOutput(orig2), captureOutput(myList2));
}
TEST_F(someFixture, insertManyBack) {
  std::list<double> orig2 = {-1,   0.99, 1.99, 2.5,  2.5, 0.99,
                             0.99, -2,   -2,   88.0, 99.0};
  s21::list<double> myList2 = {-1, 0.99, 1.99, 2.5, 2.5, 0.99, 0.99, -2, -2};
  myList2.insert_many_back(88.0, 99.0);
  EXPECT_EQ(captureOutput(orig2), captureOutput(myList2));
}

TEST_F(someFixture, constructors_other) {
  std::list<double> orig2 = {-2, 88.0, 99.0};
  s21::list<double> myList2;
  s21::list<double> myList3(3);
  myList3 = {-2, 88.0, 99.0};
  EXPECT_EQ(captureOutput(orig2), captureOutput(myList3));
}

TEST_F(someFixture, copy_constructor) {
  std::list<double> orig2 = {-2, 88.0, 99.0};
  s21::list<double> myList2 = {-2, 88.0, 99.0};
  s21::list<double> myList3(myList2);
  EXPECT_EQ(captureOutput(orig2), captureOutput(myList3));
}

TEST_F(someFixture, maxSizeFunc) { myList.max_size(); }