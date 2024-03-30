#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    int t, len;
    cin>>t;
    while(t>0)
    {
        char arr[101];
        cin>>arr;
        len=(int)strlen(arr);
        for(int i=0;i<len;i+=2)
        {
            cout<<arr[i];
        }
        for(int i=1;i<len;i+=2)
        {
            cout<<arr[i];
        }
        cout<<endl;
        t--;
    }
}
