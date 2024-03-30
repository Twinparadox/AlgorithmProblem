#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int n, len;
	char s[51], c;
	cin >> n >> s;
	len = strlen(s);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cin >> c;
			s[j] = s[j] - c ? '?' : c;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << s[i];
	}
	return 0;
}
