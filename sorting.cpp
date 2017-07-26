// sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void selection_sort(int*, int );
void bubble_sort(int*,int);
void insertion_sort(int*,int);
void swap(int*, int*);
void quick_sort(int*, int, int);
int* merge_sort(int*,int);
int* merge(int*, int*, int, int);
int partition(int*, int, int);
void getTopK(int*,int,int,int);



int _tmain(int argc, _TCHAR* argv[])
{
	int n,k;	
	cout<<"enter size of an array";
	cin>>n;
   
	int *a=new int[n];
	cout<<"\n enter the elements of an array";

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<"\n";

	for(int i=0;i<n;i++)
		cout<<a[i];

	cout<<"\n";

//	selection_sort(a, n);
//	bubble_sort(a,n);
//	insertion_sort(a,n);
	cout<<"\n enter k\n";
	cin>>k;
	getTopK(a,0,n-1,k);

//	quick_sort(a,0,n-1);
//	a=merge_sort(a,n);

	cout<<"\n";

	for(int i=0;i<n;i++)
		cout<<a[i];

	return 0;
}



int* merge(int* left, int* right, int m, int n){

	int i=0,j=0,k=0;
	int *c= new int[m+n];

	while(i<m && j<n)
	{
		if(left[i] < right[j])
		{
			c[k++]= left[i++];
		}
		else
			c[k++]= right[j++];	
	}

	if(i<m){

	while(i<m)
		c[k++]=left[i++];
	}

	if(j<n){

	while(j<n)
		c[k++]=right[j++];

	}

	return c;
}

int* merge_sort(int *a, int n){
	if(n <= 1)return &a[0];

	int *left = merge_sort(&a[0],n/2 );
	int *right = merge_sort(&a[n/2],n-(n/2));

	a=merge(left,right,n/2,n-(n/2));

	return a;

}



void selection_sort(int *arr, int n){
	int min;

	for(int i=0; i<n-1; i++)
	{
		min=i;
		for(int j= i+1; j<n; j++){

		    if(arr[j] < arr[min])
				min=j;
		}
		swap(&arr[i],&arr[min]);
	}

}

void bubble_sort(int *a,int n){
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j+1] < a[j])
				swap(&a[j+1],&a[j]);
		}
	}

}

void insertion_sort(int *a,int n){

	for(int i=1; i<=n-1; i++){

		for(int j=i; j>0 && a[j] < a[j-1]; j--){
		
			swap(&a[j],&a[j-1]);
		}
	}
}

void quick_sort(int *a, int low, int high){

	if(high<=low)return;
	int pivot_pos= partition(a,low,high);

	quick_sort(a,low,pivot_pos-1);
	quick_sort(a,pivot_pos+1,high);
}

int partition(int *a, int low, int high)
{ 
	int cur=low;
	int p=low-1;
	int pivot=a[high];

	while(cur < high){
	
		if(a[cur]<=pivot){
		  swap(&a[p+1],&a[cur]);
		  p++;
		}
		cur++;
	}

	swap(&a[p+1],&a[high]);

	return p+1;
}

void getTopK(int *a, int i, int j, int k){

	int pivot_pos= partition(a,i,j);
	bool flag=false;

	while(!flag){

	if(k == pivot_pos){
		cout<<"\nfound topK\n";
		for(int i=0;i<k;i++)
			cout<<" "<<a[i];
		flag=true;
	}
	else if(k < pivot_pos){
		pivot_pos= partition(a,i,pivot_pos-1);
	}
	else
		pivot_pos= partition(a,pivot_pos+1,j);
	
	}
	

}

void swap(int *a,int *b)
{ int temp;

temp=*a;
*a=*b;
*b=temp;

}

