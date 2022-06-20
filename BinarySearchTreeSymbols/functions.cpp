#include "functions.h"
using namespace std;

string deleteRecurringSymbs(string symbs)
{
	int i = 0, k, m;
	while (i < symbs.size()) {
		k = i;
		char curr = symbs[i];
		m = symbs.find(curr, k + 1);
		if (m != string::npos) {
			symbs = symbs.substr(0, k) + symbs.substr(k + 1, symbs.size() - k - 1);
			m--;
			while (m != string::npos) {
				symbs = symbs.substr(0, m) + symbs.substr(m + 1, symbs.size() - m - 1);
				m = symbs.find(curr, m + 1);
			}
		}
		else i++;
	}
	return symbs;
}
