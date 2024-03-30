#include <iostream>
using namespace std;

class Book
{
public:
    int volume;
    int value;
    int num;
    double vpv;
};

int main()
{
    int n, uvolume;
    int getmax=0;
    int cnt=0;
    int t;
    
    cin>>t;
    
    while(t)
    {
    cin>>n>>uvolume;
        
        getmax=0;
        cnt=0;
    Book* b=new Book[n];
    Book tmp;
    
    for(int i=0;i<n;i++)
    {
        cin>>b[i].volume>>b[i].value>>b[i].num;
        b[i].vpv=(double)b[i].value/(double)b[i].volume;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(b[j].vpv<b[j+1].vpv)
            {
                tmp=b[j];
                b[j]=b[j+1];
                b[j+1]=tmp;
            }
            else if(b[j].vpv==b[j+1].vpv)
            {
                if(b[j].volume>b[j+1].volume)
                {
                    tmp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=tmp;
                }
            }
        }
    }
    
    while(cnt<n && uvolume>=0)
    {
        if(uvolume-b[cnt].volume<0 || b[cnt].num<1)
        {
            cnt++;
            continue;
        }
        b[cnt].num--;
        uvolume-=b[cnt].volume;
        getmax+=b[cnt].value;
    }
    
    cout<<getmax<<endl;
    
        t--;
        
        delete [] b;
    }
}
