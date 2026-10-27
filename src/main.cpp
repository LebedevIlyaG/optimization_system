#include <iostream>
#include "GSA.h"
#include "Piyavsky.h"

int main(int argc, char* argv[])
{
  std::cout << "Система глобальной оптимизации" << std::endl;
  std::cout << "===============================" << std::endl;
  
  // TODO: Реализовать примеры использования алгоритмов
  
  // Пример 1: Метод Пиявского для одномерной задачи
  std::cout << "\nПример 1: Метод Пиявского (одномерный случай)" << std::endl;
  // Piyavsky solver1(2.0, 0.01, 100);
  // auto result1 = solver1.Solve();
  // std::cout << "Лучшее значение: " << result1.bestTrial->z[0] << std::endl;
  
  // Пример 2: Алгоритм GSA для многомерной задачи
  std::cout << "\nПример 2: Алгоритм GSA (многомерный случай)" << std::endl;
  int N = 2;
  std::vector<double> A(N, -2.2);
  std::vector<double> B(N, 1.8);
  
  // GSA solver2(N, 2.0, 0.01, 1000, A, B, 4, true);
  // auto result2 = solver2.Solve();
  // std::cout << "Лучшее значение: " << result2.bestTrial->z[0] << std::endl;
  
  std::cout << "\nРабота завершена!" << std::endl;
  
  return 0;
}
