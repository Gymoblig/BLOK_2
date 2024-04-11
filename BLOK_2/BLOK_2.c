#pragma warning(disable:4996)
#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

void uloha211()
{
    system("cls");
    int prve = 0, druhe = 0, vysledok;
    //Zistenie premennych
    printf("============ULOHA 2.1.2===========\n");
    printf("Zadajte prve cislo, ktore chcete spocitat: ");
    scanf("%d", &prve);
    printf("Zadajte druhe cislo, ktore chcete spocitat: ");
    scanf("%d", &druhe);

    __asm 
    {
        mov eax, prve
        mov ebx, druhe
        add eax, ebx 
        mov vysledok, eax
    }
    printf("Vysledok %d + %d je: %d\n", prve, druhe, vysledok);
    
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();
    getchar();
}

void uloha212()
{
    system("cls");
    int cislo, vysledok;
    printf("============ULOHA 2.1.2===========\n");
    printf("Zadajte cislo, ktore chcete vynasobit 2: ");
    scanf("%d", &cislo);
    __asm {
        mov eax, cislo
        shl eax, 1
        mov vysledok, eax
    }

    printf("Vysledok %d x 2 je: %d\n", cislo, vysledok);
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();
    getchar();
}

/*void uloha214()
{
    system("cls");

    char pole[13] = { 0 }; //predpokladam, ze to bude mat menej ako 100 znakov
    int eax = 0;
    printf("============ULOHA 2.1.4===========\n");
    __asm {
        mov eax, 0
        cpuid
        mov dword ptr pole[0], ebx
        mov dword ptr pole[4], edx
        mov dword ptr pole[8], ecx
        
    }
    pole[12] = '\0';
    printf("V tomto pocitaci sa nachadza: %s\n", pole); 
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();

}*/

void uloha231() {
    system("cls");
    printf("============ULOHA 2.3.1===========\n");
    FILE* vstup, * vystup;
    char c;
    vstup = fopen("poviedka.html", "r");
    if (vstup == NULL) {
        printf("Chyba pri otvarani!\n");
        return;
    }
    vystup = fopen("poviedka1.html", "w");
    if (vystup == NULL) {
        printf("Chyba pri otvarani!\n");
        return;
    }
    // Prevod znakov
    while ((c = fgetc(vstup)) != EOF) {
        switch (c) {
            case (char)181: c = (char)190; break; // ľ
            case (char)185: c = (char)154; break; // š
            case (char)187: c = (char)157; break; // ť
            case (char)190: c = (char)158; break; // ž

            case (char)165: c = (char)188; break; // Ĺ
            case (char)169: c = (char)138; break; // Š
            case (char)171: c = (char)141; break; // Ť
            case (char)174: c = (char)142; break; // Ž 
        }

        
        fputc(c, vystup);
    }
    fclose(vstup); // Zatvorenie suborov
    fclose(vystup);

    printf("Znaky boli prevedene!\n");
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();
    getchar();
}

void uloha251() 
{
    system("cls");
    printf("============ULOHA 2.5.1===========\n\n");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i <= 50; i++) {
        if (i <= 10) {
            SetConsoleTextAttribute(hConsole, 2);
        }
        else if (i <= 20) {
            SetConsoleTextAttribute(hConsole, 4);
        }
        else if (i <= 30) {
            SetConsoleTextAttribute(hConsole, 9);
        }
        else if (i <= 40) {
            SetConsoleTextAttribute(hConsole, 6);
        }
        else{ SetConsoleTextAttribute(hConsole, 5); }
        printf(" %03d\n", i);
        Sleep(500);
    }
    SetConsoleTextAttribute(hConsole, 0x0F);
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();
    getchar();
}

void uloha252()
{   
    system("cls");
    HANDLE  hConsole;                         
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("============ULOHA 2.5.2===========\n");
    char meno[] = "Peter";
    char priezvisko[] = "";
    char vyska[] = "178";
    char vaha[] = "110";
    char cislo[] = "0944 636 002";
    int suradnicaX = 0,X=0, Y = 0;
    int docasna_premenna = 0;
    printf("Zadajte suradnicu X: ");
    scanf("%d",&X);
    printf("Zadajte suradnicu Y: ");
    scanf("%d",&Y);

    system("cls");
    printf("====Stacte ENTER pre ukoncenie====\n"); getchar();
    int meno_dlzka = strlen(meno);
    int priezvisko_dlzka = strlen(priezvisko);
    int vyska_dlzka = strlen(vyska);
    int vaha_dlzka = strlen(vaha);
    int cislo_dlzka = strlen(cislo);
    int dlzka = meno_dlzka + priezvisko_dlzka + 3;
    if (dlzka <= cislo_dlzka) {
        docasna_premenna = dlzka;
        dlzka = cislo_dlzka;
        cislo_dlzka = docasna_premenna;
    }
    
    const unsigned char RohVpravoDole = 0xd9;
    const unsigned char RohVlavoDole = 0xC0;
    const unsigned char RohVpravoHore = 0xBF;
    const unsigned char RohVlavoHore = 0xDA;
    const unsigned char PrepojkaVlavo = 0xC3;
    const unsigned char PrepojkaVpravo = 0xB4;
    const unsigned char Ciarka = 0xB3;
    const unsigned char CiarkaVodorovne = 0xC4;
    const unsigned char Kriz = 0xC5;
    const unsigned char Tecko = 0xC2;
    const unsigned char ObrateneTecko = 0xC1;

    COORD point = { X,Y };
      
    SetConsoleCursorPosition(hConsole, point); 
    putchar(RohVlavoHore);
    for (int i = 0; i <= 8; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(Tecko);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoHore);
    Y = Y + 1;
    point.Y = Y;


    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("Meno:    ");

    putchar(Ciarka);
    if (docasna_premenna > 0) {
        for (int i = 0; i <= (12 - cislo_dlzka - 1); i++) {
            putchar(' ');
        }
    }
    printf(" %s %s  ", meno, priezvisko);
    
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= 8; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(Kriz);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("Vyska:   ");
    putchar(Ciarka);
    for (int i = 0; i <= dlzka-vyska_dlzka-3; i++) {
        putchar(' ');
    }
    printf("%s cm", vyska);
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= 8; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(Kriz);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("Vaha:    ");
    putchar(Ciarka);
    for (int i = 0; i <= dlzka - vaha_dlzka-3; i++) {
        putchar(' ');
    }
    printf("%s kg", vaha);
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;


    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= 8; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(Kriz);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("Tel. c.: ");
    putchar(Ciarka);
    if (docasna_premenna <= 0) {
        for (int i = 0; i <= dlzka - cislo_dlzka; i++) {
            putchar(' ');
        }
    }
    else putchar(' ');
    printf("%s", cislo);
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(RohVlavoDole);
    for (int i = 0; i <= 8; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(ObrateneTecko);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoDole);
    point.Y = Y + 1;




    SetConsoleCursorPosition(hConsole, point);
    getchar();
    
}
void menu_hudba()
{
    int Y = 1;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("==================ULOHA 2.4===================\n");
    const unsigned char RohVpravoDole = 0xd9;
    const unsigned char RohVlavoDole = 0xC0;
    const unsigned char RohVpravoHore = 0xBF;
    const unsigned char RohVlavoHore = 0xDA;
    const unsigned char PrepojkaVlavo = 0xC3;
    const unsigned char PrepojkaVpravo = 0xB4;
    const unsigned char Ciarka = 0xB3;
    const unsigned char CiarkaVodorovne = 0xC4;
    const unsigned char Kriz = 0xC5;
    const unsigned char Tecko = 0xC2;
    const unsigned char ObrateneTecko = 0xC1;
    COORD point = { 3,1 };

    SetConsoleCursorPosition(hConsole, point);
    putchar(RohVlavoHore);
    for (int i = 0; i <= 27; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(Tecko);
    for (int i = 0; i <= 9; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoHore);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("1) Prehrat                  ");
    putchar(Ciarka);
    for (int i = 0; i <= 9; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("2) Zastavit                 ");
    putchar(Ciarka);
    for (int i = 0; i <= 9; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("3) Pokracovat               ");
    putchar(Ciarka);
    for (int i = 0; i <= 9; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("4) Ukoncit                  ");
    putchar(Ciarka);
    for (int i = 0; i <= 9; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("5) Vypnut                   ");
    putchar(Ciarka);
    for (int i = 0; i <= 9; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= 27; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(ObrateneTecko);
    for (int i = 0; i <= 9; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;


    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= 38; i++) {
        putchar(' ');
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(RohVlavoDole);
    for (int i = 0; i <= 38; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoDole);
    point.Y = Y + 1;
}
void uloha24() 
{
    char prikaz[100];
    char nazov[100];
    system("cls");
    
    menu_hudba();
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point = { 33,2 };
    SetConsoleCursorPosition(hConsole, point);
    while (1) {
        point.X = 33;
        point.Y = 2;
        SetConsoleCursorPosition(hConsole, point);
        fgets(prikaz, sizeof(prikaz), stdin);
        point.X = 5;
        point.Y = 8;

        if (strncmp(prikaz, "1", 1) == 0) {
            
            SetConsoleCursorPosition(hConsole, point);
            printf("Zadaj nazov: ");
            fgets(nazov, sizeof(nazov), stdin);
            nazov[strcspn(nazov, "\n")] = '\0';

            char playCommand[512];
            sprintf(playCommand, "open \"%s\" alias FILE1", nazov);
            mciSendStringA(playCommand, NULL, 0, 0);

            mciSendStringA("play FILE1", NULL, 0, 0);
        }
        else if (strncmp(prikaz, "2", 1) == 0) {
            mciSendStringA("pause FILE1", NULL, 0, 0);
            SetConsoleCursorPosition(hConsole, point);
            printf("Zastavenie                            ");
        }
        else if (strncmp(prikaz, "3", 1) == 0) {
            mciSendStringA("resume FILE1", NULL, 0, 0);
            SetConsoleCursorPosition(hConsole, point);
            printf("Pokracovanie                          ");
        }
        else if (strncmp(prikaz, "4", 1) == 0) {
            mciSendStringA("stop FILE1", NULL, 0, 0);
            mciSendStringA("close FILE1", NULL, 0, 0);
            SetConsoleCursorPosition(hConsole, point);
            printf("Ukoncenie                             ");
        }
        else if (strncmp(prikaz, "5", 1) == 0) {
            break;
        }
        else {
            SetConsoleCursorPosition(hConsole, point);
            printf("Neplatny prikaz");
        }
    }
}

void menu_klavesnica()
{
    int Y = 1, dlzka = 45;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("====================ULOHA 2.6=====================\n");
    const unsigned char RohVpravoDole = 0xd9;
    const unsigned char RohVlavoDole = 0xC0;
    const unsigned char RohVpravoHore = 0xBF;
    const unsigned char RohVlavoHore = 0xDA;
    const unsigned char PrepojkaVlavo = 0xC3;
    const unsigned char PrepojkaVpravo = 0xB4;
    const unsigned char Ciarka = 0xB3;
    const unsigned char CiarkaVodorovne = 0xC4;
    const unsigned char Kriz = 0xC5;
    const unsigned char Tecko = 0xC2;
    const unsigned char ObrateneTecko = 0xC1;
    COORD point = { 1,1 };
    SetConsoleCursorPosition(hConsole, point);
    putchar(RohVlavoHore);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoHore);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    for (int i = 0; i <= dlzka; i++) {
        printf(" ");
    }
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(PrepojkaVlavo);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(PrepojkaVpravo);
    Y = Y + 1;
    point.Y = Y;
    SetConsoleCursorPosition(hConsole, point);
    putchar(Ciarka);
    printf("F1 = Navod | F2 = Spustenie | F10/ESC = Koniec");
    putchar(Ciarka);
    Y = Y + 1;
    point.Y = Y;

    SetConsoleCursorPosition(hConsole, point);
    putchar(RohVlavoDole);
    for (int i = 0; i <= dlzka; i++) {
        putchar(CiarkaVodorovne);
    }
    putchar(RohVpravoDole);
    Y = Y + 1;
    point.Y = Y;
}


void uloha26()
{
    system("cls");
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    menu_klavesnica();
    COORD point = { 1,1 };
    unsigned char ch = 0;
    while (!0) {
        if (kbhit())
        {
            ch = getch();
            char cch;
            switch (ch)
            {
            case 0x00:
                cch = getch();

                if (cch == 59) {
                    point.X = 3;
                    point.Y = 4;
                    SetConsoleCursorPosition(hConsole, point);
                    printf("==========Random generator pismeniek=========\n");
                    point.X = 3;
                    point.Y = 5;
                    SetConsoleCursorPosition(hConsole, point);
                    printf("F1= Navod\n");
                    point.X = 3;
                    point.Y = 6;
                    SetConsoleCursorPosition(hConsole, point);
                    printf("F2= Spustenie\n");
                    point.X = 3;
                    point.Y = 7;
                    SetConsoleCursorPosition(hConsole, point);
                    printf("F10/ESC= Koniec\n");
                    point.X = 3;
                    point.Y = 8;
                    SetConsoleCursorPosition(hConsole, point);
                    printf("Bud co najrychlejsi!\n");
                }
                else if (cch == 60) {
                    int porovnanie = 0;
                    while (1) {
                        point.X = 0;
                        point.Y = 0;
                        SetConsoleCursorPosition(hConsole, point);
                        menu_klavesnica();
                        clock_t Start, Koniec;  
                        float  Trvanie;
                        srand(time(NULL));
                        int pismenko = ((rand() % 22) + 97);
                        point.X = 24;
                        point.Y = 7;
                        SetConsoleCursorPosition(hConsole, point);
                        printf("%c", pismenko);
                        Start = clock();
                        while ((porovnanie = getch()) != pismenko)
                        {
                            if (porovnanie == 27 || porovnanie == 68) return;
                         
                        };
                        Koniec = clock();
                        Trvanie = (float)(Koniec - Start) / CLOCKS_PER_SEC;

                        point.X = 20;
                        point.Y = 2;
                        SetConsoleCursorPosition(hConsole, point);
                        printf("%.2f sekund", Trvanie);
                        Sleep(2000);
                    }
                }
                else if (cch == 68 || cch == 27) {
                    return;
                }
            }
        }
    }
    return 0;

}
void main()
{

    char vyber;
    while (1) {
        system("cls");
        printf("================BLOK 2=================\n\n");
        printf("1) Uloha 2.1.1 - Procesor         (1b)\n2) Uloha 2.1.2 - Procesor         (1b)\n3) Uloha 2.3.1 - Disky            (2b)\n============================Spolu: 4b==\n\n");
        printf("4) Uloha 2.5.1 - Grafika          (1b)\n5) Uloha 2.5.2 - Semigrafika      (3b)\n============================Spolu: 4b==\n\n");
        printf("6) Uloha 2.4 - Multimedia         (4b)\n7) Uloha 2.6 - Klavesnica a mys   (4b)\n============================Spolu: 8b==\n\n");
        printf("Vyberte od 1 po 7 (pre ukoncenie stlacte Q): ");
        scanf("%c", &vyber);

        switch (vyber) {
        case '1':
            getchar();
            uloha211();
            break;
        case '2':
            getchar();
            uloha212();
            break;
        case '3':
            getchar();
            uloha231();
            break;
        case '4':
            getchar();
            uloha251();
            break;
        case '5':
            getchar();
            uloha252();
            break;
        case '6':
            getchar();
            uloha24();
            break;
        case '7':
            getchar();
            uloha26();
            break;

        case 'Q':
        case 'q':
            exit(0);
        default:
            printf("Zle zadany vyber, prosim skuste to znovu\n");
        }
    }
    return 0;
}
