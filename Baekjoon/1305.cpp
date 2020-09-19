/*
[P5] - 1305 광고
KMP의 failure function을 활용
http://blog.securekim.com/2018/12/kmp-failure-function.html

failure function에서 구하는 값은
문자열의 1 ~ len까지 항목을 고려한 경우, 접두사와 접미사가 같은 최대 길이
광고판 길이에서 그 최대 길이를 빼면 답이 문제는 그 최대 길이에서 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<int> pi;
int len;
void failure()
{
	pi.resize(len);
	int idx = 0;
	for (int i = 1; i < len; i++)
	{
		while (idx > 0 && str[i] != str[idx])
			idx = pi[idx - 1];
		if (str[i] == str[idx])
			pi[i] = ++idx;
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int ans;

	cin >> len >> str;
	failure();

	ans = len - pi[len - 1];
	cout << ans;
}