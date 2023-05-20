#include<iostream>
using namespace std;

//Recursive
int binarySearch(int* arr,int low,int high,int item){
    if(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==item) return mid;
        else if(arr[mid]>item) return binarySearch(arr,low,mid-1,item);
        else return binarySearch(arr,mid+1,high,item);
    }
    return -1;
}

//Iterative
int binSearch(int* arr,int low,int high,int item){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==item) return mid;
        else if(arr[mid]>item) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(void){
    int n,item;
    cout<<"Enter the size of the array:";
    cin>>n;
    int* arr=new int[n];

    cout<<"Enter elements in the array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the element you want to search:";
    cin>>item;

    //int index=binarySearch(arr,0,n-1,item);
    int index=binSearch(arr,0,n-1,item);
    if(index!=-1)
         cout<<"Element present at the index:"<<index<<endl;
    else
        cout<<"Element does not exist"<<endl;
    return 0;
}