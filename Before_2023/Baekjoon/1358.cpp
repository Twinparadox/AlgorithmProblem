#include <iostream>
#include <math.h>
using namespace std;
struct coord
{
	int x, y;
};
int main(void)
{
	double r;
	int w, h, x, y, p, cnt = 0;
	struct coord arr[100];
	cin >> w >> h >> x >> y >> p;
	r = (double)h / 2;
	for (int i = 0; i < p; i++)
		cin >> arr[i].x >> arr[i].y;

	for (int i = 0; i < p; i++)
	{
		if ((arr[i].x >= x && arr[i].x <= x + w) && (arr[i].y >= y && arr[i].y <= y + h))
			cnt++;
		else
		{
			double dist1 = sqrt(pow(arr[i].x - x, 2) + pow(arr[i].y - (y + r), 2));
			double dist2 = sqrt(pow(arr[i].x - (x + w), 2) + pow(arr[i].y - (y + r), 2));

			if (dist1 <= r || dist2 <= r)
				cnt++;
		}
	}
	cout << cnt;
}
