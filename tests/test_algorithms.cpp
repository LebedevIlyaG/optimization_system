#include <gtest/gtest.h>
#include "GSA.h"
#include "Piyavsky.h"

/**
 * @brief Тесты для алгоритмов оптимизации
 */
class AlgorithmTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Настройка перед тестами
  }
  
  void TearDown() override {
    // Очистка после тестов
  }
};

// TODO: Добавить тесты для алгоритмов оптимизации
// - Тест конструктора GSA
// - Тест конструктора Piyavsky
// - Тест метода Solve() для простых функций
// - Тест корректности результата (количество итераций, испытаний)
// - Тест параллельного выполнения (если доступен OpenMP)

TEST_F(AlgorithmTest, GSAConstructor) {
  int N = 2;
  std::vector<double> A(N, -5.0);
  std::vector<double> B(N, 5.0);
  
  EXPECT_NO_THROW({
    GSA solver(N, 2.0, 0.1, 100, A, B, 2, true);
  });
}

TEST_F(AlgorithmTest, PiyavskyConstructor) {
  EXPECT_NO_THROW({
    Piyavsky solver(2.0, 0.1, 100);
  });
}

TEST_F(AlgorithmTest, GSASolveReturnsResult) {
  int N = 2;
  std::vector<double> A(N, -2.0);
  std::vector<double> B(N, 2.0);
  
  GSA solver(N, 2.0, 0.5, 10, A, B, 1, true);
  SolutionResult result = solver.Solve();
  
  // Проверяем, что результат не пустой
  EXPECT_GE(result.iterationCount, 0);
  EXPECT_GE(result.trialCount, 0);
  EXPECT_GE(result.time, 0.0);
}

TEST_F(AlgorithmTest, PiyavskySolveReturnsResult) {
  Piyavsky solver(2.0, 0.5, 10);
  SolutionResult result = solver.Solve();
  
  // Проверяем, что результат не пустой
  EXPECT_GE(result.iterationCount, 0);
  EXPECT_GE(result.trialCount, 0);
  EXPECT_GE(result.time, 0.0);
}
