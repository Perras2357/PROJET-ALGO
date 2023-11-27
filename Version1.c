#include <stdio.h>
#include <stdlib.h>

/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                                               */
/*************************************************/

#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

typedef enum { FALSE, TRUE} bool;

/*************************************************/
/*                                               */
/*          definition type liste                */
/*                                               */
/*************************************************/

typedef struct element {
    int data;          
    struct element* next;  
} Bloc;

typedef Bloc* Liste ;

/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/

/* initialise une Liste � vide */
void initVide(Liste *L);

/* renvoie 1 si la Liste en parametre est vide, 0 sinon */
bool estVide(Liste l);

/* renvoie le premier element de la Liste en parametre */
int premier(Liste l);

/* renvoie une nouvelle Liste correspondant a celle en parametre, avec l'element x ajoute en haut de la pile */
Liste ajoute(int x, Liste l);

/* modifie la Liste en parametre: x est ajoute comme premier element */
void empile(int x, Liste* L);

/* renvoie une nouvelle Liste correspondant a celle en parametre sans son premier element */
Liste suite(Liste l);

/* modifie la Liste en parametre: le premier element est retire */
void depile(Liste* l);

/* affichage simple en recursif et en iteratif */
void affiche_rec(Liste l);
void affiche_iter(Liste l);

/* longueur en recursif et en iteratif */
int longueur_rec (Liste l);
int longueur_iter (Liste l);

/*  Elimination du dernier element en recursif et en iteratif  */
/*  VD est la sousprocedure utilitaire de la version recursive */
void VD (Liste *L);
void VireDernier_rec (Liste *L);
void VireDernier_iter (Liste *L);


/*************************************************/
/*                                               */
/*                briques de base                */
/*                                               */
/*************************************************/


void initVide( Liste *L)
{
    *L = NULL ;
}

bool estVide(Liste l)
{
    return l == NULL ;
}

int premier(Liste l)
{
    return l->data ; 
}

Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
    tmp->data = x ;
    tmp->next = l ;
    return tmp ;
}

void empile(int x, Liste *L)
{
      *L = ajoute(x,*L) ; 
}


Liste suite(Liste l)
{
    return l->next ;
}


void depile(Liste *L)
{
    Liste tmp = *L ;
    *L = suite(*L) ;
    free(tmp) ;
}

/*************************************************/
/*                                               */
/*     Affiche, avec les briques de base         */
/*                                               */
/*************************************************/

void affiche_rec(Liste l)
{
    if(estVide(l))
        printf("\n");
    else
    {
        printf("%d ", premier(l));
        affiche_rec(suite(l));
    }
}


void affiche_iter(Liste l)
{
    Liste L2 = l;
    while(!estVide(L2))
    {
        printf("%d ", premier(L2));
        L2 = suite(L2);
    }
    printf("\n");
}

/*************************************************/
/*                                               */
/*     Longueur, sans les briques de base        */
/*                                               */
/*************************************************/

int longueur_rec (Liste l)
{
    if (l == NULL)
         return 0 ;
    else return (1 + longueur_rec(l->next)) ;
}


int longueur_iter (Liste l)
{
    Liste P = l;
    int cpt = 0 ;
    while (P ISNOT NULL)
    {   P = P->next ;
        cpt++ ;
    }
    return cpt ;
}

/*************************************************/
/*                                               */
/*       VireDernier,                            */
/*               sans les briques de base,       */
/*               ni le "->"                      */
/*                                               */
/*************************************************/

void VD (Liste *L)
          // *L non NULL ie liste non vide
{
     if ( ((**L).next) == NULL )
            depile(L) ;   // moralement : depile(& (*L)) ;
     else VD (& ( (**L).next )) ;
}

void VireDernier_rec (Liste *L)
{
     if ( (*L) ISNOT NULL )
          VD(L);        // moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L)
{
    if ( (*L) ISNOT NULL)
    {
        while ( ((**L).next) ISNOT NULL )
                 L = & ( (**L).next ) ;
        free(*L) ;
        *L = NULL ;
     }
}


/*************************************************/
/*                                               */
/*       Libere la memoire                       */
/*                                               */
/*************************************************/

void VideListe(Liste *L)
{
    if(NOT(estVide(*L)))
    {
        depile(L);
        VideListe(L);
    }
      
}
/*************************************************/
/*                                               */
/*           Croissante                           */
/*                                               */
/*************************************************/
bool croissante(Liste head) {
    Liste current = head;
    
         while (NOT estVide(current) AND NOT estVide(suite(current))) {
            
             if( (premier(current) > premier(suite(current))) ){
                 return FALSE ;
             }
            current = suite(current);    
        }
        return TRUE ;
       
}

/*************************************************/
/*                                               */
/*          NombreMemePosition                    */
/*                                               */
/*************************************************/
int compareElements1(Liste list1, Liste list2) {
    int  i = 0; Liste tmp1 = list1; Liste tmp2 = list2;
    while (NOT estVide(tmp1) AND NOT estVide(tmp2)) {
       
        if (premier(tmp1) == premier(tmp2)) {
            i = i+1 ;  
        }
        tmp1 = suite(tmp1);
        tmp2 = suite(tmp2);
    }
    return i;
}


int compareElements2(Liste list1, Liste list2) {
    int  i = 0; Liste tmp1 = list1; Liste tmp2 = list2;
    if ( estVide(tmp1)  OR estVide(tmp2) ) {
        return 0 ;
    } else {
        
           if (premier(list1) == premier(list2)) {
                i = i+1 ;  
            }
    }
    return i + compareElements2(suite(tmp1) , suite(tmp2));
}


void S_compareElements(Liste list1, Liste list2, int *nbre){
    
     if ( NOT estVide(list1) && NOT estVide(list2)) {
        
           if (premier(list1) ==  premier(list2)) {
               *nbre += 1 ;
               S_compareElements( suite(list1) , suite(list2) ,nbre); 
            } else {
               
                S_compareElements(suite(list1) , suite(list2) ,nbre); 
            }  
    }
} 

int compareElements3(Liste list1, Liste list2) {
    int nbre = 0 ;
     S_compareElements(list1,list2,&nbre);
    return nbre ; 
}


/*************************************************/
/*                                               */
/*           AjouteDevantPremierZero              */
/*                                               */
/*************************************************/

 void AjoutePremierZero( Liste *L , int x ){
    if (estVide(*L) || premier(*L) == 0)
    {
        empile(x,L);
        return;
    }
    else
        AjoutePremierZero( &((*L)->next) ,x );
        
}

/*************************************************/
/*                                               */
/*  AjouteDevantDernierZero                      */
/*                                               */
/*************************************************/
void SousAjoute( Liste *L, int x , Liste *M){
    if(estVide(*L)){
        if( estVide(*M)){
            empile(x,L);
        } else {
            empile(x,M);
        }
    }else{
        if( premier(*L)==0){
            M = L ;
            SousAjoute( &((*L)->next) , x , M );
        } else {
            SousAjoute( &((*L)->next) , x , M );
        }
        
    }
}

void AjouteDernierZero( Liste *L , int x ){
    Liste *M = NULL ;
     SousAjoute( L, x , M);
}

/*************************************************/
/*                                               */
/*                TIC                            */
/*                                               */
/*************************************************/
void TIC( Liste *L ){ 
    Liste tmp1 = NULL ;
    if( estVide(*L) OR premier(*L)==0){
        return;
    } else {
        
        /* je recupere tout les entiers non nul avant le dernier zero a delete*/
        while(!estVide(*L)){
            if(premier(*L)==0 && premier(suite(*L)) !=0 ){
               (*L) = suite(*L) ; break ;
            } else if (premier(*L) != 0) {
               empile ( premier(*L),&tmp1);
            }   
          (*L) = suite(*L) ;
        }
        
        /* j'enpile ses elements dans la liste en ajoutant un zero devant chaque nombre*/
        while(!estVide(tmp1)){
            empile(premier(tmp1),L);
            empile(0,L);
            (tmp1) = suite(tmp1) ;
        }  
    }
}

/*************************************************/
/*                                               */
/*           Main                                */
/*                                               */
/*************************************************/

void poup (Liste l)
{
        printf("Double Affichage \n") ;
        affiche_rec(l) ;
        affiche_iter(l) ;

        printf("Longueur en double %d %d \n\n", 
                           longueur_rec(l), 
                           longueur_iter(l) 
               ) ;
}



int main(int argc, char** argv)
{
    Liste list1 = NULL; Liste list2 = NULL;
    int elementsList1[] = {3,7,2,0,0,0,8,9,0,0,2,1}; int elementsList2[] = {1,7,3,0,6,0,0,5,8,9,10};

    for (int i = 0; i < sizeof(elementsList1) / sizeof(elementsList1[0]); ++i) {
        empile( elementsList1[i],&list1);
    }

    for (int i = 0; i < sizeof(elementsList2) / sizeof(elementsList2[0]); ++i) {
        empile(elementsList2[i],&list2);
    }

    if(FALSE){
        printf(" La valeur de retour est:  %d \n", croissante(list1));
    }

    if(FALSE){
        printf("le nombre de x a la meme position est : %d\n",compareElements2(list1, list2));
        printf("le nombre de x a la meme position est : %d\n",compareElements1(list1, list2));
        printf("le nombre de x a la meme position est : %d\n",compareElements3(list1, list2));
    }

    if(FALSE){
        printf("la liste avant Ajout est: "); affiche_rec(list1);
        AjoutePremierZero(&list1 , 2) ;
        printf("\n"); printf("la liste aprés Ajout est: "); affiche_rec(list1);
    }

    if(TRUE){
        printf("la liste avant modification est: "); affiche_rec(list1);
        AjouteDernierZero(&list1,9);
        printf("\n"); printf("la liste aprés modification est: "); affiche_rec(list1);
    }

    if(FALSE){
        printf("la liste avant la fonction TIC est: ");affiche_rec(list1);
         TIC( & list1);
        printf("la liste apréz la fonction TIC est: ");affiche_rec(list1);
    }
  /*  Liste l ;

        initVide (&l) ;

          poup(l) ;

             empile(4, &l) ;

          poup(l) ;

             empile(5, &l) ;
             empile(6, &l) ;
             empile(7, &l) ;
             empile(8, &l) ;
             empile(9, &l) ;

          poup(l) ;

        VireDernier_rec  (&l) ;
        VireDernier_iter (&l) ;
        depile(& l) ;

          poup(l) ;

    VideListe(&l);*/
    return 0;
}

