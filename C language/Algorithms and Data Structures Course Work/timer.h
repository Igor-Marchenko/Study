#ifndef __Timer_H__ //���� ������ __Timer_H__ �� ����������
#define __Timer_H__ //���������� __Timer_H__ (���� ���� ���)

#include <time.h> //���������� ����������� ����� time.h
#include <stdio.h> //���������� ����������� ����� stdio.h
#define measurements_number 28 //��������������� measurements_number - ������� �������� ������ ���������� ������䳿 ������ ��������� ����������

clock_t Res[measurements_number]; //����� ��� ���������� ������䳿 ������ ��������� ����������

void MeasurementProcessing(); //�������� ������� MeasurementProcessing

#endif//����������, ���� ������ __Timer_H__ ����������
