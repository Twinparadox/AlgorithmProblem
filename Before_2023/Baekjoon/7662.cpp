#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T, Q, n;
	char op;
	cin >> T;
	while (T--)
	{
		multiset<int, greater<int> > ms;
		cin >> Q;
		while (Q--)
		{
			cin >> op >> n;
			if (op == 'I')
				ms.insert(n);
			else
			{
				if (ms.empty())
					continue;
				else
				{
					if (n == 1)
						ms.erase(ms.begin());
					else
						ms.erase(--ms.end());
				}
			}
		}
		if (ms.empty())
			cout << "EMPTY";
		else
			cout << *ms.begin() << ' ' << *ms.rbegin();

		cout << '\n';
	}
}