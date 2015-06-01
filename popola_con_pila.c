#include <stdio.h>
#include <malloc.h>


#define N 20

struct nodo{    //nodo_t nodo
	int num;
	struct nodo *left;
	struct nodo *right;
	struct nodo *prev;
	int left_visit;
	int right_visit;
};

typedef struct nodo foglia;

void popola_albero(foglia *,int);
void stampa_in_ordine(foglia *);
void stampa_in_ordine_decrescente(foglia *);

//main
int main(){

	foglia *testa;
	int n1,DIM;

	do{
	printf("Quanti numeri vuoi inserire nell'albero?\n");
	scanf("%d",&DIM);
	}while(DIM>N);
	
	
	printf("Inserisci il primo numero nell'albero: ROOT\n");
	scanf("%d",&n1);
	
	testa=(foglia *)malloc(sizeof(foglia)); // chiamarla root
	testa->prev=NULL;
	testa->right=NULL;
	testa->left=NULL;
	
	testa->num=n1;
	
	
	popola_albero(testa,DIM);
	
	printf("\n L'albero è riempito di numeri\n I numeri ordnati sono:");
	
	stampa_in_ordine(testa);
	
	printf("\n L'albero è riempito di numeri\n I numeri ordnati in ordine DECRESCENTE sono:");
	
	stampa_in_ordine_decrescente(testa);
	
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

void stampa_in_ordine(foglia *testa){
	
	
	if(testa==NULL)
		return;
	
	stampa_in_ordine(testa->left);
	printf("\n%d\n",testa->num);							
	stampa_in_ordine(testa->right);
		
}	

void stampa_in_ordine_decrescente(foglia *testa){
	

	if(testa==NULL)
		return;
							
	stampa_in_ordine_decrescente(testa->right);
	printf("\n%d\n",testa->num);
	stampa_in_ordine_decrescente(testa->left);	
}	
	
/*
void stampa_in_ordine(foglia *testa){
	
	
	if(testa->right==NULL && testa->left==NULL){

		printf("\nsono la foglia:%d\n",testa->num);
		
		
	}else{ 
		
		if(testa->left!=NULL){
		
			stampa_in_ordine(testa->left);
		}
		
		printf("\nsono in mezzo %d\n",testa->num);
			
		if(testa->right!=NULL){
				
			stampa_in_ordine(testa->right);
		}
		
	}
}
*/
