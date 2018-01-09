#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	int alen, blen;
	long long sum = 0;
	cin >> a >> b;
	alen = a.length(), blen = b.length();
	for (int i = 0; i < alen; i++)
		for (int j = 0; j < blen; j++)
			sum += (int)((char)a[i] - '0')*((char)b[j] - '0');
	cout << sum;
}
