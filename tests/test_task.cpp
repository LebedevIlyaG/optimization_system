#include <gtest/gtest.h>
#include "Task.h"
#include "Trial.h"
#include <cmath>

/**
 * @brief Тесты для класса Task
 */
class TaskTest : public ::testing::Test {
protected:
  Task* task;
  
  void SetUp() override {
    task = new Task(2, {-5.0, -5.0}, {5.0, 5.0});
  }
  
  void TearDown() override {
    delete task;
  }
};

// TODO: Добавить тесты для класса Task
// - Тест конструктора
// - Тест вычисления функции Растригина
// - Тест вычисления в известных точках (например, в минимуме)
// - Тест корректности размерности

TEST_F(TaskTest, Constructor) {
  EXPECT_EQ(task->dim, 2);
  EXPECT_EQ(task->A[0], -5.0);
  EXPECT_EQ(task->B[1], 5.0);
}

TEST_F(TaskTest, FunctionCalculation) {
  Trial trial;
  trial.y = {0.0, 0.0};
  double value = (*task)(trial);
  
  // В точке (0, 0) функция Растригина должна быть равна 0
  EXPECT_NEAR(value, 0.0, 1e-10);
}

TEST_F(TaskTest, FunctionNonZeroPoint) {
  Trial trial;
  trial.y = {1.0, 1.0};
  double value = (*task)(trial);
  
  // В точке (1, 1) значение должно быть положительным
  EXPECT_GT(value, 0.0);
}
