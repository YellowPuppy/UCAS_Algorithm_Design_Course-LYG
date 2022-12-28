#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;

long fibonacci(int n) {
    vector<long> dp(n, 0);
    dp[0] = 3, dp[1] = 4, dp[2] = 5;
    for(int i = 3; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n - 1];
}

int main() {
    int N;
    scanf("%d", &N);
    long res = fibonacci(N);
    cout << res;
}
