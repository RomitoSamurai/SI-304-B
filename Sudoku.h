#include <stdio.h>
#include <stdlib.h>
#define N 6

int grade1[N][N]=
  {{ 0, 0, 0, 1, 6, 0,0,0},
   { 0, 0, 0, 0, 0, 4,0,0},
   { 0, 2, 0, 0, 0, 3,0,0},
   { 3, 0, 0, 0, 5, 0,0,0},
   { 4, 0, 0, 0, 0, 0,0,0},
   { 0, 5, 1, 0, 0, 0,0,0},
  };

int grade2[N][N]=
  {{ 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0},
  };

void flag(){

    int cont, cont2;
    for(cont = 0; cont < 6; cont++)
        for(cont2 = 0; cont2 < 6; cont2++)
            if(grade1[cont][cont2] != 0)
                grade2[cont][cont2] = -1;
}
void desenha_grade() {
  int i,j;
  printf("   0   1  2   3  4  5 \n");
  printf("  +---------+---------+\n");
  for (i = 0; i < N; i++) {
	printf("%d |", i);
	for (j = 0; j < N; j++) {
	  if (grade1[i][j] != 0)
	printf(" %d ", grade1[i][j]);
	  else
	printf("   ");
	  if (j % 3 == 2)
	printf("|");
	}
	if (i % 3 == 1,5 && i != 0 && i != 2 && i != 4  )
	  printf("\n  +---------+---------+");
	printf("\n");




  }
}
void dificuldade(){
		int opcao;
         //system("clear");
		  printf("Selecione a Dificuldade \n");
	printf("1. Facil \n2. Medio \n3. Dificil\nDigite a opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    if(opcao != 1 && opcao != 2 &&  opcao != 3 &&  opcao != 4 &&  opcao != 5){
    			 //system("clear");
    			printf("\nOpcao Invalida.\n\n");
    			menu();
			}
	 switch(opcao){
    	case 1:
            //system("clear");
            flag();
    		desenha_grade();
    		colocar_numero();
    		break;
    	case 2:
    		//system("clear");
            flag();
    		desenha_grade();
    		colocar_numero();
    		break;
    	case 3:
    		//system("clear");
            flag();
    		desenha_grade();
    		colocar_numero();
    		break;

	}
}

void menu(){

		int opcao;
    printf("Jogo Sudoku v.01");
    printf("\n\n\n");
	printf("--- Menu --- \n");
	printf("1. Jogar\n2. Regras\n3. Sair\nDigite a opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    if(opcao != 1 && opcao != 2 &&  opcao != 3){
    			//system("clear");
    			printf("\nOpcao Invalida.\n\n");
    			menu();
			}
	 switch(opcao){
    	case 1:
            //system("clear");
    		dificuldade();
    		break;
    	case 2:
         system("clear");
    			printf("REGRAS DO JOGO\n");
		printf("O objetivo do jogo e completar todos os quadrados utilizando\n");
		printf("numeros de 1 a 6. Para completa-los, seguiremos a seguinte regra: \n");
		printf("Nao podem haver numeros repetidos nas linhas horizontais e verticais, \n");
		printf("assim como nos quadrados grandes.\n\n\n");

		menu();
    		break;
    	case 3:
    	 //system("clear");
    		break;

	}

}
void colocar_numero(){
    while(1){
        int linha,coluna, numero;
        printf("Digite o numero da linha: ");
        scanf("%d", &linha);
        printf("Digite o numero da coluna: ");
        scanf("%d", &coluna);
        if(grade2[linha][coluna] == -1){
            //system("clear");
            printf("O numero nao pode ser alterado\n");
        }
        else{
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &numero);
            if(numero > 0 && numero <= 6){
            if(existenaColuna(coluna,numero) == 1){

   				if(existenalinha(linha,numero) == 1){
   					if(valida_quadrante(linha-1,coluna-1,numero) == 1){

   					grade1[linha][coluna] = numero;
   						}else{
   								printf("O numero ja existe no quadrante!\n");
						   }
				   }else
		   				{
		   			
		   				printf("O numero ja existe na linha!\n");
		   				}

		   }
		   else
		   {
            //system("clear");
		   	printf("O numero ja existe na coluna!\n");
		   }
        }else{
        	
            //system("clear");
            desenha_grade();
			printf("O numero deve ser entre 1 e 6!\n");
        }

        }

        //system("clear");
        desenha_grade();
    }


}

int numero_valido(numero){
	if(numero >= 1 && numero <= 6 ){
		return 1;
	}else
		printf("O numero deve ser entre 1 e 6.\n\n");
		return 0;
}

int existenaColuna(coluna,numero)
 {
		int i;
	  for (i=0; i<6; i++)
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
	   for (j=0; j<6; j++)
	   {
		   if (grade1[linha][j] == numero){

			   return 0;
			   break;

		}
	}
	return 1;
}
int valida_quadrante(int i, int j, int k) {
 int c,l;
  for (l = 0; l < N; l++)
	if (grade1[l][j] == k)
	  return 0;
  for (c = 0; c < N; c++)
	if (grade1[i][c] == k)
	  return 0;
  for (l = i - i % 3; l < i - i % 3 +1; l++)
	for (c = j - j % 3; c < j - j % 3 + 1; c++)
	  if (grade1[l][c] == k)
	return 0;
	else
	return 1;

}
