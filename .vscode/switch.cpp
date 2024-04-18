#include <iostream>
using namespace std;
int main(){
    char button;
    cout<<"input a character(a to e):";
    cin>>button;
    switch (button){
        case 'a':
        cout<<"aria";
        break; 
        case 'b':
        cout<<"i love you";
        break;
         case 'c':
        cout<<"i miss you";
        break;
         case 'd':
        cout<<"do you love me?";
        break;
         case 'e':
        cout<<"i like you";
        break;
        default:
        cout<<"love you extream";
        break;
        }return 0;
}