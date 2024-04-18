#include <iostream>
using namespace std;
voidmerge(int arr[],int n,int m,int arr2[],merged[]){
    it i=0;j=0;k=0;
    while(i<n && j<m){
        if (arr[i]<arr2[j]){
            merged[k++]=arr[i++];
        }else{
            merged[k++]=arr2[j++];
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int merged[n+m];
    merge(arr;n;arr2;m;merge)
    for(int i=0;i<n+m;i++){
        cout<<merged[i];
    }
    return 0;
}