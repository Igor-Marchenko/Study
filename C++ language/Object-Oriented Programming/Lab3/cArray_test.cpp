#include "cArray.h"
#include <time.h>

int main() {
	int i = 0;
	srand(time(NULL));
	cArray *vect = NULL, *mas1=NULL, *mas2=NULL;
	if ((NULL == (vect = new cArray)) || (NULL == (mas1 = new cArray)) || (NULL == (mas2 = new cArray)))
		exit (-1);
	vect->SetSize(12);
	mas1->SetSize(15);
	for (i = 0; i < (vect->Getsize()); i++) {
		vect->Add(0 + rand() % 10);
	}
	for (i = 0; i < (mas1->Getsize()); i++) {
		mas1->Add(i + 1);
	}
	for (i = 0; i < (mas2->Getsize()); i++) {
		mas2->Add(i + 2);
	}
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Mas1" << std::endl;
	for (i = 0; i <= mas1->Getupperbound(); i++) {
		std::cout << mas1->GetAt(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Mas2" << std::endl;
	for (i = 0; i <= mas2->Getupperbound(); i++) {
		std::cout << mas2->GetAt(i) << " ";
	}
	std::cout << std::endl;
	vect->Copy(mas1);
	vect->Append(mas2);
	std::cout << "Size is " << vect->Getsize() << std::endl;
	std::cout << "Number of elements is " << vect->Getcount() << std::endl;
	std::cout << "Upper_bound is " << vect->Getupperbound() << std::endl;
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	std::cout<< "Getting element from the position 8: element is " <<vect->GetAt(8) << std::endl;
	vect->SetAt(10, 3);
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	vect->FreeExtra();
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	vect->RemoveAt(3);
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	vect->InsertAt(100, 7);
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "At the position 2: " << (*vect)[2] << std::endl;
	vect->RemoveAll();
	std::cout << "Vect" << std::endl;
	for (i = 0; i <= vect->Getupperbound(); i++) {
		std::cout << vect->GetAt(i) << " ";
	}
	std::cout << std::endl; 
	(*vect)[100] = 0;
	system("pause");
	exit (0);
}