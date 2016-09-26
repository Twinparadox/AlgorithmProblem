#include <iostream>
using namespace std;

typedef struct Jewel
{
	int weight;
	int price;
	float PPW;
} Jewel;

Jewel jew[1000];

int main()
{
	int n, maxweight;
	int jew_count = 0, maxprice = 0;
	Jewel tmp;

	cin >> n >> maxweight;
	for (int i = 0; i < n; i++)
	{
		cin >> jew[i].weight >> jew[i].price;
		jew[i].PPW = (float)jew[i].price / jew[i].weight;
	}

	// ���� �� ���ݺ�� �������� ����
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (jew[i].PPW < jew[j].PPW || (jew[i].PPW == jew[j].PPW && jew[i].weight < jew[j].weight))
			{
				tmp = jew[i];
				jew[i] = jew[j];
				jew[j] = tmp;
			}
		}
	}

	// PPW�� ���� �������� �ִ��� ����ִ� ä��� ����
	for (int i = 0; i < n; i++)
	{
		jew_count = maxweight / jew[i].weight;
		maxprice += (jew[i].price*jew_count);
		maxweight -= jew[i].weight*jew_count;
		if (maxweight == 0)
			break;
	}
	cout << maxprice;
	
	return 0;
}