#include<stdio.h>
int a[10][10],p[10][10],n;
int i,j,k;
void write_data(){
    printf("path matrix: \n");
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d ",p[i][j]);
    }
    printf("\n");
}
}

void path(){
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        p[i][j]=a[i][j];
    }
}

    for(k=0;k<n;k++){
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(p[i][k]==1 && p[k][j]==1){
            p[i][j]=1;
        }
    }
}
}
}

void read_data(){
    printf("enter no of vertices : ");
    scanf("%d",&n);
    printf("enter adjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void main(){
read_data();
path();
write_data();
}
