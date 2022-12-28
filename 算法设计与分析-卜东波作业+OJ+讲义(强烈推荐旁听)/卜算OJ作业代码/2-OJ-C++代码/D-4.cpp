#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
int main() 
{
    int n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
	vector<int> odd, even;
    for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 1) {
			odd.push_back(a[i]);
		}
		else {
			even.push_back(a[i]);
		}
	}

	sort(odd.begin(), odd.end());
	reverse(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	for(int i = 0; i < odd.size(); i++) {
		printf("%d ", odd[i]);
	}
	for(int i = 0; i < even.size(); i++) {
		if(i == even.size() - 1)
			printf("%d", even[i]);
		else
			printf("%d ", even[i]);
	}
}
