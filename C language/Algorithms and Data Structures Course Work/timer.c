#include "timer.h" //ϳ�������� ������������ ���� ������ ������ ��� ������� �� ������� ������ ������ (������� MeasurementProcessing) � �� ������� ���������� ������䳿 ��������� ���������� � ���� ���������  

void MeasurementProcessing() //��������� ������� ���������� ������䳿 ������ ��������� ����������
{
    long int Sum,Min1,Min2,Min3,Max1,Max2,Max3; // ���� Min1,Min2,Min3,Max1,Max2,Max3 ���� long int - ��� �����'���������� 3-� ��������� � 3-� ������������;Sum ���� long int - ��� ���� ������� ������
    int imin1,imin2,imin3,imax1,imax2,imax3,z; // ���� imin1,imin2,imin3,imax1,imax2,imax3 ���� int - ��� �����'���������� ���� 3-� ��������� � 3-� ������������ ��������; z ���� int - ������ ������� �� �����

// ��� ������ ����� (0-� �� 1-�) �����������
// ����� ����� �������� ��������� ��� ��������� �� ��� ������������
// �������� � ������� �� �������� �� �������� ����

// ��������� ��������� �� ������������ �������� ������ ���������� � ��������� �� � ���������
// ������, ����������� �� �������� -1
    Sum = Res[2]; 
	Min1 = Res[2]; 
	Max1 = Res[2]; 
	imin1 = 2; 
	imax1 = 2;
    for (z = 3; z < measurements_number; z++)
    {
        Sum = Sum + Res[z];
        if (Res[z] > Max1) 
			{ 
				Max1 = Res[z]; 
				imax1 = z;
			}
        else 
			if (Res[z] < Min1) 
			{ 
				Min1 = Res[z]; 
				imin1 = z; 
			}
    }
    Res[imin1]=-1;
	Res[imax1]=-1;

// ��������� ������ ��������� �� ������ ������������ ��������
// � ��������� �� � ��������� ������, ����������� �� �������� -1
    if (Res[2] == -1) 
	{
		Min2 = Res[3]; 
		imin2 = 3;
	}
    else 
	{
		Min2 = Res[2]; 
		imin2 = 2;
	}
    Max2 = Res[2]; 
	imax2 = 2;
    for (z = 3; z < measurements_number; z++)
    {
        if (Res[z] > Max2) 
		{ 
			Max2 = Res[z]; 
			imax2 = z; 
		}
        else 
			if (Res[z]<Min2 && Res[z]!=-1) 
			{ 
				Min2 = Res[z]; 
				imin2 = z; 
			}
    }
    Res[imin2]=-1; 
	Res[imax2]=-1;

// ��������� ����� ��������� �� ����� ������������ ��������
    if (Res[2] == -1)
        if (Res[3] == -1) 
		{
			Min3 = Res[4]; 
			imin3 = 4;
		}
        else 
		{
			Min3 = Res[3]; 
			imin3 = 3;
		}
    else 
	{
		Min3 = Res[2];
		imin3 = 2;
	}
    Max3 = Res[2]; 
	imax3 = 2;
    for (z = 3; z < measurements_number; z++)
    {
        if (Res[z] > Max3) 
		{ 
			Max3 = Res[z]; 
			imax3 = z; 
		}
        else 
			if (Res[z]<Min3 && Res[z]!=-1) 
			{
				Min3 = Res[z]; 
				imin3 = z; 
			}
    }

// ���� ��� ����� ���� ��� ������������ �� ��� ��������� �������� ���� �������� �� 0-�� �������� ������ Res
    Res[0] = Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;
}
