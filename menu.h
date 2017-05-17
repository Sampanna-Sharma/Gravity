#ifndef MENU_H
#define MENU_H

void game();
int counter=1;
char data;
int xgravity=0,ygravity=0;
int xStart,yStart;
int backgroundColor=4;
int hiColor=4;
int aColor=4;
int heColor= 4;
int exColor= 4;
void menu();
void select();
int mainmenu();


int highscoredisplay()
{
    cleardevice();
    FILE *fpp;
    fpp = fopen("highscore.txt","r");
    char player[100];
    char players[100];
    int playerscore;
    int h=1;
    int i;
    outtextxy(100,60,"HighScore:");
    while(1)
    {
      // fgets(player,100,fpp);
        fscanf(fpp," %s%d",player,&playerscore);
        sprintf(players,"%s --->  %d",player,playerscore);
        if(feof(fpp)){
            break;
        }

        h++;
        outtextxy(50,h*60,players);
    }
    fclose(fpp);
    fflush(stdin);
}

void help()
{
        cleardevice();
       int a=15,b=15;
       char about[500];

       FILE *fp2;
       fp2 = fopen("help.txt","r");
       rectangle(5,5,getmaxx()-5,getmaxy()-5);

      while(1)
       {
           if(feof(fp2))
        {
            break;
        }
         fgets(about,sizeof(about),fp2);
         setbkcolor(RED);
         settextstyle(3,0,2);
         outtextxy(a,b,about);
         b+=40;
       }

    fclose(fp2);

}

void about()
{

    int a=80,b=100,i=0;
    cleardevice();

    rectangle(5,5,getmaxx()-5,getmaxy()-5);

   setbkcolor(RED);


 FILE *fp;
   char about[500],c;
   fp = fopen("about.txt","r");

  while(1)
   {
        if(feof(fp))
        {
            break;
        }

       fgets(about,sizeof(about),fp);
       setbkcolor(RED);
   settextstyle(4,0,14);
       outtextxy(a,b,about);

       b+=60;


   }



}







int mainmenu()
{
     setcolor(WHITE);
    fflush(stdin);
    data='l';

    page=0;

	while(1){
    setactivepage(page);
    setvisualpage(1-page);
    setfillstyle(SOLID_FILL,4);

    bar(0,0,650,520);

menu();
if(counter==1 && data=='d')
         {
            game();
            break;

         }
else if(counter==5 && data=='d')
         {
            exit(1);
         }
else if(counter==2 && data=='d')
         {
            highscoredisplay();
         }

else if(counter==3 && data=='d')
         {
            help();
         }

else if(counter==4 && data=='d')
         {
            about();
         }

    page=1-page;

	}



return 0;
}


void menu()

{
    setbkcolor(4);
            settextstyle(3,0,9);
            outtextxy(xgravity+180,ygravity,"Gravity");
            settextstyle(8,0,5);
        setbkcolor(backgroundColor);
        outtextxy(xStart+190,yStart+140,"Start Game");


        setbkcolor(hiColor);
        outtextxy(xStart+190,yStart+200,"High Score");
         setbkcolor(heColor);
        outtextxy(xStart+190,yStart+260,"Help");
        setbkcolor(aColor);
         outtextxy(xStart+190,yStart+320,"About");
          setbkcolor(exColor);
         outtextxy(xStart+190,yStart+380,"Exit");
         select();




}
void select()
{


    int k = kbhit();
    int a=0;
    int b=0;




    if(k)
    {
        data = getch();


      switch(data)
        {
            case 'w': a=1;
                    break;
            case 's': b=1;
                    break;
        }

    }
    k=0;



    if(a==1)
    {

        counter--;

    }
    else if(b==1)
    {

        counter++;
    }

    int counter1 = counter;
    if(counter1<1)
    {
        counter =5;
    }
    else if(counter1>5)
    {
        counter =1;
    }

    if(counter1==1)
    {
    backgroundColor=2;
    hiColor=4;
    heColor=4;
    aColor=4;
    exColor=4;

    }

else if(counter1==2)
{
    backgroundColor=4;
    hiColor=2;
    exColor=4;
    heColor=4;
    aColor=4;

}
else if(counter1==3)
{
    backgroundColor=4;
    hiColor=4;
    exColor=4;
    heColor=2;
    aColor=4;
}
else if(counter1==4 )
{
    backgroundColor=4;
    hiColor=4;
    heColor=4;
    exColor=4;
    aColor=2;

}
else if(counter1==5 )
{
    backgroundColor=4;
    hiColor=4;
    heColor=4;
    aColor=4;
    exColor=2;

}

delay(80);
//b=1-b;

}
#endif // MENU_H
