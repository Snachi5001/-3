#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>                  //�������� ����������
#include <stdlib.h>                 //������������ ������� 
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct node
{
	char name[200];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

struct node *head = NULL, *last = NULL; // ��������� �� ������ � ��������� �������� ������
char ss[200];

struct node* get_struct(void) {
	struct node* p = NULL;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}
	printf("������� ������:\n");
	scanf("%s", &ss);
	strcpy(p->name, ss);
	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}
void push(void) {
	struct node* p = NULL, * f = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) {	// ���� ������ ���, �� ������������� ������ ������
		head = p;
		last = p;
	}

	else if (head != NULL && p != NULL) { // ������ ��� ����, �� ��������� � �����
		p->next = head;
		head = p;
	}
	return;
}
void pop(void)
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}
	else{
		head = struc->next; // ������������� ������ �� ��������� �������
		printf("\n%s\n", struc->name);
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
}
void find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	int iii = 1, ii = 0;
	while (struc)
	{
		if (strcmp(name, struc->name) == 0)
		{
			printf("���������� ����� ��������: %d\n", iii);
			break;
		}
		struc = struc->next;
		iii += 1;
	}
	if (ii = 0) {
		printf("������� �� ������\n");
	}
}


/* �������� ����������� ������. */
void review(void) {
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
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
		printf("�������: 1/2/3/4 (������/��������/���������� ������/�����)\n");   // ������ ������
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
			printf("������� �������)\n");
			scanf("%s", &o);
			find(o);
		}
		printf("\n");
	}
}