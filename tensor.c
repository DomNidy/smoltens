#include <immintrin.h> // AVX2 instrunction set
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tensor.h"

void free_tensor(Tensor *tensor)
{
    // Tensor data is heapallocated
    free(tensor->data);
    free(tensor);
}

// Rewrite these to guarantee that the data is aligned
void *smoltens_calloc(size_t count, size_t dtype_size)
{
    void *data = (void *)calloc(count, dtype_size);
    if (data == NULL)
    {
        printf("smoltens_calloc: Failed to allocate %d elements of size %d\n", count, dtype_size);
        return NULL;
    }
    else
    {
        printf("smoltens_cmalloc: Successfully allocated %d elements of size %d\n", count, dtype_size);
    }
    return data;
}

// Rewrite these to guarantee that the data is aligned
void *smoltens_malloc(size_t size)
{
    void *data = (void *)malloc(size);
    if (data == NULL)
    {
        printf("smoltens_malloc: Failed to allocate %d bytes of memory\n", size);
        return NULL;
    }
    else
    {
        printf("smoltens_malloc: Successfully allocated %d bytes of memory\n", size);
    }
    return data;
}

void show(Tensor *tensor)
{
    printf("[");
    for (int i = 0; i < tensor->element_count - 1; i++)
    {
        printf("%f, ", tensor->data[i]);
    }
    printf("%f]\n", tensor->data[tensor->element_count - 1]);
}

Tensor *zeros(size_t element_count)
{
    // Allocate memory for the tensor
    Tensor *tensor = (Tensor *)smoltens_malloc(sizeof(Tensor));

    // Allocate memory for tensor data (calloc initializes values to 0)
    DTYPE *tensor_data = (DTYPE *)smoltens_calloc(element_count, sizeof(DTYPE));
    tensor->element_count = element_count;
    tensor->data = tensor_data;
    tensor->show = show;

    return tensor;
}

Tensor *ones(size_t element_count)
{
    Tensor *tensor = (Tensor *)smoltens_malloc(sizeof(Tensor));
    DTYPE *tensor_data = (DTYPE *)smoltens_malloc(element_count * sizeof(DTYPE));

    // Return 256-bit vector with all elements initialized to specified scalar
    // __m256 ones = _mm256_set1_ps(1.0f);

    for (int i = 0; i < element_count; i++)
    {
        tensor_data[i] = 1.0f;
    }

    tensor->element_count = element_count;
    tensor->data = tensor_data;
    tensor->show = show;
    return tensor;
}

Tensor *tensor_add(Tensor *a, Tensor *b)
{
    if (a->element_count != b->element_count)
    {
        printf("Incompatible tensor shapes received, tensor a has shape %d, and tensor b has shape %d\n", a->element_count, b->element_count);
        return NULL;
    }

    Tensor *new_tensor = zeros(a->element_count);
    for (int i = 0; i < a->element_count; i++)
    {
        new_tensor->data[i] = a->data[i] + b->data[i];
    }
    return new_tensor;
}

DTYPE tensor_product(Tensor *a, Tensor *b)
{
    if (a->element_count != b->element_count)
    {
        printf("Incompatible tensor shapes received, tensor a has shape %d, and tensor b has shape %d\n", a->element_count, b->element_count);
        return 0.f;
    }

    DTYPE product = 0.f;
    for (int i = 0; i < a->element_count; i++)
    {
        product += a->data[i] * b->data[i];
    }
    return product;
}

DTYPE tensor_frobenius_norm(Tensor *a)
{
    DTYPE norm = 0.f;
    for (int i = 0; i < a->element_count; i++)
    {
        norm += pow(a->data[i], 2.f);
    }
    return sqrt(norm);
}

DTYPE tensor_sum(Tensor *a)
{
    DTYPE sum = 0;
    for (int i = 0; i < a->element_count; i++)
    {
        sum += a->data[i];
    }
    return sum;
}