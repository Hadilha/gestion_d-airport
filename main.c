
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include "myconio.h"
#include <stdio.h>
#include <windows.h>
#include "liste.h"

 liste * L ;
 int N ;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("my project"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1500,                 /* The programs width */
           800,                /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
        case 0:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                system("color B0");
                L=creer_liste();
                L=CREATION() ;
                system("color 0F");
                affiche_liste(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 1:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                struct avion av;
                system("color B0");

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            { av=SAISIE_AVION(L);
                insere_tete_av(av,L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 2:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                system("color B0");
                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {                    av=SAISIE_AVION(L);

                insere_queue_av(av ,L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 3:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                system("color B0");
               if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {  av=SAISIE_AVION(L);

                inserer_pos(L,av);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 4:
                 system("color F9");
                 ShowWindow(hwnd,SW_HIDE);
                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {system("color 0F");
                supprimer_premier(L);
                 affiche_liste(L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
        case 5:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                system("color B0");
                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            { system("color 0F");
                supprimer_dernier(L);
                affiche_liste(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }

        case 6:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);


                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {
               system("color B0");
                suppression_pos_av(L);
                affiche_liste(L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }

        case 7:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {
                system("color 0F");
                suppression_av_donne(L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
            }
        case 8:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                    printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {


                system("color B0");

                suppression_comp_donne(L);
                fflush(stdin);


                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break; }
        case 9:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {


                 system("color B0");

                 modifie_identifiant(*L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break; }
        case 10:


                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                        printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {

                 system("color B0");

                 modifie_Compagnie(*L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 11:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                 if (N==1)
            {system("color 0F");
                affiche_liste(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}
              if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                    printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }




        case 12:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);




                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                    printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {system("color B0");

                TESTT(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 13:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                     printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {

                system("color B0");

                TESTcomp(L) ;
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 14:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                    printf (" \n*** ATTENTION !!!!! *** \n ");

                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {
                system("color B0");

                TESThdec(L) ;
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 15:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                if (N==0)

                {   system("color 0F");
                    textbackground (0);textcolor(12);
                    printf (" \n*** ATTENTION !!!!! *** \n ");
                    printf ("IL FAUT REMPLIR LA LISTE DES REPERTOIRE AVANT D'EFFECTUER CETTE OPERTAION !!!");
                 printf ("\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;                    }

            else
            {

                system("color B0");
                TRI1(L) ;
                system("color B0");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;}

        case 16:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);

                enregistrement(L);
                printf("   ***enregistrement terminee ***");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 17:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);

                chargement(L);
                printf("\nAPRES CHARGEMENT\n");
                affiche_liste(L);

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 18:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,1560,800,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
     HMENU htp2=CreateMenu();
    HMENU hex3=CreateMenu();
     HMENU hex2=CreateMenu();
     HMENU hex4=CreateMenu();



   AppendMenu(hmenu,MF_STRING,0,"Creaction du repertoire Avion");
    /*******************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp,"Mise a jour des Avions");

    AppendMenu(htp,MF_POPUP,(UINT_PTR)hex2,"Ajouter un nouvel avion");
        AppendMenu(hex2,MF_STRING,1," Ajout en tete");
        AppendMenu(hex2,MF_STRING,2,"Ajout en queue");
        AppendMenu(hex2,MF_STRING,3,"Ajout a partir d'une position ");
    AppendMenu(htp,MF_POPUP,(UINT_PTR)hex3," Supprimer un avion");
        AppendMenu(hex3,MF_STRING,4," Suppression en tete");
        AppendMenu(hex3,MF_STRING,5,"Suppression en queue");
        AppendMenu(hex3,MF_STRING,6,"Suppression a partir d'une position");
        AppendMenu(hex3,MF_STRING,7,"Suppression d'un avion donnee");
        AppendMenu(hex3,MF_STRING,8,"Suppression des avions d'une compagnie donnee");
    AppendMenu(htp,MF_POPUP,(UINT_PTR)hex4," Modifier les données d'un avion");
        AppendMenu(hex4,MF_STRING,9," Identifiant");
        AppendMenu(hex4,MF_STRING,10,"Compagnie");




/***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"MENU Recherche et affichage");

      AppendMenu(htp1,MF_STRING,11,"Contenu de la liste des avions");
      AppendMenu(htp1,MF_STRING,12,"Recherche par identifiant avion");
      AppendMenu(htp1,MF_STRING,13,"Recherche par compagnie");
      AppendMenu(htp1,MF_STRING,14,"Recherche par heure de decollage");
      AppendMenu(htp1,MF_STRING,15,"Tri");


      /***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"MENU Enregistrement et chargement");

      AppendMenu(htp2,MF_STRING,16,"Enregistrement");
      AppendMenu(htp2,MF_STRING,17,"Chargement");


/***************************************************************/

    AppendMenu(hmenu,MF_STRING,18,"Quitter");
    SetMenu(hwnd,hmenu);
}
