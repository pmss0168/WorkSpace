Tree rightSibling(int x, Tree T)
{
    if (T != NULL)
    {
        if (T->Left->Data == x)
        {
            if (T->Right != NULL)
                return T->Right;
            else
                return NULL;
        }
        if (T->Data > x)
            return rightSibling(x, T->Left);
        if (T->Data < x)
            return rightSibling(x, T->Right);
    }
    return NULL;
}