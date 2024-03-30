#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, len1, len2, carry, prevCarry;
	string fib1 = "0", fib2 = "1";

	cin >> n;
	if (n == 0)
		cout << fib1;
	else if (n == 1)
		cout << fib2;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			string nextFib = "";
			prevCarry = carry = 0;
			len1 = fib1.length();
			len2 = fib2.length();
			if (len1 < len2)
			{
				for (int i = 0; i < len2 - len1; i++)
					fib1.insert(fib1.begin(), '0');
				len1 = len2;
			}
			else if (len1 > len2)
			{
				for (int i = 0; i < len1 - len2; i++)
					fib2.insert(fib2.begin(), '0');
			}

			for (int i = len1 - 1; i >= 0; i--)
			{
				int f1 = fib1[i] - '0';
				int f2 = fib2[i] - '0';

				prevCarry = carry;

				if (f1 + f2 + prevCarry >= 10)
				{
					carry = 1;
					nextFib += (f1 + f2 + prevCarry - 10) + '0';
					if (i == 0 && carry)
						nextFib += '1';
				}
				else
				{
					carry = 0;
					nextFib += (f1 + f2 + prevCarry) + '0';
				}
			}
			reverse(nextFib.begin(), nextFib.end());
			fib1 = fib2;
			fib2 = nextFib;
		}
		cout << fib2;
	}
}