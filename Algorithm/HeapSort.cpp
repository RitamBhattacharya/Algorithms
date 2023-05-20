#include<iostream>
using namespace std;

void maxHeap(int *arr,int i,int n){
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    int largest=i;
    if(leftChild<n && arr[leftChild]>arr[i])
        largest=leftChild;
    if(rightChild<n && arr[rightChild]>arr[largest])
        largest=rightChild;

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxHeap(arr,largest,n);
    }        
}
void heapify(int* arr,int n){
    for(int i=n/2-1;i>=0;i--)
        maxHeap(arr,i,n);
}
void heapSort(int* arr,int n){
    heapify(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        maxHeap(arr,0,i);
    }
}

int main(void){
    int n,*arr;
    cout<<"Enter the size of the array:";
    cin>>n;
    arr=new int[n];
    cout<<"Enter the elements in the array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Before sorting the elements are:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    heapSort(arr,n);
    cout<<"\nAfter sorting the elements are:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    return 0;
}
