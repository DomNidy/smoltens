#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>

void show(Tensor *tensor)
{
    printf("[");
    for (int i = 0; i < tensor->elementCount - 1; i++)
    {
        printf("%f, ", tensor->data[i]);
    }
    printf("%f]\n", tensor->data[tensor->elementCount - 1]);
}

Tensor *zeros(size_t size)
{
    printf("size %d\n", size);
    // Allocate memory for the tensor
    Tensor *tensor = (Tensor *)malloc(sizeof(Tensor));
    if (tensor == NULL)
    {
        printf("Failed to allocate memory for tensor\n");
        return NULL;
    }
    else
    {
        printf("Allocated memory for tensor\n");
    }

    // Allocate memory for tensor data (calloc initializes values to 0)
    DTYPE *tensorData = (DTYPE *)calloc(size, sizeof(DTYPE));
    if (tensorData == NULL)
    {
        printf("Failed to allocate memory for tensor data\n");
        free(tensor);
        return NULL;
    }
    else
    {
        printf("Allocated memory for tensor data\n");
    }

    tensor->elementCount = size;
    tensor->data = tensorData;
    tensor->show = show;

    return tensor;
}

Tensor ones(size_t size)
{
    Tensor tensor;
    DTYPE *tensorData = (DTYPE *)malloc(size * sizeof(DTYPE));

    for (int i = 0; i < size; i++)
    {
        tensorData[i] = 1.0f;
    }

    tensor.elementCount = size;
    tensor.data = tensorData;
    tensor.show = show;
    return tensor;
}

void freeTensor(Tensor *tensor)
{
    // Tensor data is heapallocated
    free(tensor->data);
    free(tensor);
}
