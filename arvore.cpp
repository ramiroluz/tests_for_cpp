
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;

#ifdef _WIN32
    #define CLEAR() system("cls")
#else
    #define CLEAR() system("clear")
#endif

#define PAUSE() cin.clear(); cin.get()

struct node
{
    int info;
    struct node *esquerdo;
    struct node *direito;
};

int numero_de_nos = 0;

queue< node* > node_queue;

node *raiz;

int le_info()
{
    int info;
    CLEAR();
    cout << "Digite um valor inteiro: ";
    cin >> info;
    return info;
}

int arvore_insere(int info)
{
    node *novo = new node;
    node *aux = new node;
    node *pai = new node;

    novo->info = info;
    novo->esquerdo = NULL;
    novo->direito = NULL;

    if(raiz == NULL) raiz=novo;
    else
    {
        aux = raiz;
        while(aux)
        {
            pai = aux;
            if( novo->info < aux->info )
            {
                aux = aux->esquerdo;
            }
            else
            {
                aux = aux->direito;
            }
        }
        if(novo->info > pai->info)
        {
            pai->direito = novo;
        }
        else
        {
            pai->esquerdo = novo;
        }
    }
    numero_de_nos++;
    return novo->info;
}

void insere()
{
    int info;
    info = le_info();
    arvore_insere(info);
}

int arvore_remove(int info)
{
    int retorno = 0;
    if(raiz)
    {
        node *no = new node;
        node *aux = new node;
        node *pai = new node;

        no = raiz;
        pai = NULL;
        while(no)
        {
            if(no->info == info) break;
            else
            {
                pai = no;
                if(info > no->info) no = no->direito;
                else no = no->esquerdo;
            }
        }

        // Remoção por fusão.
        if (no)
        {
            // Remove a raiz.
            if(no->info == raiz->info)
            {
                retorno = raiz->info; // O nó removido é a própria raiz.
                if ((no->direito == NULL) && (no->esquerdo == NULL)) raiz = NULL;
                else
                {
                    if (no->direito==NULL) raiz = no->esquerdo;
                    else
                    {
                        if (no->esquerdo==NULL) raiz = no->direito;
                        else
                        {
                            raiz = no->esquerdo;
                            aux=no->esquerdo;
                            while (aux->direito) aux=aux->direito;

                            aux->direito = no->direito;
                        }
                    }
                }
            }
            else
            {
                retorno = no->info;
                // Testa se é nó folha.
                if ((no->direito == NULL) && (no->esquerdo == NULL))
                {
                    // Testa se é filho da direita ou da esquerda.
                    if(no->info > pai->info) pai->direito = NULL;        // Direito
                    else pai->esquerdo = NULL;                           // Esquerdo
                }
                else
                {
                    if (no->direito==NULL)
                    {
                        // Testa se é filho da direita ou da esquerda.
                        if(no->info > pai->info) pai->direito = no->esquerdo; // Direito
                        else pai->esquerdo = no->esquerdo;                    // Esquerdo
                    }
                    else
                        if (no->esquerdo==NULL)
                        {
                            // Testa se é filho da direita ou da esquerda.
                            if(no->info > pai->info) pai->direito = no->direito; // Direito
                            else pai->esquerdo = no->direito;                    // Esquerdo
                        }
                        else {
                            aux=no->esquerdo;
                            while (aux->direito) aux=aux->direito;

                            // Testa se é filho da direita ou da esquerda.
                            if(no->info > pai->info) pai->direito = no->esquerdo; // Direito
                            else pai->esquerdo = no->esquerdo;                     // Esquerdo
                            aux->direito = no->direito;
                        }
                }
                delete no;
            }
            numero_de_nos--;
        }
        else
        {
            cout << info << "Nao consta na arvore" << endl;
            PAUSE();
        }
    }
    else
    {
        cout << "Arvore vazia, nada para remover" << endl;
        PAUSE();
    }
    return retorno;
}

void remove()
{
    int info;
    info = le_info();
    arvore_remove(info);
}


string arvore_texto()
{
    ostringstream impressao;
    int contador = 0;

    if(raiz)
    {
        node* aux;

        impressao << "Impressao" << endl;
        impressao << "Raiz: " << raiz->info << " FE: ";
        if(raiz->esquerdo)
        {
            node_queue.push(raiz->esquerdo);
            impressao << raiz->esquerdo->info;
        }
        else impressao << -1;
        impressao << " FD: ";
        if(raiz->direito)
        {
            impressao << raiz->direito->info;
            node_queue.push(raiz->direito);
        }
        else impressao << -1;
        impressao << endl;
        contador++;

        while(!node_queue.empty())
        {
            aux = node_queue.front();
            node_queue.pop();
            impressao << "No: " << aux->info << " FE: ";
            if(aux->esquerdo) {
                impressao << aux->esquerdo->info;
                node_queue.push(aux->esquerdo);
            }
            else impressao << -1;
            impressao << " FD: ";
            if(aux->direito)
            {
                impressao << aux->direito->info;
                node_queue.push(aux->direito);
            }
            else impressao << -1;
            impressao << endl;
            contador++;
            if(contador > numero_de_nos)
            {
                std::stringstream out;
                out << contador;
                return "ERRO IMPRESSAO ENTROU EM LOOP INFINITO" + out.str();
            }
        }
    }
    else impressao << "Arvore vazia, nada para imprimir" << endl;
    return impressao.str();
}

void imprime()
{
    CLEAR();
    cout << arvore_texto();
    PAUSE();
    //cin.clear();
    //getchar();
}

void tela()
{
    CLEAR();
    cout << "    ==       MENU PRINCIPAL        ==" << endl;
    cout << "    =================================" << endl;
    cout << "    ==    1 - Insercao na arvore   ==" << endl;
    cout << "    ==    2 - Remocao da arvore    ==" << endl;
    cout << "    ==    3 - Imprime a arvore     ==" << endl;
    cout << "    ==    0 - Sair                 ==" << endl;
    cout << "    =================================" << endl;
    cout << "    Escolha uma opcao, usando numeros de 0 a 3" << endl;
}

