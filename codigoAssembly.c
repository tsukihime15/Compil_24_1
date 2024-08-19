#include "codigoAssembly.h"

int Registrador_atual = 7; 
int section_data = 0; //para variaveis globais e constantes
/*chamada uma vez so na raiz da AST*/

void generateAsm(NODO* arvore){

    FILE *output_file = stdout;

    /*Cabecalho do arquivo .asm*/
    fprintf(output_file, ".file   \"main.c\"\n\t.text\n\t.globl  main\n\t.type   main, @function\nmain:\n");
    fprintf(output_file,"\tpushq   %%rbp\n\tmovq    %%rsp, %%rbp\n\tsubq    $32, %%rsp\n");
    
    //printf("1\n"); // debug

    geraCodigoPelaAST(arvore, output_file);

    /*Final do arquivo .asm*/
    fprintf(output_file, "\tmovq    %%rbp, %%rsp\n\tpopq    %%rbp\n\tret\n");

    if (output_file != stdout) 
        fclose(output_file);
}

void geraCodigoPelaAST(NODO* nodo, FILE* output_file){

    if (nodo == NULL) return; 

    if (!nodo || nodo->visitado) return;
    nodo->visitado = 1;

//Inicia a declaracao de Var Globais
    if(nodo->valor_lexico->natureza == GLOBAL_DECL && section_data == 0)
        {
        fprintf(output_file, "section .data\n");
        section_data = 1;
        }
    switch (nodo->valor_lexico->natureza) {
        case LITERAL:
            // Código para um literal
            //geraCodigo(nodo, output_file);
            break;

        case GLOBAL_DECL:
            // Código para um literal
            geraCodigoVarGlobal(nodo, output_file);
            break;

        case VARIABLE:
            // Código para uma variavel
            //geraCodigo(nodo, output_file);
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
            //geraCodigo(nodo, output_file);
            break;

        case FUNCTION_CALL:
            // Código para uma chamada de função
            //geraCodigoChamadaFuncao(nodo, output_file);
            break;

        case FUNCTION:
            // Código para uma função
            //geraCodigoFuncao(nodo, output_file);
            break;

        default:
            break;
    }

    // Percorre toda a arvore
    geraCodigoPelaAST(nodo->filho, output_file);
    geraCodigoPelaAST(nodo->irmao, output_file);

}

void geraCodigoVarGlobal(NODO* arvore, FILE* output_file){
    
    fprintf(output_file, "\t%s resd 1\n",arvore->valor_lexico->valor);
}

void geraCodigoAtrib(NODO* arvore, FILE *output_file) {
    // arvore->filho eh o identificador
    // arvore->irmao eh a expressao
    fprintf(output_file, "\t// Código para atribuição\n");
    geraCodigoExpressao(arvore->irmao, output_file);
    fprintf(output_file, "\t// Código para armazenar o valor em %s\n", arvore->filho->valor_lexico->valor);

}

void geraCodigoOperacao(NODO* arvore, FILE *output_file){

}

void geraCodigoControle(NODO* arvore, FILE *output_file){

}

void geraCodigoChamadaFuncao(NODO* arvore, FILE *output_file) {
    fprintf(output_file, "\t// Código para chamada de função\n");
    // arvore->filho é a função
    // arvore->irmao é a lista de argumentos
    fprintf(output_file, "\tcall %s\n", arvore->valor_lexico->valor);
}

void geraCodigoFuncao(NODO* nodo, FILE *output_file) {
    fprintf(output_file, "\t.globl %s\n", nodo->valor_lexico->valor);
    fprintf(output_file, "\t.type %s, @function\n", nodo->valor_lexico->valor);
    fprintf(output_file, "%s:\n", nodo->valor_lexico->valor);
    fprintf(output_file, "\tpushq %%rbp\n");
    fprintf(output_file, "\tmovq %%rsp, %%rbp\n");
    //fprintf(output_file, "\tsubq $%d, %%rsp\n", quantasVarNaLista(nodo) * 4); // Assumindo 4 bytes por variável
}

void geraCodigoExpressao(NODO *arvore, FILE *output_file) {
    if (arvore->valor_lexico->natureza == OPERATOR) {
        // Gerar código para operadores binários
        geraCodigoExpressao(arvore->filho, output_file);
        geraCodigoExpressao(arvore->irmao, output_file);
        fprintf(output_file, "\t// Código para operador %s\n", arvore->valor_lexico->valor);
    } else if (arvore->valor_lexico->natureza == VARIABLE) {
        fprintf(output_file, "\t// Código para variável %s\n", arvore->valor_lexico->valor);
    } else if (arvore->valor_lexico->natureza == LITERAL) {
        fprintf(output_file, "\t// Código para literal %s\n", arvore->valor_lexico->valor);
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