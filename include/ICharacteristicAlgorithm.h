#pragma once
#include "IInitialSet.h"
#include "ICharacteristicCalculating.h"
#include "INewPointCalculating.h"
#include "SearchInformation.h"
#include "Task.h"
#include "SolutionResult.h"

/**
 * @brief Интерфейс алгоритма глобальной оптимизации
 * 
 * Определяет базовый интерфейс для всех алгоритмов характеристик
 */
class ICharacteristicAlgorithm
{
public:
  /**
   * @brief Решение задачи оптимизации
   * @return Результат решения
   */
  virtual SolutionResult Solve() = 0;

  /**
   * @brief Получение результата последнего решения
   * @return Результат решения
   */
  virtual SolutionResult GetSolutionResult() = 0;
  
  virtual ~ICharacteristicAlgorithm() = default;
};
