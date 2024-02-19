#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1]){
            swap(arr[j+1],arr[j]);
            j=j-1;
        }
       
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
    insertionsort(arr,n);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}