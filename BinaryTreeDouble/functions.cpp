#include "functions.h"
using namespace std;

double* inputNums(int& n)
{
	cout << "Введіть кількість вузлів дерева: ";
	while (true) {
		try {
			cin >> n;
			if (cin.fail()) throw "Некоректне введення";
			else {
				cin.clear();
				cin.ignore(32762, '\n');
				break;
			}
		}
		catch (const char*) {
			cin.clear();
			cin.ignore(32762, '\n'); 
			cout << "Некоректне введення даних: ви повинні ввести дійсне число!\nСпробуйте ще раз: ";
		}
	}
	cout << "\n";
	double* nums = new double[n];
	for (int i = 0; i < n; ++i) {
		cout << "Введіть число з індексом " << i << ": ";
		while (true) {
			try {
				cin >> nums[i];
				if (cin.fail()) throw "Некоректне введення";
				else {
					cin.clear();
					cin.ignore(32762, '\n');
					break;
				}
			}
			catch (const char*) {
				cin.clear();
				cin.ignore(32762, '\n');
				cout << "Некоректне введення даних: ви повинні ввести дійсне число!\nСпробуйте ще раз: ";
			}
		}
	}
	return nums;
}

void sortArray(double* arr, int len)
{
	bool flag = true;
	for (int i = 0; i < len && flag; ++i) {
		flag = false;
		for (int j = 0; j < len - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				flag = true;
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

double countAverage(double* arr, int len)
{
	if (len == 0) return 0;
	double sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += arr[i];
	}
	return (double)(sum / len);
}
