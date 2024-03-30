/* [G5] 3495 - 아스키 도형 */
/*
단순 구현 문제
사선을 통해 형성된 도형의 넓이를 구하는 문제로,
사선이 있는 곳은 무조건 0.5의 넓이를 갖고, 사선에 둘러싸인 곳은 1의 넓이를 갖음
사선으로 둘러싸인 것을 판정하는 것은 해당 지점 이전에 사선이 홀수만큼 있었을 때임
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	vector<string> board;
	int H, W;
	double area = 0;

	cin >> H >> W;

	board.resize(H);

	for (int i = 0; i < H; i++)
	{
		cin >> board[i];
		int cur = 0;
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == '/' || board[i][j] == '\\')
			{
				cur++;
				area += 0.5;
			}
			else
			{
				if (cur % 2 == 1)
					area += 1;
			}
		}
	}
	cout << area;
}