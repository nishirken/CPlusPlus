#include <iostream>
using namespace std;

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

class Rational {
    public:
        Rational() {}
        Rational(int newNumerator, int newDenominator) {
            if ((numerator / denominator) < 0) {
                numerator = -abs(numerator);
                denominator = abs(denominator);
            }
            if (numerator == 0) {
                denominator = 1;
            }

            int greatestDenom = gcd(newNumerator, newDenominator);
            numerator = newNumerator / greatestDenom;
            denominator = newDenominator / greatestDenom;
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

bool operator==(const Rational& x, const Rational& y) {
  return x.Numerator() == y.Numerator() && x.Denominator() == y.Denominator();
}

Rational operator+(const Rational& x, const Rational& y) {
  if (x.Denominator() == y.Denominator()) {
    return Rational(x.Numerator() + y.Numerator(), x.Denominator());
  }
  return Rational(
    x.Numerator() * y.Denominator() + y.Numerator() * x.Denominator(),
    x.Denominator() * y.Denominator()
  );
}

Rational operator-(const Rational& x, const Rational& y) {
  if (x.Denominator() == y.Denominator()) {
    return Rational(x.Numerator() + y.Numerator(), x.Denominator());
  }
  return Rational(
    x.Numerator() * y.Denominator() - y.Numerator() * x.Denominator(),
    x.Denominator() * y.Denominator()
  );
}

Rational operator*(const Rational& x, const Rational& y) {
  return Rational(
    x.Numerator() * y.Numerator(),
    x.Denominator() * y.Denominator()
  );
}

Rational operator/(const Rational& x, const Rational& y) {
  return Rational(
    x.Numerator() * y.Denominator(),
    x.Denominator() * y.Numerator()
  );
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
