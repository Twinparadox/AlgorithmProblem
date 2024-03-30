#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	cin >> t;
	while (t--)
	{
		int min = 100, max = -1, tmp;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (min > tmp)
				min = tmp;
			if (max < tmp)
				max = tmp;
		}
		cout << (max - min) * 2 << '\n';
	}
}
