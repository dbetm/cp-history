//Operator Overloading

#include<iostream>

using namespace std;

class Complex {
public:
    int a,b;
    void input(string s) {
        int v1 = 0;
        int i = 0;
        while(s[i]!='+') {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i') {
            i++;
        }
        int v2=0;
        while(i<s.length()) {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
// https://www.hackerrank.com/challenges/overload-operators/problem
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
#include <string>

Complex operator +(Complex x, Complex y) {
    Complex z;
    string res = to_string(x.a + y.a) + "+"; // parte real
    res += to_string(x.b + y.b);
    z.input(res);
    return z;
}

ostream& operator <<(ostream& output, Complex c) {
    output << c.a << "+i" << c.b;
    return output;
}

int main() {
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
