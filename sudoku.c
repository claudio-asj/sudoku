#include <stdio.h>
#include <time.h>

void print_matriz(int matriz[9][9]){
    printf("\n");
    int i,j,a=1,b=1;
    for (i = 1; i < 10; i++){
        if (i == 4 || i == 7)
            printf("\t");
        printf("\t%i", i);
    }

    printf("\n  -----------------------------------------------------------------------------------------------\n");

    for (i=0;i<9;i++){
        printf("%i |", i+1);
        for(j=0;j<9;j++){
            printf("\t%i",matriz[i][j]);
            if (a==3){
                printf("\t|");
                a=1;
            } else{
                a++;
            }
        }
        printf("\n");
        if(b==3){
            printf("  -----------------------------------------------------------------------------------------------\n");
            b=1;
        }else{
            b++;
        }
    }
    printf("\n");
}

int validacao(int a, int b, int matriz[9][9]){
    int resposta;
    a= a-1;
    b=b-1;
    if(matriz[a][b]==0){
        resposta = 1; // ok
        return resposta;
    } else{
        resposta=0;
        return resposta;
    }

}

int checar(int sudoku[9][9]){
     // checa linha e coluna juntos
    int i, j, k, l, a = 0, erro = 0;
    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            for (k = 0; k < 9; k++){
                if ((sudoku[i][j] == sudoku[i][k] && j != k) || (sudoku[i][j] == sudoku[k][j] && i != k))
                    return 0;
            }
            if (sudoku [i][j] == 0)
                return 0;
        }
    }
    
    // checa cada quadrado
    while (a < 9) {
        for (i = a; i < 3+a; i++){
            for (j = a; j < 3+a; j++){
                for (k = a; k < 3+a; k++){
                    for (l = a; l < 3+a; l++){
                        if ((sudoku[i][j] == sudoku[k][l] && i != k && j != l))
                            return 0;                        
                    }

                }            
            }
        }
        a += 3;
    }
    return 1;
}

//função de limpar tela do monitor
void limpaTela(){
     #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
}

int main (void){
    //inicio do jogo
    limpaTela();
    printf("\n\t\t*  ## ##   ##  ###  ### ##    ## ##   ##  ###  ##  ### *\n\t\t* ##   ##  ##   ##   ##  ##  ##   ##  ##  ##   ##   ## *\n\t\t* ####     ##   ##   ##  ##  ##   ##  ## ##    ##   ## *\n\t\t*  #####   ##   ##   ##  ##  ##   ##  ## ##    ##   ## *\n\t\t*     ###  ##   ##   ##  ##  ##   ##  ## ###   ##   ## *\n\t\t* ##   ##  ##   ##   ##  ##  ##   ##  ##  ##   ##   ## *\n\t\t*  ## ##    ## ##   ### ##    ## ##   ##  ###   ## ##  *\n");
    

    //matriz
    int sudokuFac[9][9] = {     {6, 0, 0, 3, 7, 5, 0, 1, 4},
                                {0, 4, 0, 0, 0, 0, 0, 7, 3},
                                {0, 0, 8, 0, 2, 0, 0, 0, 0},
                                {4, 0, 7, 9, 6, 0, 0, 2, 0},
                                {0, 8, 0, 2, 0, 0, 0, 0, 0},
                                {0, 2, 0, 0, 5, 1, 4, 0, 6},
                                {0, 0, 0, 0, 9, 0, 1, 0, 0},
                                {9, 7, 0, 0, 0, 0, 0, 3, 0},
                                {2, 6, 0, 5, 3, 7, 0, 0, 8}};


    int sudokuMed[9][9] = {     {3, 2, 6, 8, 0, 0, 0, 4, 7},
                                {5, 0, 0, 2, 0, 0, 0, 0, 6},
                                {0, 0, 0, 0, 0, 7, 0, 0, 2},
                                {0, 0, 2, 5, 0, 8, 0, 9, 4},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {6, 8, 0, 9, 0, 2, 1, 0, 0},
                                {1, 0, 0, 4, 0, 0, 0, 0, 0},
                                {2, 0, 0, 0, 0, 1, 0, 0, 9},
                                {8, 6, 0, 0, 0, 9, 7, 5, 1}};

    int sudokuDif[9][9] = {     {2, 0, 0, 4, 1, 3, 6, 8, 0},
                                {0, 0, 0, 2, 6, 9, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 0},
                                {0, 0, 1, 0, 0, 0, 0, 9, 0},
                                {0, 0, 6, 9, 0, 4, 5, 0, 0},
                                {0, 8, 0, 0, 0, 0, 3, 0, 0},
                                {0, 6, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 4, 7, 0, 0, 0},
                                {0, 1, 4, 8, 3, 6, 0, 0, 5}};
    
    int sudokuGG[9][9] = {      {0, 3, 4, 6, 7, 8, 9, 1, 2},
                                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    // recebendo de uma matriz base
    int sudoku[9][9];
    int base[9][9];
    int i,j;

    //igualando as matrizes
    int dif;
    while (1){
        printf("\nDificuldade do jogo:\n1 - Facil\n2 - Medio\n3 - Dificil\n4 - Sair\n");
        scanf("%d", &dif);

        switch(dif){
            case 1:
                for (i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        sudoku[i][j] = sudokuFac[i][j];
                        base[i][j] = sudokuFac[i][j];
                    }
                }
                break;
            case 2:
                for (i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        sudoku[i][j] = sudokuMed[i][j];
                        base[i][j] = sudokuMed[i][j];
                    }
                }
                break;
            case 3:
                for (i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        sudoku[i][j] = sudokuDif[i][j];
                        base[i][j] = sudokuDif[i][j];
                    }
                }
                break;
            case 4:
                printf("Programa encerrado!\n");        
                return 0;
            case 5:
                for (i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        sudoku[i][j] = sudokuGG[i][j];
                        base[i][j] = sudokuGG[i][j];
                    }
                }
                break;
        }
        if (dif < 1 || dif > 5)
            printf("\nValor invalido\n");
        else
            break;
    }
    
    //jogo
    int loop = 1;
    int comando,a,b,c;
    int tentativas=0;
    //contagem de tempo
    int tempo_inicial,tempo_final;
    tempo_inicial = time(NULL);
    print_matriz(sudoku);

    while (loop == 1){
        limpaTela();
        print_matriz(sudoku);

        printf("\n\t<======= Comandos =======>");
        printf("\n 1- Alterar Valor da Tabela\n 2- Checar Tabela\n 3- Desistir\n");
        scanf("%i", &comando);
        switch (comando)
        {
        case 1:
            printf("\nCoordenada  linha , coluna: ");
            scanf("%i %i", &a, &b);
            if( validacao(a,b,base)==1){
                printf("Valor: ");
                scanf("%i",&c);
                if(c<10 && c>0){
                    sudoku[a-1][b-1] = c;
                } else{
                    printf("\nValor Invalido!");
                }
                break;
            } else{
                printf("\nValor Invalido, essa coordenada não pode ser alterada");
                break;
            }
            
        
        case 2:
           //Rodar Função de checar tabela
           if (checar(sudoku)==1){
               tempo_final = time(NULL);
               limpaTela();
               printf("\n<===================================>");
               printf("\nParabéns! Voce Terminou com %i tentativas em %i minuto(s) e %i segundo(s). \n", tentativas+1, (tempo_final - tempo_inicial)/60, (tempo_final - tempo_inicial)%60);
               return 0;
           } else if(checar(sudoku)==0){
               printf("\n <=========>\nTem algo errado.");
           }
            break;
        case 3:
            printf("\n\t Game Over" );
            return 0;
            break;

        default:
            printf("Valor Invalido");
            break;
        }

        tentativas = tentativas + 1;
      
    }


    return 0;
}
