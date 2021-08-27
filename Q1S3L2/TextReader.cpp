#include "TextReader.h"

std::string vowels = "AaEeIiOoUuYy";

bool ForVowels(char ch) {
	for (int i = 0; i < vowels.size(); i++) {
		if (ch == vowels[i]) {
			return true;
		}
	}
	return false;
}

int ForCntr(std::istream_iterator<char> beg, std::istream_iterator<char> end, bool (*func) (char)) {
	int tmp_cnt = 0;
	for (auto i = beg; i != end; i++) {
		if (func(*i)) {
			tmp_cnt++;
		}
	}
	return tmp_cnt;
}

int VowelCountIfFind(std::ifstream& ist) {
	return std::count_if(std::istream_iterator<char>(ist), std::istream_iterator<char>(),
		[](char ch) { return (bool)(vowels.find(ch) + 1); });
}

int VowelCountIfFor(std::ifstream& ist) {
	return std::count_if(std::istream_iterator<char>(ist), std::istream_iterator<char>(), ForVowels);
}

int VowelForFind(std::ifstream& ist) {
	return ForCntr(std::istream_iterator<char>(ist), std::istream_iterator<char>(), [](char ch) { return (bool)(vowels.find(ch) + 1); });
}

int VowelForFor(std::ifstream& ist) {
	return ForCntr(std::istream_iterator<char>(ist), std::istream_iterator<char>(), ForVowels);
}

TextReader::TextReader(std::string fname) : fname(fname) {
	fin.open(fname);
}

void TextReader::TimerVowelCounter(int (*func) (std::ifstream& ist)) {
	Timer t("Time");
	vow_cnt = func(fin);
	std::cout << n << ") Result is " << vow_cnt << std::endl;
	t.print();
	fin.close();
	fin.open(fname);
	n++;
}