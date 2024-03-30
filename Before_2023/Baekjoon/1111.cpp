#include <iostream>
using namespace std;
int main(void)
{
	int arr[50], n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1)
		cout << "A";
	else if (n == 2)
	{
		if (arr[0] == arr[1])
			cout << arr[0];
		else
			cout << "A";
	}
	else
	{
		if (arr[0] == arr[1])
			a = 0;
		else
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		b = arr[1] - arr[0] * a;

		bool check = false;
		for (int i = 2; i < n; i++)
		{
			if ((arr[i - 1] != arr[i - 2]) && (a != (arr[i] - arr[i - 1]) / (arr[i - 1] - arr[i - 2])))
			{
				cout << "B";
				check = true;
				break;
			}
			if (b != arr[i] - arr[i - 1] * a)
			{
				cout << "B";
				check = true;
				break;
			}
		}

		if(!check)
			cout << arr[n - 1] * a + b;
	}
}
