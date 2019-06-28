#pragma once
#include <iostream>
#include <cstdlib> 
#include <string>
#include <string.h>
#include <Windows.h>

class Node {
	private:
		unsigned m_BookId;
		std:: string m_Author;
		std:: string m_Title;
		unsigned m_Year;
		unsigned m_Quantity;
	public:
		Node *Left;
		Node *Right;
		Node() : m_BookId(0), m_Year(0), m_Quantity(0), Left(NULL), Right(NULL) {}
		Node(Node *ptr) {
			m_BookId = ptr->Get_Id();
			m_Quantity = ptr->Get_Quantity();
			m_Year = ptr->Get_Year();
			m_Author = ptr->Get_Author();
			m_Title = ptr->Get_Title();
		}
		~Node(){}
		void Set_Year(unsigned nmb);
		void Set_Quantity(unsigned nmb);
		void Set_Id(unsigned nmb);
		void Set_Author(std::string Author);
		void Set_Title(std::string Name);
		std:: string Get_Author() const;
		std:: string Get_Title() const;
		unsigned Get_Id() const;
		unsigned Get_Year() const;
		unsigned Get_Quantity() const;
		void Print_Node();
};