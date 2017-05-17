#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <stdio.h>
#include <string.h>

struct CONTAININFILE{
        char name[6][100];
        int scored[6];
        }c1;
char name1[100];
 char playerss[30];
char arr[30]="";

int score=0;
void getplayername()
{
           char arr1[30]="";

            int cnt=0,i;




        cleardevice();
       outtextxy(20,50,"Congo you scored highscore");
   while(1){

    outtextxy(20,50,"Congo you scored highscore");
    outtextxy(20,120,"Enter your name:");
       fflush(stdin);
    playerss[cnt]=getch();
    if((int)playerss[cnt]==8){
     if(cnt!=0){
      cnt--;
      }
      setcolor(WHITE);
      memset(arr1,0,cnt+1);
      memcpy(arr1,playerss,cnt);
      memcpy(playerss,arr1,cnt);
      cleardevice();
      outtextxy(200,200,arr1);
      }
    else if((int)playerss[cnt]==13){
            fflush(stdin);
        break;
    }
    else{
    memcpy(arr1,playerss,cnt+1);
    cleardevice();
    outtextxy(200,200,arr1);
    cnt++;
    }

  }
  strcpy(arr,arr1);
  cleardevice();
}

void sortcontent()
{
    while(1)
    {
        int s=0;
        int i=0;
        for(i=0;i<5;i++)
        {
            if(c1.scored[i]<c1.scored[i+1])
            {
                int tempscore = c1.scored[i];
                c1.scored[i] =c1.scored[i+1];
                c1.scored[i+1] = tempscore;

                char tempname[100];
                strcpy(tempname,c1.name[i]);
                strcpy(c1.name[i],c1.name[i+1]);
                strcpy(c1.name[i+1],tempname);
                s=1;
            }

        }
        if(s==0)
        {
            for(i=0;i<5;i++)
        {

            if(score==c1.scored[i])
            {


        getplayername();
    strcpy(c1.name[i],arr);
  //  printf("%s",playerss);
    getch();
    break;

            }

            }

    break;
        }

    }
}



void checkscore()
{

strcpy(name1,"Unnamed");
FILE *fp;
fp= fopen("highscore.txt","a+");
int filelen=0;
while(1)
{
    fscanf(fp," %s%d",c1.name[filelen],&c1.scored[filelen]);
    filelen++;
    if(feof(fp)){
        break;
    }
}
filelen--;
printf("%d\n",filelen);

if(filelen<5)
{

        getplayername();
    //strcpy(c1.name[filelen],arr1);
    freopen("highscore.txt","a+",fp);
    fprintf(fp,"%s\t%d\n",arr,score);

     // printf("%d",score);
    fclose(fp);

}
else{
        fp= fopen("highscore.txt","w");
   strcpy(c1.name[5],name1);
    c1.scored[5] = score;

    sortcontent();
    int i=0;
    for(i=0;i<5;i++)
    {
        fprintf(fp,"%s\t%d\n",c1.name[i],c1.scored[i]);
    }
    fclose(fp);
}



}



#endif // HIGHSCORE
