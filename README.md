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
