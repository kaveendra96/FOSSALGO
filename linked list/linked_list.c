#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
	};
int count = 0;
struct node *start=NULL;   // this pointer store the pointer of first node;

void display(struct node *start);
struct node *addBegin(struct node *start,int num);
struct node *addEnd(struct node *start,int num);
struct node *del(struct node* start,int num);
void search(struct node *start,int num);
int  countLinkedList(struct node *start);
void  addAfter(struct node *start,int num,int num2);


int main(){

	display(start);
	start=addBegin(start,10);
	start=addBegin(start,23);
	start=addBegin(start,45);
	search(start,2343);
	//display(start);
	start=addBegin(start,102);
	
	display(start);
	start=addEnd(start,10000);
	display(start);
	start=del(start,102);
	display(start);

	start=del(start,243);
	display(start);
	printf("%d",countLinkedList(start));
	addAfter(start,123,23);
	display(start);
	

return 0;
}

void display(struct node *start)
{	
	struct node *p;
	if(start==NULL)
	{
	printf("\n linked list is empty");
	return;
	}
	
		p=start;
		while(p != NULL)
		{
			printf("[%d]->",p->val);
			p=p->next;
			
		}
		//printf("<<%p>>",p);
		printf("NULL");
		printf("\n\n");
}

struct node *addBegin(struct node *start,int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=num;
	temp->next=start;
	start=temp;
	return start;
}
struct node *addEnd(struct node *start,int num){
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=num;
	p=start;
	while(p->next !=NULL)
	{
		p=p->next;
		

	}
	//printf("<<%p>>",p);
	p->next=temp;
	temp->next=NULL;
	
	return start;
}
struct node *del(struct node* start,int num)
{
	struct node * temp ,*p;
	if(start==NULL)
	{
		printf("Linked list is empty");
		return start;
	}
	if(start->val==num)
	{
		temp=start;
		start=start->next;
		free(temp);
		return start;
	}

	p=start;
	while(p->next !=NULL)
	{
		if(p->next->val==num)
		{
			temp=p->next;
			p->next=temp->next;
			free(temp);
			return start;

		}
		p=p->next;


	}
	printf("%d not in the list",num);
	return start;
}

void search(struct node *start,int num)
{
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		if(p->val==num)
		{
			printf("\n%d found\n",num);
			return;
		}
		p=p->next;

	}
	printf("\n no file found\n");

}

int  countLinkedList(struct node *start)
{
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		count++;
		p=p->next;

	}
	return count;
	

}
void  addAfter(struct node *start,int num,int num2)
{
	struct node *temp,*p;
	p=start;
	while(p !=NULL){
		if(p->val==num2)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->val=num;
			temp->next=p->next;
			p->next=temp;
			return ;
		}
	p=p->next;
	}
}
struct node* addBefore(struct node * start,int num,int num2)
{
	struct node *temp,*p;
	
	if(start->val==num2)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->val=num;
		temp->next=start;
		start=temp;
		return start;
	}
	p=start;
	while(p->next!=NULL)
	{
		if(p->next->val==num2)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->val=num;
			temp->next=p->next;
			p->next=temp;
			return start;

		}
		p=p->next;

	}
	printf("\n %d not in the list",num2);
	return start;

}


