#include <gtest/gtest.h>
#include "Extended.h"
#include <cmath>

/**
 * @brief Тесты для класса Extended
 */
class ExtendedTest : public ::testing::Test {
protected:
  void SetUp() override {
    Extended::SetPrecision(0.01);
  }
};

// TODO: Добавить тесты для класса Extended
// - Тест конструкторов
// - Тест арифметических операций
// - Тест операторов сравнения
// - Тест преобразования в double
// - Тест преобразования в строку

TEST_F(ExtendedTest, DefaultConstructor) {
  Extended e;
  EXPECT_EQ(e.toDouble(), 0.0);
}

TEST_F(ExtendedTest, ConstructorWithValue) {
  Extended e(3.14);
  EXPECT_NEAR(e.toDouble(), 3.14, 1e-10);
}

TEST_F(ExtendedTest, Addition) {
  Extended e1(2.5);
  Extended e2(3.5);
  Extended result = e1 + e2;
  EXPECT_NEAR(result.toDouble(), 6.0, 1e-10);
}

TEST_F(ExtendedTest, Subtraction) {
  Extended e1(5.0);
  Extended e2(2.0);
  Extended result = e1 - e2;
  EXPECT_NEAR(result.toDouble(), 3.0, 1e-10);
}

TEST_F(ExtendedTest, Multiplication) {
  Extended e1(2.0);
  Extended e2(3.0);
  Extended result = e1 * e2;
  EXPECT_NEAR(result.toDouble(), 6.0, 1e-10);
}

TEST_F(ExtendedTest, Division) {
  Extended e1(10.0);
  Extended e2(2.0);
  Extended result = e1 / e2;
  EXPECT_NEAR(result.toDouble(), 5.0, 1e-10);
}

TEST_F(ExtendedTest, Comparison) {
  Extended e1(3.0);
  Extended e2(5.0);
  
  EXPECT_TRUE(e1 < e2);
  EXPECT_TRUE(e1 <= e2);
  EXPECT_TRUE(e2 > e1);
  EXPECT_TRUE(e2 >= e1);
  EXPECT_TRUE(e1 != e2);
  EXPECT_FALSE(e1 == e2);
}

TEST_F(ExtendedTest, EqualityComparison) {
  Extended e1(3.14);
  Extended e2(3.14);
  
  EXPECT_TRUE(e1 == e2);
  EXPECT_FALSE(e1 != e2);
}
