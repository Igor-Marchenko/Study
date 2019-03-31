#include "timer.h" //Підключаємо заголовочний файл модуля таймер для доступу до функцій даного модуля (функції MeasurementProcessing) і до вектора результатів швидкодії алгоритмів сортування і його розмірності  

void MeasurementProcessing() //Безтипова функція розрахунку швидкодії роботи алгоритмів сортування
{
    long int Sum,Min1,Min2,Min3,Max1,Max2,Max3; // змінні Min1,Min2,Min3,Max1,Max2,Max3 типу long int - для запам'ятовування 3-х мінімальних і 3-х максимальних;Sum типу long int - для суми значень масиву
    int imin1,imin2,imin3,imax1,imax2,imax3,z; // змінні imin1,imin2,imin3,imax1,imax2,imax3 типу int - для запам'ятовування місць 3-х мінімальних і 3-х максимальних елементів; z типу int - індекс проходу по циклу

// Два перших виміри (0-й та 1-й) відкидаються
// Серед інших елементів знаходимо три мінімальних та три максимальних
// елементи і віднімаємо їх значення із загальної суми

// Знаходимо мінімальний та максимальний елементи масиву рещультатів і виключаємо їх з наступних
// пошуків, встановивши їм значення -1
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

// Знаходимо другий мінімальний та другий максимальний елементи
// і виключаємо їх з наступних пошуків, встановивши їм значення -1
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

// Знаходимо третій мінімальний та третій максимальний елементи
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

// Сума всіх вимірів мінус три максимальних та три мінімальних значення буде записана до 0-го елемента масива Res
    Res[0] = Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;
}
