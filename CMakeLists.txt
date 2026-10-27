cmake_minimum_required(VERSION 3.24)

project(OptimizationSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_TESTS "Build GoogleTest tests" ON)
option(USE_OPENMP "Enable OpenMP when available" ON)

set(OPTIMIZATION_HEADERS
    include/Common.h
    include/Defines.h
    include/Evolvent.h
    include/Extended.h
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

set(OPTIMIZATION_SOURCES
    src/Common.cpp
    src/Evolvent.cpp
    src/Extended.cpp
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

add_library(optimization_lib STATIC
    ${OPTIMIZATION_HEADERS}
    ${OPTIMIZATION_SOURCES}
)
target_include_directories(optimization_lib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_features(optimization_lib PUBLIC cxx_std_17)

# These PUBLIC settings also apply to the application and tests,
# which include this library's headers, but not to GoogleTest itself.
if(MSVC)
    target_compile_options(optimization_lib PUBLIC /utf-8)
    target_compile_definitions(optimization_lib PUBLIC
        _CRT_SECURE_NO_WARNINGS
        _USE_MATH_DEFINES
        NOMINMAX
    )
endif()

if(USE_OPENMP)
    find_package(OpenMP QUIET COMPONENTS CXX)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(optimization_lib PUBLIC OpenMP::OpenMP_CXX)
        # _OPENMP is provided by the compiler; do not define it manually.
        message(STATUS "OpenMP enabled")
    else()
        message(STATUS "OpenMP not found; using serial execution")
    endif()
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
    ${OPTIMIZATION_HEADERS}
    ${OPTIMIZATION_SOURCES}
)
set_target_properties(optimization_lib PROPERTIES FOLDER "Libraries")

add_executable(optimization_system src/main.cpp)
target_link_libraries(optimization_system PRIVATE optimization_lib)
set_target_properties(optimization_system PROPERTIES
    FOLDER "Application"
    VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:optimization_system>"
)

# VS_STARTUP_PROJECT is a DIRECTORY property, not a GLOBAL property.
if(CMAKE_GENERATOR MATCHES "^Visual Studio")
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT optimization_system)
endif()

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest CONFIG QUIET)

    if(NOT TARGET GTest::gtest_main)
        include(FetchContent)
        if(MSVC)
            # Match the default MSVC runtime used by this project (/MD, /MDd).
            set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        endif()
        set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
        set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
        FetchContent_Declare(googletest
            URL "https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip"
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        )
        FetchContent_MakeAvailable(googletest)
    endif()

    foreach(_target IN ITEMS gtest gtest_main)
        if(TARGET ${_target})
            set_target_properties(${_target} PROPERTIES FOLDER "ThirdParty/GoogleTest")
        endif()
    endforeach()

    add_executable(optimization_tests
        tests/test_algorithms.cpp
        tests/test_common.cpp
        tests/test_evolvent.cpp
        tests/test_extended.cpp
        tests/test_interval.cpp
        tests/test_task.cpp
        tests/test_trial.cpp
    )
    target_link_libraries(optimization_tests PRIVATE
        optimization_lib
        GTest::gtest_main
    )
    set_target_properties(optimization_tests PROPERTIES
        FOLDER "Tests"
        VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:optimization_tests>"
    )
    include(GoogleTest)
    gtest_discover_tests(optimization_tests DISCOVERY_MODE PRE_TEST)
endif()

include(GNUInstallDirs)
install(TARGETS optimization_system
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)
install(DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

message(STATUS "Generator: ${CMAKE_GENERATOR}")
message(STATUS "Build tests: ${BUILD_TESTS}")
