#include "GSAInitialSet.h"

GSAInitialSet::GSAInitialSet(Task* _task, Evolvent* _evolvent, int _P)
  : task(_task), evolvent(_evolvent), P(_P)
{
}

std::vector<Trial*> GSAInitialSet::GetStartPont()
{
  // TODO: Реализовать генерацию начального множества точек.
  // Необходимо вернуть 2 + P точек:
  //   - левую границу  (x = 0),
  //   - правую границу (x = 1),
  //   - P внутренних точек, равномерно распределённых по [0, 1].
  // Для каждой точки заполнить y через evolvent->GetImage (если evolvent != nullptr).
  return std::vector<Trial*>();
}
