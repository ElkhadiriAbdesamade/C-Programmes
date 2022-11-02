#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<windows.h>

typedef struct
{
    int num;
    char nom[30];
    char prenom[30];
}Stagiaire;
int getInt(char* msg)
{
    int rep;
    puts(msg);
    scanf("%d",&rep);
    return rep;

}
char* getString(char* msg)
{
    char* rep=malloc(100);
    puts(msg);
    gets(rep);
    return rep;

}
Stagiaire getStagiaire()
{
    Stagiaire s;
    s.num=getInt("Tapez le numero du stagiaire ?\n");
    getchar();
    strcpy(s.nom,getString("Tapez le nom du stagiaire ?\n"));
     strcpy(s.prenom,getString("Tapez le prenom du stagiaire ?\n"));
    return s;
}
void remplirTableauStagiaire(int n,Stagiaire* t)
{
    int i;
    for(i=0;i<n;i++)
    {
        t[i]=getStagiaire();
    }
}
void afficherUnStagiaire(Stagiaire s)
{
    printf("%d\t%s\t%s\n",s.num,s.nom,s.prenom);
}
void afficherTableauStagiaire(int n,Stagiaire* t)
{
    int i;
    for(i=0;i<n;i++)
    {
        afficherUnStagiaire(t[i]);
    }
}
void trierParNum(int n, Stagiaire* t)
{
    int i,sorted=0;
    Stagiaire tmp;
    while(!sorted)
    {
        sorted=1;
        for(i=0;i<n-1;i++)
        {

            if(t[i].num>t[i+1].num)
            {
                tmp=t[i];
                t[i]=t[i+1];
                t[i+1]=tmp;
                sorted=0;

            }
        }
    }
}
void trierParNom(int n, Stagiaire* t)
{
     int i,sorted=0;
    Stagiaire tmp;
    while(!sorted)
    {
        sorted=1;
        for(i=0;i<n-1;i++)
        {

            if(strcmp(t[i].nom,t[i+1].nom)>0)
            {
                tmp=t[i];
                t[i]=t[i+1];
                t[i+1]=tmp;
                sorted=0;

            }
        }
    }

}
void enregistrer(int n, Stagiaire* t)
{
    FILE* f=fopen("stagiaire.bin","wb");
    fwrite(t,n*sizeof(Stagiaire),1,f);
    fclose(f);
}
Stagiaire* ouvrir(int* n)
{
    FILE* f=fopen("stagiaire.bin","rb");
    fseek(f,0,SEEK_END);
    long taille=ftell(f);
    *n=taille/sizeof(Stagiaire);
    Stagiaire* t=malloc(*n*sizeof(Stagiaire));
  rewind(f);
    fread(t,*n*sizeof(Stagiaire),1,f);
    fclose(f);
    return t;
}
Stagiaire chercherParNum(int num,int nbr,Stagiaire* t)
{
    Stagiaire s;
    int i;
    s.num=-1;
    for(i=0;i<nbr;i++)
    {
        if(t[i].num==num)
        {
            s=t[i];
            break;
        }

    }
    return s;

}
int getNbrRepetitionNom(char* nom,int nbr, Stagiaire* t)
{
    int n=0,i;
    for(i=0;i<nbr;i++)
    {
        if(strcmp(t[i].nom,nom)==0)
        {
            n++;
        }
    }
    return n;

}
Stagiaire* chercherParNom(char* nom,int nbr,Stagiaire* t)
{
    Stagiaire* t1 =NULL;
    int i,j=0;
    int n= getNbrRepetitionNom(nom,nbr,t);
    if(n>0)
    {
        t1=malloc(n*sizeof(Stagiaire));
        for(i=0;i<nbr;i++)
        {
          if( strcmp(t[i].nom,nom)==0)
          {
              t1[j]=t[i];
              j++;
          }
        }
        return t1;
    }



}
Stagiaire* Ajouter(Stagiaire s,int* nbr,Stagiaire* t)
{
    int i;
    Stagiaire* t1= malloc((*nbr+1)*sizeof(Stagiaire));
    for(i=0;i<*nbr;i++)
    {
        t1[i]=t[i];
    }
    t1[i]= s;
    (*nbr)++;
    return t1;
}
Stagiaire* Supprimer(Stagiaire s,int* nbr,Stagiaire* t)
{
    int i,j=0;
    Stagiaire* t1= malloc((*nbr-1)*sizeof(Stagiaire));
    for(i=0;i<*nbr;i++)
    {
        if(t[i].num!=s.num)
        {
            t1[j]=t[i];
            j++;
        }

    }
      (*nbr)--;
    return t1;
}
void Modifier(Stagiaire s,int n,Stagiaire* t)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(t[i].num==s.num)
        {
            t[i]=s;
            break;
        }
    }
}
void Color(int c)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,c);
}
void gotoXY(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}


int main()
{
    int nbrStag,choix=0;
    Stagiaire* stags;
    int i,j;
    //system("color D");

    for(i=0;i<58;i++)
    {
        gotoXY(i,0);
    puts(" Gestion des stagiaires\n");
    for(j=0;j<5000000;j++)
    {

    }
    system("cls");

    }
     for(i=58;i>0;i--)
    {
        gotoXY(i,0);
    puts(" Gestion des stagiaires\n");
    for(j=0;j<5000000;j++)
    {

    }
    system("cls");

    }
     system("dir c:\\");


     while(choix!=10)
    {

        Color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
        choix= getInt("1. Saisir\n2. Afficher\n3. Trier\n4. Enregistrer\n5. Ouvrir\n6. Chercher\n7. Ajouter\n8. Supprimer\n9. Modifier\n10. Quitter\nVotre choix ?\n");
        switch(choix)
        {
        case 1:
             Color(FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
            nbrStag= getInt("Combien de stagiaire voulez vous traiter ?\n");
                stags=malloc(nbrStag*sizeof(Stagiaire));
                remplirTableauStagiaire(nbrStag,stags);
            break;
        case 2:

            afficherTableauStagiaire(nbrStag,stags);
            system("pause");
            break;
        case 3:
            {
                int choix=0;
                while(choix!=3)
                {
                    choix= getInt("1. Par Num\n2. Par Nom\n3. Retour\nTapez votre choix ?\n");
                    switch(choix)
                    {
                    case 1:
                         trierParNum(nbrStag,stags);
                        afficherTableauStagiaire(nbrStag,stags);
                        break;
                    case 2:
                        trierParNom(nbrStag,stags);
                        afficherTableauStagiaire(nbrStag,stags);
                        break;

                    }
                    system("pause");
                    system("cls");
                }
                break;
            }
                    case 4:
                        enregistrer(nbrStag,stags);

                        break;
                    case 5:
                        stags=ouvrir(&nbrStag);
                        break;
                    case 6:
                        {
                int choix=0;
                while(choix!=3)
                {
                    choix= getInt("1. Par Num\n2. Par Nom\n3. Retour\nTapez votre choix ?\n");
                    switch(choix)
                    {
                    case 1:
                        {
                            int num=getInt("Tapez le numero du stagiaire a chercher ?\,");
                          Stagiaire s=chercherParNum(num,nbrStag,stags);
                            if(  s.num !=-1)
                            {
                                afficherUnStagiaire(s);

                            }
                            else
                            {
                                puts("Aucun stagiaire ne possede ce numero !\n");
                            }

                               break;
                        }
                    case 2:
                        {
                            getchar();
                            char* nom=getString("Tapez le nom du stagiaire a chercher ?\n");
                            Stagiaire* t= chercherParNom(nom,nbrStag,stags);
                            if(t!=NULL)
                            {
                                afficherTableauStagiaire(getNbrRepetitionNom(nom,nbrStag,stags),t);
                            }
                            else
                                {
                                    puts("Aucun stagiaire ne possede ce nom !\n");
                                }
                            break;
                        }




                    }
                    system("pause");
                    system("cls");
                }
                break;
            }
                    case 7:
                        {
                            Stagiaire s=getStagiaire();
                            if(chercherParNum(s.num,nbrStag,stags).num==-1)
                            {
                                 stags= Ajouter(s,&nbrStag,stags);
                            }
                            else
                            {
                                puts(" Ce numero est deja affecte a un autre stagiaire !\n");
                                system("pause");
                            }


                            break;
                        }
                    case 8:
                        {
                            int num= getInt("Tapez le numero du stagiaire a supprimer ?\n");
                           char rep;
                            Stagiaire s= chercherParNum(num,nbrStag,stags);
                            if (s.num!=-1)
                            {
                                afficherUnStagiaire(s);
                                puts("Etes vous sur de vouloir supprimer ce stagiaire  O/N?\n");
                               getchar();
                                rep=getch();
                                if(rep=='o'||rep=='O')
                                {
                                    stags=Supprimer(s,&nbrStag,stags);
                                    puts("Suppression effectuee avec succes.\n");

                                }


                            }
                            else
                            {
                                puts("Aucun stagiaire ne possede ce numero !");
                            }
                            system("pause");

                            break;
                        }
                    case 9:
                        {
                            int num= getInt("Tapez le numero du stagiaire a modifier ?\n");
                           char rep;
                            Stagiaire s= chercherParNum(num,nbrStag,stags);
                            if (s.num!=-1)
                            {
                                afficherUnStagiaire(s);
                                puts("Etes vous sur de vouloir Modifier ce stagiaire  O/N?\n");
                               getchar();
                                rep=getch();
                                if(rep=='o'||rep=='O')
                                {
                                    int choix=0;
                                    while(choix!=3)
                                    {
                                        choix=getInt("1. Modifier Nom \n2. Modifier Prenom\n3. Retour\nVotre choix ?\n");
                                       getchar();
                                        switch(choix)
                                        {
                                        case 1:
                                            strcpy(s.nom,getString("Tapez le nouveau nom ?\n"));
                                            Modifier(s,nbrStag,stags);
                                            break;
                                        case 2:
                                            strcpy(s.prenom,getString("Tapez le nouveau prenom ?\n"));
                                            Modifier(s,nbrStag,stags);
                                            break;
                                        }

                                        system("cls");
                                    }



                                }


                            }
                            else
                            {
                                puts("Aucun stagiaire ne possede ce numero !");
                            }
                            system("pause");

                            break;
                        }



        }
           system("cls");
    }

    return 0;
}
