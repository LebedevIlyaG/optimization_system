#include "PiyavskyCharacteristicCalculating.h"

PiyavskyCharacteristicCalculating::PiyavskyCharacteristicCalculating(SearchInformation* _searchInformation)
  : searchInformation(_searchInformation), isUseStartPount(true)
{
}

double PiyavskyCharacteristicCalculating::CalculateCharacteristic(Interval& interval)
{
  // TODO: Реализовать вычисление характеристики интервала по формуле Пиявского:
  //   R = 0.5 * r * (x_right - x_left) - (z_right + z_left) / 2
  (void)interval;
  return 0.0;
}
