#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, t = 1;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		cin.ignore();
		string *arr = new string[n];
		for (int i = 0; i < n; i++)
			getline(cin, arr[i]);
		sort(arr, arr + n);
		cout << t << '\n';
		for (int i = 0; i < n; i++)
			cout << arr[i] << '\n';
		t++;
	}
}
