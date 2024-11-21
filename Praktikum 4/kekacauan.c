# include <stdio.h>
# include "matrix.h"


int main (){
    int n, kacau;
    scanf("%d", &n);
    Matrix m;
    createMatrix(n,n,&m);
    readMatrix(&m,n,n);
    int mod = 1000000000 +7;
    for (int i=0; i < n; i++){
        for(int j=0; j<n;j++){
            if (m.mem[i][j] >0){
                for (int row=i+1; row<n; row++){
                    if (m.mem[row][j] >0){
                        kacau = kacau%mod +(m.mem[row][j])%mod;}
                }
                for (int rowb = i-1; rowb>=0; rowb--){
                    if (m.mem[rowb][j]>0){
                        kacau = kacau%mod + (m.mem[rowb][j])%mod;}
                }
                for (int col = j+1; col < n; col++){
                    if (m.mem[i][col]>0){
                        kacau = kacau%mod +  (m.mem[i][col])%mod;}
                }
                 for (int colb = j-1; colb>=0; colb--){
                    if (m.mem[i][colb] >0){
                        kacau = kacau%mod +  (m.mem[i][colb])%mod;}
                }

            }
        }
    }

    printf("%d\n", (kacau)%mod);
    return 0;

}