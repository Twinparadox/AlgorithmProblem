/*
[G2] 1701 - Cubeitor
KMP의 Failure Function 이용하는 문제
https://jason9319.tistory.com/130
string의 substring에 대한 failure function을 계산하고,
거기서 최댓값을 구하면 됨
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> failure;
void setFailure(string str)
{
	int idx = 0, len = str.length();
	for (int i = 1; i < len; i++)
	{
		while (idx > 0 && str[i] != str[idx])
			idx = failure[idx - 1];
		if (str[i] == str[idx])
			failure[i] = ++idx;
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string str;
	int maxLen = 0, len;

	cin >> str;
	len = str.length();

	for (int i = 0; i < len; i++)
	{
		string sub = str.substr(i, len);
		failure = vector<int>(len - i);
		setFailure(sub);

		for (int j = 0; j < len - i; j++)
			maxLen = max(maxLen, failure[j]);
	}

	cout << maxLen;
}