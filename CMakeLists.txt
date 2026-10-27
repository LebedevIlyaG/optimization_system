cmake_minimum_required(VERSION 3.21)

# C++ only: не тратим время на проверку C-компилятора, нам он не нужен.
project(OptimizationSystem VERSION 1.0.0 LANGUAGES CXX)

# --- Базовые настройки -------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Режим по умолчанию для многоконфигурационных генераторов (VS): Release
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Пусть VS видит CMakeLists.txt в дереве решения
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT optimization_system)

option(BUILD_TESTS "Собирать тесты (GoogleTest)" ON)
option(USE_OPENMP  "Использовать OpenMP, если найден" ON)

if(MSVC)
    # /utf-8 обязателен: в исходниках кириллица в UTF-8 без BOM
    add_compile_options(/utf-8 /EHsc /MP /W3)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS _USE_MATH_DEFINES NOMINMAX WIN32_LEAN_AND_MEAN)
endif()

# --- OpenMP ------------------------------------------------------------------
set(HAVE_OPENMP OFF)
if(USE_OPENMP)
    find_package(OpenMP QUIET COMPONENTS CXX)
    if(OpenMP_CXX_FOUND)
        set(HAVE_OPENMP ON)
        message(STATUS "OpenMP: включен")
    else()
        message(STATUS "OpenMP: не найден, собираем однопоточно")
    endif()
endif()

# --- Списки файлов -----------------------------------------------------------
# Явные списки вместо GLOB: при GLOB_RECURSE + CONFIGURE_DEPENDS VS перегенерирует
# проект на каждой сборке и решение в обозревателе "скачет"/пустеет.
set(LIB_HEADERS
    include/Common.h
    include/Defines.h
    include/Extended.h
    include/Evolvent.h
    include/GSA.h
    include/GSACharacteristicCalculating.h
    include/GSAInitialSet.h
    include/GSANewPointCalculating.h
    include/ICharacteristicAlgorithm.h
    include/ICharacteristicCalculating.h
    include/IInitialSet.h
    include/INewPointCalculating.h
    include/Interval.h
    include/Piyavsky.h
    include/PiyavskyCharacteristicCalculating.h
    include/PiyavskyNewPointCalculating.h
    include/SearchInformation.h
    include/SolutionResult.h
    include/Task.h
    include/Trial.h
)

set(LIB_SOURCES
    src/Common.cpp
    src/Extended.cpp
    src/Evolvent.cpp
    src/GSA.cpp
    src/GSACharacteristicCalculating.cpp
    src/GSAInitialSet.cpp
    src/GSANewPointCalculating.cpp
    src/Interval.cpp
    src/Piyavsky.cpp
    src/PiyavskyCharacteristicCalculating.cpp
    src/PiyavskyNewPointCalculating.cpp
    src/Task.cpp
    src/Trial.cpp
)

list(TRANSFORM LIB_HEADERS PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
list(TRANSFORM LIB_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

# --- Библиотека алгоритмов ---------------------------------------------------
add_library(optimization_lib STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_include_directories(optimization_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(HAVE_OPENMP)
    target_link_libraries(optimization_lib PUBLIC OpenMP::OpenMP_CXX)
endif()

source_group("Headers" FILES ${LIB_HEADERS})
source_group("Sources" FILES ${LIB_SOURCES})
set_target_properties(optimization_lib PROPERTIES
    FOLDER "Libraries"
    PROJECT_LABEL "optimization_lib"
)

# --- Приложение --------------------------------------------------------------
add_executable(optimization_system src/main.cpp)

# CMakeLists.txt в дереве решения (правый клик -> открыть в редакторе VS)
target_sources(optimization_system PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")

target_link_libraries(optimization_system PRIVATE optimization_lib)

set_target_properties(optimization_system PROPERTIES
    FOLDER "Application"
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# --- Тесты -------------------------------------------------------------------
if(BUILD_TESTS)
    enable_testing()

    # 1) Пытаемся найти установленный GoogleTest (vcpkg / системный)
    find_package(GTest CONFIG QUIET COMPONENTS gtest gtest_main)

    # 2) Иначе подкачиваем исходники
    if(NOT TARGET GTest::gtest_main AND NOT TARGET gtest_main)
        include(FetchContent)
        set(gtest_force_shared_crt ON  CACHE BOOL "" FORCE)
        set(INSTALL_GTEST           OFF CACHE BOOL "" FORCE)
        set(BUILD_GMOCK             OFF CACHE BOOL "" FORCE)
        set(BUILD_GTEST             ON  CACHE BOOL "" FORCE)

        FetchContent_Declare(googletest
            URL "https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip"
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        )
        FetchContent_MakeAvailable(googletest)

        foreach(_t gtest gtest_main)
            if(TARGET ${_t})
                set_target_properties(${_t} PROPERTIES FOLDER "ThirdParty/GoogleTest")
            endif()
        endforeach()
    endif()

    set(GTEST_LINK)
    if(TARGET GTest::gtest_main)
        set(GTEST_LINK GTest::gtest_main)
    elseif(TARGET gtest_main)
        set(GTEST_LINK gtest_main)
    endif()

    if(NOT GTEST_LINK)
        message(WARNING "GoogleTest не найден и не загружен — тесты отключены")
    else()
        add_executable(run_tests
            tests/test_common.cpp
            tests/test_extended.cpp
            tests/test_trial.cpp
            tests/test_interval.cpp
            tests/test_task.cpp
            tests/test_evolvent.cpp
            tests/test_algorithms.cpp
        )

        target_link_libraries(run_tests PRIVATE optimization_lib ${GTEST_LINK})

        if(MSVC)
            target_compile_options(run_tests PRIVATE /wd4389 /wd4018 /wd4244)
        endif()

        set_target_properties(run_tests PROPERTIES
            FOLDER "Tests"
            VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        )

        include(GoogleTest)
        # PRE_TEST: список тестов определяется при запуске, а не при сборке —
        # не ломает генерацию решения и не требует собирать exe на этапе configure.
        gtest_discover_tests(run_tests
            DISCOVERY_MODE PRE_TEST
            TEST_PREFIX "unit.")
    endif()
endif()

# --- Установка ---------------------------------------------------------------
include(GNUInstallDirs)
install(TARGETS optimization_system RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# --- Итоговая сводка ---------------------------------------------------------
message(STATUS "----------------------------------------------------------")
message(STATUS " OptimizationSystem ${PROJECT_VERSION}")
message(STATUS " Generator : ${CMAKE_GENERATOR}")
message(STATUS " OpenMP    : ${HAVE_OPENMP}")
message(STATUS " Tests     : ${BUILD_TESTS}")
message(STATUS "----------------------------------------------------------")
