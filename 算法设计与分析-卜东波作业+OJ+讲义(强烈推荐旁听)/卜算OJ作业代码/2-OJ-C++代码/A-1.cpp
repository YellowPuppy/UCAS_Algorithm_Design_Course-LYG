#include <bits/stdc++.h> //ÍòÄÜÍ·ÎÄ¼ş, Ë¢ÌâÊ±¿ÉÒÔÓÃ, ´óĞÍÏîÄ¿Ç§Íò²»ÄÜÓÃ
using namespace std;
void Merge(vector<int>& nums, int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	vector<int> temp(high - low + 1);
	while(i <= mid && j <= high) {
		if(nums[i] <= nums[j])
			temp[k++] = nums[i++];
		else 
			temp[k++] = nums[j++];
	}
	while(i <= mid) temp[k++] = nums[i++];
	while(j <= high) temp[k++] = nums[j++];
	for(int i = low; i <= high; i++) {
		nums[i] = temp[i - low];
	}
}

void MergeSort(vector<int>& nums, int low, int high) {
	if(low < high) {
		int mid = (high + low) >> 1;
		MergeSort(nums, low, mid);
		MergeSort(nums, mid + 1, high);
		Merge(nums, low, mid, high);
	}
}

int partition(vector<int>& nums, int low, int high) {
	int index = low + rand()%(high - low + 1);
	swap(nums[low], nums[index]);
	int pivot = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= pivot) 
			high--;
		swap(nums[low], nums[high]);
		while (low < high && nums[low] <= pivot)
			low++;
		swap(nums[low], nums[high]);
	}
	return low;
}

void QuickSort(vector<int>& nums, int low, int high) {
	if(low < high) {
		int loc = partition(nums, low, high);
		QuickSort(nums, low, loc - 1);
		QuickSort(nums, loc + 1, high);
	}
}

bool BinarySearch(vector<int>& nums, int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) >> 1;
		if(nums[mid] == target) {
			return true;
		}
		else if(nums[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return false;
}

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);//è¾“å…¥æ•°ç»„çš„é•¿åº¦å’ŒæŸ¥è¯¢çš„æ¬¡æ•°
    vector<int> a(n);//å®šä¹‰æ•°ç»„ 
    for (int i = 0; i < n; i++) {//å¯¹æ•°ç»„åˆå§‹åŒ– 
        scanf("%d", &a[i]);
    }
    //sort(a.begin(), a.end()); //è°ƒåº“
	//MergeSort(a, 0, n - 1); //æ‰‹æ’•å½’å¹¶æ’åº
	QuickSort(a, 0, n - 1); //æ‰‹æ’•å¿«é€Ÿæ’åº
    int key;
	for(int s = 1; s <= m; s++) {
		scanf("%d", &key);
		//bool flag = binary_search(a.begin(), a.end(), key); //è°ƒåº“
		bool flag = BinarySearch(a, 0, n - 1, key); //æ‰‹å†™çš„
		if(flag == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
