#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int i=0;
	char ch = 'A';
	while(i<n){
		int j=0;
		while(j<n){
			cout<<ch<<" ";
			ch++;
			j++;
		}
		cout<<endl;
		i++;
	}
	
	return 0;
}
