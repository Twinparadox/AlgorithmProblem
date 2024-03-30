#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	int t, len, size;
	char arr[100][100];
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		len = s.length();
		size = sqrt(len);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				arr[i][j] = (char)s[size*i + j];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cout << arr[j][size - i - 1];
		cout << '\n';
	}
}
