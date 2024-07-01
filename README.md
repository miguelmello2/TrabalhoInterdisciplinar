# Trabalho-AEDs-e-Fundamentos

PONTIFÍCIA UNIVERSIDADE CATÓLICA DE MINAS GERAIS

INSTITUTO DE CIÊNCIAS EXATAS E INFORMÁTICA

UNIDADE EDUCACIONAL CORAÇÃO EUCARÍSTICO

Nome dos integrantes do grupo:

Gabriel Reis

Docente: 

Prof. Michelle Hanne e Prof. Carlos Ribas

Nome do sistema:

Hotel Descanso Garantido 

Apresentação:

Esse projeto e sobre o Hotel Descanso Garantido, no qual o usuário vai cadastrar os seus clientes, quartos, funcionários e estadia, dentro do seu computador, substituindo a forma antiga que era anotado em um papel.

<img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_174656782.png?raw=true"/>
 
Figura 1: Criando Quadros e decidindo cada tópico pelo Trello "(https://trello.com/invite/b/x2oRG6ZX/ATTI2b418028945054326b0de565c12f3edbF0B2C525/meu-quadro-do-trello)"
Decidi organizar as minhas ideias e coloca-las no Trello para que assim fique melhor a visualização de cada passo a passo que eu vou fazer.

<img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_174235558.png?raw=true"/>
 
Figura 2: Definir o que fazer em cada Sprint
Na figura 2, defini o dia e todas as funções e metas que irei produzir a cada sprint, priorizando a qualidade e o desenvolvimento do código, para que assim, eu tenha uma organização e visualização de cada passo a passo que eu deva fazer e confirmar os objetivos que eu fiz. 

<img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-06-30_175151845.png?raw=true"/>
 
Figura 3: Mostrar o que eu já concluo
Na figura 3, coloquei todos os processos que eu concluo no card “CONCLUIDO”, enxergando a velocidade do meu progresso.

Explicação da Estrutura de Dados Principal
O programa utiliza várias estruturas de dados para gerenciar um sistema de hotel. Cada estrutura representa uma entidade principal no sistema, como clientes, funcionários, quartos e estadias. Aqui estão as principais estruturas de dados:

Cliente: Representa um cliente do hotel.
typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
} Cliente;

Esta estrutura armazena o ID, nome, endereço e telefone de um cliente.

Funcionario: Representa um funcionário do hotel, com um campo adicional para o salário.
typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
    double salario;
} Funcionario;
Esta estrutura armazena o ID, nome, endereço, telefone e salário de um funcionário.

Quarto: Representa um quarto no hotel, com capacidade, diária e status (disponível ou ocupado).
typedef struct {
    int numero;
    int capacidade;
    double diaria;
    char status;
} Quarto;
Esta estrutura armazena o número, capacidade, diária e status de um quarto. O status pode ser “Disponível” ou “Ocupado”.

Data: Representa uma data com dia, mês e ano.
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;
Esta estrutura armazena uma data, com dia, mês e ano.

Estadia: Representa uma estadia no hotel, associando um cliente a um quarto durante um período específico.
typedef struct {
    int id;
    Data entrada;
    Data saida;
    Cliente cliente;
    Quarto quarto;
} Estadia;
Esta estrutura armazena uma estadia, com um ID, data de entrada, data de saída, informações do cliente e informações do quarto.


Arrays e Contadores: Arrays para armazenar múltiplos clientes, funcionários, quartos e estadias. Variáveis para contar o total de cada usuario.
Cliente clientes[100];
Funcionario funcionarios[100];
Estadia estadias[100];
Quarto quartos[100];
int totalClientes = 0, totalFuncionarios = 0, totalEstadias = 0, totalQuartos = 0;

Apresentação das Assinaturas das Funções:
dataParaTm (Converte uma estrutura Data para uma estrutura tm do C.)
void dataParaTm(Data d, struct tm *tm);
calcularDiferencaDias (Calcula a diferença em dias entre duas datas.):
int calcularDiferencaDias(Data inicio, Data fim);

calcularDiarias (Calcula o total a pagar por uma estadia, baseada no número de dias e na diária do quarto):
float calcularDiarias();

encerrarEstadia (Encerra uma estadia, mudando o status do quarto para “Disponivel”)
void encerrarEstadia();

buscarCliente (Busca e exibe informações de um cliente pelo seu ID)
void buscarCliente();

buscarFuncionario (Busca e exibe informações de um funcionário pelo seu ID)
void buscarFuncionario();

adicionarQuarto(Adiciona um novo quarto ao sistema)
void adicionarQuarto();

adicionarEstadia (Adiciona uma nova estadia ao sistema, associando um cliente e um quarto)
void adicionarEstadia();

adicionarFuncionario (adiciona um novo funcionário no sistema)
void adicionarFuncionario();

adicionarCliente (Adiciona um novo cliente ao sistema)
void adicionarCliente();

buscarQuarto (Busca e exibe informações de um quarto pelo seu número)
void buscarQuarto();


Testes:

Teste 1 (Cadastrar cliente): 

Entrada de dados: 

1/ Reis/ Castelo/ 31975. 

Saída de dados esperada: 

“Cliente cadastrado com sucesso.” 

Resultado: Funcionando corretamente!


Teste 2- (Cadastro de um código de cliente repetido) quando o usuário for cadastrar um cliente, e colocar um código/ID que já existe(já foi cadastrado).

Entrada de dados:

 1.
 Saída de dados:

Este ID já existe! 

Resultado: Funcionando corretamente!


Teste 3 (Cadastrar funcionário)

 Entrada de dados: 
 
1/ Gabriel/ 319/ 1200. 

Saída de dados: 

Funcionário cadastrado com sucesso! 

Resultado: Funcionando corretamente!


Teste 4- (Cadastro de um ID de funcionário repetido): Ao cadastrar funcionário, colocar um ID que já tenha sido cadastrado.

 Entrada de dados: 
 
1. 
Saída de dados:

Esse ID já existe! 

Resultado: Funcionando corretamente!


Teste 5 (Cadastro de quarto):

 Entrada de dados:
 
 1/ 4/ 250/. 
 
Saída de dados: 

Quarto cadastrado!. 

Resultado: Funcionando corretamente!


Teste 6: (Cadastro de um código de quarto repetido):quando o usuário for cadastrar um novo quarto usando um ID já existente. 

Entrada de dados: 

1.

Saída de dados: 

O ID desse quarto já existe! 

Resultado: Funcionando corretamente!


Teste 7: (Cadastrar uma estadia): 

Entrada de dados: 

1000/1/1/"23/10/2003"/"26/10/2003". 

Saída de dados: 

Estadia cadastrada com sucesso!. 

Resultado: Funcionando corretamente!


Teste 8: Cadastrar estadia sem existir o quarto: 

Entrada de dados: 

8/8/8. 

Saída de dados: 

Esse quarto não está cadastrado!. 

Resuldado: Funcionando corretamente!


Teste 9: Ver se ao digitar um ID que não foi cadastrado, deve apresentar uma mensagem de que esse id não existe

Entrada de dados:

-9.
Saída de dados:

Esse ID não existe!.

Resultado: Funcionando corretamente!


Teste 10: Calcular a diária sem existir o ID da estadia.

Entrada de dados:

-9.

Saída de dados:

Estadia não encontrada!.

Resultado: Funcionando corretamente!


Para fazer os testes automatizados eu utilizei a biblioteca <assert.h> no próprio code blox, facilitando se cada função está funcionando.

 <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-07-01_110310213.png?raw=true"/>

 <img src="https://github.com/ReisBiel23/Trabalho-AEDs-e-Fundamentos/blob/main/imagem_2024-07-01_110736525.png?raw=true"/>
