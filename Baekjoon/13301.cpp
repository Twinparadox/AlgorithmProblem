#include <iostream>
using namespace std;
int main(void)
{
	long long arr[82] = { 0,1, }, length = 0;
	int n;
	cin >> n;
	for (int i = 2; i <= n+1; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	length = arr[n + 1] * 2 + arr[n] * 2;
	cout << length;
}
