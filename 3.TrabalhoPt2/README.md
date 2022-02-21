# Sistema de Indicação de Tarefas

Um sistema de tarefas simples para adicionar informações sobre tarefas de qualquer tipo, sendo possível exibí-las, editá-las e excluí-las se necessário. As tarefas também podem ser marcadas como concluídas, e o sistema pode exibir as tarefas do momento, que irá organizá-las por prioridade, deadline e duração;  

As opções que primeiramente aparecerão no menu quando o programa for iniciado são:

1 - INSERIR NOVA TAREFA
2 -  VISUALIZAR TAREFAS CADASTRADAS
3 - EXCLUIR TAREFA
4 - EDITAR TAREFA
5 - INDICAR TAREFAS DO MOMENTO
6 - CONCLUIR TAREFA
0 - SAIR

---

## 1 - INSERIR NOVA TAREFA

Insere uma nova tarefa no sistema. O sistema irá pedir as informações da tarefa para adicioná-la à lista de tarefas. As informações em sequência são:

- Nome da Tarefa
- Prioridade
- Data de início (cada seção abaixo é pedida individualmente):
	- Dia
	- Mês
	- Ano
	- Hora
	- Minuto
- Tempo de Duração (cada seção abaixo é pedida individualmente):
	- Horas
	- Minutos
- OPCIONAL: o sistema pede se a tarefa é longa (se demora dias, meses e anos). Se o usuário desejar, pode também incluir na tarefa:
	- Dias
	- Meses
	- Anos

Após isso, pressione qualquer tecla e você voltará ao menu. A tarefa cadastrada é incluída no sistema e será visível quando selecionar a opção "VISUALIZAR TAREFAS CADASTRADAS"

---
## 2 - VISUALIZAR TAREFAS CADASTRADAS

Ao selecionar esta opção, todas as tarefas cadastradas pela opção "INSERIR NOVA TAREFA" enquanto o programa esteve ativo aparecerão, ordenadas por deadline, e exibindo todas as informações cadastradas, incluindo um ID, para diferenciá-la de tarefas que tenham o mesmo nome ou dados exatamente iguais, já que o ID é único em cada tarefa.

---
## 3 - EXCLUIR TAREFA

Exibirá todas as tarefas cadastradas da mesma forma que ao selecionar a opção "VISUALIZAR TAREFAS CADASTRADAS". O sistema então irá pedir o ID da tarefa a excluir, ou selecionar 0 para voltar ao menu. Ao dar o ID de uma tarefa, a tarefa é excluída da lista de tarefas, e então ao pressionar qualquer botão retornará ao menu.

---
## 4 - EDITAR TAREFA

Exibirá todas as tarefas cadastradas da mesma forma que ao selecionar a opção "VISUALIZAR TAREFAS CADASTRADAS". O sistema então irá pedir o ID da tarefa a editar, ou digitar 0 para cancelar a operação. 

Ao encontrar um ID, o sistema então exibirá 3 opções, novamente exibindo 0 para cancelar:

1 - EDITAR DADOS (NOME, PRIORIDADE E STATUS)
2 - EDITAR DEADLINE
3 - EDITAR DURACAO
0 - CANCELAR

Ao selecionar uma opção, a seção é bem semelhante às vistas ao adicionar uma tarefa, mas apenas para os elementos selecionados: 

1. A primeira opção apenas pedirá o nome da tarefa, prioridade, e digitar 1 para marcar como concluida ou 0 como para fazer;
2. A segunda opção pedirá uma nova data de deadline da tarefa, solicitando para digitar o novo dia, mês, ano, hora e minuto, respectivamente
3. A terceira opção pedirá novos valores de duração: horas, minutos e novamente perguntará se é uma tarefa longa. Caso o usuário digite "s" ou "S", pedirá também valores de dias, meses e anos da duração da tarefa

---
## 5 - INDICAR AS TAREFAS DO MOMENTO

Caso o usuário tenha tarefas não concluidas, esta opção irá exibir as tarefas de maior prioridade, ocultando aquelas de menor prioridade que chocam com o horário da selecionada. Tarefas marcadas como concluídas não serão levadas em conta ao selecionar essa opção.

---
## 6 - CONCLUIR TAREFA

Ao selecionar essa opção, o sistema irá mostrar todas as tarefas, como na opção "VISUALIZAR TAREFAS CADASTRADAS", e irá pedir o ID de uma tarefa para marcá-la como concluída, ou 0 para cancelar a operação. Após escolher um ID válido, a tarefa está com o status concluída, e não será levada em conta ou exibida quando o usuário selecionar a opção "INDICAR TAREFAS DO MOMENTO"

---
## 0 - SAIR

Ao selecionar essa opção, o programa é fechado.

---