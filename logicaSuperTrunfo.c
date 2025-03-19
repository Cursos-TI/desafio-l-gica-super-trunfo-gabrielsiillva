#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as propriedades de uma cidade
typedef struct {
    char nome[50];
    char estado[50];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *c) {
    printf("\nDigite o nome da cidade: ");
    scanf(" %[^\n]", c->nome);
    printf("Digite o estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Digite o código da cidade: ");
    scanf("%s", c->codigo);
    printf("Digite a população: ");
    scanf("%d", &c->populacao);
    printf("Digite a área em km²: ");
    scanf("%f", &c->area);
    printf("Digite o PIB da cidade em bilhões: ");
    scanf("%f", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade c) {
    printf("\n🔹 Cidade: %s (%s)\n", c.nome, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função para comparar as cidades
void compararCidades(Cidade c1, Cidade c2, int criterio) {
    printf("\n🔹 Comparação das cidades com base no critério escolhido:\n");
    
    if (criterio == 1) { // População
        if (c1.populacao > c2.populacao)
            printf("🏆 %s tem a maior população!\n", c1.nome);
        else
            printf("🏆 %s tem a maior população!\n", c2.nome);
    }
    else if (criterio == 2) { // Área
        if (c1.area > c2.area)
            printf("🏆 %s tem a maior área!\n", c1.nome);
        else
            printf("🏆 %s tem a maior área!\n", c2.nome);
    }
    else if (criterio == 3) { // PIB
        if (c1.pib > c2.pib)
            printf("🏆 %s tem o maior PIB!\n", c1.nome);
        else
            printf("🏆 %s tem o maior PIB!\n", c2.nome);
    }
    else if (criterio == 4) { // Densidade Populacional (menor vence)
        float densidade1 = c1.populacao / c1.area;
        float densidade2 = c2.populacao / c2.area;

        if (densidade1 < densidade2)
            printf("🏆 %s tem a menor densidade populacional!\n", c1.nome);
        else
            printf("🏆 %s tem a menor densidade populacional!\n", c2.nome);
    }
    else {
        printf("❌ Critério inválido!\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int criterio;

    printf("🚀 Super Trunfo - Comparação de Cidades 🚀\n");

    // Cadastro das cidades
    printf("\n🔹 Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\n🔹 Cadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    // Exibição das cidades cadastradas
    printf("\n📌 Cidades cadastradas:");
    exibirCidade(cidade1);
    exibirCidade(cidade2);

    // Escolha do critério de comparação
    printf("\nEscolha um critério de comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("Digite sua escolha (1-4): ");
    scanf("%d", &criterio);

    // Comparação e exibição do resultado
    compararCidades(cidade1, cidade2, criterio);

    return 0;
}