typedef struct
{
    int capacity;
    int topofstack;
    int *array;
} MinStack;

/** initialize your data structure here. */
#define EMPTYTOS (-1)
MinStack* minStackCreate(int maxSize)
{
    MinStack *S;
    S = malloc(sizeof(MinStack)*maxSize);
    if(S == NULL)
        return NULL;
    S->array = malloc(sizeof(int)*maxSize);
    if(S->array == NULL)
        return NULL;
    S->topofstack = EMPTYTOS;
    S->capacity = maxSize;
    return S;
}

void minStackPush(MinStack* obj, int x)
{
    if(obj->topofstack == obj->capacity)
        return NULL;
    else
        obj->array[++obj->topofstack]=x;
}

void minStackPop(MinStack* obj)
{
    if(obj->topofstack == EMPTYTOS)
        return NULL;
    else
        obj->topofstack--;
}

int minStackTop(MinStack* obj)
{
    if( (obj->topofstack!=EMPTYTOS) )
        return obj->array[obj->topofstack];
    return 0;
}

int minStackGetMin(MinStack* obj)
{
    int min = obj->array[obj->topofstack];
    int tmp = 0;
    for(int i=obj->topofstack;i>EMPTYTOS;i--)
    {
        if( obj->array[i] < min)
            min = obj->array[i];
    }
    return min;
}

void minStackFree(MinStack* obj)
{
    free(obj);
}
