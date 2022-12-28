#include <bits/stdc++.h> //ÍòÄÜÍ·ÎÄ¼ş, Ë¢ÌâÊ±¿ÉÒÔÓÃ, ´óĞÍÏîÄ¿Ç§Íò²»ÄÜÓÃ
using namespace std;
int a[10020];
int main(){
	int n,i,min,max;
	scanf("%d",&n);
	for(i=0;i<n;i++){ //è¾“å…¥
		scanf("%d",&a[i]);
	}
	max=a[0],min=a[0];//æœ€å¤§æœ€å°å€¼åˆå§‹è®¾ç½®ä¸ºæ•°ç»„ç¬¬ä¸€ä¸ªæ•°
	for(i=1;i<n;i++){
		if(a[i]<min){ //æ‰¾æœ€å¤§
			min=a[i];
		}
		if(a[i]>max){ //æ‰¾æœ€å°
			max=a[i];
		}
	}
	printf("%d",max-min);
}
