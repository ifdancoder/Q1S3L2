#pragma once

#include "Timer.h"
#include <fstream>
#include <string>
#include <functional>
#include <algorithm>

extern std::string vowels;

bool ForVowels(char ch);
int ForCntr(std::istream_iterator<char> beg, std::istream_iterator<char> end, bool (*func) (char));

int VowelCountIfFind(std::ifstream& ist);
int VowelCountIfFor(std::ifstream& ist);
int VowelForFind(std::ifstream& ist);
int VowelForFor(std::ifstream& ist);

class TextReader {
private:
	std::ifstream fin;
	std::string fname;
	size_t n = 1;
	size_t vow_cnt = 0;
public:
	TextReader(std::string fname = "text.txt");
	void TimerVowelCounter(int (*func) (std::ifstream& ist));
};