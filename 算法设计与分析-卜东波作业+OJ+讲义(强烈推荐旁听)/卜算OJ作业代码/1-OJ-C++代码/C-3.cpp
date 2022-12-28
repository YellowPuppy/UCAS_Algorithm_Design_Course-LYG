#include <bits/stdc++.h> //万能头文件, 刷题时可以用, 大型项目千万不能用
using namespace std;
const int max_n=300;

struct bign{
	int a[max_n];
	int size;
	bign(){
		memset(a,0,sizeof(a));
		size=0;
	}
};

bign fun1(string str){
	//灏唖tr杞负bign
	bign ans;
	int len=str.length();
	for(int i=len-1;i>=0;i--){
		ans.a[ans.size++]=str[i]-'0';
	}
	return ans;
}

bign Add(bign x,bign y){
	bign ans;
	int r=0;
	int len1=x.size,len2=y.size;
	int i=0;
	for(i=0;i<len1 && i<len2;i++){
		int tmp=x.a[i]+y.a[i]+r;
		ans.a[ans.size++]=tmp%10;
		r=tmp/10;
	}
	while(i<len1){
		int tmp=x.a[i++]+r;
		ans.a[ans.size++]=tmp%10;
		r=tmp/10;
	}
	while(i<len2){
		int tmp=y.a[i++]+r;
		ans.a[ans.size++]=tmp%10;
		r=tmp/10;
	}
	if(r!=0){
		ans.a[ans.size++]=r;
	}
	return ans;
}

void print(bign ans){
	int j=ans.size-1;
	while(ans.a[j]==0 && j>0){
		j--;
	}
	
	while(j>=0){
		cout<<ans.a[j--];
	}
	cout<<endl;
}

int main(){
	string str1,str2;
	cin >> str1 >> str2;
	bign num1=fun1(str1);
	bign num2=fun1(str2);
	bign num3=Add(num1,num2);
	print(num3);
	return 0;
}
