#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>                  //указание прототипов
#include <stdlib.h>                 //библиотечных функций 
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct node
{
	char name[200];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node *head = NULL, *last = NULL; // указатели на первый и последний элементы списка
char ss[200];

struct node* get_struct(void) {
	struct node* p = NULL;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	printf("Введите объект:\n");
	scanf("%s", &ss);
	strcpy(p->name, ss);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}
void push(void) {
	struct node* p = NULL, * f = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) {	// если списка нет, то устанавливаем голову списка
		head = p;
		last = p;
	}

	else if (head != NULL && p != NULL) { // список уже есть, то вставляем в конец
		p->next = head;
		head = p;
	}
	return;
}
void pop(void)
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}
	else{
		head = struc->next; // установливаем голову на следующий элемент
		printf("\n%s\n", struc->name);
		free(struc);  // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
	}
}
void find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	int iii = 1, ii = 0;
	while (struc)
	{
		if (strcmp(name, struc->name) == 0)
		{
			printf("Порядковый номер элемента: %d\n", iii);
			break;
		}
		struc = struc->next;
		iii += 1;
	}
	if (ii = 0) {
		printf("Элемент не найден\n");
	}
}


/* Просмотр содержимого списка. */
void review(void) {
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("%s \n", struc->name);
		struc = struc->next;
	}
	return;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct node* p = NULL;
	int e;
	while (1) {
		printf("Введите: 1/2/3/4 (запись/удаление/отобразить список/поиск)\n");   // вводим данные
		scanf("%d", &e);
		if (e == 1) {
			push();
		}
		if (e == 2) {
			pop();
		}
		if (e == 3) {
			review();
		}
		if (e == 4) {
			char o[200];
			printf("Введите элемент)\n");
			scanf("%s", &o);
			find(o);
		}
		printf("\n");
	}
}