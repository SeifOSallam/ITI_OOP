#include <iostream>

using namespace std;

class Complex {
    int real;
    int imaginary;

public:
    Complex(){}
    Complex(int real,int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    void setReal(int real) {
        this->real = real;
    }
    int getReal() {
        return real;
    }
    void setImaginary(int imaginary) {
        this->imaginary = imaginary;
    }
    int getImaginary() {
        return imaginary;
    }
    /*void print(){
        cout<<"Number = "<<real<<" ";
        if (imaginary > 0) {
            cout<<"+ "<<imaginary<<"j"<<endl;
        }
        else if (imaginary < 0) {
            cout<<"- "<<(imaginary*(-1))<<"j"<<endl;
        }
        else cout<<endl;
    }*/
    void print(void);
    Complex addComplex(Complex c) {
        Complex res;
        res.real = this->real + c.real;
        res.imaginary = this->imaginary + c.imaginary;
        return res;
    }
    Complex operator + (Complex& c) {
        real+=c.real;
        imaginary+=c.imaginary;
        return *this;
    }
    Complex operator + (int x) {
        real+=x;
        return *this;
    }
    Complex operator - (Complex& c) {
        real-=c.real;
        imaginary-=c.imaginary;
        return *this;
    }
    Complex operator * (Complex& c) {
        real*=c.real;
        imaginary*=c.imaginary;
        return *this;
    }
    Complex operator / (Complex& c) {
        if (c.real != 0)
            real/=c.real;
        if (c.imaginary != 0)
            imaginary/=c.imaginary;
        return *this;
    }
    Complex operator ++ () {
        real++;
        imaginary++;
        return *this;
    }
    Complex operator ++ (int) {
        Complex temp = *this;
        real++;
        imaginary++;
        return temp;
    }
    Complex operator -- () {
        real--;
        imaginary--;
        return *this;
    }
    Complex operator -- (int) {
        Complex temp = *this;
        real--;
        imaginary--;
        return temp;
    }
    int operator == (Complex& c) {
        return (real == c.real && imaginary == c.imaginary);
    }
    int operator [] (int i) {
        if (i == 0) return real;
        else if (i == 1) return imaginary;
        else return -1;
    }
    int operator [] (string s) {
        if (s == "real") {
            return real;
        }
        else if (s == "imaginary") {
            return imaginary;
        }
        else return -1;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
    operator += (Complex& c) {
        real+=c.real;
        imaginary+=c.imaginary;
    }
    operator float() {
        return (float)real;
    }
    friend Complex subComplex(Complex c1, Complex c2);
};
Complex subComplex(Complex c1,Complex c2) {
    Complex res;
    res.real = c1.real - c2.real;
    res.imaginary = c1.imaginary - c2.imaginary;
    return res;
}

void Complex::print(void) {
    cout<<"Number = "<<real<<" ";
    if (imaginary > 0) {
        cout<<"+ "<<imaginary<<"j"<<endl;
    }
    else if (imaginary < 0) {
        cout<<"- "<<(imaginary*(-1))<<"j"<<endl;
    }
    else cout<<endl;
}

Complex operator + (int x, Complex& c) {
    Complex temp;
    temp.setReal(x+c.getReal());
    temp.setImaginary(x+c.getImaginary());
    return temp;
}
Complex operator - (int x, Complex& c) {
    Complex temp;
    temp.setReal(c.getReal()-x);
    temp.setImaginary(c.getImaginary()-x);
    return temp;
}

void print(Complex c) {
    cout<<"Number = "<<c.getReal()<<" ";
    if (c.getImaginary() > 0) {
        cout<<"+ "<<c.getImaginary()<<"j"<<endl;
    }
    else if (c.getImaginary() < 0) {
        cout<<"- "<<(c.getImaginary()*(-1))<<"j"<<endl;
    }
    else cout<<endl;
}
Complex addComplex(Complex c1, Complex c2) {
    Complex res;
    res.setReal(c1.getReal() + c2.getReal());
    res.setImaginary(c1.getImaginary() + c2.getImaginary());
    return res;
}
ostream & operator << (ostream &out, const Complex &c)
{
    out<<"Number = "<<c.real<<" ";
    if (c.imaginary > 0) {
        out<<"+ "<<c.imaginary<<"j"<<endl;
    }
    else if (c.imaginary < 0) {
        out<<"- "<<(c.imaginary*(-1))<<"j"<<endl;
    }
    else out<<endl;
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imaginary;
    return in;
}

int main()
{
    Complex c1(3,5);
    Complex c2(6,-10);
    Complex c3(10,20);
    c1+=c2;
    c1.print();
    cout<<(float)c1<<endl;
    cout<<c1[1]<<endl;
    cout<<"C1 REAL:"<<(c1["real"])<<endl;
    Complex c4;
    cin>>c4;
    cout<<c4;
}
