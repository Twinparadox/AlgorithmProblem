#include <iostream>
#include <vector>
using namespace std;
int N, M, ans = 0;
vector<vector<int > > board;
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
void calculate(int x, int y)
{
	// ----, l
	// ㅁ
	// ㅗ, ㅜ, ㅓ, ㅏ
	// ㄴ, ㄱ, ㄴr, ㄱr
	// L, 4개
	// 나머지 4개
	int dir[19][4][2] = {
		{{0,0},{0,1},{0,2},{0,3}}, {{0,0},{1,0},{2,0},{3,0}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{1,-1},{2,0}}, {{0,0},{1,0},{1,1},{2,0}}, {{0,0},{0,1},{-1,1},{0,2}}, {{0,0},{0,1},{1,1},{0,2}},
		{{0,0},{0,-1},{1,0},{2,0}}, {{0,0},{1,0},{2,0},{2,1}}, {{0,0},{1,0},{2,0},{2,-1}}, {{0,0},{0,1},{1,0},{2,0}},
		{{0,0},{0,-1},{0,-2},{1,0}}, {{0,0},{1,0},{0,1},{0,2}}, {{0,0},{1,0},{1,-1},{1,-2}}, {{0,0},{1,0},{1,1},{1,2}},
		{{0,0},{0,1},{1,1},{1,2}}, {{0,0},{1,0},{1,-1},{2,-1}}, {{0,0},{0,1},{-1,1},{-1,2}}, {{0,0},{1,0},{1,1},{2,1}}
	};
	for (int i = 0; i < 19; i++)
	{
		int flag = 1, sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dir[i][j][0], ny = y + dir[i][j][1];
			if (!isValid(nx, ny))
			{
				flag = 0;
				break;
			}
			sum += board[ny][nx];
		}
		if (flag)
			ans = ans < sum ? sum : ans;
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	board = vector<vector<int> >(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			calculate(j, i);
	cout << ans;
}