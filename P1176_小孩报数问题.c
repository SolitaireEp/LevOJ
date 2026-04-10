#include <stdio.h>
#include <string.h>

int main()
{
  int N,i,W,S,cur,left;
  scanf("%d",&N);
  char names [64][16];
  for(i=0;i<N;i++)
    scanf("%s",names[i]);
  scanf("%d,%d",&W,&S);
  int exists[64];
  for(i=0;i<N;i++)
    exists[i]=1;
  cur=W-1;
  left=N;
  while(left>0)
  {
    int count=S;
    while(count>0)
    {
      if(exists[cur])
      {
        count--;
        if(count==0)
          break;
      }
      cur=(cur+1)%N;
    }
    printf("%s\n",names[cur]);
    exists[cur]=0;
    left--;
    if(left>0)
    {
      do{
      cur=(cur+1)%N;
      }while(!exists[cur]);
    }
  }
  return 0;
}
