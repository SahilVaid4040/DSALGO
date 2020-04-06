#include <iostream>
using namespace std;
class Complex{
private:
int real;
int imaginary;
public:
Complex()
{
    real =0;
    imaginary =0;
}
Complex(int r1,int i1)
{
    real = r1;
    imaginary =i1;
}
Complex(Complex &C)
{
    real = C.real;
    imaginary = C.imaginary;
}
void Set_Real(int r1)
{
    real =r1;
}
void Set_Imaginary(int i1){
  imaginary = i1;
}
void print()
{
    if(imaginary>0)
    cout<<real<<" + "<<imaginary<<"i"<<endl;
    else if(imaginary<0)
    cout<<real<<" - "<<-imaginary<<"i"<<endl;
    else
    cout<<real<<endl;
}
void operator +(Complex &C)
{
    real+=C.real;
    imaginary+=C.imaginary;
}
void operator !(){
    imaginary*=-1;
}
void operator [](char *c)
{
    if(c=="Make it real")
    imaginary =0;
}

    
};
void operator <<(ostream &os,Complex &C)
{
    C.print();
}
//Return type changed to istream & so that we can input two complex no in 1 statement
//it will first input the first complexx no then return istream which will input second one
//Cascading of operators same can be done for +(like C1+C2+C3) by changong return type to complex
istream & operator >>(istream &is,Complex &C)
{
    int r1;
    int i1;
    is>>r1>>i1;
    C.Set_Real(r1);
    C.Set_Imaginary(i1);
    return is;
}
int main() {
    Complex c1(5,3);
    Complex c2;
    c2.Set_Imaginary(4);
    c2.Set_Real(1);
    c1.print();
    c2.print();
    c1+c2;
    c1.print();
    c2.print();
    !c1;
    c1.print();
    c1["Make it real"];
    c1.print();
    Complex d1,d2;
    cin>>d1>>d2;
    cout<<d1;
    cout<<d2;
    return 0;
}
