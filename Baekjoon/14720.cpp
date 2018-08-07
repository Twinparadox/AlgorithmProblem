#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, cnt, state, start = -1;
	bool check = false;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0 && !check)
			check = true, start = i;
	}
	
	if (!check)
		cout << 0;
	else {
		state = 0, cnt = 1;
		for (int i = start+1; i < n; i++)
		{
			int tmp = (state + 1) % 3;
			if (tmp == arr[i])
				state++, cnt++;
		}
		cout << cnt;
	}
}
