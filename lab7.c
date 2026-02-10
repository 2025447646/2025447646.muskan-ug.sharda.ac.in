#include <stdio.h>

// Declaration of data structure
typedef struct {
    float real;
    float imag;
} Complex;

// Function declarations
void input(Complex *c);
void display(Complex c);
Complex Add(Complex a, Complex b);
Complex Sub(Complex a, Complex b);
Complex Mul(Complex a, Complex b);

int main() {
    Complex num1, num2, num3;

    printf("Enter first complex number:\n");
    input(&num1);

    printf("Enter second complex number:\n");
    input(&num2);

    num3 = Add(num1, num2);
    printf("Addition: ");
    display(num3);

    num3 = Sub(num1, num2);
    printf("Subtraction: ");
    display(num3);

    num3 = Mul(num1, num2);
    printf("Multiplication: ");
    display(num3);

    return 0;
}

// Function definitions
void input(Complex *c) {
    printf("Enter real part: ");
    scanf("%f", &c->real);
    printf("Enter imaginary part: ");
    scanf("%f", &c->imag);
}

void display(Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

Complex Add(Complex a, Complex b) {
    Complex r;
    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;
    return r;
}

Complex Sub(Complex a, Complex b) {
    Complex r;
    r.real = a.real - b.real;
    r.imag = a.imag - b.imag;
    return r;
}

Complex Mul(Complex a, Complex b) {
    Complex r;
    r.real = (a.real * b.real) - (a.imag * b.imag);
    r.imag = (a.real * b.imag) + (a.imag * b.real);
    return r;
}