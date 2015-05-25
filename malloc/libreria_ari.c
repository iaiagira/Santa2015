#include <stdio.h>
#include <string.h>
#include "libreria_ari.h"
#include <malloc.h>


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

int cancella_utente(char *nome, char *cognome, utente **testa){
		
	utente *prev=NULL,*tmp;
	
	tmp=*testa;
	
		
	while((tmp!=NULL)){	
		printf("\ntmp e' diverso da NULL\n");
		
		if((strcmp(tmp->nome,nome)==0)&&(strcmp(tmp->cognome,cognome)==0)){
			
			if(prev==NULL){
				
				printf("sto eliminando il primo elemento nome:%s cognome: %s\n",nome,cognome);
				
				*testa=tmp->next;
			
				free(tmp->nome); 
				free(tmp->cognome); 
				free(tmp);
				
			}else{
		
				prev->next=tmp->next;
			
				free(tmp->nome); 
				free(tmp->cognome); 
				free(tmp);
			
			}
			
			return 1;
			
		}
		prev=tmp;
		tmp=tmp->next;
		
	}
	
	return 0;
}
/* // altro modo per fare cancella utente ritornando la testa e non un numero per dire cancellato correttamente o no
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
*/

//inserisci utente in ordine alfabetico
int  inserisci(utente *testa, utente *da_inserire){
	
	int ok=0;
utente *tmp,tmp2;
	
	
	
	
	for(tmp=testa;tmp!=NULL;tmp=tmp->next){
		tmp2=
			if(strcmp((tmp)->cognome,(da_inserire)->cognome)<0){   //se il cognome dell'utente dopo deve stare prima in ordine alfabet.
				tmp
				ne->next=tmp;
				tmp->next=ne;
				
		}
		}
	
	return ok;
}
		
