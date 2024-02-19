#include <iostream>
using namespace std;
void buildmax(int arr[],int treesize, int current_i){
    int left=2*current_i+1;
    int right=2*current_i+2;
    int largest = current_i;
    if (left < treesize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < treesize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != current_i) {
        swap(arr[current_i], arr[largest]);
        buildmax(arr, treesize, largest);
    }
}
void heapify(int arr[],int treesize){
    for(int i=treesize/2-1;i>=0;i--){
        buildmax(arr,treesize,i);
    }
}
void heapsort(int arr[],int treesize){
    heapify(arr,treesize);
    cout<<"Max Heap: "<<endl;
    for(int i=0;i<treesize;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=treesize-1;i>=0;i--){
        swap(arr[0],arr[i]);
        buildmax(arr,i,0);
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
    int i=0;
    heapsort(arr,n);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}