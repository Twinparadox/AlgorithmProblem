#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int n, tmp, sub1, sub2, size;
	vector<int> arr;
	bool check = false;
	cin >> n;
	tmp = n;
	while (tmp > 0)
	{
		arr.push_back(tmp % 10);
		tmp /= 10;
	}
	size = arr.size();
	if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			sub1 = sub2 = 1;
			for (int j = 0; j <= i; j++)
				sub1 *= arr[j];
			for (int j = i + 1; j < size; j++)
				sub2 *= arr[j];
			if (sub1 == sub2)
			{
				check = true;
				break;
			}
		}
	}
	if (check)
		cout << "YES";
	else
		cout << "NO";
}
