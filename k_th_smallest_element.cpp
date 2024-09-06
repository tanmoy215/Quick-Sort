#include<iostream>
using namespace std;

//Pertition Algorithm


int pertition(int arr[], int st, int ed){
    int pivotElement = arr[st];
    int count=0;
    for(int i=st+1;i<=ed;i++){
        if(arr[i]<=pivotElement) count++;
    }
    int pivotIdx=st+count;
    swap(arr[pivotIdx],arr[st]);
    int i=st;
    int j=ed;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>=pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

//finding the k-th element

int kth_smallest(int arr[],int st, int ed,int k){
 int pi = pertition(arr,st,ed);
 if(pi+1==k) return arr[pi];
 else if(pi+1<k) return kth_smallest(arr,pi+1,ed,k);
 else return kth_smallest(arr,st,pi-1,k);
}

//Quick sort Algorithm


// void quicksort(int arr[], int st, int ed){
//     //base case
//     if(st>=ed) return;
//     int pi = pertition(arr,st,ed);                   //not a mandatory
//     quicksort(arr,st,pi-1);
//     quicksort(arr,pi+1,ed);
// }
int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(int);
    //unsorted Array
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // quicksort(arr,0,n-1);
    // //final Array
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    int k=2;
    cout<<endl<<"Kth Smallest Element : "<<kth_smallest(arr,0,n-1,k);
}