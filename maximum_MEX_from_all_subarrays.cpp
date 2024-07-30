#include<bits/stdc++.h>
using namespace std;

//Problem: Find the maximum MEX from all subarrays of length K of given array

//MEX is the smallest minimum positive number that is not present in the array

int maxMex(int arr[], int n, int k){
	set<int> s;
	for(int i=1; i<=n+1; i++){
		s.insert(i);
	}
	
	int i=0, j=0;
	int maxmex = INT_MIN;
	while(j<n){
		s.erase(arr[j]);
		
		if(j-i+1 == k){
			int mex = *(s.begin());
			maxmex = max(maxmex, mex);
			
			s.insert(arr[i]);
			i++;
		}
		j++;
	}
	return maxmex;
}

int main(){
	int arr[] = {6, 1, 3, 2, 4};
	int k=3;
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<maxMex(arr, n, k)<<endl;   
	
	return 0;
}
