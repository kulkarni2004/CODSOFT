#include<iostream>
using namespace std;

int main(){
    int a,b;
    char op;
    cout<<"Enter the value of first operand:";
    cin>>a;

    cout<<"Enter the value of second operand:";
    cin>>b;

    cout<<"Enter the operand you want to perform:";
    cin>>op;

    switch(op){
        case '+':cout<<"Addition of two operand is:"<<(a+b)<<endl;
        break;

        case '-':cout<<"Subtraction of two operand is:"<<(a-b)<<endl;
        break;

        case '*':cout<<"Multiplication of two operand is:"<<(a*b)<<endl;
        break;

        case '/':cout<<"Division of two operand is:"<<(a/b)<<endl;
        break;

        case '%':cout<<"Modulus of two operand is:"<<(a%b)<<endl;
        break;
    }
}