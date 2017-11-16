#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main(void)
{
	int n, a[50], b[50], sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	cout << sum;
}
