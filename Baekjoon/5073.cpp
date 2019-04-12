#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int size = 3;
	vector<int> arr(size);
	while (1)
	{
		for (int i = 0; i < size; i++)
			cin >> arr[i];

		if (!(arr[0] || arr[1] || arr[2]))
			break;

		sort(arr.begin(), arr.end());
		if (arr[2] >= (arr[0] + arr[1]))
			cout << "Invalid\n";
		else
		{
			if (arr[0] == arr[1])
			{
				if (arr[0] == arr[2])
					cout << "Equilateral\n";
				else
					cout << "Isosceles\n";
			}
			else if (arr[1] == arr[2])
			{
				if (arr[0] == arr[1])
					cout << "Equilateral\n";
				else
					cout << "Isosceles\n";
			}
			else
				cout << "Scalene\n";
		}
	}
}