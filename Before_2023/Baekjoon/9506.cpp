#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void)
{
	int n, sum = 0;
	while (1)
	{
		cin >> n;
		if (n == -1)
			break;
		sum = 1;
		vector<int> arr;
		arr.push_back(1);
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				arr.push_back(i), sum += i;
			if (sum > n)
				break;
		}
		if (sum == n)
		{
			int size = arr.size();
			cout << n << " = ";
			sort(arr.begin(), arr.end());
			for (int i = 0; i < size - 1; i++)
				cout << arr[i] << " + ";
			cout << arr[size - 1];
		}
		else
		{
			cout << n << " is NOT perfect.";
		}
		cout << '\n';
	}
}
