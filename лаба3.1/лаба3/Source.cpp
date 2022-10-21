#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>                  //�������� ����������
#include <stdlib.h>                 //������������ ������� 
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct node
{
	int inf;  // ���������
	char name[200];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

struct node *head = NULL, *last = NULL; // ��������� �� ������ � ��������� �������� ������
int t;
char ss[200];

struct node* get_struct(void){
	struct node* p = NULL;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}
	
	p->inf = t;
	strcpy(p->name, ss);
	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}
void spstore(void){
	struct node *p = NULL, *f = NULL;
	p = get_struct();
	if (head == NULL && p != NULL){	// ���� ������ ���, �� ������������� ������ ������
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL){ // ������ ��� ����, �� ��������� � �����
		f = head;
		if (f->inf > p->inf) {
			p->next = head;
			head = p;
		}
		if (last->inf <= p->inf) {
			last->next = p;
			last = p;
		}
		if (last->inf > p->inf && f->inf <= p->inf){
			while (f->next->inf <= p->inf) {
				f = f->next;
			}
			p->next = f->next;
			f->next = p;
		}
	}
	return;
}
void del(int eee, char* name)
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev = NULL;// ��������� �� �������������� ���������� �������
	int flag = 0;      // ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}

	if (strcmp(name, struc->name) == 0 && eee == struc->inf) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->name) == 0 && eee == struc->inf) // ���� �����, ��
		{
			flag = 1;         // ���������� ���������
			if (struc->next)  // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc);		    // �������  �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else			// ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc);	// �������  �������
				return;
			}
		}
		else // ���� �� �����, ��
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0)				// ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("������� �� ������\n");
		return;
	}


}
void find(int eee, char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	int iii = 1, ii = 0;
	while (struc)
	{
		if (strcmp(name, struc->name) == 0 && eee == struc->inf)
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
void review(void){
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("%d - %s \n", struc->inf, struc->name);
		struc = struc->next;
	}
	return;
}

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct node* p = NULL;
	int e;
	printf("������� ����� ������: 1/2/3 (������/��������/�����), ��������� �������, ������: \n");   // ������ ������
	while(1){
		scanf("%d%d%s", &e, &t, &ss);
		if (e == 1) {
			spstore();
		}
		if (e == 2) {
			del(t ,ss);
		}
		if (e == 3) {
			find(t, ss);
		}
		review();
		printf("\n");
	}

}