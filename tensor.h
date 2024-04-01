#define DTYPE float

typedef struct Tensor
{
    // The amount of elements in this tensors array
    int element_count;
    // Pointer to head of array
    DTYPE *data;
    // Prints out the elements of the tensor
    void (*show)(struct Tensor *);
} Tensor;

// Creates and returns a pointer to a tensor of `element_count` elements, all set to 0
Tensor *zeros(size_t element_count);

// Creates and returns a pointer tensor of `element_count` elements, all set to 0
Tensor *ones(size_t element_count);

// Frees the memory allocated for a tensor
void free_tensor(Tensor *tensor);

// Encapsulates malloc with logging
void *smoltens_malloc(size_t size);

// Encapsulates calloc with logging
void *smoltens_calloc(size_t count, size_t dtype_size);

// Performs elementwise addition over two tensors and returns a new tensor with the result
Tensor *tensor_add(Tensor *a, Tensor *b);

// Computes the tensor product between a and b
DTYPE tensor_product(Tensor *a, Tensor *b);

// Computes the frobenius norm of a tensor
DTYPE tensor_frobenius_norm(Tensor *a);

// Computes the sum of all elements of a tensor
DTYPE tensor_sum(Tensor *a);