#define FLAG_ERROR_CANT_DIVIDE_BY_ZERO 0
#define FLAG_SUCCESS 1

#include <math.h>

typedef struct Complex{
    double real;
    double imaginary;
    double modulus;
} Complex;

Complex* create(double *real, double *imaginary){
    Complex result;
    result.real = *real;
    result.imaginary = *imaginary;
    updateModulus(&result);
    return &result;
}

double getReal(Complex *a){
    return a->real;
}

double getReal(Complex *a){
    return a->real;
}

double getModulus(Complex *a){
    return a->modulus;
}

void updateModulus(Complex *a){
    a->modulus = sqrt(pow(a->real,2)+ pow(a->imaginary,2));
    return;
}

/* Still need to think if these setter functions should be implemented.
    The complex numbers shouldn't be modifiable after creation.
void setReal(Complex *a, double *real){
    a->real = *real;
    updateModulus(a);
    return;
}

void setReal(Complex *a, double *imaginary){
    a->imaginary = *imaginary;
    updateModulus(a);
    return;
}
*/

void add(Complex *a, Complex *b, Complex *result){
    result->real = a->real + b->real;
    result->imaginary = a->imaginary + b->imaginary;
    return;
}

void subtract(Complex *a, Complex *b, Complex *result){
    result->real = a->real - b->real;
    result->imaginary = a->imaginary - b->imaginary;
    return;
}

int divide(Complex *a, Complex *b, Complex *result);

