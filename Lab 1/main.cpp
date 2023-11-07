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

int main()
{
    Complex c1;
    Complex c2(6,-10);
    c1.setReal(3);
    c1.setImaginary(5);
    Complex c3 = c1.addComplex(c2);
    c3.print();
    c3 = subComplex(c1,c2);
    c3.print();
}
