/**
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{
	QueueType *cQ = createQueue();
	element data;
	char command;

	do{
		printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}

QueueType *createQueue() //큐를 생성합니다
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement() //값을 입력받습니다.
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ) // 큐가 비어 있는지를 체크하는 함수입니다. 
{
    return (cQ->front == cQ->rear);
}


/* complete the function */
int isFull(QueueType *cQ) // 큐가 가득 찼는지를 확인하는 큐 입니다.
{
    return ((cQ->rear + 1) % MAX_QUEUE_SIZE == cQ->front);
}



/* complete the function */
void enQueue(QueueType *cQ, element item) // 큐에 입력을 받아 추가를 하는 함수입니다.
{
    if (isFull(cQ)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
    cQ->queue[cQ->rear] = item;
}


/* complete the function */ 
void deQueue(QueueType *cQ, element *item) // 큐에서 제거를 시키는 함수입니다.
{
    if (isEmpty(cQ)) {
        printf("큐가 이미 비어있습니다.\n");
        *item = '\0';
        return;
    }
    cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
    *item = cQ->queue[cQ->front];
}



void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first; // 큐의 값을 출력합니다.
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}


