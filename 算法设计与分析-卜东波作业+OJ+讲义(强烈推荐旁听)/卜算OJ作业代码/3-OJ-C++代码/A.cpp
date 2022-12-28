#include <bits/stdc++.h> //����ͷ�ļ�, ˢ��ʱ������, ������Ŀǧ������
using namespace std;

int mostvalue(vector<int>& a) { //时间复杂度为O(n), 空间复杂度为O(n)
    int n = a.size();
    vector<int> dp(n);
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    int index = max_element(dp.begin(), dp.end()) - dp.begin();
    return dp[index];
}

int mostvalue2(vector<int>& a) {  //时间复杂度为O(n), 空间复杂度为O(1)
    int n = a.size();
    int dp = a[0];
    int res = INT_MIN;
    for(int i = 1; i < n; i++) {
        dp = max(dp + a[i], a[i]);  //使用滚动数组思想来优化空间
        res = max(res, dp); //迭代式更新求得最大值
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    //int res = mostvalue(a); //不优化空间
    int res = mostvalue2(a); //优化空间
    cout << res;
    
}



 
