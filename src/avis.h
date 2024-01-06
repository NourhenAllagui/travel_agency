#include <gtk/gtk.h>



typedef struct
{
char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];


}admin;


void afficher_avis(GtkWidget *liste);
void supprimer_avis(char x[]);
void modifier_avis(y,z);
void date_a (char dt[]);

