#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string S, K, sub = "";
	int len = 0;
	cin >> S >> K;

	len = S.length();
	for (int i = 0; i < len; i++)
		if (S[i]<'0' || S[i]>'9')
			sub += S[i];

	int idx = sub.find(K);
	if (idx == -1)
		cout << 0;
	else
		cout << 1;
}