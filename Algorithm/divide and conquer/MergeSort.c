#include<stdio.h>

void merge(int* arr,int low,int mid,int high){
    int l=low,m=mid+1,k=low,i;
    int b[high-low+1];

    while((l<=mid) && (m<=high)){
        if(arr[l]<=arr[m]){
            b[k]=arr[l];
            l++;
        }
        else{
            b[k]=arr[m];
            m++;
        }
        k++;
    }
    if(l>mid){
        for(i=m;i<=high;i++){
            b[k]=arr[i];
            k++;
        }
    }
    else{
        for(i=l;i<=mid;i++){
            b[k]=arr[i];
            k++;
        }
    }

    for(i=low;i<=high;i++)
        arr[i]=b[i];
}

void mergeSort(int* arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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

    mergeSort(arr,0,n-1);

   printf("After sorting the elements are:");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);

    return 0;
}
