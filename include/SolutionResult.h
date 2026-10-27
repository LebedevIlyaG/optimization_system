#pragma once

#include "Interval.h"

/**
 * @brief Структура для хранения результата решения задачи оптимизации
 */
class SolutionResult
{
public:
  /// Все выполненные испытания
  std::vector<Trial*> trials;
  
  /// Все интервалы
  std::vector<Interval*> intervals;
  
  /// Лучшая найденная точка
  Trial* bestTrial;
  
  /// Количество итераций
  int iterationCount;
  
  /// Количество испытаний
  int trialCount;
  
  /// Время работы алгоритма (в секундах)
  double time;
};
