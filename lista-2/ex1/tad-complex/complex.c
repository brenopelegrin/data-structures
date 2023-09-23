#define FLAG_ERROR_CANT_DIVIDE_BY_ZERO -1
#define FLAG_SUCCESS 1
#define PRECISION 1.0E-14
#define CLOSE(a,b) (fabs(a-b)<PRECISION)

#include <math.h> 
#include "complex.h"

Complex createComplex(double *real, double *imaginary){
    Complex result;
    result.real = *real;
    result.imaginary = *imaginary;
    calculateModulus(&result);
    return result;
}

Complex getConjugate(Complex *a){
    Complex result;
    result.real = a->real;
    result.imaginary = -(a->real);
    calculateModulus(&result);
    return result;
}

double getReal(Complex *a){
    return a->real;
}

double getImaginary(Complex *a){
    return a->imaginary;
}

double getModulus(Complex *a){
    return a->modulus;
}

void calculateModulus(Complex *a){
    a->modulus = sqrt(pow(a->real,2)+ pow(a->imaginary,2));
    return;
}

/* Still need to think if these setter functions should be implemented.
    The complex numbers shouldn't be modifiable after creation.
void setReal(Complex *a, double *real){
    a->real = *real;
    calculateModulus(a);
    return;
}

void setReal(Complex *a, double *imaginary){
    a->imaginary = *imaginary;
    calculateModulus(a);
    return;
}
*/

void add(Complex *a, Complex *b, Complex *result){
    result->real = a->real + b->real;
    result->imaginary = a->imaginary + b->imaginary;
    calculateModulus(result);
    return;
}

void subtract(Complex *a, Complex *b, Complex *result){
    result->real = a->real - b->real;
    result->imaginary = a->imaginary - b->imaginary;
    calculateModulus(result);
    return;
}

void multiply(Complex *a, Complex *b, Complex *result){
    result->real = (a->real)*(b->real) - (a->imaginary)*(b->imaginary);
    result->imaginary  = (a->real)*(b->imaginary) + (b->real)*(a->imaginary);
    calculateModulus(result);
    return;
}

int divide(Complex *a, Complex *b, Complex *result){
    double modulus = getModulus(b);
    if(CLOSE(modulus, 0.0)){
        return FLAG_ERROR_CANT_DIVIDE_BY_ZERO;
    }
    else{
        result->real = ( (a->real)*(b->real) - (a->imaginary)*(b->imaginary) )/(pow(b->real, 2) + pow(b->imaginary, 2) );
        result->imaginary = ( (a->imaginary)*(b->real) - (a->real)*(b->imaginary) )/(pow(b->real, 2) + pow(b->imaginary, 2) );
        calculateModulus(result);
        return FLAG_SUCCESS;
    }
}

