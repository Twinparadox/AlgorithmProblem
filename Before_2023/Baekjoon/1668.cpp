#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	int n, arr[50];
	stack<int> sl, sr;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sl.push(arr[0]);
	for (int i = 1; i < n; i++)
		if (arr[i] > sl.top())
			sl.push(arr[i]);
	sr.push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--)
		if (arr[i] > sr.top())
			sr.push(arr[i]);

	cout << sl.size() << ' ' << sr.size();
}
