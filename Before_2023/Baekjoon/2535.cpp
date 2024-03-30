#include <iostream>
#include <algorithm>
using namespace std;
struct inform
{
	int nation;
	int num;
	int score;
};
int compare(const void* a, const void* b)
{
	struct inform *pa = (struct inform*)a, *pb = (struct inform*)b;
	if (pb->score > pa->score)
		return 1;
	else if (pb->score == pa->score)
	{
		return pa->nation - pb->nation;
	}
	else
		return -1;
}
int main(void)
{
	int n, nation, num, score, check[101] = { 0, }, medal = 0;
	struct inform arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nation >> num >> score;
		arr[i] = { nation,num,score };
	}
	qsort(arr, n, sizeof(struct inform), compare);
	for (int i = 0; i < n && medal < 3; i++)
	{
		if (check[arr[i].nation] < 2)
			cout << arr[i].nation << " " << arr[i].num << "\n", medal++, check[arr[i].nation]++;
	}
}
