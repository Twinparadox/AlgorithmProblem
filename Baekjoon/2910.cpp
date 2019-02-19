#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> freq;
map<int, int> order;
vector<pair<int, int> > arr;
bool compare(const pair<int, int> a, const pair<int, int> b)
{
	if (a.first == b.first)
		return order[a.second] < order[b.second];
	else
		return a.first > b.first;
}
int main(void)
{
	int N, C, tmp;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		freq[tmp]++;
		if (order[tmp] == 0)
			order[tmp] = i + 1;
	}
	for (map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++)
		arr.push_back(make_pair((*iter).second, (*iter).first));
	sort(arr.begin(), arr.end(), compare);

	for (vector<pair<int, int> >::iterator iter = arr.begin(); iter != arr.end(); iter++)
		for (int i = 0; i < (*iter).first; i++)
			cout << (*iter).second << ' ';
}