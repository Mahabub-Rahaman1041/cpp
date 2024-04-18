#include<iostream>
using namespace std;
int main(){
    int pocketmoney=2500;
    for(int i=1;i<=30;i++){
        if(i%2==0){
            continue;
        }
        if(pocketmoney==0){
            break;
        }
        cout<<"go with aria\n";
        pocketmoney=pocketmoney-1000;
    }
    return 0;
}