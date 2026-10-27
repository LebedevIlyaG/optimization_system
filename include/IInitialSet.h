#pragma once
#include "Trial.h"
#include "Task.h"
#include <vector>

/**
 * @brief Интерфейс для генерации начального множества точек
 */
class IInitialSet
{
public:
  /**
   * @brief Генерация начальных точек
   * @return Вектор начальных испытаний
   */
  virtual std::vector<Trial*> GetStartPont() = 0;
  
  virtual ~IInitialSet() = default;
};
