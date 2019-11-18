#include <stdlib.h>  
#include <stdio.h>
#include <unistd.h> 

// 回调函数
void majin(void* (*operate)(int i))
{
    int j=0;
    pthread_t tids;
    while(1){
        j++;
        printf("majin %d\n",j);
        operate(j);
        sleep(1);
    }


}
 
// 获取随机值
void * usr(int i)
{   
    
    printf("usr %d\n",i*5);
    
    
}
 
int main(void)
{

    majin(usr);
    
    return 0;
}
