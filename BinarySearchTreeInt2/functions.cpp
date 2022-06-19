#include "functions.h"
using namespace std;

int inputNumOfElem()
{
	cout << "������ ������� �������� �����������: ";
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
			cout << "�� ����� ���������� �����! ������ ���� �����: ";
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
		cout << "������ ����� � �������� " << i << ": ";
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
				cout << "�� ����� ���������� �����! ������ ���� �����: ";
			}
		}
	}
	return arr;
}
