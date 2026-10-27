#include "Trial.h"

int Trial::TrialNumberCreate = 0;

Trial::Trial(double _x) : x(_x), numberCreate(TrialNumberCreate)
{
  y.resize(1);
  y[0] = x;
  z.resize(1);
  TrialNumberCreate++;
}

Trial::Trial(std::vector<double> _y) : y(_y), numberCreate(TrialNumberCreate)
{
  x = y[0];
  z.resize(1);
  TrialNumberCreate++;
}

Trial::Trial(const Trial& p) : x(p.x), y(p.y), z(p.z), numberCreate(TrialNumberCreate)
{
  TrialNumberCreate++;
}
