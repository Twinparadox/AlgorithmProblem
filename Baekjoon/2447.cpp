#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> ans;
void recursive(int size, int x, int y)
{
	if (size == 1)
	{
		ans[x][y] = '*';
		return;
	}
	else
	{
		int subSize = size / 3;
		for (int i = x; i < x + size; i += subSize)
		{
			for (int j = y; j < y + size; j += subSize)
			{
				if (i == x + subSize && j == y + subSize)
					continue;
				recursive(subSize, i, j);
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	ans = vector<string>(N, string(N, ' '));

	recursive(N, 0, 0);
	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';
}