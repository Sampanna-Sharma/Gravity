#ifndef UNTITLED1_H
#define UNTITLED1_H


int page=0;
char arra[6];
int cnt=1;


int initsplashscreen();

void splashScreen(char str[]){


          setbkcolor(RED);
          settextstyle(3,0,9);
          setcolor(WHITE);
          int i=0,l=180;
          static int j=180;

          for(i=0;i<100;i++){
            setactivepage(1-page);
            setvisualpage(page);

            cleardevice();
        //    delay(4);

            outtextxy(j,i,str);
            outtextxy(l,0,arra);

            page=1-page;
          }


            strcat(arra,str);

            settextstyle(2,0,10);
            j+=35;
            setcolor(BLUE);settextstyle(2,0,10);
            setcolor(BLUE);
}




int initsplashscreen(){



   delay(1000);
   splashScreen("G");
   splashScreen("r");
   splashScreen("a");
   splashScreen("v");
   splashScreen("i");
   splashScreen("t");
   splashScreen("y");
   splashScreen("");

   setvisualpage(page);
   delay(100);
   setcolor(WHITE);
   settextstyle(0,0,3);
   outtextxy(220,250,"Loading...");// Loading menu
   rectangle(100,350,600,400);
   setcolor(WHITE);
   delay(10);

   int k;
   setcolor(GREEN);
   for(k=0;k<=480;k+=2){
   line(110+k,360,110+k,390);
   delay(10);

}
//    clearBuffer(stdin);
   return 0;

}
#endif // UNTITLED1_H
