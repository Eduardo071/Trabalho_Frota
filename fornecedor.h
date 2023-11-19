#include <stdio.h>
#include <string.h>

struct Fornecedor {
  char razao_social[50];
  char fantasia[100];
  char cnpj[15];
  char inc_estadual[50];
  char inc_municipal[50];
  char cep[8];
  char endereco[100];
  char numero[6];
  char complemento[50];
  char bairro[50];
  char cidade[50];
  char uf[3];
  char telefone[15];
  char email[100];
  char data_fund[8];
  char site[30];
};

void adicionarFornecedor() {
  struct Fornecedor novoFornecedor;

  printf("<<< Cadastro de Fornecedor >>>\n");
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  printf("Razão Social: ");
  fgets(novoFornecedor.razao_social, sizeof(novoFornecedor.razao_social),
        stdin);

  printf("Fantasia: ");
  fgets(novoFornecedor.fantasia, sizeof(novoFornecedor.fantasia), stdin);

  printf("CNPJ: ");
  fgets(novoFornecedor.cnpj, sizeof(novoFornecedor.cnpj), stdin);

  printf("Inscrição Estadual: ");
  fgets(novoFornecedor.inc_estadual, sizeof(novoFornecedor.inc_estadual),
        stdin);

  printf("CEP: ");
  fgets(novoFornecedor.cep, sizeof(novoFornecedor.cep), stdin);

  printf("Endereço: ");
  fgets(novoFornecedor.endereco, sizeof(novoFornecedor.endereco), stdin);

  printf("Número: ");
  fgets(novoFornecedor.numero, sizeof(novoFornecedor.numero), stdin);

  printf("Complemento: ");
  fgets(novoFornecedor.complemento, sizeof(novoFornecedor.complemento), stdin);

  printf("Bairro: ");
  fgets(novoFornecedor.bairro, sizeof(novoFornecedor.bairro), stdin);

  printf("Cidade: ");
  fgets(novoFornecedor.cidade, sizeof(novoFornecedor.cidade), stdin);

  printf("UF: ");
  fgets(novoFornecedor.uf, sizeof(novoFornecedor.uf), stdin);
  
  printf("Telefone: ");
  fgets(novoFornecedor.telefone, sizeof(novoFornecedor.telefone), stdin);

  printf("E-mail: ");
  fgets(novoFornecedor.email, sizeof(novoFornecedor.email), stdin);

  printf("Data de Fundação: ");
  fgets(novoFornecedor.data_fund, sizeof(novoFornecedor.data_fund), stdin);

  printf("Site: ");
  fgets(novoFornecedor.site, sizeof(novoFornecedor.site), stdin);

  printf("Fornecedor adicionado com sucesso!\n");
}