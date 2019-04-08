#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, max = 1000000;
	bool flag = true;
	vector<int> arr;
	cin >> N;

	arr.push_back(4);
	arr.push_back(7);
	for (int i = 0; flag; i++)
	{
		if (arr[i] * 10 + 4 <= max)
			arr.push_back(arr[i] * 10 + 4);
		else
			flag = false;
		if (arr[i] * 10 + 7 <= max)
			arr.push_back(arr[i] * 10 + 7);
		else
			flag = false;
	}

	sort(arr.begin(), arr.end());
	int size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] <= N && arr[i + 1] > N)
		{
			cout << arr[i];
			return 0;
		}
	}
	cout << arr[size - 1];
	return 0;
}