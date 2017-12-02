#include <iostream>
using namespace std;
int main(void)
{
	int k, p, m, cnt = 0;;
	cin >> k;
	while (k--)
	{
		cin >> p >> m;
		bool check[500] = { false, };
		cnt = 0;
		for (int i = 0, s; i < p; i++)
		{
			cin >> s;
			if (check[s - 1])
				cnt++;
			else
				check[s - 1] = true;
		}
		cout << cnt << '\n';
	}
}
