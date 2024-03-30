#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
	int N, K;
	string str;
	stack<int> st;
	deque<int> dq;

	cin >> N >> K;
	cin >> str;

	for (int i = 0; i < N; i++)
	{
		int su = str[i] - '0';
		while (!dq.empty() && K > 0 && su > dq.back())
		{
			dq.pop_back();
			K--;
		}
		dq.push_back(su);
	}

	int size = dq.size();
	str = "";

	for (int i = 0; i < size - K; i++)
	{
		cout << dq.front();
		dq.pop_front();
	}
}