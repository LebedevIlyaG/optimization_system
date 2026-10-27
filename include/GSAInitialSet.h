#pragma once
#include "IInitialSet.h"
#include "Task.h"
#include "Evolvent.h"

/**
 * @brief Класс для генерации начального множества точек для алгоритма GSA
 */
class GSAInitialSet : public IInitialSet
{
protected:
  Task* task;
  Evolvent* evolvent;
  int P;
  
public:
  /**
   * @brief Конструктор
   * @param _task Указатель на задачу оптимизации
   * @param _evolvent Указатель на развертку Пеано
   * @param _P Количество параллельных точек
   */
  GSAInitialSet(Task* _task, Evolvent* _evolvent, int _P = 0);

  /**
   * @brief Генерация начальных точек
   * @return Вектор начальных испытаний
   */
  virtual std::vector<Trial*> GetStartPont() override;
};
