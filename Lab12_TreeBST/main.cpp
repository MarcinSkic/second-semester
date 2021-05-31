#include <iostream>

using namespace std;
struct node{
    int key;
    node* parent;
    node* left;
    node* right;
};
node* make_node(int value){
    node * n = new node;
    n->key = value;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}
void add_node(int value, node* &root){

    if(root == nullptr){
        root=make_node(value);
        return;
    }

    node * temp = root;
    while(true){
        if(value >= temp->key){
            if(temp->right==nullptr){
                temp->right=make_node(value);
                temp->right->parent=temp;
                return;
            } else {
                temp=temp->right;
            }
        } else {
            if(temp->left==nullptr){
                temp->left=make_node(value);
                temp->left->parent=temp;
                return;
            } else {
                temp=temp->left;
            }
        }
    }
}
void preorder(node * root){
    if(root != nullptr){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
void inorder(node* root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
node* find_node(node* root,int value){
    while(root != nullptr){
        if(root->key == value){
            return root;
        }
        if(value>root->key){
            root=root->right;
        } else {
            root = root->left;
        }
    }
    return nullptr;
}
node* find_successor(node* n){
    if(n->right != nullptr){
        n=n->right;
        while(n->left != nullptr){
            n=n->left;
        }
        return n;
    }
    node *temp=n->parent;
    while(temp != nullptr && temp->left != n){
        n = temp;
        temp = temp->parent;
    }
    return temp;
}
node* delete_node(node * &root,node* delete_node){
    node *temp1, *temp2;
    if(delete_node->left == nullptr || delete_node -> right == nullptr){
        temp1=delete_node;
    } else {
        temp1=find_successor(delete_node);
    }

    if(temp1->left!= nullptr){
        temp2=temp1->left;
    } else {
        temp2=temp1->right;
    }

    if(temp2 != nullptr){
        temp2->parent=temp1->parent;
    }

    if(temp1->parent == nullptr){
        root=temp2;
    } else {
        if(temp1 == temp1->parent->left){
            temp1->parent->left=temp2;
        } else {
            temp1->parent->right=temp2;
        }
    }

    if(temp1 != delete_node){
        delete_node->key=temp1->key;
    }
    delete temp1;
}
bool isEmpty(node *root){
    if(root == nullptr){
        return true;
    } else {
        return false;
    }
}
void choice1(node *root){
    if(isEmpty(root)){
        cout<<"Drzewo jest puste"<<endl;
    } else {
        cout<<"Drzewo zawiera elementy"<<endl;
    }
}
void choice2(node* &root){

    int value;

    cout<<endl<<"Drzewo przed dodaniem: ";
    inorder(root);
    cout<<endl;

    cout<<endl<<"Podaj wartosc do dodania: ";
    cin>>value;

    if(find_node(root,value) != nullptr){
        cout<<"Wezel o takiej wartosci juz istnieje!"<<endl;
        return;
    }

    add_node(value,root);

    cout<<endl<<"Drzewo po dodaniu: ";
    inorder(root);
    cout<<endl;
}
void choice3(node* root){
    int value;

    if(isEmpty(root)){
        cout<<"Drzewo jest puste"<<endl;
        return;
    }

    cout<<endl<<"Podaj wartosc do znalezienia: ";
    cin>>value;

    if(find_node(root,value) != nullptr){
        cout<<"Wezel o takiej wartosci istnieje"<<endl;
    } else {
        cout<<"Wezel o takiej wartosci nie istnieje"<<endl;
    }
}
void choice4(node* root){
    cout<<endl<<"Drzewo preorder: ";
    preorder(root);
    cout<<endl;
}
void choice5(node* root){
    cout<<endl<<"Drzewo inorder: ";
    inorder(root);
    cout<<endl;
}
void choice6(node* root){
    cout<<endl<<"Drzewo postorder: ";
    postorder(root);
    cout<<endl;
}
void choice7(node* &root){
    int value;
    node *searched;

    if(isEmpty(root)){
        cout<<"Drzewo jest puste"<<endl;
        return;
    }

    cout<<endl<<"Drzewo przed usunieciem: ";
    inorder(root);
    cout<<endl;

    cout<<endl<<"Podaj wartosc do usuniecia: ";
    cin>>value;

    searched = find_node(root,value);
    if(searched == nullptr){
        cout<<"Wezel o takiej wartosci nie istnieje!"<<endl;
        return;
    }

    delete_node(root,searched);

    cout<<endl<<"Drzewo po usunieciu: ";
    inorder(root);
    cout<<endl;
}
void deleteHelper(node* &root){
    if(root != nullptr){
        deleteHelper(root->left);
        deleteHelper(root->right);
        delete root;
    }
    root = nullptr;
}
void choice8(node * &root){
    deleteHelper(root);
}
int main()
{

    node* tree = nullptr;

    int choice;

    while(true){
        cout<<"Co chcesz zrobic: "<<endl
        <<"\tSprawdzic czy drzewo jest puste - 1"<<endl
        <<"\tDodac nowy wezel do drzewa - 2"<<endl
        <<"\tSprawdzic czy wezel o podanej wartosci znajduje sie w drzewie - 3"<<endl
        <<"\tWyswietlenie drzewa preorder - 4"<<endl
        <<"\tWyswietlenie drzewa inorder - 5"<<endl
        <<"\tWyswietlenie drzewa postorder - 6"<<endl
        <<"\tUsuniecie wezla o podanej wartosci - 7"<<endl
        <<"\tUsuniecie calego drzewa - 8"<<endl
        <<"\tWyjsc - 9"<<endl;

        fflush(stdin);
        cout<<"Podaj swoj wybor: ";
        cin>>choice;

        switch (choice){
            case 1:
                choice1(tree);
                break;
            case 2:
                choice2(tree);
                break;
            case 3:
                choice3(tree);
                break;
            case 4:
                choice4(tree);
                break;
            case 5:
                choice5(tree);
                break;
            case 6:
                choice6(tree);
                break;
            case 7:
                choice7(tree);
                break;
            case 8:
                choice8(tree);
                break;
            case 9:
                return 0;
            default:
                cout<<"Zly wybor, sprobuj jeszcze raz";
                break;
        }
    }

    return 0;
}
