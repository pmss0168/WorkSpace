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