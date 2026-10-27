#pragma once
#include "Interval.h"

/**
 * @brief Интерфейс для вычисления новой точки в интервале
 */
class INewPointCalculating
{
public:
  /**
   * @brief Вычисление новой точки в заданном интервале
   * @param interval Интервал, в котором вычисляется новая точка
   * @return Указатель на новое испытание
   */
  virtual Trial* ClaculateNewPoint(Interval& interval) = 0;
  
  virtual ~INewPointCalculating() = default;
};
