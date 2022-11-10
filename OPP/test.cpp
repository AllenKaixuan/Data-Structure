/*
类模板与运算符重载
注意：调试时对于同一种运算符两种重载方式不能同时出现
*/
#include <iostream>
using namespace std;
template <class T>
class complex
{
public:
    complex() = default;
    complex(T, T);
    complex<T> operator+(complex<T>);

    // 类模板的友元操作符重载,内联
    friend complex<T> operator-(complex<T> cmpl1, complex<T> cmpl2)
    {
        complex<T> cmpl3;
        cmpl3.a = cmpl1.a - cmpl2.a;
        cmpl3.b = cmpl1.b - cmpl2.b;
        return cmpl3;
    }

    // friend ostream &operator<<(ostream &out, complex<T> cmpl)  // 不能同时出现，需要注释掉
    // {
    //     out << cmpl.a << "+" << cmpl.b << "i" << endl;
    //     return out;
    // }

    friend istream &operator>>(istream &in, complex<T> cmpl)
    {
        in >> cmpl.a >> cmpl.b;
        return in;
    }

    complex<T> &operator=(complex<T>);
    void output(ostream &);

private:
    T a;
    T b;
};
template <class T>
complex<T>::complex(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
void complex<T>::output(ostream &out)
{
    out << "(" << this->a << "," << this->b << ")" << endl;
}

template <class T>
ostream &operator<<(ostream &out, complex<T> cmpl) // 以类成员函数的方式重载<<
{
    cmpl.output(out);
    return out;
}

template <class T>
complex<T> complex<T>::operator+(complex<T> cmpl) // 注意类型参数T的位置，所有类（对象）都要实例化
{
    complex temp;
    temp.a = this->a + cmpl.a;
    temp.b = this->b + cmpl.b;
    return temp;
}

template <class T>
complex<T> &complex<T>::operator=(complex<T> cmpl)
{
    this->a = cmpl.a;
    this->b = cmpl.b;
    return *this;
}

int main()
{
    complex<int> cmpl1(3, 5); // 指明参数类型
    complex<int> cmpl2(2, 6);
    cout << cmpl1 - cmpl2;
    cout << cmpl1 + cmpl2;
    cout << cmpl1;
}