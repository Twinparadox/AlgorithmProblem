#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	string *l;
	int n, m, size;
	cin >> n >> m;
	l = new string[n + m];
	size = 0;
	for (int i = 0; i < n + m; i++)
		cin >> l[i];
	sort(l, l + n + m);
	for (int i = 1; i < n + m; i++)
		if (l[i] == l[i - 1])
			size++;
	cout << size << "\n";
	for (int i = 1; i < n + m; i++)
		if (l[i] == l[i - 1])
			cout << l[i] << "\n";
}
