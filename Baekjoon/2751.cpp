#include <iostream>
using namespace std;
int arr[1000001];
void Merge(int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* leftArr = new int[n1];
	int* rightArr = new int[n2];

	for (i = 0; i < n1; i++)
		leftArr[i] = arr[i + left];
	for (i = 0; i < n2; i++)
		rightArr[i] = arr[i + mid + 1];

	i = j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = leftArr[i];
		k++, i++;
	}
	while (j < n2)
	{
		arr[k] = rightArr[j];
		k++, j++;
	}
}
void MergeSort(int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	MergeSort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}
