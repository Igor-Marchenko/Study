#ifndef __sortings_h__ //якщо макрос __sortings_h__ не визначений
#define __sortings_h__ //визначення __sortings_h__ (лише один раз)

#include <stdio.h> //підключення бібліотечного файлу stdio.h
#include <stdbool.h> //підключення бібліотечного файлу stdbool.h для можливості використання булевих змінних
#include <time.h> //підключення бібліотечного файлу time.h для вимірів швидкодії роботи алгоритмів сортування

clock_t insertion_sort(); //прототип функції insertion_sort 
clock_t insertion_vect(); //прототип функції insertion_vect
clock_t selection_sort(); //прототип функції selection_sort
clock_t selection_vect(); //прототип функції selection_vect
clock_t exchange_flag_sort(); //прототип функції exchange_flag_sort
clock_t exchange_flag_vect(); //прототип функції exchange_flag_vect

#endif //завершення, якщо макрос __sortings_h__ визначений
