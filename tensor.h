#define DTYPE float

typedef struct Tensor
{
    // The amount of elements in this tensors array
    int elementCount;
    // Pointer to head of array
    float *data;
    // Prints out the elements of the tensor
    void (*show)(struct Tensor *);
} Tensor;

// Creates and returns a pointer to a tensor of `size` elements, all set to 0
Tensor* zeros(size_t size);

// Creates and returns a pointer tensor of `size` elements, all set to 0
Tensor ones(size_t size);

void freeTensor(Tensor *tensor);