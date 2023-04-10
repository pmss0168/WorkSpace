#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* define Linked List */
typedef struct{
	char ID[10], Name[50];
	float R1, R2, R3;
} Student;

struct Node{
	Student Element;
	struct Node *Next;
};

typedef struct Node *Position;
typedef struct Node *List;

/* function protptype */
int append(Student s, List *pL);    // chen 1 sinh vien vao cuoi danh sach
List getList();                     // tra ve danh sach rong
List getFailedList(List L);         // tra ve sinh sach sinh vien chua dat
Position locate(char ID[], List L); // tra ve vi tri dau tien cua ID
void printList(List L);             // hien thi danh sach
void showPassedList(List L);        // hien th sinh vien dat

/* function declaration */
int append(Student s, List *pL){
	List P = locate(s.ID, *pL), T;
	/* neu s khong co trong List
	thi them s vao cuoi List*/
	if (P->Next == NULL){
		T = (List)malloc(sizeof(struct Node));
		T->Element = s;
		T->Next = NULL;

		P->Next = T;
		return 1;
	}
	else{
		return 0;
	}
}

List getList(){
	List L;
	L = (List)malloc(sizeof(struct Node));
	return L;
}

List getFailedList(List L){
	List P = L, result = getList();
	int a;
	while (P->Next != NULL){
		if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 < 4)
			a = append(S->Next->Element, &result);
		P = P->Next;
	}
	a++;
	return result;
}

List locate(char ID[], List L){
	List P = L;
	while (P->Next != NULL){
		if (strcmp(ID, P->Next->Element.ID) == 0)
			return P;
		P = P->Next;
	}
	return P;
}

void printList(List L){
	List P = L;
	int i = 1;
	while (P->Next != NULL){
		printf("%2d -", i);
		printf("%11s -", P->Next->Element.ID);
		printf("%51s - ", P->Next->Element.Name);
		printf("%.3f - ", P->Next->Element.R1);
		printf("%.3f - ", P->Next->Element.R2);
		printf("%.3f - ", P->Next->Element.R3);
		printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
		P = P->Next;
		i++;
	}
}

void showPassedList(List L){
	List P = L;
	float avg = 0;
	int count = 0, i = 1;

	while (P->Next != NULL){
		avg = (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3;
		if (avg >= 4.0){
			printf("%2d -", i++);
			printf("%11s -", P->Next->Element.ID);
			printf("%51s - ", P->Next->Element.Name);
			printf("%.3f - ", P->Next->Element.R1);
			printf("%.3f - ", P->Next->Element.R2);
			printf("%.3f - ", P->Next->Element.R3);
			printf("%.3f\n", avg);
			
			count++;
		}
		P = P->Next;
	}

	printf("%d students in total", count);
}