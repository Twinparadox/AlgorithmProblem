#include <iostream>
using namespace std;
int main()
{
	int n;
	int arr[50];
	long long int fibo1 = 0, fibo2 = 1, tmp;
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 피보나치
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			tmp = fibo1 + fibo2;
			fibo1 = fibo2;
			fibo2 = tmp;
			if (fibo1 > 1000000007)
				fibo1 %= 1000000007;
			if (fibo2 > 1000000007)
				fibo2 %= 1000000007;
		}
		cout << fibo2 << endl;
		fibo1 = 0;
		fibo2 = 1;
	}
	return 0;
}
