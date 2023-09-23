
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definition of the linked list

struct noeud{
    int x;
    struct noeud *suivant;
    };
typedef struct noeud Noeud;


typedef Noeud *liste;


liste* listecreer ()
/* créer une liste vide */
{
return (NULL);
}

char estvide(liste *l){
    return (l==NULL);
}

liste adjq(int el, liste ancienne)
/* ajoute en queue l’élément el à la liste ancienne */
{liste y, courant; /*création de l’élément à rajouter*/
y= (Noeud *) malloc (sizeof (Noeud));
y->x= el;
y->suivant= NULL;
if (!ancienne) /*ajout à une liste vide */
ancienne=y;
else { courant= ancienne;
while (courant->suivant)
courant=courant->suivant;
courant->suivant=y;
}
return ancienne;
}

liste supprimerpremier (liste tete)
{ liste p;
if (tete != NULL)
{   p=tete;
    tete= tete->suivant;
    free(p); }
return (tete);
}

int main()
{
    int k;
    printf("Give the number of digits"); // We start by reading the number of digits of a number
    scanf("%d",&k);
    printf("Enter the number of elements in the list"); // We give the number of elements in the list
    int nb;
    scanf("%d",&nb);
    int i=0;
    liste l= listecreer(); // We create the list where we will store the numbers
   while(i<nb){
       int d;
       do{
        printf("Give an element"); // We fill in the list
        scanf("%d",&d);
      }while(d>pow(10,k));
       l=adjq(d,l);
       i++;}
       liste lbis=listecreer(); // This list is created to display the elements of the list l
       lbis=l;
    printf("the unsorted list is : \n");
    while(lbis!=NULL){
        int el=lbis->x;
        printf("%d\n",el);
        lbis=lbis->suivant;
    }

    liste baquet[10]; // We create our bucket and we initialize it
    for(int i=0;i<10;i++){
        baquet[i]=listecreer();
    }
    static int puiss = 1;

    for(int i=0;i<k;i++) // We do this work for the number of digits indicated
        {
           liste l1=listecreer(); // In order not to lose the elements, they are stored in another list
                                  
       	    l1=l;
            while(l1!=NULL)
                {
                    int el=(l1->x)% (10 * puiss)/puiss;  // We fill our bucket according to the criteria
                    baquet[el]=adjq(l1->x,baquet[el]);
                    l1=l1->suivant;
            }
            while(l!=NULL)
            {
                l=supprimerpremier(l); // We delete the elements of our list in order to restock them in the new order
            }
            for(int j=0;j<10;j++)
            {
                        while(baquet[j]!=NULL) // We fill our sorted list
                        {
                            int el=baquet[j]->x;
                            l=adjq(el,l);
                            baquet[j]=baquet[j]->suivant;
                        }
            }

            puiss *= 10;
        }

    printf("la liste triee est : \n"); // Finally we print our sorted list
    while(l!=NULL){
        int el1=l->x;
        printf("%d\n",el1);
        l=l->suivant;
    }




 }


