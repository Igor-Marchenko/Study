#include "cArray.h"

cArray::cArray() {
	count = 0;
	size = GROWBY;
	upper_bound = count - 1;
	arr = new int [size];
}

cArray::~cArray() {
	delete[] arr;
}

int cArray::Getsize() const {
	return this->size;
}

int cArray::Getcount() const {
	return this->count;
}

int cArray::Getupperbound() const {
	return this->upper_bound;
}

bool cArray::IsEmpty() const {
	return (count == 0) ? true : false;
}

void cArray::SetSize(int nnewsize) {
	int *buff = NULL;
	int i = 0;
	if (nnewsize == 0) {
		this->~cArray();
		arr = NULL;
		count = 0;
		upper_bound = -1;  
		return;
	}
	if ((size < nnewsize) || (size > nnewsize)) {
		if (NULL == (buff = new int[count]))
			return;
		for (i = 0; i < count; i++)
			buff[i] = arr[i];
		this->~cArray();
		size = nnewsize;
		if(NULL == (arr = new int[size])) {
			delete[]buff;
			return;
		}
		if (count > size) {
			count = size;
			upper_bound = count - 1;
		}
		for (i = 0; i <= this->Getupperbound(); i++) 
			arr[i] = buff[i];
		delete[]buff;
	}
}

void cArray::FreeExtra() {
	int *buff = NULL;
	int i = 0;
	if (NULL == (buff = new int[count]))
		return;
	for (i = 0; i < count; i++)
		buff[i] = arr[i];
	this->~cArray();
	size = count;
	if (NULL == (arr = new int[size])) {
		delete[]buff;
		return;
	}
	for (i = 0; i < size; i++)
		arr[i] = buff[i];
	delete[]buff;
}

void cArray::RemoveAll() {
	this->~cArray();
	size = GROWBY;
	count = 0;
	upper_bound = -1;
	if (NULL == (arr = new int[size]))
		return;
}

int cArray::GetAt(int indx) const {
	if ((indx >= 0) && (indx <= this->Getupperbound())) {
			return arr[indx];
	}		
	else {
		system("pause");
		exit(99);
	}
}

void cArray::SetAt(int n, int indx) {
		if ((indx >= 0) && (indx <= this->Getupperbound())) {
			this->arr[indx] = n;
			return;
		}
		else {
			system("pause");
			exit(109);
		}
}

void cArray::Add(int n) {
	int *buff = NULL;
	int i = 0;
	if (upper_bound >= size - 1) {
		if (NULL == (buff = new int[size])) {
			return;
		}
		for (i = 0; i < count; i++)
			buff[i] = arr[i];
		this->~cArray();
		size += GROWBY;
		if (NULL == (arr = new int[size])) {
			delete[]buff;
			return;
		}
		for (i = 0; i <= this->Getupperbound(); i++) 
			arr[i] = buff[i];
	}
	delete[]buff;
	count++;
	upper_bound++;
	arr[upper_bound] = n;
}

void cArray::Append(cArray *ar) {
	if (ar == NULL)
		return;
	int *buff = NULL;
	int i = 0, numb = ar->Getcount();
	if ((size - count) < numb) {
		if (NULL == (buff = new int[count]))
			return;
		for (i = 0; i < count; i++)
			buff[i] = arr[i];
		this->~cArray();
		while ((size - count) < numb)
			size += GROWBY;
		if (NULL == (arr = new int[size])) {
			delete[]buff;
			return;
		}
		for (i = 0; i < count; i++)
			arr[i] = buff[i];
		for (i = count; i < size; i++) {
			if (i < count + numb)
				arr[i] = ar->arr[i - count];
		}
		delete[]buff;
	}
	else {
		for(i=count; i < count + numb; i++)
			arr[i] = ar->arr[i - count];
	}
	count += numb;
	upper_bound = count - 1;
}

void cArray::Copy(cArray *ar) {
	this->~cArray();
	if (ar == NULL) 
		return;
	int i = 0, numb = ar->Getsize();
	if (size  < numb) {
		while (size < numb)
			size += GROWBY;
	}
	if (NULL == (arr = new int[size])) {
		return;
	}
	count = ar->count;
	upper_bound = count - 1;
	for (i = 0; i <= this->Getupperbound(); i++) 
			arr[i] = ar->arr[i];
}

void cArray::InsertAt(int n, int indx) {
	int *buff = NULL;
	int i = 0, place = 0;
	if((indx >=0 )&&(indx <= upper_bound)) {
		if (upper_bound == size - 1) {
			if (NULL == (buff = new int[size]))
				return;
			for (i = 0; i < size; i++)
				buff[i] = arr[i];
			this->~cArray();
			size += GROWBY;
			if (NULL == (arr = new int[size])) {
				delete[]buff;
				return;
			}
			for (i = 0; i <= Getupperbound(); i++) 
				arr[i] = buff[i];
			delete[]buff;
		}
		for (i = upper_bound; i >= indx; i--)
			arr[i + 1] = arr[i];
		arr[indx] = n;
		upper_bound++;
		count++;
	}
	else {
		system("pause");
		exit(213);
	}
}

void cArray::RemoveAt(int indx) {
	int i = 0;
	if ((indx >= 0) && (indx <= upper_bound)) {
		for (i = indx; i < upper_bound; i++)
			arr[i] = arr[i + 1];
		arr[upper_bound] = 0;
		if (count > 0) 
			count--;
		upper_bound--;
	}
	else {
		system("pause");
		exit(249);
	}
}

int & cArray::operator[](int indx) {
	if ((indx >= 0) && (indx <= this->upper_bound))
		return this->arr[indx];
	else {
		system("pause");
		exit(264);
	}
}


