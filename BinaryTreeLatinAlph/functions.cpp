#include "functions.h"
using namespace std;

string inputString()
{
	string str;
	char ch;
	cin >> str;
	try {
		for (int i = 0; i < str.size(); ++i) {
			ch = str[i];
			if (!isalpha(ch)) throw "Incorrect";
		}
	}
	catch (const char*) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректне введення!\nВведіть рядок ще раз: ";
		str = inputString();
	}
	return str;
}
