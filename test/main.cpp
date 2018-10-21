#include<iostream>
#include<typeinfo>
using namespace std;


template<typename T>
struct A{
    void f();
};
template<typename T>
void A<T>::f(){cout << typeid(A<T>).name() << endl;}

int main()
{
    A<int> a;
    a.f();
}
