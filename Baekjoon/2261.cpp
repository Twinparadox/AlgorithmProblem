#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
struct coord {
	int x;
	int y;
};
double minDistance = -1;
vector<struct coord> arr;

double minDist(double a, double b)
{
	return a < b ? a : b;
}
double mesaureDistance(const struct coord a, const struct coord b)
{
	double distance = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
	if (minDistance == -1 || distance < minDistance)
		minDistance = distance;
	return distance;
}
double closestPair(int left, int right)
{
	int size = right - left + 1;
	if (size == 2)
		return mesaureDistance(arr[left], arr[right]);
	else
	{
		int mid = (left + right) / 2;
		double cpLeft = closestPair(left, mid);
		double cpRight = closestPair(mid + 1, right);
		double distRange = minDist(cpLeft, cpRight);


	}
}
int compareCoord(const struct coord& a, const struct coord& b)
{
	if (a.x > b.x)
		return 1;
	else if (a.x == b.x)
	{
		if (a.y > b.y)
			return 1;
		else if (a.y == b.y)
			return 0;
		else
			return -1;
	}
	else
		return -1;
}
int main(void)
{
	int N, x, y;
	cin >> N;

	arr.reserve(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr.begin(), arr.end(), compareCoord);

	closestPair(0, N - 1);
}