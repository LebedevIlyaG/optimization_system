#include "Evolvent.h"
#include <cstring>

// ------------------------------------------------------------------------------------------------
Evolvent::Evolvent(int _N, int _m) : extNull(0.0), extOne(1.0), extHalf(0.5)
{
  if ((_N < 1) || (_N > MaxDim))
    throw -1;
  N = _N;
  y = new double[N];

  if ((_m < 2) || (_m > MaxM))
    throw -1;
  m = _m;

  nexpExtended = extOne;
  for (int i = 0; i < N; i++)
    nexpExtended += nexpExtended;
}

// ------------------------------------------------------------------------------------------------
Evolvent::~Evolvent()
{
  delete[] y;
}

// ------------------------------------------------------------------------------------------------
Evolvent::Evolvent(const Evolvent& evolvent) : extNull(0.0), extOne(1.0), extHalf(0.5)
{
  N = evolvent.N;
  y = new double[N];
  m = evolvent.m;
  nexpExtended = evolvent.nexpExtended;

  for (int i = 0; i < N; i++)
  {
    A[i] = evolvent.A[i];
    B[i] = evolvent.B[i];
  }
}

// ------------------------------------------------------------------------------------------------
Evolvent& Evolvent::operator=(const Evolvent& evolvent)
{
  if (N != evolvent.N)
  {
    N = evolvent.N;
    if (y)
      delete[] y;
    y = new double[N];
  }
  m = evolvent.m;
  nexpExtended = evolvent.nexpExtended;

  for (int i = 0; i < N; i++)
  {
    A[i] = evolvent.A[i];
    B[i] = evolvent.B[i];
  }

  return *this;
}

// ----------------------------------------------------------------------------
void Evolvent::SetBounds(const double* _A, const double* _B)
{
  for (int i = 0; i < N; i++)
  {
    A[i] = _A[i];
    B[i] = _B[i];
  }
}

// ----------------------------------------------------------------------------
void Evolvent::CalculateNumbr(Extended *s, long long *u, long long *v, long long *l)
{
  // TODO: Вычислить номер узла s(u), индекс активной координаты l(u) и вектор v(u).
  (void)u; (void)v;
  *s = extNull;
  *l = 0;
}

// ----------------------------------------------------------------------------
void Evolvent::CalculateNode(Extended is, int n, long long *u, long long *v, long long *l)
{
  // TODO: Вычислить u[s], v[s], l[s] по номеру узла s = is.
  (void)is;
  *l = 0;
  for (int i = 0; i < n; i++)
  {
    u[i] = -1;
    v[i] = -1;
  }
}

// ------------------------------------------------------------------------------------------------
void Evolvent::transform_P_to_D()
{
  // TODO: Преобразование из гиперкуба P в гиперинтервал D:
  //   y[i] = y[i] * (B[i] - A[i]) + (A[i] + B[i]) / 2
}

// ----------------------------------------------------------------------------
void Evolvent::transform_D_to_P()
{
  // TODO: Преобразование из гиперинтервала D в гиперкуб P:
  //   y[i] = (y[i] - (A[i] + B[i]) / 2) / (B[i] - A[i])
}

// ----------------------------------------------------------------------------
double* Evolvent::GetYOnX(const Extended& _x)
{
  // TODO: Реализовать прямое отображение развёртки Пеано (x -> y).
  (void)_x;
  for (int i = 0; i < N; i++)
    y[i] = 0.0;
  return y;
}

//-----------------------------------------------------------------------------
Extended Evolvent::GetXOnY()
{
  // TODO: Реализовать обратное отображение развёртки Пеано (y -> x).
  return extNull;
}

//----------------------------------------------------------------------------
void Evolvent::GetImage(const Extended& x, double* _y, int EvolventNum)
{
  (void)EvolventNum;
  if ((x.toDouble() < 0) || (x.toDouble() > 1))
    throw -1;

  GetYOnX(x);
  transform_P_to_D();
  memcpy(_y, y, N * sizeof(double));
}

//----------------------------------------------------------------------------
void Evolvent::GetInverseImage(double* _y, Extended& x)
{
  memcpy(y, _y, N * sizeof(double));
  transform_D_to_P();
  x = GetXOnY();
}

//----------------------------------------------------------------------------
void Evolvent::GetPreimages(double* _y, Extended* x)
{
  memcpy(y, _y, N * sizeof(double));
  transform_D_to_P();
  x[0] = GetXOnY();
}

// ------------------------------------------------------------------------------------------------
double Evolvent::ZeroConstraintCalc(const double* _y, int EvolventNum)
{
  (void)_y; (void)EvolventNum;
  return -1;
}
