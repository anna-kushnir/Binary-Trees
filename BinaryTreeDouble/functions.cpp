#include "functions.h"
using namespace std;

double* inputNums(int& n)
{
	cout << "������ ������� ����� ������: ";
	while (true) {
		try {
			cin >> n;
			if (cin.fail()) throw "���������� ��������";
			else {
				cin.clear();
				cin.ignore(32762, '\n');
				break;
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32762, '\n'); 
			cout << "���������� �������� �����: �� ������ ������ ����� �����!\n��������� �� ���: ";
		}
	}
	cout << "\n";
	double* nums = new double[n];
	for (int i = 0; i < n; ++i) {
		cout << "������ ����� � �������� " << i << ": ";
		while (true) {
			try {
				cin >> nums[i];
				if (cin.fail()) throw "���������� ��������";
				else {
					cin.clear();
					cin.ignore(32762, '\n');
					break;
				}
			}
			catch (const char*) {
				cin.clear();
				cin.ignore(32762, '\n');
				cout << "���������� �������� �����: �� ������ ������ ����� �����!\n��������� �� ���: ";
			}
		}
	}
	return nums;
}

