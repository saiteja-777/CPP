#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
//	int i=0;
//	while(i<n){
//		int j=0; 
//		while(j<=i){
//			cout<<"*"<<" ";
//			j++;
//		}
//		cout<<endl;
//		i++;
//	}
	
	
	int i=1;
	while(i<=n){
		int j=n-i+1;
		while(j<=n){
			cout<<"*"<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}
	
	
	return 0;
}
