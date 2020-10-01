#include<cstdint>
class Fraction {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs){
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
    }
    Fraction& operator=(const Fraction& rhs);
    Fraction(int64_t numerator, uint64_t denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    //  Add operator overloads below
    Fraction operator+(const Fraction& b){
        Fraction sum(1, 1);
        sum.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
        sum.denominator = this->denominator * b.denominator;
        return sum;
    }
    Fraction& operator+=(const Fraction& a){
        this->numerator = this->numerator * a.denominator + a.numerator * this->denominator;
        this->denominator *= a.denominator;
        return *this;
    }
    Fraction operator-(){
        Fraction neg(1, 1);
        neg.numerator = -(this->numerator);
        neg.denominator = this->denominator;
        return neg;
    }
    Fraction operator-(const Fraction& b){
        Fraction diff(1, 1);
        diff.numerator = this->numerator * b.denominator - b.numerator * this->denominator;
        diff.denominator = this->denominator * b.denominator;
        return diff;
    }
    Fraction& operator-=(const Fraction& a){
        this->numerator = this->numerator * a.denominator - a.numerator * this->denominator;
        this->denominator = this->denominator * a.denominator;
        return *this;
    }
    Fraction operator*(const Fraction& b){
        Fraction prod(1, 1);
        prod.numerator = this->numerator * b.numerator;
        prod.denominator = this->denominator * b.denominator;
        return prod;
    }
    Fraction& operator*=(const Fraction& a){
        this->numerator = this->numerator * a.numerator;
        this->denominator = this->denominator * a.denominator;
        return *this;
    }
};