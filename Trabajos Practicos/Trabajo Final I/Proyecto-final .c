#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define N 2
#define FILAJUGADA 4
#define COLJUGADA 4
#define OPORTUNIDADES 4

int apuesta;
int contadorDeMovimientos;

void mueveArreglo(char x,int matriz[N][N]);
void imprimeArreglo(int matriz[N][N]);
int puntaje(int apuesta, int contadorDeMovimientos);
void ejecucion(int arreglo[N][N], int comparacion [N][N]);
bool matricesIguales(int arreglo[N][N],int comparacion[N][N]);
void cargaMatriz(int arreglo[N][N],int auxiliar[FILAJUGADA][COLJUGADA]);
bool filajugada(int repetir[FILAJUGADA],int filajugada);

int main(){

srand(time(NULL));

//CARGA VARIABLES
int cantidad= (N*N);
int auxiliar[FILAJUGADA][COLJUGADA]={{1,0,2,3},
                                     {1,0,2,3},
                                     {1,0,2,3},
                                     {1,0,2,3}};

int aux[FILAJUGADA];
int repetir[FILAJUGADA] = {0,0,0,0};
int arreglo[N][N];
int comparacion[N][N];
int puntajesPorRonda[OPORTUNIDADES];
int i;
int j;
int contador2=0;
int contador3=0;
int jugada;
int volverAJugar;
int jugadasHechas=0;
int rondasJugadas=0;
int puntos;




//LLENADO E IMPRESION ARREGLO AUXILIAR

printf("el arreglo llenado es: \n");

for (i=0;i<FILAJUGADA;i++){

    aux[i]=(i);

}

for(i=0;i<cantidad;i++){

    printf("%d ",aux[i]);

}


//CARGA MATRIZ DE COMPARACION


for (i=0;i<N;i++){

    for(j=0;j<N;j++){

        comparacion[i][j]=aux[contador2++];

    }
}



//EJECUCIÓN

for (i= 0;i < OPORTUNIDADES;i++){ //Oportunidades de una ronda



do {

     jugada = rand() % FILAJUGADA;

}

while (

       filajugada(repetir,jugada)  //Seleccion de jugadas no repetidas

       );

   repetir[jugada] = 1;
   jugadasHechas ++;

if (jugadasHechas == 2){

    for(j = 0;j < FILAJUGADA;j++ ){

        repetir[j] = 0;

    }

    jugadasHechas = 0;

}

   cargaMatriz(arreglo,aux);
   printf("\nel arreglo es: \n");
   imprimeArreglo(arreglo);
   printf("\nel arreglo de comparacion es: \n");
   imprimeArreglo(comparacion);
   ejecucion(arreglo,comparacion);


do{

   printf("\nDesea volver a jugar?: INGRESAR 1 PARA CONTINUAR / INGRESAR 0 PARA TERMINAR:  ");
   scanf("%d",&volverAJugar);

   }

while(

        volverAJugar != 1 && volverAJugar != 0 //Opcion volver a jugar

     );

   if(volverAJugar == 1){

    true;

   }else{

          printf("EL JUEGO HA FINALIZADO");
          i = OPORTUNIDADES;

    }
    puntos = puntaje(apuesta,contadorDeMovimientos);
    puntajesPorRonda[i] = puntos;

for(j = 0; j <= rondasJugadas;j++){

    printf("Puntos partida %d: %d \n",(j+1),puntajesPorRonda[j]); //Historial de puntajes

}
    rondasJugadas++;
    apuesta = 0;
    contadorDeMovimientos = 0;

}


return 0;

}




//////////////////////////////////////////////////FUNCIONES//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//CARGA MATRIZ/////////////////////////////////////////////////////////////////////
void cargaMatriz(int arreglo[N][N],int auxiliar[FILAJUGADA][COLJUGADA]){
int i;
int j;
int contador=0;


for(i=0;i<N;i++){

    for(j=0;j<N;j++){

        arreglo[i][j] = auxiliar[FILAJUGADA][contador];
        contador++;

    }


}


}





//FUNCION MOVIMIENTOS/////////////////////////////////////////////////////////

void mueveArreglo(char x,int matriz[N][N]){
int i=0;
int j=0;
int vacio1;
int vacio2;
int valorDeCambio;


    switch(x){

    case 's': for (i=0;i<N;i++){

                    for(j=0;j<N;j++){

                        if (matriz[i][j]==0){

                            vacio1=i;
                            vacio2=j;

                        }

                    }

                }


              if (vacio1<N-1){
                valorDeCambio=matriz[vacio1 + 1][vacio2];

           matriz[vacio1][vacio2]=valorDeCambio;
           matriz[vacio1+1][vacio2]=0;

             }else{printf("\nMOVIMIENTO INVALIDO\n");}

                break;

     case 'w': for (i=0;i<N;i++){

                    for(j=0;j<N;j++){

                        if (matriz[i][j]==0){

                            vacio1=i;
                            vacio2=j;

                        }

                    }

                }


              if (vacio1>0){
                valorDeCambio=matriz[vacio1 - 1][vacio2];

           matriz[vacio1][vacio2]=valorDeCambio;
           matriz[vacio1-1][vacio2]=0;

             }else{printf("\nMOVIMIENTO INVALIDO\n");}

             break;

    case 'a': for (i=0;i<N;i++){

                    for(j=0;j<N;j++){

                        if (matriz[i][j]==0){

                            vacio1=i;
                            vacio2=j;

                        }

                    }

                }


              if (vacio2>0){
                valorDeCambio=matriz[vacio1][vacio2 - 1];

           matriz[vacio1][vacio2]=valorDeCambio;
           matriz[vacio1][vacio2 - 1]=0;

             }else{printf("\nMOVIMIENTO INVALIDO\n");}

             break;

        case 'd': for (i=0;i<N;i++){

                    for(j=0;j<N;j++){

                        if (matriz[i][j]==0){

                            vacio1=i;
                            vacio2=j;

                        }

                    }

                }


              if (vacio2<N-1){
                valorDeCambio=matriz[vacio1][vacio2 + 1];

           matriz[vacio1][vacio2]=valorDeCambio;
           matriz[vacio1][vacio2 + 1]=0;

             }else{printf("\nMOVIMIENDO INVALIDO\n");}

             break;

        case 'q': printf("HA SALIDO DEL JUEGO!");

             break;

    default: printf("ERROR: INGRESE UN MOVIMIENTO VALIDO A-W-S-D\n");

    }}


//FUNCION IMPRESION MATRICES///////////////////////////////////////////////////

void imprimeArreglo(int matriz[N][N]){

int i;
int j;

for(i=0;i<N;i++){

    for(j=0;j<N;j++){

        printf("%2d\t",matriz[i][j]);
    }

    printf("\n");

}



}


//FUNCION PUNTAJE///////////////////////////////////////////////////////////////

int puntaje(int apuesta,int contadorDeMovimientos){

int puntos;


        if(contadorDeMovimientos>=(apuesta-10) || contadorDeMovimientos<apuesta){

            puntos = 1200;

        }if (contadorDeMovimientos>apuesta || contadorDeMovimientos<(apuesta+10)  ){

            puntos = 500;

        }if (contadorDeMovimientos==apuesta){

            puntos = 1000;

        }if (contadorDeMovimientos<(apuesta-10)){

            puntos = 1500;

        }else{

            puntos = 0;

        }

        return puntos;

}


//FUNCION MATRICES IGUALES///////////////////////////////////////////////////

bool matricesIguales(int arreglo[N][N],int comparacion[N][N]){

int i;
int j;

for(i = 0;i < N;i++){

    for(j = 0;j < N;j++){

      if(arreglo[i][j] != comparacion[i][j]) {

        return false;

      }

    }

}

return true;

}



//FUNCION EJECUCION DE JUEGO////////////////////////////////////////////////////////////////////////


void ejecucion(int arreglo[N][N],int comparacion[N][N]){
int valorMoviento;


do {

    printf("\nINGRESE UNA APUESTA DE MOVIMIENTOS ENTRE 40 Y 200 INCLUSIVE\n");
    scanf("%d",&apuesta);


    }

 while (

        apuesta < 40 || apuesta > 200

        );

 do {
    printf("\ningrese movimientos (W - S - A - D) o 'Q' para salir\n");
    getchar();
    scanf("%c",&valorMoviento);
    valorMoviento = tolower(valorMoviento);
    mueveArreglo(valorMoviento,arreglo);
    printf("\n");

    if (valorMoviento=='a' ||
        valorMoviento=='d' ||
        valorMoviento=='s' ||
        valorMoviento=='w')
        {

            system("cls");
            printf("Cantidad de movimientos: %d  Apuesta: %d\n",contadorDeMovimientos++,apuesta);
            imprimeArreglo(arreglo);


        }

      }


while(!matricesIguales(arreglo,comparacion) && valorMoviento != 'q' );


printf("Tus puntos obtenidos son: %d",puntaje(apuesta,contadorDeMovimientos));

}



//FUNCION FILA JUGADA//////////////////////////////////////////////////////////////////////////////

bool filajugada(int repetir[FILAJUGADA],int filajugada){


        if (repetir[filajugada] == 1){

           return true;
        }


return false;

}





