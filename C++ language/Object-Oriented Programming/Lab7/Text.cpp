#include"Text—lassifier.h"

frequency_map Text—lassifier::freqs()  { 
	return _freqs; 
}

std::string Text—lassifier::category()  { 
	return _category; 
}

void Text—lassifier::setCategory(std::string& cat) { 
	_category = cat; 
}

void Text—lassifier::learn(std::istream& in){
	std::string buff, tmp_buff, tmp;
	while (getline(in, buff)){
		if (buff.size() == 0)
			continue;
		int size = buff.size();
		int start = 0;
		for (int i = 0; i < size; i++){

			while (isalpha(buff[i]))
				i++;
			if (i - start >= 1){
				tmp = buff.substr(start, i - start);
				tmp = "_" + tmp;
				for (int j = LOWER_NGRAM_LEN; j <= UPPER_NGRAM_LEN; j++){
					tmp_buff = tmp;
					for (int i = 1; i < j; i++)
						tmp_buff.push_back('_');
					for (size_t j_ = 0; j_ <= tmp_buff.size() - j - 1; j_++){
						frequency_map::iterator it;
						for (it = _freqs.begin(); it != _freqs.end(); it++){
							if (it->first == tmp_buff.substr(j_, j)){
								it->second++;
								break;
							}

						}
						if (it == _freqs.end())
							_freqs.push_back(std::pair<std::string, unsigned long>(tmp_buff.substr(j_, j), 1));
					}
				}
			}
			start = i + 1;
		}
	}
	sort(_freqs.begin(), _freqs.end(), [](const _map& a, const _map& b) {return a.second>b.second;});
	_freqs.resize(CATEGORY_LEN);
}

void Text—lassifier::dumpProfile(std::ostream& out) {
	out << "s " << _category << std::endl;
	for (frequency_map::iterator it = _freqs.begin(); it != _freqs.end(); it++)
		out << "n " << std::setw(6) << std::left << it->first << std::setw(5) << std::left << it->second << std::endl;
}

void Text—lassifier::learnfromDump(std::istream& in) {
	_freqs.clear();
	std::string buff, tmp;
	int pos = 0;
	while (getline(in, buff)){
		if (buff[0] == 'c')
			continue;
		if (buff[0] == 's'){
			_category = buff.substr(2, buff.size() - 1);
			continue;
		}
		if (buff[0] != 'n')
			continue;
		pos = buff.find(' ');
		buff = buff.substr(pos + 1, buff.size());
		pos = buff.find(' ');
		_freqs.push_back(std::pair<std::string, unsigned long>(buff.substr(0, pos), 0));
		if (_freqs.size() == CATEGORY_LEN)
			break;
	}
}

long int Text—lassifier::score(const Text—lassifier &obj) {
	const frequency_map *s1 = NULL, *s2 = NULL;
	std::string str;
	long int score = 0;
	long int i, j;
	if (_freqs.size() >= obj._freqs.size()){
		s1 = &_freqs;
		s2 = &obj._freqs;
	}
	else{
		s2 = &_freqs;
		s1 = &obj._freqs;
	}
	for (i = 0; i < (long int)s1->size(); i++){
		str = (*s1)[i].first;
		bool found = false;
		for (j = 0; j < (long int)s2->size(); j++){
			if ((*s2)[j].first == str){
				score += abs(i - j);
				found = true;
				break;
			}
		}
		if (found == false)
			score += MAX_SCORE;
	}
	return score;
}
