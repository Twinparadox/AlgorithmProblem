#include <iostream>
using namespace std;
int main()
{
	int n, c;
	int tmp;
	int win;
	
	cin >> c;
	while (c)
	{
		int* russia = new int[100];
		int* korea = new int[100];

		cin >> n;

		win = 0;
		for (int i = 0; i < n; i++)
			cin >> russia[i];
		for (int i = 0; i < n; i++)
			cin >> korea[i];

		// korea rating 오름차순
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (korea[i] > korea[j])
				{
					tmp = korea[i];
					korea[i] = korea[j];
					korea[j] = tmp;
				}
			}
		}

		// 최적 매치 구하기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 이미 매칭된 선수면 패스
				if (korea[j] == -1)
					continue;
				// rating이 동일한 경우
				if (russia[i] == korea[j])
				{
					win++;
					korea[j] = -1;
					break;
				}
				// rating이 가장 적게 차이나는 경우
				else if (russia[i] < korea[j])
				{
					win++;
					korea[j] = -1;
					break;
				}
			}
		}

		cout << win << endl;
		c--;
		delete[] russia;
		delete[] korea;
	}
	return 0;
}
