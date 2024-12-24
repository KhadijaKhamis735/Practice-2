struct stackNode {
    int data;
    struct stackNode *next;
};

struct stackNode *top = NULL;

void push(int value) {
    struct stackNode *newnode = (struct stackNode *)malloc(sizeof(struct stackNode));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto the stack.\n", value);
}
void displayStack() {
    struct stackNode *temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
