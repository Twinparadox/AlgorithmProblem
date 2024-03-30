#include <iostream>
using namespace std;
int main(void)
{
	int N, K, half;
	cin >> N >> K;
	half = N / 2;
	while (K--)
	{
		int a, b, color;
		cin >> a >> b;
		if (b <= half)
		{
			int start = b, end = N + 1 - b;
			if (a >= start && a <= end)
			{
				color = b % 3;
			}
			else
			{
				if (a <= half)
				{
					color = a % 3;
				}
				else
				{
					color = (N + 1 - a) % 3;
				}
			}
		}
		else
		{
			int start = N + 1 - b, end = b;
			if (a >= start && a <= end)
			{
				color = (N + 1 - b) % 3;
			}
			else
			{
				if (a <= half)
				{
					color = a % 3;
				}
				else
				{
					color = (N + 1 - a) % 3;
				}
			}
		}

		if (color == 0)
		{
			cout << 3;
		}
		else
		{
			cout << color;
		}
		cout << '\n';
	}
}