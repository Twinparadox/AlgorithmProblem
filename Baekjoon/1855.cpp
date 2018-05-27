#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int k, len;
	string crypt;
	char arr[200][200];
	cin >> k >> crypt;
	len = crypt.length();
	for (int i = 0; i < len/k; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < k; j++)
				arr[i][j] = crypt[i*k + j];
		else
			for (int j = k - 1; j >= 0; j--)
				arr[i][k-1-j] = crypt[i*k + j];
	}
	for (int i = 0; i < k; i++)
		for (int j = 0; j < len / k; j++)
			cout << arr[j][i];
}
