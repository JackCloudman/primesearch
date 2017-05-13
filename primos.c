#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
unsigned int numint,i=3,total=0,primo,limite;
short es_primo;
float num;
int main(){
  //Leemos un numero entero
  scanf("%f",&num );
  numint=num;
  if(num>=2&&(num-numint)==0){
    clock_t start = clock();
    int *listaprimos;
    listaprimos=(int*)calloc(1,sizeof(int));
    listaprimos[0]=2;
    while(i<=num){
      limite=((int)pow(num,0.5))+1;
      es_primo=1;
      for(primo=0;primo<=total;primo++){
        if(i%listaprimos[primo]==0){
          es_primo=0;
          break;
        }
        if(listaprimos[primo]>limite){
          break;
        }
      }
      if(es_primo){
        total++;
        listaprimos=(int*)realloc(listaprimos,sizeof(int)*(total+1));
        listaprimos[total]=i;
      }
      i+=2;
    }
    printf("\nCalculado!\nTiempo: %fs\nTotal de numeros primos encontrados:%d\nMayor numero primo encontrado:%d\n",((double)clock()-start)/1000,total+1,listaprimos[total]);
    system("PAUSE");
    printf("[");
    for(i=0;i<total;i++){
      if(listaprimos[i]==0){
        break;
      }
      printf("%d,",listaprimos[i]);
    }
    printf("%d",listaprimos[total]);
    printf("]");
  }
  else{
    printf("Debe ser un numero entero mayor o igual a 2!\n");
  }
  return 1;
}
