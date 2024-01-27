//STACK IMPLEMENTATION USING LINKED LIST//
//DATA STRUCTURE//
//AUTHOR:=HEM.V.NAIK//
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct nodeofstack 
{
	int data;
	struct nodeofstack *previouslink,*nextlink;
}*head=NULL,*top=NULL,*current=NULL;
int flag,pos,key,search,choice;
void pushinstack(void);
void popinstack(void);
void traverse(void);
void searching(void);
void sizeofstack(void);
int main()
{
	 for(;;)
	 {
	 	std::cout<<"1--->PUSH"<<endl;
	 	std::cout<<"2--->POP"<<endl;
	 	std::cout<<"3--->TRAVERSE"<<endl;
	 	std::cout<<"4--->EXIT"<<endl;
	 	std::cout<<"ENTER CHOICE:";
	 	std::cin>>choice;
	 	switch(choice)
	 	{
	 	    case 1:
			 pushinstack();
			 break;
			case 2:
			 popinstack();
			 break;
			case 3:
			 traverse();
			 break;
			case 4:
			 exit(1);
			default:
			 std::cout<<"INVALID CHOICE!!!"<<endl;	
		}
	 }
	 getch();
	 return 0;
}
void pushinstack(void)
{
	top=(struct nodeofstack*)malloc(1*sizeof(struct nodeofstack));
	std::cout<<"ENTER DATA:";
	std::cin>>top->data;
	if(head==NULL)
	{
		head=current=top;
		head->previouslink=head->nextlink=NULL;
	}
	else
	{
		current->nextlink=top;
		top->previouslink=current;
		current=top;
		top->nextlink=NULL;
	}

}
void popinstack(void)
{
    struct nodeofstack *a=NULL;
    if(head==NULL)
    {
    	std::cout<<"STACK EMPTY"<<endl;
	}
	else
	{
		if(head->nextlink==NULL)
		{
			std::cout<<"DELETE DATA:"<<head->data<<endl;
			head=top=current=NULL;
			free(head);
		}
		else
		{
	    	a=top;
		    top=top->previouslink;
		    top->nextlink=NULL;
		    a->previouslink=NULL;
		    std::cout<<"DELETE DATA:"<<a->data<<endl;
		    free(a);
		    current=top;
	    }
	}
}
void traverse(void)
{
	struct nodeofstack *s=NULL;
	if(head==NULL)
	{
		std::cout<<"STACK EMPTY"<<endl;
	}
	else
	{
		std::cout<<"DISPLAY"<<endl;
		for(s=top;s!=NULL;s=s->previouslink)
		{
			std::cout<<s->data<<endl;
		}
	}
}
void searching(void)
{
	struct nodeofstack *x=NULL;
	if(head==NULL)
	{
		std::cout<<"STACK EMPTY"<<endl;
	}
	else
	{
	    std::cout<<"ENTER SEARCH:";
	    std::cin>>search;
	    flag=0;
	    pos=1;
	    for(x=head;x!=NULL;x=x->nextlink)
	    {
	    	if(x->data==search)
	    	{
	    		flag=1;
	    		break;
			}
			pos++;
		}
		if(flag==1)
		std::cout<<"DATA IS AT POSITION:"<<pos<<endl;
		else
		std::cout<<"DATA NOT FOUND"<<endl;
    }
}
void sizeofstack(void)
{
	struct nodeofstack *b=NULL;
	key=0;
	for(b=head;b!=NULL;b=b->nextlink)
	{
		key++;
	}
	std::cout<<"SIZE OF STACK="<<key<<endl;
}









