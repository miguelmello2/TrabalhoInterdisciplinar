# **Pontifícia Univerdade Católica de Minas Gerais**

**Instituto de Ciências Exatas e Informática**

**Unidade Educacional Coração Eucarístico**

## Gabriel Reis e Miguel Mello

## Sistema do Hotel Descanso garantido 

**Introdução**
<div>
   Esse projeto e sobre o Hotel Descanso Garantido, no qual o usuário vai cadastrar os seus clientes, quartos, funcionários e estadia, dentro do seu computador, substituindo a forma antiga que era anotado em um papel.

##   
   <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_174656782.png?raw=true"/>

    
   Figura 1: Criando Quadros e decidindo cada tópico pelo <a href="https://trello.com/invite/b/x2oRG6ZX/ATTI2b418028945054326b0de565c12f3edbF0B2C525/meu-quadro-do-trello">Trello</a>, onde decidi organizar as nossas ideias e coloca-las no Trello para que assim fique melhor a visualização de cada passo a passo que eu vou fazer.
##
   <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_174235558.png?raw=true"/>
    
   Figura 2: Definir o que fazer em cada Sprint
   Na figura 2, definimos o dia e todas as funções e metas que iremos produzir a cada sprint, priorizando a qualidade e o desenvolvimento do código, para que assim, temos uma organização e visualização de cada passo a passo que vamos fazer e confirmar os objetivos que fizemos.
## 
   
   <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_175151845.png?raw=true"/>
    
   Figura 3: Mostrar o que eu já concluo
   Na figura 3, coloquei todos os processos que eu concluo no card “CONCLUIDO”, enxergando a velocidade do meu progresso.
</div>

<!--Funções-->
<div>
<h1>Explicação da Estrutura de Dados Principal</h1>
O programa utiliza várias estruturas de dados para gerenciar um sistema de hotel. Cada estrutura representa uma entidade principal no sistema, como clientes, funcionários, quartos e estadias. Aqui estão as principais estruturas de dados:


testeAdicionarCliente: Adiciona um cliente de teste ao array de clientes e salva os clientes em um arquivo.

testeBuscarCliente: Busca um cliente de teste pelo ID e verifica se os dados estão corretos.

testeAdicionarFuncionario: Adiciona um funcionário de teste ao array de funcionários e salva os funcionários em um arquivo.

testeBuscarFuncionario: Busca um funcionário de teste pelo ID e verifica se os dados estão corretos.

testeAdicionarQuarto: Adiciona um quarto de teste ao array de quartos e salva os quartos em um arquivo.

testeBuscarQuarto: Busca um quarto de teste pelo número e verifica se os dados estão corretos.

testeAdicionarEstadia: Adiciona uma estadia de teste ao array de estadias e salva as estadias em um arquivo.

testeCalcularDiarias: Calcula o total a pagar pela estadia de teste com base na diferença entre a data de entrada e saída.

executarTestes: Executa todas as funções de teste.

salvarClientes: Salva os dados dos clientes em um arquivo.

salvarFuncionarios: Salva os dados dos funcionários em um arquivo.

salvarQuartos: Salva os dados dos quartos em um arquivo.

salvarEstadias: Salva os dados das estadias em um arquivo.

definirStatusQuarto: Define o status de um quarto baseado no número do quarto.

lerClientes: Lê os dados dos clientes de um arquivo e os armazena no array de clientes.

lerFuncionarios: Lê os dados dos funcionários de um arquivo e os armazena no array de funcionários.

lerQuartos: Lê os dados dos quartos de um arquivo e os armazena no array de quartos.

lerEstadias: Lê os dados das estadias de um arquivo e os armazena no array de estadias.

calcularDiarias: Calcula o total a pagar pela estadia com base na diferença entre a data de entrada e saída.

encerrarEstadia: Encerra uma estadia com base no ID, altera o status do quarto para 'L' (livre) e salva as alterações.

buscarCliente: Busca um cliente pelo ID e exibe seus dados.

buscarFuncionario: Busca um funcionário pelo ID e exibe seus dados.

buscarQuarto: Busca um quarto pelo número e exibe seus dados.

verificarIDCliente: Verifica se o ID do cliente já existe.

verificarIDFuncionario: Verifica se o ID do funcionário já existe.

verificarNumeroQuarto: Verifica se o número do quarto já existe.

verificarIDEstadia: Verifica se o ID da estadia já existe.

listarClientes: Lista todos os clientes.

listarFuncionarios: Lista todos os funcionários.

listarQuartos: Lista todos os quartos.

listarEstadias: Lista todas as estadias.
</div>
<!--Testes-->
<div>
<hr>
<h1>Testes</h1>

<h3>Teste 1 (Cadastrar cliente): </h3>

Entrada de dados: 

1/ Reis/ Castelo/ 31975. 

Saída de dados esperada: 

“Cliente cadastrado com sucesso.” 

Resultado: Funcionando corretamente!


<h3>Teste 2- (Cadastro de um código de cliente repetido) quando o usuário for cadastrar um cliente, e colocar um código/ID que já existe(já foi cadastrado).  </h3>

Entrada de dados:

Saída de dados:

Este ID já existe! 

Resultado: Funcionando corretamente!


<h3>Teste 3 (Cadastrar funcionário)  </h3>

 Entrada de dados: 
 
1/ Gabriel/ 319/ 1200. 

Saída de dados: 

Funcionário cadastrado com sucesso! 

Resultado: Funcionando corretamente!


<h3>Teste 4- (Cadastro de um ID de funcionário repetido): Ao cadastrar funcionário, colocar um ID que já tenha sido cadastrado.  </h3>

Entrada de dados: 
 
Saída de dados:

Esse ID já existe! 

Resultado: Funcionando corretamente!


<h3>Teste 5 (Cadastro de quarto):  </h3>

 Entrada de dados:
 
 1/ 4/ 250/. 
 
Saída de dados: 

Quarto cadastrado!. 

Resultado: Funcionando corretamente!

<h3>Teste 6: (Cadastro de um código de quarto repetido):quando o usuário for cadastrar um novo quarto usando um ID já existente.  </h3>

Entrada de dados: 

Saída de dados: 

O ID desse quarto já existe! 

Resultado: Funcionando corretamente!


<h3>Teste 7: (Cadastrar uma estadia):  </h3>

Entrada de dados: 

1000/1/1/"23/10/2003"/"26/10/2003". 

Saída de dados: 

Estadia cadastrada com sucesso!. 

Resultado: Funcionando corretamente!


<h3>Teste 8: Cadastrar estadia sem existir o quarto: </h3>

Entrada de dados: 

8/8/8. 

Saída de dados: 

Esse quarto não está cadastrado!. 

Resuldado: Funcionando corretamente!


<h3>Teste 9: Ver se ao digitar um ID que não foi cadastrado, deve apresentar uma mensagem de que esse id não existe </h3>

Entrada de dados:

-9.
Saída de dados:

Esse ID não existe!.

Resultado: Funcionando corretamente!


<h3>Teste 10: Calcular a diária sem existir o ID da estadia. </h3>

Entrada de dados:

-9.

Saída de dados:

Estadia não encontrada!.

Resultado: Funcionando corretamente!

<hr>
Para fazer os testes automatizados nos utilizamos a biblioteca <assert.h> no próprio <a href = "https://www.codeblocks.org/">Code::Blocks</a> facilitando se cada função está funcionando.

 <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-07-01_110310213.png?raw=true"/>

 <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-07-01_110736525.png?raw=true"/>

</div>
