#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tensor.h"

int main(int argc, char *argv[])
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    Tensor *b = ones(55000);
    Tensor *a = ones(55000);
    Tensor *c = tensor_add(a, b);

    float c_sum = tensor_sum(c);
    float c_norm = tensor_frobenius_norm(c);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("C Norm = %f\n", c_norm);
    printf("C Sum = %f\n", c_sum);
    printf("Time taken = %f seconds\n", cpu_time_used);
}