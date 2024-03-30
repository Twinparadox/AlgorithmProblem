#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, max = -1, len, ans[3] = { 0, }, meta[3][6] = { {0,1,2},{1,0,1,2},{2,2,0,0,1,1,} };
	string str;
	cin >> n;
	cin >> str;
	len = str.length();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == 0 && str[j] == (char)(65 + meta[i][j % 3]))
				ans[i]++;
			else if (i == 1 && str[j] == (char)(65 + meta[i][j % 4]))
				ans[i]++;
			else if (i == 2 && str[j] == (char)(65 + meta[i][j % 6]))
				ans[i]++;

		}
	}

	for (int i = 0; i < 3; i++)
		if (max < ans[i])
			max = ans[i];

	cout << max << '\n';
	for (int i = 0; i < 3; i++)
	{
		if (ans[i] == max)
		{
			switch (i)
			{
			case 0:
				cout << "Adrian\n";
				break;
			case 1:
				cout << "Bruno\n";
				break;
			case 2:
				cout << "Goran\n";
				break;
			default:
				break;
			}
		}
	}
}
