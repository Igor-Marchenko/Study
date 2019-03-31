#include "Output.h" //Підключаємо заголовочний файл модуля виводу (Output) для доступу до функцій даного модуля (функцій виводу, виводу таблиці)
#include "timer.h" //Підключаємо заголовочний файл модуля таймер для доступу до функцій даного модуля (функції обробки результатів)
#include "common.h" //Підключаємо заголовочний файл модуля коммон (common) для доступу до спільних даних окремих модулів, що знаходяться в цьому модулі (матриці, вектора, змінних)
#include "Input.h" //Підключаємо заголовочний файл модуля введення (Input) для доступу до функцій даного модуля (функції введення впорядкованих елементів, введення випадкових елементів, введення обернено впорядкованих елементів)
#include "sortings.h" //Підключаємо заголовочний файл модуля сортування (sortings) для доступу до функцій даного модуля (функції сортування матриці і сортування вектора вставкою,вибором,обміном)

void output(int ident,int ident1,int ident2) //Безтипова функція виводу результатів сортування на екран
{
	printf("\n");
	switch (ident) //Вивід на екран назв за допомогою конструкції перемикання із набором констант в залежності від переданих у функцію параметрів
	{
		case 1:
		{
			switch (ident1) //конструкція перемикання із набором констант 
			{
				case 1: 
					{
						switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран
						{
							case 1:{
										printf("Insertion Sort - Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 2:{
										printf("Insertion Sort - Random Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 3:{
										printf("Insertion Sort - Back Ordered Vector and Matrix");
										printf("\n");
										break;
									}
						}
						break;
					}
				case 2: 
					{
						switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран 
						{
							case 1:{
										printf("Selection Sort - Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 2:{
										printf("Selection Sort - Random Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 3:{
										printf("Selection Sort - Back Ordered Vector and Matrix");
										printf("\n");
										break;
									}
						}
						break;
					}	
				case 3: 
					{
						switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран 
						{
							case 1:{
										printf("Exchange with a Flag Sort - Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 2:{
										printf("Exchange with a Flag Sort - Random Ordered Vector and Matrix");
										printf("\n");
										break;
									}
							case 3:{
										printf("Exchange with a Flag Sort - Back Ordered Vector and Matrix");
										printf("\n");
										break;
									}
						}
						break;
					}				
			}
			break;
		}
		case 2:
		{
			switch (ident1) //конструкція перемикання із набором констант 
			{
				case 1: 
				{
					switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран 
					{
						case 1:{
									printf("Insertion Sort - Sorted Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 2:{
									printf("Insertion Sort - Sorted Random Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 3:{
									printf("Insertion Sort - Sorted Back Ordered Vector and Matrix");
									printf("\n");
									break;
								}
					}
					break;
				}
				case 2: 
				{
					switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран 
					{
						case 1:{
									printf("Selection Sort - Sorted Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 2:{
									printf("Selection Sort - Sorted Random Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 3:{
									printf("Selection Sort - Sorted Back Ordered Vector and Matrix");
									printf("\n");
									break;
								}
					}
					break;
				}	
				case 3: 
				{
					switch(ident2) //конструкція перемикання із набором констант - виводить необхідну назву на екран 
					{
						case 1:{
									printf("Exchange with a Flag Sort - Sorted Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 2:{
									printf("Exchange with a Flag Sort - Sorted Random Ordered Vector and Matrix");
									printf("\n");
									break;
								}
						case 3:{
									printf("Exchange with a Flag Sort - Sorted Back Ordered Vector and Matrix");
									printf("\n");
									break;
								}
					}
					break;
				}				
			}
			break;	
		}
	}
	
	for(i=0;i<n1;i++) //цикл для виведення вектора
	{
		printf("%d ",vect[i]); //виведення чергового елемента
	}
	printf("\n\n");
	for(k=0;k<p;k++)  //виведення матриці
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ", matr[k][i][j]); //виведення чергового елемента матриці
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

void gets_time(int ident,int ident1,int ident2) //Безтипова функція, що заповнює вектор результатів швидкодії в залежності від параметрів, які передються в цю функцію
{
	int x; //змінна х типу int - використовується в заголовку цикла
	for(x=0;x<measurements_number;x++) //цикл заповнення  вектора результатів
	{
		switch(ident) // конструкція перемикання із набором констант викликає потрібну функцію в залежності від параметрів
		{
			case 1:
			{
				switch(ident1) //конструкція перемикання із набором констант
				{
					case 1:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=insertion_sort(); //виклик функції сортування матриці вставкою 
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=insertion_sort(); //виклик функції сортування матриці вставкою 
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=insertion_sort(); //виклик функції сортування матриці вставкою 
								break;
							}
						}
						break;	
					}
					case 2:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=selection_sort(); //виклик функції сортування матриці вибором 
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=selection_sort(); //виклик функції сортування матриці вибором
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=selection_sort(); //виклик функції сортування матриці вибором
								break;
							}
						}
						break;	
					}
					case 3:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=exchange_flag_sort(); //виклик функції сортування матриці обміном з прапорцем
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=exchange_flag_sort(); //виклик функції сортування матриці обміном з прапорцем
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=exchange_flag_sort(); //виклик функції сортування матриці обміном з прапорцем 
								break;
							}
						}
						break;	
					}
				}
				break;	
			}
			case 2:
			{
				switch(ident1)  //конструкція перемикання із набором констант
				{
					case 1:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=insertion_vect(); //виклик функції сортування вектора вставкою
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=insertion_vect(); //виклик функції сортування вектора вставкою
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=insertion_vect();  //виклик функції сортування вектора вставкою
								break;
							}
						}
						break;	
					}
					case 2:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=selection_vect(); //виклик функції сортування вектора вибором
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=selection_vect(); //виклик функції сортування вектора вибором
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=selection_vect(); //виклик функції сортування вектора вибором
								break;
							}
						}
						break;	
					}
					case 3:
					{
						switch(ident2) //конструкція перемикання із набором констант - викликає  функції заповнення і сортування
						{
							case 1:
							{
								input_sorted(); //виклик функції введення впорядкованих елементів в матрицю і вектор
								Res[x]=exchange_flag_vect(); //виклик функції сортування вектора обміном з прапорцем
								break;		
							}
							case 2:
							{
								input_random(); //виклик функції введення випадкових елементів в матрицю і вектор
								Res[x]=exchange_flag_vect(); //виклик функції сортування вектора обміном з прапорцем
								break;	
							}
							case 3:
							{
								input_back_sorted(); //виклик функції введення обернено впорядкованих елементів в матрицю і вектор
								Res[x]=exchange_flag_vect(); //виклик функції сортування вектора обміном з прапорцем
								break;
							}
						}
						break;	
					}
				}
				break;
			}
		}
	}
}

void ouput_table() //Безтипова функція виведення таблиці результатів
{
	printf("p=%d ", p);
	printf("m=%d ", m);
	printf("n=%d ", n);
	printf("n1=%d\n", n1);
	printf("\t\t\t\tOrdered \t Random \t Back Ordered\n\n");
	int z; //змінна z типу int - використовується в заголовку цикла
   	for(z=0;z<6;z++)
	{	
	   	switch(z) ////конструкція перемикання із набором констант - викликає  функції заповнення вектора результатів і обробки результатів
	   	{
	   	 	case 0:
	   		{
	   			printf("Insertion numb 1 matr");
	   			gets_time(1,1,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,1,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,1,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			printf("\n");
	   			break;
			}
			case 1:
	   		{
	   			printf("Insertion numb 1 vect");
	   			gets_time(2,1,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,1,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,1,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			printf("\n\n");
	   			break;
			}
			case 2:
	   		{
	   			printf("Selection numb 1 matr");
	   			gets_time(1,2,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,2,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,2,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			printf("\n");
	   			break;
			}
			case 3:
	   		{
	   			printf("Selection numb 1 vect");
	   			gets_time(2,2,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,2,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,2,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			printf("\n\n");
	   			break;
			}
			case 4:
	   		{
	   			printf("Exchange numb 2 matr");
	   			gets_time(1,3,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,3,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			gets_time(1,3,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //вивід результата в таблицю
	   			printf("\n");
	   			break;
			}
			case 5:
	   		{
	   			printf("Exchange numb 2 vect");
	   			gets_time(2,3,1); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,3,2); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			gets_time(2,3,3); //виклик функції заповнення вектора результатів
	   			MeasurementProcessing(); //виклик функції обробки результатів
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //вивід результата в таблицю
	   			printf("\n\n");
	   			break;
			}
		}	
	}
}




