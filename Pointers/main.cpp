using namespace std;
#include <iostream>

struct Node{
    int data;
    Node *next;

};


Node* InsertAtBeginning(Node *list, int value){
    Node *newNode = new Node();
    newNode ->data = value;
    newNode ->next = list;
    return newNode;
}

void display(Node *list){
    Node *temp = list;
    while (temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next;
    }

}
void InsertAtPosition(Node *list, int value, int position){
    //verificando posiçoes 1 e 0
    if (position==0){
        cout << "Impossivel inserir na posicao";
    } else if (position==1){
        list = InsertAtBeginning(list, value);
    }

    Node *newNode= new Node();
    newNode->data=value;

    Node *preview=NULL;
    Node *temp=list;
    int position_counter=0;
    while(position_counter != position){
        preview = temp;
        temp = temp->next;
        position_counter++;
    }
    
    preview->next= newNode;
    newNode->next=temp;
}

void search(Node *list, int value){
    Node *temp = list;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->data==value){
            found= true;
            break;
        }
        temp = temp->next;
    }
    if (found){
        cout << value << "Encontrado";
    }else {
        cout << value << "Nao encontrado";
    }
    
}

void deleteElement(Node *list, int value){
    Node *preview = NULL;
    Node *temp = list;
    
    // É o primeiro elemento
    if (temp->data == value){
        list = temp->next;
        delete temp;
        return;
    }
    
    while (temp !=NULL)
    {
       if (temp->data == value)
       {
        preview->next= temp->next;
        break;
       }
       preview = temp;
       temp = temp->next;
    }

    if (temp == NULL){
        cout << "Valor nao encontrado"<< endl;
    }
    
}


int main () {
    
    Node *list=NULL;
    int n_elements;
         //inserindo elementos no começo da lista
    cout << "Digite o numero de elementos da lista: ";
    cin >> n_elements;
    for(int i=0; i < n_elements; i++) {
        int value;
        cout << "Digite o valor do elemento [" << i << "]: \n";
        cin >> value;
        list = InsertAtBeginning(list, value);
    }

        //percorrendo a lista
    cout << "----------------------------\n";
    cout << "Lista: ";
    display(list);

        //inserindo elemento em uma posição específica
    int value, position;
    cout << "----------------------------\n";
    cout << "Digite a posicao que o valor sera inserido: ";
    cin >> position;
    cout << "Digite o valor a ser inserido: ";
    cin >> value;
    InsertAtPosition(list, value, position);

        //percorrer lista depois da inserção
    cout << "----------------------------\n";
    cout << "Lista apos inserir o valor: " ;
    display(list);

        //procurando elementos na lista
    cout << "----------------------------\n";
    cout << "Digite um valor para buscar na lista: ";
    cin >> value;
    search (list, value);

        //deletando elemento da lista
    cout << "----------------------------\n";
    cout << "Digite um valor para deletar da lista: ";
    cin >> value;   
    deleteElement(list, value);
    
    cout << "----------------------------\n";
    cout << "Lista apos deletar o valor: ";
    display(list);
    return 0;
}
