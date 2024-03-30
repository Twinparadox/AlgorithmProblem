#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	long long n, b, c, bCnt = 0, cCnt = 0;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		arr[i] -= b, bCnt++;
		if (arr[i] > 0)
		{
			if (arr[i] % c == 0)
				cCnt += arr[i] / c;
			else
				cCnt += (arr[i] / c + 1);
		}
	}
	cout << bCnt + cCnt;
}
