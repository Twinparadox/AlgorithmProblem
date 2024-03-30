#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long ans = 0;
void merge(vector<int>& arr, vector<int>& left, vector<int>& right)
{
	arr.clear();

	vector<int>::iterator itLeft = left.begin();
	vector<int>::iterator itRight = right.begin();

	while (itLeft != left.end() || itRight != right.end())
	{
		if (itLeft != left.end() && itRight != right.end())
		{
			if (*itLeft <= *itRight)
			{
				arr.push_back(*itLeft++);
			}
			else
			{
				arr.push_back(*itRight++);
				ans += left.end() - itLeft;
			}
		}
		else
		{
			if (itLeft != left.end())
			{
				arr.push_back(*itLeft++);
			}
			else
			{
				arr.push_back(*itRight++);
			}
		}
	}
}
void sorting(vector<int>& arr)
{
	if (arr.size() > 1)
	{
		int size = arr.size() / 2;

		vector<int> left(arr.begin(), arr.begin() + size);
		sorting(left);

		vector<int> right(arr.begin() + size, arr.end());
		sorting(right);

		merge(arr, left, right);
	}
}
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> smaller(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sorting(arr);
	cout << ans;
}