#ifndef __sortings_h__ //���� ������ __sortings_h__ �� ����������
#define __sortings_h__ //���������� __sortings_h__ (���� ���� ���)

#include <stdio.h> //���������� ����������� ����� stdio.h
#include <stdbool.h> //���������� ����������� ����� stdbool.h ��� ��������� ������������ ������� ������
#include <time.h> //���������� ����������� ����� time.h ��� ����� ������䳿 ������ ��������� ����������

clock_t insertion_sort(); //�������� ������� insertion_sort 
clock_t insertion_vect(); //�������� ������� insertion_vect
clock_t selection_sort(); //�������� ������� selection_sort
clock_t selection_vect(); //�������� ������� selection_vect
clock_t exchange_flag_sort(); //�������� ������� exchange_flag_sort
clock_t exchange_flag_vect(); //�������� ������� exchange_flag_vect

#endif //����������, ���� ������ __sortings_h__ ����������
