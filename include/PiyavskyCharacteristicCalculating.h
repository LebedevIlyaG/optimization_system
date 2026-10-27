#pragma once
#include "ICharacteristicCalculating.h"
#include "SearchInformation.h"

/**
 * @brief Класс для вычисления характеристики интервала в методе Пиявского
 */
class PiyavskyCharacteristicCalculating : public ICharacteristicCalculating
{
protected:
  SearchInformation* searchInformation;
  bool isUseStartPount;
  
public:
  /**
   * @brief Конструктор
   * @param _searchInformation Указатель на информацию о поиске
   */
  PiyavskyCharacteristicCalculating(SearchInformation* _searchInformation);
  
  /**
   * @brief Вычисление характеристики интервала по формуле Пиявского
   * @param interval Интервал для вычисления
   * @return Значение характеристики R
   */
  virtual double CalculateCharacteristic(Interval& interval) override;
};
