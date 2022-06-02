#include <iostream>
using namespace std;

int log2(int number)
{
	int power = 0;
	while (number > 1)
	{
		power += 1;
		number /= 2;
	}
	return power;
}

int main()
{
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cout << log2(a) << '\n';
	}
	return 0;
}
