#ifndef __Timer_H__ //якщо макрос __Timer_H__ не визначений
#define __Timer_H__ //визначення __Timer_H__ (лише один раз)

#include <time.h> //підключення бібліотечного файлу time.h
#include <stdio.h> //підключення бібліотечного файлу stdio.h
#define measurements_number 28 //макропідстановка measurements_number - кількість елементів масиву розрахунку швидкодії роботи алгоритмів сортування

clock_t Res[measurements_number]; //масив для розрахунку швидкодії роботи алгоритмів сортування

void MeasurementProcessing(); //прототип функції MeasurementProcessing

#endif//завершення, якщо макрос __Timer_H__ визначений
