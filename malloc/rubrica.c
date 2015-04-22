//Rubrica con array e puntatori


#include <stdio.h>
#include <string.h>

#define M 15
#define dim 500
#define dim1 100

typedef struct {
	char nome[M];
	char cognome[M];
	int num_di_t;
	int immagine[dim][dim];
}utente;

utente rubrica[dim1];

int inserisci_utente(utente *);  //done
void ordina_cognomi(utente *,int);  //done
int cancella_utente(utente *,int);				//non funziona il copiare una parola,ma poi che senso ha farmi vedere un 'none'?bisognerebbe traslare tt di 1 casella:quella cancellata
int cerca_utente(utente *,int); //done
//int inserisci_utente_ultimo(utente *);

int main(){
	int m=0,i,ins=0,verifica=0;
	
	
	//INSERIRE UTENTI
	m=inserisci_utente(rubrica);
	
	/*for(i=0;i<m;i++){
		rubrica[i].num_di_t=0;
	}*/
	
	//ORDINARE UTENTI
	ordina_cognomi(rubrica,m);
	
	printf("Rubrica ordinata alfabeticamente:\n");
	for(i=0;i<m;i++){
		printf("Utente numero %d:\tNome:%s\t Cognome:%s\tTelefono:%d\n",i+1,rubrica[i].nome,rubrica[i].cognome,rubrica[i].num_di_t);
	}
	
	//CANCELLA UTENTE
	printf("Vuoi cancellare un utente?(1=sì, 0=no)");
	scanf("%d",&verifica);
	if(verifica==1){
		ins=cancella_utente(rubrica,m);

		printf("Rubrica con i cancellamenti eseguiti:\n");
		for(i=0;i<m;i++){
		printf("Utente numero %d:\tNome:%s\t Cognome:%s\tTelefono:%d\n",i+1,rubrica[i].nome,rubrica[i].cognome,rubrica[i].num_di_t);
	}
}
	
	
	
	//RICERCARE UTENTE SPECIFICO
	printf("Vuoi cercare un utente?(1=sì, 0=no)");
	scanf("%d",&verifica);
	if(verifica==1)
	ins=cerca_utente(rubrica,m);
	
/*	if(ins==1){
		k=inserisci_utente_ultimo(rubrica,dim1);
	}
*/		
	
	return 0;
}

int inserisci_utente(utente *r){
	int i,n;
	
	printf("Quanti utenti vuoi inserire nella tua rubrica?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Utente numero %d:\n",i+1);
		printf("Nome, Cognome:\n");
		scanf("%s%s",(r+i)->nome,(r+i)->cognome);
		printf("Numero di telefono:\n");
		scanf("%d",&(r+i)->num_di_t);
		printf("Utente numero %d:\tNome:%s\t Cognome:%s\tTelefono:%d\n",i+1,(r+i)->nome,(r+i)->cognome,(r+i)->num_di_t);
	}
	
	for(i=0;i<n;i++){
		printf("Utente numero %d:\tNome:%s\t Cognome:%s\tTelefono:%d\n",i+1,(r+i)->nome,(r+i)->cognome,(r+i)->num_di_t);
	}
return n;	
}

void ordina_cognomi(utente *r,int m){
	int i,j;
	utente tmp;
	
	for(i=0;i<m;i++)
		for(j=0;j<m-1;j++){
			if(strcmp((r+j)->cognome,(r+j+1)->cognome)>0){   //se il cognome dell'utente prima deve stare dopo in ordine alfabet.
				strcpy(tmp.cognome,(r+j)->cognome);
				strcpy((r+j)->cognome,(r+j+1)->cognome);
				strcpy((r+j+1)->cognome,tmp.cognome);
				strcpy(tmp.nome,(r+j)->nome);
				strcpy((r+j)->nome,(r+j+1)->nome);
				strcpy((r+j+1)->nome,tmp.nome);
				tmp.num_di_t=(r+j)->num_di_t;
				(r+j)->num_di_t=(r+j+1)->num_di_t;
				(r+j+1)->num_di_t=tmp.num_di_t;
		}
	}
}


int cerca_utente(utente *r,int m){
	utente da_cercare;
	int i=0;//inserire=0;
	
	printf("Inserisci nome e cognome dell'utente da cercare:\n");
	scanf("%s%s",da_cercare.nome,da_cercare.cognome);
	
	while(((strcmp((r+i)->cognome, da_cercare.cognome)!=0)&&(strcmp((r+i)->nome, da_cercare.nome)!=0))&&(i<m)){
		i++;
		}
		
		if(i<m){
			printf("Utente trovato alla posizione %d\n",i+1);
			return 1;
		}
		else{
			printf("Non hai all'interno della rubrica l'utente cercato\n");
			//scanf("%d",&inserire);
			return 0;		
		}
	
}	

int cancella_utente(utente *r,int m){
	int i=0;
	utente da_cancellare;
	
	printf("Inserisci nome e cognome dell'utente da cancellare:\n");
	scanf("%s%s",da_cancellare.nome,da_cancellare.cognome);
	
	while(((strcmp((r+i)->cognome, da_cancellare.cognome)!=0)&&(strcmp((r+i)->nome, da_cancellare.nome)!=0))&&(i<m)){
		i++;
		}
		
		if(i<m){
			printf("Utente da cancellare trovato alla posizione %d\n",i+1);
			strcpy((r+i)->nome, "none");
			strcpy((r+i)->cognome, "none");
			(r+i)->num_di_t=0;
			return 1;
		}
		else{
			printf("Non hai all'interno della rubrica l'utente cercato\n");
			//scanf("%d",&inserire);
			return 0;		
	}
}

/* int inserisci_utente_ultimo(untente *r,int dim1){
	int i;
	
		while(((r+i)->num_di_t)!=0){
	i++;
	}
	
	*/	
