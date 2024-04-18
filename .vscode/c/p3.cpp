#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cout<<"size of the array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>freqmap;
    for(int i=0;i<n;i++){
        freqmap[arr[i]]++;
    }
    cout<<"freq"<<endl;
    for(auto it=freqmap.begin();it!=freqmap.end();it++){
        cout<<it->first<<": "<<it->second<<endl;
    }
    return 0;
}