#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M;
vector<vector<int> > board;
vector<vector<int> > dp;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> N >> M;
	board.resize(N + 1, vector<int>(M + 1));
	dp.resize(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		for (int j = 1; j <= M; j++)
			board[i][j] = str[j - 1] - '0';
	}

	int maxLen = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j])
			{
				int tmp = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
				dp[i][j] = dp[i - 1][j - 1] < tmp ? dp[i - 1][j - 1] : tmp;
				dp[i][j] += 1;
				maxLen = dp[i][j] < maxLen ? maxLen : dp[i][j];
			}
		}
	}

	cout << maxLen * maxLen;
}