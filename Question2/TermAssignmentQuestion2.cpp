//NEVZAT BUÐRAHAN TÜRK |ID:17050111036
#include <stdio.h>
#include "customer_queue.h"
#include "person_info.h"
#include "phone_num.h"
#define STACK_SIZE  100


void menu();//shows menu
void waiting_process(queue_t *q);//put the customer's information in a queue 
void processAp(stack_t *s,queue_t *q,stack_p *p);//move information in a queue to stack and gives number to the first application in the queue
void deleteP(stack_t *s,int num);//deleting customer's phone number


void menu()
{
	printf("\n");
	printf("1) Application form for telephone installations\n2) Number waiting for process\n3) Process an aplication\n4) Delete account\n5) Menu\n6) Exit\n\nEnter a choice:");
}

void waiting_process(queue_t *q)
{		
		customer_t custom;
	
		printf("\nEnter a name:");
		scanf("%s",custom.nameq);
		printf("\nEnter a surname:");
		scanf("%s",custom.snameq);
		printf("\nEnter an city:");
		scanf("%s",custom.city);
		printf("\nEnter a date of application(Example:5 05 2019): ");
		scanf("%d %d %d",&(custom.adateq.dayq ),&(custom.adateq.monthq ),&(custom.adateq.yearq ));
		insert(q,custom);
	
}


void processAp(stack_t *s,queue_t *q,stack_p *p)
{	

	customer_t custom;

	if(is_empty_q(q))
		printf("The queue is empty!!!\n");
	
	else
	{	
		custom=remove(q);
		custom.phone_num=pop_pn(p);
			
		printf("\nName: %s\nSurname: %s\nCity: %s\nDate of application: %d %d %d\nPhone number: %d\n\n",custom.nameq,custom.snameq,custom.city,custom.adateq.dayq,custom.adateq.monthq,custom.adateq.yearq,custom.phone_num);
		push(s,custom);

	}
			
}



void deleteP(stack_t *s,int num)
{	
	stack_t temp;
	initialize_s(&temp);
	customer_t del;
	
	while(!is_empty_s(s))
	{
		del=pop(s);
		
		if(del.phone_num==num)
			printf("%s %s 's acount deleted!!!",del.nameq,del.snameq);
				
			else
			{
				push(&temp,del);
			}
	}
	
		while(!is_empty_s(&temp))
			{
				push(s,pop(&temp));
			}		

}

int main()
{	queue_t q;
	stack_t s;
	stack_p p;
	
	customer_t custom;
	
	initialize_q(&q); 
	initialize_s(&s);
	initialize_s_pn(&p);

	int choice; 
	int numb=48268;
	int num,i; 
	
	stack_p phone;				
	initialize_s_pn(&phone);
	
	for(i=0;i<STACK_SIZE;i++)
	{
		
		push_pn(&phone,numb);
		numb=numb-2;
		}	
	
	
	
	printf("\t\t\tWelcome Dear Customer !!!Please choose operation from the menu\n\n");
	menu();
	scanf("%d",&choice);

	
while(1)
{

	switch (choice)
	{
	case 1:
		waiting_process(&q);
		printf("\nProcess completed!\n -> Please enter 5 for menu or enter 6 for exit!\nEnter your choice: ");
		scanf("%d",&choice);
		break;	

	case 2:
		printf("number of waiting process:%d",(q.rear-q.front+1));
		printf("\n -> Please enter 5 for menu or enter 6 for exit!\nEnter your choice: ");
		scanf("%d",&choice);
		break;

	case 3:
		processAp(&s,&q,&phone);
		printf("\n -> Please enter 5 for menu or enter 6 for exit!\nEnter your choice: ");
		scanf("%d",&choice);
		break;
	
	case 4:
		printf("\nPlease enter the phone number:");
		scanf("%d",&num);
		deleteP(&s,num);
		printf("\n\n Please enter 5 for the menu or  enter 6 for exit!\nEnter your choice: ");
		scanf("%d",&choice);
		break;

	case 5:
			menu();
			scanf("%d",&choice);
		break;
	
	case 6:
		return 0;
	}
	
}
	return 0;
	}
