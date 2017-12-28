#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, len, dist;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		len = a.length(), dist = 0;
		for (int i = 0; i < len; i++)
			if (a[i] != b[i])
				dist++;
		cout << "Hamming distance is " << dist << ".\n";
	}
}
