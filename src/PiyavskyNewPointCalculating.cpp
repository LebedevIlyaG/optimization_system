#include "PiyavskyNewPointCalculating.h"

PiyavskyNewPointCalculating::PiyavskyNewPointCalculating(SearchInformation* _searchInformation)
  : searchInformation(_searchInformation), isUseStartPount(true)
{
}

Trial* PiyavskyNewPointCalculating::ClaculateNewPoint(Interval& interval)
{
  // TODO: Реализовать вычисление новой точки в интервале по формуле Пиявского:
  //   x_new = 0.5*(x_right + x_left) - (z_right - z_left) / (2*r)
  //   trial->y[0] = x_new
  (void)interval;
  return new Trial();
}
