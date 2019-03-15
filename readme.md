
## math.h

~~~~
namespace math{
    /* The constant PI*/
    const double PI = 3.14159265359;

    /* Returns the absolute value of a,b*/
    float abs(float a);

    /* Returns the maximum of a,b */
    float min(float a, float b);

    /* Returns the minimum of a,b */
    float max(float a, float b);

    /* Returns n factorial */
    long double factorial(int n);

    double power(double x, double a);

    /* Rounds x to the nearest integer 2.4 -> 2 , 2.5 -> 3 */
    int round(int x);

    /* Returns the value of exp(x). iterations determines the precision. */
    long double exp(long double x, unsigned iterations = 70);

    /* Returns the value of log_e(x).*/
    long double ln(long double x, unsigned iterations = 90);

    /* Returns the value of log_base(x).*/
    long double log(long double x, int base = 10);

    /* Returns the n-th root of x*/
    long double root(long double x, int n = 2);

    /* Returns sin(x) */
    long double sin(long double x, unsigned iterations = 30);

    /* Returns cos(x) */
    long double cos(long double x, unsigned iterations = 30);

    /* Returns tan(x) */
    long double tan(long double x, unsigned iterations = 45);

    /* Returns n modulo m*/
    long double mod(float n, float m);

    /* Returns the greatest common division of a and b */
    int gcd(int a, int b);

    /* Returns the lowest common multiple of an and b */
    int lcm(int a, int b);

    /* returns the binomial coefficient of n over k */
    int nCr(int n, int k);
}
~~~~
