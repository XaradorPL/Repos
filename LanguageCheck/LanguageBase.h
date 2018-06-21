#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class LanguageBase
{
public:
	static vector <string> languages;
	string language;

	void Learn();

	LanguageBase(string lang);
	~LanguageBase();
};

