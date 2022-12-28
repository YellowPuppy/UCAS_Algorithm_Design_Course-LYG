#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
#define N 200009 
#define int ll
typedef long long ll;
ll n,q[N*30],dis[N],dp[N],qi[N],pi[N],lim[N];
int tot,head[N],deep[N],remt[N][30],remv[N][30],p[N][30],now=1;
int ddf;
inline ll rd(){
    ll x=0;char c=getchar();bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x; 
}
struct SEG{int head,tail;}tr[N<<2];
struct edge{int n,to,l;}e[N];
inline void add(int u,int v,int l){e[++tot].n=head[u];e[tot].to=v;head[u]=tot;e[tot].l=l;}
inline double get_k(int j,int k){return (double)((double)dp[j]-dp[k])/((double)dis[j]-dis[k]);}
inline int get_ans(int cnt,double p){
    int l=tr[cnt].head,r=tr[cnt].tail-1,ans=-1;    
    if(tr[cnt].head>=tr[cnt].tail)return q[tr[cnt].tail];
    while(l<=r){
        int mid=(l+r)>>1;
        if(get_k(q[mid],q[mid+1])>=p){ans=mid;r=mid-1;}else l=mid+1;
    }
    if(ans<0)ans=tr[cnt].tail;
    return q[ans];
}
int query(int cnt,int l,int r,int L,int R,double p){
    if(l>=L&&r<=R)return get_ans(cnt,p);
    int mid=(l+r)>>1;
    if(mid>=L&&mid<R){
        int x=query(cnt<<1,l,mid,L,R,p),y=query(cnt<<1|1,mid+1,r,L,R,p);
        if(get_k(x,y)>=p)return x;else return y;
    }
    else if(mid>=L)return query(cnt<<1,l,mid,L,R,p);
    else return query(cnt<<1|1,mid+1,r,L,R,p);
}
inline int findqueue(int cnt,int u){
    if(tr[cnt].head>=tr[cnt].tail)return tr[cnt].tail;
    int l=tr[cnt].head,r=tr[cnt].tail-1,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(get_k(q[mid],q[mid+1])>get_k(q[mid],u))ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(ans<0)ans=tr[cnt].tail;
    return ans;
}
void build(int cnt,int l,int r){
    tr[cnt].tail=now-1;tr[cnt].head=now;
    now+=(r-l+1)+5;
    if(l==r)return;int mid=(l+r)>>1;
    build(cnt<<1,l,mid);build(cnt<<1|1,mid+1,r);
}
void insert(int cnt,int l,int r,int u,int x,int dep){
    int pos=findqueue(cnt,u)+1;
    remt[u][dep]=tr[cnt].tail;
    remv[u][dep]=q[pos];
    q[pos]=u;tr[cnt].tail=pos; 
    if(l==r)return;
    int mid=(l+r)>>1;
    if(mid>=x)insert(cnt<<1,l,mid,u,x,dep+1);
    else insert(cnt<<1|1,mid+1,r,u,x,dep+1);
}
void del(int cnt,int l,int r,int u,int x,int dep){    
    q[tr[cnt].tail]=remv[u][dep];
    tr[cnt].tail=remt[u][dep];
    if(l==r)return;
    int mid=(l+r)>>1;
    if(mid>=x)del(cnt<<1,l,mid,u,x,dep+1);
    else del(cnt<<1|1,mid+1,r,u,x,dep+1);
}
inline int jump(int x,int l){
    int now=x;
    for(int i=20;i>=0;--i)if(p[now][i]&&dis[x]-dis[p[now][i]]<=l)now=p[now][i];
    return now;
}
void dfs(int u){
    for(int i=1;(1<<i)<=deep[u];++i)p[u][i]=p[p[u][i-1]][i-1];
    if(u!=1){
        int x=jump(u,lim[u]);
        ddf=u;
        int y=query(1,1,n,deep[x],deep[p[u][0]],pi[u]);
        dp[u]=dp[y]+(dis[u]-dis[y])*pi[u]+qi[u];
    }
    insert(1,1,n,u,deep[u],0);
    for(int i=head[u];i;i=e[i].n){
       int v=e[i].to;dis[v]=dis[u]+e[i].l;
       deep[v]=deep[u]+1;p[v][0]=u;dfs(v); 
    }
    del(1,1,n,u,deep[u],0);
} 
signed main(){
    n=rd();int t=rd();int father;int l;
    for(int i=2;i<=n;++i){
        father=rd();l=rd();pi[i]=rd();qi[i]=rd();lim[i]=rd();
        add(father,i,l); 
    }
    build(1,1,n); 
    deep[1]=1;dfs(1);
    for(int i=2;i<=n;++i)printf("%lld\n",dp[i]);
    return 0;
}
