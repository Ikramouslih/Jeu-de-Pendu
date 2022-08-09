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


int jvsj(){
    char t[o];//pour stocker le mot à deviner
    char j1[o],j2[o] ;// pour stocker les noms des joueurs
    char b[10] = {'_', '_', '_', '_', '_', '_','_','_','_','_'};//pour l'affichage du progress
    char x[o];//pour stocker les lettres qui sont deja utilisées

    printf("                                                                    DONNEZ LE NOM DU JOUEUR1 : ");
    scanf("%s",&j1);//lire le nom du premier joueur
    printf("\n\n");
    printf("                                                                    DONNEZ LE NOM DU JOUEUR2 : ");
    scanf("%s",&j2);//lire le nom du deuxieme joueur
    printf("\n\n");
    printf("                                                             %s : ENTREZ UN MOT PUIS CLICKEZ SUR (ENTRER)!\n\n",j1);
    printf(" \t\t\t\t\t\t\t\t\t");

    i = -1;//initialisation
    do//une boucle qui permet d'afficher des tiret a la place des lettres
    {   i++;// décrementation (indicateur du tableau + contient nombre de lettre)
        t[i] = getch();//affectation sans affichage du caractere sur l'ecran
        if (t[i] != 13)// different du bouton "entrer" (pour ne pas le prendre  en consideration)
        {
            printf("_    ");// affichage des tirets au lieu des caractères
        }

    } while (t[i] != 13);// arret du boucle quand l'utilisateur click sur "entrer"
    printf("\n\n\n");
    printf("                                                                   %s : VOUS DEVEZ DEVINER LE MOT!:",j2);
    printf("\n\n");
    printf("   \t\t\t\t\t\t\t\t");

    score = 0;//initialisation du score
    cpt = 0;//initialisation du compteur qui nous permet de voir si l'utilisateur a saisi tous les lettres du mot
    k = 0;//initialisation d'indicateur du tableau X[]
    tries = 0;//initialisation du nombre d'essaie
    do
    {
        flag = 0;//initialisation de variable d'aide
        if (ltr != '\n')//pour ne pas prendre en consideration le "\n" lors du click sur "entrer"
        {
            printf("\n\n                                                                           Donnez une lettre: ");
        }
        ltr = getchar();//lire une lettre
        for (j = 0; j < k; j++) //boucle pour vérifier si la lettre a été deja entré lors de la répétition du boucle
        {
            if (ltr == x[j])
            {
                flag = 2;//affectation du variable d'aide
            }
        }
        if (ltr != '\n')
        {
            for (j = 0; j < i; j++)//boucle pour comparer la lettre entrée avec les lettres du mot à deviner
            {
                if (ltr == t[j])
                {
                    if (flag != 2)//si la lettre n'est pas encore saisie
                    {
                        flag = 1;//affectation du variable d'aide
                        score += 100;// incrementation du score
                        b[j] = t[j];// affectation du lettre au tableau des tirets et à sa propre place
                        cpt++;//incrementation du compteur
                    }
                }
            }
            x[k] = ltr;//affectation de la lettre dans une case de ce tableau pour éviter la répetition apres
            k++;//incrementation d'indicateur du tableau
            if (flag == 0)// au cas ou la variable d'aide n'a pas été changé (n'existe pas dans le mot à deviner)
            {
                tries++;// incrementation d'essaie gaspillé
                printf("\n\n                                                                          Incorrect!  Reessayez!\n\n");
                man(tries);//fonction du diagramme
                printf("\t\t\t\t\t\t\t\t\t");
                for (j = 0; j < i; j++)//boucle d'affichage des tirets avec les lettres entrées
                {
                    printf("%c    ", b[j]);
                }
                score -= 25;//décrementation du score
                printf("\n");
                printf("\n                                                                          Il vous reste %d chances.\n\n", 6 - tries);
                //affichage de nombre d'essais restants
                printf("                                                              ___________________________________________________\n");
            }
            else if (flag == 1)// au cas ou la variable d'aide a été changé (la lettre existe dans le mot à deviner)
            {
                printf("\n\n                                                                              Correct! NEXT: \n\n");
                man(tries);//fonction du diagramme
                printf("\t\t\t\t\t\t\t\t\t");
                for (j = 0; j < i; j++)//boucle d'affichage des tirets avec les lettres correctes entrées
                {
                    printf("%c    ", b[j]);
                }
                printf("\n\n");
                printf("                                                              ___________________________________________________\n");
            }
            else if (flag == 2)// au cas ou la variable d'aide a été changé (la lettre déja entrée)
            {
                tries++;//incrementation d'essaie gaspillé
                score -= 25;//décrementation du score
                printf("\n\n                                                                            Lettre deja utilise!\n");
                man(tries);//fonction du diagramme
                printf("                                                                            Il vous reste %d chances.\n\n", 6 - tries);
                //affichage de nombre d'essais restants
                printf("                                                             ___________________________________________________\n");
            }
            if (cpt == i)//si tous les tirets ont été remplacé par une lettre
            {
                printf("\n");
                printf("                                                                             -------------------\n");
                printf("                                                                            |   SCORE   :    %d | \n",score);//affichage du score
                printf("                                                                             -------------------     \n\n\n");
                printf("                                                                    ");
                system("pause");
                delay();//fonction du retard
                printf("\n\n\n\n\n\n\n\n\n\n");
                printf("                                                                        ** %s A REUSSI **\n\n\n",j2);// affichage du nom du gagnant
                printf("                                                                                 _____    \n");
                printf("                                                                                | ¤ ¤ |\n");
                printf("                                                                                |__~__|    \n");
                printf("                                                                                   |    \n");
                printf("                                                                                  \\|/    \n");
                printf("                                                                                   |     \n");
                printf("                                                                                   |     \n");
                printf("                                                                                  / \\     \n");
                printf("                                                                                 /   \\ \n\n\n");
                printf("                                                                       _________________________\n\n\n");
                printf("\n                                                                        POUR REJOUER, ENTREZ (1)\n");
                printf("\n                                                               POUR RETOURNER AU MENU PRINCIPAL, ENTREZ (0)\n\n");
                printf("\n                                                                            Votre choix : ");
                do{//boucle pour éliminier le cas de faute de frappe
                scanf("%d",&s);//lecture du choix
                 if(s == 1)
                {
                    delay();//fonction du retard
                    titre();//fonction du graphe du titre
                    jvsj();//fonction du jeu
                }
                else if(s == 0)
                {
                    delay();//fonction du retard
                    titre();//fonction du graphe du jeu
                    menu();//fonction du menu principal
                }
                else{printf("\n");//affichage du message d'erreur
                     printf("                                                                           ERREUR! REESSAYEZ : \t");}

                }while(s != 0 && s != 1);
                }
          }

    } while (tries < 6);//la boucle va arreter si le joueur gaspille tout ses essais
    if(cpt<i){//s'il reste des les tirets qui n'ont pas été remplacé par une lettre
    if(score < 0)
    {score = 0;}//pour ne pas afficher un nombre négatif
    printf("\n\n                                                                                     OUPS\n\n");
    printf("                                                                    ");
    system("pause");
    delay();//fonction du retard
    gameover(score);//fonction du page du game over
    }
    return 0;
}



int dif1()
{
    char b[6] = {'_', '_', '_', '_', '_', '_'};//pour l'affichage du progress
    char x[o];//pour stocker les lettres qui sont deja utilisées
    srand((unsigned)time(NULL));//pour éviter la répetition du fonction random
    c = rand() % 10;//pour choisir un chifrre aléatoire du 0 à 9
         printf("                                                                         ------------------------\n");
         printf("                                                                        | DIFFICULTE 1: *Facile* |\n");
         printf("                                                                         ------------------------\n\n\n");//affichage du difficulté

    score=0;
    cpt = 0;
    k = 0;
    tries = 0;
    do
    {
        flag = 0;
        if (ltr != '\n')
        {printf("\n\n                                                                           Donnez une lettre: ");}
        ltr = getchar();
        for (j = 0; j < k; j++)
            {if (ltr == x[j])
                    {flag = 2;}
            }
        if (ltr != '\n')
        {for (i = 0; i < 4; i++)
            {if (ltr == word4ltr[c][i])
                {if (flag != 2)
                            {flag = 1;
                             score += 100;
                             b[i] = word4ltr[c][i];
                             cpt++;
                            }
                }
            }
        x[k] = ltr;
        k++;
        if (flag == 0)
            {   tries++;
                printf("\n                                                                          Incorrect!  Reessayez!\n\n");
                man(tries);
                printf("   \t\t\t\t\t\t\t\t\t");
                for (j = 0; j < 4; j++)
                    {printf("%c\t", b[j]);}
                score -= 25;
                printf("\n");
                printf("\n                                                                         Il vous reste %d chances.\n\n", 6 - tries);
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 1)
            {   printf("\n                                                                              Correct! NEXT: \n\n");
                man(tries);
                printf("   \t\t\t\t\t\t\t\t\t");
                for (j = 0; j < 4; j++)
                    {printf("%c\t", b[j]);}
                printf("\n\n");
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 2)
            {
                tries++;
                score-=25;
                printf("\n                                                                            Lettre deja utilise!\n");
                man(tries);
                printf("                                                                           Il vous reste %d chances.\n\n",6 - tries);
                printf("                                                             ___________________________________________________\n");
            }
        if(cpt==4)//si tous les tirets ont été remplacé par une lettre
            {   printf("\n                                                                          ** NIVEAU (1) REUSSI **\n\n\n");
                printf("                                                                             -------------------\n");
                printf("                                                                            | SCORE (1):    %d | \n",score);
                printf("                                                                             -------------------     \n\n\n");
                printf("                                                                    ");system("pause");
                delay();
                printf("\n\n\n\n\n\n\n\n\n\n");
                printf("                                                                       ** NIVEAU REUSSI (1) **\n\n\n");
                printf("                                                                            ooo        _____    \n");
                printf("                                                                          oo oo       | ¤ ¤ |\n");
                printf("                                                                         oo  oo       |__~__|    \n");
                printf("                                                                             oo          |    \n");
                printf("                                                                             oo         \\|/    \n");
                printf("                                                                             oo          |     \n");
                printf("                                                                             oo          |     \n");
                printf("                                                                             oo         / \\     \n");
                printf("                                                                           oooooo      /   \\ \n\n\n");
                printf("                                                                       _________________________\n\n\n");
                printf("\n                                                                 POUR PASSER AU NIVEAU SUIVANT, ENTREZ (1)\n");
                printf("\n                                                               POUR RETOURNER AU MENU PRINCIPAL, ENTREZ (2)\n\n");
                printf("\n                                                                            Votre choix : ");
                do{
                scanf("%d",&s);
                 if(s == 1)//pour passer au niveau suivant
                {
                    delay();
                    titre();
                    dif2();
                }
                else if(s == 2)//pour retourner au menu principal
                {
                    delay();
                    titre();
                    menu();
                }
                else{printf("\n");//pour éliminer le cas du faute de tappe
                     printf("                                                                           ERREUR! REESSAYEZ : \t");}

                }while(s != 2 && s != 1);
            }
        }

    } while (tries < 6);

    if(cpt<4){
    if (score < 0)
    {score = 0;}
    printf("\n\n                                                                                     OUPS\n\n");
    printf("                                                                    ");
    system("pause");
    delay();
    gameover(score);
    }

return 0;

}


int dif2()
{
    char b[6] = {'_', '_', '_', '_', '_', '_'};//pour l'affichage du progress
    char x[o];//pour stocker les lettres qui sont deja utilisées
    srand((unsigned)time(NULL));//pour éviter la répetition du fonction random
    c = rand() % 9;//pour choisir un chifrre aléatoire du 0 à 9
        printf("                                                                         ------------------------\n");
        printf("                                                                        | DIFFICULTE 2: *Moyen*  |\n");
        printf("                                                                         ------------------------\n\n\n");

    cpt = 0;
    k = 0;
    tries = 0;
    score = 0;
    do
    {
        flag = 0;
        if (ltr != '\n')
        {printf("\n\n                                                                           Donnez une lettre: ");}
        ltr = getchar();
        for (j = 0; j < k; j++)
            {if (ltr == x[j])
                    {flag = 2;}
            }
        if (ltr != '\n')
        {for (i = 0; i < 5; i++)
            {if (ltr == word5ltr[c][i])
                {if (flag != 2)
                            {flag = 1;
                             score += 100;
                             b[i] = word5ltr[c][i];
                             cpt++;
                            }
                }
            }
        x[k] = ltr;
        k++;
        if (flag == 0)
            {   tries++;
                printf("\n                                                                          Incorrect!  Reessayez!\n\n");
                man(tries);
                printf("\t\t\t\t\t\t\t\t\t");
                for (j = 0; j < 5; j++)
                    {printf("%c\t", b[j]);}
                score -= 25;
                printf("\n");
                printf("\n                                                                          Il vous reste %d chances.\n\n", 6 - tries);
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 1)
            {   printf("\n                                                                              Correct! NEXT: \n\n");
                man(tries);
                printf("\t\t\t\t\t\t\t\t\t");
                for (j = 0; j < 5; j++)
                    {printf("%c\t", b[j]);}
                printf("\n\n");
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 2)
            {
                tries++;
                score-=25;
                printf("\n                                                                            Lettre deja utilise!\n");
                man(tries);
                printf("                                                                            Il vous reste %d chances.\n\n",6 - tries);
                printf("                                                             ___________________________________________________\n");
            }
        if(cpt==5)
            {
                printf("\n                                                                         ** NIVEAU (2) REUSSI **\n\n\n");
                printf("                                                                            -------------------\n");
                printf("                                                                           | SCORE (2):    %d  | \n",score);
                printf("                                                                            -------------------     \n\n\n");
                printf("                                                                   ");system("pause");
                delay();
                printf("\n\n\n\n\n\n\n\n\n\n");
                printf("                                                                        ** NIVEAU REUSSI (2) **\n\n\n");
                printf("                                                                           oooooo      _____    \n");
                printf("                                                                          ooo   oo    | ¤ ¤ |\n");
                printf("                                                                                oo    |__~__|    \n");
                printf("                                                                               oo        |    \n");
                printf("                                                                              oo        \\|/    \n");
                printf("                                                                             oo          |     \n");
                printf("                                                                            oo           |     \n");
                printf("                                                                           oo           / \\     \n");
                printf("                                                                          oooooooo     /   \\ \n\n\n");
                printf("                                                                       _________________________\n\n\n");
                printf("\n                                                                POUR PASSER AU NIVEAU SUIVANT, ENTREZ (1)\n");
                printf("\n                                                               POUR RETOURNER AU MENU PRINCIPAL, ENTREZ (2)\n\n");
                printf("\n                                                                            Votre choix : ");
                do{
                scanf("%d",&s);
                 if(s == 1)
                {
                    delay();
                    titre();
                    dif3();
                }
                else if(s == 2)
                {
                    delay();
                    titre();
                    menu();
                }
                else{printf("\n");
                     printf("                                                                           ERREUR! REESSAYEZ : \t");}

                }while(s != 2 && s != 1);
            }
        }

    } while (tries < 6);
    if(cpt<5){
    if (score < 0)
    {score = 0;}
    printf("\n\n                                                                                     OUPS\n\n");
    printf("                                                                    ");
    system("pause");
    delay();
    gameover(score);
    }

    return 0;
}


int dif3()
{
    int m;//variable d'aide
    char b[6] = {'_', '_', '_', '_', '_', '_'};//pour l'affichage du progress
    char x[o];//pour stocker les lettres qui sont deja utilisées
    srand((unsigned)time(NULL));//pour éviter la répetition du fonction random
    c = rand() % 9;//pour choisir un chifrre aléatoire du 0 à 9
        printf("                                                                         ---------------------------\n");
        printf("                                                                        | DIFFICULTE 3: *Difficile* |\n");
        printf("                                                                         ---------------------------\n\n\n");

    cpt = 0;
    k = 0;
    tries = 0;
    do
    {
        flag = 0;
        if (ltr != '\n')
        {printf("\n\n                                                                           Donnez une lettre: ");}
        ltr = getchar();
        for (j = 0; j < k; j++)
            {if (ltr == x[j])
                    {flag = 2;}
            }
        if (ltr != '\n')
        {for (i = 0; i < 6; i++)
            {if (ltr == word6ltr[c][i])
                {if (flag != 2)
                            {flag = 1;
                             score += 100;
                             b[i] = word6ltr[c][i];
                             cpt++;
                            }
                }
            }
        x[k] = ltr;
        k++;
        if (flag == 0)
            {   tries++;
                printf("\n                                                                          Incorrect!  Reessayez!\n\n");
                man(tries);
                printf("                                                                    ");
                for (j = 0; j < 6; j++)
                    {printf("%c\t", b[j]);}
                score -= 25;
                printf("\n");
                printf("\n                                                                         Il vous reste %d chances.\n\n", 6 - tries);
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 1)
            {   printf("\n                                                                              Correct! NEXT: \n\n");
                man(tries);
                printf("                                                                   ");
                for (j = 0; j < 6; j++)
                    {printf("%c\t", b[j]);}
                printf("\n\n");
                printf("                                                              ___________________________________________________\n");
            }
        else if (flag == 2)
            {   tries++;
                score-=25;
                printf("\n                                                                            Lettre deja utilise!\n");
                man(tries);
                printf("\n                                                                         Il vous reste %d chances.\n\n", 6 - tries);
                printf("                                                              ___________________________________________________\n");
            }
            if(cpt==6)
            {
                printf("\n                                                                         ** NIVEAU (3) REUSSI **\n\n\n");
                printf("                                                                            -------------------\n");
                printf("                                                                           | SCORE (3):    %d  | \n",score);
                printf("                                                                            -------------------     \n\n\n");
                printf("                                                                   ");system("pause");
                delay();
                printf("\n\n\n\n\n\n\n\n\n\n\n");
                printf("                                                                          ** NIVEAU REUSSI (3) **\n\n");
                printf("                                                                            Vous avez gagne!!!\n\n\n\n");
                printf("                                                                           ooooooo     _____    \n");
                printf("                                                                                oo    | ¤ ¤ |\n");
                printf("                                                                                oo    |__~__|    \n");
                printf("                                                                                oo       |    \n");
                printf("                                                                           ooooooo      \\|/    \n");
                printf("                                                                                oo       |     \n");
                printf("                                                                                oo       |     \n");
                printf("                                                                                oo      / \\     \n");
                printf("                                                                           ooooooo     /   \\ \n\n\n");
                printf("                                                                       _________________________\n\n\n");
                printf("                                                                   ");system("pause");


     saved();//fonction du graphe
     winfonction();//fonctin du graphe
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     printf("                                                                | CLICKEZ SUR 0 POUR RETOURNER AU MENU PRiNCIPAL |\n\n\n\n");
     printf("                                                                                Votre choix : \t");
     do//boucle pour éliminier le cas de faute de frappe
    { scanf("%d", &m);//lire le choix
        if (m == 0)
        {   tries=7;//pour arreter la boucle
            delay();//fonction du retard
            titre();//fonction du graphe du titre
            menu();//fonction du menu principal
        }
        else
        {
            printf("\n                                                                             Erreur, clickez sur 0: \t");//affichage msg d'erreur

        }

    } while (m != 0);
     }
        }

    } while (tries < 6);
    if(cpt<6){
    if (score < 0)
    {score = 0;}
    printf("\n\n                                                                                     OUPS\n\n");
    printf("                                                                    ");
    system("pause");
    delay();
    gameover(score);
    }
    return 0;

}
