#include <iostream>
using namespace std;
int main(void)
{
	int sum, tmp;
	cin >> sum;
	for (int i = 0; i < 9; i++)
	{
		cin >> tmp;
		sum -= tmp;
	}
	cout << sum;
	return 0;
}
