#include <stdio.h>
#include <malloc.h>


#define N 20

struct nodo{
	int num;
	struct nodo *left;
	struct nodo *right;
	struct nodo *prev;
};

typedef struct nodo foglia;

void popola_albero(foglia *,int);
void stampa_in_ordine(foglia *);

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
	testa->num=n1;
	
	
	popola_albero(testa,DIM);
	
	printf("\n L'albero è riempito di numeri\n I numeri ordnati sono:");
	
	//stampa_in_ordine(testa,DIM);
	
	
return 0;
}


//popola_albero

void popola_albero(foglia *testa, int DIM){
	
	
	int n=0,i;
	foglia *tmp,*tmp1, *c;
	
	/*//inserisco il secondo numero della lista
	
	printf("\nInserisci numero\n");
	scanf("%d",&n);
	
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
	*/
	
	//inserisco altri numeri della lista
	
	tmp=testa;
	
	for(i=1;i<DIM;i++){
		
		printf("PROVO allocare memoria1 per %d",n);
		printf("\nInserisci numero\n");
		scanf("%d",&n);
		
		printf("PROVO allocare memoria2 per %d",n);
		
		tmp1=(foglia *)malloc(sizeof(foglia));
		
		tmp1->prev=NULL;
		tmp1->left=NULL;
		tmp1->right=NULL;
		
		tmp1->num=n;
		
		c=tmp1;
		
		
		/*free(tmp1->left);
		free(tmp1->right);
		free(tmp1->prev);
		free(tmp1);
		*/
		
		printf(" al giro %d tmp1=%d",i,tmp1->num);
		
		while(tmp->left!=NULL || tmp->right!=NULL){
			
			tmp=testa;
			
			if(n>tmp->num){
				
				tmp=tmp->right;
				printf("a dx del root,tmp right è %d\n",tmp->right->num);
				
			}else{
				
				tmp=tmp->left;
				printf("a sx del root,tmp left è %d\n",tmp->left->num);
			}
		}
		
		if(n>tmp->num){
			
			c->prev=tmp;
			tmp->right=c;
			
			printf("METTO:a dx del tmp,tmp right è %d\n",tmp->right->num);
			
		}else{
			
			c->prev=tmp;
			tmp->left=c;
			
			printf("METTO:a sx del tmp,tmp left è %d\n",tmp->left->num);
		
		}
			printf("ho finito il %d ciclo for",i);
	}
			
}	
		/*if(n>root->num){
			
			tmp=root;
			while(tmp->right!=NULL && tmp1->num>tmp->num){
				
				tmp=tmp->right;
				
			}
				
				if(n>tmp->num && tmp->right==NULL){
				
					tmp1->prev=tmp;
					tmp->next=tmp1;
					tmp->right=tmp1;
					printf("a dx del root,a dx perchè %d > %d ;tmp right è %d\n",tmp1->num,tmp->num,tmp->right->num);
					
				}else if(n<tmp->num && tmp->left==NULL){
				
					tmp1->prev=tmp;
					tmp->next=tmp1;
					tmp->left=tmp1;
					printf("a sx del root,a sx perchè %d < %d ;tmp left è %d\n",tmp1->num,tmp->num, tmp->left->num);
				}
				
		
				
		}else{
			
			tmp=root;
			
			while(tmp->left!=NULL && tmp1->num<tmp->num){
				
				tmp=tmp->left;
			
			}
		
				if(n>tmp->num && tmp->right==NULL){
				
					tmp1->prev=tmp;
					tmp->next=tmp1;
					tmp->right=tmp1;
					printf("a sx del root,a dx perchè %d > %d ;tmp right è %d\n",tmp1->num,tmp->num, tmp->right->num);
					
				}else if(n<tmp->num && tmp->left==NULL){
				
					tmp1->prev=tmp;
					tmp->next=tmp1;
					tmp->left=tmp1;
					printf("a sx del root,a sx perchè %d < %d ;tmp left è %d\n",tmp1->num,tmp->num, tmp->left->num);
				}
				
			}
		}
	}
		
		if(n<testa->num && n<root->num){
			
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


void stampa_in_ordine(foglia *testa){
	
	
	if(testa->right==NULL && testa->left==NULL){

		printf("\n%d\n",testa->num);
		
		stampa(testa->prev);
		
	}else if(testa->right!=NULL){
		
		stampa(testa->right);
		
	
	}else
	stampa_in_ordine(testa->next);
	
*/
