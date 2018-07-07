#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	int alen, blen, aIdx = -1, bIdx = -1;
	cin >> a >> b;
	alen = a.length();
	blen = b.length();
	for (int i = 0; i < alen && aIdx==-1; i++)
	{
		for (int j = 0; j < blen; j++)
		{
			if (a[i] == b[j])
			{
				aIdx = i, bIdx = j;
				break;
			}
		}
	}

	for (int i = 0; i < blen; i++)
	{
		if (i == bIdx)
		{
			cout << a;
		}
		else
		{
			for (int j = 0; j < alen; j++)
			{
				if (j == aIdx)
					cout << b[i];
				else
					cout << '.';
			}
		}
		cout << endl;
	}
}
