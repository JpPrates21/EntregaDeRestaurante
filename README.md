# | ENTREGA DE RESTAURANTES 🛵

Este projeto representa uma cidade fictícia como uma matriz, onde cada posição indica se uma rua é pavimentada ou não. Nessa cidade, diversos restaurantes estão conectados por ruas pavimentadas, e cada um possui entregadores de moto com velocidades diferentes para realizar entregas. O objetivo do sistema é calcular e ordenar os tempos de entrega dos restaurantes até a sua casa, considerando preferências de custo e limite de espera.

## 📁 Estrutura dos Dados

- **Ruas Pavimentadas**: Representadas em uma matriz de coordenadas (x, y) com valores `1` para ruas pavimentadas e `0` para ruas não-pavimentadas. As informações sobre as ruas estão em um arquivo chamado `"ruas.txt"`.
- **Restaurantes**: Cada restaurante possui uma localização, um tipo de custo (caro ou barato) e uma velocidade de entrega em "zambs por minuto". Esses dados estão armazenados no arquivo `"restaurantes.txt"`.

## 🚗 Unidade de Distância

- **Zambs**: A unidade de medida de distância entre coordenadas pavimentadas adjacentes. A velocidade das motos é dada em zambs por minuto.

## 🔍 Funcionamento

1. **Entrada das Coordenadas**: O programa solicita a localização da sua casa, verificando se está em uma área pavimentada.
2. **Cálculo de Distâncias**: Calcula a distância entre sua casa e todos os restaurantes.
3. **Preferência de Custo**: O usuário escolhe se prefere restaurantes caros ou baratos.
4. **Ordenação por Tempo de Entrega**: O sistema organiza os restaurantes do mais rápido ao mais lento.
5. **Filtro por Tempo Máximo**: O usuário pode definir um tempo máximo de espera, e o sistema exibirá apenas os restaurantes que atendem a essa restrição.

## 🧑‍💻 Rodando Localmente

Clone o projeto:

```bash
git clone https://github.com/JpPrates21/EntregaDeRestaurante.git
```

Entre no diretório do projeto:
```
cd "diretorio_onde_o_projeto_se_encontra"
```
Compile o projeto:
```
gcc main.c -o Programa
```

Executando o Projeto  
- Pelo VSCode:
```
./Programa.exe (Windows)
./Programa (Linux/MAC)
```

- Pelo Prompt de Comando:
```
Programa.exe
```

💻 Exemplo de Entrada e Saída  

- Entrada:
```
Digite as coordenadas da sua casa (x y): 18 4  
Digite sua preferencia de custo (caro ou barato): caro  
Digite o tempo maximo de espera: 10  
```
- Saída:
```
Distancia em Zambs:  
Cantina_da_Carol: 38 zambs  
Espeto_do_Chico: 37 zambs  
Churrasco_de_Boi: 36 zambs  
Las_pombas: 22 zambs  
Macarrao_na_chapa: 17 zambs  
Taste_Vin: 0 zambs  
Voador: 11 zambs  
Moto_velha: 25 zambs  
Caro_e_ruim: 22 zambs  
Comida_de_buteco: 20 zambs  
Xucesso_da_Cida: 40 zambs  

Restaurantes em ordem crescente do tempo de entrega:  
Taste_Vin: 0.0 min  
Voador: 2.2 min  
Las_pombas: 5.5 min  
Cantina_da_Carol: 7.6 min  
Xucesso_da_Cida: 8.0 min  
Macarrao_na_chapa: 8.5 min  
Churrasco_de_Boi: 9.0 min  
Caro_e_ruim: 11.0 min  
Espeto_do_Chico: 18.5 min  
Comida_de_buteco: 20.0 min  
Moto_velha: 25.0 min  

Restaurantes com tempo de entrega menor ou igual ao tempo maximo (10.0 min):
Taste_Vin: 0.0 min  
Voador: 2.2 min  
Las_pombas: 5.5 min  
Cantina_da_Carol: 7.6 min  
Xucesso_da_Cida: 8.0 min  
Macarrao_na_chapa: 8.5 min  
Churrasco_de_Boi: 9.0 min  
```
