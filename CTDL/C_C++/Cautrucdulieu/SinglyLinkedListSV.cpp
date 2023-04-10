#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char ID[10];
	char Name[50];
	float R1, R2, R3;
} Student;
typedef Student ElementType;
struct Node
{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

Position locate(char *x, List L)
{
	Position P = L;
	int Found = 0;
	while ((P->Next != NULL) && (Found == 0))
	{
		if (strcmp(P->Next->Element.ID, x) == 0)
			Found = 1;
		else
			P = P->Next;
	}
	return P;
}
int append(Student x, List *pL)
{
	struct Node *A = locate(x.ID, *pL);
	if (A->Next != NULL)
	{
		return 0;
	}
	else
	{
		struct Node *T, *P = (*pL);
		// while (P->Next != NULL)
		// {
		// 	P = P->Next;
		// }
		T = (struct Node *)malloc(sizeof(struct Node));
		T->Element = x;
		T->Next = NULL;
		A->Next = T;
		return 1;
	}
}
List getList()
{
	List L;
	L = (struct Node *)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}
// List getFailedList(List L)
// {
// 	struct Node *P = L;
// 	List kqL;
// 	kqL = getList();
// 	while (P->Next != NULL)
// 	{
// 		float tbc = 0;
// 		tbc = (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3;
// 		if (tbc <= 4.0)
// 		{
// 			append(P->Next->Element, &kqL);
// 		}
// 		P = P->Next;
// 	}
// 	return kqL;
// }
List readList()
{
	List L;
	L = getList();
	int n, i;
	printf("Nhap n = ");
	scanf("%d ", &n);
	for (i = 0; i < n; i++)
	{
		Student x;
		char *Id;
		Id = (char *)calloc(10 + 1, sizeof(char));
		char *Name;
		Name = (char *)calloc(50 + 1, sizeof(char));
		fgets(Id, 11, stdin);
		if (Id[strlen(Id) - 1] == '\n')
			Id[strlen(Id) - 1] = '\0';
		strcpy(x.ID, Id);
		fgets(Name, 51, stdin);
		if (Name[strlen(Name) - 1] == '\n')
			Name[strlen(Name) - 1] = '\0';
		strcpy(x.Name, Name);
		scanf("%f %f %f ", &x.R1, &x.R2, &x.R3);
		append(x, &L);
	}
	return L;
}
void printList(List L)
{
	Node *P = L;
	int t = 0;
	printf("\n");
	while (P->Next != NULL)
	{
		t++;
		printf("%2d - %10s - %50s - %2.3f - %2.3f - %2.3f - %2.3f\n", t, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3, (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
		P = P->Next;
	}
}
void showPassedList(List L)
{
	List P = L;
	int count = 0, t = 0;
	while (P->Next != NULL)
	{
		count++;
		t++;
		if (((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3) >= 4)
		{
			printf("%2d - %10s - %50s - %2.3f - %2.3f - %2.3f - %2.3f\n", t, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3, (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
			printf("%d students in total", count);
		}
		P = P->Next;
	}
}

int main(int argc, char const *argv[])
{
	List L;
	L = readList();
	printList(L);
	showPassedList(L);
	return 0;
}
