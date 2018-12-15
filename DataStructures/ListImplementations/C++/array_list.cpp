// so the size will increse twice wherever the limit is reached 
// size growth is amortized constant o(1)

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
		cout<<"\n";
}

int main(){


	add(2);
	add(4);
	add(2);
	add(4);
	printElements();


	cout<<get_element_at(10)<<"\n";
	remove(3);	printElements();
	remove(0);	printElements();
	remove(1);	printElements();
	remove(0);	printElements();
	remove(4);	printElements();
	cout<<"reached 1\n";
	printElements();
	cout<<"reached 2\n";
	add(2);	printElements();
	add(4);	printElements();
	add(2);	printElements();
	add(4);	printElements();

	cout<<"reached 3\n";

}