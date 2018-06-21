#include "LanguageBase.h"

vector<string> LanguageBase::languages;

LanguageBase::LanguageBase(string lang)
{
	
	language = lang;
	languages.push_back(lang);
}

void LanguageBase::Learn()
{
	string filename;
	filename = (this->language) + ".txt";
	fstream myfile;
	myfile.open(filename.c_str());
	string data;
	string text;
	vector <int> charcount (26);
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
		charcount[j]+= count(text.begin(), text.end(), temp);
		j++;
	}
	j = 0;
	for (int i = 97; i < 123; i++)
	{
		char temp = i;
		charcount[j] += count(text.begin(), text.end(), temp);
		j++;
	}
	for (int i = 0; i < 26; i++)
	{
		//cout << charcount[i] << endl;
	}
	//cout << text << endl;
	//cout << chartotal;
	//sk³adnia fstream wziêta z instrukcji i pracy domowej B6 z æwiczeñ MiTP z pierwszego semestru, sk³adnia strtok z http://www.cplusplus.com/reference/cstring/strtok/


	string output;
	output = language + "base.txt";
	ofstream myfileout;

	
	double sum=0;
	double chartotal=0;
	myfileout.open(output.c_str());

	if (myfileout.is_open())
	{
		for (int i = 0; i < 26; i++)
		{
			chartotal += charcount[i];
		}
		for (int i = 0; i < 26; i++)
		{
			if (i == 25)
			{
				myfileout << (charcount[i]/chartotal)*100;
			}
			else
			{
				myfileout << (charcount[i]/chartotal)*100 << "\n";
			}
			sum += (charcount[i] / chartotal) * 100;
		}
	}
	else
	{
		cout << "Nie mozna otworzyc pliku" << endl;
	}
	myfileout.close();
	
}


LanguageBase::~LanguageBase()
{
}
