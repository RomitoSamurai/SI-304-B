#include <stdio.h>
#define N 6

int op, numero ,linha, coluna;
int grade1[N][N]=
  {{ 0, 6, 0, 1, 0, 4},
   { 0, 0, 8, 3, 0, 5},
   { 2, 0, 0, 0, 0, 0},
   { 8, 0, 0, 4, 0, 7},
   { 0, 0, 6, 0, 0, 0},
   { 7, 0, 0, 9, 0, 1},
  };

void desenha_grade() {
  int i,j;
  printf("  0  1  2   3  4  5 \n");
  printf("+---------+---------+\n");
  for (i = 0; i < N; i++) {
	printf("|");
	for (j = 0; j < N; j++) {
	  if (grade1[i][j] != 0)
	printf(" %d ", grade1[i][j]);
	  else
	printf("   ");
	  if (j % 3 == 2) 
	printf("|");
	}
	if (i % 3 == 2)
	  printf("\n+---------+---------+");
	printf("\n");
  }
}
void dificuldade(){
		int opcao;
		  printf("Selecione a Dificuldade \n");
	printf("1. Facil \n2. Medio \n3. Dificil\n");
    scanf("%d", &opcao);
    printf("\n");
    if(opcao != 1 && opcao != 2 &&  opcao != 3 &&  opcao != 4 &&  opcao != 5){
    			printf("\nOpcao Invalida.\n\n");
    			menu();
			}
	 switch(opcao){
    	case 1:
    		desenha_grade();
    		colocar_numero();
    		break;
    	case 2:
    		break;
    	case 3:
    		break;
    	
	}
}

void menu(){
	
		int opcao;
	printf("--- Menu --- \n");
	printf("1. Jogar\n2. Regras\n3. Sair\n");
    scanf("%d", &opcao);
    printf("\n");
    if(opcao != 1 && opcao != 2 &&  opcao != 3){
    			printf("\nOpcao Invalida.\n\n");
    			menu();
			}
	 switch(opcao){
    	case 1:
    		dificuldade();
    		break;
    	case 2:
    			printf("REGRAS DO JOGO\n");
		printf("O objetivo do jogo e completar todos os quadrados utilizando\n");
		printf("numeros de 1 a 9. Para completa-los, seguiremos a seguinte regra: \n"); 
		printf("Nao podem haver numeros repetidos nas linhas horizontais e verticais, \n");
		printf("assim como nos quadrados grandes.\n\n\n");
	
		menu();
    		break;
    	case 3:
    		break;
    	
	}
	
}
int existe_numero(linha,coluna){
	if(grade1[linha][coluna] == 0){
		  return 1;
	}else{
	return 0;
	}
}
int numero_valido(numero){
	if(numero >= 1 && numero <= 9 ){
		return 1;
	}else
		printf("O numero deve ser entre 1 e 9.\n\n");
		return 0;
}
void colocar_numero(){
	 printf("Digite uma linha: ");
   scanf("%d", &linha);
 
   printf("Digite uma coluna: ");
   scanf("%d", &coluna);
   
   printf("Digite o numero: ");
   scanf("%d", &numero);
    //Validando Numero
   if(numero_valido(numero)){
   	
   		if(existe_numero(linha,coluna) == 1 ){
		   
   			if(existenaColuna(coluna,numero) == 1){
   			
   				if(existenalinha(linha,numero) == 1){
   				
   					grade1[linha][coluna] = numero;
				   }else
		   				{
		   				printf("O numero ja existe na linha!\n");
		   				}
   			
		   }
		   else
		   {
		   	printf("O numero ja existe na coluna!\n");
		   }
		   
		}
		else
		{
				printf("A posicao desta linha e coluna ja foi preenchido. Por favor escolha outra \n\n");
		}
		   
   }
 	desenha_grade();
   colocar_numero();
   
}
int existenaColuna(coluna,numero)
 {
		int i;			   
	  for (i=0; i<9; i++)
	   {
		  if (grade1[i][coluna] == numero){
		  
			  return 0;
			  break;
	 
			}

	}
		
return 1;
}
int existenalinha(linha,numero) 
{
	int j;		
	   for (j=0; j<9; j++)
	   {
		   if (grade1[linha][j] == numero){
		   
			   return 0;
			   break;
		
		}
	}
	return 1;
}
int main(){

    printf("Jogo Sudoku v.01");
    printf("\n\n\n");
  
    
   menu();
    		
	
	return 0;
}
