#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int n,m,i,a,b,c,d;
    scanf("%d%d/%d",&n,&a,&b);
    for(i=2;i<=n;i++)
    {
        scanf("%d/%d",&c,&d);
        m=b*d/gcd(b,d);
        a*=m/b, b=m;
        a+=c*(m/d);
    }
    m=gcd(a,b);
    a/=m, b/=m;
    if(b==1)
        printf("%d\n",a);
    else
        printf("%d/%d\n",a,b);
    return  0;
}
