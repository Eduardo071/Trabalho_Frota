#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContaReceber {
  char nomeEmpresa[50];
  char dataLancamento[11];
  int numeroDocumento;
  char dataDocumento[11];
  int quantidadeParcelas;
  float valorParcela;
  char dataVencimento[11];
  char tipoDocumento[50];
  char centroCusto[50];
  char complementoDocumento[41];
  char historico[301];
};

void cadastrarConta(struct ContaReceber contas[], int *numContas);
void listarContas(struct ContaReceber contas[], int numContas);

int contasReceber() {
  struct ContaReceber contas[100];
  int opcao, numContas = 0;

  do {
    printf("\n1 - Cadastrar contas a receber\n");
    printf("2 - Listar contas a receber\n");
    printf("3 - Sair\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      cadastrarConta(contas, &numContas);
      break;
    case 2:
      listarContas(contas, numContas);
      break;
    case 3:
      printf("Programa encerrado.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (opcao != 3);

  return 0;
}

int validarDataGrupoAriane(char data[]) {
  int dia, mes, ano;
  if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3) {
    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1900 &&
        ano <= 2100) {
      return 1;
    }
  }
  return 0;
}

void cadastrarConta(struct ContaReceber contas[], int *numContas) {
  struct ContaReceber novaConta;

  printf("Nome da Empresa: ");
  getchar();
  fgets(novaConta.nomeEmpresa, sizeof(novaConta.nomeEmpresa), stdin);
  novaConta.nomeEmpresa[strcspn(novaConta.nomeEmpresa, "\n")] = '\0';

  printf("Data do Lançamento (dd/mm/aaaa): ");
  fgets(novaConta.dataLancamento, sizeof(novaConta.dataLancamento), stdin);
  novaConta.dataLancamento[strcspn(novaConta.dataLancamento, "\n")] = '\0';
  if (!validarDataGrupoAriane(novaConta.dataLancamento)) {
    printf("Data incorreta! Utilize o formato dd/mm/aaaa e certifique-se de "
           "que a data é válida.\n");
    return;
  }

  printf("Número do Documento: ");
  scanf("%d", &novaConta.numeroDocumento);

  printf("Data do Documento (dd/mm/aaaa): ");
  scanf("%s", novaConta.dataDocumento);
  if (!validarDataGrupoAriane(novaConta.dataDocumento)) {
    printf("Data incorreta! Utilize o formato dd/mm/aaaa e certifique-se de "
           "que a data é válida.\n");
    return;
  }

  printf("Quantidade de Parcelas: ");
  scanf("%d", &novaConta.quantidadeParcelas);

  printf("Valor da Parcela: ");
  scanf("%f", &novaConta.valorParcela);

  printf("Data de Vencimento (dd/mm/aaaa): ");
  scanf("%s", novaConta.dataVencimento);
  if (!validarDataGrupoAriane(novaConta.dataVencimento)) {
    printf("Data incorreta! Utilize o formato dd/mm/aaaa e certifique-se de "
           "que a data é válida.\n");
    return;
  }

  printf("Tipo de Documento: ");
  getchar();
  fgets(novaConta.tipoDocumento, sizeof(novaConta.tipoDocumento), stdin);
  novaConta.tipoDocumento[strcspn(novaConta.tipoDocumento, "\n")] = '\0';

  printf("Centro de Custo: ");
  fgets(novaConta.centroCusto, sizeof(novaConta.centroCusto), stdin);
  novaConta.centroCusto[strcspn(novaConta.centroCusto, "\n")] = '\0';

  printf("Complemento do Documento (máximo 40 caracteres): ");
  fgets(novaConta.complementoDocumento, sizeof(novaConta.complementoDocumento),
        stdin);
  novaConta
      .complementoDocumento[strcspn(novaConta.complementoDocumento, "\n")] =
      '\0';

  printf("Histórico (máximo 300 caracteres): ");
  fgets(novaConta.historico, sizeof(novaConta.historico), stdin);
  novaConta.historico[strcspn(novaConta.historico, "\n")] = '\0';

  contas[*numContas] = novaConta;
  (*numContas)++;
  printf("Conta cadastrada com sucesso!\n");
}

void listarContas(struct ContaReceber contas[], int numContas) {
  if (numContas == 0) {
    printf("Nenhuma conta cadastrada.\n");
    return;
  }

  printf("\nListagem de Contas a Receber:\n");
  for (int i = 0; i < numContas; i++) {
    printf("Nome da Empresa: %s\n", contas[i].nomeEmpresa);
    printf("Data do Lancamento: %s\n", contas[i].dataLancamento);
    printf("Numero do Documento: %d\n", contas[i].numeroDocumento);
    printf("Data do Documento: %s\n", contas[i].dataDocumento);
    printf("Quantidade de Parcelas: %d\n", contas[i].quantidadeParcelas);
    printf("Valor da Parcela: %.2f\n", contas[i].valorParcela);
    printf("Data de Vencimento: %s\n", contas[i].dataVencimento);
    printf("Tipo de Documento: %s\n", contas[i].tipoDocumento);
    printf("Centro de Custo: %s\n", contas[i].centroCusto);
    printf("Complemento do Documento: %s\n", contas[i].complementoDocumento);
    printf("Historico: %s\n", contas[i].historico);

    if (i < numContas - 1) {
      printf("\n");
    }
  }
}