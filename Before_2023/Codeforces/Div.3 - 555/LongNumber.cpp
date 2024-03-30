#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	string str;
	vector<int> arr(10);
	bool flag = true;

	cin >> n;
	cin >> str;
	for (int i = 1; i <= 9; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		int su = str[i] - '0';
		if (flag)
		{
			if (arr[su] > su)
			{
				flag = false;
				str[i] = arr[su] + '0';
			}
		}
		else
		{
			if (arr[su] < su)
				break;
			else
				str[i] = arr[su] + '0';
		}
	}
	cout << str;
}