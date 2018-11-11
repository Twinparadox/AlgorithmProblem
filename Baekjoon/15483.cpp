#include <iostream>
#include <string>
using namespace std;
int MinValue(int a, int b, int c)
{
	int min;
	if (a < b)
		min = a;
	else
		min = b;
	if (min < c)
		return min;
	else
		return c;
}
int DP(string A, string B)
{
	int aLen = A.size();
	int bLen = B.size();
	int** E;
	char *aChar, *bChar;
	aChar = (char*)A.c_str();
	bChar = (char*)B.c_str();
	E = new int*[aLen + 1];
	for (int i = 0; i <= aLen; i++)
	{
		E[i] = new int[bLen + 1];
	}
	for (int i = 0; i <= aLen; i++)
	{
		E[i][0] = i;
	}
	for (int i = 0; i <= bLen; i++)
	{
		E[0][i] = i;
	}
	for (int i = 1; i <= aLen; i++)
	{
		for (int j = 1; j <= bLen; j++)
		{
			if (aChar[i - 1] == bChar[j - 1])
				E[i][j] = E[i - 1][j - 1];
			else
				E[i][j] = 1 + MinValue(E[i - 1][j], E[i][j - 1], E[i - 1][j - 1]);
		}
	}
	return E[aLen][bLen];
}
int main(void)
{
	string A, B;
	cin >> A >> B;
	cout << DP(A, B);
}