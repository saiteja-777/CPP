#include<bits/stdc++.h>
using namespace std;

int maxLengthSubsequence(vector<int>& arr, int n){
	int count = 1;
	int maxi = INT_MIN;
	for(int i=0; i<n-1; i++){
		if(arr[i+1]>=arr[i]){
			count++;
		}
		else{
			maxi = max(maxi, count);
			count=1;
		}
	}
	return maxi;
}

int main(){
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<< maxLengthSubsequence(arr, n)<<endl;
}
