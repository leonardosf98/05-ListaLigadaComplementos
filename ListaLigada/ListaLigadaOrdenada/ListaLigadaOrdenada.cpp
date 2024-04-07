#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}
void inserirElemento()
{
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;

    if (posicaoElemento(novo->valor) != NULL) {
        cout << "Esse valor ja se encontra na lista\n";
        free(novo);
        return;
    }

    novo->prox = NULL;

    if (primeiro == NULL)
    {
        primeiro = novo;
        ultimo = novo;
        return; 
    }
    
    if (novo->valor < primeiro->valor) { 
        novo->prox = primeiro;
        primeiro = novo;
        return;
    }

    NO* anterior = primeiro;
    NO* atual = primeiro->prox;

    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novo;
    novo->prox = atual;

    if (atual == NULL) { 
        ultimo = novo;
    }
}


void excluirElemento()
{
    int valueToDelete = 0;
    cout << "Digite o valor a ser deletado: ";
    cin >> valueToDelete;

    if (primeiro == NULL) {
        cout << "A lista esta vazia\n";
        return;
    }

    NO* anterior = NULL;
    NO* atual = primeiro;

    while (atual != NULL && atual->valor < valueToDelete) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor != valueToDelete) {
        cout << "O valor nao foi encontrado para ser deletado\n";
        return;
    }

    if (anterior == NULL) { 
        primeiro = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    if (atual == ultimo) { 
        ultimo = anterior;
    }

    free(atual);
    cout << "Valor excluido com sucesso\n";
}

void buscarElemento()
{
    int valueToFind = 0;
    cout << "Digite um valor para ser buscado: ";
    cin >> valueToFind;

    NO* result = buscaBinaria(valueToFind);

    if (result != NULL && result->valor == valueToFind) {
        cout << "O valor foi encontrado\n";
    } else {
        cout << "O valor nao foi encontrado\n";
    }
}

NO* buscaBinaria(int valor)
{
    NO* inicio = primeiro;
    NO* fim = ultimo;

    while (inicio != NULL && inicio->valor <= fim->valor)
    {
        NO* meio = meioDaLista(inicio, fim);

        if (meio->valor == valor)
            return meio;
        else if (meio->valor < valor)
            inicio = meio->prox;
        else
            fim = meio;

    }

    return NULL;
}

NO* meioDaLista(NO* inicio, NO* fim)
{
    NO* slow = inicio;
    NO* fast = inicio->prox;

    while (fast != fim)
    {
        fast = fast->prox;
        if (fast != fim)
        {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    return slow;
}


NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

