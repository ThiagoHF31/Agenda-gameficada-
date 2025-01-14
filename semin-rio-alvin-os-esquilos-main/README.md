# Gerenciador de Tarefas - Trabalho de Estruturas de Dados

## Introdução

### Descrição

Este projeto é um gerenciador de tarefas desenvolvido em *C* como parte do trabalho da disciplina *INF0063 - AED1 (Algoritmos e Estruturas de Dados I). O sistema permite que o usuário adicione tarefas, acompanhe o progresso e registre as tarefas concluídas, além de calcular o **XP* ganho ao completar as tarefas. A implementação utiliza estruturas de dados como *fila* e *lista encadeada* para gerenciar as tarefas pendentes e concluídas.

<p align="center">
  <img src="https://amhandmade.pt/cdn/shop/files/IMG_5474.jpg?v=1695566664&width=1445" alt="img" width="300">
</p>



---

## Fundamentos Teóricos

### Estruturas de Dados Utilizadas

- **Fila de Tarefas Pendentes (Queue):**
  - Utilizada para gerenciar as tarefas não concluídas, seguindo o conceito FIFO (*First In, First Out*).
  - **Descrição:** Novas tarefas são adicionadas ao final da fila, enquanto as tarefas concluídas são removidas do início.
  - **Implementação:** Cada tarefa é representada como um nó conectado sequencialmente por ponteiros.

- **Lista de Tarefas Concluídas:**
  - Estrutura de dados do tipo lista ligada para armazenar as tarefas finalizadas, em ordem LIFO (*Last In, First Out*).
  - **Descrição:** Novas tarefas concluídas são inseridas no início da lista.
  - **Implementação:** Cada nó aponta para o próximo elemento, formando uma sequência encadeada.

---
### Mecanismos e Algoritmos

- **Adição de Tarefas à Fila:**
  - O método `adicionarTarefaFila` realiza uma busca linear para evitar duplicatas antes de inserir a nova tarefa:
    1. Verifica se a descrição da tarefa já existe na fila.
    2. Caso seja única, aloca a tarefa dinamicamente e a insere na estrutura.

- **Exibição das Tarefas:**
  - As funções `exibirTarefas` e `exibirTarefasConcluidas` iteram pelas estruturas de dados e exibem as tarefas em formato de tabela para melhor visualização.

- **Conclusão de Tarefas:**
  - O método `concluirTarefa` permite ao usuário selecionar uma tarefa por índice.
    - Após a conclusão:
      - Atualiza o tempo dedicado à tarefa.
      - Calcula o XP ganho (1 XP a cada 10 minutos de trabalho).
      - Move a tarefa da fila para a lista de tarefas concluídas.

- **XP Total:**
  - Calculado com base nas tarefas concluídas e armazenado em uma variável global.

- **Gerenciamento de Memória:**
  - Uso de funções como `malloc` e `free` para gerenciamento dinâmico da memória, permitindo a criação e remoção de tarefas sem desperdício de recursos.

---
### Avaliação da Solução

A solução pode ser avaliada com base nos seguintes critérios:

- **Funcionalidade:**
  - Verificar se as operações de adicionar, concluir e exibir tarefas funcionam corretamente.
  - Testar cenários de erro, como tarefas duplicadas ou seleção inválida.

- **Desempenho:**
  - Avaliar a eficiência da busca linear ao evitar duplicatas.
  - Medir o tempo de execução em cenários com muitas tarefas.

- **Utilização de Recursos:**
  - Garantir que a memória alocada seja liberada adequadamente para evitar *memory leaks*.
  - Monitorar o consumo de memória.

- **Usabilidade:**
  - Validar a clareza das mensagens e a navegação no menu.
  - Testar a facilidade de uso do sistema.

- **Escalabilidade:**
  - Medir o comportamento com volumes crescentes de tarefas pendentes e concluídas.

---
### Forma de Avaliação

Para validar e aprimorar a solução, as seguintes estratégias podem ser aplicadas:

- **Testes unitários:**
  - Validar individualmente funções como `adicionarTarefaFila` e `concluirTarefa`.

- **Cenários de uso reais:**
  - Simular casos típicos e extremos, como a adição de uma grande quantidade de tarefas.

- **Ferramentas de monitoramento:**
  - Utilizar ferramentas como Valgrind para verificar vazamentos de memória.

- **Feedback de usuários:**
  - Coletar opiniões sobre a experiência de uso e possíveis melhorias.


---

## Metodologia

### Funcionalidades

<p align="center">
  <img src="https://midias.siteware.com.br/wp-content/uploads/2019/05/25081155/dicas-gestao-projetos.jpg" alt="img" width="400">
</p>

- *Adicionar Tarefas:* O usuário pode adicionar tarefas com uma descrição e tempo estimado para a sua execução.
- *Exibir Tarefas Pendentes:* Lista todas as tarefas ainda não concluídas.
- *Concluir Tarefas:* O usuário pode marcar uma tarefa como concluída e registrar o tempo real dedicado à tarefa.
- *Exibir Tarefas Concluídas:* Exibe uma lista de tarefas já concluídas, com o tempo estimado, tempo real e XP ganho.
- *Ver XP Total:* O sistema calcula e exibe o total de XP ganho até o momento.
- *Controle de Entrada:* O sistema evita a duplicação de tarefas com a mesma descrição.

### Estruturas de Dados Utilizadas

- *Fila:* Utilizada para armazenar as tarefas pendentes. A fila segue a estrutura *FIFO* (First In, First Out), onde a tarefa que é adicionada primeiro será a primeira a ser concluída.
- *Lista Encadeada:* Utilizada para armazenar as tarefas concluídas. Cada tarefa concluída é inserida no início da lista.

### Estrutura do Código

- *Tarefa:* Estrutura que armazena os dados de cada tarefa, como descrição, XP, tempo estimado, tempo real e ponteiro para a próxima tarefa.
- *Fila:* Estrutura que mantém as tarefas pendentes. Contém ponteiros para o início (frente) e fim (traseira) da fila.
- *ListaConcluidas:* Estrutura que mantém as tarefas concluídas, com um ponteiro para o início da lista.

### Como Usar

1. *Adicionar Tarefas:* O programa pede ao usuário a descrição da tarefa e o tempo estimado para sua execução.
2. *Exibir Tarefas Pendentes:* Mostra todas as tarefas pendentes, incluindo descrição, XP acumulado, tempo estimado e tempo real.
3. *Concluir Tarefas:* O usuário seleciona uma tarefa pendente para marcar como concluída, informa o tempo real dedicado e ganha XP.
4. *Exibir Tarefas Concluídas:* Exibe uma lista das tarefas concluídas com o tempo real dedicado e o XP acumulado.
5. *Ver XP Total:* Mostra o total de XP acumulado até o momento.

### Como Compilar e Executar

1. **Compilar o código:**  
   Execute o seguinte comando no terminal para compilar o programa:  
   ```bash
   gcc -o Codigo Codigo.c

   

2. **Executar o programa:**
Após a compilação, execute o programa com o comando:
   ```bash
   ./Codigo

   

3. Siga as instruções no menu interativo para adicionar tarefas, concluí-las, verificar tarefas pendentes ou concluídas, e ver o XP total.

### Exemplo de Saída

```plaintext
==========================================
 Bem-vindo ao Gerenciador de Tarefas XP!
==========================================
1. Adicionar Tarefa
2. Exibir Tarefas
3. Marcar Tarefa como Concluída
4. Ver Tarefas Concluídas
5. Ver XP Total
6. Sair
Escolha uma opção: 1
Digite a descrição da tarefa: Estudar Estruturas de Dados
Digite o tempo estimado (em minutos): 60
Tarefa adicionada com sucesso!
```

## Resultados e Conclusões

Os resultados mostram que o gerenciador de tarefas opera corretamente, com adição, conclusão e exibição funcionando conforme esperado. Em testes simulando 20 tarefas, o XP total foi calculado corretamente, e a exibição foi clara e organizada. Não foram detectados memory leaks em testes com o Valgrind, garantindo eficiência no uso de memória. Comparado a soluções similares, o sistema se destacou pela simplicidade de uso e clareza. Como lição, aprendemos a importância de validar cenários extremos, usar boas práticas de gerenciamento de memória e estruturar menus intuitivos para a experiência do usuário.

## Equipe

- *202302520 - Ana Clara Fortunado de Souza*
- *202201646 - Layssa Ribeiro Abreu Peres*
- *202206139 - Thiago Honorato Ferreira*

## Licença

Este projeto é licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.