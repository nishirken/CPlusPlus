#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int gcd(long a, long b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

class Rational {
    public:
        Rational() {
            numerator = 0;
            denominator = 1;
        }
        Rational(long newNumerator, long newDenominator) {
            if (newNumerator == 0) {
                numerator = 0;
                denominator = 1;
                return;
            }

            int greatestDenom = gcd(abs(newNumerator), abs(newDenominator));
            numerator = newNumerator / greatestDenom;
            denominator = newDenominator / greatestDenom;

            if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
                numerator = -abs(numerator);
            } else {
                numerator = abs(numerator);
            }
            denominator = abs(denominator);
        }

        int Numerator() const {
            return numerator;
        }

        int Denominator() const {
            return denominator;
        }
    private:
        int numerator = 0;
        int denominator = 1;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
