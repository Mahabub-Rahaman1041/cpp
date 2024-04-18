#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos,num,a;
    cout<<" insertion(1) or deletion(0) ";
    cin>>a;
    if(a==1){
    cout<<"enter the pos and num  "<<endl;
    cin>>pos>>num;
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=num;
    n++;
    cout<<"after insertion";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    }else{
        cout<<"pos";
        cin>>pos;
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"after deletion";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    }
    return 0;
}