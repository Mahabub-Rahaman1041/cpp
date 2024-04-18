#include <iostream>
using namespace std;
int main(){
    int n,i,j,f=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if (arr[i]>arr[j]){
            f=1;
            break;
        }
    }
    }
    if(f==0){
        cout<<"asscending order";
    }else{
        cout<<"not in specific order";
    }
    
    return 0;
    }