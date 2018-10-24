#include<bits/stdc++.h>

#define nullptr NULL

using namespace std;

void bucket_sort(vector<float> &array);

struct node{
	
	float data;
	
	node *next;
};

struct linked_list{  //for creating buckets 
	
	node *start;
	
	node *end;
	
	int total;
	
};

void bucket_sort(vector<float> &array){
	
	linked_list list[array.size()];
	
	int n=array.size();
	//creating n buckets
	
	for(int i=0;i<array.size();++i){
		
		list[i].start = nullptr;
		
		list[i].end = nullptr;
		
		list[i].total = 0;
	}
	
	for(int i=0;i<array.size();++i){
		
		if(list[(int)(n*array[i])].start==nullptr){
			
			node *temp = new node;
			
			temp->next = nullptr;
			
			temp->data = array[i];
			
			list[(int)(n*array[i])].start = temp;
			
			list[(int)(n*array[i])].end = temp;
			
			list[(int)(n*array[i])].total = 1;
			
		}
		
		else
		{
			
			node *temp = new node;
			
			temp->next = nullptr;
			
			temp->data = array[i];
			
			list[(int)(n*array[i])].end->next = temp;
			
			list[(int)(n*array[i])].end = temp;
			
			list[(int)(n*array[i])].total += 1;
			
			
		}
		
		
	}
	
	for(int i=0;i<array.size();++i){
		
		
		if(list[i].total>0){
			
			int curr_size = list[i].total;
			
			float temp_arr[curr_size];
			
			node *temp = new node;
			
			
			temp = list[i].start;
			
			
			int j=0;
			
			while(temp!=nullptr){
				
				
				temp_arr[j] = temp->data;
				
				
				temp=temp->next;
				
				j=j+1;
				
			
			}
			
		
			
			
			int k,l;
			
			for(k=1;k<curr_size;++k){
				
				
				float pivot=temp_arr[k];
				
				l=k-1;
				
				while(l>=0 && temp_arr[l]>pivot){
					
					
						
						temp_arr[l+1] = temp_arr[l];
						
						l=l-1;
					
				}
				
				temp_arr[l+1]=pivot;
				
			}
			
			
		
			
			
			temp = list[i].start;
			
			 j=0;
			 
			 
			
			while(temp!=nullptr){
				
				temp->data = temp_arr[j];
				
				temp=temp->next;
				
				j++;
			}
			
			
		
		
		}
	}
	
	int j=0;
	
	for(int i=0;i<array.size();i++){
		
		if(list[i].start!=nullptr){
			
			node *temp = new node;
			
			temp = list[i].start;
			
			cout<<temp->data<<endl;
			
			while(temp!=nullptr){
				
				array[j] = temp->data;
				
				temp = temp->next;
				
				j++;
			}
		}
	}
	

} 

int main(){
	
	int n;
	
	cout<<"enter the size of an array:";
	
	cin>>n;
	
	vector<float> array(n);
	
	for(int i=0;i<n;i++){
		
		cin>>array[i];
		
	}
	
    bucket_sort(array);
    
    for(int i=0;i<n;i++){
    	
    	cout<<array[i]<<"     ";
	}
}
