#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct bf
{
	int y;
	int x;
	int hCnt;
	int allCnt;
};
int monkey[4][2] =
{
	{1,0},{0,1},{-1,0},{0,-1}
};
int horse[8][2] =
{
	{2, 1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}
};
int K, W, H, ans;
vector<vector<int> > board;
vector<vector<vector<int> > > visit;
bool isValid(int y, int x)
{
	return y >= 0 && y < H && x >= 0 && x < W;
}
void bfs(int y, int x)
{
	queue<struct bf> q;
	q.push({ y,x,0,0 });
	visit[0][y][x] = 0;
	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x;
		int hCnt = q.front().hCnt, allCnt = q.front().allCnt;
		q.pop();
		if (cy == H - 1 && cx == W - 1)
		{
			ans = ans < allCnt ? ans : allCnt;
			continue;
		}
		if (hCnt < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int dy = cy + horse[i][0], dx = cx + horse[i][1];
				if (isValid(dy, dx) && !board[dy][dx] && (!visit[hCnt + 1][dy][dx] || visit[hCnt + 1][dy][dx] > allCnt + 1))
				{
					q.push({ dy,dx,hCnt + 1,allCnt + 1 });
					visit[hCnt + 1][dy][dx] = allCnt + 1;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int dy = cy + monkey[i][0], dx = cx + monkey[i][1];
			if (isValid(dy, dx) && !board[dy][dx] && (!visit[hCnt][dy][dx] || visit[hCnt][dy][dx] > allCnt + 1))
			{
				q.push({ dy,dx,hCnt,allCnt + 1 });
				visit[hCnt][dy][dx] = allCnt + 1;
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> K >> W >> H;
	board = vector<vector<int> >(H, vector<int>(W, 0));
	visit = vector<vector<vector<int> > >(K + 1, vector<vector<int> >(H, vector<int>(W, 0)));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> board[i][j];

	ans = W * H + 1;
	bfs(0, 0);
	if (ans == W * H + 1)
		cout << -1;
	else
		cout << ans;
}