/*
[G4] 16961 - 부분 문자열
KMP
https://jason9319.tistory.com/130
failure function과 sliding 과정에 대해 상세히 볼 것
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string S, P;
int sLen, pLen;
vector<int> failure;
void setFailure()
{
	failure.resize(pLen, 0);
	int idx = 0;
	for (int i = 1; i < pLen; i++)
	{
		while (idx > 0 && P[i] != P[idx])
			idx = failure[idx - 1];
		if (P[i] == P[idx])
			failure[i] = ++idx;
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int flag = 0;

	cin >> S >> P;
	sLen = S.length();
	pLen = P.length();

	setFailure();

	int idx = 0;
	for (int i = 0; i < sLen; i++)
	{
		while (idx > 0 && S[i] != P[idx])
			idx = failure[idx - 1];
		if (S[i] == P[idx])
		{
			if (idx == pLen - 1)
			{
				flag = 1;
				idx = failure[idx];
			}
			else
				idx++;
		}
	}

	cout << flag;
}