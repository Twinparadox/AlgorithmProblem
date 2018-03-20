#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int m, n, blind[5] = { 0, };
	vector<string> arr;
	cin >> n >> m;
	for (int i = 1; i <= 5 * n + 1; i++)
	{
		string tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 1; i < 5 * n + 1; i += 5)
	{
		for (int j = 1; j < 5 * m + 1; j += 5)
		{
			int type = 0;
			for (type = 0; type < 4; type++)
				if ((char)arr[i + type][j] != '*')
					break;
			blind[type]++;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << blind[i] << ' ';
}
