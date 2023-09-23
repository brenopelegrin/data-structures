#define FLAG_ERROR_CANT_DIVIDE_BY_ZERO -1
#define FLAG_SUCCESS 1
#define PRECISION 1.0E-14
#define ISCLOSE(a,b) (fabs(a,b)<PRECISION)

typedef struct complex{
    double real;
    double imaginary;
    double modulus;
} Complex;

Complex createComplex(double *real, double *imaginary);
Complex getConjugate(Complex *a);
double getReal(Complex *a);
double getModulus(Complex *a);
void calculateModulus(Complex *a);

void add(Complex *a, Complex *b, Complex *result);
void subtract(Complex *a, Complex *b, Complex *result);
void multiply(Complex *a, Complex *b, Complex *result);
int divide(Complex *a, Complex *b, Complex *result);