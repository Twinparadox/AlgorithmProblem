#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, len, cnt = 0, idx = 0;
	string str;
	cin >> n >> m;
	cin >> str;

	for (int i = 0; i < m; i++)
	{
		if (str[i] == 'I')
		{
			int size = 0;
			while (str[i + 1] == 'O' && str[i + 2] == 'I')
			{
				size++;
				if (size == n)
					cnt++, size--;
				i += 2;
			}
		}
	}

	cout << cnt;
}