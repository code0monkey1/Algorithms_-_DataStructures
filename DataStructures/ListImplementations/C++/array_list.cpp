// so the size will increse twice wherever the limit is reached 

#include <bits/stdc++.h>

using namespace std;
int size=0;
int index_at=-1;
int* arr=NULL;

int count(){
	return size;
}

void add(int num){
	if(arr==NULL)arr=new int[1];
	
	arr[++index_at]=num;
	size++;

	if(index_at==size)
		arr= new int[(size)*2];

}
void shift_elements_to_left_after(int index_at){

	for (int i = index_at ; i+1 < size; ++i)
		arr[i]=arr[i+1];

}

void remove(int index_at){
	if(size==0){
		cout<<"The list is empty !!";
		return  ;
	}

	shift_elements_to_left_after(index_at);
	size--;
}



int get_element_at(int index_at){
	if(index_at>=0 and index_at<size) 
		return arr[index_at];
	else 
		cout<<"Not Applicable";
	return -1;
}
void printElements(){
	for(int i=0;i<size;i++)cout<<arr[i]<<" ";
}

int main(){


	add(2);
	add(4);
	add(2);
	add(4);
	cout<<get_element_at(1)<<"\n";
	cout<<get_element_at(10)<<"\n";
	remove(3);
	remove(0);
	remove(1);
	remove(0);
	remove(4);

	printElements();

}