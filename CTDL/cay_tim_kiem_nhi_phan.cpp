#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node* Left;
	struct Node* Right;
};
typedef Node* Tree;
//Co get, Sibling thi xai vong lap while


//ktra rong 
int isEmpty(Tree T){
    if(T==NULL)
    	return 1;
    else 
		return 0;
}
//khoi tao cay rong
Tree initTree(){
    Tree T = (struct Node*)malloc(sizeof(struct Node*));
    T = NULL;
    return T;
}
//chieu cao cua cay co khoa x
int hNode(int x, Tree T){
    Tree p = T;
    if(p == NULL)
        return -1;
    else
        if(p->Key == x){
            if(p->Left == NULL && p->Right == NULL)
                return 0;
            int l = 0, r = 0;
            if(p->Left != NULL)
                l = hNode(p->Left->Key, p->Left);
            if(p->Right != NULL)
                r = hNode(p->Right->Key, p->Right);
            if(l > r)
                return l+1;
            else 
                return r+1;
        }
        else
            if(p->Key > x)
                return hNode(x,T->Left);
            else 
                return hNode(x,T->Right);
}
//tim ae ruot phai
Tree rightSibling(int x, Tree T){
    Tree Bro = NULL;
    while(T != NULL){
        if(T->Key == x){
            if(T != Bro)
                return Bro;
            else
                return NULL;
        }
        else{
            Bro = T->Right;
            if(T->Key > x)
                T = T->Left;
            else
                T = T->Right;
        }
    }
    return NULL;
}
//duyet tien tu
void preOrder(Tree T){
    if(T!=NULL){
    printf("%d ",T->Key);
    preOrder(T->Left);
    preOrder(T->Right);
	}
}
//duyet trung tu
void inOrder(Tree T){
	if(T!=NULL){
		inOrder(T->Left);
		printf("%d ",T->Key);
		inOrder(T->Right);
	}
}
//duyet hau tu
void posOrder(Tree T){
    if(T!=NULL){
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ",T->Key);
        
    }
}
//chen 
void insertNode(int x, Tree *pT){	
    if((*pT) == NULL){											//Neu cay rong chen vao
        (*pT) = (struct Node*)malloc(sizeof(struct Node*));	
        (*pT)->Key = x;
        (*pT)->Right = NULL;
        (*pT)->Left = NULL;
    }
    else{
        if((*pT)->Key == x);									//Neu x da co trong cay
            //khong lam gi ca
        else													//Neu x khong co trong cay
            if((*pT)->Key > x)									//Hy vong x nam ben trai
                insertNode(x,&(*pT)->Left);						
            else												//Hy vong x nam ben phai
                insertNode(x,&(*pT)->Right);
    }
}
//xoa 
KeyType deleteMin(Tree *pT){
    KeyType k;
    if((*pT)->Left == NULL){
        k = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return k;
    }
    else
        return deleteMin(&(*pT)->Left);
}

void deleteNode(int x, Tree *pT){
    if((*pT) != NULL){
        if((*pT)->Key > x)                                      //Hy vong x nam ben trai cua nut
            deleteNode(x, &(*pT)->Left);
        else
            if((*pT)->Key < x)                                  //Hy vong x nam ben phai cua nut
                deleteNode(x, &(*pT)->Right);
            else                                                //Tim thay khoa x
                if((*pT)->Left == NULL && (*pT)->Right == NULL) //x la nut la
                    (*pT) = NULL;
                else                                            //Nut co it mot con
                    if((*pT)->Left == NULL)                     //Chac chan co con phai
                        (*pT) = (*pT)->Right;
                    else
                        if((*pT)->Right == NULL)                //Chac chan co con trai
                            (*pT) = (*pT)->Left;
                        else                                    //Nut co hai con
                            (*pT)->Key = deleteMin(&(*pT)->Right);
    }
}
//lay gia tri lon nhat
Tree maxNode(Tree T){
    Tree p = T;
    while(p->Right != NULL){
        p = p->Right;
    }
    return p;
}
// tra ve nut dung truoc 
Tree getPrevious(int x, Tree T){
    Tree p = NULL;
    while(T != NULL){
        if(T->Key == x){
            if(T->Left == NULL)
                return p;
            else
               return maxNode(T->Left);
        }
        else{
            if(T->Key > x)
                T = T->Left;
            else{
                p = T;
                T = T->Right;
            }
        }
    }
    return NULL;
}
//lay gia tri nho nhat
Tree minNode(Tree T){
    Tree p=T;
    while (p->Left!=NULL)
        p=p->Left;
    return p;
}
//tra ve nut dug sau
Tree getNext(int x, Tree T){
	Tree p = NULL;
    while(T != NULL){
        if(T->Key == x){
            if(T->Right == NULL)
                return p;
            else
                return minNode(T->Right);
        }
        else{
            if(T->Key > x)
            	p = T;
                T = T->Left;
            else
                T = T->Right;
        }
    }
    return NULL;
}

//tim 
Tree searchNode(int x,Tree T){
    if(T!=NULL)
    	if(T->Key==x)
        	return T;
    	else 
	  		if(T->Key<x)
        		return  searchNode(x,T->Right);
      		else 
	  			return searchNode(x,T->Left);
    else 	
		return NULL;
}
//chieu cao cua cay
//Cach 1:
int getHeight(Tree T){
    if(T == NULL)
        return -1;
    else{
        int a = getHeight(T->Left);
        int b = getHeight(T->Right);
        if(a>b)
            return a+1;
        else 
			return b+1;
    }
}
//Cach 2:
int getHeight(Tree T){
    if(T == NULL)
        return -1;
    else{
        if(T->Right == NULL && T->Left == NULL)
            return 0;
        int l = 0, r = 0;
        if(T->Left != NULL)
            l = getHeight(T->Left);
        if(T->Right != NULL)
            r = getHeight(T->Right);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
}
//tim cha cua khoa x 
Tree getParent(int x, Tree T){
    Tree p = NULL;
    while(T != NULL){
        if(T->Key > x){
            p = T;
            T = T->Left;
        }
        else
            if(T->Key < x){
                p = T;
                T = T->Right;
            }
            else
                return p;
    }
    return NULL;
}
//ham printPath
void printPath(int x, Tree T){
    if(T != NULL){
        printf("%d ", T->Key); 
        if(T->Key == x)
            printf("-> Tim thay");
        else
            if(T->Key > x)
                printPath(x, T->Left);
            else
                printPath(x, T->Right);
    }
    else
        printf("-> Khong thay");
}
//Lay so luong nut co 2 con
int getFullNodes(Tree T){
	if(T == NULL)
		return 0;
	else{
		if(T->Left != NULL && T->Right != NULL)
			return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);
		else
			return getFullNodes(T->Left) + getFullNodes(T->Right);
	}
}
//Anh
int isMirrors(Tree T1, Tree T2){
    if (emptyTree(T1) && emptyTree(T2))
        return true;
    else{
        if (T1 && T2 && T1->Data == T2->Data){
            return (isMirrors(T1->Left, T2->Right) && (isMirrors(T1->Right, T2->Left)));
        }
        else
            return false;
    }
}
//Tim gia tri nut lon nhat
int max(int a, int b){
    return a > b ? a : b;
}
int findMax(Tree T){
    if (!emptyTree(T)){
        return max(T->Data, max(findMax(T->Left), findMax(T->Right)));
    }
    else
        return 0;
}
//Tim gia tri nut nho nhat
int min(int a, int b){
	return a < b ? a : b;
}
int findMin(Tree T){
	if(T != NULL){
		return min(T->Key,min(findMin(T->Left),findMin(T->Right)));
	else
		return 0;
	}
}
//Tao mot nut 
struct Node *createNode(DataType x)
{
    Tree T;
    T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}