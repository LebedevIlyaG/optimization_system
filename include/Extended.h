/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//             LOBACHEVSKY STATE UNIVERSITY OF NIZHNY NOVGOROD             //
//                                                                         //
//                       Copyright (c) 2015 by UNN.                        //
//                          All Rights Reserved.                           //
//                                                                         //
//  File:      Extended.h                                                  //
//                                                                         //
//  Purpose:   Header file for class, that represents numbers with         //
//             arbitrary accuracy                                          //
//                                                                         //
//  Author(s): Chigarev V.                                                 //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#ifndef __EXTENDED_H__
#define __EXTENDED_H__

/**
 * @brief Тип данных Extended для работы с числами высокой точности
 * 
 * В данной реализации используется double, но возможно расширение
 * с использованием библиотек произвольной точности (MPFR)
 */
enum ExtendedTypeID { etDouble = 0, etMPFR = 2 };

/**
 * @brief Класс для представления чисел с произвольной точностью
 */
class Extended
{
protected:
  double dValue;
  
  static bool precisionSet;
  static double maxNumbers;
  static double precision;
  static float precisionReserveFactor;
  static int digitsNumber;
  static int packedSize;

public:
  static ExtendedTypeID type;

  void Init();
  void Free();

  Extended(double val = 0.0);
  Extended(const char* str);
  Extended(const Extended& e);
  ~Extended();

  static float getPrecisionReserveFactor();
  static void SetPrecision(double prec);
  static double GetPrecision();
  static int GetPackedSize();
  void Pack(void* result) const;
  void Unpack(void* packed);

  static ExtendedTypeID GetTypeID();
  static void SetTypeID(ExtendedTypeID typeID);

  static int GetStringSize();
  void toString(char* s) const;

  double toDouble() const;

  const Extended& operator=(const Extended& e);
  const Extended& operator=(const double& e);
  const Extended& operator=(const char* e);

  Extended operator+(const Extended& e) const;
  Extended operator+=(const Extended& e);
  Extended operator+(const double& e) const;
  void operator+=(const double& e);

  Extended operator-(const Extended& e) const;
  Extended operator-=(const Extended& e);
  Extended operator-(const double& e) const;
  void operator-=(const double& e);

  Extended operator*(const Extended& e) const;
  Extended operator*=(const Extended& e);
  Extended operator*(const double& e) const;
  void operator*=(const double& e);

  Extended operator/(const Extended& e) const;
  Extended operator/(const double& e) const;

  // Дружественные операции
  friend Extended operator+(const double& e1, const Extended& e2);
  friend Extended operator-(const double& e1, const Extended& e2);
  friend Extended operator*(const double& e1, const Extended& e2);
  friend Extended operator/(const double& e1, const Extended& e2);

  friend Extended fabs(const Extended& e);
  friend double floor(const Extended& e);
  friend Extended pow(const Extended& e, double degree);
  friend double root(const Extended& e, int k);

  // Операторы сравнения
  friend bool operator==(const Extended& e1, const Extended& e2);
  friend bool operator==(const Extended& e1, double d);
  friend bool operator==(double d, const Extended& e1);

  friend bool operator!=(const Extended& e1, const Extended& e2);
  friend bool operator!=(const Extended& e1, double d);
  friend bool operator!=(double d, const Extended& e1);

  friend bool operator<(const Extended& e1, const Extended& e2);
  friend bool operator<(const Extended& e, const double d);
  friend bool operator<(const double d, const Extended& e);

  friend bool operator>(const Extended& e1, const Extended& e2);
  friend bool operator>(const Extended& e, const double d);
  friend bool operator>(const double d, const Extended& e);

  friend bool operator<=(const Extended& e1, const Extended& e2);
  friend bool operator<=(const Extended& e, const double d);
  friend bool operator<=(const double d, const Extended& e);

  friend bool operator>=(const Extended& e1, const Extended& e2);
  friend bool operator>=(const Extended& e, const double d);
  friend bool operator>=(const double d, const Extended& e);
};

#endif // __EXTENDED_H__
