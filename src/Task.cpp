#include "Task.h"

Task::Task(int _dim, std::vector<double> _A, std::vector<double> _B)
  : dim(_dim), A(_A), B(_B)
{
}

double Task::operator()(Trial& trial)
{
  // TODO: Реализовать вычисление целевой функции.
  // Пример (функция Растригина):
  //   #define _USE_MATH_DEFINES
  //   #include <cmath>
  //   double sum = 0.0;
  //   for (int j = 0; j < dim; j++)
  //     sum += trial.y[j]*trial.y[j] - 10.0*cos(2.0*M_PI*trial.y[j]) + 10.0;
  //   return sum;
  return 0.0;
}
