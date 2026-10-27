# Сборка и запуск

Этот файл содержит пошаговые инструкции по сборке и запуску проекта.

## Предварительные требования

### Linux (Ubuntu/Debian)

```bash
# Установка необходимых пакетов
sudo apt-get update
sudo apt-get install build-essential cmake git libomp-dev
```

### macOS

```bash
# Установка Homebrew (если еще не установлен)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Установка необходимых пакетов
brew install cmake libomp
```

### Windows

1. Установите Visual Studio 2019 или новее с компонентами C++
2. Установите CMake: https://cmake.org/download/
3. Добавьте CMake в PATH

## Сборка проекта

### Вариант 1: Стандартная сборка

```bash
# Перейти в корневую директорию проекта
cd optimization_system

# Создать директорию для сборки
mkdir build
cd build

# Настроить проект с CMake
cmake ..

# Собрать проект
cmake --build .

# Или для многопоточной сборки (Linux/macOS)
make -j4
```

### Вариант 2: Сборка без тестов

```bash
mkdir build
cd build
cmake -DBUILD_TESTS=OFF ..
cmake --build .
```

### Вариант 3: Сборка без OpenMP

```bash
mkdir build
cd build
cmake -DUSE_OPENMP=OFF ..
cmake --build .
```

### Вариант 4: Release сборка (оптимизированная)

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

## Запуск программы

### Linux/macOS

```bash
# Из директории build
./optimization_system
```

### Windows

```bash
# Из директории build
.\Debug\optimization_system.exe
# или для Release
.\Release\optimization_system.exe
```

## Запуск тестов

### Использование CTest

```bash
# Из директории build
ctest

# С подробным выводом
ctest -V

# Запуск конкретного теста
ctest -R test_trial

# Параллельный запуск тестов
ctest -j4
```

### Прямой запуск тестового исполняемого файла

```bash
# Linux/macOS
./run_tests

# Windows
.\Debug\run_tests.exe
```

### Запуск с фильтром Google Test

```bash
# Запустить только тесты Trial
./run_tests --gtest_filter=TrialTest.*

# Запустить все тесты кроме Evolvent
./run_tests --gtest_filter=-EvolventTest.*

# Повторить тесты 10 раз
./run_tests --gtest_repeat=10
```

## Очистка сборки

```bash
# Удалить директорию build
cd ..
rm -rf build

# Или на Windows
rmdir /s /q build
```

## Установка (опционально)

```bash
# Из директории build
sudo make install

# Или с указанием префикса
cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
make
sudo make install
```

## Проверка установки

```bash
# Проверить, что программа доступна
which optimization_system

# Запустить установленную программу
optimization_system
```

## Частые проблемы

### Проблема: CMake не находит компилятор

**Решение:**
```bash
# Указать компилятор явно
cmake -DCMAKE_CXX_COMPILER=g++ ..
```

### Проблема: Ошибки связанные с OpenMP

**Решение 1:** Установить OpenMP
```bash
# Linux
sudo apt-get install libomp-dev

# macOS
brew install libomp
```

**Решение 2:** Отключить OpenMP
```bash
cmake -DUSE_OPENMP=OFF ..
```

### Проблема: Google Test не загружается

**Решение:** Проверить подключение к интернету. CMake автоматически загружает Google Test при первой сборке.

Альтернатива - отключить тесты:
```bash
cmake -DBUILD_TESTS=OFF ..
```

### Проблема: Ошибки компиляции в Extended.cpp

**Причина:** Проект использует упрощенную версию без библиотеки MPFR

**Решение:** Убедитесь, что в Defines.h определен `#define NO_MPREAL`

## Отладка

### Сборка в режиме отладки

```bash
mkdir build_debug
cd build_debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

### Использование GDB (Linux/macOS)

```bash
gdb ./optimization_system
# В GDB:
(gdb) run
(gdb) backtrace  # при ошибке
```

### Использование Valgrind (проверка утечек памяти)

```bash
valgrind --leak-check=full ./optimization_system
```

## Производительность

### Профилирование с gprof

```bash
cmake -DCMAKE_CXX_FLAGS="-pg" ..
make
./optimization_system
gprof ./optimization_system gmon.out > analysis.txt
```

### Проверка использования OpenMP

```bash
# Установить количество потоков
export OMP_NUM_THREADS=4
./optimization_system
```

## Дополнительные опции CMake

```bash
# Посмотреть все доступные опции
cmake -L ..

# Включить verbose режим для отладки CMake
cmake --debug-output ..

# Очистить кэш CMake
rm CMakeCache.txt
cmake ..
```

## Continuous Integration (CI)

Проект готов для интеграции с CI системами:

### GitHub Actions

Создайте `.github/workflows/build.yml`:

```yaml
name: Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    - name: Install dependencies
      run: sudo apt-get install -y cmake libomp-dev
    - name: Build
      run: |
        mkdir build
        cd build
        cmake ..
        make
    - name: Test
      run: |
        cd build
        ctest --output-on-failure
```

Удачной работы!
