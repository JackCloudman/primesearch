#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
int numint,total=0,i=3,es_primo,primo,limite;
float num;
int main(){
  //Leemos un numero entero
  scanf("%f",&num );
  numint=num;
  if(num>=2&&(num-numint)==0){
    clock_t start = clock();
    int listaprimos[numint/2];
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
        listaprimos[total]=i;
      }
      i+=2;
    }
    printf("[");
    for(i=0;i<total;i++){
      if(listaprimos[i]==0){
        break;
      }
      printf("%d,",listaprimos[i]);
    }
    printf("%d",listaprimos[total]);
    printf("]");
    printf("\nTiempo: %fs\n",((double)clock()-start)/1000);
  }
  else{
    printf("Debe ser un numero entero mayor o igual a 2!\n");
  }
  return 1;
}
