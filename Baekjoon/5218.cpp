#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		string s1, s2;
		cin >> s1 >> s2;
		cout << "Distances: ";
		size = s1.length();
		for (int i = 0; i < size; i++)
		{
			if ((int)s2[i] - (int)s1[i] >= 0)
				cout << (int)s2[i] - (int)s1[i] << ' ';
			else
				cout << (int)s2[i] - (int)s1[i] + 26 << ' ';
		}
		cout << '\n';
	}
}
