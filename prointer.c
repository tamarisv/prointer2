#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void cadastrar_cliente()
{  
	int cod_cliente;     
	char *nome;
	char *rg;
	char *cpf;
	char *endereco;
	int data_nasc;
	int cnh;
	
	printf("\n === CADASTRAMENTO DE NOVO CLIENTE ===\n");
	
	printf("\nDigite o Codigo do Cliente: ");
	scanf("%d", &cod_cliente);
	nome = readline("Nome: ");
	rg = readline("RG (apenas numeros): ");
	cpf = readline("CPF (apenas numeros): ");
	endereco = readline("Endereco: ");
	printf("Data de Nascimento: ");
	scanf("%d", &data_nasc);
	printf("Carteira de Habilitacao: ");
	scanf("%d", &cnh);
	
	printf("\nCadastrando Cliente...\n");

// comandos para inserção do cadastro no banco de dados, quando existir.
	
	printf("\n=== NOVO CADASTRO REALIZADO ===\n");
	
	printf("Codigo do Cliente: %d", cod_cliente);	
	printf("\nNome: %s", nome);
	printf("\nRG: %s", rg);
	printf("\nCPF: %s", cpf);
	printf("\nEndereco: %s", endereco);
	printf("\nData de Nascimento: %d", data_nasc);
	printf("\nCarteira de Habilitacao: %d", cnh);
}
void cadastrar_automovel()
{
	int cod_auto;
	char *marca;
	char *modelo;
	int ano;
	int cod_class;
	
	printf("\n=== CADASTRAMENTO DE NOVO AUTOMOVEL ===\n");
	
	printf("\nDigite o Codigo do Automovel: ");
	scanf("%d", &cod_auto);
	marca = readline("Marca: ");
	modelo = readline("Modelo:");
	printf("Ano/Modelo de Fabricacao: ");
	scanf("%d", &ano);
	printf("Codigo de Classificacao: ");
	scanf("%d", &cod_class);
	
	printf("Cadastrando Automovel...\n");
}
void cadastrar_classificacao_automovel()
{
	int cod_class;
	char *descricao_classificacao;
	float valor_locacao;
	
	printf("\n=== CADASTRAMENTO DE CLASSIFICACAO DE AUTOMOVEL ===\n");
	
	printf("\nDigite o Codigo da Classificacao: ");
	scanf("%d", &cod_class);
	descricao_classificacao = readline("Descricao da Classificacao: ");
	printf("Digite o Valor para Locacao: R$ ");
	scanf("%f", &valor_locacao);
	printf("\nCadastrando Classificacao de Automovel...\n");
}

void totalPagar ()
{
	float totalPagar, basico, inter, exec;
	int numDias, resp, cod_locacao, cod_cliente;
	char *nome;
	
	printf("\nDigite o Codigo da Locacao: ");
	scanf("%d", &cod_locacao);
	nome = readline("Nome do Cliente: ");
		
	printf("\n[1] Basico");
	printf("\n[2] Intermediario");
	printf("\n[3] Executivo\n");
	
	printf("\nDigite o valor correspondente a classificacao do veiculo: ");
	scanf("%d", &resp);
	printf("\nDigite o tempo de locacao do automovel (Dias): ");
	scanf("%d", &numDias);
	
	basico = 80;
	inter = 150;
	exec = 300;
	
	switch(resp) 
	{
		case 1:
		   totalPagar = numDias * basico;
		  	break;
		case 2:
			totalPagar = numDias * inter;
			break;
		case 3:
			totalPagar = numDias * exec;
			break;
		default:
			printf("Opcao Invalida! Tente Novamente!");
	
	}
	printf("\nTotal a pagar: R$ %.02f\n", totalPagar);

	
	  return;
}	



void menu_opcoes()
{
	printf("\n=== SISTEMA DE LOCACAO DE AUTOMOVEIS ===\n\n");
	printf("MENU:\n");
	printf("[1] Cadastrar Cliente\n");
	printf("[2] Cadastrar Automovel\n");
	printf("[3] Cadastrar Classificacao de Automovel\n");
	printf("[4] Movimentacao de Locacao\n");
}

int le_opcao()
{
	int opcao;
	printf("\nDigite a opcao correspondente: ");
	scanf("%d", &opcao);
	return opcao;
}


void executa_acao(int opcao)
{
	printf("Voce escolheu a opcao: %d\n", opcao);

	switch(opcao)
	{
		case 1:
			cadastrar_cliente();
			break;
		case 2:
			cadastrar_automovel();
			break;
		case 3:
			cadastrar_classificacao_automovel();
			break;
		case 4:
			totalPagar();
			break;
		default:
			printf("Opcao Invalida!\n");
 } 		
printf("\n\nOperacao Realizada com Sucesso!\n");
}
void main()
{
   int opcao;
	menu_opcoes();
	opcao = le_opcao();
	

	
	
		while (opcao != 0)
		{
			executa_acao(opcao);
			menu_opcoes();
			opcao = le_opcao();

	   }
}	



