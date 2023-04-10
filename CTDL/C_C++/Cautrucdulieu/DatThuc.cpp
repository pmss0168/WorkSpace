#include <stdio.h>
#define Maxlength 100
typedef struct{
    double he_so;
    int bac;
} DonThuc;
typedef DonThuc ElementType;
typedef int Position;
struct DaThuc {
    ElementType A[Maxlength];
    Position so_luong;
};

int main(int argc, char const *argv[]){
    struct DaThuc d={{{1.5,1}}, 1};
    printf("Size A = %lu x %lu\n",sizeof(d.A)/sizeof(DonThuc), sizeof(DonThuc));
    printf("n = %d\n", d.so_luong);
    return 0;
}

