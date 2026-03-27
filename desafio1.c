#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mostrarArmarios(unsigned char armario){
    
    printf("Armarios disponiveis:\n");
    printf("7 6 5 4 3 2 1 0\n");
    printf("------------------------\n");
    
    for(int i = 7; i >= 0; i--){
        printf("%d ", (armario >> i)&1);
     };
     
}

unsigned char escolherArmarioAleatorio(unsigned char armario){
    srand(time(NULL));
    char armarioAleatorio = 0;
    int contador = 0; 
    
    do{
       armarioAleatorio = rand()%8;
       
       if(armario == 255){
            puts("Armarios esgotados!\n");
            break;
        }
        
    }while((armario >> armarioAleatorio)&1);
    
   printf("\n");
   printf("O armario aleatorio escolhido foi %d", armarioAleatorio);
    puts("\n");
        
    armario = armario | (1 << armarioAleatorio);
        
    return armario;
    
}

unsigned char esvaziarArmarios(unsigned char armario){
    
    int armarioEsvaziado = 0;
    
    puts("Digite o numero do armario que quer esvaziar:");
    scanf("%d", &armarioEsvaziado);
    
    if((armario >> armarioEsvaziado)&1){
        printf("Armario %d esvaziado!", armarioEsvaziado);
         armario = armario & ~(1 << armarioEsvaziado);
        
    }else{
        printf("Armario %d ja esta vazio!", armarioEsvaziado);
    }
    
    return armario;
}

int main(){
    
    unsigned char armario = 0;
    int resposta = 0;
    puts("\n");
    
    
    
    do{
        puts("\n\n‐-------------------------------\n");
        mostrarArmarios(armario);
        puts("\n\n‐-------------------------------\n");
        
        puts("\n");
        
        puts("1 - Receber armario");
        puts("2 - Esvaziar armario");
        puts("3 - Sair");
        scanf("%d", &resposta);
        
        switch(resposta){
            
            case 1: 
                armario = escolherArmarioAleatorio(armario);
                break;
           case 2:
               armario = esvaziarArmarios(armario);
               break;
               
           case 3: 
               puts("Encerrando programa!");
               break;
               
           default:
               puts("Opção nao encontrada!");
            
        }
        
    }while(resposta != 3);
   
    
    
    return 0; 
}