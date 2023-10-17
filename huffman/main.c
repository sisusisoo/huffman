#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct Element {
	int key;

}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;

}HeapType;

void printHeap(HeapType* h) {
	for (int i = 1; i < h->heap_size + 1; i++) {
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
}

HeapType* create() {
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	return h;

}
void init(HeapType* h) {
	h->heap_size = 0;
}
int is_empty(HeapType* h) {
	return (h->heap_size == 0);
}

int is_full(HeapType* h) {
	return(h->heap_size == (MAX_ELEMENT - 1));

}

void insert_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	h->heap[i] = item;
	//printHeap(h);
	while (i > 1 && item.key > h->heap[i / 2].key) {


		h->heap[i] = h->heap[i / 2];
		h->heap[i / 2] = item;
		i = i / 2;


		//printHeap(h);
	}

	h->heap[i] = item;

}


//�����Լ� 
element delete_heap(HeapType* h) {
	int  parent, child;
	element item, temp;
	item = h->heap[1];//������ ���� ū�� ���߿� ���� �Ϸ��� 
	temp = h->heap[(h->heap_size)--];//�÷��� ���� ��  
	parent = 1;
	child = 2;
	//printHeap(h);
	while (child <= h->heap_size) {
		if (child <= h->heap_size &&
			(h->heap[child].key) < h->heap[child + 1].key)//�� �ڽ� �߿� ū���� ���� �װ� �ø����� 
			child++;
		if (temp.key >= (h->heap[child].key)) break;
		h->heap[parent] = h->heap[child];//�̷��� �ڵ����� 1��° ���� �����ǰ� �ٸ� ������ ��ü��
		parent = child;//������ �ٲ� �ٷ� �ؿ� �ٱ�� 
		child *= 2;//�ش� Ʈ���� �Ʒ��ٱ�� �̵�

	}
	h->heap[parent] = temp;
	return item;
}

//




void heap_sort(element a[], int n) {//���� n 
	int i;
	HeapType* h;
	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_heap(h);
	}
	free(h);

}


void main() {
	



	element sort[]= { 34,12,76,59,32,55,88,26,16,79,34,85,29,78,41,56,86};//---
	heap_sort(sort, 17);
	for (int i = 0; i < 17; i++) {
		printf("%d ", sort[i].key);
	}
	printf("\n");




}
