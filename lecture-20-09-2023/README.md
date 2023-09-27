# Lecture from 20/09/2023

## Implementation of a stack abstract data type

It must be implemented as a stack with static size, defined on compile time.

I'll try to implement this stack using dynamic allocation later


## Static stack (statstack) specification

```c
#define STATIC_STACK_SIZE 100
typedef struct StaticStack{
	// Attributes
	int top;
	int items[STATIC_STACK_SIZE];
};
```

### Methods

- push(StaticStack *s, int *newElement, int *errorCode);
- pop(StaticStack *s, int *errorCode);
- top(StaticStack *s, int *errorCode);
- isEmpty(StaticStack *s, int *errorCode);
- isEqual(StaticStack *s1, StatickStack *s2);
- invert(StaticStack *s);
- clear(StaticStack *s, int *errorCode);
