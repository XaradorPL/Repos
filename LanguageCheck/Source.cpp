#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "CharFrequency.h"
using namespace std;

int main()
{

	LanguageBase Pol("polish");
	Pol.Learn();
	LanguageBase Eng("english");
	Eng.Learn();
	LanguageBase Cz("czech");
	Cz.Learn();
	LanguageBase Esp("espanol");
	Esp.Learn();

	CharFrequency TestF("test");
	TestF.TestFreq();
	double max = 0;
	int j=0;
	for (int i = 0; i < TestF.percentage.size(); i++)
	{
		if (TestF.percentage[i] > max)
			max = TestF.percentage[i];
		if (TestF.percentage[i] == max)
			j = i;
	}
	for (int i = 0; i < TestF.percentage.size(); i++)
	{
		cout << "Language: " << LanguageBase::languages[i] << " matches the template in " << TestF.percentage[i]*100 << "%" << endl;
	}
	cout <<endl<< "The text is probably in " << LanguageBase::languages[j] << endl;
	
	system("PAUSE");
	return 0;
}