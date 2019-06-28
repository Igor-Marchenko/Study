#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>

#define MAX_SCORE 150

#define LOWER_NGRAM_LEN	2
#define UPPER_NGRAM_LEN	5
//Äîâæèíà ïğîô³ë³â êàòåãîğ³é é òåêñò³â, ùî ğîçï³çíàşòüñÿ
#define CATEGORY_LEN 1000
/* N-grams frequencies profile */
typedef std::pair<std::string, unsigned long> _map;
typedef std::vector<_map> frequency_map;
using namespace std;

class TextÑlassifier {
private:


	/*! internal frequency map */
	frequency_map _freqs;
	/*! internal name of classifer */
	std::string _category;

public:

	/* Name of category defaults to 'Unknown.' */
	TextÑlassifier() :_category("Unknown") {}

	/*Param classification - name of the category (e.g., "English").    */
	TextÑlassifier(const std::string category) :_category(category) {}

	/* returns the map N-grams and their frequencies.     */
	frequency_map freqs(); /* { return _freqs; }*/

						   /* returns the name of the classifier.*/
	std::string category(); /* { return _category; }*/

					   /*Param classification - name of the category.*/
	void setCategory(std::string& cat); /*{ _category = cat; }*/

								   /*learns the frequencies of N-grams in a corpus.*/
	void learn(std::istream& in);

	/*dumps the frequencies of N-grams in a corpus.
	File structure is as follows:
	* lines which start with c - comments
	* line which starts with s - classification
	* lines with N-grams start with n  and contain
	* N-gram and its quantity separated with space or tab*/
	void dumpProfile(std::ostream &out);

	/*learns the frequencies of N-grams from a file created by.
	dumpProfile() function */
	void learnfromDump(std::istream& in); 

	 /*returns distance measure between 2 TextÑlassifiers*/
	long int score(const TextÑlassifier &obj);
};

