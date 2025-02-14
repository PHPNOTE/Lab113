#include <stdio.h>

struct complex{
    float real;
    float imag;
};

struct complex add_complex(struct complex a, struct complex b){
    struct complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

struct complex multiply_complex(struct complex a, struct complex b){
    struct complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}    
void print_complex(char *str, struct complex a){
    printf("%s", str);
    float imag = a.imag, real = a.real;

    if (imag == 0 && real == 0){
        printf(" 0.0\n");
        return;
    }
    if (real == 0){
        printf("%.1fi",imag);
    }else if (real != 0){
        printf("%.1f", real);
        if (imag < 0){
            printf(" - %.1fi", imag * (-1));
        }else if (imag == 0){
            printf("\n");
            return;
        }else if(imag > 0){
            printf(" + %.1fi",imag);
        }
    }

    printf("\n");
}
int main(){
    struct complex C, D, E, F;

    printf("Enter C: ");
    scanf("%f %f", &C.real, &C.imag);
    printf("Enter D: ");
    scanf("%f %f", &D.real, &D.imag);

    E = add_complex(C, D);
    F = multiply_complex(C, D);

    print_complex("C + D = ", E);
    print_complex("C x D = ", F);

    return 0;
}