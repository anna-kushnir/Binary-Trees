#include "functions.h"
using namespace std;

int inputNumOfElem()
{
	cout << "¬вед≥ть к≥льк≥сть елемент≥в посл≥довност≥: ";
	int n;
	while (true) {
		try {
			cin >> n;
			if (cin.fail()) throw "Incorrect";
			else {
				cin.clear();
				cin.ignore(32672, '\n'); 
				break;
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32672, '\n');
			cout << "¬и ввели некоректне число! ¬вед≥ть ц≥ле число: ";
		}
	}
	cout << "\n";
	return n;
}

int* inputArray(int n)
{
	int* arr = new int[n];
	int i = 0;
	while (i < n) {
		cout << "¬вед≥ть число з ≥ндексом " << i << ": ";
		while (true) {
			try {
				cin >> arr[i];
				if (cin.fail()) throw "Incorrect";
				else {
					cin.clear();
					cin.ignore(32672, '\n'); 
					i++;
					break;
				}
			}
			catch (const char*) {
				cin.clear();
				cin.ignore(32672, '\n');
				cout << "¬и ввели некоректне число! ¬вед≥ть ц≥ле число: ";
			}
		}
	}
	return arr;
}
