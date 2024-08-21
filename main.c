#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING 50
#define MAX_RESTAURANTES 23

typedef struct {
    int x;
    int y;
    char nome[MAX_STRING];
    char custo[MAX_STRING];
    int velocidade;
    float tempogasto;
} Restaurante;

typedef struct {
    int x;
    int y;         
    int pavimentado;
} Rua;

float contarRuasPavimentadas(int origemX, int origemY, int destinoX, int destinoY, int coordenadaspavimento[40][24]) {
    // Implementação do algoritmo de busca em largura (BFS)
    int fila[40 * 24][2]; // Fila para armazenar as coordenadas (x, y)
    int visitado[40][24]; // Matriz para rastrear se uma posição foi visitada
    int dx[] = {1, -1, 0, 0}; // Movimentos possíveis nas direções x e y
    int dy[] = {0, 0, 1, -1};
    float distancia[40][24]; // Matriz para armazenar a distância acumulada até cada posição

    memset(visitado, 0, sizeof(visitado));
    memset(distancia, 0, sizeof(distancia));

    fila[0][0] = origemX;
    fila[0][1] = origemY;
    visitado[origemX][origemY] = 1;

    int frente = 0, traseira = 1;

    while (frente < traseira) {
        int atualX = fila[frente][0];
        int atualY = fila[frente][1];
        frente++;

        if (atualX == destinoX && atualY == destinoY) {
            // Chegamos ao destino, paramos a busca
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = atualX + dx[i];
            int newY = atualY + dy[i];

            // Verifica se a nova posição está dentro dos limites e se é pavimentada
            if (newX >= 1 && newX <= 39 && newY >= 1 && newY <= 23 && coordenadaspavimento[newX][newY] == 1 && !visitado[newX][newY]) {
                fila[traseira][0] = newX;
                fila[traseira][1] = newY;
                traseira++;
                visitado[newX][newY] = 1;
                distancia[newX][newY] = distancia[atualX][atualY] + 1; // Incrementa a distância ao percorrer uma rua pavimentada
            }
        }
    }

    return distancia[destinoX][destinoY];
}

void CompararRestaurantes(Restaurante arr[], int n) {
    int i, j, minIndex;
    Restaurante temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].tempogasto > arr[minIndex].tempogasto) {
                minIndex = j;
            }
        }
        // Troca os restaurantes
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    Rua cidade; 
    Restaurante restaurantes[MAX_RESTAURANTES];
    int coordenadaspavimento[40][24];// Índices de 1 a 39 e 1 a 23

    // Leitura das ruas pavimentadas
    FILE *ruasFile = fopen("ruas.txt", "r+t");
    if (ruasFile == NULL) {
        printf("Erro ao abrir o arquivo de ruas.\n");
        return 1;
    }

    for (int i = 1; i <= 39; i++) {
        for (int j = 1; j <= 23; j++) {
            fscanf(ruasFile, "%d %d %d", &cidade.x, &cidade.y, &cidade.pavimentado);
            if (cidade.pavimentado == 1) {
                coordenadaspavimento[cidade.x][cidade.y] = 1;
            } else {
                coordenadaspavimento[cidade.x][cidade.y] = 0;
            }
        }
    }

    fclose(ruasFile);

    // Leitura dos restaurantes
    FILE *restaurantesFile = fopen("restaurantes.txt", "r+t");
    if (restaurantesFile == NULL) {
        printf("Erro ao abrir o arquivo de restaurantes.\n");
        return 1;
    }

    for (int i = 0; i < MAX_RESTAURANTES; i++) {
        fscanf(restaurantesFile, "%d %d %s %s %d", &restaurantes[i].x, &restaurantes[i].y, restaurantes[i].nome, &restaurantes[i].custo, &restaurantes[i].velocidade);
    }

    fclose(restaurantesFile);

    // Leitura das coordenadas da casa
    int casaX, casaY;
    while (coordenadaspavimento[casaX][casaY] == 0) {
        printf("Digite as coordenadas da sua casa (x y): ");//atenção para a casa na cordenada 10-21, pois ela não está ligada a nenhuma pavimentação
        scanf("%d %d", &casaX, &casaY);
    }    

    //2. Leia (do teclado) a preferência de custo (caro ou barato), e retorne um arranjo com os restaurantes em ordem de rapidez de entrega.
    char preferenciaCusto[7];
    printf("Digite sua preferencia de custo (caro ou barato): ");
    scanf("%s", &preferenciaCusto);
    float distancia = 0;
    printf("\nDistancia em Zambs:\n");
    // Calcula o tempo gasto para os restaurantes escolhidos
    for (int i = 0; i < MAX_RESTAURANTES; i++) {
        if ((strcmp(preferenciaCusto, "caro") == 0 && strcmp(restaurantes[i].custo, "Caro") == 0) ||
            (strcmp(preferenciaCusto, "barato") == 0 && strcmp(restaurantes[i].custo, "Barato") == 0)) {

            distancia = contarRuasPavimentadas(casaX, casaY, restaurantes[i].x, restaurantes[i].y, coordenadaspavimento);//Distancia em minutos onde por exemplo 9.5 é igual a 9 minutos e 30 segundos
            restaurantes[i].tempogasto = distancia / restaurantes[i].velocidade;
            printf("%s: %.0f zambs\n",restaurantes[i].nome,distancia);
        }
    }

    // Ordena os restaurantes com base no tempo gasto
    CompararRestaurantes(restaurantes, MAX_RESTAURANTES);

    // Impressão dos restaurantes em ordem crescente de tempo gasto
    printf("\nRestaurantes em ordem crescente do tempo de entrega:\n");
    for (int i = MAX_RESTAURANTES - 1; i >= 0; i--) {
        if ((strcmp(preferenciaCusto, "caro") == 0 && strcmp(restaurantes[i].custo, "Caro") == 0) ||
            (strcmp(preferenciaCusto, "barato") == 0 && strcmp(restaurantes[i].custo, "Barato") == 0)) {

            printf("%s: %.1f min\n", restaurantes[i].nome, restaurantes[i].tempogasto);
        }
    }

    //3. Leia (do teclado) a preferência de custo (caro ou barato) e o tempo máximo que voce quer esperar (minutos), e retorne um arranjo com os restaurantes que respeitem a restrição de tempo de espera.
    float tempomaximo = 0;
    printf("\nDigite o tempo maximo de espera: ");
    scanf("%f", &tempomaximo);

    printf("\nRestaurantes com tempo de entrega menor ou igual ao tempo maximo (%.1f min):\n", tempomaximo);
for (int i = MAX_RESTAURANTES - 1; i >= 0; i--) {
    if ((strcmp(preferenciaCusto, "caro") == 0 && strcmp(restaurantes[i].custo, "Caro") == 0) ||
        (strcmp(preferenciaCusto, "barato") == 0 && strcmp(restaurantes[i].custo, "Barato") == 0)) {
        
        if (tempomaximo >= restaurantes[i].tempogasto) {
            printf("%s: %.1f min\n", restaurantes[i].nome, restaurantes[i].tempogasto);
        }
    }
}
    system("pause");
    return 0;
}