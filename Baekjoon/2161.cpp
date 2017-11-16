#include <deque>
#include <iostream>
using namespace std;
int main(void)
{
	deque<int> dq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	while(!dq.empty())
	{
		cout << dq.front() << " ";
		dq.pop_front();
		if (dq.empty())
			break;
		dq.push_back(dq.front());
		dq.pop_front();
	}
}
