/*!
* file: cArray.h
* cArray class declaration
* written: 15/11/2017
* Copyright (c) 2017 by MarIO
*/

#pragma once
#include <iostream>

class cArray {
	//The minimum number of element slots to allocate if a size increase is necessary. 
	#define GROWBY 10
public:
	//Constructs an empty array.
	cArray(void);
	~cArray(void);

	//Attributes
	//Gets the number of elements in this array.
	int Getsize() const;
	//Gets the number of elements in this array.
	int Getcount() const;
	//Returns the largest valid index.
	int Getupperbound() const;
	//Determines whether the array is empty.
	bool IsEmpty()const;
	//Establishes the size of an empty or existing array; allocates memory if necessary.
	void SetSize(int nnewsize);

	//Operations
	//Frees all unused memory above the current upper bound.
	//This function has no effect on the upper bound of the array.
	void FreeExtra();

	//Removes all the elements from this array.
	void RemoveAll();

	//Element Access
	//Returns the value at a given index.
	int GetAt(int)const;
	//Sets the value for a given index; array not allowed to grow.
	void SetAt(int n, int indx);

	//Growing the Array
	//Adds an element to the end of the array; grows the array if necessary.
	void Add(int);
	//Appends another array to the array; grows the array if necessary
	void Append(cArray *);
	//Copies another array to the array; grows the array if necessary.
	void Copy(cArray *);

	//Insertion/Removal
	//Inserts an element at a specified index.
	void InsertAt(int n, int indx);
	//Removes an element at a specific index.
	void RemoveAt(int);

	//Operators
	//Sets or gets the element at the specified index.
	int& operator [](int);
private:
	int *arr=NULL;
	int size;
	int count;
	int upper_bound;
};
