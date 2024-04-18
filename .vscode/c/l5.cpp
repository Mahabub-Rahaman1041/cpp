#include<iostream>
using namespace std;
bool ispalindrome(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<end){
        if(arr[start]!=arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main(){
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(ispalindrome(arr,n)){
        cout<<"palindrome";
    }else{
        cout<<"not palindrome";
    }
    return 0;
}