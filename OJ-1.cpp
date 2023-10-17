#include<iostream>
#include<string>
using namespace std;

template<class elemType>
class linkStack{
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };
    node *top_p;
public:
    linkStack();
    ~linkStack();
    bool isEmpty();
    void push(const elemType &x);
    elemType pop();
    elemType top();
    void cetak();
};

template<class elemType>
linkStack<elemType>::linkStack(){
    top_p = NULL;
}

template<class elemType>
linkStack<elemType>::~linkStack(){
    node *tmp;
    while(top_p != NULL){
        tmp = top_p;
        top_p = top_p -> next;
        delete tmp;
    }
}

template<class elemType>
bool linkStack<elemType>::isEmpty(){
    return top_p == NULL;
}

template<class elemType>
void linkStack<elemType>::push(const elemType &x){
    top_p = new node(x, top_p);
}

template<class elemType>
elemType linkStack<elemType>::pop(){
    node *tmp = top_p;
    top_p = top_p->next;
    delete tmp;
    return 0;
}

template<class elemType>
elemType linkStack<elemType>::top(){
    if(top_p->data == NULL){
        return NULL;
    }
    else{
        return top_p-> data;
    }
}

template<class elemType>
void linkStack<elemType>::cetak(){
    node *tmp = top_p;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void parseBoolExpr(string expression) {
// TODO, finish your algorithm here
    linkStack<char> st, output;
    int size = expression.size();
    char ch;
    for(int i = 0; i < size; i++){
        ch = expression[i];
        if(ch == 't' || ch == 'f'){
            output.push(ch);
        }
        else if(ch == ')'){
            int jf = 0;
            int jt = 0;
            while(!st.isEmpty()){
                if(st.top() != '('){
                    char apa = output.top();
                    if(apa == 't'){
                        jt++;
                    }
                    else{
                        jf++;
                    }
                    output.pop();
                    st.pop();
                }
                else{
                    char apa = output.top();
                    if(apa == 't'){
                        jt++;
                    }
                    else{
                        jf++;
                    }
                    output.pop();
                    st.pop();
                    break;
                }
            }
            //cout << "jf :" << jf << endl;
            //cout << "jt :" << jt << endl;
            char tanda = st.top();
            // cout << "Tanda = " << tanda << endl;
            if (tanda=='!'){
                if (jf==0){
                    output.push('f');
                }else{
                    output.push('t');
                }
                st.pop();
            }else if (tanda=='&'){
                if (jf==0){
                    output.push('t');
                }else{
                    output.push('f');
                }
                st.pop();
            }else if (tanda=='|'){
                if (jt==0){
                    output.push('f');
                }else{
                    output.push('t');
                }
                st.pop();
            }
        }
        else{
            st.push(ch);
        }
        //cout<<"  stack  : "; st.cetak();
        //cout<<"  output : "; output.cetak();
    }
    //cout<<"hasil : "<<output.top()<<endl;
    if (output.top() == 'f'){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
}
int main () {
    string expression;
    cin >> expression;
    parseBoolExpr(expression);
    return 0;
}