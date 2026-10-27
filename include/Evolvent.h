#pragma once

#include "Common.h"
#include "Extended.h"
#include <vector>

/**
 * @brief Класс развертки Пеано
 * 
 * Реализует отображение между одномерным отрезком [0,1] и 
 * многомерным гиперкубом с помощью кривой Пеано
 */
class Evolvent
{
protected:
  /// Точность разложения гиперкуба
  int m;
  
  /// Размерность задачи
  int N;
  
  /// Левые границы поисковой области
  double A[MaxDim];
  
  /// Правые границы поисковой области
  double B[MaxDim];
  
  /// Точка из гиперкуба [-1/2, 1/2]^N
  double* y;

  const Extended extNull;
  const Extended extOne;
  const Extended extHalf;
  Extended nexpExtended;

  /**
   * @brief Вычисление номера узла
   */
  void CalculateNumbr(Extended* s, long long* u, long long* v, long long* l);

  /**
   * @brief Вычисление вспомогательного центра u(s)
   */
  void CalculateNode(Extended is, int n, long long* u, long long* v, long long* l);
  
  /**
   * @brief Преобразование из гиперкуба P в гиперинтервал D
   */
  void transform_P_to_D();
  
  /**
   * @brief Преобразование из гиперинтервала D в гиперкуб P
   */
  void transform_D_to_P();
  
  /**
   * @brief Получить точку y по x
   */
  double* GetYOnX(const Extended& _x);
  
  /**
   * @brief Получить x по точке y
   */
  Extended GetXOnY();

public:
  /**
   * @brief Конструктор развертки Пеано
   * @param _N Размерность задачи
   * @param _m Плотность развертки (точность)
   */
  Evolvent(int _N = 2, int _m = 10);

  /**
   * @brief Конструктор копирования
   */
  Evolvent(const Evolvent& evolvent);

  /**
   * @brief Деструктор
   */
  virtual ~Evolvent();

  /**
   * @brief Получить левые границы области поиска
   */
  const double* getA() const { return A; }

  /**
   * @brief Получить правые границы области поиска
   */
  const double* getB() const { return B; }

  /**
   * @brief Установить границы поисковой области
   * @param _A Левые границы
   * @param _B Правые границы
   */
  void SetBounds(const double* _A, const double* _B);

  /**
   * @brief Преобразование x в y (прямое отображение развертки)
   * @param x Одномерная координата
   * @param _y Выходной массив многомерных координат
   * @param EvolventNum Номер развертки (для множественных разверток)
   */
  virtual void GetImage(const Extended& x, double* _y, int EvolventNum = 0);

  /**
   * @brief Преобразование y в x (обратное отображение развертки)
   * @param _y Многомерные координаты
   * @param x Выходная одномерная координата
   */
  void GetInverseImage(double* _y, Extended& x);

  /**
   * @brief Получить все прообразы точки y
   * @param _y Многомерные координаты
   * @param x Массив прообразов
   */
  virtual void GetPreimages(double* _y, Extended* x);

  /**
   * @brief Оператор присваивания
   */
  Evolvent& operator=(const Evolvent& evolvent);

  /**
   * @brief Вычисление функции существования точки в развертке
   * @param _y Многомерные координаты
   * @param EvolventNum Номер развертки
   * @return Значение <0 означает, что точка существует
   */
  virtual double ZeroConstraintCalc(const double* _y, int EvolventNum = 0);
};
