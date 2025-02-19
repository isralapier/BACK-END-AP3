#include <stdio.h>
#include <stdlib.h>

//ESTRUCTURA ARBOL AVL
typedef struct avl{

    int altura;
    int dato;
    struct avl * izq;
    struct avl * der;

}nodo;

//ESTRUCTURA PARA LA COLA
typedef struct Cola{
    nodo ** arreglo;       //arreglo de punteros a nodos
    int frente;
    int ultimo;
    int capacidad;
}cola;


//FUNCIONES PARA ARBOL
int max(int a,int b);
int alturaNodo(nodo *);
int altura(nodo*);
int factorEquilibrio(nodo *);
nodo * rotacionIzquierda(nodo *);
nodo * nuevoNodo(int);
nodo * insertar(nodo*,int);
nodo * obtenerMinimo(nodo *);
nodo * eliminar(nodo*,int);



//FUNCIONES PARA MANEJAR LA COLA
cola * crearCola(int);
int colaVacia(cola *);
void encolar(cola *,nodo*);
nodo * desencola(cola *);
void recorridoHorizontal(nodo*);

// MAIN
int main(){

//MENU ITERATIVO
nodo *arbol = NULL;
int opcion,valor;

do{
    printf("\n ====MENU ARBOL AVL ==== \n"); //MENU
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    printf("3. Mostrar arbol (recorrido por niveles)\n");
    printf("4.  Salir\n");
    printf("Seleccione una opcion:");
    scanf("%d",&opcion);

    switch(opcion){
    case 1:
        printf("Ingrese un valor a insertar: ");
        scanf("%d", &valor);
        nodo *nuevo_arbol = insertar(arbol, valor);
        if (nuevo_arbol != NULL) {
        arbol = nuevo_arbol;
        } else {
        printf("Error al insertar.\n");
            }
        break;

    case 2:
            printf("Ingrese un valor a eliminar: "); //ELIMINAR
            getchar();
            scanf("%d",&valor);
            arbol = eliminar(arbol,valor);
            break;
    case 3:
            printf("Arbol AVL (Recorrido por niveles):\n"); //RECORRIDO HORIZONTAL
            recorridoHorizontal(arbol);
            printf("\n");
            break;
    case 4:
            printf("Salida exitosa\n"); //SALIR
            break;

    default:
            printf("Opcion invalida, intente de nuevo"); //OPC INVALIDA

    }

}while (opcion != 4);





return 0;
}

///////////////////////////////////////FUNCIONES ARBOLES
//FUNCION MAX
int max(int a,int b){

return (a > b) ? a : b;

}


//FUNCION ALTURA
int altura(nodo * Nodo){

if(Nodo == NULL){

    return 0;

}else{

return Nodo->altura;

}

}


//FUNCION ALTURA NODO
int alturaNodo(nodo * a){

    if(a != NULL){

        int hizq = alturaNodo(a->izq);
        int hder = alturaNodo(a->der);
        if(hizq > hder){

            return 1 + hizq;

        }else {

            return 1 + hder;

        }

    }else{

    return 0;

        }

    }



//FUNCION FACTOR EQUILIBRIO
int factorEquilibrio(nodo * n){

    return alturaNodo(n->izq) - alturaNodo(n->der);


}

//FUNCION ROTACION SIMPLE IZQUIERDA
nodo * rotacionIzquierda(nodo * x){


        nodo * y,*t; //Asigna nodos
        y = x->der;
        t = y->izq;


        y->izq = x; //Rota nodos
        x->der = t;

        //actualiza altura
        x->altura = 1 + max(altura(x->izq),altura(x->der));
        y->altura = 1 + max(altura(y->izq),altura(y->der));

        return y;
}

//FUNCION ROTACION SIMPLE DERECHA
nodo * rotacionDerecha(nodo * x){

    nodo * y,*t; // Asigna nodo
    y = x->izq;
    t = y->der;

    y->der = x; //rota nodos
    x->izq = t;

    //actualiza altura
    x->altura = 1 + max(altura(x->izq),altura(x->der));
    y->altura = 1 + max(altura(y->izq),altura(y->der));

    return y;

}


//FUNCION ROTACION DOBLE DERECHA
nodo * rotacionDobleDerecha(nodo * x){

    x->izq = rotacionIzquierda(x->izq);
    return rotacionDerecha(x);

}

//FUNCION ROTACION DOBLE IZQUIERA
nodo * rotacionDobleIzquiera(nodo * x){

    x->der = rotacionDerecha(x->der);
    return rotacionIzquierda(x);


}

//FUNCION NUEVO NODO
nodo * nuevoNodo(int n){

    nodo * nuevo;
    nuevo =(nodo*)malloc(sizeof(nodo));
    nuevo->altura = 0;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->dato = n;

    return nuevo;
}

//FUNCION INSERTAR
nodo * insertar(nodo * x,int n){

    if(x == NULL){

       return nuevoNodo(n);

    }else{
        if(n < (x->dato)){

        x->izq = insertar((x->izq),n);

    }else if(n > (x->dato)){

        x->der = insertar((x->der),n);

    }else {

       return x; // valor duplicado no permitido

    }

    }

    //actualizar altura del nodo
  x->altura = 1 + max(altura(x->izq),altura(x->der));

    //calcular factor de balanceo
 int balance = factorEquilibrio(x);


    //casos de desbalance

if(balance > 1 && n < x->izq->dato){  //COMPARACION SUBARBOLES

    return rotacionDerecha(x);

}else if(balance < -1 && n > x->der->dato){

    return rotacionIzquierda(x);

}else if(balance > 1 && n > x->izq->dato){

     return rotacionDobleDerecha(x);

}else if(balance < -1 && n < x->der->dato ){

    return rotacionDobleIzquiera(x);

}


    return x;



}

//FUNCION OBTENER MINIMO
nodo * obtenerMinimo(nodo * x){
       while(x->izq != NULL){

         x = x->izq;


       }

       return x;

}

//FUNCION ELIMINAR
nodo * eliminar(nodo * x,int valor){
    if(x == NULL){

        return x;

    }else{

         if(valor < x->dato){  //comparo mayor- menor

        x->izq = eliminar(x->izq,valor);

         }else if(valor > x->dato){

        x->der = eliminar(x->der,valor);

        }else{              //nodo encontrado

             if(x->izq == NULL || x->der == NULL){

                 if(x->izq != NULL){

                    x = x->izq;

                }else{

                    x = x->der;

                }


             }else{

                nodo * sucesor = obtenerMinimo(x->der);
                x->dato = sucesor->dato;
                x->der = eliminar(x->der,sucesor->dato);


        }

     }

}

if(x == NULL){

    return x;

}

    //actualizar altura
x->altura = 1 + max(altura(x->izq),altura(x->der));

    //calcular factor de balanceo
int balance = factorEquilibrio(x);

    //casos de desbalance
if(balance > 1 && factorEquilibrio(x->izq) >= 0){

    return rotacionDerecha(x);

}else if(balance > 1 && factorEquilibrio(x->izq) <0){

    return rotacionDobleDerecha(x);

}else if(balance < -1 && factorEquilibrio(x->der) <= 0){

    return rotacionIzquierda(x);

}else if(balance < -1 && factorEquilibrio(x->der) > 0){

    return rotacionDobleIzquiera(x);

}

return x;


}

/////////////////////////////////////FUNCIONES COLA

//FUNCION CREAR COLA
cola * crearCola(int capacidad){
    cola * Cola = (cola*)malloc(sizeof(cola));
    Cola->arreglo =((nodo**)malloc(capacidad * (sizeof(nodo*))));

    Cola->frente = 0;
    Cola->ultimo = -1;
    Cola->capacidad = capacidad;

    return Cola;
}

//FUNCION COLA VACIA
int colaVacia(cola * Cola){
    return Cola->ultimo < Cola->frente;
}


//FUNCION ENCOLA
void encolar(cola * Cola,nodo * Nodo){

    Cola->ultimo++;
    Cola->arreglo[Cola->ultimo] = Nodo;

}


//FUNCION DESENCOLA
nodo * desencola(cola * Cola){

    nodo * Nodo = Cola->arreglo[Cola->frente];
    Cola->frente++;
    return Nodo;

}


//FUNCION RECORRIDO HORIZONTAL
void recorridoHorizontal(nodo * Nodo){

if(Nodo == NULL){

    return;

}

cola * c = crearCola(100);

encolar(c,Nodo);

while(!(colaVacia(c))){

    nodo * Nuevo = desencola(c);
    printf("%d ",Nuevo->dato);



    if(Nuevo->izq != NULL){

        encolar(c,Nuevo->izq);

    }

    if(Nuevo->der != NULL){

        encolar(c,Nuevo->der);

    }
}
 free(c->arreglo);
 free(c);


}







