#include<iostream>
using namespace std;


bool isSubset(int arr[], int n, int k){
	
	//slidng window technique
	int left =0, right =0, sum=0;
	
	while(right < n){
		sum += arr[right];
		
		if(right-left+1 == k && sum == 0) return 1;
		else if(right-left+1 == k){
			sum -= arr[left];
			left++;
		}
		right++;
	}
	return 0;
}

//Another way to count the values
bool isSubset2(int arr[], int n, int k){
	//base case
	if(k%2 != 0) return 0;
	
	int count = 0;
	for(int i=0; i<n; i++){
		if(arr[i] == 1) count++;
	}
	
	int posCnt = count;
	int negCnt = n-count;
	
	return (posCnt >= k/2 && negCnt >= k/2);
}
int main(){
	int arr[] = {1, -1, 1, -1, 1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k;
	cin>>k;
	
	if(isSubset(arr, n, k) && isSubset2(arr, n, k)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"False"<<endl;
	}
	
	return 0;
}
