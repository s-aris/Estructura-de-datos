#include <stdio.h>
#define MAX 1000

int isEmpty(int top) {
    return top == -1;
}
int isFull(int top, int cap) {
    return top == cap - 1;
}

int main(void) {
    char s[MAX];
    if (!fgets(s, sizeof s, stdin)) return 0;

    char st[MAX];   // pila de abridores
    int idx[MAX];   // pila de índices
    int top = -1;

    for (int i = 0; s[i] && s[i] != '\n'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (isFull(top, MAX)) {
                printf("ERROR %d\n", i);
                return 0;
            }
            st[++top] = c;
            idx[top] = i;
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(top)) {
                printf("ERROR %d\n", i);
                return 0;
            }
            char t = st[top];
            top--;
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                printf("ERROR %d\n", i);
                return 0;
            }
        }
        // otro caracter se ignora
    }

    if (!isEmpty(top)) {
        printf("ERROR %d\n", idx[0]); 
        return 0;
    }

    printf("OK\n");
    return 0;
}
