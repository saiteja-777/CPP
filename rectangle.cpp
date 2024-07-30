#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int i=1;
	while(i<=n){
		int j=1;
		while(j<=n-i+1){
			cout<<j<<" ";
			j++;
		}
		int star=i-1;
		star *= 2;
		while(star){
			cout<<"*"<<" ";
			star--;
		}
		j=n-i+1;
		while(j>0){
			cout<<j<<" ";
			j--;
		}
		cout<<endl;
		i++;
	}
	
	return 0;
}
