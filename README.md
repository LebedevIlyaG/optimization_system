# Система глобальной оптимизации

Шаблон программной системы для изучения методов глобальной оптимизации.

## Описание проекта

Данный проект представляет собой шаблон системы для решения задач глобальной оптимизации с использованием методов характеристик. Реализованы:

- **Метод Пиявского** - для одномерных задач оптимизации
- **Алгоритм GSA (Global Search Algorithm)** - для многомерных задач с использованием развертки Пеано

## Структура проекта

```
optimization_system/
├── include/           # Заголовочные файлы
│   ├── Common.h
│   ├── Defines.h
│   ├── Extended.h
│   ├── Trial.h
│   ├── Interval.h
│   ├── Task.h
│   ├── Evolvent.h
│   ├── SearchInformation.h
│   ├── SolutionResult.h
│   ├── IInitialSet.h
│   ├── ICharacteristicCalculating.h
│   ├── INewPointCalculating.h
│   ├── ICharacteristicAlgorithm.h
│   ├── GSAInitialSet.h
│   ├── GSACharacteristicCalculating.h
│   ├── GSANewPointCalculating.h
│   ├── GSA.h
│   ├── PiyavskyCharacteristicCalculating.h
│   ├── PiyavskyNewPointCalculating.h
│   └── Piyavsky.h
├── src/              # Файлы реализации
│   ├── Common.cpp
│   ├── Extended.cpp
│   ├── Trial.cpp
│   ├── Interval.cpp
│   ├── Task.cpp
│   ├── Evolvent.cpp
│   ├── GSAInitialSet.cpp
│   ├── GSACharacteristicCalculating.cpp
│   ├── GSANewPointCalculating.cpp
│   ├── GSA.cpp
│   ├── PiyavskyCharacteristicCalculating.cpp
│   ├── PiyavskyNewPointCalculating.cpp
│   ├── Piyavsky.cpp
│   └── main.cpp
├── tests/            # Тесты
│   ├── test_common.cpp
│   ├── test_extended.cpp
│   ├── test_trial.cpp
│   ├── test_interval.cpp
│   ├── test_task.cpp
│   ├── test_evolvent.cpp
│   └── test_algorithms.cpp
├── CMakeLists.txt    # Конфигурация сборки
└── README.md         # Этот файл
```

## Требования

- **CMake** >= 3.14
- **C++ компилятор** с поддержкой C++17 (GCC, Clang, MSVC)
- **OpenMP** (опционально, для параллельных вычислений)
- **Git** (для автоматической загрузки Google Test)

## Сборка проекта

### Linux / macOS

```bash
# Создать директорию для сборки
mkdir build
cd build

# Настроить проект
cmake ..

# Собрать проект
make

# Запустить тесты
make test
# или
ctest
```

### Windows (Visual Studio)

```bash
# Создать директорию для сборки
mkdir build
cd build

# Настроить проект
cmake ..

# Собрать проект
cmake --build . --config Release

# Запустить тесты
ctest -C Release
```

## Задания для студентов

Проект содержит заглушки (TODO) в следующих местах, которые необходимо реализовать:

### 1. Вспомогательные функции (Common.cpp)

- `GetFileExtension()` - получение расширения файла
- `FindXY()` - поиск оптимальных значений X и Y
- `IsBelowGraph()` - проверка положения точки относительно графика (интерполяция Лагранжа)

### 2. Развертка Пеано (Evolvent.cpp)

- `CalculateNumbr()` - вычисление номера узла в дереве развертки
- `CalculateNode()` - вычисление координат узла по номеру
- `GetYOnX()` - прямое отображение развертки (x → y)
- `GetXOnY()` - обратное отображение развертки (y → x)

### 3. Алгоритм GSA (GSA.cpp)

Реализовать основной цикл алгоритма:
1. Получение начальных точек
2. Вычисление значений функции (с использованием OpenMP)
3. Основной итерационный цикл:
   - Обновление оценки константы Липшица M
   - Вычисление характеристик интервалов
   - Выбор P интервалов с максимальной характеристикой
   - Вычисление новых точек
   - Разбиение интервалов
   - Проверка критерия остановки

### 4. Метод Пиявского (Piyavsky.cpp)

Реализовать одномерный алгоритм глобального поиска:
1. Получение начальных точек
2. Основной цикл с выбором интервала по характеристике
3. Вычисление новой точки и разбиение интервала

### 5. Тесты

Дополнить существующие тесты:
- Проверка корректности работы алгоритмов на тестовых функциях
- Проверка сходимости к известным решениям
- Тесты производительности

## Примеры использования

### Метод Пиявского (одномерная оптимизация)

```cpp
#include "Piyavsky.h"

// Создание решателя
// Параметры: r (константа Липшица), eps (точность), maxIter (макс. итераций)
Piyavsky solver(2.0, 0.01, 1000);

// Решение задачи
SolutionResult result = solver.Solve();

// Вывод результатов
std::cout << "Лучшее значение: " << result.bestTrial->z[0] << std::endl;
std::cout << "Точка минимума: " << result.bestTrial->x << std::endl;
std::cout << "Итераций: " << result.iterationCount << std::endl;
std::cout << "Испытаний: " << result.trialCount << std::endl;
```

### Алгоритм GSA (многомерная оптимизация)

```cpp
#include "GSA.h"

// Размерность задачи
int N = 2;

// Границы области поиска
std::vector<double> A(N, -5.0);  // Левые границы
std::vector<double> B(N, 5.0);   // Правые границы

// Создание решателя
// Параметры: N, r, eps, maxIter, A, B, P (кол-во потоков), useStartPoints
GSA solver(N, 2.0, 0.01, 2000, A, B, 4, true);

// Решение задачи
SolutionResult result = solver.Solve();

// Вывод результатов
std::cout << "Лучшее значение: " << result.bestTrial->z[0] << std::endl;
std::cout << "Точка минимума: (";
for (int i = 0; i < N; i++) {
    std::cout << result.bestTrial->y[i];
    if (i < N - 1) std::cout << ", ";
}
std::cout << ")" << std::endl;
```

## Архитектура системы

### Паттерны проектирования

1. **Strategy (Стратегия)** - для реализации различных способов вычисления характеристик и новых точек
2. **Template Method** - базовый алгоритм в `ICharacteristicAlgorithm`
3. **Factory Method** - для создания начальных множеств точек

### Основные компоненты

- **Trial** - класс испытания (точка поиска)
- **Interval** - интервал между двумя испытаниями
- **Task** - целевая функция
- **Evolvent** - развертка Пеано для редукции размерности
- **SearchInformation** - информация о процессе поиска
- **ICharacteristicAlgorithm** - интерфейс алгоритма

## Параллельные вычисления

Проект поддерживает параллельное вычисление значений целевой функции с использованием OpenMP:

```cpp
#pragma omp parallel for num_threads(P)
for (int i = 0; i < newTrials.size(); i++) {
    newTrials[i]->z[0] = (*task)(*(newTrials[i]));
}
```

## Тестовые функции

По умолчанию используется **функция Растригина**:

```
f(x) = sum(x[i]^2 - 10*cos(2*pi*x[i]) + 10)
```

Минимум: f(0, 0, ..., 0) = 0

## Критерии остановки

1. По точности: `dx < eps`, где `dx = (x_right - x_left)^(1/N)`
2. По количеству итераций: `iterationCount >= maxIterationCount`

## Рекомендации по разработке

1. Начните с реализации простых функций в `Common.cpp`
2. Реализуйте развертку Пеано для одномерного случая (N=1)
3. Реализуйте метод Пиявского и проверьте его работу
4. Перейдите к многомерному случаю (развертка для N>1)
5. Реализуйте алгоритм GSA
6. Добавьте тесты и проверьте корректность

## Полезные ссылки

- [Презентация по системе](presentation_optimization_system.pptx)
- Strongin R.G., Sergeyev Y.D. Global Optimization with Non-Convex Constraints
- Курс "Технологии разработки программного обеспечения" на ННГУ

## Авторы

- Баркалов К.А.
- Сысоев А.В.

ННГУ им. Н.И. Лобачевского, 2015-2024

## Лицензия

Проект предназначен для образовательных целей.
