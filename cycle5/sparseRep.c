#include<stdio.h>
void read_sparsemat(int mat_normal[100][100],int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat_normal[i][j]);
        }
    }
}
void print_sparsemat(int mat_normal[100][100],int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("%d  ",mat_normal[i][j]);
        }
    }
}
void conv_tuple(int mat_normal[100][100],int r,int c)
{
    //sparse  to Tuple Form Conversion
    int mat_tup[100][3];
    int i,j,cnz=0,tr=0,tc=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat_normal[i][j]!=0)
            {
                cnz++;
                mat_tup[cnz][0]=i;
                mat_tup[cnz][1]=j;
                mat_tup[cnz][2]=mat_normal[i][j];
            }
         }
    }
    mat_tup[0][0]=r;
    mat_tup[0][1]=c;
    mat_tup[0][2]=cnz;
    tr=cnz+1;
    tc=3;
    printf("\nrows columns values");
    for(i=0;i<tr;i++)
    {
        printf("\n");
        for(j=0;j<tc;j++)
        {
            printf("%d  ",mat_tup[i][j]);
        }
    }
  }
void main()
{
    int mat1[100][100],r1,c1,mat2[100][100],r2,c2;
    printf("\n Matrix:");
    printf("\nEnter the no. of rows:");
    scanf("%d",&r1);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c1);
    printf("Enter the elements\n");
    read_sparsemat(mat1,r1,c1);
   
    printf("\nThe matrix is :");
    print_sparsemat(mat1,r1,c1);
    
    printf("\nMatrix in tuple form:\n");
    conv_tuple(mat1,r1,c1);
    
 }




