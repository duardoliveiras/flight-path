### Requisitos

Pronto - [✔]

À Fazer - [✖]

##### Básico

- [✔] Ler dados dos CSV para estruturas do tipos grafos.

- [✔] Obrigatório utilizar a classe de `Graph` utilizada em aulas.

- [✔] Interface em linha de comando amigável.

##### Cálculos e listagem de conexões:

- [✔] Quantidade global de aeroportos e vôos disponíveis.

- [✔] Quantidade de vôos saíndo de um aeroporto e quantas companhias aéreas diferentes.

- [✔] Número de vôos por cidade e por companhias aéreas.

- [✔] Número de diferentes países para onde um aeroporto/cidade voa.

- [✔] Número de destinos (aeroportos, cidades ou paises) a partir de um determinado aeroporto (com número máximo de paradas).

- [✔] Viagem máxima e o correspondente par de aeroportos (origem-destino). Viagem aéreas com o maior número de escalas entre elas.

- [✔] Ranking de aeroportos com maiores capacidades de tráfego aéreo (maior número de vôos).

- [✔] Identificar aeroportos que são essenciais para manter a conexão entre destinos. Aqueles que se removidos, areas de conexão se tornam inacessíveis (Articulation Points - DFS).

##### Melhores opções de vôos:

- [✔] Uma única opção ou conjunto de opções que a partir de uma origem e destino, a melhor opção é o vôo com menor quantidade de paradas. As localizações devem ser lidas pela entrada do usuário.

- [✔] Deve ser possível calcular a melhor opção a partir de aeroportos (código ou nome).

- [✔] A partir da cidade, analisando todos aeroportos das cidade escolhidas.

- [✔] A partir das coordenadas geográficas, dada uma coordenada devemos realizar o cálculo a partir dos aeroportos mais próximos.

- [✔] O usuário pode realizar combinações dos itens anterior. Exemplo: solicitar um vôo a partir de um aeroporto para um local, ou de um local para uma cidade. (SE quisermos usar distâncias no programa, podemos utilizar a função `Haversina Distance`.

##### Filtros:

- [✖] Alguns usuários podem querer filtrar somente determinado conjunto de companhias aéreas. O sistema deve apresentar a melhor opção de voo, ou o conjunto de opções (se forem equivalentes) respeitando o critério do utilizador.

##### Documentação Doxygen

- Implementar a documentação e se for relevante, calcular a complexidade da função.

Exemplo:

```c
/**
 * @brief Function to compare students based on their codes in ascending order.
 * Complexity: O(1)
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return Returns true if the code of the first student is less than that of the second.
 */
```

### Check List Final:

- [✖] O programa usa a classe `Graph.h` fornecida em aula com suas devidas modifições que fazem sentido para o problema proposto?

- [✖] O programa permite pesquisa constante de companhias aéreas, aeroportos e cidades? (Provavelmente o uso de `Hashtables`)

- [✖] O programa tem apenas funções relativamente eficientes (Evitando lentidão durante a execução)?

- [✖] O programa foi documentado utilizando o `Doxygen` e apresenta a complexidade das principais funções?

- [✖] O programa faz uso de algoritmos aprendidos em sala? (DFS, BFS, Connected Component, Articulation Points)?
