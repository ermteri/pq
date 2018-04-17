#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>


typedef struct Trees{
  struct Trees *parent;
  struct Trees *left;
  struct Trees *right;
  float value;
  int arch;
  struct Trees *self;
}Tree;

//public
struct Trees *empty =NULL;
struct Trees *head;
int maxTask;
int nrEvent;
int archtecture;


//method declearation
Tree * creatHeap(Tree *heap,float value);
Tree * creatNode(float value,int arch);
int add(Tree *main, float item,int arch);
Tree * naiveMerge(Tree *main1, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
int decompose(Tree element,clock_t timestemp);
int increment();

//method
int main(int argc, char *argv[] ){
if(argc != 4) {
    printf("usage: list <maxTask> <nrEvent> <archtecture>\n");
    exit(0);
  }
  maxTask =atoi(argv[1]) ;
  nrEvent =atoi(argv[2]);
  archtecture=atoi(argv[3]);
  int counter=0;

int current=nrEvent;
float dataList[3];
  clock_t t,timestemp;
  t=clock();//predefined  function in c
  //add
  Tree *heap=creatHeap(heap,t);
  for (int i =1;i<current+1;i++){
      timestemp =clock();
    add(heap,timestemp,rand()%archtecture);

  }
//pop
  while((heap->left)!=empty||(heap -> right)!=empty){
    Tree element=pop(heap);

    //decompose
    if(element.arch>0){
   decompose(element, timestemp);
   //printf("element .arch : %d\n",element.arch);
}

   }
   Tree element=pop(heap);


 t=clock()-t;
 float effeciency=((float)t)/CLOCKS_PER_SEC;
/*
 //average operation
 dataList[counter]=effeciency;
  if (counter==2){
    current++;
    float sum=dataList[0]+dataList[1]+dataList[2];
    effeciency=sum / 3;
    counter=0;
    printf("%d\t%.8f\n", current, effeciency);
  }
*/
  printf("%d\t%.8f\n", current, effeciency);



//printf("# not crashed");

return 0;
}
int decompose(Tree element,clock_t timestemp){
  element.arch=element.arch-1;
  int n =rand()%maxTask;//random N
  int t =element.arch;//random N
  for(int i=1;i<n;i++){

    add(head,t+increment(),element.arch);
  }
}

int increment(){
  return rand()%(int)(10);
}

Tree * creatHeap(Tree *heap,float value){
  Tree *out=creatNode(value,rand()%archtecture);
  head=out;
  return out;
}

Tree * creatNode(float value,int arch){
  Tree *out=malloc(sizeof *out);
  out->parent=empty;
  out->left =empty;
  out->right=empty;
  out->value=value;
  out->arch=arch;
  out->self=&*out;
  return out;
}

int add(Tree *main, float item,int arch){
Tree *itemT=creatNode(item,arch);
Tree *tail=naiveMerge(main, itemT);
swap(tail);
 return 0;
}

int merge(Tree *main, Tree *item){
  Tree *tail =  naiveMerge(main,item);
  swap(tail);
  return 0;
}

int swap(Tree *tail){
  Tree *target;
  target=tail;
while((target->parent) !=empty){//probelm infinity loop
  target=(target ->parent);
  Tree *temp =(target->left);
  (target->left) = (target-> right);
  (target ->right )=temp;
}
  return 0;
}


Tree * naiveMerge(Tree *main1, Tree *item){
  Tree *container;
  Tree *main=malloc(sizeof *main);
  *main=*main1;
  //choose head
  if((main->value)>(item -> value)){

    //exchange item and main
    Tree *temp=main;
     main=item;
     item=temp;
     //head attach
    if((main->left)!=empty){
      main->left->parent=head;
  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
  }else{
    if((main->left)!=empty){
      main->left->parent=head;

  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
  }
container = head;
  while(1){
  //rest
  while((container->value)<=(item -> value)){

    //check last item
    if((container->right)==empty){//reason of infinity loop
      //position found
      //attach
      Tree *parent = container;
      //attach new tree
      (item->parent)=parent;
      (parent->right)=item;
      free(main);
      return parent->right; //return tail
    }else{
    container=(container->right);
  }
  }
  //position found
  //attach
  Tree *parent = (container->parent);
  //detch both child and parent
  (container->parent)=empty;
  (parent->right) = empty;
  //attach new tree
  (item->parent)=parent;
  (parent->right)=item;
  //prepare for next round
  item=container;
  container=(parent->right);
}
}

Tree pop(Tree *main){
  Tree *left=(main->left);
  Tree *right =(main->right);
  int leftFlag=0;
  int rightFlag=0;

  //detach head

  //detach left
  if((main->left)!=empty){
  (left->parent)=empty;
  (main->left)=empty;
  leftFlag=1;
}
//detach right
if ((main -> right)!=empty){
  (right->parent)=empty;
  (main->right)=empty;
  rightFlag=1;
}


  Tree target=*main;

  if(leftFlag==1&&rightFlag==1){
  merge(left,right);
}else if (leftFlag==1&&rightFlag==0){
  //attach head to the next Item
  *head=*left;
    left=head;
}else if (leftFlag==0&&rightFlag==1){
  *head=*right;
    right=head;
}
//reset flag
leftFlag =0;
rightFlag=0;
  return target;
}
