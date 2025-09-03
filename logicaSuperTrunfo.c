#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings

// Estrutura para representar uma carta do Super Trunfo
typedef struct { // Estrutura logica das cartas
    char estado[50];
    char codigo[20];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta; 

// Função para calcular atributos derivados: Densidade Populacional e PIB per capita
void calcularAtributos(Carta *c) { //operacao de calculo dos atributos
    if (c->area != 0) { //quando for true
        c->densidadePopulacional = c->populacao / c->area;
    } else { //quando for false
        c->densidadePopulacional = 0;
    }

    if (c->populacao != 0) { //quando for true
        c->pibPerCapita = c->pib / c->populacao;
    } else { //quando for false
        c->pibPerCapita = 0;
    }
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) { //comandos para adicionar informacoes
    printf("\n--- Cadastro de Carta ---\n"); //exibe dados da carta 
    printf("Estado: "); //exibe dados do estado
    fgets(carta->estado, sizeof(carta->estado), stdin); //comandos das informacoes inseridas
    carta->estado[strcspn(carta->estado, "\n")] = '\0';  // Remove newline

    printf("Código da carta: "); //exibe dados inseridos
    fgets(carta->codigo, sizeof(carta->codigo), stdin); //comandos das informacoes inseridas
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0'; // Remove newline

    printf("Nome da cidade: "); //exibe dados inseridos
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin); //comandos das informacoes inseridas
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remove newline

    printf("População: "); //exibe dados inseridos
    scanf("%d", &carta->populacao);  //comandos das informacoes inseridas    

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em reais): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    getchar(); // reseta o as entradas inseridas

    calcularAtributos(carta); // Calcula os atributos derivados
}

// Função para imprimir os dados principais de uma carta
void exibirCarta(Carta c) { //comandos para exibir as informacoes
    printf("%s (%s):\n", c.nomeCidade, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("-----------------------------\n");
}

int main() { //funcao principal
    Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    // Exibição das cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);

    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Comparação de atributo fixo: População
    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) { //comparacao dos atributos
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) { //comparacao dos atributos
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0; //finaliza o programa
}
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.


    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

