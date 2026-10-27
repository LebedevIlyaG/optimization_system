#include "Piyavsky.h"
#include "PiyavskyCharacteristicCalculating.h"
#include "PiyavskyNewPointCalculating.h"
#include "GSAInitialSet.h"
#include <chrono>

Piyavsky::Piyavsky(double r, double _eps, int _maxIterationCount)
{
  task = new Task(1, {-4}, {8});
  initialSet = new GSAInitialSet(task, nullptr);
  searchInformation = new SearchInformation();
  characteristicCalculating = new PiyavskyCharacteristicCalculating(searchInformation);
  newPointCalculating = new PiyavskyNewPointCalculating(searchInformation);
  searchInformation->r = r;
  searchInformation->M = 0;
  searchInformation->bestTrial = nullptr;
  eps = _eps;
  maxIterationCount = _maxIterationCount;
  N = 1;
  P = 0;
  result = nullptr;
}

Piyavsky::~Piyavsky()
{
  // TODO: Реализовать корректное освобождение памяти
}

SolutionResult Piyavsky::Solve()
{
  // TODO: Реализовать основной цикл метода Пиявского
  // 1. Получить начальные точки (левая и правая границы)
  // 2. Вычислить значения функции в начальных точках
  // 3. Основной цикл:
  //    - Вычислить характеристики всех интервалов
  //    - Выбрать интервал с максимальной характеристикой
  //    - Вычислить новую точку в выбранном интервале
  //    - Вычислить значение функции в новой точке
  //    - Разбить интервал новой точкой
  //    - Обновить лучшую найденную точку
  //    - Проверить критерий остановки (по размеру интервала или количеству итераций)
  
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
