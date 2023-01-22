/*

************** Exercicio 01 **************

Faça um programa que manipule dois arquivos de registros de funcionários. 

O primeiro arquivo (denominado funcionários.bin) contém apenas 1 registro por 
funcionário, com as seguintes informações: 
    CPF: char[11] 
    Nome: char[30] 
    Entrada: estrutura time_t 
    Saída: estrutura time_t 
    Status: char ('P' para presente ou 'A' para ausente) 
    Os horários devem ser manipulados com a estrutura time_t: 
        veja https://cplusplus.com/reference/ctime/time/ 

O segundo arquivo (denominado log.bin) deve conter o log de entrada e saída dos 
funcionários, onde os registros são inseridos no final do arquivo, para fins de controle 
e arquivamento. Os registros devem conter: 
    CPF: char[11] 
    Horário: estrutura time_t 
    Evento: char ('E' para entrada ou 'S' para saída) 

O programa deve ter as operações: 
    registro de entrada ou saída de funcionário 
    chave é o CPF, funcionário deve ser incluído caso CPF fornecido não 
        esteja presente no arquivo funcionários.bin 
    atualização do status e horário no arquivo funcionários.bin 
    inclusão do evento no final do arquivo log.bin 
    listagem (printf) de todos os registros do arquivo funcionários.bin 
    listagem (printf) de todos os registros do arquivo log.bin de um dado 
        funcionário, onde a chave de busca é o CPF 

O programa deve: 
    Toda a implementação deve ser feita em um arquivo denominado main.c 
    Utilizar o modelo de programa fornecido 
    Ler e gravar os arquivos em modo binário (“rb”, “wb”, “rb+” ou “wb+”) 
    Utilizar estruturas definidas pelo usuário para os registros (structs) 
    Realizar a leitura e gravação dos registros (structs) com os comandos fread e 
        fwrite 
    Ser modularizado (as operações devem ser implementadas em funções) 
    Abrir e fechar os arquivos de dados apenas na função main( ) 
    Os arquivos devem ser abertos apenas no início do main( ) e devem ser 
        fechados apenas antes de terminar o programa 
    As funções que implementam as operações de registro e de listagens não 
        devem abrir/fechar os arquivos, uma vez que elas recebem o FILE* dos 
        arquivos que foram abertos no programa principal 
    Ao reexecutar o programa, os registros manipulados anteriormente devem 
        continuar disponíveis 
    Sugestão: tentar abrir o arquivo com “rb+” e se resultado do fopen for igual a 
        NULL, abrir com “wb+” 

Exemplo de uso da biblioteca time.h 

#include <stdio.h> 
#include <time.h> // biblioteca time.h 
int main () { 
 time_t relogio; // estrutura time_t 
 time(&relogio); // atribui horário corrente ao relogio 
 printf("%s", ctime(&relogio)); // imprime horário 
 return 0; 
}


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct funcionario{
    char CPF[12], Nome[30];
    time_t Entrada;
    time_t Saida;
    char Status;
};

struct log{
    char CPF[11];
    time_t Horario;
    char Evento;
};

void imprimirfuncionario(struct funcionario x){
    printf("\nCPF: %s\n", x.CPF);
    printf("nome do funcionario: %s\n", x.Nome);
    printf("entrada: %s", ctime(&x.Entrada));
    printf("saida: %s", ctime(&x.Saida));
}

void imprimirlog(struct log x){
    printf("\ncpf: %s\n", x.CPF);
    if(x.Evento == 'P'){
        printf("horario de Entrada: ");
    }
    else printf("horario de Saida: ");
    printf("%s", ctime(&x.Horario));
}

void registro(FILE *f, FILE *l){
    struct funcionario x, temp;
    struct log y;
    printf("registro de funcionarios\n");
    printf("cpf: ");
    scanf("%s", &x.CPF);
    while(getchar() != '\n');

    int novo=1;
    fseek(f, 0, SEEK_SET);

    while(fread(&temp, sizeof(struct funcionario), 1, f)){
        if(strcmp(temp.CPF, x.CPF) == 0){
            novo=0;
            strcpy(x.Nome,temp.Nome);
            do{
                printf("status: ");
                scanf("%c", &x.Status);
                while(getchar() != '\n');
                if(x.Status == 'P'){
                    time(&x.Entrada);
                    x.Saida = temp.Saida;
                    y.Horario = x.Entrada;
                }
                else if(x.Status == 'A'){
                    time(&x.Saida);
                    x.Entrada = temp.Entrada;
                    y.Horario = x.Saida;
                }
            } while(x.Status != 'P' && x.Status != 'A');
            y.Evento = x.Status;
            strcpy(y.CPF, x.CPF);
            fseek(l, 0, SEEK_END);
            fwrite(&y, sizeof(struct log), 1, l);
            fseek(f, -1*sizeof(struct funcionario), SEEK_CUR);
            break;
        }
    }
    if(novo==1){
        printf("Nome: ");
        gets(x.Nome);
        time(&x.Entrada);
        time(&x.Saida);
        x.Status = ' ';
        fseek(f, 0, SEEK_END);
    }
    fwrite(&x, sizeof(struct funcionario), 1, f);
}

void listagem_funcionarios(FILE *f){
    printf("\n");
    struct funcionario x;
    fseek(f, 0, SEEK_SET);
    while(fread(&x, sizeof(struct funcionario), 1, f)){
        imprimirfuncionario(x);
    }
    printf("\n");
}

void listagem_log(FILE *f) {
    printf("\n");
    struct log x;
    fseek(f, 0, SEEK_SET);
    while(fread(&x, sizeof(struct log), 1, f)){
        imprimirlog(x);
    }
    printf("\n");
}

int main(){
    time_t relogio;
    time(&relogio);

    FILE *funcionarios;
    funcionarios = fopen("funcionarios.bin", "rb+");
    if(funcionarios == NULL){
            funcionarios = fopen("funcionarios.bin", "wb+");
            if(funcionarios == NULL){
                printf("Nao foi possivel abrir o arquivo");
                system("pause");
                exit(1);
            }
    }

    FILE *log;
    log = fopen("log.bin", "rb+");
    if(log == NULL){
            log = fopen("log.bin", "wb+");
            if(log == NULL){
                printf("Nao foi possivel abrir o arquivo");
                system("pause");
                exit(1);
            }
    }

    int opcao;
    do {
        printf("\n\n 0-sair\n 1-registro entrada/saida\n 2-lista funcionarios\n 3-lista log\n");
        printf("\n Opcao: "); scanf(" %d",&opcao);
        switch(opcao) {
            case 1: registro(funcionarios,log); break;
            case 2: listagem_funcionarios(funcionarios); break;
            case 3: listagem_log(log); break;
            printf("\n\n\n");
        }
    } while (opcao != 0);

    fclose(funcionarios);
    fclose(log);

    return 0;

}
