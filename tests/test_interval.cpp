#include <gtest/gtest.h>
#include "Interval.h"
#include "Trial.h"

/**
 * @brief Тесты для класса Interval
 */
class IntervalTest : public ::testing::Test {
protected:
  Trial* t1;
  Trial* t2;
  
  void SetUp() override {
    t1 = new Trial(0.0);
    t2 = new Trial(1.0);
  }
  
  void TearDown() override {
    delete t1;
    delete t2;
  }
};

// TODO: Добавить тесты для класса Interval
// - Тест конструктора по умолчанию
// - Тест установки левой и правой точек
// - Тест оператора сравнения для очереди с приоритетом
// - Тест корректности хранения характеристики R

TEST_F(IntervalTest, DefaultConstructor) {
  Interval interval;
  EXPECT_EQ(interval.left, nullptr);
  EXPECT_EQ(interval.right, nullptr);
  EXPECT_EQ(interval.R, 0.0);
}

TEST_F(IntervalTest, SetPoints) {
  Interval interval;
  interval.left = t1;
  interval.right = t2;
  EXPECT_EQ(interval.left->x, 0.0);
  EXPECT_EQ(interval.right->x, 1.0);
}

TEST_F(IntervalTest, ComparisonOperator) {
  Interval i1, i2;
  i1.R = 10.0;
  i2.R = 5.0;
  
  Interval comp;
  EXPECT_TRUE(comp(&i2, &i1));
}
