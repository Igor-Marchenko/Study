#include "Output.h" //ϳ�������� ������������ ���� ������ ������ (Output) ��� ������� �� ������� ������ ������ (������� ������, ������ �������)
#include "timer.h" //ϳ�������� ������������ ���� ������ ������ ��� ������� �� ������� ������ ������ (������� ������� ����������)
#include "common.h" //ϳ�������� ������������ ���� ������ ������ (common) ��� ������� �� ������� ����� ������� ������, �� ����������� � ����� ����� (�������, �������, ������)
#include "Input.h" //ϳ�������� ������������ ���� ������ �������� (Input) ��� ������� �� ������� ������ ������ (������� �������� ������������� ��������, �������� ���������� ��������, �������� �������� ������������� ��������)
#include "sortings.h" //ϳ�������� ������������ ���� ������ ���������� (sortings) ��� ������� �� ������� ������ ������ (������� ���������� ������� � ���������� ������� ��������,�������,������)

void output(int ident,int ident1,int ident2) //��������� ������� ������ ���������� ���������� �� �����
{
	printf("\n");
	switch (ident) //���� �� ����� ���� �� ��������� ����������� ����������� �� ������� �������� � ��������� �� ��������� � ������� ���������
	{
		case 1:
		{
			switch (ident1) //����������� ����������� �� ������� �������� 
			{
				case 1: 
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� �����
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
						switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� ����� 
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
						switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� ����� 
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
			switch (ident1) //����������� ����������� �� ������� �������� 
			{
				case 1: 
				{
					switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� ����� 
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
					switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� ����� 
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
					switch(ident2) //����������� ����������� �� ������� �������� - �������� ��������� ����� �� ����� 
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
	
	for(i=0;i<n1;i++) //���� ��� ��������� �������
	{
		printf("%d ",vect[i]); //��������� ��������� ��������
	}
	printf("\n\n");
	for(k=0;k<p;k++)  //��������� �������
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ", matr[k][i][j]); //��������� ��������� �������� �������
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

void gets_time(int ident,int ident1,int ident2) //��������� �������, �� �������� ������ ���������� ������䳿 � ��������� �� ���������, �� ���������� � �� �������
{
	int x; //����� � ���� int - ��������������� � ��������� �����
	for(x=0;x<measurements_number;x++) //���� ����������  ������� ����������
	{
		switch(ident) // ����������� ����������� �� ������� �������� ������� ������� ������� � ��������� �� ���������
		{
			case 1:
			{
				switch(ident1) //����������� ����������� �� ������� ��������
				{
					case 1:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=insertion_sort(); //������ ������� ���������� ������� �������� 
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=insertion_sort(); //������ ������� ���������� ������� �������� 
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=insertion_sort(); //������ ������� ���������� ������� �������� 
								break;
							}
						}
						break;	
					}
					case 2:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=selection_sort(); //������ ������� ���������� ������� ������� 
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=selection_sort(); //������ ������� ���������� ������� �������
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=selection_sort(); //������ ������� ���������� ������� �������
								break;
							}
						}
						break;	
					}
					case 3:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=exchange_flag_sort(); //������ ������� ���������� ������� ������ � ���������
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=exchange_flag_sort(); //������ ������� ���������� ������� ������ � ���������
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=exchange_flag_sort(); //������ ������� ���������� ������� ������ � ��������� 
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
				switch(ident1)  //����������� ����������� �� ������� ��������
				{
					case 1:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=insertion_vect(); //������ ������� ���������� ������� ��������
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=insertion_vect(); //������ ������� ���������� ������� ��������
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=insertion_vect();  //������ ������� ���������� ������� ��������
								break;
							}
						}
						break;	
					}
					case 2:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=selection_vect(); //������ ������� ���������� ������� �������
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=selection_vect(); //������ ������� ���������� ������� �������
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=selection_vect(); //������ ������� ���������� ������� �������
								break;
							}
						}
						break;	
					}
					case 3:
					{
						switch(ident2) //����������� ����������� �� ������� �������� - �������  ������� ���������� � ����������
						{
							case 1:
							{
								input_sorted(); //������ ������� �������� ������������� �������� � ������� � ������
								Res[x]=exchange_flag_vect(); //������ ������� ���������� ������� ������ � ���������
								break;		
							}
							case 2:
							{
								input_random(); //������ ������� �������� ���������� �������� � ������� � ������
								Res[x]=exchange_flag_vect(); //������ ������� ���������� ������� ������ � ���������
								break;	
							}
							case 3:
							{
								input_back_sorted(); //������ ������� �������� �������� ������������� �������� � ������� � ������
								Res[x]=exchange_flag_vect(); //������ ������� ���������� ������� ������ � ���������
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

void ouput_table() //��������� ������� ��������� ������� ����������
{
	printf("p=%d ", p);
	printf("m=%d ", m);
	printf("n=%d ", n);
	printf("n1=%d\n", n1);
	printf("\t\t\t\tOrdered \t Random \t Back Ordered\n\n");
	int z; //����� z ���� int - ��������������� � ��������� �����
   	for(z=0;z<6;z++)
	{	
	   	switch(z) ////����������� ����������� �� ������� �������� - �������  ������� ���������� ������� ���������� � ������� ����������
	   	{
	   	 	case 0:
	   		{
	   			printf("Insertion numb 1 matr");
	   			gets_time(1,1,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,1,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,1,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			printf("\n");
	   			break;
			}
			case 1:
	   		{
	   			printf("Insertion numb 1 vect");
	   			gets_time(2,1,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,1,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,1,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			printf("\n\n");
	   			break;
			}
			case 2:
	   		{
	   			printf("Selection numb 1 matr");
	   			gets_time(1,2,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,2,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,2,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			printf("\n");
	   			break;
			}
			case 3:
	   		{
	   			printf("Selection numb 1 vect");
	   			gets_time(2,2,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,2,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,2,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			printf("\n\n");
	   			break;
			}
			case 4:
	   		{
	   			printf("Exchange numb 2 matr");
	   			gets_time(1,3,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,3,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			gets_time(1,3,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]/20); //���� ���������� � �������
	   			printf("\n");
	   			break;
			}
			case 5:
	   		{
	   			printf("Exchange numb 2 vect");
	   			gets_time(2,3,1); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,3,2); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%6.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			gets_time(2,3,3); //������ ������� ���������� ������� ����������
	   			MeasurementProcessing(); //������ ������� ������� ����������
	   			printf("\t\t%10.1f ",(float)Res[0]*p/20); //���� ���������� � �������
	   			printf("\n\n");
	   			break;
			}
		}	
	}
}




