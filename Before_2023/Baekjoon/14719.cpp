#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W;
	vector<int> board;
	vector<int> lDepth, rDepth;

	cin >> H >> W;
	board.resize(W);
	lDepth.resize(W);
	rDepth.resize(W);
	for (int i = 0; i < W; i++)
		cin >> board[i];

	int prev = board[0];
	lDepth[0] = prev;
	for (int i = 1; i < W; i++)
	{
		if (prev <= board[i])
			prev = board[i];
		lDepth[i] = prev;
	}

	int next = board[W - 1];
	rDepth[W - 1] = next;
	for (int i = W - 2; i >= 0; i--)
	{
		if (next <= board[i])
			next = board[i];
		rDepth[i] = next;
	}

	int ans = 0;
	for (int i = 0; i < W; i++)
	{
		int minH = lDepth[i] < rDepth[i] ? lDepth[i] : rDepth[i];
		ans += minH - board[i];
	}
	cout << ans;
}