#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

//https://stackoverflow.com/questions/21788598/c-inserting-into-linked-list-in-ascending-order
typedef struct node{
    float data;
    struct node *ptr;
    struct node *ptr_p;
    struct node *tail;
} node;


int pCount;
int debug=0;
clock_t save;
int counter=0;
int n_max=0;
float n_counter=0;


node* insert(node* head, float num) {
counter++;
clock_t start,end;

    node *temp ,*tail;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    //first
    if(!head){
        head=temp;
        head->tail=temp;
    } else{
if(temp->data<=head->data){//insert head
head->ptr_p=temp;
temp->ptr=head;
temp->ptr_p=NULL;
temp->tail=head->tail;
head->tail=NULL;
head=temp;//update head
}else if(temp->data>=head->tail->data){//insert tail
temp->ptr_p=head->tail;
head->tail->ptr=temp;
temp->ptr=NULL;
head->tail=temp;//update tail
}else{
int avg =head->data+head->tail->data;
      avg=avg/2;//average
if (num>avg){
node *container=head->tail;

//search
start=clock();
while(temp->data<container->data){
n_counter++;
container=container->ptr_p;
}
end =clock();
save=save+(end-start);
//link temp
temp->ptr_p=container;
temp->ptr=container->ptr;
//update container
container->ptr->ptr_p=temp;
container->ptr=temp;
}else{
node *container=head;
//search
start=clock();
while(temp->data>container->data){
n_counter++;
container=container->ptr;
}
end =clock();
save=save+(end-start);
//link temp
temp->ptr=container;
temp->ptr_p=container->ptr_p;
//update container
container->ptr_p->ptr=temp;
container->ptr_p=temp;


}

}
    }

    return head;
}

node *trace=NULL;
//pop
node pop(node* head){
if(debug==1){
if (head->ptr_p!=NULL){
      printf("#Head is%f:\n",head->data);
}
}

trace=head->ptr;
if(trace!=NULL){
head->ptr->tail=head->tail;
}


if(debug==1){
if(head->tail==NULL){
 printf("\n\n#Error Report!\n");
      printf("trace->tail is empty\n");
      printf("#trace is%f:\n",trace->data);
 printf("Because of: \n");

 printf("Head->tail is empty\n");
      printf("#Head is%f:\n",head->data);
      printf("#Head->tail is%f:\n",head->tail->data);


//exit(-1);
}
    }


node out = *head;
free(head);
pCount++;
  return out;
}


//free the malloced memory to avoid memory leakage
void free_list(node *head) {
    node *prev = head;
    node *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->ptr;
        free(prev);
    }
}



int n=9;



//absolute value
//https://stackoverflow.com/questions/22268815/absolute-value-of-int-min
unsigned int absu(int value) {
    return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}

//increment generator
int increment(node* head){
int avg =0;
if(head==NULL){
avg=3;
}else{
  avg =(head->tail->data-head->data);//dynamic range
}
  int out=absu(rand()+rand()-rand())%(avg+1);
  out=absu(out);
  //printf("%d , %d\n",out,avg);
  return out ;
}

//decompose
node* decompose(node* head,node element){
  int n =absu(rand()+rand()-rand())%(n_max-counter);//random N
  n=absu(n);
  int t =element.data;// obtain value from main node
float variable=0;
//printf("#value of n is %d\n", n);
  for(int i=1;i<n;i++){
     variable =t+increment(head);
    head = insert(head, variable);
  }
  return head;
}

//test 
int test(){
float insert_list[]={0,1,1.1,1.2,5,4,6,5.4,3.5};
float answer_list[]={0,1,1.1,1.2,3.5,4,5,5.4,6};
 node *head, *p;
    head = NULL;
      printf("#size of insert_list is %d ", (int)sizeof(insert_list));
for(int i=0;i<9;i++) {        
       head = insert(head, insert_list[i]);
      printf("#inserting %f \n", insert_list[i]);
    }
    p = head;

int i_check=0;
 while(head->ptr!=NULL){
      node poped_node=pop(head);

      printf("#poping %f \n", poped_node.data);
      head=trace;
float var =0;
 if(counter<n_max){
     head= decompose(head,poped_node);
  }
/*
if(var<answer_list[0]
      if(poped_node.data!=answer_list[i_check]){
                printf("List pop error \n");
                
           return 0;
         }
*/
      i_check++;
}

printf("test pass");
return 1;
}







//main
int main(int argc, char *argv[]){
  if(argc != 3) {
      printf("usage: list  <nrEvent>  <debug>\n");
      exit(0);
    }
int num;

    n_max =atoi(argv[1]);//nrEvent
    debug=atoi(argv[2]); //debug
    int r =0;
    clock_t timestemp;
    time_t rand_t;
    node *head, *p;
    head = NULL;
   srand((unsigned) time(&rand_t));
  int n =absu(rand()+rand()-rand())%(n_max-counter);//random N
      n=absu(n);
    while(n==0){
      n =(rand()+rand()-rand())%(n_max-counter);
    }

    //add
    for(int i=0;i<n;i++) {
        timestemp =clock();
        head = insert(head, timestemp);
    //DEBUG
if(debug==1){
if(head->tail==NULL){
 printf("\n\n#Error Report!\n");
      printf("HEAD->tail is empty\n");
      printf("#HEAD is%f:\n",head->data);
return 0;
}
    }


    }
    p = head;

    //DEBUG
int check=1;
float temp=0;
if (debug==1){
  p = head;
printf("#Current list:\n");
    if(head!=NULL){
 temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
}
}

    //pop
    while(head!=NULL){
      node poped_node=pop(head);
      head=trace;


      //DEBUG
if (debug==1){
      printf("\n#POPED %f\n",poped_node.data );

 check=1;
  p = head;
      printf("#Current list:\n");
    if(head!=NULL){
     temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
}
}

      //decompose
      if(counter<n_max){
     head=decompose(head,poped_node);
  }

if (debug==1){
  //DEBUG
 check=1;
  p = head;
      printf("#Current list:\n");
    if(head!=NULL){
 temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
      printf("\n ");
}
}


     }

//debyg
    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

     //node poped_node=pop(head);//last
//debug
    //printf("\n#POPED %f\n",poped_node.data );


    double effeciency=(save)/(double)CLOCKS_PER_SEC*1000;
    int current= n;
     printf("%d\t%.8lf\n", n_max, effeciency);
    return 0;
}
