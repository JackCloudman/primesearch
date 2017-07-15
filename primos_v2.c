/*Programa que calcula los numeros primos que hay del rango 2-"n" numero,
las variables del main i = 3 nos indica el siguiente numero a buscar
el limite es la raiz cuadrada del numero a analizar, el rango maximo es el numero
hasta donde buscaremos numeros primos, total es la cantidad total de numeros primos que tenemos.
Se ocupa TAD list para guardar los numeros y ocupamos las variables primerN para el primer nodo
y ultimoN para el ultimo.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef struct lista{
  unsigned int numero;
  struct lista* siguiente;
}lista;
lista* primerN = NULL;
lista* ultimoN = NULL;
void guardarnumero(int num);
void mostrarnumeros();
int main(){
  int i=3,limite,rango_max,total=1;
  lista* j = NULL;
  short es_primo;
  //Creacion del primer nodo de la lista que contendra el numero "2"
  primerN = (lista*)calloc(1,sizeof(lista));
  primerN->numero = 2;
  primerN->siguiente = NULL;
  ultimoN = primerN;
  ////////////////////////////////////////////////////
  do{
    printf("Dame un numero mayor a 2: ");
    scanf("%d",&rango_max);
  }while(rango_max<2);
  clock_t start = clock();
  while(i<=rango_max){
    limite = (int)(pow(i,0.5)+1);
    es_primo = 1;
    j = primerN;
    while(j!=NULL){
      if((j->numero)>limite){
        break;
      }
      else{
        if(i%(j->numero)==0){
          es_primo = 0;
          break;
        }
      }
      j = j->siguiente;
    }
    if(es_primo){
      total++;
      guardarnumero(i);
    }
    i+=2;
  }
  printf("\nCalculado!\nTiempo: %fs\nTotal de numeros primos encontrados:%d\nMayor numero primo encontrado:%d\n",((double)clock()-start)/1000,total,ultimoN->numero);
  system("PAUSE");
  mostrarnumeros();
  return 0;
}
void guardarnumero(int num){
  ultimoN->siguiente= (lista*)calloc(1,sizeof(lista));
  ultimoN=ultimoN->siguiente;
  ultimoN->numero = num;
  ultimoN->siguiente = NULL;
}
void mostrarnumeros(){
  lista* i = primerN;
  printf("[");
  while(i!=ultimoN){
    printf("%d,",i->numero);
    i = i->siguiente;
  }
  printf("%d]\n",ultimoN->numero);
}
