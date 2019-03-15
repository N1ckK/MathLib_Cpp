#include "math.h"

/*
    === abs ===
    returns the absolute value of a given integer
*/
float math::abs(float a){
    return (a >= 0) ? a : -a;
}

/*
    === min ===
    returns the smaller number of given integers a and b
*/
float math::min(float a, float b){
    return (a <= b) ? a : b;
}

/*
    === min ===
    returns the bigger number of given integers a and b
*/
float math::max(float a, float b){
    return (a >= b) ? a : b;
}

/*
    === sign ===
    TODO
*/
int sign(auto x){
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

/*
    === factorial ===
    iteratively calculates n factorial
*/
long double math::factorial(int n){
    int prod = 1;
    for (int i = 2 ; i <= n ; i++) prod *= i;
    return prod;
}

/*
    === power ===
    raises any decimal number x to the power of any decimal a. If a is
    an integer greater or equal than one, the power will be iteratively
    calculated by continous multiplication. If "a" is a decimal number but
    greater than one, the largest integer less than a is calculated of
    which the power is calculated as explained obove. The difference
    between the integer and the decimal is then calculated by
    exp( a - (int) a log_e(x) ) and multiplied to the result.
*/
double math::power(double x, double a){
    int n = (int) a;
    double prod = 1;
    if (n > 0){
        prod = x;
        while (n != 1){
            if (n % 2 == 0){
                prod = prod * prod;
                n = n / 2;
            }else{
                prod = prod * prod * prod;
                n = (n-1) / 2;
            }
        }
    }
    if (a - (int) a != 0 && (int) a > 0){
        prod *= math::exp((a - (int) a) * math::ln(x));
    }else if ((int) a < 0){
        prod *= math::exp((a) * math::ln(x));
    }
    return prod;
}

/*
    === round ===
    rounds the given decimal to an integer where as .5 yields the next bigger
    integer.
*/
int math::round(auto x){
    float diff = x - (int) x;
    return (diff >= 0.5) ? (int) x + 1 : (int) x;
}

/*
    === exp ===
    returns the value of the exponential function by creating the taylor
    polynomial with given iterations.
*/
long double math::exp(long double x, unsigned iterations){
	auto sum = 1.0l;
	auto summand = 1.0l;

	for (unsigned i = 1 ; i <= iterations; ++i){
		summand = summand * x / i;
		sum += summand;
	}
	return sum;
}

/*
    === natlog_taylor ===
    returns the value of (x-1) the taylor polynomial log_e(x+1) with
    given iterations. The taylor polynomial will only converger for
    values -1 <= x <= 1. As a result, only x with 0 <= x <= 2 will yield
    effective results.
*/
long double natlog_taylor(long double x, unsigned iterations = 100){
    // 0 <= x < 2
    auto sum = 0.0l;
    auto summand = (x - 1);
    for (unsigned i = 2 ; i <= iterations; i++){
        sum += summand;
        summand = summand * (x - 1) * (-1) * (i-1) / i;
    }
    return sum;
}

/*
    === ln ===
    returns the value at x of the natural logarithm with given iterations.
    x is thereby unrestricted. x is thereby rewritten in a quotiens of
    two numbers between 0 and 2. the difference of the logarithm yielded by
    the taylor polynomial is the wanted value.
*/
long double math::ln(long double x, unsigned iterations){
    auto num = 1 + (x-1)/(1+x), den = 1 - (x-1)/(1+x);
    return natlog_taylor(num, iterations) - natlog_taylor(den, iterations);
}

/*
    === log ===
    returns the value at x of the logarithm to a given base. x is thereby
    unrestricted. this function uses the rule that log_a(x) = log(x)/log(a)
*/
long double math::log(long double x, int base){
    return 1 / math::ln(base) * math::ln(x);
}

/*
    === root ===
    returns the value of the n-th root of x by calulating x^(1/n)
*/
long double math::root(long double x, int n){
    return math::exp((float) 1/n * math::ln(x));
}

/*
    === mod ===
    returns the result uf n modulo m. by finding the largest sum of m smaller
    than n. Note than m has to be positive. Calling this function with zero
    or a negative number will raise a runtime error.
*/
long double math::mod(float n, float m){
    float m1 = 0;
    while (n >= m1){
        m1 += m;
    }
    return n - m1 + m;
}

/*
    == sin_taylor ===
    returns the value at x of the taylor polynomial of sin(x) with given
    iterations.
*/
long double sin_taylor(long double x, unsigned iterations){
    auto sum = 0.0l, summand = x;
    for (unsigned i = 3 ; i <= iterations ; i += 2){
        sum += summand;
        summand = summand * (-1) * x / i * x / (i - 1);
    }
    return sum;
}

/*
    === sin ===
    returns the value of sin(x) with given iterations (precision). x is
    thereby unrestricted. Due to sin being a repetitive function, the given x
    is translated to an x' with 0 <= x' < pi and abs(sin(x)) = abs(sin(x'))
    of which the value of sin(x) is then deduced.

*/
long double math::sin(long double x, unsigned iterations){
    long double val = sin_taylor(sign(x) * mod(abs(x), math::PI), iterations);
    return (mod(x, 2 * math::PI) - mod(x, math::PI) < 0.1) ? val : -val;
}

/*
    === cos ===
    returns the value of cos(x) with given iterations (precision). x is
    thereby unrestricted. This function uses cos(x) = sin(x + PI/2)
*/
long double math::cos(long double x, unsigned iterations){
    return math::sin(x + math::PI / 2, iterations);
}

/*
    === tan ===
    returns the value of tan(x) with given iterations (precision). x is
    thereby unrestricted. This function uses tan(x) = sin(x) / cos(x)
*/
long double math::tan(long double x, unsigned iterations){
    return math::sin(x, iterations) / math::cos(x, iterations);
}

long double arcsin(){
    // todo
}

long double arccos(){
    // todo
}

long double arctan(){
    // todo
}


/*
    === gcd ===
    Todo
*/
int math::gcd(int a, int b){
    int d = 0;
    while (a % 2 == 0 && b % 2 == 0){
        a /= 2;
        b /= 2;
        d += 1;
    }
    while (a != b){
        if (a % 2 == 0) a /= 2;
        else if (b % 2 == 0) b /= 2;
        else if (a > b) a = (a - b)/2;
        else b = (b - a) / 2;
    }
    return a;

}

/*
    === lcm ===
    Todo
*/
int math::lcm(int a, int b){
    return abs(a * b)/ math::gcd(a, b);
}

/*
    === nCr ===
    Todo
*/
int math::nCr(int n, int k){
    if (k > n) return 0;
    else if (k == 0) return 1;
    else return nCr(n - 1, k - 1) + nCr(n - 1, k);
}
