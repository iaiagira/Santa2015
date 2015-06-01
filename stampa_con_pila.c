#include<stdio.h>
#include<malloc.h>


struct el_t{    
	int num;
	struct el_t *left;
	struct el_t *right;
	struct el_t *prev;
	struct el_t *next;
	int left_visit;
	int right_visit;
};

typedef struct el_t elem;

void popola_albero(elem *,int);
void push(elem *, elem);
void pull(elem *);
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
	root->next=NULL;
	root->right=NULL;
	root->left=NULL;
	
	root->num=n1;
	
	
	popola_albero(root,DIM);
	
	printf("\n L'albero è riempito di numeri\n I numeri ordnati sono:");
	
	stampa_in_ordine(root);
	
	
return 0;
}


//popola_albero

void popola_albero(foglia *testa, int DIM){
	
	
	int n=0,i,inserito;
	foglia *tmp,*tmp1;
	
	//inserisco altri numeri della lista
	for(i=1;i<DIM;i++){
		
		printf("\nPROVO allocare memoria1 per %d\n",n);
		printf("\nInserisci numero\n");
		scanf("%d",&n);
		
		printf("\nPROVO allocare memoria2 per %d\n",n);
		
		tmp1=(foglia *)malloc(sizeof(foglia));
		
		tmp1->prev=NULL;
		tmp1->next=NULL;
		tmp1->left=NULL;
		tmp1->right=NULL;
		tmp1->right_visit=NULL;
		tmp1->left_visit=NULL;
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

void push(elem *testa, elem da_inserire){
	
	if(testa==NULL)
		
		testa=da_inserire;
	
	else push(testa->next,da_inserire);
	
}

void pull(elem *testa){
	
	elem *tmp;
	
	if(testa->next==NULL){
		
		tmp=testa;
		testa=tmp->prev;
		free(tmp);
		
	
	}else pull(testa->next);
	
}
	

void stampa_in_ordine(foglia *testa){
	
	
	if(testa==NULL)
		return;
	
	/*stampa_in_ordine(testa->left);
	printf("\n%d\n",testa->num);							
	stampa_in_ordine(testa->right);
	*/	
}	
