#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

int main(int argc, char *argv[])
{
    Tensor *b = ones(3);
    Tensor *a = ones(3);
    b->show(b);
    a->show(a);

    Tensor *c = tensor_add(a, b);
    c->show(c);

    Tensor *d = tensor_add(c, c);
    d->show(d);

    float prod = tensor_product(c, d);
    float frob_norm = tensor_frobenius_norm(d);

    printf("%f frob norm", frob_norm);
}