#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
 unsigned char armarios=0;
 int menu,ocupar;
 srand(time(NULL));
  
  printf("\t* BEM VINDO AO SISTEMA DE ARMÁRIOS *\n\n");

  
 while(menu != 3){//Laço principal do Gerenciador 

 printf("   Armários disponíveis\n");
 printf(" *************************\n");
   
 for(int i=0;i<=7;i++){//onde verifica os armários dispoíveis
 armarios & 1<<i?printf(" * Armário %d- Ocupado*   *\n",i+1) : 
 printf(" * Armário %d- Desocupado *\n",i+1);
   }
   
 printf(" *************************\n");
 puts("_____________________________________________");
   
 //Menu do Gerenciador 
 printf("\n\n1- Ocupar armário\n2- Liberar armário\n3- Sair");
 printf("\nDigite a opção desejada: ");
 scanf("%d",&menu);


  switch(menu){

  case 1:
    if(armarios == 255){
     printf("\nTodos os armários já estão ocupados\n");
    }else{ 
      
    do{//loop para caso o número já tenha sido gerado
      ocupar = rand() % 8;
      }while ((armarios & 1<<ocupar) != 0); 
      
    armarios= armarios | (1 << ocupar); //ocupação dos armários
    printf("\nVocê ocupou o armário %d\n",ocupar+1);
      }
    
     break;
     
  case 2:
      printf("\nDigite a posição do armário: ");
      scanf("%d",&ocupar);
      ocupar--;
      if( (armarios & 1 << ocupar) == 0){
        printf("O armário selecionado já se encontra desocupado\n");
        }else{//desocupação dos armários
         armarios= armarios & ~(1 << ocupar);
       printf("\nVocê desocupou o armário %d\n\n",ocupar+1);}
    
     break; 
      
  case 3:
     printf("\nFechando sistema de armários...\n");
      
  }
}
return 0;
}