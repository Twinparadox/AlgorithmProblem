#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;
struct candidate
{
	int idx;
	int nRecommend;
	int date;
};
bool compare(struct candidate a, struct candidate b)
{
	if (a.nRecommend == b.nRecommend)
		return a.date < b.date;
	return a.nRecommend < b.nRecommend;
}
bool compareIdx(struct candidate a, struct candidate b)
{
	return a.idx < b.idx;
}
int main(void)
{
	int N, M, size;
	cin >> N >> M;
	deque<struct candidate> frame;

	int cand;
	bool flag;
	for (int i = 0; i < M; i++)
	{
		cin >> cand;
		flag = true;
		for (auto &it : frame)
			if (it.idx == cand)
				it.nRecommend++, flag = false;

		if (!flag)
			continue;

		sort(frame.begin(), frame.end(), compare);
		if (frame.size() >= N)
			frame.pop_front();
		frame.push_back({ cand, 1, i });
	}

	sort(frame.begin(), frame.end(), compareIdx);

	for (auto it : frame)
		cout << it.idx << ' ';
}