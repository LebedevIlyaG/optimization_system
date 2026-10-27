#ifndef __DEFINES_H__
#define __DEFINES_H__

/* ======================================================================== *\
**  Константы                                                               **
\* ======================================================================== */

/// Максимальная размерность
#ifdef GLOBALIZER_MAX_DIMENSION
#define MAX_TRIAL_DIMENSION GLOBALIZER_MAX_DIMENSION
#else
#define MAX_TRIAL_DIMENSION 200
#endif

/// Максимальное количество функций
#ifdef GLOBALIZER_MAX_Number_Of_Function
#define MAX_NUMBER_OF_FUNCTION GLOBALIZER_MAX_Number_Of_Function
#else
#define MAX_NUMBER_OF_FUNCTION 20
#endif

// Максимальное количество глобальных минимумов
#define MAX_NUM_MIN 20

/// Используемый тип данных для вычислений на центральном процессоре
#define CPU_VALUE double

/// Тип флага
#define FLAG bool

/**
Данный параметр определяет уровень, меньше которого константа Липшица считается нулевой.
*/
#define _M_ZERO_LEVEL 1e-12

#endif
