// Google GTest Framework Example
// To COMPILE IT
// g++ test_arvore.cpp -lgtest_main -pthread -o test_arvore
// TO RUN
// ./test_arvore
//
// TO FILTER TEST EXECUTION
// ./test_arvore --gtest-filter=ArvoreTest.Insere
//

#include <gtest/gtest.h>
#include "arvore.cpp"

namespace {

// The fixture for testing class Arvore.
class ArvoreTest : public ::testing::Test {
 protected:
  ArvoreTest() {
    // You can do set-up work for each test here.
  }

  virtual ~ArvoreTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    node* aux;
    node* pai;
    aux = raiz;
    pai = aux;
    while(aux)
    {
        if((aux->esquerdo == NULL) && (aux->direito==NULL)) 
        {
            if(aux->info == raiz->info) aux = raiz = NULL;
            else
            {
                if(aux->info > pai->info) pai->direito = NULL;
                else pai->esquerdo = NULL;
                delete aux;
                aux = raiz;
                pai = aux;
            }
        }
        else
        {
            pai = aux;
            if(aux->esquerdo == NULL) aux = aux->direito;
            else aux = aux->esquerdo;
        }
    }
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};


TEST_F (ArvoreTest, Insere) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 1 FE: -1 FD: 2" << endl;
    impressao << "No: 2 FE: -1 FD: 3" << endl;
    impressao << "No: 3 FE: -1 FD: -1" << endl;

    arvore_insere (1);
    arvore_insere (2);
    arvore_insere (3);
    //arvore_insere(15); // ERRO PROPOSITAL
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, CriaArvoreAltura3) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 3 FD: 7" << endl;
    impressao << "No: 3 FE: 1 FD: 4" << endl;
    impressao << "No: 7 FE: 6 FD: 9" << endl;
    impressao << "No: 1 FE: -1 FD: 2" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;
    impressao << "No: 6 FE: -1 FD: -1" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 2 FE: -1 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (3);
    arvore_insere (1);
    arvore_insere (7);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (6);
    arvore_insere (8);
    //arvore_insere(15); // ERRO para demonstração
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNo2FilhosEsquerda) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 1 FD: 7" << endl;
    impressao << "No: 1 FE: -1 FD: 2" << endl;
    impressao << "No: 7 FE: 6 FD: 9" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 6 FE: -1 FD: -1" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (3);
    arvore_insere (1);
    arvore_insere (7);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (6);
    arvore_insere (8);
    arvore_remove (3);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNo2FilhosDireita) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 1 FD: 6" << endl;
    impressao << "No: 1 FE: -1 FD: 2" << endl;
    impressao << "No: 6 FE: -1 FD: 9" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (1);
    arvore_insere (7);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (6);
    arvore_insere (8);
    arvore_remove (7);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoSubEsq1FilhoNaDireita) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 2 FD: 6" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 6 FE: -1 FD: 9" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (1);
    arvore_insere (6);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (8);
    arvore_remove (1);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoSubDir1FilhoNaDireita) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 2 FD: 9" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (6);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (8);
    arvore_remove (6);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizComSubArvoreDir) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 4 FE: -1 FD: 9" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (9);
    arvore_insere (8);
    arvore_remove (2);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoSubArvoreDirFilhoEsq) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 4 FE: -1 FD: 8" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (4);
    arvore_insere (9);
    arvore_insere (8);
    arvore_remove (9);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizComSubArvoreEsq) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (2);
    arvore_insere (4);
    arvore_remove (5);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizComUltimoFilhoEsq) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 2 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (2);
    arvore_remove (5);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizComUltimoFilhoDir) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 4 FE: -1 FD: -1" << endl;

    arvore_insere (2);
    arvore_insere (4);
    arvore_remove (2);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizCom2Filhos) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 4 FE: -1 FD: 9" << endl;
    impressao << "No: 9 FE: 8 FD: -1" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (8);
    arvore_remove (5);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoSubDir1FilhoNaEsquerda) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 2 FD: 8" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 8 FE: -1 FD: -1" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (9);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (8);
    arvore_remove (9);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoFolhaSubDirSemFilhos) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 2 FD: -1" << endl;
    impressao << "No: 2 FE: -1 FD: 4" << endl;
    impressao << "No: 4 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (2);
    arvore_insere (4);
    arvore_insere (8);
    arvore_remove (8);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveNoSubEsqSemFilhos) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: 2 FD: -1" << endl;
    impressao << "No: 2 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (2);
    arvore_insere (4);
    arvore_remove (4);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveUltimoNoSubEsq) {
    ostringstream impressao;

    impressao << "Impressao" << endl;
    impressao << "Raiz: 5 FE: -1 FD: -1" << endl;

    arvore_insere (5);
    arvore_insere (2);
    arvore_remove (2);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

TEST_F (ArvoreTest, RemoveRaizSemFilhos) {
    ostringstream impressao;

    impressao << "Arvore vazia, nada para imprimir" << endl;

    arvore_insere (5);
    arvore_remove (5);
    ASSERT_EQ (impressao.str(), arvore_texto());
}

} // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

