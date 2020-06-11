/* [G4] 2580 - 스도쿠 */
/*
DFS와 백트래킹(Back-Tracking)을 활용해야 함
https://www.geeksforgeeks.org/sudoku-backtracking-7/
좋은 예제가 존재하긴 하지만, 위 풀이 방법으로는 TLE를 통과할 수 없음

1. 수를 채울 수 있는 경우와 아닌 경우를 계속 판별하기 보다, 별도의 변수에 저장해놓기
2. 복사 생성자 문제 해결하기

*/


#include <iostream>
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
void Solve(vector<vector<int> > &board, int already)
{
	if (flag)
		return;
	if (already == N * N)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
				cout << board[y][x] << ' ';
			cout << '\n';
		}
		flag = true;
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!board[y][x])
			{
				for (int su = 1; su <= N; su++)
				{
					if (isValid(su, x, y))
					{
						board[y][x] = su;
						checkRow[y][su] = checkCol[x][su] = true;
						checkMat[y / 3 * 3 + x / 3][su] = true;
						Solve(board, already + 1);
						board[y][x] = 0;
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
	vector<vector<int> > board(N, vector<int>(N));
	checkRow.resize(N, vector<bool>(N + 1, false));
	checkCol.resize(N, vector<bool>(N + 1, false));
	checkMat.resize(N, vector<bool>(N + 1, false));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
			checkRow[y][board[y][x]] = true;
			checkCol[x][board[y][x]] = true;
			checkMat[y / 3 * 3 + x / 3][board[y][x]] = true;
			if (board[y][x])
				already++;
		}
	}
	Solve(board, already);
}