#include <iostream>
using namespace std;

int main()
{
	char c = '\0';
	char last_c = c;
	while (cin.get(c)) {
		if (c == last_c && c == ' ')
			continue;
		cout << c;
		last_c = c;
	}
	return 0;
}
