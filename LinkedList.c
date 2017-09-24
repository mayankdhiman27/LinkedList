#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
static struct node * head=NULL;

//Function to Insert At Beginning
void insertAtStart(int data){
struct node *p;
if(head==NULL){
p=(struct node *)malloc(sizeof(struct node *));
p->data=data;
p->next=NULL;
head=p;
}
else{
p=(struct node*)malloc(sizeof(struct node*));
p->data=data;
p->next=head;
head=p;
}
printf("Data successfully inserted...");
}

//Function to insert in between
void insertInBtn(int data,int k){
int flag=0;
if(head==NULL){
printf("There is no data to insert in between..please insert atleast one data..");
}
else{
struct node *p=head;
struct node *prev=p;
struct node *new;
while(p!=NULL){
if(p->data==k){
new=(struct node *)malloc(sizeof(struct node *));
new->data=data;
prev->next=new;
new->next=p->next;
flag=1;
}
prev=p;
p=p->next;
}
if(flag==1){
printf("Data successfully inserted...\n");
}
}
}

//Function to insert At End
void insertAtEnd(int data){
int flag=0;
struct node *p;
if(head==NULL){
p=(struct node *)malloc(sizeof(struct node *));
p->data=data;
p->next=NULL;
}
else{
struct node *p1;
p=head;
while(p->next!=NULL){
p=p->next;
}
p1=(struct node *)malloc(sizeof(struct node *));
p1->data=data;
p->next=p1;
p1->next=NULL;
flag=1;
}
if(flag==1){
printf("Data inserted successfully...");
}
}

//Function to Search
void search(int data){
int flag=0;
if(head==NULL){
printf("Hey!! Are u fine.. What u want to search..?..There is nothing your Linked List...Try to insert first\n");
}
else{
struct node *p=head;
while(p!=NULL){
if(p->data==data){
flag=1;
printf("Congo..The one which u tried to find is in your Linked List\n");
}
p=p->next;
}
}
if(flag==0){
printf("Ooops!!!..Bad Luck...Not Found..Try Next time..All the best\n");
}
}

//Function to delete data from linked list
void delete(int data){
int flag=0;
if(head==NULL){
printf("There is Nothing to delete..Are u OK..?\n");
}
else{
if(head->data==data){
struct node *temp=head;
head=head->next;
free(temp);
}
else{
struct node *p=head;
struct node *prev=p;
while(p!=NULL){
if(p->data==data){
flag=1;
prev->next=p->next;
}
else{
prev=p;
p=p->next;
}
}
}
}
if(flag==1){
printf("Required item deleted from your linked list...\n");
}
}

void printLL(){
struct node *p=head;
if(head->next==NULL){
printf("%d",head->data);
}
else{
while(p!=NULL){
if(p->next!=NULL){
printf("%d -> ",p->data);
}
else{
printf("%d",p->data);
}
p=p->next;
}
}
printf("\n");
}

//Message function
void message(){
printf("Please Enter your choice...\n");
printf("1 To Insert at start\n");
printf("2 To Insert at End\n");
printf("3 To Insert in Between\n");
printf("4 To Delete any data from your Linked List\n");
printf("5 To search your data\n");
printf("9 To Print have a look to your updated Linked List\n");
printf("0 To exit any time...\n");
}

//Driver code
void main(){
printf("Welcome to the world of Linked List Data Manipulation\n");
message();
int n,d;
scanf("%d",&n);
while(n!=0){
switch(n){
case 1:
	printf("Enter data to insert At start\n");
	scanf("%d",&d);
	insertAtStart(d);
	break;
case 2:
	printf("Enter data to insert at End\n");
	scanf("%d",&d);
	insertAtEnd(d);
	break;
case 3:
	printf("Enter data to insert In Between..afer that number after which you want to insert...(you can press 9 to see your LinkedList)\n");
	//if(choice is 9), then call printLL function	
	int k;
	scanf("%d %d %d",&d,&k);
	insertInBtn(d,k);
	break;
case 4:
	printf("Enter data to delete\n");
	scanf("%d",&d);
	delete(d);
	break;
case 5:
	printf("Enter data you want to search in your Linked List\n");
	scanf("%d",&d);
	search(d);
	break;
case 9:
	printLL();
	break;
default:
	printf("Please Enter correct choice or 0 to exit...");
	break;
}
message();
scanf("%d",&n);
if(n==0){
printf("Thank You!!\n");
exit(2);
}
}
}
