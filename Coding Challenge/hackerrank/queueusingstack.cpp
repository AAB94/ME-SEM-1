#include<iostream>
using namespace std;

struct stack{
    int top;
    int arr[100010];
    int n;
};
stack s1,s2;

void push(stack *s,int x){
    s->top = s->top + 1;
    s->arr[s->top] = x;
    s->n = s->n + 1;
}

int pop(stack *s){
    int x = s->arr[s->top];
    s->top = s->top - 1;
    s->n = s->n - 1;
    return x;
}

void dequeue(){
    int i = 0,x;
    for(i = s1.n-1 ; i > 0; --i){
        x = pop(&s1);
        push(&s2,x);
    }
    i = pop(&s1);
    for( i = s2.n; i > 0; --i){
        x = pop(&s2);
        push(&s1,x);
    }
}


int main(){
    int q,t,x;
    cin>>q;
    int i;
    s1.top = -1;
    s1.n = 0;
    s2.top = -1;
    s2.n = 0;
    for(i=0;i<q;++i){
        cin>>t;
        switch(t){
            case 1:
                cin>>x;
                push(&s1,x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout<<s1.arr[0]<<endl;
                break;
        }
    }
    return 0;
}
