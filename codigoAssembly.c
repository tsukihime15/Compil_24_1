#include "codigoAssembly.h"

int Registrador_atual = 7; 

int section_bss = 0; //para variaveis globais e constantes
int section_text_var_glbl = 0; //para var globais
int section_text_func = 0; //para funcoes
int num_var_local = 0;

/*chamada uma vez so na raiz da AST*/

void generateAsm(NODO* arvore){

    FILE *output_file = stdout;

    //printf("1\n"); // debug

    geraCodigoPelaAST(arvore, output_file);

    if (output_file != stdout) 
        fclose(output_file);
}

void geraCodigoPelaAST(NODO* nodo, FILE* output_file){

    if (nodo == NULL) return; 

    if (!nodo || nodo->visitado) return;
    nodo->visitado = 1;

    switch (nodo->valor_lexico->natureza) {
        case LITERAL:
            // Código para um literal
            fprintf(output_file, "\tmovl $%s, %%eax\n", nodo->valor_lexico->valor);
            fprintf(output_file, "\tPassou LITERAL %s\n",nodo->valor_lexico->valor);
            break;

        case GLOBAL_DECL:
            // Código para declarar variaveis globais
            geraCodigoVarGlobal(nodo, output_file);
            fprintf(output_file, "\tPassou GLOBAL_DECL %s\n",nodo->valor_lexico->valor);
            break;

        case VARIABLE:
            // Código para declarar uma variavel local (?)
            geraCodigoVariable(nodo, output_file);
            fprintf(output_file, "\tPassou VARIABLE %s, desl %d\n",nodo->valor_lexico->valor, nodo->valor_lexico->deslocamento);
            break;
        case OPERAND:
            // Código para usar uma variavel em uma expressao
            //geraCodigoOperand(nodo, output_file);
            fprintf(output_file, "\tPassou OPERAND %s, desl %d\n",nodo->valor_lexico->valor, nodo->valor_lexico->deslocamento);
            break;

        case ATRIBUITION:
            // Código para uma atribuição
            //geraCodigoAtrib(nodo, output_file);
            break;

        case OPERATOR:
            // Código para uma função
            //geraCodigoOperacao(nodo, output_file);
            break;

        case CONTROL:
            // Código para uma função
            //geraCodigoControle(nodo, output_file);
            break;

        case TYPE:
            // Código para um TYPE
            //geraCodigo(nodo, output_file);
            break;

        case RETURN:
            // Código para um RETURN
            geraCodigoRetorno(nodo, output_file);
            break;

        case FUNCTION_CALL:
            // Código para uma chamada de função
            //geraCodigoChamadaFuncao(nodo, output_file);
            break;

        case FUNCTION:
            // Código para uma função
            geraCodigoFuncao(nodo, output_file);
            break;

        default:
            break;
    }

    // Percorre toda a arvore
    geraCodigoPelaAST(nodo->filho, output_file);
    geraCodigoPelaAST(nodo->irmao, output_file);

}

void geraCodigoVarGlobal(NODO* nodo, FILE* output_file){
    //Inicia a declaracao de Var Globais
    if(section_text_var_glbl == 0)
        {
        fprintf(output_file, "\t.text\n");
        section_text_var_glbl = 1;
        }

    fprintf(output_file, "\t.globl\t%s\n",nodo->valor_lexico->valor); 

    if(section_bss == 0)
        {
        fprintf(output_file, "\t.bss\n");
        section_bss = 1;
        }

    fprintf(output_file, "\t.align 4\n");
    fprintf(output_file, "\t.type\tz, @object\n");
    fprintf(output_file, "\t.size\t%s, 4\n",nodo->valor_lexico->valor);
    fprintf(output_file, "%s:\n",nodo->valor_lexico->valor);
    fprintf(output_file, "\t.zero	4\n");
}

void geraCodigoVariable(NODO* nodo, FILE* output_file){
    // acho que so precisa definir o deslocamento dela (posicao da pilha)
    num_var_local ++;
    nodo->valor_lexico->deslocamento = num_var_local * -4;
    //fprintf(output_file, "%d",nodo->valor_lexico->valor);
}

void geraCodigoAtrib(NODO* nodo, FILE *output_file) {
    // arvore->filho eh o identificador
    // arvore->irmao eh a expressao

    if(nodo->filho == NULL)
        {}
        else
    if (nodo->filho->valor_lexico->natureza == OPERAND){
        geraCodigoPelaAST(nodo->filho,output_file); //preciso q passe aqui para receber o deslocamento
        fprintf(output_file, "\tmovl\t%d(%%rbp), %%eax\n",nodo->filho->valor_lexico->deslocamento);
    }
    else if (nodo->filho->valor_lexico->natureza == LITERAL)
            fprintf(output_file, "\tmovl\t$%s, %%eax\n",nodo->filho->valor_lexico->valor);
        
    geraCodigoExpressao(nodo->irmao, output_file);
    fprintf(output_file, "\t// Código para armazenar o valor em %s\n", nodo->filho->valor_lexico->valor);

}

void geraCodigoOperacao(NODO* arvore, FILE *output_file){
if (arvore == NULL) return;

    // Gera código para o operando esquerdo
    geraCodigoExpressao(arvore->filho, output_file);

    // Empilha o resultado da operação no registrador
    fprintf(output_file, "\tpush %%eax\n");

    // Gera código para o operando direito
    geraCodigoExpressao(arvore->filho->irmao, output_file);

    // Desempilha e realiza a operação
    fprintf(output_file, "\tpop %%ecx\n");
    //int intValue = atoi(arvore->valor_lexico->valor);
    switch (arvore->valor_lexico->valor[0]) {
        case '+':
            fprintf(output_file, "\taddl %%ecx, %%eax\n");
            break;
        case '-':
            fprintf(output_file, "\tsubl %%ecx, %%eax\n");
            break;
        case '*':
            fprintf(output_file, "\timull %%ecx, %%eax\n");
            break;
        case '/':
            fprintf(output_file, "\tcltd\n");
            fprintf(output_file, "\tidivl %%ecx\n");
            break;
    }
}

void geraCodigoControle(NODO* arvore, FILE *output_file){
    static int label_counter = 0;
    int local_label = label_counter++;

    if (strcmp(arvore->valor_lexico->valor, "if") == 0) {
        geraCodigoExpressao(arvore->filho, output_file);
        fprintf(output_file, "\tcmp $0, %%eax\n");
        fprintf(output_file, "\tje .L%d\n", local_label);
        geraCodigoPelaAST(arvore->filho->irmao, output_file); // bloco 'then'
        fprintf(output_file, ".L%d:\n", local_label);
    } else if (strcmp(arvore->valor_lexico->valor, "while") == 0) {
        int start_label = label_counter++;
        int end_label = label_counter++;
        fprintf(output_file, ".L%d:\n", start_label);
        geraCodigoExpressao(arvore->filho, output_file);
        fprintf(output_file, "\tcmp $0, %%eax\n");
        fprintf(output_file, "\tje .L%d\n", end_label);
        geraCodigoPelaAST(arvore->filho->irmao, output_file); // bloco 'while'
        fprintf(output_file, "\tjmp .L%d\n", start_label);
        fprintf(output_file, ".L%d:\n", end_label);
    }
}

void geraCodigoRetorno(NODO* nodo, FILE *output_file){
    if(nodo->filho == NULL)
        {}
        else
    if (nodo->filho->valor_lexico->natureza == OPERAND)
        fprintf(output_file, "\tmovl\t%d(%%rbp), %%eax\n",nodo->filho->valor_lexico->deslocamento);
    else if (nodo->filho->valor_lexico->natureza == LITERAL)
            fprintf(output_file, "\tmovl\t$%s, %%eax\n",nodo->filho->valor_lexico->valor);
    fprintf(output_file, "\tmovq\t%%rbp, %%rsp\n");
    fprintf(output_file, "\tpopq\t%%rbp\n");
    fprintf(output_file, "\tret\n");
}

void geraCodigoChamadaFuncao(NODO* arvore, FILE *output_file) {
    // arvore->filho é a função
    // arvore->irmao é a lista de argumentos
    for (NODO* arg = arvore->irmao; arg != NULL; arg = arg->irmao) {
        geraCodigoPelaAST(arg, output_file);
        fprintf(output_file, "\tpush %%eax\n");
    }
    fprintf(output_file, "\tcall %s\n", arvore->filho->valor_lexico->valor);
    fprintf(output_file, "\tadd $%d, %%esp\n", 4 * contador_de_argumentos(arvore->irmao)); // Limpa a pilha
}

void geraCodigoFuncao(NODO* nodo, FILE *output_file) {
    //Inicia a declaracao da funcao
    if(section_text_func == 0)
        {
        fprintf(output_file, "\t.text\n");
        section_text_func = 1;
        }
    fprintf(output_file, "\t.globl %s\n", nodo->valor_lexico->valor);
    fprintf(output_file, "\t.type %s, @function\n", nodo->valor_lexico->valor);

    fprintf(output_file, "%s:\n", nodo->valor_lexico->valor);
    fprintf(output_file, "\tpushq \t%%rbp\n");
    fprintf(output_file, "\tmovq \t%%rsp, %%rbp\n");
    fprintf(output_file, "\tsubq \t$%d, %%rsp\n", 10 * 4); // Assumindo 4 bytes por variável e no max 10 variaveis
}

void geraCodigoExpressao(NODO *arvore, FILE *output_file) {
    if (arvore == NULL) return;

    if (arvore->valor_lexico->natureza == OPERATOR) {
        // Gerar código para operadores binários
        //geraCodigoExpressao(arvore->filho, output_file);
        //geraCodigoExpressao(arvore->irmao, output_file);
        geraCodigoOperacao(arvore, output_file);
        //fprintf(output_file, "\t// Código para operador %s\n", arvore->valor_lexico->valor);
    } else if (arvore->valor_lexico->natureza == OPERAND) {
        fprintf(output_file, "\t// movl %d(%%rip), %%eax \n", arvore->valor_lexico->deslocamento);
    } else if (arvore->valor_lexico->natureza == LITERAL) {
        fprintf(output_file, "\t// movl $%s, %%eax \n", arvore->valor_lexico->valor);
    }
}

void geraCodigoBloco(NODO *arvore, FILE *output_file) {
    fprintf(output_file, "\t// Início do bloco de comandos\n");
    for (NODO *comando = arvore->filho; comando != NULL; comando = comando->irmao) {
        geraCodigoBloco(comando, output_file);
    }
    fprintf(output_file, "\t// Fim do bloco de comandos\n");
}

/*Seleciona o proximo registrador*/
int selecionaRegistrador (int Registrador_atual){
    // algoritmo bobinho por enquanto
    Registrador_atual ++;
    if (Registrador_atual > 15)
        Registrador_atual = 8;
    
    return Registrador_atual;
}

// Função auxiliar para contar os argumentos de uma função
int contador_de_argumentos(NODO* nodo) {
    int count = 0;
    for (NODO* arg = nodo; arg != NULL; arg = arg->irmao) {
        count++;
    }
    return count;
}
