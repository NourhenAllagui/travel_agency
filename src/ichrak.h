#include <gtk/gtk.h>
typedef struct {
char id[30];
char lieu[30];
char nom[30];
int e;
char chambre[30];
char prix[30]; 
int p;}hotel;
typedef struct {
char id[30];
char dep[30];
char arr[30];
int jv;
int mv;
int av;
char heure[30];
char type[30];
char prixv[30];
 int pl;}vol;


//////////////hotel
void afficherh(GtkWidget *liste);
void ajouterh(hotel h);
void modifierh(hotel h);
void supprimerh(hotel h);
////////////////vol
void afficherv(GtkWidget *liste);
void ajouterv(vol v);
void modifierv(vol v);
void supprimerv(vol v);
