#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
int main()
{
	string a;
	cin >> a;	//杈撳叆瀛楃涓瞐 
	int i, j=a.size()-1; //i浠庡ご寮�濮�  j浠庢渶鍚庢暟缁勪竴涓厓绱犲紑濮�  棣栧熬鍚屾椂鍚戜腑闂村垽瀹�
	 
    while( (i<j) &&(a[i]==a[j]) ) 		//鎴栫敤while鍐欐硶
    {
        i++;
        j--;
    }
	if(i>=j) 	//鑻ユ彁鍓嶇粨鏉熷垯 i<j  娌℃湁鎻愬墠缁撴潫鍒檌澶т簬绛変簬j 
		cout<<"yes";
	else 
		cout<<"no"; 
	return 0;

}
