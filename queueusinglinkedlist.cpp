#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct nodeofqueue
{
	int data;
	struct nodeofqueue *nextlink,*previouslink;
}*head=NULL,*front=NULL,*rear=NULL,*current=NULL;
void enqueue(void);
void dequeue(void);
void traverse(void);
void searching(void);
void sizeofqueue(void);
int choice,pos,key,val,search,flag;
int main()
{
	  for(;;)
	  {
	  	   std::cout<<"1--->ENQUEUE"<<endl;
	  	   std::cout<<"2--->DEQUEUE"<<endl;
	  	   std::cout<<"3--->TRAVERSE"<<endl;
	  	   std::cout<<"4--->SEARCHING"<<endl;
	  	   std::cout<<"5--->SIZE OF QUEUE"<<endl;
	  	   std::cout<<"6--->EXIT"<<endl;
	  	   std::cout<<"ENTER CHOICE:";
	  	   std::cin>>choice;
	  	   switch(choice)
	  	   {
	  	   	  case 1:
	  	   	  	enqueue();
					break;
			  case 2:
			    dequeue();
				    break;
			  case 3:
			    traverse();
				    break;
			  case 4:
			     searching();
				    break;
			  case 5:
			     sizeofqueue();
				    break;
			  case 6:
			     exit(1);
				   break;
			  default:
			      std::cout<<"INVALID CHOICE"<<endl;	
		   }
	  }
	  getch();
	  return 0;
}
void enqueue(void)
{
	  rear=(struct nodeofqueue*)malloc(1*sizeof(struct nodeofqueue));
	  std::cout<<"ENTER VAL:";
	  std::cin>>rear->data;
	  if(head==NULL)
	  {
	  	   head=rear;
	  	   current=rear;
	  	   current->previouslink=NULL;
	  	   current->nextlink=NULL;
	  }
	  else
	  {
	  	   current->nextlink=rear;
	  	   rear->previouslink=current;
	  	   current=rear;
	  	   rear->nextlink=NULL;
	  }
}
void dequeue(void)
{
	 struct nodeofqueue *x=NULL;
	 if(head==NULL)
	 {
	 	  std::cout<<"QUEUE EMPTY"<<endl;
	 }
	 else
	 {
	 	  front=head;
	 	  x=front;
	 	  front=front->nextlink;
	 	  x->nextlink=NULL;
	 	  front->previouslink=NULL;
	 	  std::cout<<"DELETE VAL:"<<x->data<<endl;
	 	  free(x);
	 	  head=front;
	 }
}
void traverse(void)
{
     struct nodeofqueue *a=NULL;
     if(head==NULL)
     {
     	  std::cout<<"NO DISPLAY"<<endl;
	 }
	 else
	 {
	 	  std::cout<<"TRAVERSE"<<endl;
	 	  for(a=head;a!=NULL;a=a->nextlink)
	 	  {
	 	  	    std::cout<<a->data<<endl;
		  }
	 }
}
void searching(void)
{
	 struct nodeofqueue *l=NULL;
	 if(head==NULL)
	 {
	 	 std::cout<<"SEARCH NOT POSSIBLE"<<endl;
	 }
	 else
	 {
	 	 std::cout<<"ENTER SEARCH:";
	 	 std::cin>>search;
	 	 flag=0;
	 	 pos=1;
	 	 for(l=head;l!=NULL;l=l->nextlink)
	 	 {
	 	 	  if(l->data==search)
	 	 	  {
	 	 	  	  flag=1;
	 	 	  	  break;
			  }
			  pos++;
		 }
	 }
	 if(flag==1)
	 std::cout<<"DATA IS AT POSITION:"<<pos<<endl;
	 else
	 std::cout<<"DATA NOT FOUND"<<endl;
}
void sizeofqueue(void)
{
	 key=0;
	 struct nodeofqueue *m=NULL;
	 for(m=head;m!=NULL;m=m->nextlink)
	 {
	 	  key=key+1;
	 }
	 std::cout<<"SIZE OF QUEUE="<<key<<endl;
}




















