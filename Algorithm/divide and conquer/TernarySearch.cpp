#include<iostream>
using namespace std;

int ternarySearch(int* arr,int low,int high,int item){
    if(low<=high){
        int mid1=low+(high-low)/3;
        int mid2=high-(high-low)/3;

        if(arr[mid1]==item) return mid1;
        else if(arr[mid2]==item) return mid2;
        else if(item<arr[mid1]) return ternarySearch(arr,low,mid1-1,item);
        else if(item>arr[mid2]) return ternarySearch(arr,mid2+1,high,item);
        else return ternarySearch(arr,mid1+1,mid2-1,item);
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

    int index=ternarySearch(arr,0,n-1,item);

    if(index!=-1)
         cout<<"Element present at the index:"<<index<<endl;
    else
        cout<<"Element does not exist"<<endl;
    return 0;
}