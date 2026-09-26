# Trabalho B1 - Lógica de Programação e Algoritmos

**Nome:** Miguel Vilar Martins Ferreira | **R.A.:** UC26102017 | **Curso:** Engenharia de Software

## Descrição
Esse programa é um simulador de frete bem direto que fiz em linguagem C. Ele serve para calcular o preço final de uma entrega cruzando a distância, o peso do pacote e a modalidade de envio que o usuário escolher. O foco principal foi resolver um problema prático de logística seguindo a regra da matéria: fazer tudo rodar em tempo real sem salvar nada em vetores ou structs.

## Funcionalidades
- Não aceita dados errados: se digitar distância ou peso menor ou igual a zero, o programa reclama e pede de novo.
- Descobre a tarifa de partida sozinho com base nos km rodados.
- Cobra uma taxa extra em porcentagem dependendo do peso do pacote.
- Deixa o usuário escolher entre os envios Econômico, Expresso ou Prioritário.
- Dá para colocar ou não um seguro de R\$ 15,00 contra danos na carga.
- Mostra um resumão completo na tela assim que o programa fecha, exibindo o faturamento total, quantas entregas foram feitas e quais foram os valores da maior e da menor entrega da sessão.

## Organização da solução
Para o código não virar uma bagunça, deixei a função `main` cuidando apenas do loop principal e de perguntar se o usuário quer continuar ou parar. Toda a parte pesada de contas e travas foi dividida nessas funções separadas:
* `validarOpcao0ou1`: Cuida das perguntas de sim ou não (como a do seguro e a de continuar).
* `validarModalidade`: Garante que o usuário só escolha as opções de frete que realmente existem (1, 2 ou 3).
* `calcularValorBase`: Olha a quilometragem e pega o preço fixo de partida.
* `calcularAdicionalPeso`: Define a porcentagem a mais que vai ser cobrada por conta dos quilos do pacote.
* `calcularAdicionalModalidade`: Define o acréscimo baseado na pressa do envio escolhido.

## Compilação
Como usei apenas o C padrão, você consegue compilar o código direto abrindo o projeto no **Dev-C++** ou rodando esse comando clássico do GCC no terminal:
```bash
gcc -o simulador src/main.c
```

## Execução
Para testar e rodar o simulador no computador:
1. Abra o arquivo executável gerado depois que o código compilar.
2. Digite as informações do primeiro pacote seguindo o que aparece no terminal.
3. No fim da entrega, responda com `1` para cadastrar mais pacotes ou digite `0` para fechar o sistema e ver a tabela com as estatísticas finais.

## Uso de Inteligência Artificial
Usei inteligência artificial durante o desenvolvimento para atuar como um parceiro de programação (pair programming). A ferramenta me ajudou a debater a melhor forma de dividir as funções para respeitar as regras do trabalho, a organizar a sequência certa de commits no GitHub e a encontrar e limpar pequenos erros de digitação que apareceram no Dev-C++. Toda a lógica final do sistema e a validação do código foram controladas e revisadas inteiramente por mim.


