#include "GSA.h"
#include "GSACharacteristicCalculating.h"
#include "GSANewPointCalculating.h"
#include "GSAInitialSet.h"
#include <chrono>
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

GSA::GSA()
  : initialSet(nullptr), characteristicCalculating(nullptr), newPointCalculating(nullptr),
    searchInformation(nullptr), task(nullptr), evolvent(nullptr), result(nullptr),
    eps(0), maxIterationCount(100), isUseStartPount(true), N(1), P(0)
{
}

GSA::GSA(int _N, double _r, double _eps, int _maxIterationCount, std::vector<double> _A, std::vector<double> _B, int _P, bool _isUseStartPount)
  : eps(_eps), maxIterationCount(_maxIterationCount), isUseStartPount(_isUseStartPount), N(_N), P(_P), result(nullptr)
{
  if (P == 0)
  {
#ifdef _OPENMP
#pragma omp parallel
    {
      if (omp_get_thread_num() == 0)
        P = omp_get_num_threads();
    }
#else
    P = 1;
#endif
  }
  
  task = new Task(N, _A, _B);
  evolvent = new Evolvent(N, 10);
  evolvent->SetBounds(_A.data(), _B.data());
  initialSet = new GSAInitialSet(task, evolvent, P);
  searchInformation = new SearchInformation();
  characteristicCalculating = new GSACharacteristicCalculating(searchInformation, isUseStartPount);
  newPointCalculating = new GSANewPointCalculating(searchInformation, evolvent, isUseStartPount);
  searchInformation->r = _r;
  searchInformation->M = 0;
  searchInformation->bestTrial = nullptr;
}

GSA::~GSA()
{
  // TODO: Реализовать корректное освобождение памяти
  // Удалить все испытания, интервалы, компоненты алгоритма
}

SolutionResult GSA::Solve()
{
  // TODO: Реализовать основной цикл алгоритма GSA
  // 1. Получить начальные точки
  // 2. Создать начальные интервалы
  // 3. Вычислить значения функции в начальных точках (параллельно с OpenMP)
  // 4. Основной цикл:
  //    - Обновить оценку константы Липшица M
  //    - Вычислить характеристики всех интервалов
  //    - Выбрать P интервалов с максимальной характеристикой
  //    - Вычислить новые точки в выбранных интервалах
  //    - Вычислить значения функции в новых точках (параллельно)
  //    - Разбить интервалы новыми точками
  //    - Обновить лучшую найденную точку
  //    - Проверить критерий остановки
  
  if (result != nullptr)
    delete result;
  result = new SolutionResult();

  auto start = std::chrono::high_resolution_clock::now();

  // Заглушка - вернуть пустой результат
  result->iterationCount = 0;
  result->trialCount = 0;
  result->bestTrial = nullptr;
  result->time = 0.0;

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  result->time = duration.count();

  return *result;
}

SolutionResult GSA::GetSolutionResult()
{
  if (result != nullptr)
    return *result;
  
  return SolutionResult();
}
