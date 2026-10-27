#pragma once
#include "ICharacteristicCalculating.h"
#include "SearchInformation.h"

/**
 * @brief Класс для вычисления характеристики интервала в алгоритме GSA
 */
class GSACharacteristicCalculating : public ICharacteristicCalculating
{
protected:
  SearchInformation* searchInformation;
  bool isUseStartPount;
  
public:
  /**
   * @brief Конструктор
   * @param _searchInformation Указатель на информацию о поиске
   * @param _isUseStartPount Использовать ли начальные точки
   */
  GSACharacteristicCalculating(SearchInformation* _searchInformation, bool _isUseStartPount = true);
  
  /**
   * @brief Вычисление характеристики интервала по формуле GSA
   * @param interval Интервал для вычисления
   * @return Значение характеристики R
   */
  virtual double CalculateCharacteristic(Interval& interval) override;
};
