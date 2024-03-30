#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(void)
{
	int n, tmp;
	long long sum = 0;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - i <= 0)
			break;
		sum += (arr[i] - i);
	}
	cout << sum;
}
