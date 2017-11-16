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
	while(dq.size()>1)
	{
		dq.pop_front();
		if (dq.size()==1)
			break;
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << dq.front();
}
