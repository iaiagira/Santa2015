#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "libreria_ari.h"

#define M 15
#define dim 500
#define dim1 100


int main(){
	
	utente *testa, *coda, *tmp,da_inserire;
	char da_cercarenome[M],da_cercarecognome[M];
	int n, i, size,ok=0,soluz=0,lunghnome=0,lunghcognome=0;
	char name[M], surname[M];
	
	//Inserimento utenti
	size=sizeof(utente);

	testa=(utente *)malloc(sizeof(utente));
	testa->next=NULL;
	
	
	coda=testa;
	
	
	//Ho creato il primo elemento messo a NULL + testa e coda puntano entrambi a questo primo elemento
	printf("\nQuanti utenti vuoi inserire?\n");
	scanf("%d",&n);
	
	printf("\nInserisci il nome e cognome del 1° utente\n");
	scanf("%s%s",name,surname);
	
	lunghnome=strlen(name);
	lunghcognome=strlen(surname);
	
		
	//printf("lughnome:%d lungcognome %d",lunghnome, lunghcognome);
	
	testa->nome=(char*)malloc(sizeof(char)*(lunghnome+1));  // +1 perchè c'è il carattere terminatore che la strlen non conta!!!
	testa->cognome=(char*)malloc(sizeof(char)*(lunghcognome+1));
	
	strcpy(testa->nome,name);
	strcpy(testa->cognome,surname);
	
	printf("nome del primo %s",testa->nome);
	
	printf("\nInserisci il numero di telefono del 1° utente\n");
	scanf("%d",&testa->num_di_t);
	
	
	for(i=1;i<n;i++){
		tmp=(utente *)malloc(sizeof(utente));
		
		printf("\nInserisci il nome e cognome del %d° utente\n",i+1);
		scanf("%s%s",name,surname);
		
		lunghnome=strlen(name);
		lunghcognome=strlen(surname);
	
		tmp->nome=(char*)malloc(sizeof(char)*(lunghnome+1));
		tmp->cognome=(char*)malloc(sizeof(char)*(lunghcognome+1));
	
		strcpy(tmp->nome, name);
		strcpy(tmp->cognome,surname);
	
		printf("\nInserisci il numero di telefono del %d° utente\n",i+1);
		scanf("%d",&tmp->num_di_t);
		tmp->next=NULL;
		
		coda->next=tmp;
		coda=tmp;
	}
	
	printf("\nLa rubrica e':\n");
	
	
	
	for(tmp=testa;tmp!=NULL;tmp=tmp->next)
	
		printf("\nUtente: %s\t%s\t%d\n", tmp->nome,tmp->cognome,tmp->num_di_t); 
	
	
	
	//Ricerca di un utente
	
	printf("\nDigita il nome e cognome dell'utente che vuoi cercare\n");
	scanf("%s%s",da_cercarenome,da_cercarecognome);
	
	printf("\n il nome e cognome dell'utente che vuoi cercare sono : %s\t%s\n",da_cercarenome,da_cercarecognome);
	
	soluz=ricerca(testa,da_cercarenome,da_cercarecognome);
	
	if(soluz==1)
		printf("\nUtente trovato\n");
	else 
		printf("\nUtente NON trovato\n");
	
	
	
	//Ordina cognomi
	
	
	ordina_cognomi(testa);
	
	printf("Rubrica ordinata alfabeticamente:\n");
	for(tmp=testa;tmp!=NULL;tmp=tmp->next){
		
		printf("\nUtente: %s\t%s\t%d\n", tmp->nome,tmp->cognome,tmp->num_di_t); 
	}
	
	//Cancella un utente
	
	printf("\nDigita il nome e cognome dell'utente che vuoi cancellare\n");
	scanf("%s%s",da_cercarenome,da_cercarecognome);
	
	printf("\n il nome e cognome dell'utente che vuoi cancellare sono : %s\t%s\n",da_cercarenome,da_cercarecognome);
	
	
	ok=cancella_utente(da_cercarenome,da_cercarecognome,&testa);

	
	if(ok==1){
		
		printf("Utente trovato e cancellato\n");
		printf("Rubrica sistemata:\n");
		
		for(tmp=testa;tmp!=NULL;tmp=tmp->next)
			
			printf("\nUtente: %s\t%s\t%d\n", tmp->nome,tmp->cognome,tmp->num_di_t); 
		
	}else
	
		printf("Utente NON trovato e  NON cancellato\n");
	
	
	
/*	
	//Inserire altro utente in modo ordinato
	
	tmp=(utente *)malloc(sizeof(utente));
	tmp->next=NULL;
	
	da_inserire=tmp;
	
	printf("\nDigita il nome, cognome e numero di tel dell'utente che vuoi inserire\n");
	scanf("%s%s%d",da_inserire->nome,da_inserire->cognome, &da_inserire->num_di_t);
	
	printf("\n il nome e cognome dell'utente che vuoi cancellare sono : %s\t%s\n",da_inserire->nome,da_inserire->cognome);
	
	soluz=inserisci(testa,da_inserire);
	
	if(soluz==1){
	printf("Utente inserito in modo corretto\n");
	printf("Rubrica ordinata alfabeticamente con l aggiunta dell utente:\n");
	for(tmp=testa;tmp!=NULL;tmp=tmp->next){
		
		printf("\nUtente: %s\t%s\t%d\n", tmp->nome,tmp->cognome,tmp->num_di_t); 
		}
	}
	else
	printf("Utente NON inserito\n");
	
	//free(da_inserire);
	
*/
	
return 0;
}
