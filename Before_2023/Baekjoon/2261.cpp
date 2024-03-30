#include <cstdio>
#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
using namespace std;
vector<pair<int, int> > points;
bool compare(const pair<int, int> a, const pair<int, int> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
	{
		if (a.second < b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool compareY(const pair<int, int> a, const pair<int, int> b)
{
	return a.second < b.second;
}
int dist(const pair<int, int> a, const pair<int, int> b)
{
	return (pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
int minNum(int a, int b)
{
	return a < b ? a : b;
}
int closestPair(int start, int end)
{
	int size = end - start + 1;
	if (size <= 16)
	{
		int min = INT_MAX;
		for (int i = start; i <= end; i++)
		{
			for (int j = i + 1; j <= end; j++)
			{
				int d = dist(points[i], points[j]);
				min = d < min ? d : min;
			}
		}
		return min;
	}
	else
	{
		int mid = (start + end) / 2;
		pair<int, int> mPoint = points[mid];

		int leftRange = closestPair(start, mid);
		int rightRange = closestPair(mid + 1, end);
		int distRange = minNum(leftRange, rightRange);

		vector<pair<int, int> > tmpPoints;
		for (int i = start; i <= end; i++)
			if (pow((points[i].first - mPoint.first), 2) <= distRange)
				tmpPoints.push_back(points[i]);

		sort(tmpPoints.begin(), tmpPoints.end(), compareY);
		int size = tmpPoints.size();
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size && (tmpPoints[j].second - tmpPoints[i].second) < distRange; j++)
			{
				int minSub = dist(tmpPoints[i], tmpPoints[j]);
				if (minSub < distRange)
					distRange = minSub;
			}
		}
		return distRange;
	}
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	points = vector<pair<int, int> >(N);
	for (int i = 0; i < N; i++)
		cin >> points[i].first >> points[i].second;

	sort(points.begin(), points.end(), compare);
	cout << closestPair(0, N - 1);
}