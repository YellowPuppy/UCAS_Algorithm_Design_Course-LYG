#include <bits/stdc++.h> //����ͷ�ļ�, ˢ��ʱ������, ������Ŀǧ������
using namespace std;
int main()
{
	string a;
	cin >> a;	//输入字符串a 
	int i, j=a.size()-1; //i从头开始  j从最后数组一个元素开始  首尾同时向中间判定
	 
    while( (i<j) &&(a[i]==a[j]) ) 		//或用while写法
    {
        i++;
        j--;
    }
	if(i>=j) 	//若提前结束则 i<j  没有提前结束则i大于等于j 
		cout<<"yes";
	else 
		cout<<"no"; 
	return 0;

}
