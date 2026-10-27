#pragma once

#include "INewPointCalculating.h"
#include "SearchInformation.h"

/**
 * @brief Класс для вычисления новой точки в интервале для метода Пиявского
 */
class PiyavskyNewPointCalculating : public INewPointCalculating
{
protected:
  SearchInformation* searchInformation;
  bool isUseStartPount;
  
public:
  /**
   * @brief Конструктор
   * @param _searchInformation Указатель на информацию о поиске
   */
  PiyavskyNewPointCalculating(SearchInformation* _searchInformation);

  /**
   * @brief Вычисление новой точки в интервале по формуле Пиявского
   * @param interval Интервал для вычисления
   * @return Указатель на новое испытание
   */
  virtual Trial* ClaculateNewPoint(Interval& interval) override;
};
