// DANH SÁCH LIÊN KẾT ĐÔI - DOUBLY LINKED LIST
#include <iostream>
#include <stdio.h>
#define null NULL
using namespace std;

struct  node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

//Tao node

node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = null;
    newNode->prev = null;
    return newNode;
}

//Duyet danh sach theo chieu thuan

void duyet(node *head){
    while(head != null){
        cout << head->data << endl;
        head = head->next;
    }
}

//Dem so diem (node) trong danh sach

int size(node *head){
    int cnt = 0;
    while(head != null){
        cnt += 1;
        head = head->next;
    }
    return cnt;
}

//buoc 1: cho phan [next] cua [node] moi luu dia chi cua [node] head
//buoc 2: cho phan [prev] cuar [node] head luu dia chi cua [node] moi
//buoc 3: cap nhat hea la [node] moi

void pushFront(node **head, int x){
    node* newNode = makeNode(x);
    //cho [next node] moi luu dia chi hien tai cua [node] head:
    newNode->next = (*head);
    //can than neu head la NULL truy cap vao prev se loi
    if(*head != null)
        (*head)->prev = newNode;
    //cap nhat head
    (*head) = newNode;
    
}

// buoc 1: kiem tra neu dslk rong thi gan luon head la [node] moi
// buoc 2: duyet toi [node] cuoi trong dslk(temp)
// buoc 3: cho phan [next] cua [node] cuoi luu [node] moi
// buoc 4: cho phan [prev] cua [node] moi luu [node] cuoi

void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    //b1:
    if(*head == null){
        *head = newNode;
        return;
    }
    //b2:
    node *temp= *head;
    while(temp->next != null){
        temp = temp->next;
    }
    //b3:
    temp->next = newNode;
    //b4:
    newNode->prev = temp;
}

// buoc 1: duye toi [node] thu k - 1
// buoc 2: cho [node] thu k lien ket [node] moi 
// buoc 3: cho [node] thu k - 1 lien ket voi [node] moi 

void insert(node **head, int  k, int x){
    int n = size(*head);
    if((k < 1)||(k > n + 1)) return;
    else
        if(k == n + 1) pushBack(head, x);
        else{
            //b1
            node *temp = (*head);
            for(int i = 1; i < k - 1; ++i){
                temp = temp->next;
            }
            // temp : node thu k - 1
            node *newNode = makeNode(x);
            //b2
            newNode->next = temp->next;
            temp->next->prev = newNode;
            //b3
            temp->next = newNode;
            newNode->prev = temp;
        }
}

// buoc 1: check rong, neu dslk rong thi khong xoa
// buoc 2: cho [node] head sang [node] thu 2 trong danh sach lien ket 
// buoc 3: neu [node] head sau khi cap nhat khong phai la null thi cap nhat phan prev cho luu null, cap nhat phan prev cua null se loi 
// buoc 4: giai phong node dau trong dslk

void popFront(node **head){
    //b1
    if(*head == null) return;
    node *temp = *head;
    //b2
    *head = temp->next;
    //b3
    if(*head != null){
        (*head)->prev = null;
    }
    //b4
    free(temp);
}

// buoc 1: neu dslk rong thi khong thuc hien xoa 
// buoc 2: neu dslk chi co 1 node thi free node head 
// buoc 3: duyet toi node cuoi cung trong dslk 
// buoc 4: cho phan next cua node thu 2 tu cuoi ve tro vao null 
// buoc 5: free node cuoi

void popBack(node **head){
    //b1
    if(*head == null) return;
    node *temp= *head;
    //b2
    if(temp->next == null){
        *head = null;
        free(temp);
        return;
    }
    //b3
    while(temp->next != null){
        temp = temp->next;
    }
    //b4
    temp->prev->next = null;
    //b5
    free(temp);
}

//xoa phan tu thu k

// buoc 1: kiem tra vi tri xoa hop le 
// buoc 2: neu k=1 goi xoa dau 
// buoc 3: duyt toi node thu k (temp)
// buoc 4: cho node k-1 lien ket toi node k+1 va bo qua node k 
// buoc 5: free node k

void erase(node **head, int k){
    int n =  size(*head);
    if((k < 1)||(k > n)) return;
    if(k == 1) popFront(head);
    else{
        node *temp = *head;
        for(int i = 1; i <= k - 1; ++i){
            temp = temp->next;
        }
        temp->prev->next = temp->next; // k - 1=> k + 1 :next
        if(temp->next != null)
            temp->next->prev = temp->prev; // k + 1 => k - 1 :prev
        free(temp);
    }

}

//Selection sort

void sort(node **head){
    for(node *i = *head; i != null; i = i->next){
        node *min = i;
        for(node *j = i->next; j != null; j = j->next){
            if(min->data > j->data){
                min = j;
            }
        }
        int temp = min->data;
        min->data = i->data;
        i->data = temp;
    }
}

//lat nguoc dslk doi

void reverse(node **head){
    if(*head == null) return;
    node *left = *head;
    node *right = *head;

    while(right->next != null){
        right = right->next;
    }

    int n = size(*head);
    for(int i = 1; i <= n / 2; ++i){
        int tmp = left->data;
        left->data = right->data;
        right->data = tmp;
        left = left->next;
        right = right->prev;
    }
}
int main(){
    cout <<" xong " << endl;
    return 0;
}