#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct team {
	int id;
	int distance;
	int rank;
};
bool compareDistance(const struct team a, const struct team b)
{
	if (a.distance < b.distance)
		return true;
	else
		return false;
}
bool compareID(const struct team a, const struct team b)
{
	if (a.id < b.id)
		return true;
	else
		return false;
}
int main(void)
{
	int R, C, size = 9;
	cin >> R >> C;
	vector<string> picture(R);
	vector<struct team> list(size);
	for (int i = 0; i < R; i++)
		cin >> picture[i];

	for (int i = 0; i < 9; i++)
		list[i].id = i + 1, list[i].distance = -1;

	for (int i = 0; i < R; i++)
	{
		size_t pos;
		int teamNumber = 1;
		for (; teamNumber < size + 1; teamNumber++)
		{
			pos = picture[i].find(to_string(teamNumber));
			if (pos != string::npos)
				break;
		}

		if (pos == string::npos)
			continue;
		else
			list[teamNumber - 1].distance = C - pos;
	}

	sort(list.begin(), list.end(), compareDistance);
	int rank = 1;
	for (int i = 0; i < size; i++)
	{
		list[i].rank = rank;
		if (i < size - 1)
		{
			if (list[i].distance < list[i + 1].distance)
				rank++;
		}
	}

	sort(list.begin(), list.end(), compareID);
	for (int i = 0; i < size; i++)
		cout << list[i].rank << '\n';
}