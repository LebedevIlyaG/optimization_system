/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//             LOBACHEVSKY STATE UNIVERSITY OF NIZHNY NOVGOROD             //
//                                                                         //
//                       Copyright (c) 2015 by UNN.                        //
//                          All Rights Reserved.                           //
//                                                                         //
//  File:      Common.h                                                    //
//                                                                         //
//  Purpose:   Common Header file                                          //
//                                                                         //
//  Author(s): Sysoyev A., Barkalov K.                                     //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#ifndef __COMMON_H__
#define __COMMON_H__

#include "Defines.h"
#include <string>

/* ============================================================================================= *\
**  Constants                                                                                    **
\* ============================================================================================= */

const int MaxNumOfTaskLevels = 5;
const int MaxNumOfFunc = MAX_NUMBER_OF_FUNCTION;
const int MaxDim = MAX_TRIAL_DIMENSION;
const int MaxNumOfGlobMinima = MAX_NUM_MIN;
const int MaxM = 20;
const int MaxL = 10;

const double MaxDouble = 1.7e308;
const double MinDouble = -1.7e308;
const double AccuracyDouble = 1.0e-8;

/**
 * @brief Получение расширения файла
 * @param filename Имя файла
 * @param include_dot Включать ли точку в расширение
 * @return Расширение файла
 */
std::string GetFileExtension(const std::string& filename, bool include_dot = false);

/**
 * @brief Поиск значений X и Y по заданным параметрам
 * @param x Выходное значение X
 * @param y Выходное значение Y
 * @param z Входной параметр Z
 * @param C Входной параметр C
 */
void FindXY(int& x, int& y, int z, int C);

/**
 * @brief Проверка, находится ли точка ниже графика
 * @param x Координата X
 * @param y Координата Y
 * @return true если точка ниже графика
 */
bool IsBelowGraph(int x, int y);

#endif
// - end of file ----------------------------------------------------------------------------------
