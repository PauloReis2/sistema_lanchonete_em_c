#include <stdio.h>
#include <string.h>
//Não consegui rodar o programa sem definir o maximo de pedidos e uma variavel para le - la
#define MAX_PEDIDOS 5
//Iria colocar também o nome dos pedidos mas ficaria meio irrelevante, afinal o sistema é para cadastrar os pedidos no caixa
typedef struct{
	int codpedidos;
	float valorpedidos;
} pedidos;

//Vou criar aqui uma fução para limpar o buffer do teclado
void limpa(){
	int l;
	while ((l = getchar()) != '\n' && l != EOF);
}
//Finalmalmente o inicio do main
int main(){
	pedidos lista[MAX_PEDIDOS];
	int totalderegistros = 0;
	int opcao;
	
	
	do{
		printf ("\n=====================================\n");
		printf ("Sistema de Caixa de Lanchonete \n");
		printf (" 1. Registrar pedido do cliente\n");
		printf (" 2. Pedidos ja registrados\n");
		printf (" 3. Sair\n");
		printf ("Escolha uma opcao: ");
		scanf ("%d", &opcao);
		limpa();
		
		switch (opcao){
			case 1:
				if (totalderegistros < MAX_PEDIDOS){
				
					printf ("\n------ Registro de Pedido ------\n");
				
					printf ("Codigo do pedido: ");
					scanf ("%d", &lista[totalderegistros].codpedidos);
					//Aqui eu percebi que ter o valor do produto aqui também é meio irrelevante, afinal pelo código daria pra saber o valor
					printf ("Valor do pedido: ");
					scanf ("%f", &lista[totalderegistros].valorpedidos);
				
					limpa();
					totalderegistros++;
					printf ("Pedido Registrado com sucesso\n");
		        }else{
		        	printf ("\n[AVISO] Limite de pedidos atingido\n");
				}
				break;
		
		    case 2:
		    	printf ("\n------ Pedidos ja registrado ------\n");
				if (totalderegistros == 0){
					printf ("Nenhum pediso cadastrado no momento\n");
				}else{
					float valortotal = 0;
					for (int i = 0; i < totalderegistros; i++){
						valortotal += lista[i].valorpedidos;
						printf ("[%d] Codigo: %d| Valor: R$ %.2f \n", i +1, lista[i].codpedidos, lista[i].valorpedidos);
					}("------ Pedidos já Registrados ------\n");
				
				printf ("----------------------------------------\n");
				printf ("Valor total do pedido: R$ %.2f\n", valortotal);
			    }
				break;
			
			case 3:
			    printf ("Fechando o Registro. Ate o proximo turno");
				break;
			
			default:
				printf ("\n[ERRO] Opcao invalida\\n");
				break;
		    }
		} while (opcao != 3);
		return 0;
	
	}//percebi que poderia ter criado uma função para armazenar todas essas linhas que digitei no codigo 

