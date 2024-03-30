#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);

	int len;
	int n, s, e, tmp;
	char max, min;
	char arr[1000000];
	
	cin >> arr;
	len = strlen(arr);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		// 비트 연산
		if (s > e)
        	{
        		tmp=s;
            		s=e;
        	    	e=tmp;
	 	}
        	max = min = arr[s];
        
        	for (j = s+1; j <= e; j++)
		     if(arr[j]!=arr[j-1])
			break;
		min=arr[j];
        	if (max == min)
            		printf("Yes\n");
        	else
        		printf("No\n");

	}
	return 0;
}
