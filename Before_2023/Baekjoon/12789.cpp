#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	int n, cur = 1, idx = 0;
	int arr[1000], ans[1000];
	stack<int> st;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++)
	{
		if (cur != arr[i] && (st.empty() || (!st.empty() && cur != st.top())))
			st.push(arr[i]);
		else
		{
			if (cur == arr[i])
				cur++;
			while (!st.empty() && st.top() == cur)
			{
				st.pop();
				cur++;
			}
		}
	}

	if (cur - 1 == n)
	{
		cout << "Nice";
	}
	else
	{
		if (st.empty())
			cout << "Sad";
		else if (st.top() != cur)
			cout << "Sad";
		else
		{
			int size = st.size();
			bool sad = false;
			for (int i = 0; i < size; i++)
			{
				if (st.empty() || st.top() != cur)
				{
					sad = true;
					cout << "Sad";
					break;
				}
				else
					st.pop(), cur++;
			}
			if(!sad)
				cout << "Nice";
		}
	}
}
