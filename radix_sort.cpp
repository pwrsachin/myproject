#include<bits/stdc++.h>
using namespace std;
void counting_sort(vector<int> &vect,int d,int i);
int main(){
	int n;
	int d;
	cout<<"enter the max no. of digits a number can have:\n";
	cin>>d;
	cout<<"enter the size of an array:";
	cin>>n;
	vector<int> vect;
	vect.resize(n);
	for(int i=0;i<n;i++){
		cin>>vect[i];
	}
	
	for(int i=0;i<d;i++){
	counting_sort(vect,d,i);
	}
	
	for(int i=0;i<vect.size();i++){
		cout<<vect[i]<<"   ";
	}
	
}
void counting_sort(vector<int> &vect,int d,int p){
	int size=10;
	vector<int> array(size);
	for(int i=0;i<size;i++){
		array[i]=0;
	}
	for(int i=0;i<vect.size();i++){
		
		array[((int)(vect[i]/pow(10,p)))%10]+=1;
	}
	
	/*	for(int i=0;i<array.size();i++){
		cout<<array[i]<<"   ";
	}
	cout<<"\n";*/
	
	for(int i=1;i<10;i++){
		array[i]=array[i-1]+array[i];
	}
	
	vector<int> count(size);
	count[0]=0;
	for(int i=0;i<9;i++){
		count[i+1]=array[i];
	}
	vector<int> output(vect.size());
	for(int i=0;i<vect.size();i++){
		output[count[((int)(vect[i]/pow(10,p)))%10]]=vect[i];
		count[((int)(vect[i]/pow(10,p)))%10]+=1;
	}
	for(int i=0;i<vect.size();i++){
		vect[i]=output[i];
	}
}
