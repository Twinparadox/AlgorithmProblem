#include <iostream>
using namespace std;
int arr[100001] = { 0, }, n, m, a, b;
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a]++, arr[b] ++;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << '\n';
}
