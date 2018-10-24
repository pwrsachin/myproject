#include<bits/stdc++.h>
using namespace std;
class Heap{
	private:
		vector<int> data;
	public:
		
		void read_data(){
		int n;
		cout<<"enter the size of an array:"<<endl;
		cin>>n;
		data.resize(n);
		for(int i=0;i<n;i++){
			cin>>data[i];
			
		}
		}
		void swap_(vector<int> &array,int i,int j){
			cout<<"enter in swap\n";
			int temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			
		}
		int left(int n){
			return 2*n+1;
		}
		int right(int n){
			return 2*n+2;
		}
		void max_heapify(vector<int> &array,int n,int heap_size){
			int minindex=n;
			int l=left(n);
			int r=right(n);
			if(l<=heap_size && array[l]>array[n]){
				minindex=l;
			}
			if(r<=heap_size && array[r]>array[minindex]){
				minindex=r;
			}
			if(minindex!=n){
				swap_(array,n,minindex);
				max_heapify(array,minindex,heap_size);
				
			}
		}
		void build_max_heap(vector<int> &array){
			int heap_size=array.size()-1;
			for(int i=array.size()/2-1;i>=0;i--){
				max_heapify(array,i,heap_size);
			}
		}
		void heapsort(vector<int> &array){
			int heap_size=array.size()-1;
			build_max_heap(array);
			for(int i=array.size()-1;i>0;i--){
				swap_(array,0,i);
				heap_size-=1;
				max_heapify(array,0,heap_size);
				
			}
			for(int i=0;i<data.size();i++){
				cout<<" "<<data[i];
			}
		}
		
		void solve(){
			read_data();
			heapsort(data);
		}
		
};
int main(){
	Heap demo;
	demo.solve();
	return 0;
}
