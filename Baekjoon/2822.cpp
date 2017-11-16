#include <iostream>
#include <algorithm>
using namespace std;
struct num
{
	int a;
	int idx;
};
int compare(const void* a, const void* b)
{
	struct num *pa = (struct num*)a, *pb = (struct num*)b;
	return pb->a - pa->a;
}
int main(void)
{
	struct num arr[8];
	int tmp, sum = 0, list[5];
	for (int i = 0; i < 8; i++)
	{
		cin >> tmp;
		arr[i].a = tmp;
		arr[i].idx = i + 1;
	}
	qsort(arr, 8, sizeof(struct num), compare);
	for (int i = 0; i < 5; i++)
	{
		list[i] = arr[i].idx;
		sum += arr[i].a;
	}
	sort(list, list + 5);
	cout << sum << "\n";
	for (int i = 0; i < 5; i++)
		cout << list[i] << " ";
}
