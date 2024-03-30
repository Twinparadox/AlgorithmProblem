#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	int len;
	string tmp;
	while (cin >> tmp)
	{
		len = tmp.length();
		for (int i = 0; i < len; i += 2)
		{
			int sum = 0;
			char a, b;
			a = (char)tmp[i], b = (char)tmp[i + 1];
			if (a >= 'A')
				sum += pow(16, 1)*(a - 'A' + 10);
			else
				sum += pow(16, 1)*(a - '0');
			if (b >= 'A')
				sum += (b - 'A' + 10);
			else
				sum += (b - '0');
			cout << (char)sum;
		}
		cout << '\n';
	}
}

