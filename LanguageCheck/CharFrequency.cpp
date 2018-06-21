#include "CharFrequency.h"


CharFrequency::CharFrequency(string name)
{
	testlang = name;
}

void CharFrequency::TestFreq()
{
	string filename;
	filename = this->testlang + ".txt";
	fstream myfile;
	myfile.open(filename.c_str());
	string data;
	string text;
	vector <int> charcount(26);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, data);
			text += data;
		}
	}
	else cout << "Nie mozna otworzyc pliku" << endl;
	myfile.close();
	sort(text.begin(), text.end());
	int j = 0;
	for (int i = 65; i < 91; i++)
	{
		char temp = i;
		charcount[j] += count(text.begin(), text.end(), temp);
		j++;
	}
	j = 0;
	for (int i = 97; i < 123; i++)
	{
		char temp = i;
		charcount[j] += count(text.begin(), text.end(), temp);
		j++;
	}
	double sum = 0;
	double chartotal = 0;

	for (int i = 0; i < 26; i++)
	{
		chartotal += charcount[i];
	}
	for (int i = 0; i < 26; i++)
	{
		if (i == 25)
		{
			 freqtest[i] = (charcount[i] / chartotal) * 100;
		}
		else
		{
			freqtest[i] = (charcount[i] / chartotal) * 100 ;
		}
		sum += (charcount[i] / chartotal) * 100;
	}
	
	for (int i = 0; i < LanguageBase::languages.size(); i++)
	{
		string name = LanguageBase::languages[i] + "base.txt";
		myfile.open(name.c_str());
		string dat;
		int k=0;
		double equalnum = 0;
		double tolerance = 1;
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				 getline(myfile, dat);
				 //cout << stod(dat) << endl;
				 if (stod(dat) <= (freqtest[k] + tolerance) && (stod(dat) >= (freqtest[k] - tolerance)))
				 {
					 equalnum++;
					 k++;
				 }
			}
		}
		else cout << "Cannot open the file" << endl;
	
		percentage.push_back(equalnum / 26);
		myfile.close();
	}

}

CharFrequency::~CharFrequency()
{
}
