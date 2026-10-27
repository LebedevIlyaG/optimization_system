#pragma once

#include "Interval.h"
#include <vector>
#include <queue>

/**
 * @brief Структура для хранения информации о процессе поиска
 * 
 * Содержит все испытания, интервалы, очередь характеристик,
 * лучшую найденную точку и параметры алгоритма
 */
class SearchInformation
{
public:
  /// Все выполненные испытания
  std::vector<Trial*> trials;
  
  /// Все интервалы
  std::vector<Interval*> intervals;
  
  /// Очередь с приоритетом для интервалов (по характеристике R)
  std::priority_queue<Interval*, std::vector<Interval*>, Interval> characteristicQueue;

  /// Лучшая найденная точка
  Trial* bestTrial;

  /// Оценка константы Липшица
  double M;
  
  /// Параметр надежности алгоритма
  double r;
};
