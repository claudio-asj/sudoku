Trabalho Final
Computação I



Descrição sobre o objetivo do trabalho: 
Nosso grupo decidiu criar um jogo com 3 níveis de dificuldade: fácil, médio e difícil, bem como uma opção de sair do jogo. Foi criada uma tabela de sudoku para cada dificuldade. Teclar 1 escolhe dificuldade fácil, teclar 2 escolhe médio, teclar 3 escolhe difícil e teclar 4 sai do jogo, qualquer outro número selecionado não é aceito e é indicado um erro avisando que o valor é inválido. Dentro do jogo,foi criado uma opção 
de colocar um valor em uma coordenada, outra opção para ver se a tabela estava concluída e outra para a pessoa desistir. Sempre que um valor é colocado pela pessoa, o programa limpa o output e printa a nova tabela com o valor pedido pela 
pessoa no local desejado. Quando a pessoa quiser, ela pode desistir ou pedir para o programa verificar se ela venceu ou se ainda não acabou. Ao vencer, o jogo apresenta quantas tentativas e quanto tempo a pessoa gastou durante o jogo. 

Premissas consideradas:
Durante a produção do jogo, ideias foram pensadas, como a ideia de o próprio programa criar uma tabela sudoku aleatória, porém, acreditamos que seria complexo demais, principalmente levando em conta a parte da dificuldade, uma vez que não saberíamos como colocar para o programa definir aleatoriamente os valores na tabela baseado na dificuldade. Portanto, decidimos colocar tabelas predefinidas. Outra ideia pensada foi implementar uma função "checar", a qual dizia para a pessoa se ela havia vencido o jogo. Se algum valor estava na posição errada o programa avisava que tinha algo errado e o jogo continuava normalmente, se estava tudo correto, ele finalizava. Inicialmente, essa função era chamada "resultado", e a antiga função que possuia o nome "checar" serviria como uma função que indicaria para a pessoa se o valor que ela colocou naquela posição estava correto ou errado assim que a pessoa indicasse a coordenada e o valor a ser colocado. Se estivesse correto, o jogo continuaria normalmente, se estivesse errado, o programa diria que estava errado e impediria a pessoa de colocar aquele valor naquela posição. Essa função serviria para facilitar o jogo, sendo utilizada na dificuldade fácil, porém, ela foi descartada no final, e a função que antigamente era chamada de "resultado" passou a ser chamada de "checar". Também pensamos em colocar caracteres coloridos e em usar bibliotecas que permitiam o uso das setas do teclado para que, ao invés da pessoa colocar a coordenada, a pessoa selecionasse o número que estivesse destacado com uma cor diferenciada alterando as coordenadas pela seta do teclado. 
Também pensamos em usar a opção de pausar o programa, com a pessoa avançando assim que apertasse qualquer tecla, bem como o programa pausando por alguns segundos, porém, pensando que o programa deveria funcionar em qualquer máquina e em qualquer software, decidimos descartar essas ideias e usar somente as bibliotecas padrões. Pensamos em criar uma função "validação", a qual, quando a pessoa teclasse para colocar um valor, a função avalia cada posição e verifica se 
tem algum número 0 (que indica que nenhum valor foi predefinido naquela posição e, então, a pessoa pode colocar o valor). Criamos uma função que limpa a tela do programa (chamamos de "LimpaTela"), para que a tabela não seja printada toda hora, poluindo o output, mas sim uma nova tabela aparece no mesmo local que a antiga, tanto para windows quanto para linux. Pensamos em utilizar o comando system("pause") no título do jogo, para fazer algo parecido com títulos de video game com a opção "aperte start para começar", porém, não sabíamos se funcionaria em qualquer máquina, uma vez que alguns do grupo disseram que o comando não estava funcionando em suas máquinas, então, descartamos a ideia. Tivemos, 
também, a ideia de contabilizar as tentativas e o tempo gasto durante o jogo usando a biblioteca <time.h.> e printar essas informações ao vencer.

Descrição do jogo e regras: 
O programa funciona igual ao sudoku conhecido por todos. As regras são que não pode ter números iguais na mesma linha e coluna, bem como a tabela é dividida em 9 mini tabelas, as quais também não podem ter valores repetidos dentro de cada uma. Assim que a dificuldade é selecionada, o jogo apresenta a tabela e a pessoa possui a opção de colocar um valor (teclando 1), verificar se já terminou o jogo (teclando 2) ou desistir (teclando 3).Digitar qualquer outro número que não sejam esses três faz o programa printar uma mensagem de erro e pedir novamente para a pessoa escolher uma opção. Caso ela decida alterar o valor na tabela, será pedido as coordenadas (o scanf das coordenadas são: linha coluna. Ex.: 2 4 → linha 2 e coluna 4) e, logo em seguida, o valor para colocar nesse local (os valores aceitos são de 1 até 9 incluso. Valores menores que 1 ou maiores que 9 o programa printa uma mensagem dizendo "valor inválido" e pede novamente o valor a ser colocado). Caso a pessoa tente mudar algum valor que já foi predefinido inicialmente na tabela, o programa indica um erro avisando que aquele valor não pode ser alterado, entretanto, se eu coloco um valor em um espaço vazio e depois tento alterar, o programa permite. Caso eu tecle a opção de ver se o jogo já terminou, se algum valor estiver errado ou eu não tenha escrito todos os valores na tabela, o programa diz que o jogo ainda não acabou e que tem algo errado, continuando o jogo normalmente, caso eu tenha colocado todos os valores nas posições corretas, o jogo diz que eu consegui vencer, indicando quantas tentativas eu fiz e em quanto tempo estive jogando e termina. Caso eu tecle para desistir, o programa printa "Game Over" e termina.

Saída: 
Ao iniciar, o programa imprime:

A partir disso, o usuário escolhe uma das opções, digita e caso ele opte pela entrada 4 o programa encerra retornando:

Contudo, caso o usuario entre com 1,2,3 o programa retorna:

a partir daqui o programa vai entrar em um ciclo, onde o usuário pode escolher umas das 3 ações, caso ele entre com 3- desistir:


Entretanto, se o usuário entrar com a opção 1, alterar valor, ele deverá entrar com as coordenadas e o valor a ser alterado, como por exemplo:

Após isso, o programa entra no loop e retorna a tabela com o valor autalizado

e assim o usuario pode continuar o jogo. Caso ele deseje checar se a tabela esta complera entrando com o 2, se ela n estiver ele retorna uma mensagem aimca da tabela:

Caso o usuário finalize o jogo corretamente e usar o comando de checar termos como retorno:


Ferramentas aprendidas e utilizadas na elaboração do trabalho: Foram utilizadas muitas matrizes e funções, uma vez que a tabela sudoku é uma grande matriz. Também aprendemos alguns comandos novos como o sleep() da biblioteca <unistd.h>,
também vimos a biblioteca <conio.h>, com o comando textcolor() e outros comandos para mudar a cor dos caracteres, como preto = "\x1b[30m", vermelho = "\x1b[31m", verde = "\x1b[32m", amarelo = "\x1b[33m", azul = "\x1b[34m", magenta = "\x1b[35m", ciano = "\x1b[36m" e branco = "\x1b[37m". Aprendemos sobre o system("pause"), que pausa o programa até a pessoa apertar qualquer tecla, bem como vimos superficialmente sobre como usar as setas do teclado utilizando
a biblioteca <conio.h>
