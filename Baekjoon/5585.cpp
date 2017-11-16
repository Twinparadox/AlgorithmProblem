#include <iostream>
using namespace std;
int main(void)
{
	int sum = 0, idx = 0, money, arr[6] = { 500,100,50,10,5,1 };
	cin >> money;
	money = 1000 - money;
	while (money > 0)
	{
		if (money >= arr[idx])
		{
			sum += money / arr[idx];
			money -= (money / arr[idx])*arr[idx];
		}
		else
			idx++;
	}
	cout << sum;
}
