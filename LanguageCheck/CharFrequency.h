#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "LanguageBase.h"

using namespace std;

class CharFrequency
{
public:
	string testlang;
	double freqtest[26];
	void TestFreq();
	vector <double> percentage;
	CharFrequency(string name);
	~CharFrequency();
};

