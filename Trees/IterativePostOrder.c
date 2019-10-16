#include<stdio.h>
#include<stdlib.h>
struct Tnode {
    int val;
    struct Tnode *left,*right;
};
struct snode{
    struct Tnode *node;
    struct snode *next;
};
int create_node(int val,struct Tnode **node){
    struct Tnode *tmp;
    tmp=malloc(sizeof(struct Tnode));
    if(tmp==NULL) return 0;
    tmp->val=val;
    tmp->left=NULL;
    tmp->right=NULL;
    (*node)=tmp;
    return 1;
}
void insert_node(struct Tnode **Troot,struct Tnode **node){
    struct Tnode *parent,*tmp;
    int val;
    if((*node)==NULL) return;
    if((*Troot)==NULL){
    (*Troot)=(*node);
    return;
    }
    tmp=(*Troot);
    val=(*node)->val;
    while(tmp!=NULL){
    parent=tmp;
    if(val<tmp->val) tmp=tmp->left;
    else tmp=tmp->right;
    }
    if(val<parent->val){
    parent->left=(*node);
    }
    else parent->right=(*node);
    return;
}
void push_sstack(struct snode **stack,struct Tnode *node){
    struct snode *stop,*tmp;
    stop=*stack;
    if(stop==NULL){
    tmp=malloc(sizeof(struct snode));
    tmp->node=node;
    tmp->next=NULL;
    (*stack)=tmp;
    }
    else {
    tmp=malloc(sizeof(struct snode));
    if(tmp!=NULL){
    tmp->node=node;
    tmp->next=stop;
    (*stack)=tmp;}
    else     printf(" \n Memory is Full Can't insert value\n ");
    }
}
struct Tnode *pop_sstack(struct snode **stack){
    if((*stack)!=NULL)
    {
    struct Tnode *rval;
    struct snode *tmp,*stop;
    stop=(*stack);
    tmp=stop;
    rval=tmp->node;
    stop=stop->next;
    *stack=stop;
    tmp->next=NULL;
    free(tmp);
    return rval;
    }
    return NULL;
}
int is_stack_empty(struct snode **stack){
    if((*stack)==NULL) return 1;
    else return 0;
}
 
void postorder_iterative(struct Tnode **Troot )
{
    if((*Troot)==NULL) return;
    struct snode *s1=NULL,*s2=NULL; 
    struct Tnode *curnode=(*Troot);
    push_sstack(&s1,curnode);
    while(!is_stack_empty(&s1))
    {	
	curnode=pop_sstack(&s1);
	push_sstack(&s2,curnode);
	if(curnode->left) push_sstack(&s1,curnode->left);
	if(curnode->right) push_sstack(&s1,curnode->right);       
    }
	while(!is_stack_empty(&s2)){
	curnode=pop_sstack(&s2);
	printf(" %d ",curnode->val);
	}
}
 
int main(){
struct Tnode *root=NULL,*node;
int key,ival,*sum,ssum=0;
sum=&ssum;
do{
printf("\n[1] Insert value");
printf("\n[2] Print Tree (Postorder Iterative) ");
printf("\n[3] Exit ");
printf("\nEnter the input key : ");
scanf("%d",&key);
switch(key){
case 1:
    printf("\n Enter the value to be inserted :");
    scanf("%d",&ival);
    if(create_node(ival,&node))
        insert_node(&root,&node);
    else printf("\n Memory is Full !! ");
break;
case 2:
printf("\n Tree contents are :\n");
    postorder_iterative(&root);
break;
case 3:
break;
default:
printf("\t Enter the Correct key !!!!! ");
break;
}
}while(key!=3);
 return 0;
}