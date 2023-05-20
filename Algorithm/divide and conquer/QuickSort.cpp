#include<iostream>
using namespace std;

//Haore's Partition Algorithm
int partition1(int* arr,int low,int high){
    int j=low;
    int pivot=arr[low];

    for(int i=low+1;i<=high;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

//Lomuto's Partition Algorithm
int partition2(int* arr,int low,int high){
    int j=low-1;
    int pivot=arr[high];

    for(int i=low;i<=high-1;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    j++;
    swap(arr[j],arr[high]);
    return j;
}

void quickSort(int* arr,int low,int high){
    if(low<high){
        int j=partition2(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

int main(void){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements in the array:");
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

   printf("Before sorting the elements are:");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");

    quickSort(arr,0,n-1);

   printf("After sorting the elements are:");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}