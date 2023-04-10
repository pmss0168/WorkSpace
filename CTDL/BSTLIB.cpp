#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node* left;
	struct Node* right;
};
typedef Node* TTree;
//Tao rong
void MakeNullTree(TTree *T){ 
	(*T)=NULL; 
}
//Kiem tra rong
int EmptyTree(TTree T){
	return T==NULL;
}
//Xac dinh con trai
TTree LeftChild(TTree T){ 
	if (T!=NULL) 
		return T->left;
	else 
		return NULL;
}
//Xac dinh con phai
TTree RightChild(TTree T){ 
	if (T!=NULL) 
		return T->right;
	else 
		return NULL;
}
//Kiem tra nut la trong cay
int IsLeaf(TTree T){ 
	if(T!=NULL)
		return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
	else 
		return 0;
}
//Duyet tien tu
void PreOrder(TTree T){
	printf("%c ",T->Key);
	if (LeftChild(T)!=NULL)
		PreOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PreOrder(RightChild(T));
}
//Duyet trung tu
void InOrder(TTree T){
	if (LeftChild(T)!=NULL)
		InOrder(LeftChild(T));
	printf("%c ",T->Key);
	if(RightChild(T)!=NULL) 
		InOrder(RightChild(T));
}
//Duyet hau tu 
void PosOrder(TTree T){
	if(LeftChild(T)!=NULL) 
		PosOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PosOrder(RightChild(T));
	printf("%c ",T->Key);
}
//Xac dinh so nut trong cay
int nb_nodes(TTree T){
	if(EmptyTree(T)) 
		return 0;
	else 
		return 1 + nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}
//Tao cay tu hai cay co san
//TTree Create2(Tdata v,TTree l,TTree r){ 
//	TTree N;
//	N=(TNode*)malloc(sizeof(TNode));
//	N->Data=v;
//	N->left=l;
//	N->right=r;
//	return N;
//}
//Tim kiem vi tri cua nut trong cay
TTree Search(KeyType x,TTree Root){
	if (Root == NULL) 
		return NULL;//không tìm thấy x
	else if (Root->Key == x) // tìm thấy khoá x
			return Root;
		else if (Root->Key < x)
		//tìm tiếp trên cây bên phải
				return Search(x,Root->right);
			else //tìm tiếp trên cây bên trái
				return Search(x,Root->left);
}
//Them nut vao cay
void InsertNode(KeyType x, TTree *T){
	if((*T) == NULL){
		(*T) = (Node*)malloc(sizeof(Node));
		(*T)->Key = x;
		(*T)->left = NULL;
		(*T)->right = NULL;
	}
	else
		if((*T)->Key == x)
			printf("Da ton tai khoa x");
		else
			if((*T)->Key > x)
				InsertNode(x,&(*T)->left);
			else
				InsertNode(x,&(*T)->right);
}
//Xoa nut trong cay
KeyType DeleteMin(TTree *T){
	KeyType k;
	if((*T)->left == NULL){
		k = (*T)->Key;
		(*T) = (*T)->right;
		return k;
	}
	else 
		return DeleteMin(&(*T)->left);
}

void DeleteNode(KeyType x, TTree *T){
	if((*T)!=NULL) //Kiem tra cay khac rong
		if(x <(*T)->Key) //Hy vong x nam ben trai cua nut
			DeleteNode(x,&(*T)->left);
		else
			if(x >(*T)->Key) //Hy vong x nam ben phai cua nut
				DeleteNode(x,&(*T)->right);
			else // Tim thay khoa x tren cay
				if(((*T)->left==NULL)&&((*T)->right==NULL))//x la nut la
					(*T)=NULL; // Xoa nut x
				else // x co it nhat mot con
					if((*T)->left==NULL) //Chac chan co con phai
						(*T) = (*T)->right;
					else
						if((*T)->right==NULL) //Chac chan co con trai
							(*T) = (*T)->left;
						else // x co hai con
							(*T)->Key = DeleteMin(&(*T)->right);
}




