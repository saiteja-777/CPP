#include<SDL2/SDL.h>
#include<iostream>
#include<random>
#include<ranges>
#include<algorithm>
using namespace std;

int main(){
	radom_device rd;
	uniform_int_distribution d(1,99);
	vector<int> v;
	for(int i=0; i<100; i++){
		v.push_bacj(d(rd));
	}
	
	//sort algorithm
	for(unsigned int i=0; i<v.size(); i++){
		for(unsigned int j=i; j<v.size(); j++){
			if(v[j]<v[i]) swap(v[j], v[i]);
		}
	}
	for(int i:v) cout<<i<<" ";
}
