#include <stdio.h>  
int main()  
{  

  
    int n, m, i, j, avail[10],max[10][10],alloc[10][10],k;  
    printf("\nEnter the no. of processes:");
    scanf("%d",&n);
    printf("\nEnter the no. of resources:");
    scanf("%d",&m);
    
    printf("\nEnter the allocatin marix:");
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        scanf("%d",&alloc[i][j]);
    
    printf("\nEnter the max marix:");
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       scanf("%d",&max[i][j]);
       
       printf("Enter the available resources:");
       
       for(int j=0;j<m;j++)
       scanf("%d",&avail[j]);
       
    
 
    
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  //finish
    }  
    int need[n][m];  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < n; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  //finish
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  //safe sequence
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    }  
    return (0);  
}  

