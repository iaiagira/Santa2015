#include<stdio.h>
#include<malloc.h>

#define N 20

struct el_t{    
	int num;
	struct el_t *left;
	struct el_t *right;
	struct el_t *prev;
};

struct pila_t{
	int left_visit;
	int right_visit;
	struct pila_t *next;
};

typedef struct pila_t pila;


typedef struct el_t elem;

void popola_albero(elem *,int);
void push(pila **,int,int);
void pop(pila **);
void stampa_in_ordine(elem *);

//main
int main(){

	elem *root;
	int n1,DIM;

	do{
	printf("Quanti numeri vuoi inserire nell'albero?\n");
	scanf("%d",&DIM);
	}while(DIM>N);
	
	
	printf("Inserisci il primo numero nell'albero: ROOT\n");
	scanf("%d",&n1);
	
	root=(elem *)malloc(sizeof(elem)); 
	root->prev=NULL;
	root->right=NULL;
	root->left=NULL;
	
	root->num=n1;
	
	
	popola_albero(root,DIM);
	
	
	stampa_in_ordine(root);
	
	
return 0;
}


//popola_albero

void popola_albero(elem *testa, int DIM){
	
	
	int n=0,i,inserito;
	elem *tmp,*tmp1;
	
	//inserisco altri numeri della lista
	for(i=1;i<DIM;i++){
		
		printf("\nInserisci numero\n");
		scanf("%d",&n);
		
		
		tmp1=(elem *)malloc(sizeof(elem));
		
		tmp1->prev=NULL;
		tmp1->left=NULL;
		tmp1->right=NULL;
		
		tmp1->num=n;
		
		tmp=testa;
		inserito=0;
		
		printf("\n al giro %d tmp1=%d\n",i,tmp1->num);
		
		while(!inserito){
			
	
			if(n>tmp->num){
				
				if(tmp->right!=NULL){
					
					tmp=tmp->right;
					printf("\na dx del root,tmp right è %d\n",tmp->num);
				
				}else{
					
					tmp1->prev=tmp;
					tmp->right=tmp1;
					inserito=1;
					printf("METTO:a dx del tmp,tmp è %d\n",tmp->num);
					
				}
				
			}else{  //implicitamente < o =
				
				if(tmp->left!=NULL){
					
					tmp=tmp->left;
					printf("a sx del root,tmp left è %d\n",tmp->num);
				
				}else{
					
					tmp1->prev=tmp;
					tmp->left=tmp1;
					inserito=1;
					printf("METTO:a sx del tmp,tmp è %d\n",tmp->num);
					
				}
			}
		}
	}
			
}	

void push(pila **testa, int left_visit,int right_visit){
	
	pila *tmp;
	
	tmp=(pila *)malloc(sizeof(pila));
	tmp->left_visit=left_visit;
	tmp->right_visit=right_visit;
	
	tmp->next=*testa;
	
	*testa=tmp;
	
}

void pop(pila **testa){
	
	pila *tmp;
	
	tmp=*testa;
	*testa=tmp->next;

	free(tmp);
	
}
	

void stampa_in_ordine(elem *testa){
	
	pila *esploraz;

	esploraz=NULL;
	
	if(testa==NULL)
		return;
		
	push(&esploraz,0,0);
		
	printf("\n L'albero è riempito di numeri\n I numeri ordinati sono:");
	
	while(esploraz!=NULL){
		
		
		if(esploraz->left_visit==0){
			
			esploraz->left_visit=1;
		
			if(testa->left!=NULL){
				testa=testa->left;
				push(&esploraz,0,0);
				
			}
		}else if(esploraz->right_visit==0){
				
			printf("\n%d\n",testa->num);	
			esploraz->right_visit=1;
		
			if(testa->right!=NULL){
				testa=testa->right;
				push(&esploraz,0,0);
			}
		}else{
			
			pop(&esploraz);
			testa=testa->prev;
		}	
	}
}	
