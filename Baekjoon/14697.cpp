#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, n, tmp = 0;
	bool arr[351] = { false, };
	cin >> a >> b >> c >> n;

	for (int i = a; i <= n; i += a)
		arr[i] = true;
	for (int i = b; i <= n; i += b)
		arr[i] = true;
	for (int i = c; i <= n; i += c)
		arr[i] = true;

	if (!arr[n])
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[i])
			{
				for (int la = i + a, lb = i + b, lc = i + c; la <= n;)
				{
					arr[la] = arr[lb] = arr[lc] = true;
					if (la <= n)
						la += a;
					if (lb <= n)
						lb += b;
					if (lc <= n)
						lc += c;
				}
			}
			if (arr[n])
				break;
		}
	}

	if (arr[n])
		cout << 1;
	else
		cout << 0;
}
