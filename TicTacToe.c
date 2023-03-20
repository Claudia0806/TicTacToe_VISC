#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

char matriz[3][3];

//Limpia el tablero, dejandolo en blanco
void clean()
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}

//Imprime la matriz en pantalla
void print_matrix()
{
    int f;
    for(f=0; f<3; f++) {
        printf(" %c | %c | %c ",matriz[f][0], matriz[f][1], matriz [f][2]);
        if(f!=2) printf("\n---|---|---\n");
    }
    printf("\n");
}

//Imprime movimientos del jugador
void movement(char player)
{
    int x;
    printf("Jugador = %c. Ingrese la casilla que desee ", player);
    x = get_int(":");

    int row = (x - 1)/3;
    int col = (x - 1)%3;

    if(matriz[row][col]!= ' ')
    {
        printf("Movimiento no válido\n");
        movement(player);
    }
    else
        matriz[row][col] = player;
}

//Checa si hay un ganador
char check_winner()
{
    int i;
    for(i=0; i<3; i++)
        if(matriz[i][0]== matriz[i][1] && matriz[i][0]==matriz[i][2])
            return matriz[i][0];

    for(i=0; i<3; i++)
        if(matriz[0][i]== matriz[1][i] && matriz[0][i]==matriz[2][i])
            return matriz[0][i];

    if(matriz[0][0]==matriz[1][1] && matriz[1][1]==matriz[2][2])
        return matriz[0][0];

    if(matriz[0][2]==matriz[1][1] && matriz[1][1]==matriz[2][0])
        return matriz[0][2];


    int row, col;
    for(row=0; row<3; row++) {
        for(col=0; col<3; col++) {
            if(matriz[row][col] == ' ') {
                return ' ';
            }
        }
    }

    return ' ';
}

bool tie()
{
    char flag = check_winner();
    if (flag == ' ') {
        int row, col;
        for(row=0; row<3; row++) {
            for(col=0; col<3; col++) {
                if(matriz[row][col] == ' ') {
                    return false;
                }
            }
        }
        return true ;
    }
    return false ;
}


int main()
{
    printf("Hello world");
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}





