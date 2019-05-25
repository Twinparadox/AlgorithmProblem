#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, alen, blen;
	string arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			alen = arr[i].length();
			blen = arr[j].length();
			if (alen != blen)
				continue;
			else
			{
				bool check = true;
				for (int k = 0; k < alen; k++)
				{
					if (arr[i][k] != arr[j][alen - 1 - k])
					{
						check = false;
						break;
					}
				}
				if (check)
				{
					cout << alen << ' ' << arr[i][alen / 2];
					return 0;
				}
			}
		}
	}
}