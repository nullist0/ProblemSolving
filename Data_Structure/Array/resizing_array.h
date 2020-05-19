#define INIT_SIZE 2

typedef struct{
    int size;
    int *values;
} resize_array;

void init_array(resize_array* arr);
void set(resize_array* arr, int index, int value);
int get(resize_array* arr, int index);