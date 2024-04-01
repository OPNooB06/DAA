#include <iostream>
using namespace std;
void countsort(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int count_arr[max+1]={0};
    for(int i=0;i<size;i++){
        count_arr[arr[i]]++;
    }
    for(int i=1;i<max+1;i++){
        count_arr[i]=count_arr[i]+count_arr[i-1];
    }
    int sorted_arr[size];
    for(int i=size-1;i>=0;i--){
        int index=count_arr[arr[i]]-1;
        sorted_arr[index]=arr[i];
        count_arr[arr[i]]--;
    }
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<sorted_arr[i]<<endl;
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
    countsort(arr,n);
}
