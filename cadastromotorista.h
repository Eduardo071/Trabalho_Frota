// testa se o sistema � Windows, pois o "cls" funciona somente no Windows,
// sen�o utiliza o "clear" que � o comando para limpar a tela no Linux
#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif


// inclus�o de bibliotecas
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#include "funcoes.h"


// defini��o da struct empresa
typedef struct empresa
{
	// campos da struct empresa
	int iCodigo;
	char sTipo_Pessoa[1]; // F-F�sica / J-Jur�dica
    char sRazao_Social[100];
    char sFantasia[100];
    char sCNPJ_CPF[14];
    char sInscEst_RG[30];
    char sInsc_Mun[20];
    char sEndereco[100];
    char sNumero[5];
    char sComplemento[20];
    char sBairro[30];
    char sCidade[30];
    char sUF[2];
    char sCEP[8];
    char sFone1[12];
    char sFone2[12];
    char sFone3[12];
    char sNome_Contato[30];
    char sRegime_Tributario[50];
    char sEmail[100];
    char sSite[50];
    char sAtivo[1]; // S - Sim / N - N�o
} st_empresa;


typedef struct motorista {

    int iCodigo;
    char sNome[50];
    char sIdade;
    char sCategoria_Cnh[20];
    char sEndereco[50];
    char sNumero_Residencia;
    char sCidade[50];
    char sEmail[50];
    char sObservacao[100];
    char sVencimento[20];
    char sData_Cadastro[20];
    char sTelefone;
}st_motorista;

// prot�tipos de fun��es

/**
 * Exibe o menu com todas as op��es do programa
 * retorno: um caractere do n�mero correspondente a op��o
 */
char menu();

/**
 * Cadastra uma Empresa
 */
void cadastrar_empresa();

void cadastrar_motorista();

/**
 * Exibe todas as empresas cadastradas
 */
void listar_empresa();

void listar_motorista();


//==========================================================================

int main(void)
{
    //setlocale(LC_ALL,"pt_BR.utf8");
    setlocale(LC_ALL,"portuguese");

	//char resp;
	int resp;

	// loop infinito do programa
	while(1)
	{
		// obt�m a escolha do usu�rio
		resp = menu();

		// testa o valor de "resp"
	if (resp == 1) {
    system(limpar_tela);
    cadastrar_empresa();
} else if (resp == 2) {
    msg_em_desenvolvimento();
    // cadastrar_cliente();
} else if (resp == 3) {
    msg_em_desenvolvimento();
    // listar_filmes();
} else if (resp == 4) {
    system(limpar_tela);
    cadastrar_motorista();
} else if (resp == 5) {
    msg_em_desenvolvimento();
    // pesquisar_filme();
} else if (resp == 6) {
    msg_em_desenvolvimento();
    // pesquisar_cliente();
} else if (resp == 7) {
    msg_em_desenvolvimento();
    // alugar_filme();
} else if (resp == 8) {
    system(limpar_tela);
    listar_empresa();
} else if (resp == 9) {
    msg_em_desenvolvimento();
    // excluir_filme();
} else if (resp == 10) {
    msg_em_desenvolvimento();
} else if (resp == 11) {
    system(limpar_tela);
    listar_motorista();
} else if (resp == 12) {
    msg_em_desenvolvimento();
} else if (resp == 13) {
    msg_em_desenvolvimento();
} else if (resp == 14) {
    msg_em_desenvolvimento();
} else if (resp == 0) {
    // se for igual a 0, ent�o sai do loop while
    break;
} else {
    printf("\nOpcao invalida! Pressione <Enter> para continuar...");
    scanf("%d", &resp);
    // uma forma de "limpar" o buffer de entrada
    fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
}
system(limpar_tela);

	}
	printf("\n******************************************\n");
	printf("D�vidas, procure o setor de TI, ramal 123.");
	printf("\n******************************************\n");
	return 0;
}

// fun��o que exibe o menu e retorna a op��o escolhida pelo usu�rio
char menu()
{
	//char resp[2];
	int resp;

	printf("\n--[ KNOWLEDGE System Solutions  ]-------------------------------------------");
	printf("\n--[ Sistema de Gest�o de Frotas - Distribuidora XPTO Ltda ]-----------------");
	printf("\n\n 1 - Cadastrar Empresas\n");
	printf(" 2 - Cadastrar Clientes\n");
	printf(" 3 - Cadastrar Fornecedores\n");
	printf(" 4 - Cadastrar Motoristas\n");
	printf(" 5 - Cadastrar Produtos\n");
	printf(" 6 - Cadastrar Lan�amentos a Pagar\n");
	printf(" 7 - Cadastrar Lan�amentos a Receber\n");
	printf(" 8 - Listar todas as Empresas\n");
	printf(" 9 - Listar todos os Clientes\n");
	printf("10 - Listar todos os Fornecedores\n");
	printf("11 - Listar todos os Motoristas\n");
	printf("12 - Listar todos os Produtos\n");
	printf("13 - Listar todos os Lan�amentos a Pagar\n");
	printf("14 - Listar todos os Lan�amentos a Receber\n");
	printf(" 0 - Sair\n");
	printf("\nDigite o numero da opcao: ");
	scanf("%d", &resp); // o *c pega o Enter e descarta
    //scanf("%1s%*c", resp); // o *c pega o Enter e descarta

	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso

	// se chegou aqui, � porque a op��o � v�lida
	return resp;
}

//---------------------------------------------------------
void cadastrar_empresa(){

	// abre o arquivo para escrita
	// a+b => acrescenta dados ao final do arquivo ou cria
	// um arquivo bin�ria para leitura e escrita
	FILE *arq_empresa = fopen("empresa.bin", "a+b");

	// testa a abertura do arquivo
	if(arq_empresa == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}

	/*
		N�O � interessante que o usu�rio digite o C�digo da empresa, esse
		C�digo tem que ser gerado autom�tico, ent�o temos que pegar o
		C�digo da �ltima empresa cadastrada
	*/
	int cont_bytes = 0;

	// cont_bytes ir� guardar o n�mero total de bytes
	// seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_empresa, 0, SEEK_END);

	// pegamos a quantidade de bytes com a fun��o ftell
	cont_bytes = ftell(arq_empresa);

    st_empresa empresa;

	if(cont_bytes == 0)
	{
		// se for 0, ent�o n�o existe empresa cadastrada
		// coloca o C�digo come�ando de 1
		empresa.iCodigo = 1;
	}
	else
	{
		st_empresa ultima_empresa;

		// utiliza a fun��o fseek para posicionar o arquivo
		// cont_bytes - sizeof(st_empresa) serve para posicionar
		// para que possamos pegar o c�digo da �ltima empresa cadastrada
		fseek(arq_empresa, cont_bytes - sizeof(st_empresa), SEEK_SET);

		// ler os dados da empresa
		fread(&ultima_empresa, sizeof(st_empresa), 1, arq_empresa);

		// o C�digo da empresa � o c�digo da �ltima empresa acrescido em 1
		empresa.iCodigo = ultima_empresa.iCodigo + 1;
	}


	// obt�m o nome da empresa
	// ^\n indica para pegar at� a quebra de linha (enter)
	// %*c descarta o enter
	printf("\nTipo de pessoa (F / J): ");
	scanf("%1[^\n]%*c", empresa.sTipo_Pessoa);

	printf("Raz�o Social............: ");
	scanf("%99[^\n]%*c", empresa.sRazao_Social);

	printf("Fantasia................: ");
	scanf("%99[^\n]%*c", empresa.sFantasia);

	printf("CNPJ / CPF..............: ");
	scanf("%99[^\n]%*c", empresa.sCNPJ_CPF);

	printf("Insc.Est. / RG..........: ");
	scanf("%99[^\n]%*c", empresa.sInscEst_RG);

	printf("Insc.Municipal..........: ");
	scanf("%99[^\n]%*c", empresa.sInsc_Mun);

	printf("Endere�o................: ");
	scanf("%99[^\n]%*c", empresa.sEndereco);

	printf("N�mero..................: ");
	scanf("%99[^\n]%*c", empresa.sNumero);

	printf("Complemento.............: ");
	scanf("%99[^\n]%*c", empresa.sComplemento);

	printf("Bairro..................: ");
	scanf("%99[^\n]%*c", empresa.sBairro);

	printf("Cidade..................: ");
	scanf("%99[^\n]%*c", empresa.sCidade);

	printf("UF......................: ");
	scanf("%99[^\n]%*c", empresa.sUF);

	printf("CEP.....................: ");
	scanf("%99[^\n]%*c", empresa.sCEP);

	printf("Fone 1..................: ");
	scanf("%99[^\n]%*c", empresa.sFone1);

	printf("Fone 2..................: ");
	scanf("%99[^\n]%*c", empresa.sFone2);

	printf("Fone 3..................: ");
	scanf("%99[^\n]%*c", empresa.sFone3);

	printf("Nome da pessoa contato..: ");
	scanf("%99[^\n]%*c", empresa.sNome_Contato);

	printf("Regime tribut�rio.......: ");
	scanf("%99[^\n]%*c", empresa.sRegime_Tributario);

	printf("e-mail..................: ");
	scanf("%99[^\n]%*c", empresa.sEmail);

	printf("Site....................: ");
	scanf("%99[^\n]%*c", empresa.sSite);

	printf("Ativo (S / N)...........: ");
	scanf("%99[^\n]%*c", empresa.sAtivo);

	fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso

	// se o ponteiro n�o estiver no final do arquivo nada � escrito
	fseek(arq_empresa, 0, SEEK_END);
	// escreve no arquivo
	fwrite(&empresa, sizeof(st_empresa), 1, arq_empresa);

	// fecha o arquivo
	fclose(arq_empresa);

	printf("\nEmpresa \"%s\" cadastrado com sucesso!\n", empresa.sFantasia
        );
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c"); // pega o Enter e descarta

	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso

}

//---------------------------------------------------------
// fun��o para listar todas as empresas
void listar_empresa(){

    // rb => abre arquivo bin�rio para leitura apenas
	FILE *arq_empresa = fopen("empresa.bin", "rb");

	// testa a abertura do arquivo
	if(arq_empresa == NULL)
	{
		printf("\nFalha ao abrir arquivo(s) ou ");
		printf("Nenhuma empresa cadastrada.\n");
		printf("\nPressione <Enter> para continuar...");
		scanf("%*c"); // pega o Enter e descarta

		// uma forma de "limpar" o buffer de entrada
		fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso
		return;
	}

	// vari�vel que indica se encontrou pelo menos 1 empresa
	int encontrou_empresa = 0;
	st_empresa empresa;

	printf("\nListando todas as empresa(s)...\n");
	// loop para percorrer o arquivo
	while(1)
	{
		// fread retorna o n�mero de elementos lidos com sucesso
		size_t result = fread(&empresa, sizeof(st_empresa), 1, arq_empresa);

		// se for 0, � porque n�o h� mais elemento, ent�o sai do loop
		if(result == 0)
			break;

		// atualiza a vari�vel indicando que encontrou
		// pelo menos um cliente
		encontrou_empresa = 1;

		// mostra os dados da empresa
		printf("\nC�digo: %d\n", empresa.iCodigo);
		printf("Tipo pessoa: %c\n", empresa.sTipo_Pessoa[0]);
		printf("Raz�o Social: %s\n", empresa.sRazao_Social);
		printf("Fantasia: %s\n", empresa.sFantasia);
		printf("CNPJ / CPF: %s\n", empresa.sCNPJ_CPF);


/*
    char sInscEst_RG[30];
    char sInsc_Mun[20];
    char sEndereco[100];
    char sNumero[5];
    char sComplemento[20];
    char sBairro[30];
    char sCidade[30];
    char sUF[2];
    char sCEP[8];
    char sFone1[12];
    char sFone2[12];
    char sFone3[12];
    char sNome_Contato[30];
    char sRegime_Tributario[50];
    char sEmail[100];
    char sSite[50];
    char sAtivo[1]; // S - Sim / N - N�o
*/

	}


	if(encontrou_empresa == 0)
		printf("\nNenhuma empresa cadastrada.\n");

	fclose(arq_empresa);

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // n�o recomend�vel o uso

}



/*Fun��o para cadastrar os motoristas*/


void cadastrar_motorista() {
    FILE *arq_motorista = fopen("motorista.bin", "a+b");

    if (arq_motorista == NULL) {
        printf("\nFalha ao abrir arquivo(s)!\n");
        exit(1);
    }

    int cont_bytes = 0;
    fseek(arq_motorista, 0, SEEK_END);
    cont_bytes = ftell(arq_motorista);

    st_motorista motorista;

    if (cont_bytes == 0) {
        motorista.iCodigo = 1;
    } else {
        st_motorista ultima_motorista;
        fseek(arq_motorista, cont_bytes - sizeof(st_motorista), SEEK_SET);
        fread(&ultima_motorista, sizeof(st_motorista), 1, arq_motorista);
        motorista.iCodigo = ultima_motorista.iCodigo + 1;
    }

    printf("\nNome do Motorista.......: ");
    scanf(" %49[^\n]%*c", motorista.sNome);

    printf("Idade do motorista......: ");
    scanf("%d", &motorista.sIdade);

    printf("Categoria da CNH........: ");
    scanf(" %19[^\n]%*c", motorista.sCategoria_Cnh);

    printf("Endere�o................: ");
    scanf(" %49[^\n]%*c", motorista.sEndereco);

    printf("Numero da Resid�ncia....: ");
    scanf("%d", &motorista.sNumero_Residencia);

    printf("Cidade..................: ");
    scanf(" %49[^\n]%*c", motorista.sCidade);

    printf("Email...................: ");
    scanf(" %49[^\n]%*c", motorista.sEmail);

    printf("Observa��o..............: ");
    scanf(" %99[^\n]%*c", motorista.sObservacao);

    printf("Venc.Toxicologico.......: ");
    scanf(" %19[^\n]%*c", motorista.sVencimento);

    printf("Data do Cadastro........: ");
    scanf(" %19[^\n]%*c", motorista.sData_Cadastro);

    printf("Telefone................: ");
    scanf("%d", &motorista.sTelefone);

    fseek(stdin, 0, SEEK_END);
    fseek(arq_motorista, 0, SEEK_END);
    fwrite(&motorista, sizeof(st_motorista), 1, arq_motorista);

    fclose(arq_motorista);

    printf("\nMotorista \"%s\" cadastrado com sucesso!\n", motorista.sNome);
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
}

/*Fun��o para listar os motoristas*/

void listar_motorista() {
    FILE *arq_motorista = fopen("motorista.bin", "rb");

    if (arq_motorista == NULL) {
        printf("\nFalha ao abrir arquivo(s) ou ");
        printf("Nenhum Motorista cadastrado.\n");
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");
        fseek(stdin, 0, SEEK_END);
        return;
    }

    int encontrou_motorista = 0;
    st_motorista motorista;

    printf("\nListando todos os Motoristas(s)...\n");

    while (fread(&motorista, sizeof(st_motorista), 1, arq_motorista) != 0) {
        encontrou_motorista = 1;

        printf("\nC�digo do Motorista: %d\n", motorista.iCodigo);
        printf("Nome do Motorista: %s\n", motorista.sNome);
        printf("Categoria da CNH: %s\n", motorista.sCategoria_Cnh);
        printf("Venc.Toxicologico: %s\n", motorista.sVencimento);
        printf("Telefone: %d\n", motorista.sTelefone);
        printf("Observa��es: %s\n", motorista.sObservacao);
    }

    if (encontrou_motorista == 0)
        printf("\nNenhum Motorista Cadastrado.\n");

    fclose(arq_motorista);

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
}
