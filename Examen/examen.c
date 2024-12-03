
#include <stdio.h>
#include <stdlib.h>

#define CANT 2

typedef struct {

    char * nombre[50];
    int edad;
    char materia[20];



}Alumno;

void anotarAlumno(Alumno alum[]){

    printf("Ingrese nombre:\n");
    scanf("%s",alum->nombre);
    printf("Ingrese edad:\n");
    scanf("%d",&alum->edad);
    printf("ingrese manteria:\n");
    scanf("%s",alum->materia);

}

void inscribeAlgebra(Alumno alum[]){

    FILE * archivo = fopen("algebra.data","wb+");
    if (archivo != NULL){

        fwrite(&alum[0],sizeof(Alumno),1,archivo);

    }

    fclose(archivo);

}


void inscribeLogica(Alumno alum[]){

    FILE * archivo = fopen("logica.data","wb+");
    if (archivo != NULL){

        fwrite(&alum[0],sizeof(Alumno),1,archivo);


    }

    fclose(archivo);


}


void inscribeInformatica(Alumno alum[]){

    FILE * archivo = fopen("informatica.data","wb+");
    if (archivo != NULL){

        fwrite(&alum[0],sizeof(Alumno),1,archivo);


    }

    fclose(archivo);


}


void inscribeAlgoritmos(Alumno alum[]){

    FILE * archivo = fopen("algoritmos.data","wb+");
    if (archivo != NULL){

        fwrite(&alum[0],sizeof(Alumno),1,archivo);


    }

    fclose(archivo);


}

void alumnoInscripto(const char *alumno,const char * materia){

Alumno comparacion;

FILE * archivo;

    if(strcmp(materia,"logica") == 0){

         archivo = fopen("logica.data","rb+");


    }else if (strcmp(materia,"informatica") == 0){

         archivo = fopen("informatica.data","rb+");


    }else if(strcmp(materia,"algoritmos") == 0){

         archivo = fopen("algoritmos.data","rb+");


    }else if(strcmp(materia,"algebra") == 0){

         archivo = fopen("algebra.data","rb+");


    }


    if(archivo != NULL){


        printf("carga exitosa\n");

        while(fread(&comparacion,sizeof(Alumno),1,archivo) == 1){

            printf("el nombre es %s\n",comparacion.nombre);
            if(strcmp(comparacion.nombre,alumno) == 0){

                printf("Alumno %s encontrado en la materia %s",comparacion.nombre,materia);
                break;
            }

        }

        printf("finalizado");
    }

fclose(archivo);
}



int main(){

Alumno ingreso[CANT];
char alumno1[50];
char materia1[20];

for(int i = 0;i<CANT;i++){

      anotarAlumno(&(ingreso[i]));
    if(strcmp(ingreso[i].materia,"algebra") == 0){

        inscribeAlgebra(&(ingreso[i]));


    }else if(strcmp(ingreso[i].materia,"logica") == 0){

        inscribeLogica(&(ingreso[i]));


    }else if(strcmp(ingreso[i].materia,"informatica") == 0){

        inscribeInformatica(&(ingreso[i]));


    }else if(strcmp(ingreso[i].materia,"algoritmos") == 0){

        inscribeAlgoritmos(&(ingreso[i]));


    }else printf("materia no valida");

}



printf("ingrese alumno a encontrar:\n");
scanf("%s",alumno1);
printf("ingrese materia en donde desea iniciar la busqueda\n");
scanf("%s",materia1);
alumnoInscripto(alumno1,materia1);



return 0;
}
