#include "Interval.h"

Interval::Interval() : left(nullptr), right(nullptr), R(0), numberCreate(0)
{
}

Interval::~Interval()
{
  left = nullptr;
  right = nullptr;
}

bool Interval::operator()(const Interval* a, const Interval* b)
{
  return a->R < b->R;
}
