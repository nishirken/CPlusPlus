#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(const string& str, const char& delim) {
  vector<string> acc;
  string temp;
  for (const char& c : str) {
    if (c == delim) {
      acc.push_back(temp);
      temp = "";
      continue;
    }
    temp.push_back(c);
  }
  acc.push_back(temp);
  return acc;
}

int gcd(long a, long b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

class Rational {
    public:
        Rational() {}
        Rational(long newNumerator, long newDenominator) {
            int greatestDenom = gcd(abs(newNumerator), abs(newDenominator));
            numerator = newNumerator / greatestDenom;
            denominator = newDenominator / greatestDenom;

            if ((numerator / denominator) < 0) {
                numerator = -abs(numerator);
                denominator = abs(denominator);
            }
            if (numerator == 0) {
                denominator = 1;
            }
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

ostream& operator<<(ostream& stream, const Rational& x) {
    stream << to_string(x.Numerator()) << "/" << to_string(x.Denominator());
    return stream;
}

istream& operator>>(istream& stream, Rational& x) {
    string temp;
    cin >> temp;
    vector<string> splitted = split(temp, '/');
    x = Rational(stoi(splitted[0]), stoi(splitted[1]));
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
