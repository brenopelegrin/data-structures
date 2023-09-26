#define FLAG_ERROR_CANT_DIVIDE_BY_ZERO -1
#define FLAG_SUCCESS 1
#define PRECISION 1.0E-14
#define CLOSE(a,b) (fabs(a-b)<PRECISION)

#include <math.h> 
#include "complex.h"

void createComplexFromTrig(double *modulus, double *argRad, Complex *result){
    // Creates Complex number from trigonometric form
    // z = modulus * ( cos(arg) + i sin(arg) )
    result->real = (*modulus)*cos(*argRad);
    result->imaginary = (*modulus)*sin(*argRad);
    calculateModulus(result);
    return;
}

void createComplexFromCart(double *real, double *imaginary, Complex *result){
    // Creates Complex number from cartesian form
    // z = real + i imaginary
    result->real = *real;
    result->imaginary = *imaginary;
    calculateModulus(result);
    return;
}

void createConjugate(Complex *z, Complex *result){
    // Creates conjugate from Complex number
    // z_conj = z_real - z_imaginary
    result->real = z->real;
    result->imaginary = -1.0*(z->imaginary);
    calculateModulus(result);
    return;
}

double getReal(Complex *z){
    return z->real;
}

double getImaginary(Complex *z){
    return z->imaginary;
}

double getModulus(Complex *z){
    return z->modulus;
}

void calculateModulus(Complex *z){
    // Calculates modulus of a Complex number and store in its struct
    z->modulus = sqrt(pow(z->real,2) + pow(z->imaginary,2));
    return;
}

void setReal(Complex *z, double *real){
    z->real = *real;
    calculateModulus(z);
    return;
}

void setImaginary(Complex *z, double *imaginary){
    z->imaginary = *imaginary;
    calculateModulus(z);
    return;
}

void add(Complex *z1, Complex *z2, Complex *result){
    // Adds two Complex numbers
    result->real = z1->real + z2->real;
    result->imaginary = z1->imaginary + z2->imaginary;
    calculateModulus(result);
    return;
}

void subtract(Complex *z1, Complex *z2, Complex *result){
    // Subtracts two Complex numbers
    result->real = z1->real - z2->real;
    result->imaginary = z1->imaginary - z2->imaginary;
    calculateModulus(result);
    return;
}

void multiply(Complex *z1, Complex *z2, Complex *result){
    // Calculates the product between two Complex numbers
    result->real = (z1->real * z2->real) - (z1->imaginary * z2->imaginary);
    result->imaginary  = (z1->real * z2->imaginary) + (z2->real * z1->imaginary);
    calculateModulus(result);
    return;
}

void multiplyByScalar(Complex *z, double *scalar, Complex *result){
    // Calculates the product between a real scalar and a Complex number
    result->real = z->real * (*scalar);
    result->imaginary = z->imaginary * (*scalar);
    return;
}

int divide(Complex *z1, Complex *z2, Complex *result){
    // Calculates the division between two Complex numbers
    // Returns an int flag:
    // Flag -1 means CANT_DIVIDE_BY_ZERO error
    // Flag 1 means SUCCESS
    double denominator = pow(z2->real, 2) + pow(z2->imaginary, 2);
    if(CLOSE(denominator, 0.0)){
        return FLAG_ERROR_CANT_DIVIDE_BY_ZERO;
    }
    else{
        result->real = (z1->real * z2->real + z1->imaginary * z2->imaginary) / denominator;
        result->imaginary = (z2->real * z1->imaginary - z1->real * z2->imaginary) / denominator;
        calculateModulus(result);
        return FLAG_SUCCESS;
    }
}
