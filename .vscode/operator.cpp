#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    char op;
    cout<<"result ";
    cin>>op;
    switch (op)
    {
    case '+':
    cout<<a+b;
        break;
    case '-':
    cout<<a-b;
        break;
        case '*':
    cout<<a*b;
        break;
        case '/':
    cout<<a/b;
        break;
    default:
    cout<<"unkown operator";
        break;
    }return 0;
}