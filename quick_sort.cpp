#include<iostream>
using namespace std;
int pertition(int arr[],int st, int ed){
    int pivotElement = arr[st];
    int idx =0;
    for(int i=st+1;i<=ed;i++){
        if(arr[i]<=pivotElement) idx++;
    }
    int pivotIdx = idx+st;
    swap(arr[st],arr[pivotIdx]);
    int i=st;
    int j=ed;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>=pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;     
}
void quicksort(int arr[],int st, int ed){
    if(st>=ed) return; //Base Case
    int pi = pertition(arr,st,ed);
    quicksort(arr,st,pi-1);
    quicksort(arr,pi+1,ed);
}
int main(){
    int arr[]={1,5,2,7,9,3,7,3,0};
    int n=sizeof(arr)/sizeof(int);
    cout<<"Before Quick Sort : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     quicksort(arr,0,n-1);
    cout<<endl<<"After Quick sort : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}