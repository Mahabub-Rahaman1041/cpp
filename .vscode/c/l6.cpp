#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i ,j,f=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
            f=1;
            break;
        }
        }
        }
        if(f==0){
            cout<<"asscending";
        }else{
            cout<<"descending";
        }
        return 0;
}

        