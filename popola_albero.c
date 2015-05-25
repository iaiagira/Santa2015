#include <stdio.h>
#include <malloc.h>


#define N 5

struct nodo{
	int num;
	struct nodo *left;
	struct nodo *right;
	struct nodo *prev;
	struct nodo *next;
};

typedef struct nodo foglia;

void popola_albero(foglia *,int);


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
	
	testa=(foglia *)malloc(sizeof(foglia));
	testa->prev=NULL;
	testa->right=NULL;
	testa->left=NULL;
	testa->next=NULL;
	testa->num=n1;
	
	
	popola_albero(testa,DIM-1);
	
	
	

return 0;
}


//popola_albero

void popola_albero(foglia *testa, int DIM){
	
	
	int n=0,i;
	foglia *tmp,*root;
	
	root=testa;
	
	//inserisco il secondo numero della lista
	
	tmp=(foglia *)malloc(sizeof(foglia));
		tmp->prev=NULL;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->next=NULL;
		tmp->num=n;
		
	if(n<testa->num){
			
			testa->left=tmp;
			printf("testa left è %d", testa->left->num);
			
	}else{
			
			testa->right=tmp;
			printf("testa right è %d", testa->right->num);
	}
		
		tmp->prev=testa;
		testa=tmp;
		printf("\ntesta è cambiato quindi il num di testa è %d\n", testa->num);
	
	//inserisco altri numeri della lista
	
	for(i=1;i<DIM;i++){
		
		printf("\nInserisci numero\n");
		scanf("%d",&n);
		
		tmp=(foglia *)malloc(sizeof(foglia));
		tmp->prev=NULL;
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->next=NULL;
		tmp->num=n;
		
		if(n>root->num){
			
			tmp=root;
			while(tmp->right=!NULL){
				
				tmp=tmp->next;
				
				if(n>tmp->num){
				
					tmp->prev=testa;
					testa->next=tmp;
					testa->right=tmp;
					tmp=testa;
					
				}else{
				
					tmp->prev=testa;
					testa->next=tmp;
					testa->left=tmp;
					tmp=testa;
				}
				
			}
				
		}else{
			
			tmp=root;
			
			for(tmp=root;tmp->left=!NULL;tmp=tmp->next){
		
				if(n>tmp->num){
				
					tmp->prev=testa;
					testa->next=tmp;
					testa->right=tmp;
					tmp=testa;
					
				}else{
				
					tmp->prev=testa;
					testa->next=tmp;
					testa->left=tmp;
					tmp=testa;
				}
				
			}
		}
		
	/*	if(n<testa->num && n<root->num){
			
			testa->left=tmp;
			printf("testa left è %d", testa->left->num);
			
		}else if(n>testa->num && n<root->num){
			
			testa->right=tmp;
			printf("testa right è %d", testa->right->num);
		}else if(n)
		
		tmp->prev=testa;
		testa=tmp;
		printf("\ntesta è cambiato quindi il num di testa è %d\n", testa->num);
	}
	*/
}
