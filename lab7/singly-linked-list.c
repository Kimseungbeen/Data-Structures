/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode)); //malloc 을 통해 할당을 한다
	temp->first = NULL; //first 필드 NULL
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //노드할당을 받아 키에 입력을한다.
	node->key = key;

	node->link = h->first; //입력받은 노드의 링크를 헤드의 퍼스트로 바꾼다.
	h->first = node;

	return 0;
}


/**
 * 리스트에서 key보다 큰 값을 가지는 노드 바로 앞에 삽입
 */
int insertNode(headNode* h, int key) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->key = key;
    newNode->link = NULL;

    if (h->first == NULL || key < h->first->key) { // 비어있거나 첫번째 노드의 키값이 새로운 키값보다 클 경우
        newNode->link = h->first;
        h->first = newNode;
        return 0;
    }

    listNode* curr = h->first; 
    while (curr->link != NULL && curr->link->key < key) {  // 리스트를 돌며 새로운 값보다 큰값을 찾아 삽입한다.
        curr = curr->link;
    }
    newNode->link = curr->link;
    curr->link = newNode;

    return 0;
}

/**
 * 리스트의 마지막에 key에 대한 노드를 추가
 */
int insertLast(headNode* h, int key) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->key = key;
    newNode->link = NULL;

    if (h->first == NULL) { // 리스트가 비어있으면 새로운 노드를 첫번쨰로 설정한다.
        h->first = newNode;
        return 0;
    }

    listNode* curr = h->first;
    while (curr->link != NULL) { 
        curr = curr->link;
    }
    curr->link = newNode;

    return 0;
}

/**
 * 리스트의 첫 번째 노드를 삭제
 */
int deleteFirst(headNode* h) {
    if (h->first == NULL) {
        printf("List is empty\n");
        return 0;
    }

	// 첫번째 노드를 삭제하고 두번쨰 노드가 첫번째가 된다.
    listNode* temp = h->first;
    h->first = h->first->link;
    free(temp);

    return 0;
}

/**
 * 리스트에서 주어진 key에 해당하는 노드를 삭제
 */
int deleteNode(headNode* h, int key) {
    if (h->first == NULL) {
        printf("리스트가 비었습니다.\n");
        return 0;
    }

    listNode* curr = h->first;
    listNode* prev = NULL;

    while (curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("해당값을 찾을 수 없습니다.\n");
        return 0;
    }

    if (prev == NULL) {
        h->first = curr->link;
    } else {
        prev->link = curr->link;
    }

    free(curr);

    return 0;
}

/**
 * 리스트의 마지막 노드를 삭제
 */
int deleteLast(headNode* h) {
    if (h->first == NULL) {
        printf("리스트가 비었습니다.\n");
        return 0;
    }

    listNode* curr = h->first;
    listNode* prev = NULL;

    while (curr->link != NULL) {
        prev = curr;
        curr = curr->link;
    }

    if (prev == NULL) {
        h->first = NULL;
    } else {
        prev->link = NULL;
    }

    free(curr);

    return 0;
}

/**
 * 리스트의 링크를 역순으로 재배치
 */
int invertList(headNode* h) {
    listNode* prev = NULL;
    listNode* curr = h->first;
    listNode* next = NULL;

	// 현재 노드를 이전 노드와 연결하여 역순으로 재배치 한다.
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    h->first = prev;

    return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

