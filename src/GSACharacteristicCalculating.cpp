#include "GSACharacteristicCalculating.h"

GSACharacteristicCalculating::GSACharacteristicCalculating(SearchInformation* _searchInformation, bool _isUseStartPount)
  : searchInformation(_searchInformation), isUseStartPount(_isUseStartPount)
{
}

double GSACharacteristicCalculating::CalculateCharacteristic(Interval& interval)
{
  // TODO: Реализовать вычисление характеристики интервала по формуле GSA (метод Стронгина).
  //   dx = (x_right - x_left)^(1/N)
  //   R  = dx + (z_right - z_left)^2 / (r^2 * M^2 * dx)
  //           - 2 * (z_right + z_left - 2*z_best) / (r * M)
  // Для граничных интервалов используется упрощённая формула.
  (void)interval;
  return 0.0;
}
