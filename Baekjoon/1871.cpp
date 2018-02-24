#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	int n, a, b;
	string arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		a = 0;
		for (int j = 0; j <= 2; j++)
			a += (int)((char)arr[i][j] - 'A')*pow(26, 2 - j);
		b=stoi(arr[i].substr(4, 4));
		if (abs(a - b) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
}
