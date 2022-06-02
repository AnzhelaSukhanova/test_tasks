#include <iostream>
using namespace std;

void reverse_print(int n)
{
	int next;
	cin >> next;
	if (next != 0)
		reverse_print(next);
	cout << n << ' ';
}

int main()
{
	int n;
	cin >> n;
	reverse_print(n);
	return 0;
}
