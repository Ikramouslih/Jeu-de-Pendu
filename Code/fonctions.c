#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define z 10
#define o 50



int i, j, k, k1, tries = 0, c, flag, score = 0, cpt, s;
char word4ltr[z][4] = {"miel", "golf", "vert", "lire", "velo", "film", "bleu", "gens", "asie", "pile"};//matrice des mots à 4 letrres
char word5ltr[z][5] = {"bravo", "pomme", "terre", "pilot", "cours", "photo", "avion", "train", "japon", "arbre"};//matrice des mots à 5 letrres
char word6ltr[z][6] = {"chaise", "animal", "miroir", "lettre", "pirate", "mouton", "format", "mesure", "faible", "dessin"};//matrice des mots à 6 letrres
char ltr;//lettre entrée



void delay()
{
    int c, d;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                             CHARGEMENT...\n");
    for (c = 1; c <= 42767; c++)
    {
        for (d = 1; d <= 42767; d++){}
    }
    system("cls");
}
void delayempty(){
    int c, d;
    for (c = 1; c <= 35000; c++)
    {
        for (d = 1; d <= 35000; d++){}
    }
    system("cls");
}
void delayemptyshort(){
    int c, d;
    for (c = 1; c <= 10000; c++)
    {
        for (d = 1; d <= 10000; d++){}
    }
    system("cls");
}




int menu()
{
    printf("                                                                                | MENU |        \n\n\n\n");//affichage
    printf("                                                                                1. JOUER           \n\n");//affichage
    printf("                                                                             2. INSTRUCTIONS      \n\n");//affichage
    printf("                                                                               3. CREDITS      \n\n");//affichage
    printf("                                                                               4. QUITTER           \n\n");//affichage
    printf("\n\n\n\n");
    printf("                                                                               Votre choix : ");//affichage
    do{
    scanf("%d", &k); //lire le choix
    if(k==1){vs();} //destination : fonction du menu des joueurs
    if(k==2){instructions();} //destination : fonction des instructions
    if(k==3){credits();} //destination : fonction des informartions sur le projet
    if(k==4){exit(0);} //pour arreter le programme
    if((((k != 0 && k!= 1) && k!=2) && k!=3)&& k!=4){printf("\n");//cas d'erreur
    printf("                                                                            ERREUR! REESSAYEZ :  ");}
    }while(k!=4);//refaire dans le cas d'erreur
    return 0;
}



int instructions()
{
    int m;

    delay();//fonction du retard
    titre();//fonction du titre
    printf("                                                                           | COMMENT JOUER? |\n\n\n");
    printf("   Le but du jeu est de deviner en moins de 6 essais un mot que seul la machine ou une joueur connait. Pour mener a bien votre mission, vous allez proposer une lettre : \n ");
    printf("                                           Si la lettre est correcte alors, celle ci s affiche a sa place dans le mot a deviner.\n \n");
    printf("                                                 Si la lettre est incorrecte, alors, votre nombre d essais diminue de 1. \n\n");
    printf("                                                                            Autrement dit : \n\n");
    printf("                                                  Lorsqu une lettre est correcte, le nombre d essais reste inchange. \n\n");
    printf("                                                  Lorsqu une lettre est incorrecte, le nombre d’essais diminue de 1. \n\n");
    printf("                                                         Lorsque tout le mot a ete devine, vous avez gagne. \n\n");
    printf("                                                     Lorsque le nombre d essais est a zero (0), vous avez perdu\n\n");
    printf("                                                                            BONNE CHANCE!!!\n");
    printf("\n\n\n");
    printf("                                                            clickez sur 0 pour retourner au menu principal: \t");
    do//pour éliminer la possibilité du faute de tappe
    { scanf("%d", &m);//pour lire le 0
        if (m == 0)
        {
            delay();
            titre();
            menu();//pour retourner au fonction du menu principal
        }
        else
        {
            printf("\n\t\t\t\t\t\t\t\t\tErreur, clicker sur 0: \t");//affichage du msg d'erreur

        }
    } while (m != 0);
    return 0;
}



int credits()
{
    int m;
    delay();//fonction du retard
    titre();//fonction du titre
    printf("                                                                           | PROGRAMME PAR: 1AP G3|\n\n\n");
    printf("                                                                                Sohaib Jalil\n\n");
    printf("                                                                                Ikram Mouslih\n\n\n\n\n");
    printf("                                                                              |  ENCADRE PAR: |\n\n\n");
    printf("                                                                               M. Mohamed Atibi\n\n");
    printf("                                                                             Mme. Soukaina Ihirri\n\n\n\n\n\n");
    printf("                                                                clickez sur 0 pour retourner au menu principal:  ");
    do//pour éliminer la possibilité du faute de tappe
    {scanf("%d", &m);//lire le choix
        if (m == 0)
        {
            delay();
            titre();
            menu();//pour retourner au fonction du menu principal
        }
        else
        {   printf("\n");//affichage du msg d'erreur
            printf("                                                                             Erreur, clickez sur 0: \t");
        }
    } while (m != 0);
    return 0;
}

int vs(){
    delay();//fonction : une boucle qui permet de créé un retard
    titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
    printf("                                                                                   | X VS X |\n\n\n");
    printf("                                                                             1- Joueur VS Machine\n\n");
    printf("                                                                             2- Joueur VS Joueur\n\n\n\n");
    printf("                                                                | CLICKEZ SUR 0 POUR RETOURNER AU MENU PRiNCIPAL |\n\n\n\n");
    printf("                                                                                 Votre choix :   ");
    do{scanf("%d", &k1);//lire le voix
        if (k1 == 1){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            difficulte();//destination : une autre fonction
            }
        else if(k1 == 2){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            jvsj();//destination : une autre fonction
            }
        else if(k1 == 0){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            menu();//destination : fonction du menu principal
            }
        else{printf("\n");//cas d'erreur
            printf("                                                                               ERREUR! REESSAYEZ :   ");}
    }while ((k1 != 0 && k1!= 1)&& k1!=2);//refaire dans le cas d'erreur
    return 0;}


int difficulte(){
    printf("                                                                               | DIFFICULTE |\n\n\n");//affichage
    printf("                                                                                 1- Facile\n\n");
    printf("                                                                                 2- Moyen\n\n");
    printf("                                                                                 3- Difficile\n\n\n\n");
    printf("                                                                  | CLICKEZ SUR 4 POUR RETOURNER AU MENU X VS X |\n\n");
    printf("                                                                | CLICKEZ SUR 0 POUR RETOURNER AU MENU PRiNCIPAL |\n\n\n\n");
    printf("                                                                                 Votre choix : \t");
    do{scanf("%d", &k1);//lire le choix
        if (k1 == 1)
        {   delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            dif1();}//destination : fonction
        else if(k1 == 2){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            dif2();}//destination : fonction
        else if (k1 == 3){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            dif3();}//destination : fonction
        else if (k1 == 4){
            vs();}
        else if(k1 == 0){
            delay();//fonction : une boucle qui permet de créé un retard
            titre();//fontion : manipulation du fonction d'affichage pour créé un graphe
            menu();}//destination : retour au menu principal
        else{printf("\n");//cas d'errueur
         printf("                                                                               ERREUR! REESSAYEZ : \t");
    } }while ((((k1 != 0 && k1!= 1)&& k1!=2) && k1!=3) && k!=4);//refaire dans le cas d'erreur
return 0;}




int gameover(){
    int m;
    gameovergraph();//fonction du graphe du gameover
    printf("                                                                              --------------- \n");
    printf("                                                                             | SCORE:    %d  | \n",score);//affichage du score
    printf("                                                                              ---------------      \n\n\n\n\n");
    printf("                                                                | CLICKEZ SUR 0 POUR RETOURNER AU MENU PRiNCIPAL |\n\n\n\n");
    printf("                                                                                Votre choix : \t");
     do//boucle pour éliminier le cas de faute de frappe
    { scanf("%d", &m);
        if (m == 0)
        {
            delay();//fonction du retard
            titre();//fonction du titre
            menu();//fonction du menu principal
        }
        else
        {
            printf("\n                                                                             Erreur, clickez sur 0: \t");//affichage du msg d'erreur

        }

    } while (m != 0);

return 0;
}





