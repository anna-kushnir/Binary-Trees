#include "functions.h"
using namespace std;

int inputCountOfNums()
{
	int n;
	cout << "������ ������� �������� �����������: ";
	while (true) {
		try {
			cin >> n;
			if (cin.fail()) throw "Incorrect";
			else {
				cin.clear();
				cin.ignore(32627, '\n');
				break;
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32627, '\n'); 
			cout << "����������� ���! ������ ���� �����: ";
		}
	}
	return n;
}

int* inputNums(int n)
{
	int* nums = new int[n];
	for (int i = 0; i < n; ++i) {
		cout << "������ ������� � �������� " << i << ": ";
		while (true) {
			try {
				cin >> nums[i];
				if (cin.fail()) throw "Incorrect";
				else {
					cin.clear();
					cin.ignore(32627, '\n');
					break;
				}
			}
			catch (const char*) {
				cin.clear();
				cin.ignore(32627, '\n');
				cout << "����������� ���! ������ ���� �����: ";
			}
		}
	}
	return nums;
}

void outputArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
