#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int w, h, n, sum = 0, dir, dist, tmp1, tmp2;
	cin >> w >> h >> n;
	vector<pair<int, int> > arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	cin >> dir >> dist;

	if (dir == 1)
		tmp1 = dist;
	else if (dir == 2)
		tmp1 = w + h + (w - dist);
	else if (dir == 3)
		tmp1 = w + h + w + (h - dist);
	else
		tmp1 = w + dist;

	for (int i = 0; i < n; i++)
	{
		if(arr[i].first==1)
			tmp2 = arr[i].second;
		else if(arr[i].first==2)
			tmp2 = w + h + (w - arr[i].second);
		else if(arr[i].first==3)
			tmp2 = w + h + w + (h - arr[i].second);
		else
			tmp2 = w + arr[i].second;
		int path1 = abs(tmp1 - tmp2);
		int path2 = 2 * w + 2 * h - path1;
		sum += path1 < path2 ? path1 : path2;
	}

	cout << sum;
}
