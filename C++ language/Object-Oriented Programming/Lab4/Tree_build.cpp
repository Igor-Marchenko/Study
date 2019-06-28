#include "CBinTree.h"
#include "CTreeNode.h"

int main() {
	Tree *tmp;
	tmp = new Tree();
	if (tmp == NULL)
		exit(-10);
	int x = 0;
	std::string Filename("Books.csv");
	tmp->add_from_file(Filename);
	std::cout << "Add_from_file function:\n\n";
	tmp->print_tree();
	tmp->add_exist("C++ Language", "Prata", 2007, 25);
	std::cout << "Add_exist function:\n\n";
	tmp->print_tree();
	tmp->delete_by_id((unsigned)6981);
	std::cout << "Delete_by_id function:\n\n";
	tmp->print_tree();
	std::cout << "Show_by_author function:\n\n";
	x = tmp->show_by_author("Virt");
	if (x == 0)
		std::cout << "\nThere are no books with such author";
	std::cout << std::endl;
	x = 0;
	std::cout << "Show_by_title function:\n\n";
	x = tmp->show_by_title("Algorithmes");
	if (x == 0)
		std::cout << "\nThere are no books with such title";
	std::cout << std::endl;
	tmp->~Tree();
	system("pause");
	exit(0);
}