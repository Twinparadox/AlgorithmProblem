#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int t, sum, tmp;
	cin >> t;
	vector<int> arr(t);
	for (int i = 0; i < t; i++)
		cin >> arr[i];

	for (int i = 0; i < t; i++)
	{
		if (arr[i] == 1)
			cout << "Deficient\n";
		else
		{
			sum = 1;
			for (int j = 2; j < arr[i] / 2; j++)
			{
				if (arr[i] % j == 0)
				{
					if (arr[i] / j == j)
						sum += j;
					else if (arr[i] / j > j)
						sum += (arr[i] / j + j);
					else
						break;
				}
			}
			if (sum == arr[i])
				cout << "Perfect\n";
			else if (sum < arr[i])
				cout << "Deficient\n";
			else
				cout << "Abundant\n";
		}
	}
}
