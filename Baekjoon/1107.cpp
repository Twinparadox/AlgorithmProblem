#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<bool> broken(10, false);
int main(void)
{
	int N, M, cur = 100, ans, maxCh = 1000000;
	cin >> N >> M;

	for (int i = 0, tmp; i < M; i++)
	{
		cin >> tmp;
		broken[tmp] = true;
	}

	ans = abs(N - cur);

	for (int ch = 0; ch <= maxCh; ch++)
	{
		int len = 0, tmp = ch;
		bool flag = false;
		while (1)
		{
			if (broken[tmp % 10])
				break;
			else
			{
				tmp /= 10;
				len++;
				if (tmp == 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
		{
			int result = abs(N - ch);
			if (result + len < ans)
				ans = result + len;
		}
	}
	cout << ans;
}