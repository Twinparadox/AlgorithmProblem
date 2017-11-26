#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char arr[25];
		int sum = 0;
		cin >> arr;
		for (int j = 0; j < 24; j++)
			if (arr[j] == '1')
				sum += (int)pow(2, 23 - j);
		cout << sum << '\n';
	}
}
