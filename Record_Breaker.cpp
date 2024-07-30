#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	
	//logic
	int maxi = INT_MIN;
	int days = 0;
	
	for(int j=0; j<n; j++){
		//first case
		if(j==0 && arr[j]>arr[j+1]){
			days++;
		}
		else if(j>0 && arr[j]>maxi && arr[j]>arr[j+1]){
			days++;
		}
		else if(j==n-1 && arr[j]>maxi) days++;
		
		maxi = max(maxi, arr[j]);
	}
	cout<< days<<endl;
	
	return 0;
}
