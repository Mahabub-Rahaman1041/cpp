#include <iostream> 
using namespace std; 

int main(){

int N, newPos, New, delpos, del;

cout << "\n Enter the number of clements:-";
cin>>N; 
int arry [N];

for (int i=0; i<N; i++){

cout<<"Enter"<<i<<"th element:";
cin>> arry avery [i];
}
cout<<"\n enter position to be deleted";
cin>>delpos;
int size=N;
if(delpos>0 && delpos<N){
for (int i=delpos;i<size;i++){
    arry[i]=arry[i+1];
}
size--;
else{
    cout<<"invalid position\n";
}
return 0;
}