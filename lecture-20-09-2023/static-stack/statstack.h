#define STATIC_STACK_SIZE 100

typedef struct StaticStack {
    int top;
    int items[STATIC_STACK_SIZE];  
};

