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

int lcm(long a, long b) {
    return (a * b) / gcd(a, b); 
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

bool operator<(const Rational& x, const Rational& y) {
  const int lcDenom = lcm(x.Denominator(), y.Denominator());
  return (x.Numerator() * (lcDenom / x.Denominator())) < (y.Numerator() * (lcDenom / y.Denominator()));
}

bool operator>(const Rational& x, const Rational& y) {
  const int lcDenom = lcm(x.Denominator(), y.Denominator());
  return (x.Numerator() * (lcDenom / x.Denominator())) > (y.Numerator() * (lcDenom / y.Denominator()));
}

bool operator==(const Rational& x, const Rational& y) {
  return x.Numerator() == y.Numerator() && x.Denominator() == y.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
