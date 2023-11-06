void sum(int mat1[100][3],int mat2[100][3])
{
    int tr1,tr2,n=0,mat[100][3],i,j,k;
    
    if((mat1[0][0]==mat2[0][0]) && (mat1[0][1]==mat2[0][1]))
    {
        
        tr1=mat1[0][2];
        tr2=mat2[0][2];
        i=1;
        j=1;
        k=1;
        n=tr1+tr2;
        while((i<=tr1) &&(j<=tr2))
        {
            if((mat1[i][0]==mat2[j][0]) &&(mat1[i][1]==mat2[j][1]))
            {
                mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2]+mat2[j][2];
                i++;j++;k++;
            }
            
               else if(mat1[i][0]<mat2[j][0])
                {
                    mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++;
                }
                else
                {
                     mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
                }
                       
                   }
        while(i<=tr1)
        {
           mat[k][0]=mat1[i][0];
                mat[k][1]=mat1[i][1];
                mat[k][2]=mat1[i][2];
                i++;k++; 
        }
        while(j<=tr2)
        {
             mat[k][0]=mat2[j][0];
                mat[k][1]=mat2[j][1];
                mat[k][2]=mat2[j][2];
                j++;k++;
        }
        mat[0][0]=mat1[0][0];
        mat[0][1]=mat1[0][1];
        mat[0][2]=k-1;
        printf("\nThe sum is:\n");
         for(i=0;i<k;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            
            printf("%d  ",mat[i][j]);
        }
    }
    }
    else
    {
        printf("The matrix is incompatible for addition\n");
    }
}


