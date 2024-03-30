/*
이것이 코테다
그리디 - 1이 될때까지
어떤 수가 K로 나누어 떨어지지 않으면 나누어 떨어질 때까지 뺄셈
나누어 떨어지면 나누기
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, K, cnt = 0;
	cin >> N >> K;

	while (N > 1)
	{
		if (N % K)
		{
			int sub = N % K;
			N -= sub;
			cnt += sub;
		}
		else
			N /= K, cnt++;
	}
	cout << cnt;
}