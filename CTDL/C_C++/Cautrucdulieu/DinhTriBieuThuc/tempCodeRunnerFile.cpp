char doiSo(int n){
    char x;
    switch (n)
    {
    case 10:
        x = 'A';
        break;
    case 11:
        x = 'B';
        break;
    case 12:
        x = 'C';
        break;
    case 13:
        x = 'D';
        break;
    case 14:
        x = 'E';
        break;
    case 15:
        x = 'F';
        break;
    }
    return x;
}
void doiThaplucphan(int n, Stack *pS){
    makenullStack(pS);
    int temp = n / 16;
    while (n > 0)
    {
        temp = n % 16;
        if (temp >=0 && temp <=9)
        {
            push(temp + '0',pS);
        }
        else    if(temp >= 10 && temp <= 15)
                    push(doiSo(temp),pS);
        n = n / 16;
    }
    
}