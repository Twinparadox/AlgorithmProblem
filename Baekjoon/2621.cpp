#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool checkContinuous(vector<int> arr, int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] + 1 != arr[i + 1])
			return false;
	return true;
}
int main(void)
{
	vector<int> red, green, blue, yellow, nums;
	char c;
	int num, score = 0, size = 5, cnt[4] = { 0, }, numCount[10] = { 0, };
	int rMax = 0, bMax = 0, gMax = 0, yMax = 0, max = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> c >> num;
		numCount[num]++;
		if (max < num)
			max = num;
		nums.push_back(num);
		switch (c)
		{
		case 'R':
			red.push_back(num);
			cnt[0]++;
			if (rMax < num)
				bMax = num;
			break;
		case 'G':
			green.push_back(num);
			cnt[1]++;
			if (gMax < num)
				gMax = num;
			break;
		case 'B':
			blue.push_back(num);
			cnt[2]++;
			if (bMax < num)
				bMax = num;
			break;
		case 'Y':
			yellow.push_back(num);
			cnt[3]++;
			if (yMax < num)
				yMax = num;
			break;
		default:
			break;
		}
	}
	sort(red.begin(), red.end());
	sort(green.begin(), green.begin());
	sort(blue.begin(), blue.end());
	sort(yellow.begin(), yellow.end());
	sort(nums.begin(), nums.end());

	int maxCount = 0, maxIdx;
	for (int i = 0; i < 4; i++)
		if (maxCount < cnt[i])
			maxCount = cnt[i], maxIdx = i;

	if (maxCount == 5)
	{
		score = 600;
		switch (maxIdx)
		{
		case 0:
			score += rMax;
			if (checkContinuous(red, maxCount))
				score += 300;
			break;
		case 1:
			score += gMax;
			if (checkContinuous(green, maxCount))
				score += 300;
			break;
		case 2:
			score += bMax;
			if (checkContinuous(blue, maxCount))
				score += 300;
			break;
		case 3:
			score += yMax;
			if (checkContinuous(yellow, maxCount))
				score += 300;
			break;
		default:
			break;
		}
	}
	else
	{
		maxCount = 0;
		for (int i = 0; i < 10; i++)
			if (maxCount < numCount[i])
				maxCount = numCount[i], maxIdx = i;

		if (maxCount == 4)
		{
			score = 800 + maxIdx;
		}
		else if (maxCount == 3)
		{
			for (int i = 0; i < 10; i++)
				if (numCount[i] == maxCount)
					score = i;

			bool checkTwo = false;
			int two = 0;
			for (int i = 0; i < 10; i++)
				if (numCount[i] == 2)
					checkTwo = true, two = i, score *= 10;

			if (checkTwo)
				score += 700 + two;
			else
				score += 400;
		}
		else if (maxCount == 2)
		{
			int cnts = 0, a, b = 0;
			for (int i = 0; i < 10; i++)
			{
				if (numCount[i] == 2)
				{
					cnts++;
					if (cnts == 1)
						a = i;
					else
						b = i;
				}
			}

			if (a && b)
			{
				if (a > b)
					score = 300 + a * 10 + b;
				else
					score = 300 + b * 10 + a;
			}
			else
			{
				score = 200 + a;
			}
		}
		else
		{
			if (checkContinuous(nums, size))
				score = 500 + max;
			else
				score = 100 + max;
		}
	}


	cout << score;
}