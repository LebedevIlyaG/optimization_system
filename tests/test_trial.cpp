#include <gtest/gtest.h>
#include "Trial.h"

/**
 * @brief Тесты для класса Trial
 */
class TrialTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Сброс счетчика для каждого теста
  }
};

// TODO: Добавить тесты для класса Trial
// - Тест конструктора по умолчанию
// - Тест конструктора с параметром x
// - Тест конструктора с вектором y
// - Тест конструктора копирования
// - Тест корректности заполнения полей

TEST_F(TrialTest, DefaultConstructor) {
  Trial t;
  EXPECT_EQ(t.x, 0.0);
  EXPECT_EQ(t.y.size(), 1);
  EXPECT_EQ(t.z.size(), 1);
}

TEST_F(TrialTest, ConstructorWithX) {
  Trial t(0.5);
  EXPECT_EQ(t.x, 0.5);
  EXPECT_EQ(t.y[0], 0.5);
}

TEST_F(TrialTest, CopyConstructor) {
  Trial t1(0.7);
  Trial t2(t1);
  EXPECT_EQ(t2.x, t1.x);
  EXPECT_EQ(t2.y[0], t1.y[0]);
}
