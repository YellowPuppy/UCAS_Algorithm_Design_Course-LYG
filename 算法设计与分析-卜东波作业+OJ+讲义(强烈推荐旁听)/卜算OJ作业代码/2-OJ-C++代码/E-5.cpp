#include <bits/stdc++.h> //ÍòÄÜÍ·ÎÄ¼ş, Ë¢ÌâÊ±¿ÉÒÔÓÃ, ´óĞÍÏîÄ¿Ç§Íò²»ÄÜÓÃ
using namespace std;
struct Data
{
    int l,r;
}data[100001];
struct Messi
{
    int next,to;
}edge[200010];
struct tree
{
     priority_queue<int>d1,d2;//æ¯ä¸€ä¸ªçº¿æ®µæ ‘èŠ‚ç‚¹å¯¹åº”ä¸¤ä¸ªå¤§æ ¹å †
  void push(int x) {d1.push(x);}  
  void del(int x) {d2.push(x);}   
  int top()
  {
      while (!d2.empty()&&d1.top()==d2.top()) d1.pop(),d2.pop();
      if (d1.empty()) return -1;
       return d1.top();
  } 
}c[1000001];
int n,m,dat1[200001],dat2[200001],dat3[200001];
int head[100001],num,son[100001],size[100001],fa[100001],dep[100001],top[100001],pos[100001],tot;
bool cmp(Data a,Data b)
{
    return a.l<b.l;
}
void add(int u,int v)
{
    num++;
    edge[num].next=head[u];
    head[u]=num;
    edge[num].to=v;
}
void dfs1(int u,int pa,int depth)
{
    son[u]=0;size[u]=1;fa[u]=pa;dep[u]=depth;
    for (int j=head[u];j;j=edge[j].next)
    {
        int v=edge[j].to;
         if (v!=pa)
         {
            dfs1(v,u,depth+1);
            size[u]+=size[v];
            if (size[v]>size[son[u]]) son[u]=v;
         }
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;
     pos[u]=++tot;
     if (son[u]) dfs2(son[u],tp);
     for (int j=head[u];j;j=edge[j].next)
      if (edge[j].to!=son[u]&&edge[j].to!=fa[u])
     {
        dfs2(edge[j].to,edge[j].to);
     }
}
void update(int rt,int l,int r,int L,int R,int type,int val)
{
    if (L>R) return;
    if (l>=L&&r<=R)
    {
        if (type) c[rt].del(val);
         else c[rt].push(val);
        return;
    }
     int mid=(l+r)/2;
     if (L<=mid) update(rt*2,l,mid,L,R,type,val);
     if (R>mid) update(rt*2+1,mid+1,r,L,R,type,val);
}
void change(int x,int y,int type,int val)//å¯¹æœªè·³è¿‡çš„é“¾çš„åŒºé—´ç»´æŠ¤
{int sum=0;
    while (top[x]!=top[y])
    {
        if (dep[top[x]]<dep[top[y]]) swap(x,y);
        data[++sum].l=pos[top[x]];data[sum].r=pos[x];
        x=fa[top[x]];
    }
    if (dep[x]<dep[y]) swap(x,y);
     if (x!=y) data[++sum].l=pos[y],data[sum].r=pos[x];
     sort(data+1,data+sum+1,cmp);
     int last=1;
      for (int i=1;i<=sum;i++)
       update(1,1,n,last,data[i].l-1,type,val),last=data[i].r+1;
 update(1,1,n,last,n,type,val);
}
int get()
{int x=0;
    char ch=getchar();
    while (ch<'0'||ch>'9')
      ch=getchar();
      while (ch>='0'&&ch<='9')
      {
        x=x*10+ch-'0';
         ch=getchar();
      }
      return x;
}
int query(int rt,int l,int r,int x)//æŸ¥æ‰¾
{
    if (l==r)
     {
         return c[rt].top(); 
     }
      int mid=(l+r)/2;
       if (x<=mid) return max(c[rt].top(),query(rt*2,l,mid,x));
       else return max(c[rt].top(),query(rt*2+1,mid+1,r,x));
}
int main()
{int i,x,y,a,b,v;
//freopen("2.out","w",stdout);
    n=get();m=get();
     for (i=1;i<=n-1;i++)
     {
         x=get();y=get();
         add(x,y);
         add(y,x);
     }
     dfs1(1,1,1);
     dfs2(1,1);
      for (i=1;i<=m;i++)
      {
          int t=get();
           if (t==0)
           {
               a=get();b=get();v=get();
               dat1[i]=a;dat2[i]=b;dat3[i]=v;
                change(a,b,0,v);
         }
         if (t==1)
         {
             x=get();
              a=dat1[x];b=dat2[x];v=dat3[x];
              change(a,b,1,v);
         }
          if (t==(1+1))
          {
              x=get();
              printf("%d\n",query(1,1,n,pos[x]));
          }
      }
}
