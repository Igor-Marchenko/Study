#include "CBinTree.h"
#include "CTreeNode.h"

void Tree::add(Node **ROOT, Node *tmp) {
	if (!*ROOT) {
		(*ROOT) = new Node(tmp);
		return;
	}
	if (tmp->Get_Id() < (*ROOT)->Get_Id())
		add(&((*ROOT)->Left), tmp);
	else
		if (tmp->Get_Id() > (*ROOT)->Get_Id())
			add(&((*ROOT)->Right), tmp);
}

int Tree::add_from_file(std::string File_name, Node **ROOT) {
	Node *tmp;
	std::string buff1, buff2;
	int cf = 0;
	unsigned count = 0;
	size_t size = 0, pos1 = 0, pos2 = 0;
	if (File_name.empty() == true)
		exit(-1);
	std:: ifstream fin;
	fin.open(File_name, std::ios_base::in);
	if (fin.is_open() == false) {
		perror("An Error occured while opening file\n");
		exit(-2);
	}
	while (std::getline(fin, buff1)) {
		tmp = new Node();
		if (tmp == NULL) {
			fin.close();
			exit(-3);
		}
		pos2 = 0;
		count = 0;
		pos1 = buff1.find_first_of(";");
		size = buff1.size();
		while (pos1 < size) {
			buff1[pos1] = '\0';
			buff2.append(buff1, pos2, (pos1 - pos2));
			pos2 = pos1 + 1;
			pos1 = buff1.find_first_of(";", pos1 + 1);
			switch (count) {
				case 0: {
					cf = std::stoi(buff2);
					tmp->Set_Id(cf);
					break;
				}
				case 1: {
					tmp->Set_Author(buff2);
					break;
				}
				case 2: {
					tmp->Set_Title(buff2);
					break;
				}
				case 3: {
					cf = std::stoi(buff2);
					tmp->Set_Year(cf);
					break;
				}
			}
			count++;
			buff2.erase();
		}
		buff2.append(buff1, pos2, (size - pos2));
		cf = std::stoi(buff2);
		buff2.erase();
		tmp->Set_Quantity(cf);
		tmp->Left = NULL;
		tmp->Right = NULL;
		add(ROOT, tmp);
		delete tmp;
	}
	fin.close();
	return 0;
}

int Tree::Biggest_Right(Node *ROOT) {
	while (ROOT->Right != NULL)
		ROOT = ROOT->Right;
	return ROOT->Get_Id();
}

Node* Tree::delete_by_id(Node **ROOT, unsigned number) {
	if ((*ROOT) == NULL)
		return NULL;
	if ((*ROOT)->Get_Id() == number) {
		if ((NULL == (*ROOT)->Left) && (NULL == (*ROOT)->Right)) {
			delete (*ROOT);
			return NULL;
		}
		if ((NULL == (*ROOT)->Right) && (NULL != (*ROOT)->Left)) {
			Node *tmp = (*ROOT)->Left;
			delete (*ROOT);
			return tmp;
		}
		if ((NULL == (*ROOT)->Left) && (NULL != (*ROOT)->Right)) {
			Node *tmp = (*ROOT)->Right;
			delete (*ROOT);
			return tmp;
		}
		int buff = Biggest_Right((*ROOT)->Left);
		(*ROOT)->Set_Id(buff);
		(*ROOT)->Left = delete_by_id(&((*ROOT)->Left), (*ROOT)->Get_Id());
	}
	if ((*ROOT)->Get_Id() < number) {
		(*ROOT)->Right = delete_by_id(&((*ROOT)->Right), number);
		return *ROOT;
	}
	if ((*ROOT)->Get_Id() > number) {
		(*ROOT)->Left = delete_by_id(&((*ROOT)->Left), number);
		return *ROOT;
	}
	return *ROOT;
}

Node* Tree::search_by(Node **ROOT, Node **tmp) {
	if ((*ROOT == NULL) || (*tmp == NULL))
		return NULL;
	if ((*ROOT)->Get_Author() == (*tmp)->Get_Author()) {
		if ((*ROOT)->Get_Title() == (*tmp)->Get_Title())
			if ((*ROOT)->Get_Year() == (*tmp)->Get_Year())
				return *ROOT;
	}
	Node *tmp1 = search_by(&((*ROOT)->Left), tmp);
	if (tmp1 == NULL) 
		tmp1 = search_by(&((*ROOT)->Right), tmp);
	return tmp1;
}

int Tree::add_exist(std::string Title, std::string Author, unsigned year, unsigned quantity, Node *ROOT) {
	if (Title.empty() == true)
		exit(1);
	if (Author.empty() == true)
		exit(2);
	if (year == 0)
		exit(3);
	if (quantity == 0)
		return 0;
	Node *tmp, *tmp1;
	tmp = new Node();
	if (tmp == NULL)
		exit(4);
	tmp->Set_Author(Author);
	tmp->Set_Title(Title);
	tmp->Set_Year(year);
	tmp->Set_Quantity(quantity);
	tmp1 = search_by(&ROOT, &tmp);
	if (tmp1 == NULL)
		exit(-15);
	unsigned nq = tmp->Get_Quantity();
	nq = nq + tmp1->Get_Quantity();
	tmp1->Set_Quantity(nq);
	delete tmp;
	return 0;
}

Node* Tree::delete_tree(Node **ROOT) {
	if ((*ROOT) == NULL)
		return NULL;
	if (((*ROOT)->Left == NULL) && ((*ROOT)->Right != NULL))
		(*ROOT)->Right = delete_tree(&((*ROOT)->Right));
	if (((*ROOT)->Left != NULL) && ((*ROOT)->Right == NULL))
		(*ROOT)->Left = delete_tree(&((*ROOT)->Left));
	if (((*ROOT)->Left == NULL) && ((*ROOT)->Right == NULL)) {
		delete (*ROOT);
		return NULL;
	}
	(*ROOT)->Left = delete_tree(&((*ROOT)->Left));
	(*ROOT)->Right = delete_tree(&((*ROOT)->Right));
	delete (*ROOT);
	return NULL;
}

void Tree::print_bintree(Node *ROOT) {
	if (ROOT != NULL) {
		if ((ROOT->Left == NULL) && (ROOT->Right != NULL)) {
			ROOT->Print_Node();
			print_bintree(ROOT->Right);
			return;
		}
		if ((ROOT->Left != NULL) && (ROOT->Right == NULL)) {
			print_bintree(ROOT->Left);
			ROOT->Print_Node();
			return;
		}
		if ((ROOT->Left == NULL) && (ROOT->Right == NULL)) {
			ROOT->Print_Node();
			return;
		}
		print_bintree(ROOT->Left);
		ROOT->Print_Node();
		print_bintree(ROOT->Right);
		return;
	}
	else
		return;
}

void Tree::show_by_author(Node *ROOT, std::string author, int *count) {
	if ((ROOT == NULL) || (author.empty() == true))
		return;
	if ((ROOT->Left == NULL) && (ROOT->Right != NULL)) {
		if (ROOT->Get_Author() == author) {
			ROOT->Print_Node();
			*count = 1;
		}
		show_by_author(ROOT->Right, author, count);
		return;
	}
	if ((ROOT->Left != NULL) && (ROOT->Right == NULL)) {
		show_by_author(ROOT->Left, author, count);
		if (ROOT->Get_Author() == author) {
			ROOT->Print_Node();
			*count = 1;
		}
		return;
	}
	if ((ROOT->Left == NULL) && (ROOT->Right == NULL)) {
		if (ROOT->Get_Author() == author) {
			ROOT->Print_Node();
			*count = 1;
		}
		return;
	}
	show_by_author(ROOT->Left, author, count);
	if (ROOT->Get_Author() == author) {
		ROOT->Print_Node();
		*count = 1;
	}
	show_by_author(ROOT->Right, author, count);
	return;
}

void Tree::show_by_title(Node *ROOT, std::string title, int *count) {
	if ((ROOT == NULL) || (title.empty() == true))
		return;
	if ((ROOT->Left == NULL) && (ROOT->Right != NULL)) {
		if (ROOT->Get_Title() == title) {
			ROOT->Print_Node();
			*count = 1;
		}
		show_by_title(ROOT->Right, title, count);
		return;
	}
	if ((ROOT->Left != NULL) && (ROOT->Right == NULL)) {
		show_by_title(ROOT->Left, title, count);
		if (ROOT->Get_Title() == title) {
			ROOT->Print_Node();
			*count = 1;
		}
		return;
	}
	if ((ROOT->Left == NULL) && (ROOT->Right == NULL)) {
		if (ROOT->Get_Title() == title) {
			ROOT->Print_Node();
			*count = 1;
		}
		return;
	}
	show_by_title(ROOT->Left, title, count);
	if (ROOT->Get_Title() == title) {
		ROOT->Print_Node();
		*count = 1;
	}
	show_by_title(ROOT->Right, title, count);
	return;
}