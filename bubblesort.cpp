#include <iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=n;i>=0;i--){
        for(int j=0;j<i-1;j++){
            if(arr[j]>arr[j+1]){
               swap(arr[j+1],arr[j]);
            }
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
    bubblesort(arr,n);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}