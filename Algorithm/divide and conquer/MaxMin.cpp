#include<iostream>
using namespace std;

void maxMin(int* arr,int low,int high,int* max,int* min){
    int max1,min1;
    if(low==high)
        *max=*min=arr[low];

    else if(low==high-1){
        if(arr[low]>arr[high]){
            *max=arr[low];
            *min=arr[high];
        }
        else{
            *max=arr[high];
            *min=arr[low];
        }
    }    

    else{
        int mid=(low+high)/2;
        maxMin(arr,low,mid,max,min);
        maxMin(arr,mid+1,high,&max1,&min1);

        if(max1>*max)
            *max=max1;
        if(min1<*min)
            *min=min1;
    }
}

int main(void){
    int max,min;
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int* arr=new int[n];

    cout<<"Enter elements in the array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    maxMin(arr,0,n-1,&max,&min);    

    cout<<"Maximum elemment:"<<max<<endl;
    cout<<"Minimum elements:"<<min<<endl;

    return 0;
}