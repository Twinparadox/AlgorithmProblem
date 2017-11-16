#include <iostream>
using namespace std;
int main(void)
{
	int n, plus[101] = { 0, }, minus[101] = { 0, }, tmp, v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp >= 0)
			plus[tmp]++;
		else
			minus[-tmp]++;
	}
	cin >> v;
	if (v >= 0)
		cout << plus[v];
	else
		cout << minus[-v];
}
