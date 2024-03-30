#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, sum, len;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string s;
		getline(cin, s);
		len = s.length(), sum = 0;
		for (int i = 0; i < len; i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
				sum += (int)((char)s[i] - 'A' + 1);

		if (sum == 100)
			cout << "PERFECT LIFE\n";
		else
			cout << sum << '\n';
	}
}
