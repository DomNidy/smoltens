#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

int main(int argc, char *argv[])
{
    Tensor* b = zeros(3);
    b->show(b);
}