#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
	int t, arr[16], sum;
	cin >> t;
	while (t--)
	{
		char num[17];
		cin >> num;

		sum = 0;
		for (int i = 0; i < 16; i++)
			arr[i] = num[i] - '0';
		for (int i = 0; i < 16; i++)
		{
			if(i%2==0)
				arr[i] *= 2;
			sum += arr[i] / 10 + arr[i] % 10;
		}
		if (sum % 10 == 0)
			cout << "T\n";
		else
			cout << "F\n";
	}
}
