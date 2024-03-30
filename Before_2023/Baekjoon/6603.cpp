#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	while (1)
	{
		cin >> N;
		if (N < 6)
			break;

		vector<int> arr(N);
		vector<int> check;
		vector<vector<int> > ans;
		vector<int> subAns;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		for (int i = 0; i < N - 6; i++)
			check.push_back(0);
		for (int i = 0; i < 6; i++)
			check.push_back(1);

		while (1)
		{
			for (int i = 0; i < N; i++)
				if (check[i])
					subAns.push_back(arr[i]);
			ans.push_back(subAns);
			subAns.clear();
			if (!next_permutation(check.begin(), check.end()))
				break;
		}

		sort(ans.begin(), ans.end());

		int size = ans.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 6; j++)
				cout << ans[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}