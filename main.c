#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 100
#define MAX_QUARTOS 100
#define MAX_ESTADIAS 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[100];
    char endereco[200];
    char telefone[15];
} Cliente;

typedef struct {
    int id;
    char nome[100];
    char endereco[200];
    char telefone[15];
    double salario;
} Funcionario;

typedef struct {
    int numero;
    int capacidade;
    double diaria;
    char status;
} Quarto;

typedef struct {
    int id;
    Data entrada;
    Data saida;
    Cliente cliente;
    Quarto quarto;
} Estadia;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;

Quarto quartos[MAX_QUARTOS];
int totalQuartos = 0;

Estadia estadias[MAX_ESTADIAS];
int totalEstadias = 0;

void testeAdicionarCliente() {
    Cliente c = {1, "Cliente Teste", "Endere�o Teste", "Telefone Teste"};
    clientes[totalClientes] = c;
    totalClientes++;

    salvarClientes();


    assert(totalClientes == 1);
    assert(clientes[0].id == 1);
    assert(strcmp(clientes[0].nome, "Cliente Teste") == 0);
    assert(strcmp(clientes[0].endereco, "Endere�o Teste") == 0);
    assert(strcmp(clientes[0].telefone, "Telefone Teste") == 0);
}

void testeBuscarCliente() {
    int idCliente = 1;
    int clienteEncontrado = 0;

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == idCliente) {
            clienteEncontrado = 1;
            assert(strcmp(clientes[i].nome, "Cliente Teste") == 0);
            assert(strcmp(clientes[i].endereco, "Endere�o Teste") == 0);
            assert(strcmp(clientes[i].telefone, "Telefone Teste") == 0);
            break;
        }
    }


    assert(clienteEncontrado == 1);
}

void testeAdicionarFuncionario() {
    Funcionario f = {1, "Funcionario Teste", "Endere�o Teste", "Telefone Teste", 1500.00};
    funcionarios[totalFuncionarios] = f;
    totalFuncionarios++;

    salvarFuncionarios();


    assert(totalFuncionarios == 1);
    assert(funcionarios[0].id == 1);
    assert(strcmp(funcionarios[0].nome, "Funcionario Teste") == 0);
    assert(strcmp(funcionarios[0].endereco, "Endere�o Teste") == 0);
    assert(strcmp(funcionarios[0].telefone, "Telefone Teste") == 0);
    assert(funcionarios[0].salario == 1500.00);
}

void testeBuscarFuncionario() {
    int idFuncionario = 1;
    int funcionarioEncontrado = 0;

    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == idFuncionario) {
            funcionarioEncontrado = 1;
            assert(strcmp(funcionarios[i].nome, "Funcionario Teste") == 0);
            assert(strcmp(funcionarios[i].endereco, "Endere�o Teste") == 0);
            assert(strcmp(funcionarios[i].telefone, "Telefone Teste") == 0);
            assert(funcionarios[i].salario == 1500.00);
            break;
        }
    }


    assert(funcionarioEncontrado == 1);
}

void testeAdicionarQuarto() {
    Quarto q = {101, 2, 200.00, 'D'};
    quartos[totalQuartos] = q;
    totalQuartos++;

    salvarQuartos();


    assert(totalQuartos == 1);
    assert(quartos[0].numero == 101);
    assert(quartos[0].capacidade == 2);
    assert(quartos[0].diaria == 200.00);
    assert(quartos[0].status == 'D');
}

void testeBuscarQuarto() {
    int numeroQuarto = 101;
    int quartoEncontrado = 0;

    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto) {
            quartoEncontrado = 1;
            assert(quartos[i].capacidade == 2);
            assert(quartos[i].diaria == 200.00);
            assert(quartos[i].status == 'D');
            break;
        }
    }


    assert(quartoEncontrado == 1);
}

void testeAdicionarEstadia() {
    Estadia e = {1, {1, 1, 2023}, {10, 1, 2023}, clientes[0], quartos[0]};
    estadias[totalEstadias] = e;
    totalEstadias++;

    salvarEstadias();


    assert(totalEstadias == 1);
    assert(estadias[0].id == 1);
    assert(estadias[0].entrada.dia == 1);
    assert(estadias[0].entrada.mes == 1);
    assert(estadias[0].entrada.ano == 2023);
    assert(estadias[0].saida.dia == 10);
    assert(estadias[0].saida.mes == 1);
    assert(estadias[0].saida.ano == 2023);
    assert(estadias[0].cliente.id == 1);
    assert(estadias[0].quarto.numero == 101);
}

void testeCalcularDiarias() {
    int idEstadia = 1;

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].id == idEstadia) {
            Estadia e = estadias[i];
            int dias = (e.saida.dia - e.entrada.dia) +
                       ((e.saida.mes - e.entrada.mes) * 30) +
                       ((e.saida.ano - e.entrada.ano) * 365);

            double total = dias * e.quarto.diaria;
            assert(total == 9 * 200.00);
            return;
        }
    }
}

void executarTestes() {

    totalClientes = 0;
    totalFuncionarios = 0;
    totalQuartos = 0;
    totalEstadias = 0;


    testeAdicionarCliente();
    testeBuscarCliente();
    testeAdicionarFuncionario();
    testeBuscarFuncionario();
    testeAdicionarQuarto();
    testeBuscarQuarto();
    testeAdicionarEstadia();
    testeCalcularDiarias();

    printf("Todos os testes foram executados com sucesso!\n");
}

void salvarClientes() {
    FILE *file = fopen("clientes.txt", "w");
    for (int i = 0; i < totalClientes; i++) {
        fprintf(file, "%d\n%s\n%s\n%s\n", clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
    fclose(file);
}

void salvarFuncionarios() {
    FILE *file = fopen("funcionarios.txt", "w");
    for (int i = 0; i < totalFuncionarios; i++) {
        fprintf(file, "%d\n%s\n%s\n%s\n%lf\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].endereco, funcionarios[i].telefone, funcionarios[i].salario);
    }
    fclose(file);
}

void salvarQuartos() {
    FILE *file = fopen("quartos.txt", "w");
    for (int i = 0; i < totalQuartos; i++) {
        fprintf(file, "%d\n%d\n%lf\n%c\n", quartos[i].numero, quartos[i].capacidade, quartos[i].diaria, quartos[i].status);
    }
    fclose(file);
}

void salvarEstadias() {
    FILE *file = fopen("estadias.txt", "w");
    for (int i = 0; i < totalEstadias; i++) {
        fprintf(file, "%d\n%d %d %d\n%d %d %d\n%d\n%d\n",
                estadias[i].id,
                estadias[i].entrada.dia, estadias[i].entrada.mes, estadias[i].entrada.ano,
                estadias[i].saida.dia, estadias[i].saida.mes, estadias[i].saida.ano,
                estadias[i].cliente.id, estadias[i].quarto.numero);
    }
    fclose(file);
}

void definirStatusQuarto(int numeroQuarto, char status) {
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto) {
            quartos[i].status = status;
            break;
        }
    }
}

void lerClientes() {
    FILE *file = fopen("clientes.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d\n", &clientes[totalClientes].id) != EOF) {
            fgets(clientes[totalClientes].nome, 100, file);
            strtok(clientes[totalClientes].nome, "\n");
            fgets(clientes[totalClientes].endereco, 200, file);
            strtok(clientes[totalClientes].endereco, "\n");
            fgets(clientes[totalClientes].telefone, 15, file);
            strtok(clientes[totalClientes].telefone, "\n");
            totalClientes++;
        }
        fclose(file);
    }
}

void lerFuncionarios() {
    FILE *file = fopen("funcionarios.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d\n", &funcionarios[totalFuncionarios].id) != EOF) {
            fgets(funcionarios[totalFuncionarios].nome, 100, file);
            strtok(funcionarios[totalFuncionarios].nome, "\n");
            fgets(funcionarios[totalFuncionarios].endereco, 200, file);
            strtok(funcionarios[totalFuncionarios].endereco, "\n");
            fgets(funcionarios[totalFuncionarios].telefone, 15, file);
            strtok(funcionarios[totalFuncionarios].telefone, "\n");
            fscanf(file, "%lf\n", &funcionarios[totalFuncionarios].salario);
            totalFuncionarios++;
        }
        fclose(file);
    }
}

void lerQuartos() {
    FILE *file = fopen("quartos.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d\n%d\n%lf\n%c\n", &quartos[totalQuartos].numero, &quartos[totalQuartos].capacidade, &quartos[totalQuartos].diaria, &quartos[totalQuartos].status) != EOF) {
            totalQuartos++;
        }
        fclose(file);
    }
}

void lerEstadias() {
    FILE *file = fopen("estadias.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d\n%d %d %d\n%d %d %d\n%d\n%d\n",
                      &estadias[totalEstadias].id,
                      &estadias[totalEstadias].entrada.dia, &estadias[totalEstadias].entrada.mes, &estadias[totalEstadias].entrada.ano,
                      &estadias[totalEstadias].saida.dia, &estadias[totalEstadias].saida.mes, &estadias[totalEstadias].saida.ano,
                      &estadias[totalEstadias].cliente.id, &estadias[totalEstadias].quarto.numero) != EOF) {

            for (int i = 0; i < totalClientes; i++) {
                if (clientes[i].id == estadias[totalEstadias].cliente.id) {
                    estadias[totalEstadias].cliente = clientes[i];
                    break;
                }
            }
            for (int i = 0; i < totalQuartos; i++) {
                if (quartos[i].numero == estadias[totalEstadias].quarto.numero) {
                    estadias[totalEstadias].quarto = quartos[i];
                    break;
                }
            }
            totalEstadias++;
        }
        fclose(file);
    }
}

void calcularDiarias() {
    int idEstadia;
    printf("Informe o ID da estadia: ");
    scanf("%d", &idEstadia);

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].id == idEstadia) {
            Estadia e = estadias[i];
            int dias = (e.saida.dia - e.entrada.dia) +
                       ((e.saida.mes - e.entrada.mes) * 30) +
                       ((e.saida.ano - e.entrada.ano) * 365);

            double total = dias * e.quarto.diaria;
            printf("Total a pagar pela estadia: R$ %.2lf\n", total);
            return;
        }
    }
    printf("Estadia n�o encontrada!\n");
}

void encerrarEstadia() {
    int idEstadia;
    printf("Informe o ID da estadia: ");
    scanf("%d", &idEstadia);

    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].id == idEstadia) {

            for (int j = 0; j < totalQuartos; j++) {
                if (quartos[j].numero == estadias[i].quarto.numero) {
                    quartos[j].status = 'L';
                    salvarQuartos();
                    break;
                }
            }


            for (int k = i; k < totalEstadias - 1; k++) {
                estadias[k] = estadias[k + 1];
            }
            totalEstadias--;
            salvarEstadias();

            printf("Estadia encerrada com sucesso!\n");
            return;
        }
    }
    printf("Estadia n�o encontrada!\n");
}

void buscarCliente() {
    int idCliente;
    printf("Informe o ID do cliente: ");
    scanf("%d", &idCliente);

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == idCliente) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Endere�o: %s\n", clientes[i].endereco);
            printf("Telefone: %s\n", clientes[i].telefone);
            return;
        }
    }
    printf("Cliente n�o encontrado!\n");
}

void buscarFuncionario() {
    int idFuncionario;
    printf("Informe o ID do funcion�rio: ");
    scanf("%d", &idFuncionario);

    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == idFuncionario) {
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Endere�o: %s\n", funcionarios[i].endereco);
            printf("Telefone: %s\n", funcionarios[i].telefone);
            printf("Sal�rio: %.2lf\n", funcionarios[i].salario);
            return;
        }
    }
    printf("Funcion�rio n�o encontrado!\n");
}

void buscarQuarto() {
    int numeroQuarto;
    printf("Informe o n�mero do quarto: ");
    scanf("%d", &numeroQuarto);

    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto) {
            printf("Capacidade: %d\n", quartos[i].capacidade);
            printf("Di�ria: %.2lf\n", quartos[i].diaria);
            printf("Status: %c\n", quartos[i].status);
            return;
        }
    }
    printf("Quarto n�o encontrado!\n");
}

int verificarIDCliente(int id) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            printf("ID j� existente! Informe um ID diferente.\n");
            return 1;
        }
    }
    return 0;
}


int verificarIDFuncionario(int id) {
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            printf("ID j� existente! Informe um ID diferente.\n");
            return 1;
        }
    }
    return 0;
}


int verificarNumeroQuarto(int numero) {
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numero) {
            printf("N�mero de quarto j� existente! Informe um n�mero diferente.\n");
            return 1;
        }
    }
    return 0;
}


int verificarIDEstadia(int id) {
    for (int i = 0; i < totalEstadias; i++) {
        if (estadias[i].id == id) {
            printf("ID j� existente! Informe um ID diferente.\n");
            return 1;
        }
    }
    return 0;
}


void listarClientes() {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d, Nome: %s, Endere�o: %s, Telefone: %s\n", clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
}

void listarFuncionarios() {
    printf("Lista de Funcion�rios:\n");
    for (int i = 0; i < totalFuncionarios; i++) {
        printf("ID: %d, Nome: %s, Endere�o: %s, Telefone: %s, Sal�rio: %.2lf\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].endereco, funcionarios[i].telefone, funcionarios[i].salario);
    }
}

void listarQuartos() {
    printf("Lista de Quartos:\n");
    for (int i = 0; i < totalQuartos; i++) {
        printf("N�mero: %d, Capacidade: %d, Di�ria: %.2lf, Status: %c\n", quartos[i].numero, quartos[i].capacidade, quartos[i].diaria, quartos[i].status);
    }
}

void listarEstadias() {
    printf("Lista de Estadias:\n");
    for (int i = 0; i < totalEstadias; i++) {
        printf("ID: %d, Entrada: %02d/%02d/%04d, Sa�da: %02d/%02d/%04d, Cliente: %s, Quarto: %d\n",
               estadias[i].id,
               estadias[i].entrada.dia, estadias[i].entrada.mes, estadias[i].entrada.ano,
               estadias[i].saida.dia, estadias[i].saida.mes, estadias[i].saida.ano,
               estadias[i].cliente.nome, estadias[i].quarto.numero);
    }
}

void adicionarCliente() {
    Cliente c;

    do {
        printf("Informe o ID do cliente: ");
        scanf("%d", &c.id);
    } while (verificarIDCliente(c.id));

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", c.nome);
    printf("Informe o endere�o do cliente: ");
    scanf(" %[^\n]", c.endereco);
    printf("Informe o telefone do cliente: ");
    scanf(" %[^\n]", c.telefone);

    clientes[totalClientes] = c;
    totalClientes++;

    salvarClientes();
    printf("Cliente adicionado com sucesso!\n");
}

void adicionarFuncionario() {
    Funcionario f;

    do {
        printf("Informe o ID do funcion�rio: ");
        scanf("%d", &f.id);
    } while (verificarIDFuncionario(f.id));

    printf("Informe o nome do funcion�rio: ");
    scanf(" %[^\n]", f.nome);
    printf("Informe o endere�o do funcion�rio: ");
    scanf(" %[^\n]", f.endereco);
    printf("Informe o telefone do funcion�rio: ");
    scanf(" %[^\n]", f.telefone);
    printf("Informe o sal�rio do funcion�rio: ");
    scanf("%lf", &f.salario);

    funcionarios[totalFuncionarios] = f;
    totalFuncionarios++;

    salvarFuncionarios();
    printf("Funcion�rio adicionado com sucesso!\n");
}


void adicionarQuarto() {
    Quarto q;

    do {
        printf("Informe o n�mero do quarto: ");
        scanf("%d", &q.numero);
    } while (verificarNumeroQuarto(q.numero));

    printf("Informe a capacidade do quarto: ");
    scanf("%d", &q.capacidade);
    printf("Informe a di�ria do quarto: ");
    scanf("%lf", &q.diaria);
    q.status = 'D';

    quartos[totalQuartos] = q;
    totalQuartos++;

    salvarQuartos();
    printf("Quarto adicionado com sucesso!\n");
}


void adicionarEstadia() {
    Estadia e;
    int clienteID, quartoNumero;

    do {
        printf("Informe o ID da estadia: ");
        scanf("%d", &e.id);
    } while (verificarIDEstadia(e.id));

    printf("Informe a data de entrada (dd mm aaaa): ");
    scanf("%d %d %d", &e.entrada.dia, &e.entrada.mes, &e.entrada.ano);
    printf("Informe a data de sa�da (dd mm aaaa): ");
    scanf("%d %d %d", &e.saida.dia, &e.saida.mes, &e.saida.ano);

    printf("Informe o ID do cliente: ");
    scanf("%d", &clienteID);
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == clienteID) {
            e.cliente = clientes[i];
            break;
        }
    }

    printf("Informe o n�mero do quarto: ");
    scanf("%d", &quartoNumero);
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == quartoNumero) {
            e.quarto = quartos[i];
            definirStatusQuarto(quartoNumero, 'O');
            break;
        }
    }

    estadias[totalEstadias] = e;
    totalEstadias++;

    salvarEstadias();
    printf("Estadia adicionada com sucesso!\n");
}


void menu() {
    int opcao;

    do {
        printf("\n\n==== Sistema de Gest�o de HotelHotel Descanso Garantido  ====\n\n");
        printf("1.  Adicionar cliente\n");
        printf("2.  Adicionar funcion�rio\n");
        printf("3.  Adicionar quarto\n");
        printf("4.  Adicionar estadia\n");
        printf("5.  Listar clientes\n");
        printf("6.  Listar funcion�rios\n");
        printf("7.  Listar quartos\n");
        printf("8.  Listar estadias\n");
        printf("9.  Buscar cliente\n");
        printf("10. Buscar funcion�rio\n");
        printf("11. Buscar quarto\n");
        printf("12. Calcular di�rias\n");
        printf("13. Encerrar estadia\n");
        printf("0.  Sair\n");
        printf("====================================\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                adicionarFuncionario();
                break;
            case 3:
                adicionarQuarto();
                break;
            case 4:
                adicionarEstadia();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                listarFuncionarios();
                break;
            case 7:
                listarQuartos();
                break;
            case 8:
                listarEstadias();
                break;
            case 9:
                buscarCliente();
                break;
            case 10:
                buscarFuncionario();
                break;
            case 11:
                buscarQuarto();
                break;
            case 12:
                calcularDiarias();
                break;
            case 13:
                encerrarEstadia();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
                break;
        }
    } while (opcao != 0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    executarTestes();

    lerClientes();
    lerFuncionarios();
    lerQuartos();
    lerEstadias();

    menu();

    return 0;
}
