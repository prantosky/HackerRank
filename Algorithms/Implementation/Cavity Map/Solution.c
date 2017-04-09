#include <stdio.h>
#include <stdlib.h>
int main() {

    char **mat;
    int n;
    register int i,j;
    scanf("%d",&n);
    mat=(char**)malloc(n*sizeof(char*));
    if(mat==NULL){
        puts("Error Allocating Memory");
        return -1;
    }
    for(i=0;i<n;i++){
        mat[i]=(char*)malloc((n+1)*sizeof(char));
        if(mat[i]==NULL){
            puts("Error Allocating Memory");
            return -1;
        }
        scanf("%s",mat[i]);
    }
    for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			if(mat[i][j]=='X'){
				continue;
			}
			if(mat[i][j-1]!='X' && mat[i][j-1]<mat[i][j]){
				if(mat[i][j+1]!='X' && mat[i][j+1]<mat[i][j]){
					if(mat[i-1][j]!='X' && mat[i-1][j]<mat[i][j]){
						if(mat[i+1][j]!='X' && mat[i+1][j]<mat[i][j]){
							mat[i][j]='X';
						}
						else	
						continue;
					}
					else
					continue;
				}
				else continue;
			}
			else continue;
		}
	}
    for(i=0;i<n;i++){
        puts(mat[i]);
    }
    free(mat);
    return 0;
}