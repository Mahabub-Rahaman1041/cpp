#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_set<int>uniqueelement;
    for(int i=0;i<n;i++){
        uniqueelement.insert(arr[i]);
    }
    cout<<"final"<<endl;
    for(auto it=uniqueelement.begin();it!=uniqueelement.end();++it){
        cout<<*it<<" "<<endl;
    }
    return 0;
}