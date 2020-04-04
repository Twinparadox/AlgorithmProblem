#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T;

	cin >> T;
	while (T--)
	{
		int K, N, sum = 0, ans;
		vector<vector<int> > cls(4);
		vector<vector<int> > twoCls(2);

		cin >> K >> N;
		for (int i = 0; i < 4; i++)
			cls[i].resize(N);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < N; j++)
				cin >> cls[i][j];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				twoCls[0].push_back(cls[0][i] + cls[1][j]);
				twoCls[1].push_back(cls[2][i] + cls[3][j]);
			}
		}

		sort(twoCls[0].begin(), twoCls[0].end());
		sort(twoCls[1].begin(), twoCls[1].end());

		int size1 = twoCls[0].size();
		int size2 = twoCls[1].size();
		int upper, lower;

		ans = twoCls[0][0] + twoCls[1][0];
		for (int i = 0; i < size1; i++)
		{
			int diff = abs(K - twoCls[0][i]);
			upper = lower_bound(twoCls[1].begin(), twoCls[1].end(), diff) - twoCls[1].begin();
			lower = upper - 1;

			if (0 <= upper && upper < size2)
			{
				sum = twoCls[0][i] + twoCls[1][upper];
				int tmp1 = abs(sum - K);
				int tmp2 = abs(ans - K);
				if (tmp1 < tmp2)
					ans = sum;
				else if (tmp1 == tmp2)
					ans = min(ans, sum);
			}
			if (0 <= lower && lower < size2)
			{
				sum = twoCls[0][i] + twoCls[1][lower];
				int tmp1 = abs(sum - K);
				int tmp2 = abs(ans - K);
				if (tmp1 < tmp2)
					ans = sum;
				else if (tmp1 == tmp2)
					ans = min(ans, sum);
			}
		}

		cout << ans << '\n';
	}
}