
#include "arvore.cpp"

int main( )
{
    raiz = NULL;
    int opcao = 1;

    while(opcao > 0)
    {
        tela();
        cin >> opcao;
        switch( opcao ){
            case 1:
                insere();
                break;
            case 2:
                remove();
                PAUSE();
                break;
            case 3:
                imprime();
                PAUSE();
                break;
            case 0:
                CLEAR();
                cout << "Encerrando programa" << endl;
        }
    }
}
