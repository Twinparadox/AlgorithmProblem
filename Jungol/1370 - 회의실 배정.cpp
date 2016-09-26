#include <iostream>
using namespace std;

#define MAXMEET 500

typedef struct
{
	int num;
	int start;
	int end;
} Meeting;


int main()
{
	int n;
	Meeting meet[MAXMEET], tmp;
	int result[MAXMEET];
	int cnt = 0, ending = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> meet[i].num >> meet[i].start >> meet[i].end;

	// Endtime 기준 오름차순
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (meet[i].end > meet[j].end)
			{
				tmp = meet[i];
				meet[i] = meet[j];
				meet[j] = tmp;
			}
		}
	}

	// 첫 회의 무조건 배정
	result[cnt++] = meet[0].num;
	// 채워넣기
	for (int i = 1; i < n; i++)
	{
		if (meet[i].start >= meet[ending].end)
		{
			result[cnt++] = meet[i].num;
			ending = i;
		}
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << result[i] << " ";
	
	return 0;
}