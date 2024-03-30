#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	int t, size;
	vector<pair<int, string> > arr;
	arr.push_back(make_pair(97, "A+"));
	arr.push_back(make_pair(90, "A"));
	arr.push_back(make_pair(87, "B+"));
	arr.push_back(make_pair(80, "B"));
	arr.push_back(make_pair(77, "C+"));
	arr.push_back(make_pair(70, "C"));
	arr.push_back(make_pair(67, "D+"));
	arr.push_back(make_pair(60, "D"));
	arr.push_back(make_pair(0, "F"));
	size = arr.size();

	cin >> t;
	while (t--)
	{
		string name;
		int score;
		cin >> name >> score;
		cout << name << " ";
		for (int i = 0; i < size; i++)
		{
			if (score >= arr[i].first)
			{
				cout << arr[i].second;
				break;
			}
		}
		cout << '\n';
	}
}