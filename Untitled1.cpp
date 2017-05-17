#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define PI 3.14159
#include "highscore.h"
#include "Untitled1.h"
#include "menu.h"





double ai=(PI/180)*45;
int x,y,gameover,monsterdied=0;
int a1,b1,a2,b2,a3,b3,a5,a4,b4,a6,a7,a8,a9,c,d,f,h;
int misy[1000],misx[1000],monstx=700,monsty,mism=0;
int g=0; //gravity
char dir,mis,miss;
int j,k,l,m,b; // to store the coordinate of nearest platform for detection of collision


void platform(int a ,int b, int w) // function for platform
{
     setfillstyle(SOLID_FILL,BROWN);
     int i;
for(i=a-w;i<=a-30;i+=30){

   bar(i+2,b-10,i+30,b);
}


     if(k<=x)
     {k=5000;

     }

     if(a<k) // to detect nearest platform
     {
             k=a;
             l=b;
             j=k-w;

             }


}

void missile()
{
    if(mis=='s')//to execute this control statement
    {
        misy[mism]=y;
        misx[mism]=100;
        mism++;
        mis=' ';
    }

if(mism!=0)
{
    int i;
    for(i=0; i<=mism ; i++)
    {
        if(misx[i]<650)
        {



    setfillstyle(SOLID_FILL, RED);
   fillellipse(misx[i],misy[i],5,5);
   if((misx[i]>(monstx-30) && misx[i]<(monstx)) && (misy[i]<monsty && misy[i]>(monsty-30)))
     {
         monsterdied++;
         monstx=700;
         misx[i]=700;
     }
   misx[i] +=4;
        }

    }

}


}


void monster(int a, int b,int c)
{
    if(monsterdied<c)
    {

    setfillstyle(SOLID_FILL,GREEN);
    bar(a-30,b-30,a,b);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(a-15,b-8,10,10);
    setfillstyle(SOLID_FILL,RED);

    fillellipse(a-10,b-20,4,4);
    fillellipse(a-20,b-20,4,4);

     if(monstx<x)
     {monstx=700;
      monsty=700;
     }

     if(a<monstx) // to detect nearest monster
     {
         monstx=a;
        monsty=b;
     }


    }

}


void makeportalv(int a,int b,int q ,int w) //function for vertical portal
{
     setcolor(3);
      setfillstyle(SOLID_FILL, 3);

     fillellipse(a,b,20,40);
     fillellipse(q,w,20,40);
     if(x==a && y<=b+20 && y>=b-20)
     {

          y=w;
          m +=q-a;
          }
}
void makeportalh(int a,int b,int q ,int w)//horizontal portal
{

     setcolor(WHITE);
     setfillstyle(SOLID_FILL,WHITE);



     fillellipse(a,b,60,20);
     fillellipse(q,w,60,20);


     if(x>=a-30 && x<=a+30 && y==b)
     {
          y=w;
          m +=q-a;
          }
}


void map1()
{


     b1=400;
     d=h=300;
     f=150;
     b2=100;c=600;
     a1=600-m;
     a2=1000-m;
     a3=1400-m;
     a4=2000-m;
     a5=2400-m;
     a6=3100-m;
     a7=3330-m;
     a8=3560-m;
     a9=3790-m;
     monster(500-m,390,1);
     monster(800-m,130,2);
     monster(1300-m,390,3);
     monster(2000-m,90,4);

     setcolor(WHITE);
     setfillstyle(HATCH_FILL,BROWN);
     bar(0,0,650,12);
     bar(0,468,650,480);
     setcolor(LIGHTGRAY);
     int i=0;

     for(i=12 ; i<=650 ;i +=12)
     {
       int points[]={i-12,12,i,12,i-6,24,i-12,12};
       drawpoly(4,points);
       int point[]={i-12,468,i,468,i-6,456,i-12,468};
       drawpoly(4,point);
              }

     platform(a1,b1,c);

     platform(a2,b2,d);
     platform(a3,b1,d);
     platform(a4,b2,d);
     platform(a5,b1,d);
     platform(a6,b2,f);
     platform(a7,b1,f);
     platform(a8,b2,f);
     platform(a9,b1,f);

     platform(a9+500,b2+50,90);
     platform(a9+600,b2+100,90);
     monster(a9+580,b2+90,5);
     platform(a9+700,b2+150,90);
     platform(a9+800,b2+200,90);
     monster(a9+780,b2+190,6);
     platform(a9+900,b2+250,90);
     platform(a9+1000,b2+300,90);
     monster(a9+980,b2+290,7);
     platform(a9+1100,b2+350,90);

     platform(a9+1200,b2+250,90);
     monster(a9+1210,b2+280,8);
     platform(a9+1300,b2+350,90);

     platform(a9+1400,b2+250,90);
     platform(a9+1500,b2+200,90);
     monster(a9+1510,b2+230,9);
     platform(a9+1600,b2+150,90);
     platform(a9+1700,b2+100,90);
     monster(a9+1710,b2+130,10);
     makeportalv(a3-50,b1-28,a4-200,b2-40);
     makeportalv(a9-50,b1-28,a9+400,b2);
     makeportalh(a5+100,b1-250,a5+500,b1+50);




     m+=1;




}


void setup()
{
    fflush(stdin);
    score=0;
     dir='d';

     x=100;
     y=300;
    misy[100],misx[100],monstx=700,monsty,mism=0;
    monsterdied=0;
     gameover=0;


     k=4000;b=0;
     m=0;



}

void charactor()
{
    int arr[10];
      for(int i=0;i<10;i++){


                         if(i%2==0){
                            arr[i]=x+12*(sin(((PI/4)*i)+ai));
                         }
                         else{
                            arr[i]=y+12*(cos(((PI/4)*(i-1))+ai));
                         }
                       }
                        setfillstyle(SOLID_FILL,1);
                        setcolor(1);
                        fillpoly(5,arr);// 28 used is more likely the length of square or rectangle0
                        setfillstyle(SOLID_FILL,RED);
                        setcolor(RED);
                        fillellipse((arr[0]+2*arr[4])/3,(arr[1]+2*arr[5])/3,2,2);
                        fillellipse((arr[2]+2*arr[6])/3,(arr[3]+2*arr[7])/3,2,2);





    missile();

 // readimagefile("charactor.jpg",x-25,y-25,x,y);







}


void draw()
{
       map1();


     charactor();





}

void input()
{

     char s=' ';
     int k;
     k=kbhit();
      if(k==1)
     {

        s=getch();
            switch(s)
             {


                          case 'd': mis = 's';
                          break;
             }
     }
     if(k==1 && b==1)

     {

            switch(s)
             {


                          case 'w' : dir='u';
                          break;
                          case 's': dir='d';
                          break;

             }
     }



}



void logic()
{
     if(dir=='u')
     {
                 g=-2;
                 ai+=(PI/100);
     }
     else if(dir=='d')
     {
                 g=2;
                 ai-=(PI/100);
     }






      if((y==l-22 || y==(l+12)) && x<=(k+12+12) && (x)>=j-12 )
     {
      b=1;

     if(y==(l-22))
      {
                   if(g==2)
                    {     g=0;
                    }
      }
      else if(y==(l+12))
      {
                   if(g==-2)
                    {     g=0;
                    }
      }
     }
     else{b=0;}



     y +=g;

     if(y<36 || y>456)
     {
            gameover=1;
     }

     if((x>monstx-30 && x<(monstx)) && (y<monsty && y>(monsty-30)))
     {
         gameover=1;
     }



}
    void game()
    {
        setbkcolor(0);
   cleardevice();
   setup();
   int page=0;

   while(!gameover)
   {

                    delay(1);

                   setactivepage(page);
                   setvisualpage(1-page);
                   cleardevice();
                   draw();
                   input();
                   logic();
                   char scoreary[100];
                   sprintf(scoreary,"%s: %d","SCORE",score);
                   settextstyle(3,0,2);
                   setcolor(15);
                   outtextxy(300,485,scoreary);
                  page=1-page;
                  score++;

   }

   setvisualpage(1-page);


   setcolor(4);

    settextstyle(1,0,4);
   outtextxy(200,200,"Game Over");
   setcolor(WHITE);
   outtextxy(50,400,"Press any key to continue...");

   getch();




   checkscore();
   cleardevice();
    setup();



    }




int main()
{
   int  gd = DETECT, gm;

   initgraph(&gd,&gm,"");
   initwindow(650,520,"Gravity",500,200);
   initsplashscreen();

   cleardevice();
   while(1)
   {
   mainmenu();
   }



   closegraph();

   return 0;
}
