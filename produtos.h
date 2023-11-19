#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
  // campos da struct produto
  int icodigo;
  char codigo[20];
  char item[100];
  char codigoDeBarras[20];
  char codigoFabricante[20];
  char unidade[20];
  char marca[20];
  char cor[20];
  char localizacao[20];
  char descricao[100];
  float pesoLiquido;
  float pesoBruto;

} st_produto;

// prototipos de funções

/**
 * Exibe o menu com todas as opções do programa
 * retorno: um caractere do número correspondente a opção
 */
char menu();

/**
 * Cadastra uma produto
 */

void cadastrar_produto() {

  // abre o arquivo para escrita
  // a+b => acrescenta dados ao final do arquivo ou cria
  // um arquivo binário para leitura e escrita
  FILE *arq_produto = fopen("produto.bin", "a+b");

  // testa a abertura do arquivo
  if (arq_produto == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1); // aborta o programa
  }

  /*
    não é interessante que o usuário digite o código da produto, esse
    código tem que ser gerado automático, então temos que pegar o
    código da última produto cadastrada
  */
  int cont_bytes = 0;

  // cont_bytes irá guardar o número total de bytes
  // seta o ponteiro do arquivo para o final do arquivo
  fseek(arq_produto, 0, SEEK_END);

  // pegamos a quantidade de bytes com a função ftell
  cont_bytes = ftell(arq_produto);

  st_produto produto;

  if (cont_bytes == 0) {
    // se for 0, então não existe produto cadastrada
    // coloca o código começando de 1
    produto.icodigo = 1;
  } else {
    st_produto ultima_produto;

    // utiliza a função fseek para posicionar o arquivo
    // cont_bytes - sizeof(st_produto) serve para posicionar
    // para que possamos pegar o código da última produto cadastrada
    fseek(arq_produto, cont_bytes - sizeof(st_produto), SEEK_SET);

    // ler os dados da produto
    fread(&ultima_produto, sizeof(st_produto), 1, arq_produto);

    // o código do produto têm o código do último produto acrescido em 1
    produto.icodigo = ultima_produto.icodigo + 1;
  }

  // obtém o nome da produto
  // ^\n indica para pegar até a quebra de linha (enter)
  // %*c descarta o enter
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  printf("\nCódigo: ");
  scanf("%99[^\n]%*c", produto.codigo);

  printf("Nome do Produto: ");
  scanf("%99[^\n]%*c", produto.item);

  printf("Código de Barras: ");
  scanf("%99[^\n]%*c", produto.codigoDeBarras);

  printf("Código de Fabricante: ");
  scanf("%99[^\n]%*c", produto.codigoFabricante);

  printf("unidade: ");
  scanf("%99[^\n]%*c", produto.unidade);

  printf("marca: ");
  scanf("%99[^\n]%*c", produto.marca);

  printf("Cor: ");
  scanf("%99[^\n]%*c", produto.cor);

  printf("localizacão: ");
  scanf("%99[^\n]%*c", produto.localizacao);

  printf("Descrição do Produto: ");
  scanf("%99[^\n]%*c", produto.descricao);

  printf("Peso líquido: ");
  scanf("%f", &produto.pesoLiquido);

  printf("Peso bruto: ");
  scanf("%f", &produto.pesoBruto);
  
  // se o ponteiro não estiver no final do arquivo nada ? escrito
  fseek(arq_produto, 0, SEEK_END);
  // escreve no arquivo
  fwrite(&produto, sizeof(st_produto), 1, arq_produto);

  // fecha o arquivo
  fclose(arq_produto);

  printf("\nproduto \"%s\" cadastrado com sucesso!\n", produto.item);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c"); // pega o Enter e descarta
}

void listar_produtos() {
  FILE *arq_produto = fopen("produto.bin", "rb");

  if (arq_produto == NULL) {
    printf("\nFalha ao abrir o arquivo de produtos!\n");
    return;
  }

  st_produto produto;

  printf("\nLista de Produtos Cadastrados:\n\n");

  while (fread(&produto, sizeof(st_produto), 1, arq_produto) == 1) {
    printf("Indentidador: %d\n", produto.icodigo);
    printf("Codigo: %s\n", produto.codigo);
    printf("Nome do Produto: %s\n", produto.item);
    printf("Código de Barras: %s\n", produto.codigoDeBarras);
    printf("Código Fabricante: %s\n", produto.codigoFabricante);
    printf("Unidade: %s\n", produto.unidade);
    printf("Marca: %s\n", produto.marca);
    printf("Cor: %s\n", produto.cor);
    printf("localizacão: %s\n", produto.localizacao);
    printf("Peso Bruto: %.2f\n", produto.pesoBruto);
    printf("Peso Líquido: %.2f\n", produto.pesoLiquido);
    printf("Descrição: %s\n", produto.descricao);

    printf("-------------------------------------------------------------------"
           "----------------------------------------------------\n");
  }

  fclose(arq_produto);

  printf("Pressione Enter para continuar...");
  getchar(); // Aguarda o pressionamento da tecla Enter
}
