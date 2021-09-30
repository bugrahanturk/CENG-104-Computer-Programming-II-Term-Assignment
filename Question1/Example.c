//NEVZAT BUÐRAHAN TÜRK | ID:17050111036
//You can try the header file with this program
#include<stdio.h>
#include "TermAssignmentQuestion1.h"

int main()
{
	printf("\t\t\t\tTHIS IS A EXAMPLE PROGRAM FOR HEADER FILE!!\n\n");
	doubleStack s;
	
	initialize_s1(&s);
	initialize_s2(&s);
	
	int i;
			
	for(i=0;i<70;i++)
		push1(&s,i);
	
	for(i=70;i<120;i++)
		push2(&s,i);
		
	while(!is_empty_s2(&s))
		printf("%d ",pop2(&s));
		
	while(!is_empty_s1(&s))
		printf("%d ",pop1(&s));
	
	
	
	return 0;
}
