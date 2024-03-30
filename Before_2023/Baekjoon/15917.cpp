#include <iostream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q, n;
	cin >> q;
	while (q--)
	{
		cin >> n;
		if ((n&(-n)) == n)
			cout << "1\n";
		else
			cout << "0\n";
	}
}
