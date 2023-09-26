#define FLAG_ERROR_CANT_DIVIDE_BY_ZERO -1
#define FLAG_SUCCESS 1
#define PRECISION 1.0E-14
#define ISCLOSE(a,b) (fabs(a,b)<PRECISION)

typedef struct complex{
    double real;
    double imaginary;
    double modulus;
} Complex;

// Operations over one Complex number
// getReal and getModulus returns by value
void createComplexFromCart(double *real, double *imaginary, Complex *result);
void createComplexFromTrig(double *modulus, double *argRad, Complex *result);
void createConjugate(Complex *z, Complex *result);
double getReal(Complex *z);
double getModulus(Complex *z);
void setReal(Complex *z, double *real);
void setImaginary(Complex *z, double *imaginary);
void calculateModulus(Complex *z);

// Operations between two Complex numbers
// Division returns a flag, -1 if error of division by zero, 1 if success
void add(Complex *z1, Complex *z2, Complex *result);
void subtract(Complex *z1, Complex *z2, Complex *result);
void multiply(Complex *z1, Complex *z2, Complex *result);
int divide(Complex *z1, Complex *z2, Complex *result); 
void multiplyByScalar(Complex *z, double *scalar);
