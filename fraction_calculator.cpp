#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;
public:
    fraction() : numerator(0), denominator(0)
    {}
    fraction(int num, int den) : numerator(num), denominator(den)
    {}
    void input()
    {
        cout << "Enter the numerator of fraction: "; cin >> numerator;
        cout << "Enter the denominator of fraction: "; cin >> denominator;
        if (denominator == 0)
        {
            cout << "\nThe denominator cannot be zero. Try again.";
            exit(1);
        }
        cout << endl;
    }
    void output()const
    {
        cout << numerator << '/' << denominator << endl;
    }
    fraction operator+(fraction) const;
    fraction operator*(fraction) const;
    fraction operator-(fraction) const;
    fraction operator/(fraction) const;
    void lowterms();
};

fraction fraction::operator+(fraction fr2) const
{
    int num = numerator * fr2.denominator + fr2.numerator * denominator;
    int den = denominator * fr2.denominator;
    return fraction(num, den);
}

fraction fraction::operator*(fraction fr2) const
{
    int num = numerator * fr2.numerator;
    int den = denominator * fr2.denominator;
    return fraction(num, den);
}

fraction fraction::operator-(fraction fr2) const
{
    int num = numerator * fr2.denominator - fr2.numerator * denominator;
    int den = denominator * fr2.denominator;
    return fraction(num, den);
}

fraction fraction::operator/(fraction fr2) const
{
    int num = numerator * fr2.denominator;
    int den = denominator * fr2.numerator;
    return fraction(num, den);
}

void fraction::lowterms()
{
    long tnum, tden, temp, gcd;
    tnum = labs(numerator);
    tden = labs(denominator);
    if (tden == 0)
    {
        cout << "Invalid denominator!"; exit(1);
    }
    else if (tnum == 0)
    {
        numerator = 0; denominator = 1; return;
    }
    //нахождение обшего делителя 
    while (tnum != 0)
    {
        if (tnum < tden)
        {
            temp = tnum; tnum = tden; tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

int main()
{
    cout << "\tFraction calculator" << endl;
    fraction frac1, frac2, frac3;
    char ch='a';
    do
    {
        cout << "\nEntering the first fraction: " << endl;
        frac1.input();
        cout << "\nEntering the second fraction: " << endl;
        frac2.input();
        
        cout << "Enter the sign of a mathematical operation: ";
        cin >> ch;
       
        switch (ch)
        {
            case '+': frac3=frac1+frac2; break;
            case '-': frac3=frac1-frac2; break;
            case '*': frac3=frac1*frac2; break;
            case '/': frac3=frac1/frac2; break;
        }
        frac3.lowterms();
        frac3.output();
        cout << "Proceed? (Y/N) "; 
        ch=_getche();
    } while (ch != 'N');

    cout << endl;
    system("Pause");
    return 0;
}
