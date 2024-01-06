#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ichrak.h"
#include "verif.h"
#include "string.h"
#include "fonctions.h"
#include "controle_saisie.h"
#include "avis.h"




void
on_button1n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *notebook1;
GtkWidget *treeview1n;
window1=lookup_widget(button,"window1");
notebook1=lookup_widget(window1,"notebook1");
treeview1n=lookup_widget(notebook1,"treeview1n");
afficherv(treeview1n);
}


void
on_button2n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouvol,*window1,*notebook1;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
ajouvol=create_ajouvol();
gtk_widget_show(ajouvol);
}


void
on_button3n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *notebook1;
GtkWidget *treeview2n;
 window1=lookup_widget(button,"window1");
 notebook1=lookup_widget(window1,"notebook1");
 treeview2n=lookup_widget(notebook1,"treeview2n");
afficherh(treeview2n);
}


void
on_button5n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *window1;
GtkWidget *notebook1;
GtkWidget *treeview3n;
 window1=lookup_widget(button,"window1");
 notebook1=lookup_widget(window1,"notebook1");
 treeview3n=lookup_widget(notebook1,"treeview3n");
afficher1(treeview3n);*/
}


void
on_button6n_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*
GtkWidget *ajouexcu,*window1,*notebook1;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
ajouexcu=create_ajouexcu();
gtk_widget_show(ajouexcu);*/
}


void
on_button7n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*
excursion p;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *ajouexcu,*window1;
GtkWidget *nj,*nm,*na,*np;

input1= lookup_widget(objet_graphique,"entry1n");
input2= lookup_widget(objet_graphique,"entry2n");
input3= lookup_widget(objet_graphique,"entry3n");
input4= lookup_widget(objet_graphique,"entry4n");
ajouexcu= lookup_widget(objet_graphique,"ajouexcu");
window1= lookup_widget(objet_graphique,"window1");


nj=lookup_widget(objet_graphique,"spinbutton1n");
nm=lookup_widget(objet_graphique,"spinbutton2n");
na=lookup_widget(objet_graphique,"spinbutton3n");
np=lookup_widget(objet_graphique,"spinbutton4n");


p.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
p.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
p.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
p.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));


strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
ajouter1(p);
gtk_widget_hide(ajouexcu);*/
}



void
on_button8n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget ajouexcu;

     ajouexcu=lookup_widget(button,"ajouexcu");
     gtk_widget_hide(ajouexcu);*/
}


void
on_treeview1n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *modifvol,*window1,*notebook1;
GtkWidget *treeview1n;
GtkWidget *idn,*depn,*arrn,*prixn,*heuren,*typen,*jn,*mn,*an,*pn;


gchar *id,*dep,*arr,*prix,*heure,*type;
gint *j,*m,*a,*p;

window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
modifvol=create_modifvol();
treeview1n=lookup_widget(notebook1,"treeview1n");

idn=lookup_widget(modifvol,"entrykh1");
depn=lookup_widget(modifvol,"entrykh2");
arrn=lookup_widget(modifvol,"entrykh3");
heuren=lookup_widget(modifvol,"entrykh4");
prixn=lookup_widget(modifvol,"entrykh5");
jn=lookup_widget(modifvol,"spinbuttonkh1");
mn=lookup_widget(modifvol,"spinbuttonkh2");
an=lookup_widget(modifvol,"spinbuttonkh3");
pn=lookup_widget(modifvol,"spinbuttonkh4");


typen=lookup_widget(modifvol,"comboboxentrykh1");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&dep,2,&arr,3,&j,4,&m,5,&a,6,&heure,7,&type,8,&prix,9,&p,-1);
	printf("%s %s %s %d %d %d %s %s %s %d",id,dep,arr,j,m,a,heure,type,prix,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (depn),_(dep));
        gtk_entry_set_text(GTK_ENTRY (arrn),_(arr));
	gtk_entry_set_text(GTK_ENTRY (heuren),_(heure));
	gtk_entry_set_text(GTK_ENTRY (typen),_(type));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
gtk_widget_show(modifvol);
}


void
on_treeview3n_row_activated           (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{/*
GtkWidget *modifexcu,*window1,*notebook1;
GtkWidget *treeview3n;
GtkWidget *idn,*desn,*progn,*prixn,*jn,*mn,*an,*pn;
gchar *id,*des,*prog,*prix;
gint *j,*m,*a,*pp;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
modifexcu=create_modifexcu();
treeview3n=lookup_widget(notebook1,"treeview3n");
idn=lookup_widget(modifexcu,"entry5n");
desn=lookup_widget(modifexcu,"entry6n");
progn=lookup_widget(modifexcu,"entry7n");
prixn=lookup_widget(modifexcu,"entry8n");
jn=lookup_widget(modifexcu,"spinbutton5n");
mn=lookup_widget(modifexcu,"spinbutton6n");
an=lookup_widget(modifexcu,"spinbutton7n");
pn=lookup_widget(modifexcu,"spinbutton8n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview3n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&des,2,&j,3,&m,4,&a,5,&prog,6,&prix,7,&pp,-1);
	printf("%s %s %d %d %d %s %s %d",id,des,j,m,a,prog,prix,pp);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (desn),_(des));
        gtk_entry_set_text(GTK_ENTRY (progn),_(prog));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
gtk_widget_show(modifexcu);*/
}


void
on_button9n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *modifexcu;

     modifexcu=lookup_widget(button,"modifexcu");
     gtk_widget_hide(modifexcu);*/
}


void
on_button11n_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{/*
GtkWidget *modifexcu;
 GtkWidget *id,*des,*prog,*prix,*j,*m,*a,*pl;

excursion p;
  /* char idk[20],desk[20],progk[20],prixk[20];
	int jk,mk,ak,pk;
modifexcu=lookup_widget(button,"modifexcu");
   

id=lookup_widget(button,"entry5n");
 
des=lookup_widget(button,"entry6n");
prog=lookup_widget(button,"entry7n");
prix=lookup_widget(button,"entry8n");


j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	 strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	o.j = gtk_spin_button_get_value_as_int(j);
        o.m = gtk_spin_button_get_value_as_int(m); 
	o.a = gtk_spin_button_get_value_as_int(a);
       o.p= gtk_spin_button_get_value_as_int(pl);	
	supprimero(p);
gtk_widget_hide(modifexcu);*/
}


void
on_button10n_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{/*

 GtkWidget *modifexcu;
 GtkWidget *id,*des,*prog,*prix,*j,*m,*a,*pl;
excursion p;

   char idk[20],desk[20],progk[20],prixk[20];
	int jk,mk,ak,pk;
modifexcu=lookup_widget(button,"modifexcu");
   

id=lookup_widget(button,"entry5n");
 
des=lookup_widget(button,"entry6n");
prog=lookup_widget(button,"entry7n");
prix=lookup_widget(button,"entry8n");


j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	 strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	p.j = gtk_spin_button_get_value_as_int(j);
        p.m = gtk_spin_button_get_value_as_int(m); 
	p.a = gtk_spin_button_get_value_as_int(a);
       p.p = gtk_spin_button_get_value_as_int(pl);	
	modifier1(p);
gtk_widget_hide(modifexcu);*/


}

///////////////////////hotel//////////////////////
void
on_button12nn_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
hotel h;

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *ajouhotel,*window1;
GtkWidget *ne,*np,*CHAMBRE;

input1= lookup_widget(objet_graphique,"entry1nn");
input2= lookup_widget(objet_graphique,"entry2nn");
input3= lookup_widget(objet_graphique,"entry3nn");
input4= lookup_widget(objet_graphique,"entry4nn");
ajouhotel= lookup_widget(objet_graphique,"ajouhotel");
window1= lookup_widget(objet_graphique,"window1");

CHAMBRE=lookup_widget(objet_graphique,"comboboxentry1nn");
ne=lookup_widget(objet_graphique,"spinbutton1nn");
np=lookup_widget(objet_graphique,"spinbutton2nn");



h.e=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ne));
h.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(h.chambre,gtk_combo_box_get_active_text (GTK_COMBO_BOX(CHAMBRE)));
ajouterh(h);
gtk_widget_hide(ajouhotel);
}


void
on_button13nn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouhotel;

     ajouhotel=lookup_widget(button,"ajouhotel");
     gtk_widget_hide(ajouhotel);
}


void
on_button4n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouhotel,*window1,*notebook1;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
ajouhotel=create_ajouhotel();
gtk_widget_show(ajouhotel);
}


void
on_treeview2n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *modifhotel,*window1,*notebook1;
GtkWidget *treeview2n;
GtkWidget *idn,*lieun,*nomn,*prixn,*en,*pn,*chambren;
gchar *id,*lieu,*nom,*prix,*chambre;
gint *e,*p;

window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
modifhotel=create_modifhotel();
treeview2n=lookup_widget(notebook1,"treeview2n");

idn=lookup_widget(modifhotel,"entry100n");
lieun=lookup_widget(modifhotel,"entry200n");
nomn=lookup_widget(modifhotel,"entry300n");
prixn=lookup_widget(modifhotel,"entry400n");
en=lookup_widget(modifhotel,"spinbutton100n");
pn=lookup_widget(modifhotel,"spinbutton200n");

chambren=lookup_widget(modifhotel,"comboboxentry100n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview2n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&lieu,2,&nom,3,&e,4,&chambre,5,&prix,6,&p,-1);
	printf("%s %s %s %d %s %s %d",id,lieu,nom,e,chambre,prix,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (lieun),_(lieu));
        gtk_entry_set_text(GTK_ENTRY (nomn),_(nom));
	gtk_entry_set_text(GTK_ENTRY (chambren),_(chambre));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
gtk_widget_show(modifhotel);
}


void
on_button102n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;
GtkWidget *id,*lieu,*nom,*e,*chambre,*prix,*p;

hotel h;
  /* char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");
prix=lookup_widget(objet_graphique,"entry400n");


e=lookup_widget(modifhotel,"spinbutton100n");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	 strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);

        h.p = gtk_spin_button_get_value_as_int(p); 
		
	supprimerh(h);
gtk_widget_hide(modifhotel);
}


void
on_button101n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;
 GtkWidget *id,*lieu,*nom,*e,*chambre,*prix,*p;

hotel h;
   /*char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");
prix=lookup_widget(objet_graphique,"entry400n");


e=lookup_widget(modifhotel,"spinbutton100n");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	 strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);

        h.p = gtk_spin_button_get_value_as_int(p); 
		
	modifierh(h);
gtk_widget_hide(modifhotel);
}


void
on_button100n_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;

     modifhotel=lookup_widget(button,"modifhotel");
     gtk_widget_hide(modifhotel);
}

////////////////ajout d une vol ///////////////////////////////////

void
on_button01n_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
vol v;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *ajouvol,*window1;
GtkWidget *nj,*nm,*na,*np,*TYPE;

input1= lookup_widget(objet_graphique,"entry01n");
input2= lookup_widget(objet_graphique,"entry02n");
input3= lookup_widget(objet_graphique,"entry03n");
input4= lookup_widget(objet_graphique,"entry04n");
input5= lookup_widget(objet_graphique,"entry05n");
ajouvol= lookup_widget(objet_graphique,"ajouvol");
window1= lookup_widget(objet_graphique,"window1");

TYPE=lookup_widget(objet_graphique,"comboboxentry01n");
nj=lookup_widget(objet_graphique,"spinbutton01n");
nm=lookup_widget(objet_graphique,"spinbutton02n");
na=lookup_widget(objet_graphique,"spinbutton03n");
np=lookup_widget(objet_graphique,"spinbutton04n");



v.jv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
v.mv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
v.av=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
v.pl=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(v.type,gtk_combo_box_get_active_text (GTK_COMBO_BOX(TYPE)));
ajouterv(v);
gtk_widget_hide(ajouvol);
}


void
on_buttonkh1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifvol;

     modifvol=lookup_widget(button,"modifvol");
     gtk_widget_hide(modifvol);
}


void
on_buttonkh2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifvol;
GtkWidget *id,*dep,*arr,*j,*m,*a,*heure,*type,*prix,*p;


   vol v;
modifvol=lookup_widget(objet_graphique,"modifvol");
   

id=lookup_widget(objet_graphique,"entrykh1");
 
dep=lookup_widget(objet_graphique,"entrykh2");
arr=lookup_widget(objet_graphique,"entrykh3");
heure=lookup_widget(objet_graphique,"entrykh4");
prix=lookup_widget(objet_graphique,"entrykh5");


j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	 strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
        v.pl = gtk_spin_button_get_value_as_int(p); 
		
	modifierv(v);
gtk_widget_hide(modifvol);
}


void
on_buttonkh3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifvol;
GtkWidget *id,*dep,*arr,*j,*m,*a,*heure,*type,*prix,*p;


   vol v;
modifvol=lookup_widget(objet_graphique,"modifvol");
   

id=lookup_widget(objet_graphique,"entrykh1");
 
dep=lookup_widget(objet_graphique,"entrykh2");
arr=lookup_widget(objet_graphique,"entrykh3");
heure=lookup_widget(objet_graphique,"entrykh4");
prix=lookup_widget(objet_graphique,"entrykh5");


j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	 strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
        v.pl = gtk_spin_button_get_value_as_int(p); 
		
	supprimerv(v);
gtk_widget_hide(modifvol);
}


void
on_Afficher_agent_clicked         (GtkWidget     *objet_graphique,
                                   gpointer       user_data)
{
GtkWidget *window3s,*treeview1;
window3s=lookup_widget(objet_graphique,"window3s");
treeview1=lookup_widget(window3s,"treeview1");
afficherfiche(treeview1);
}

void
on_treeview1_row_activated             (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


gchar*id,*password,*nom,*prenom,*e_mail,*adresse,*num_tel,*sexe,*jour,*mois,*annee;

GtkWidget*window5s,*window3s,*idNU,*passwordNU,*nomNU,*prenomNU,*e_mailNU,*adresseNU,*num_telNU,*jourNU,*moisNU,*anneeNU,*sexeNU,*treeview;
	
	window5s=create_window5s();	
	treeview=lookup_widget(objet_graphique,"treeview1");
	    	
	window3s=lookup_widget(objet_graphique,"window3s");
 
    	idNU=lookup_widget(window5s, "entry15s");
	passwordNU=lookup_widget(window5s,"entry16s");
	nomNU=lookup_widget(window5s, "entry8s");
	prenomNU=lookup_widget(window5s,"entry9s");
	e_mailNU=lookup_widget(window5s, "entry10s");
	num_telNU=lookup_widget(window5s, "entry11s");
	jourNU=lookup_widget(window5s, "spinbutton4s");
	moisNU=lookup_widget(window5s, "spinbutton5s");
	anneeNU=lookup_widget(window5s, "spinbutton6s");
	adresseNU=lookup_widget(window5s, "entry12s");
	sexeNU=lookup_widget(window5s, "combobox2s");

    GtkTreeIter iter;
    GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
    gtk_tree_model_get_iter(model,&iter,path);
    gtk_tree_model_get (model,&iter,0,&id,1,&password,2,&nom,3,&prenom,4,&e_mail,5,&num_tel,9,&adresse,-1);
    printf("%s %s %s %s %s %s %s %s %s %s %s\n",id,password,nom,prenom,e_mail,num_tel,jour,mois,annee,adresse,sexe);
    
    gtk_entry_set_text(GTK_ENTRY (idNU),_(id));
    gtk_entry_set_text(GTK_ENTRY (passwordNU),_(password));
    gtk_entry_set_text(GTK_ENTRY (nomNU),_(nom));
    gtk_entry_set_text(GTK_ENTRY (prenomNU),_(prenom));
    gtk_entry_set_text(GTK_ENTRY (e_mailNU),_(e_mail));
    gtk_entry_set_text(GTK_ENTRY (num_telNU),_(num_tel));
    gtk_entry_set_text(GTK_ENTRY (jourNU),_(jour));
    gtk_entry_set_text(GTK_ENTRY (moisNU),_(mois));
    gtk_entry_set_text(GTK_ENTRY (anneeNU),_(annee));
    gtk_entry_set_text(GTK_ENTRY (adresseNU),_(adresse));
    gtk_entry_set_text(GTK_ENTRY (sexeNU),_(sexe)); 
    gtk_widget_hide(window3s);
    gtk_widget_show(window5s);
}




void
on_ajout_agent_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window4s,*window3s;


window4s=create_window4s();
gtk_widget_show (window4s);
window3s=lookup_widget(objet_graphique,"window3s");
gtk_widget_hide(window3s);	



}


void
on_modif_agent_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window3s,*window5s;


window5s=create_window5s();
gtk_widget_show (window5s);
window3s=lookup_widget(objet_graphique,"window3s");
gtk_widget_hide(window3s);	


}



void
on_retour_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*GtkWidget *window4,*window3,*List_View;

window4=lookup_widget(objet_graphique,"window4s");
window3s=create_window3s();
gtk_widget_hide(window4s);
List_View=lookup_widget(window3s,"treeview1");
afficherfiche(List_View);
gtk_widget_show (window3s);	*/



}


void
on_confirmer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
fiche fi;
GtkWidget *id,*password,*nom,*prenom,*e_mail,*adresse,*sexe,*jour,*mois,*annee ,*num_tel,*pass1;
GtkWidget *window3s,*window4s,*List_View;
GtkWidget *output;
char pass[20];
id=lookup_widget(objet_graphique, "entry13s");
password=lookup_widget(objet_graphique,"entry14s");
nom=lookup_widget(objet_graphique, "entry3s");
prenom=lookup_widget(objet_graphique,"entry4s");
e_mail=lookup_widget(objet_graphique, "entry5s");
jour=lookup_widget(objet_graphique, "spinbutton1s");
mois=lookup_widget(objet_graphique, "spinbutton2s");
annee=lookup_widget(objet_graphique, "spinannees");
adresse=lookup_widget(objet_graphique, "entry7s");
num_tel=lookup_widget(objet_graphique, "entry6s");
sexe=lookup_widget(objet_graphique, "combobox1s");
pass1=lookup_widget(objet_graphique, "entry17s");

strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(fi.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mail)));
strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
fi.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
fi.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
fi.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pass1)));

output= lookup_widget(objet_graphique, "label33s");
 if ((controle_saisie_numtel(fi.num_tel)==0)||(controle_saisie_nonvide(fi.nom)==0)||(controle_saisie_nonvide(fi.prenom)==0)||(controle_saisie_nonvide(fi.password)==0)||(controle_saisie_nonvide(fi.adresse)==0)||(controle_saisie_nonvide(fi.e_mail)==0)||(controle_saisie_pwd(fi.password,pass)==0))
{
gtk_label_set_text(GTK_LABEL(output), "veuillez verifier votre saisie !");
}
else {

ajouterfiche(fi);
window3s=create_window3s();
gtk_widget_show (window3s);
window4s=lookup_widget(objet_graphique,"window4s");
gtk_widget_hide(window4s);
List_View=lookup_widget(window3s,"treeview1");
afficherfiche(List_View);	
}
}


void
on_retour_Administrateur_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5s,*window3s,*List_View;


window3s=create_window3s();
gtk_widget_show (window3s);
window5s=lookup_widget(objet_graphique,"window5s");
gtk_widget_hide(window5s);
List_View=lookup_widget(window3s,"treeview1");
afficherfiche(List_View);
		



}


void
on_confirmer_modif_agent_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id1,*password1,*nom1,*prenom1,*e_mail1,*adresse1,*sexe1,*jour1,*mois1,*annee1 ,*num_tel1,*pass2,*window3s,*window5s,*List_View;
GtkWidget *output;
   fiche fi;

    char      id[20],password[20], nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50];
   int jour,mois,annee;
   char pass[20]; 
        id1=lookup_widget(objet_graphique, "entry15s");
	password1=lookup_widget(objet_graphique,"entry16s");   
        nom1=lookup_widget(objet_graphique, "entry8s");
	prenom1=lookup_widget(objet_graphique,"entry9s");
	e_mail1=lookup_widget(objet_graphique, "entry10s");
	jour1=lookup_widget(objet_graphique, "spinbutton4s");
	mois1=lookup_widget(objet_graphique, "spinbutton5s");
	annee1=lookup_widget(objet_graphique, "spinbutton6s");
	adresse1=lookup_widget(objet_graphique, "entry12s");
	num_tel1=lookup_widget(objet_graphique, "entry11s");
	sexe1=lookup_widget(objet_graphique, "combobox2s");
        pass2=lookup_widget(objet_graphique, "entry18s");
        output= lookup_widget(objet_graphique, "label36s");
    
strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(fi.password,gtk_entry_get_text(GTK_ENTRY(password1)));
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mail1)));
strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe1)));
jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour1));
mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois1));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_tel1)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresse1)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pass2)));

fi.jour=jour;
fi.mois=mois;
fi.annee=annee;
 if ((controle_saisie_numtel(fi.num_tel)==0)||(controle_saisie_nonvide(fi.nom)==0)||(controle_saisie_nonvide(fi.prenom)==0)||(controle_saisie_nonvide(fi.password)==0)||(controle_saisie_nonvide(fi.adresse)==0)||(controle_saisie_nonvide(fi.e_mail)==0)||(controle_saisie_pwd(fi.password,pass)==0))
{
gtk_label_set_text(GTK_LABEL(output), "veuillez verifier votre saisie !"); 
}
else {
   modifierfiche(fi.id,fi.password,fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe);

    window3s=create_window3s();
    gtk_widget_show(window3s);
    window5s=lookup_widget(objet_graphique,"window5s");
    gtk_widget_hide(window5s);
    List_View=lookup_widget(window3s,"treeview1");
    afficherfiche(List_View);
}
}

void
on_supprimer_agent_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *idNU,*passwordNU,*nomNU,*prenomNU,*e_mailNU,*adresseNU,*num_telNU,*jourNU,*moisNU,*anneeNU,*sexeNU,*window3s,*window5s,*List_View;

 
    fiche fi;
 char  id[20],password[20],nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50]; 
int jour,mois,annee;
    
	idNU=lookup_widget(objet_graphique, "entry15s");
	passwordNU=lookup_widget(objet_graphique,"entry16s");	
	nomNU=lookup_widget(objet_graphique, "entry8s");
	prenomNU=lookup_widget(objet_graphique,"entry9s");
	e_mailNU=lookup_widget(objet_graphique, "entry10s");
	jourNU=lookup_widget(objet_graphique, "spinbutton4s");
	moisNU=lookup_widget(objet_graphique, "spinbutton5s");
	anneeNU=lookup_widget(objet_graphique, "spinbutton6s");
	adresseNU=lookup_widget(objet_graphique, "entry12s");
	num_telNU=lookup_widget(objet_graphique, "entry11s");
	sexeNU=lookup_widget(objet_graphique, "combobox2s");



strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY(idNU)));
strcpy(fi.password,gtk_entry_get_text(GTK_ENTRY(passwordNU)));
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY(nomNU)));
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY(prenomNU)));
strcpy(fi.e_mail,gtk_entry_get_text(GTK_ENTRY(e_mailNU)));
//strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexeNU)));

strcpy(fi.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexeNU)));
//strcpy(fi.type_de_voyage" ");
jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourNU));
mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisNU));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneeNU));
strcpy(fi.num_tel,gtk_entry_get_text(GTK_ENTRY(num_telNU)));
strcpy(fi.adresse,gtk_entry_get_text(GTK_ENTRY(adresseNU)));

fi.jour=jour;
fi.mois=mois;
fi.annee=annee;

//,prenom,e_mail,num_tel,jour,mois,annee,adresse
    supprimerfiche(fi.id,fi.password,fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe);
    
    window3s=create_window3s();
    gtk_widget_show(window3s);
    window5s=lookup_widget(objet_graphique,"window5s");
    gtk_widget_hide(window5s);
    List_View=lookup_widget(window3s,"treeview1");
    afficherfiche(List_View);

}





void
on_button_return_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4s,*window3s,*List_View;

window4s=lookup_widget(objet_graphique,"window4s");
window3s=create_window3s();
gtk_widget_hide(window4s);
List_View=lookup_widget(window3s,"treeview1");
afficherfiche(List_View);
gtk_widget_show (window3s);

}




void
on_login_button_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonlogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*pagedacceil; 
GtkWidget*loginwindow;
//pagedacceil=create_pagedacceil(); 
//gtk_widget_show(pagedacceil);
loginwindow=create_loginwindow();
gtk_widget_show(loginwindow);
//loginwindow=lookup_widget(objet,"loginwindow");
pagedacceil=lookup_widget(objet,"pagedacceil");
gtk_widget_hide(pagedacceil);

}


void
on_buttoncatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsign_up_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonquiter_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_envoyerm_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
//GtkWidget *input4;
GtkWidget *input5;

char nom[300];
char prenom[300];
char cin[300];
//char date[300];
char message[300];



input1=lookup_widget(button,"nomc");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"prenomc");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"cinc");  
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
//input4=lookup_widget(button,"datec");
//strcpy(date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"messagec");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input5)));


FILE *f;
char y[100];
date_a(y);
f=fopen("avis.txt","a+");
fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,y,message);
fclose(f); 

//gtk_widget_show(avis);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));

}


void
on_supp_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window2m;
window2m=create_window2m();
gtk_widget_show (window2m);

}



void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window3m;
window3m=create_window3m();
gtk_widget_show (window3m);


}


void
on_affich_clicked                      (GtkWidget       *objet,
                                         gpointer         user_data)
{

GtkWidget *treeview2m; 
GtkWidget *espace;
espace=lookup_widget(objet,"espace_client");
treeview2m=lookup_widget(espace,"treeview2m");
afficher_avis(treeview2m);







}


void
on_treeview2m_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_validerm_clicked                     ( GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
char x[20];
GtkWidget *window2m;
window2m=lookup_widget(objet_graphique,"window2m");


GtkWidget *input12;

 input12=lookup_widget(objet_graphique,"entry3m"); 
    strcpy(x,gtk_entry_get_text(GTK_ENTRY(input12)));

    supprimer_avis(x);
  gtk_widget_hide(window2m);
}


void
on_modifierm_clicked                    (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
char y[300];char z[300];
GtkWidget *window3m;
window3m=lookup_widget(objet_graphique,"window3m");


GtkWidget *input13;
GtkWidget *input14;

 input13=lookup_widget(objet_graphique,"entry4m"); 
    strcpy(y,gtk_entry_get_text(GTK_ENTRY(input13)));
input14=lookup_widget(objet_graphique,"entry5m"); 
    strcpy(z,gtk_entry_get_text(GTK_ENTRY(input14)));

    modifier_avis(y,z);
   gtk_widget_hide(window3m);
  
}








