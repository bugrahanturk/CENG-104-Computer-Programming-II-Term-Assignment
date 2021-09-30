//NEVZAT BUĞRAHAN TÜRK |ID: 17050111036
#define STACK_SIZE 100

typedef  int  SType;

SType  STACK_EMPTY = -987654321;

typedef struct {
	
	int top1, top2;
	SType array[STACK_SIZE];

}doubleStack;

//Functions in this file:
void initialize_s1 (doubleStack *s);
int is_empty_s1 (doubleStack *s);
int is_full_s1 (doubleStack *s);
void push1 (doubleStack *s, SType item);
SType pop1 (doubleStack *s);
void initialize_s2 (doubleStack *s);
int is_empty_s2 (doubleStack *s);
int is_full_s2 (doubleStack *s);
void push2 (doubleStack *s, SType item);
SType pop2 (doubleStack *s);

void initialize_s1 (doubleStack *s)
{
	
	s->top1 = -1;

}


int is_empty_s1 (doubleStack *s)
{
	
	if(s->top1 == -1)
		return 1;
	
	return 0;
	
}

int is_full_s1 (doubleStack *s)
{
	
	if(s->top1 == (s->top2)-1)
		return 1;
	
	return 0;
		
}

void push1 (doubleStack *s , SType item)
{
	
	if(is_full_s1(s))
		printf("Error:Stack is full!!\n");
	
	else
	{
		(s->top1)++;
		s->array[s->top1] = item;
	}
	
}

SType pop1 (doubleStack *s)
{
	
	SType item;
	
	if(is_empty_s1(s))
	{
		printf("Error:Stack is empty!\n");
		item = STACK_EMPTY;
	}
	
	else
	{
		item = s->array[s->top1];
		(s->top1)--;
	}
	
	return (item);
	
}

void initialize_s2 (doubleStack *s)
{
	
	s->top2 =STACK_SIZE;
	
}


int is_empty_s2 (doubleStack *s)
{

	if(s->top2 == STACK_SIZE)
		return 1;
	
	return 0;
		
}

int is_full_s2 (doubleStack *s)
{
	
	if(s->top2== (s->top1)+1)
		return 1;
	
	return 0;
	
}

void push2 (doubleStack *s , SType item)
{
	
	if(is_full_s2(s))
		printf("Error:Stack is full!\n");
	
	else
	{
		(s->top2)--;
		s->array[s->top2] = item;
	}
	
}

SType pop2 (doubleStack *s)
{
	SType item;
	if(is_empty_s2(s))
	{
		printf("Error:Stack is empty!\n");
		item=STACK_EMPTY;
	}
	
	else
	{
		item=s->array[s->top2];
		(s->top2)++;
	}
	
	return (item);
}

