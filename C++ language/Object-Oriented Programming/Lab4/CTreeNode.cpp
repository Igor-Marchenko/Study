#include "CTreeNode.h"

std:: string Node::Get_Author() const{
	return this->m_Author;
}
std::string Node::Get_Title() const{
	return this->m_Title;
}
 unsigned Node::Get_Id() const{
	return this->m_BookId;
}
 unsigned Node::Get_Year() const{
	return this->m_Year;
}

 unsigned Node::Get_Quantity() const {
	 return this->m_Quantity;
 }

 void Node:: Print_Node() {
	 std::cout << "\Author:\n" << this->Get_Author() << "\nTitle:\n" << this->Get_Title() << "\nYear:\n";
	 std::cout << this->Get_Year() << "\nNumder of the books:\n" << this->Get_Quantity() << "\nIdentifier:\n";
	 std::cout<< this->Get_Id() << std::endl << std::endl << std::endl;
 }

 void Node:: Set_Year(unsigned nmb) {
	m_Year = nmb;
 }

 void Node::Set_Quantity(unsigned nmb) {
	m_Quantity = nmb;
 }

 void Node::Set_Id(unsigned nmb) {
	 m_BookId = nmb;
 }

 void Node::Set_Author(std::string Author) {
	 m_Author = Author;
 }

 void Node::Set_Title(std::string Name) {
	 m_Title = Name;
 }
 