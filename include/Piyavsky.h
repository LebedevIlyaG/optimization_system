#pragma once
#include "GSA.h"

/**
 * @brief Метод Пиявского для одномерной оптимизации
 * 
 * Реализует классический метод Пиявского для решения задач
 * одномерной глобальной оптимизации
 */
class Piyavsky : public GSA
{
public:
  /**
   * @brief Конструктор метода Пиявского
   * @param r Константа Липшица (или параметр надежности)
   * @param _eps Точность по размеру интервала
   * @param _maxIterationCount Максимальное количество итераций
   */
  Piyavsky(double r, double _eps, int _maxIterationCount);
  
  /**
   * @brief Деструктор
   */
  ~Piyavsky();

  /**
   * @brief Решение задачи оптимизации методом Пиявского
   * @return Результат решения
   */
  virtual SolutionResult Solve() override;
};
