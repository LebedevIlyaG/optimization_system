#pragma once

#include "Interval.h"

/**
 * @brief Интерфейс для вычисления характеристики интервала
 */
class ICharacteristicCalculating
{
public:
  /**
   * @brief Вычисление характеристики интервала
   * @param interval Интервал для вычисления
   * @return Значение характеристики R
   */
  virtual double CalculateCharacteristic(Interval& interval) = 0;
  
  virtual ~ICharacteristicCalculating() = default;
};
