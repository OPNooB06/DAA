#include <iostream>
using namespace std;
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        int element;
        cout<<"Enter elements: ";
        cin>>element;
        arr[i]=element;
    }
    int l=0;
    int r=n-1;
    quicksort(arr,l,r);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}