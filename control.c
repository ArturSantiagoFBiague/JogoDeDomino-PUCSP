#include "model.c"
#include "controlHeader.h"
#include "view.c"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//estrutura de criação das peças
int criandoPeca(){
   c = 0;
    //criação das peças e mostrando na tela
    for ( int a = 0 ; a < 7 ; a++){
        for (b = a ; b < 7 ; b++){
            pecasDomino[c].le = a;
            pecasDomino[c].ld = b;

            printf("\n Peca %d: [%d | %d] ",c+1,a,b);
            c++;
        }
    }
}

//estrutura de reorganização de peças
int ReorganizarPeca(){
    //criação das peças e mostrando na tela
    c = 0;
    for ( a = 0 ; a < 7 ; a++){
        for ( b = a ; b < 7 ; b++){
            pecasjogo[c].le = a;
            pecasjogo[c].ld = b;
            printf("\n Peca %d: [%d][%d] ",c+1,a,b);
            c++;
        }
    }
    printf("\n*PECAS REORGANIZADAS*\n");
}

//estrutura de embaralhamento de peças
int embaralharPeca(){
    //exibição das peças embaralhadas
    int a= 0, b = 0, c = 0, test = 0;
    int embaralha[28];

    printf(" \n*Pecas do DOMINO EMBARALHADAS ");

    for (a = 1 ; a < 28 ; a++) embaralha[a] = 30;
    embaralha[0] = rand() %28;
    a = 1;

    //cria número aleatório sem repetir
    srand(time(NULL));

    while ( a < 28 )
            {
            c = rand() %28;
            test = 0;

            // rotina para testar se a peca e repetida
            for (b = 0 ; b < a ; b++)
                {
                if ( embaralha[b] == c) test = 1;
                }

            if (test == 0)
                {
                embaralha[a] = c;
                a++;
                }
            }

    for (a = 0 ; a < 28 ; a++)
            {
            c = embaralha[a];
            printf("\n Peca %d: [%d | %d]",c,pecasDomino[c].le,pecasDomino[c].ld);
            }

    printf("\n\n*PECAS EMBARALHADAS** ");
}

//estrutura de exibição das peças
int exibindoPeca(){
    // exibição das peças alinhadas
    printf(" \n\n\n*Pecas do DOMINO** ");

    for (int a = 0 ; a < 28 ; a++){
        printf("\nPeca %d: [%d | %d]", a+1, pecasjogo[a].le, pecasjogo[a].ld);
    }
    printf("\n*PECAS MOSTRADAS**");
}

//chamar Menu/switch
int chamarSwitch(){
    int sair = 1;
    int mode;

    while(sair!=0){


        mostraMenu();
        scanf("%d", &mode);


        switch(mode){

        case 1:
        criandoPeca();
        break;

        case 2:
        embaralharPeca();
        break;

        case 3:
        ReorganizarPeca();
        break;

        case 4:
        exibindoPeca();
        break;


        case 5:
        sair = 0;
        break;

        }
    }
}
