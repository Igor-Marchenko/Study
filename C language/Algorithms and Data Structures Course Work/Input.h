#ifndef __Input_H__ //якщо макрос __Input_H__ не визначений
#define __Input_H__ //визначення __Input_H__ (лише один раз)

#include <stdio.h> //підключення бібліотечного файлу stdio.h
#include <stdlib.h> //підключення бібліотечного файлу stdlib.h
#include <time.h> //підключення бібліотечного файлу time.h для заповнення матриці та вектора випадковими значеннями

void input_random(); //прототип функції input_random
void input_sorted(); //прототип функції input_sorted
void input_back_sorted(); //прототип функції input_back_sorted

#endif //завершення, якщо макрос __Input_H__ визначений
