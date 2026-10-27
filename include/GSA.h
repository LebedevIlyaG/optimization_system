#pragma once
#include "ICharacteristicAlgorithm.h"
#include "Evolvent.h"

/**
 * @brief Глобальный алгоритм поиска (GSA) для многомерных задач
 * 
 * Реализует алгоритм глобального поиска на основе метода характеристик
 * с использованием развертки Пеано для редукции размерности
 */
class GSA : public ICharacteristicAlgorithm
{
protected:
  IInitialSet* initialSet;
  ICharacteristicCalculating* characteristicCalculating;
  INewPointCalculating* newPointCalculating;
  SearchInformation* searchInformation;
  Task* task;
  Evolvent* evolvent;

  SolutionResult* result;

  double eps;
  int maxIterationCount;
  bool isUseStartPount;
  int N;
  int P;
  
public:
  /**
   * @brief Конструктор по умолчанию
   */
  GSA();
  
  /**
   * @brief Конструктор с параметрами
   * @param _N Размерность задачи
   * @param _r Параметр надежности
   * @param _eps Точность по размеру интервала
   * @param _maxIterationCount Максимальное количество итераций
   * @param _A Левые границы области поиска
   * @param _B Правые границы области поиска
   * @param _P Количество параллельных точек (0 = авто)
   * @param _isUseStartPount Использовать ли начальные точки
   */
  GSA(int _N, double _r, double _eps, int _maxIterationCount, 
      std::vector<double> _A, std::vector<double> _B, int _P = 0, bool _isUseStartPount = true);
  
  /**
   * @brief Деструктор
   */
  ~GSA();

  /**
   * @brief Решение задачи оптимизации
   * @return Результат решения
   */
  virtual SolutionResult Solve() override;

  /**
   * @brief Получение результата последнего решения
   * @return Результат решения
   */
  virtual SolutionResult GetSolutionResult() override;
};
