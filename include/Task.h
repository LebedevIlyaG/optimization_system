#pragma once
#include "Trial.h"
#include <vector>

/**
 * @brief Класс целевой функции
 * 
 * Представляет задачу оптимизации с заданной размерностью и границами
 */
class Task
{
public:
  /// Размерность задачи
  int dim;
  
  /// Левые границы области поиска
  std::vector<double> A;
  
  /// Правые границы области поиска
  std::vector<double> B;

  /**
   * @brief Конструктор задачи
   * @param _dim Размерность задачи
   * @param _A Левые границы
   * @param _B Правые границы
   */
  Task(int _dim = 1, std::vector<double> _A = {0}, std::vector<double> _B = {1});

  /**
   * @brief Вычисление значения целевой функции
   * @param trial Точка, в которой вычисляется функция
   * @return Значение функции
   */
  double operator () (Trial& trial);
};
