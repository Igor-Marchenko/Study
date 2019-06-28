#pragma once
#include "CTreeNode.h"
#include <fstream>

class Tree{
	private:
		Node *root;
		Node *search_by(Node **ROOT, Node **tmp);
		Node* delete_by_id(Node **ROOT, unsigned number);
		void add(Node **ROOT, Node *tmp);
		int Biggest_Right(Node *ROOT);
		Node* delete_tree(Node **ROOT);
		void print_bintree(Node *ROOT);
		void show_by_author(Node *ROOT, std::string author, int *count);
		void show_by_title(Node *ROOT, std::string title, int *count);
		int add_from_file(std::string File_name, Node **ROOT);
		int add_exist(std::string Title, std::string Author, unsigned year, unsigned quantity, Node *ROOT);
	public:
		Tree() : root(NULL){}

		int add_exist(std::string Title, std::string Author, unsigned year, unsigned quantity) {
			add_exist(Title, Author, year, quantity, this->root);
			return 0;
		}

		int add_from_file(std::string File_name) {
			add_from_file(File_name, &(this->root));
			return 0;
		}

		void delete_by_id(unsigned number) {
			 delete_by_id(&(this->root), number);
		}

		int show_by_author(std::string author) {
			int x = 0;
			show_by_author(this->root, author, &x);
			return x;
		}

		int show_by_title(std::string title) {
			int x = 0;
			show_by_title(this->root, title, &x);
			return x;
		}

		void print_tree() {
			print_bintree(this->root);
		}

		~Tree() {
			this->root = delete_tree(&(this->root));
		}

		void test() {
			if (this->root != NULL)
				std::cout << "It is a Betrayal\n";
		}
};