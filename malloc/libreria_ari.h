
#define M 15
#define dim 500
#define dim1 100

struct pers{
	char *nome;
	char *cognome;
	int num_di_t;
	int immagine[dim][dim];
	struct pers *next;
	};
	
	typedef struct pers utente;
	
	int ricerca(utente *,char *, char *);
	void ordina_cognomi(utente *);  
	int cancella_utente(utente *,char *, char *, utente *);
	int inserisci(utente *, utente*);
