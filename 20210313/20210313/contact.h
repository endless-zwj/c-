#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max_name 10
#define Max_sex 10
#define Max_number 11
#define Max_phoList 1000

typedef struct PhoneList
{
	char name[Max_name];
	char sex[Max_sex];
	char number[Max_number];
}PhoneList;

typedef struct Contact
{
	PhoneList data[Max_phoList];
	int size;
} Contact;

//≥ı ºªØ
void InitContact(Contact* con);

void Show(Contact* con);

void AddContact(Contact* con);

void DelContact(Contact* con);

void Search(Contact* con);

void Modify(Contact* con);

void Sort(Contact* con);

int cmp_by_name(const void* e1, const void*e2);

