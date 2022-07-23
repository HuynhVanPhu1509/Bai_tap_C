#include <stdio.h>
#include <stdint.h>
int top=-1;
typedef enum
{
    false=0,
    true
}bool_t;
bool_t IsFull(int capacity)
{
    if(top>=capacity-1) return true;
    else return false;
}
bool_t IsEmpty()
{
    if(top==-1) return true;
    else false;
}
void Push(int stack[],int value, int capacity)
{
    if(IsFull(capacity)==true) printf("stack day\r\n ");
    else
    {
      ++top;
      stack[top]=value;
    }
}
void Pop(int stack[])
{
    if(IsEmpty()==true) printf("stack trong\r\n ");
    else --top;
}
int Top(int stack[])
{
    return stack[top];
}
int Size()
{
    return top+1;
}
int main()
{
    int capacity=7;
    int stack[7];
    for(int i=0;i<capacity;i++)
    {
        Push(stack,4*i,capacity);
    }
    for(int i=0;i<capacity;i++)
    {
        printf("%d\r\n",Top(stack));
        Pop(stack);
    }
    for(int i=0;i<capacity;i++)
    {
        printf("%d\r\n",stack[i]);
    }
    return 0;
}