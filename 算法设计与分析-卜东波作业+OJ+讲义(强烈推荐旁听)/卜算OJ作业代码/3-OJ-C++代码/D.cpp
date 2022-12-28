#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
int x[1005][1005],m,a,b,c,d,e,f[1005][1005],k;
int main()
{
    cin>>m;
    for(a=1;a<=m;a++)
    {
        for(b=1;b<=a;b++)
        {
            cin>>x[a][b];
        }
    }
    for(a=1;a<=m;a++)
    {
        for(b=1;b<=a;b++)
        {
            if(a==1)
            {
                f[a][1]=x[1][1];
            }
            if(b-1>0&&b+1<=a)
            {
                f[a][b]=max(x[a][b]+f[a-1][b-1],x[a][b]+f[a-1][b]);
            }
            else
            {
                if(b-1<=0)
                {
                    f[a][b]=x[a][b]+f[a-1][b];
                }
                else
                {
                    f[a][b]=x[a][b]+f[a-1][b-1];
                }
            }
        }
    }
    for(a=1;a<=m;a++)
    {
        if(f[m][a]>k)
        {
            k=f[m][a];
        }
    }
    cout<<k;
}
