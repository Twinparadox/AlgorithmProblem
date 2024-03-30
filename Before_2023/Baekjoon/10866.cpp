#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	deque<int> dq;
	string op;
	int n, k;
	cin >> n;
	while (n--)
	{
		cin >> op;
		if (op == "push_back")
		{
			cin >> k;
			dq.push_back(k);
		}
		else if (op == "push_front")
		{
			cin >> k;
			dq.push_front(k);
		}
		else if (op == "pop_front")
		{
			if (dq.size())
				cout << dq.front() << "\n", dq.pop_front();
			else
				cout << -1 << "\n";
		}
		else if (op == "pop_back")
		{
			if (dq.size())
				cout << dq.back() << "\n", dq.pop_back();
			else
				cout << -1 << "\n";
		}
		else if (op == "size")
			cout << dq.size() << "\n";
		else if (op == "empty")
		{
			if (dq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (op == "front")
		{
			if (dq.size())
				cout << dq.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (op == "back")
		{
			if (dq.size())
				cout << dq.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}
