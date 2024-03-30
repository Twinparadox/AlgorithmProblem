/*
[G4] 16172 - 나는 친구가 적다(Large)
KMP
https://jason9319.tistory.com/130
failure function과 sliding 과정에 대해 상세히 볼 것
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str, sub;
vector<int> pi;
int len, subLen;
void failure()
{
	pi.resize(subLen);
	int idx = 0;
	for (int i = 1; i < subLen; i++)
	{
		while (idx > 0 && sub[i] != sub[idx])
			idx = pi[idx - 1];
		if (sub[i] == sub[idx])
			pi[i] = ++idx;
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string genuine = "";
	int ans = 0;

	cin >> str >> sub;

	len = str.length();
	subLen = sub.length();

	for (int i = 0; i < len; i++)
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			genuine += str[i];
	str = genuine;
	len = str.length();

	failure();
	int idx = 0;
	for (int i = 0; i < len; i++)
	{
		while (idx > 0 && str[i] != sub[idx])
			idx = pi[idx - 1];

		if (str[i] == sub[idx])
		{
			if (idx == subLen - 1)
			{
				ans = 1;
				idx = pi[idx];
			}
			else
				idx++;
		}
	}

	cout << ans;
}