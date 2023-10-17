#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

template<class elemType>
class linkQueue{
    struct Node{
        elemType data;
        Node *next;
        Node(const elemType &x, Node *N = NULL){
            data = x;
            next = N;
        }
        Node():next(NULL){}
        ~Node(){}
    };
    Node *head;
    Node *tail;
public:
    linkQueue();
 //   ~linkQueue();
    bool isEmpty();
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType top();
};

template<class elemType>
linkQueue<elemType>::linkQueue(){
    head = NULL;
    tail = NULL;
}

/*template<class elemType>
linkQueue<elemType>::~linkQueue(){
    Node *tmp;
    while(head != NULL){}
    tmp = head;
    head = head -> next;
    delete tmp;
}*/

template<class elemType>
bool linkQueue<elemType>::isEmpty(){
    return head == NULL;
}

template<class elemType>
void linkQueue<elemType>::enQueue(const elemType &x){
    if(tail == NULL){
        head = tail = new Node(x);
    }
    else{
        tail = tail -> next = new Node(x);
    }
}

template<class elemType>
elemType linkQueue<elemType>::deQueue(){
    Node *tmp = head;
    elemType ret = head -> data;
    head = head -> next;
    if(head == NULL){
        tail = NULL;
    }
    delete tmp;
    return ret;
}

template<class elemType>
elemType linkQueue<elemType>::top(){
    return head -> data;
}

template<class elemType>
class binaryTree{
    struct Node{
        elemType data;
        Node *left, *right;
        Node(const elemType &x, Node *L = NULL, Node *R = NULL){
            data = x;
            left = L;
            right = R;
        }
        Node():left(NULL), right(NULL){}
        ~Node(){}
    };
    Node *root;
public:
    binaryTree();
    ~binaryTree();
    void clear(Node *t);
    bool isEmpty();
    void levelOrder();
    void createTree(int x[], int n);
};

template<class elemType>
binaryTree<elemType>::binaryTree(){
    root = NULL;
}

template<class elemType>
binaryTree<elemType>::~binaryTree(){
    clear(root);
}

template<class elemType>
void binaryTree<elemType>::clear(Node *t){
    if(t == NULL){
        return;
    }
    else{
        clear(t->left);
        clear(t->right);
        delete t;
        t = NULL;
    }
}

template<class elemType>
bool binaryTree<elemType>::isEmpty(){
    return root == NULL;
}

template<class elemType>
void binaryTree<elemType>::levelOrder(){
    linkQueue<Node *> que;
    Node *tmp;
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        cout << 0 << endl;
        return;
    }
    que.enQueue(root);
    int level = 0;
    int wpl = 0;
    int ctrlvl = 0;
    while(!que.isEmpty()){
        if(ctrlvl == pow(2,level)){
            level++;
            ctrlvl = 0;
        }
        ctrlvl++;
        if(que.isEmpty()){
            continue;
        }
        tmp = que.deQueue();
        // cout << tmp -> data << " ";
        if(tmp -> data >0){
            wpl += tmp -> data * level;
        }
        if(tmp -> left){
            que.enQueue(tmp -> left);
        }
        if(tmp -> right){
            que.enQueue(tmp -> right);
        }
    }
    cout << wpl << endl;
}

template<class elemType>
void binaryTree<elemType>::createTree(int x[], int n){
    if(n == 0){
        root = NULL;
        return;
    }
    linkQueue<Node* > que;
    Node *tmp;
    root = new Node(x[0]);
    que.enQueue(root);
    int i = 1;
    while(i < n){
        tmp = que.deQueue();
        if(i < n) {
            tmp->left = new Node(x[i]);
            que.enQueue(tmp->left);
            i++;
        }
        if(i < n){
            tmp -> right = new Node(x[i]);
            que.enQueue(tmp -> right);
            i++;
        }
    }
}

int main(){
    binaryTree<int> Tree;
    string cmd = "";
    getline(cin, cmd);
    int pos1 = 0;
    int pos2 = 0;
    int input[100];
    int n = 0;
    cmd = cmd + ' ';
    while(true){
        pos2 = cmd.find(' ',pos1);
        if(pos2 == -1){
            break;
        }
        else{
            input[n] = stoi(cmd.substr(pos1,pos2-pos1));
            n++;
            pos1 = pos2+1;
        }
    }
    Tree.createTree(input,n);
    Tree.levelOrder();
    return 0;
}