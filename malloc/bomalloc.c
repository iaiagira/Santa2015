#include<stdio.h>
#include<string.h>
#include<malloc.h>


struct strel{
	int inf;
	struct strel *next;
	};
	
typedef struct strel el;
	
	int ricerca(el*,int);
	//void cancella(el *,int);
	
int main(){
	
	el *testa, *coda, *tmp;
	int n, i, size,N,soluz=0;
	
	size=sizeof(el);
	printf("\nLa dimensione del tipo el e': %d\n", size);

	tmp=(el *)malloc(sizeof(el));
	tmp->next=NULL;
	
	testa=tmp;
	coda=testa;
	
	printf("\nTesta1: %p",&testa);
	
//Ho creato il primo elemento messo a NULL + testa e coda puntano entrambi a questo primo elemento
	printf("\nQuanti utenti vuoi inserire?\n");
	scanf("%d",&n);
	
	printf("\nInserisci il codice del 1° utente\n");
	scanf("%d",&(testa->inf));
	
	printf("\nTesta2: %p",&testa);
	
	for(i=1;i<n;i++){
		tmp=(el *)malloc(sizeof(el));
		printf("\nInserisci il codice del %d° utente\n",i+1);
		scanf("%d",&(tmp->inf));
		tmp->next=NULL;
		printf("\nNext vale %p\n", tmp->next);
		coda->next=tmp;
		coda=tmp;
	}
	
	printf("\nTesta3: %p",&testa);
	
	printf("\nTmp che va in testa: %p",&tmp);
	
	//printf("\nTmp che va in testa+1: %d",&(tmp+1)); PERCHE''''''??????
	
	printf("\nLa rubrica e':\n");
	
	tmp=testa;
	
	/*do{
		printf("\nCodice utente: %d\n", tmp->inf);
		tmp=tmp->next;
		
	}while((tmp->next)!=NULL);
	*/
	
	for(tmp=testa;(tmp->next)!=NULL;tmp=tmp->next){
	
		printf("\nCodice utente: %d\n", tmp->inf); 
	}
	
	printf("\nCodice utente: %d\n", coda->inf); //bruttino
	
	//Ricerca di un utente
	printf("\nDigita il codice dell'utente che vuoi cercare\n");
	scanf("%d",&N);
	
	
	soluz=ricerca(testa,N);
	
	if(soluz==1)
	printf("\nUtente trovato\n");
	else printf("\nUtente NON trovato\n");
	
	/* PERCHE''''''??????
	j=0;
	while(!((tmp->next)==NULL)){
		printf("\nUtente %d°: %d\n", j, (tmp+(2*j))->inf);
		j++;
	}*/

	return 0;
}

int  ricerca(el *tmp ,int n){
	
	int ok=0;
	
	printf("\nIl codice della testa e' %d\n", tmp->inf);
	
	printf("\nIl codice del secondo utente e' %d\n", (tmp->next)->inf);
	
	printf("\nLa fine della lista e' %d\n",(((tmp->next)->next)->next));
	/*
	while((tmp->next)!=NULL){
		printf("\ntmp e' diverso da NULL\n");
		if((tmp->inf)==n){
			ok=1;
			tmp=tmp->next;
		}
	}*/
	return ok;
}
		

