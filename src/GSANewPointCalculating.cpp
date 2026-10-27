#include "GSANewPointCalculating.h"

GSANewPointCalculating::GSANewPointCalculating(SearchInformation* _searchInformation, Evolvent* _evolvent, bool _isUseStartPount)
  : searchInformation(_searchInformation), isUseStartPount(_isUseStartPount), evolvent(_evolvent)
{
}

Trial* GSANewPointCalculating::ClaculateNewPoint(Interval& interval)
{
  // TODO: Реализовать вычисление новой точки в интервале по формуле GSA.
  //   x_new = 0.5*(x_right + x_left)
  //           - sign(z_right - z_left)/(2*r) * |(z_right - z_left)/M|^N
  // Затем заполнить y через evolvent->GetImage(x_new, trial->y.data()).
  (void)interval;
  return new Trial();
}
