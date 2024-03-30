#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int k, tmp, sum = 0;
	stack<int> st;
	cin >> k;
	while (k--)
	{
		cin >> tmp;
		if (tmp == 0 && !st.empty())
			st.pop();
		else
			st.push(tmp);
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
}
