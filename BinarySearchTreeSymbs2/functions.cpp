#include "functions.h"
using namespace std;

string deleteRecurringSymbs(string str)
{
	int i = 0, k, m;
	while (i < str.size()) {
		k = i;
		char curr = str[i];
		m = str.find(curr, k + 1);
		if (m != string::npos) {
			str = str.substr(0, k) + str.substr(k + 1, str.size() - k - 1);
			m--;
			while (m != string::npos) {
				str = str.substr(0, m) + str.substr(m + 1, str.size() - m - 1);
				m = str.find(curr);
			}
		}
		else {
			i++;
		}
	}
	return str;
}
