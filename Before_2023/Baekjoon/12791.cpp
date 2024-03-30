#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	vector<pair<int, string> > list;
	int q, s, e, cnt = 0, size;
	list.push_back(make_pair(1967, "DavidBowie"));
	list.push_back(make_pair(1969, "SpaceOddity"));
	list.push_back(make_pair(1970, "TheManWhoSoldTheWorld"));
	list.push_back(make_pair(1971, "HunkyDory"));
	list.push_back(make_pair(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
	list.push_back(make_pair(1973, "AladdinSane"));
	list.push_back(make_pair(1973, "PinUps"));
	list.push_back(make_pair(1974, "DiamondDogs"));
	list.push_back(make_pair(1975, "YoungAmericans"));
	list.push_back(make_pair(1976, "StationToStation"));
	list.push_back(make_pair(1977, "Low"));
	list.push_back(make_pair(1977, "Heroes"));
	list.push_back(make_pair(1979, "Lodger"));
	list.push_back(make_pair(1980, "ScaryMonstersAndSuperCreeps"));
	list.push_back(make_pair(1983, "LetsDance"));
	list.push_back(make_pair(1984, "Tonight"));
	list.push_back(make_pair(1987, "NeverLetMeDown"));
	list.push_back(make_pair(1993, "BlackTieWhiteNoise"));
	list.push_back(make_pair(1995, "1.Outside"));
	list.push_back(make_pair(1997, "Earthling"));
	list.push_back(make_pair(1999, "Hours"));
	list.push_back(make_pair(2002, "Heathen"));
	list.push_back(make_pair(2003, "Reality"));
	list.push_back(make_pair(2013, "TheNextDay"));
	list.push_back(make_pair(2016, "BlackStar"));
	size = list.size();
	cin >> q;
	while (q--)
	{
		cnt = 0;
		cin >> s >> e;
		for (int i = 0; i < size; i++)
			if (list[i].first>=s && list[i].first <= e)
				cnt++;
		cout << cnt << "\n";
		for (int i = 0; i < size; i++)
			if (list[i].first >= s && list[i].first <= e)
				cout << list[i].first << " " << list[i].second << "\n";
	}
}
