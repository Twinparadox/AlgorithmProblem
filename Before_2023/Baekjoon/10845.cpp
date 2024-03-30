#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	queue<int> q;
	cin >> n;
	while (n)
	{
		string op;
		cin >> op;
		if (op == "push")
		{
			int tmp;
			cin >> tmp;
			q.push(tmp);
		}
		else if (op == "front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (op == "back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
		else if (op == "size")
		{
			cout << q.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (op == "pop")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		n--;
	}
	return 0;
}
