/* [G5] 3495 - �ƽ�Ű ���� */
/*
�ܼ� ���� ����
�缱�� ���� ������ ������ ���̸� ���ϴ� ������,
�缱�� �ִ� ���� ������ 0.5�� ���̸� ����, �缱�� �ѷ����� ���� 1�� ���̸� ����
�缱���� �ѷ����� ���� �����ϴ� ���� �ش� ���� ������ �缱�� Ȧ����ŭ �־��� ����
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