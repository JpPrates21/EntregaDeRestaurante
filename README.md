
# | ENTREGA DE RESTAURANTES 🛵

Eu criei uma representação de uma cidade como uma matriz, onde cada posição na matriz pode ser uma rua pavimentada ou não. As ruas são indicadas por coordenadas (x, y) e são pavimentadas se houver um valor 1 na matriz, ou não-pavimentadas se houver um valor 0. Se duas coordenadas adjacentes na matriz forem pavimentadas, então o trecho entre elas também é pavimentado. As informações sobre quais trechos são pavimentados e quais não são estão armazenadas em um arquivo chamado "ruas.txt".

Na cidade, todos os restaurantes são acessíveis por essas ruas pavimentadas, ou seja, sempre há um caminho pavimentado que liga um restaurante a qualquer outra coordenada pavimentada da cidade. Além disso, em minha representação, sempre existe apenas um caminho possível entre qualquer ponto e um restaurante.

Os restaurantes na cidade variam entre caros e baratos, e cada um deles possui um entregador que realiza entregas de moto. A velocidade de cada moto é especificada em um arquivo chamado "restaurantes.txt", que também inclui as informações de localização (x, y), nome, custo e velocidade da moto.

Na minha representação, a unidade de medida de distância é chamada de “zambs”, onde cada trecho pavimentado entre duas coordenadas adjacentes na matriz equivale a um zamb. As velocidades das motos são dadas em zambs por minuto.

Para usar o sistema, o programa primeiro solicita as coordenadas da sua casa, verificando se ela está localizada em uma área pavimentada da cidade. Com essa informação, o programa calcula a distância em "zambs" entre sua casa e todos os restaurantes da cidade. Durante o cálculo, ao encontrar uma esquina, o programa escolhe um caminho a seguir e armazena a coordenada da esquina para explorar os outros caminhos possíveis posteriormente, garantindo que todos os trajetos sejam considerados.

Em seguida, o programa permite que você informe sua preferência de custo (restaurantes caros ou baratos). Com base nessa preferência, o programa ordena os restaurantes de acordo com a rapidez da entrega, retornando uma lista organizada dos restaurantes mais rápidos para os mais lentos.

Além disso, se você especificar um tempo máximo de espera, o programa filtrará os restaurantes que atendem tanto à sua preferência de custo quanto à restrição de tempo. Ele então retorna uma lista dos restaurantes que podem entregar dentro do tempo desejado.


## | Rodando Localmente 👨‍💻

Clone o projeto

```bash
  git clone https://github.com/JpPrates21/EntregaDeRestaurante.git
```

Entre no diretório do projeto

```bash
  cd "diretorio_onde_o_projeto_se_encontra"
```

Compile o projeto

```bash
  gcc main.c -o Programa
```

Execute o projeto (Pelo VSCode)

```bash
  ./Programa.exe (Windows)
  ./Programa (Linux/MAC)
```
Execute o projeto (Pelo Prompt de Comando)

```bash
  Programa.exe
```


## | Entradas e Saídas: 💻

EXEMPLO DE ENTRADA:

Digite as coordenadas da sua casa (x y): 18 4  
Digite sua preferencia de custo (caro ou barato): caro  
Digite o tempo maximo de espera: 10  



EXEMPLO DE SAÍDA:

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


![Logo](https://www.ufmg.br/online/arquivos/anexos/20091216_logo_ufmg.png)

