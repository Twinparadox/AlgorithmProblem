#include <iostream>
#include <math.h>
#include <string>
using namespace std;
bool sosu(int n)
{
	int cnt = 0;
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	else
		for (int i = 5; i <= sqrt(n); i += 6)
			if (n%i == 0 || n % (i + 2) == 0)
				return false;
	return true;
}
int main(void)
{
	int N;
	cin >> N;
	for (int i = N; ; i++)
	{
		string str = to_string(i);
		int len = str.length();
		bool flag = true;
		for (int j = 0; j < len / 2; j++)
		{
			if (str[j] != str[len - 1 - j])
			{
				flag = false;
				break;
			}
		}

		if (flag && sosu(i))
		{
			cout << i;
			break;
		}
	}
}