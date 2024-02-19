#include <iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        if(minindex!=i){
            swap(arr[minindex],arr[i]);
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
    selectionsort(arr,n);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}