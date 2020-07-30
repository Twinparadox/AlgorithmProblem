/* [G4] 17142 - ������ 3 */
/*
BFS ����
���̷����� �� ĭ, ���� ���� ������ ó���� �ʿ��ϸ�,
������ ������, ���̷��� Ȱ��ȭ �ܰ��� ������ ���� �ξ� ó���ϴ� ���� ����
Ȱ��ȭ��ų ���̷����� �����ϴ� Combination ������ �ʿ�
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dir[4][2] =
{
	{1,0}, {-1, 0}, {0, 1}, {0, -1}
};
int N, M, ans = -1, emptySize = 0;
vector<vector<int> > originBoard;
vector<pair<int, int > > virus;
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
int bfs(vector<int> select)
{
	queue<pair<int, int > > q;
	vector<vector<int> > curBoard(N, vector<int>(N, 0));
	int size = select.size(), cnt = 0, cy, cx;
	for (int i = 0; i < size; i++)
	{
		q.push(make_pair(virus[select[i]].first, virus[select[i]].second));
		curBoard[virus[select[i]].first][virus[select[i]].second] = 1;
	}
	while (!q.empty())
	{
		cy = q.front().first, cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (isValid(nx, ny) && originBoard[ny][nx] != 1 && !curBoard[ny][nx])
			{
				if (originBoard[ny][nx] == 0)
					cnt++;
				curBoard[ny][nx] = curBoard[cy][cx] + 1;
				if (cnt == emptySize)
					return curBoard[ny][nx] - 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	if (cnt == emptySize)
		return curBoard[cy][cx] - 1;
	else
		return -1;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	originBoard.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> originBoard[i][j];
			if (originBoard[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (!originBoard[i][j])
				emptySize++;
		}
	}

	if (!emptySize)
		ans = 0;
	else
	{
		int size = virus.size();
		vector<int> ind(size, 0);
		for (int i = size - M; i < size; i++)
			ind[i] = 1;

		while (1)
		{
			vector<int> select;
			for (int i = 0; i < size; i++)
			{
				if (ind[i])
					select.push_back(i);
			}
			int sub = bfs(select);
			if (sub > -1)
			{
				if (ans < 0)
					ans = sub;
				else
					ans = min(ans, sub);
			}

			if (!next_permutation(ind.begin(), ind.end()))
				break;
		}
	}
	cout << ans;
}