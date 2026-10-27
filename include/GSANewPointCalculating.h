#pragma once

#include "INewPointCalculating.h"
#include "SearchInformation.h"
#include "Evolvent.h"

/**
 * @brief Класс для вычисления новой точки в интервале для алгоритма GSA
 */
class GSANewPointCalculating : public INewPointCalculating
{
protected:
  SearchInformation* searchInformation;
  bool isUseStartPount;
  Evolvent* evolvent;
  
public:
  /**
   * @brief Конструктор
   * @param _searchInformation Указатель на информацию о поиске
   * @param _evolvent Указатель на развертку Пеано
   * @param _isUseStartPount Использовать ли начальные точки
   */
  GSANewPointCalculating(SearchInformation* _searchInformation, Evolvent* _evolvent, bool _isUseStartPount = true);

  /**
   * @brief Вычисление новой точки в интервале по формуле GSA
   * @param interval Интервал для вычисления
   * @return Указатель на новое испытание
   */
  virtual Trial* ClaculateNewPoint(Interval& interval) override;
};
