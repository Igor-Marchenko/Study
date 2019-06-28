#include"Text—lassifier.h"

void make_dump(std::string str) {
	std::string file;
	Text—lassifier obj;
	obj.setCategory(str);
	file = str + ".txt";
	std::ifstream r_file(file);
	obj.learn(r_file);
	file = str + ".dump";
	std::ofstream w_file(file);
	obj.dumpProfile(w_file);
	r_file.close();
	w_file.close();
}

void make_score(std::string str){
	std::string file;
	Text—lassifier text, text2;
	file = str + ".score";
	std::ofstream w_file(file, std::ios_base::app);
	std::ifstream r_file("English.dump");
	text.learnfromDump(r_file);
	r_file.close();
	file = str + ".dump";
	std::ifstream read(file);.
	if (!read.is_open()){
		file = str + ".txt";
		std::ifstream unknown(file);
		text2.learn(unknown);
		file = str + ".dump";
		std::ofstream w_file2(file);
		text2.dumpProfile(w_file2);
	}
	else
		text2.learnfromDump(read);
	w_file << "text English: " << text.score(text2);
	r_file.open("French.dump");
	text.learnfromDump(r_file);
	r_file.close();
	w_file << "\ntext French: " << text.score(text2);
	r_file.open("Italian.dump");
	text.learnfromDump(r_file);
	r_file.close();
	w_file << "\ntext Italian:" << text.score(text2);
	r_file.open("Spain.dump");
	text.learnfromDump(r_file);
	r_file.close();
	w_file << "\ntext Spain:" << text.score(text2);
	w_file << "\n____________________________\n";
}

int main(){
	std::ifstream source("textENG.txt");
	/*make_dump("English");
	make_dump("French");
	make_dump("Italian");
	make_dump("Spain");*/
	make_score("textENG");
	make_score("English");
	make_score("French");
	make_score("Italian");
	make_score("Spain");
	source.close();
	system("pause");
	return 0;
}


