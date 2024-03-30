#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	int arr[20], a, b;
	stack<int> st;
	for (int i = 0; i < 20; i++)
		arr[i] = i + 1;

	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		for (int j = a - 1; j < b; j++)
			st.push(arr[j]);
		for (int j = a - 1; j < b; j++)
			arr[j] = st.top(), st.pop();
	}
	for (int i = 0; i < 20; i++)
		cout << arr[i] << " ";
}
