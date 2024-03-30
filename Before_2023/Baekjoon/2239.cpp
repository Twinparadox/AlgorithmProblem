/* [G4] 2239 - 스도쿠 */
/*
2580 스도쿠랑 동일한 문제
그저 숫자 배열로 입력받던 걸, 문자열 배열로 입력받는 차이
백트래킹 문제로, 숫자를 작은 것부터 채워나가는 방식으로 접근하면,
문제에서 말하는 사전식 정렬 조건을 충족할 수 있음
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 9;
bool flag = false;
vector<vector<bool> > checkCol, checkRow, checkMat;
bool isValid(int su, int x, int y)
{
	if (checkCol[x][su] || checkRow[y][su] || checkMat[y / 3 * 3 + x / 3][su])
		return false;
	return true;
}
void Solve(vector<string> &board, int already)
{
	if (flag)
		return;
	if (already == N * N)
	{
		for (int y = 0; y < N; y++)
			cout << board[y] << '\n';
		flag = true;
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int num = board[y][x] - '0';
			if (!num)
			{
				for (int su = 1; su <= N; su++)
				{
					if (isValid(su, x, y))
					{
						board[y][x] = su + '0';
						checkRow[y][su] = checkCol[x][su] = true;
						checkMat[y / 3 * 3 + x / 3][su] = true;
						Solve(board, already + 1);
						board[y][x] = '0';
						checkRow[y][su] = checkCol[x][su] = false;
						checkMat[y / 3 * 3 + x / 3][su] = false;
					}
				}
				return;
			}
		}
	}
}
int main(void)
{
	int already = 0;
	vector<string> board(N);
	checkRow.resize(N, vector<bool>(N + 1, false));
	checkCol.resize(N, vector<bool>(N + 1, false));
	checkMat.resize(N, vector<bool>(N + 1, false));
	for (int y = 0; y < N; y++)
	{
		cin >> board[y];
		for (int x = 0; x < N; x++)
		{
			int idx = board[y][x] - '0';
			checkRow[y][idx] = true;
			checkCol[x][idx] = true;
			checkMat[y / 3 * 3 + x / 3][idx] = true;
			if (idx)
				already++;
		}
	}
	Solve(board, already);
}