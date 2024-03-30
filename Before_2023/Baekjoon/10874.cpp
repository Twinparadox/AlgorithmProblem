#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, size;
	bool check;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		check = true;
		for (int tmp, j = 0; j < 10; j++)
		{
			cin >> tmp;
			if (((j % 5) + 1) != tmp)
				check = false;
		}
		if (check)
			arr.push_back(i + 1);
	}
	size = arr.size();
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\n';
}
