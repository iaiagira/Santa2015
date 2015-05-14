#include <stdio.h>
#include <string.h>
#include "libreria_ari.h"
#include<malloc.h>


//ricerca utente
int  ricerca(utente *tmp ,char da_cercarenome[], char da_cercarecognome[]){
	
	int ok=0;
	
	while((tmp!=NULL)&&(!ok)){
		printf("\ntmp e' diverso da NULL\n");
		if((strcmp(tmp->nome,da_cercarenome)==0)&&(strcmp(tmp->cognome,da_cercarecognome)==0)){
			ok=1;
			
		}
		tmp=tmp->next;
	}
	return ok;
}

//Ordina cognomi
void ordina_cognomi(utente *testa){
	
	utente *tmp, *tmp2;
	char *var;
	int num;
	
	
	for(tmp=testa;tmp!=NULL;tmp=tmp->next)
		for(tmp2=tmp->next;tmp2!=NULL;tmp2=tmp2->next){
			if(strcmp((tmp)->cognome,(tmp2)->cognome)>0){   //se il cognome dell'utente prima deve stare dopo in ordine alfabet.
				var=tmp->cognome;
				tmp->cognome=tmp2->cognome;
				tmp2->cognome=var;
				
				var=tmp->nome;
				tmp->nome=tmp2->nome;
				tmp2->nome=var;
				
				num=tmp->num_di_t;
				tmp->num_di_t=tmp2->num_di_t;
				tmp2->num_di_t=num;
		}
	}
}

//cancella utente
utente* cancella_utente(utente *tmp ,char *nome, char *cognome){
		
	utente *prev=NULL,*testa;
	testa=tmp;
		
	while((tmp!=NULL)){	
		printf("\ntmp e' diverso da NULL\n");
		
		if((strcmp(tmp->nome,nome)==0)&&(strcmp(tmp->cognome,cognome)==0)){
			
			if(prev==NULL){
				
				testa=tmp->next;
			
				free(tmp->nome); 
				free(tmp->cognome); 
				free(tmp);
				
			}else{
		
				prev->next=tmp->next;
			
				free(tmp->nome); 
				free(tmp->cognome); 
				free(tmp);
			
			}
			 
			return testa;
			
		}
		prev=tmp;
		tmp=tmp->next;
		
	}
	
	return testa;
}

//inserisci utente in ordine
int  inserisci(utente *tmp, utente *da_inserire){
	
	int ok=0;
utente *var, *coda, *testa;
	
	var=(utente *)malloc(sizeof(utente));
	var->next=NULL;
	
	testa=var;
	coda=testa;
	coda->next=tmp;
	coda=tmp;
	
	for(tmp=testa;tmp!=NULL;tmp=tmp->next){
			if(strcmp((tmp)->cognome,(da_inserire)->cognome)<0){   //se il cognome dell'utente dopo deve stare prima in ordine alfabet.
				strcpy(var->cognome,(tmp)->cognome);
				strcpy((tmp)->cognome,(da_inserire)->cognome);
				strcpy((da_inserire)->cognome,var->cognome);
				strcpy(var->nome,tmp->nome);
				strcpy((tmp)->nome,(da_inserire)->nome);
				strcpy((da_inserire)->nome,var->nome);
				var->num_di_t=tmp->num_di_t;
				tmp->num_di_t=da_inserire->num_di_t;
				da_inserire->num_di_t=var->num_di_t;
		}
	}
	
	//free(var);
	
	return ok;
}
		
