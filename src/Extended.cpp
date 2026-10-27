#include "Extended.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

ExtendedTypeID Extended::type = etDouble;
double Extended::maxNumbers = 101;
int Extended::digitsNumber = 2;
double Extended::precision = 0.01;
float Extended::precisionReserveFactor = 1.5;
int Extended::packedSize = -1;
bool Extended::precisionSet = false;

void Extended::Init()
{
  if (!precisionSet)
    SetPrecision(0.01);
}

void Extended::Free()
{
  dValue = 0.0;
}

Extended::Extended(double val)
{
  Init();
  dValue = val;
}

Extended::Extended(const char* str)
{
  Init();
  dValue = atof(str);
}

Extended::Extended(const Extended& e)
{
  Init();
  dValue = e.dValue;
}

Extended::~Extended()
{
  Free();
}

float Extended::getPrecisionReserveFactor()
{
  return precisionReserveFactor;
}

double Extended::GetPrecision()
{
  return precision;
}

void Extended::SetPrecision(double prec)
{
  maxNumbers = ::ceil(1.0/prec+1);
  precisionSet = true;
  precision = prec;
  digitsNumber = 20;
  packedSize = -1;
}

int Extended::GetPackedSize()
{
  if (packedSize <= 0)
  {
    packedSize = sizeof(double);
  }
  return packedSize;
}

void Extended::Pack(void* result) const
{
  memcpy(result, &dValue, sizeof(double));
}

void Extended::Unpack(void* packed)
{
  memcpy(&dValue, packed, sizeof(double));
}

ExtendedTypeID Extended::GetTypeID()
{
  return type;
}

void Extended::SetTypeID(ExtendedTypeID typeID)
{
  type = typeID;
  packedSize = -1;
}

int Extended::GetStringSize()
{
  int result = (digitsNumber) + 10;
  return result;
}

void Extended::toString(char* s) const
{
  snprintf(s, (size_t)GetStringSize(), "%.15lf", dValue);
  
  // Заменить '.' на ','
  int i = 0;
  while (s[i] != 0)
  {
    if (s[i] == '.')
    {
      s[i] = ',';
      break;
    }
    i++;
  }
}

double Extended::toDouble() const
{
  return dValue;
}

const Extended& Extended::operator=(const Extended& e)
{
  if (this == &e)
    return e;

  Free();
  dValue = e.dValue;
  return *this;
}

const Extended& Extended::operator=(const double& e)
{
  Free();
  dValue = e;
  return *this;
}

const Extended& Extended::operator=(const char* e)
{
  Free();
  dValue = atof(e);
  return *this;
}

Extended Extended::operator+(const Extended& e) const
{
  Extended tmp(*this);
  tmp.dValue += e.dValue;
  return tmp;
}

Extended Extended::operator+=(const Extended& e)
{
  *this = *this + e;
  return (*this);
}

Extended Extended::operator+(const double& e) const
{
  Extended tmp(*this);
  tmp.dValue += e;
  return tmp;
}

void Extended::operator+=(const double& e)
{
  *this = this->operator+(e);
}

Extended Extended::operator-(const Extended& e) const
{
  Extended tmp(*this);
  tmp.dValue -= e.dValue;
  return tmp;
}

Extended Extended::operator-=(const Extended& e)
{
  *this = *this - e;
  return (*this);
}

Extended Extended::operator-(const double& e) const
{
  Extended tmp(*this);
  tmp.dValue -= e;
  return tmp;
}

void Extended::operator-=(const double& e)
{
  *this = this->operator-(e);
}

Extended Extended::operator*(const Extended& e) const
{
  Extended tmp(*this);
  tmp.dValue *= e.dValue;
  return tmp;
}

Extended Extended::operator*=(const Extended& e)
{
  *this = *this * e;
  return (*this);
}

Extended Extended::operator*(const double& e) const
{
  Extended tmp(*this);
  tmp.dValue *= e;
  return tmp;
}

void Extended::operator*=(const double& e)
{
  *this = this->operator*(e);
}

Extended Extended::operator/(const Extended& e) const
{
  Extended tmp(*this);
  tmp.dValue /= e.dValue;
  return tmp;
}

Extended Extended::operator/(const double& e) const
{
  Extended tmp(*this);
  tmp.dValue /= e;
  return tmp;
}

// Дружественные функции
Extended operator+(const double& e1, const Extended& e2)
{
  Extended tmp(e1);
  tmp += e2;
  return tmp;
}

Extended operator-(const double& e1, const Extended& e2)
{
  Extended tmp(e1);
  tmp -= e2;
  return tmp;
}

Extended operator*(const double& e1, const Extended& e2)
{
  Extended tmp(e1);
  tmp *= e2;
  return tmp;
}

Extended operator/(const double& e1, const Extended& e2)
{
  Extended tmp(e1);
  tmp = tmp / e2;
  return tmp;
}

Extended fabs(const Extended& e)
{
  Extended res;
  res.dValue = ::fabs(e.dValue);
  return res;
}

double floor(const Extended& e)
{
  return ::floor(e.dValue);
}

Extended pow(const Extended& e, double degree)
{
  Extended res = 0.0;
  res.dValue = ::pow(e.dValue, degree);
  return res;
}

double root(const Extended& e, int k)
{
  return ::pow(e.dValue, 1.0/k);
}

// Операторы сравнения
bool operator==(const Extended& e1, const Extended& e2)
{
  return (e1.dValue == e2.dValue);
}

bool operator==(const Extended& e1, double d)
{
  return (e1.dValue == d);
}

bool operator==(double d, const Extended& e1)
{
  return (e1.dValue == d);
}

bool operator!=(const Extended& e1, const Extended& e2)
{
  return !(e1 == e2);
}

bool operator!=(const Extended& e1, double d)
{
  return !(e1 == d);
}

bool operator!=(double d, const Extended& e1)
{
  return !(e1 == d);
}

bool operator<(const Extended& e1, const Extended& e2)
{
  return (e1.dValue < e2.dValue);
}

bool operator<(const Extended& e, const double d)
{
  return (e.dValue < d);
}

bool operator<(const double d, const Extended& e)
{
  return (d < e.dValue);
}

bool operator<=(const Extended& e1, const Extended& e2)
{
  return (e1 < e2 || e1 == e2);
}

bool operator<=(const Extended& e, const double d)
{
  return (e < d || e == d);
}

bool operator<=(const double d, const Extended& e)
{
  return (d < e || d == e);
}

bool operator>(const Extended& e1, const Extended& e2)
{
  return !(e1 <= e2);
}

bool operator>(const Extended& e, const double d)
{
  return !(e <= d);
}

bool operator>(const double d, const Extended& e)
{
  return !(d <= e);
}

bool operator>=(const Extended& e1, const Extended& e2)
{
  return !(e1 < e2);
}

bool operator>=(const Extended& e, const double d)
{
  return !(e < d);
}

bool operator>=(const double d, const Extended& e)
{
  return !(d < e);
}
