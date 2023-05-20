#include <stdio.h>
#include <stdlib.h>

// Definirea structurii pentru stivă
typedef struct {
    int top;
    unsigned char* array;
} Stack;

// Funcția pentru crearea unei stive noi
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (unsigned char*)malloc(size * sizeof(unsigned char));
    return stack;
}

// Funcția pentru verificarea dacă stiva este goală
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Funcția pentru adăugarea unui element în vârful stivei
void push(Stack* stack, unsigned char item) {
    stack->array[++stack->top] = item;
}

// Funcția pentru eliminarea și returnarea elementului din vârful stivei
unsigned char pop(Stack* stack) {
    if (isStackEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Definirea structurii pentru coadă
typedef struct {
    int front, rear, size;
    unsigned char* array;
} Queue;

// Funcția pentru crearea unei cozi noi
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->size = 0;
    queue->rear = size - 1;
    queue->array = (unsigned char*)malloc(size * sizeof(unsigned char));
    return queue;
}

// Funcția pentru verificarea dacă coada este plină
int isQueueFull(Queue* queue) {
    return queue->size == 8;
}

// Funcția pentru verificarea dacă coada este goală
int isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// Funcția pentru adăugarea unui element în coadă
void enqueue(Queue* queue, unsigned char item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % 8;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Funcția pentru eliminarea și returnarea elementului din coadă
unsigned char dequeue(Queue* queue) {
    if (isQueueEmpty(queue))
        return '\0';
    unsigned char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % 8;
    queue->size--;
    return item;
}

// Funcția pentru adunarea a doi biți
unsigned char addBits(unsigned char bit1, unsigned char bit2, unsigned char* carry) {
    unsigned char sum = bit1 ^ bit2;
    *carry = bit1 & bit2;
    return sum;
}

// Funcția pentru scăderea a doi biți
unsigned char subtractBits(unsigned char bit1, unsigned char bit2, unsigned char* borrow) {
    unsigned char diff = bit1 ^ bit2;
    *borrow = (~bit1) & bit2;
    return diff;
}

// Funcția pentru realizarea unei operații de înmulțire (adunare repetată)
unsigned int multiply(unsigned int number1, unsigned int number2) {
    unsigned int result = 0;
    while (number2 > 0) {
        if (number2 & 1)
            result += number1;
        number1 <<= 1;
        number2 >>= 1;
    }
    return result;
}

// Funcția pentru realizarea unei operații de împărțire (scădere repetată)
unsigned int divide(unsigned int dividend, unsigned int divisor) {
    unsigned int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}

// Funcția principală
int main() {
    unsigned int number1, number2;

    printf("Introduceți primul număr natural: ");
    scanf("%u", &number1);

    printf("Introduceți al doilea număr natural: ");
    scanf("%u", &number2);

    // Convertirea numerelor în reprezentarea binară
    unsigned char bits1[32];
    unsigned char bits2[32];
    for (int i = 0; i < 32; i++) {
        bits1[i] = number1 % 2;
        bits2[i] = number2 % 2;
        number1 >>= 1;
        number2 >>= 1;
    }

    Stack* stack = createStack(32);
    Queue* queue = createQueue(32);

    // Adăugarea bitilor în stivă și coadă
    for (int i = 31; i >= 0; i--) {
        push(stack, bits1[i]);
        push(stack, bits2[i]);
        enqueue(queue, bits1[i]);
        enqueue(queue, bits2[i]);
    }

    // Adunare
    unsigned char carry = 0;
    unsigned char sumBits[32];
    for (int i = 0; i < 32; i++) {
        unsigned char bit1 = pop(stack);
        unsigned char bit2 = pop(stack);
        unsigned char sum = addBits(bit1, bit2, &carry);
        sumBits[i] = sum;
        enqueue(queue, sum);
    }
    unsigned int sum = 0;
    for (int i = 31; i >= 0; i--) {
        sum <<= 1;
        sum |= sumBits[i];
    }

    // Scădere
    unsigned char borrow = 0;
    unsigned char diffBits[32];
    for (int i = 0; i < 32; i++) {
        unsigned char bit1 = dequeue(queue);
        unsigned char bit2 = dequeue(queue);
        unsigned char diff = subtractBits(bit1, bit2, &borrow);
        diffBits[i] = diff;
        push(stack, diff);
    }
    unsigned int diff = 0;
    for (int i = 31; i >= 0; i--) {
        diff <<= 1;
        diff |= diffBits[i];
    }

    // Înmulțire
    unsigned int product = multiply(number1, number2);

    // Împărțire
    unsigned int quotient = divide(number1, number2);

    printf("Rezultatele operațiilor:\n");
    printf("Adunare: %u\n", sum);
    printf("Scădere: %u\n", diff);
    printf("Înmulțire: %u\n", product);
    printf("Împărțire: %u\n", quotient);

    // Eliberarea memoriei
    free(stack->array);
    free(stack);
    free(queue->array);
    free(queue);

    return 0;
}
