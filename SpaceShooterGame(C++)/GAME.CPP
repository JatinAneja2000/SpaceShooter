/*
**********************************************
NAME    : JATIN ANEJA.                       *
CLASS   : XI - A.                            *
PROJECT : GAME - SPACE SHOOTER.              *
DATE    : 11.01.2018                         *
**********************************************
*/
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>

//BIGNNING OF THE GAME
//THIS GAME IS ABOUT SHOOTING THE STARS FALLING TOWARDS US......


xp[20],yp[20];
// This function is for design and movement of SPACESHIP...
void bar(int z)
{
		    window(z+1,22,70,25);
		    textcolor(WHITE);
		    cprintf("     %c     ",219);
		    window(z+1,23,70,25);
		    cprintf("    %c",222);
		    textcolor(RED);
		    cprintf("%c",219);
		    textcolor(WHITE);
		    cprintf("%c   ",221);
		    window(z+1,24,70,25);
		    cprintf("   %c",222);
		    textcolor(RED);
		    cprintf("%c",219);
		    cprintf("%c",223);
		    cprintf("%c",219);
		    textcolor(WHITE);
		    cprintf("%c   ",221);
}
const int sz=6;
int xx[sz],yy[sz];

// This Function is for upward movements of SHOOTS.

static scr=0;       // variable for scoring
void up()
{
	    int flag=0,k,i;

	   // functioning of stars
	   //Random Appearence of stars on window.

	    for( i=0;i<sz&&xx[i]!=0;i++)
			{
			   for(k=0;k<20;k++)

			     { if(xx[i]==xp[k] && yy[i]==yp[k] && xp[k]!=0)
				   {
				     xx[i]=0;
				     window(73,20,80,24);
				     scr++;
				     textcolor(15);
				     cprintf("%d",scr);
			       if(scr<10)

				      cprintf("   ");
				else
				      cprintf(" ");

				   }

			      }

			   }
	       // functioning of shoots..

	    textcolor(10);
	    for(i=0;i<20;i++)
		{
		   if(xp[i]!=0)
		    {
			  flag++;
			  window(xp[i],yp[i],xp[i]+1,yp[i]+1);
			  if(yp[i]!=1)
			  cprintf("%c",4);
			  window(xp[i],yp[i]+1,xp[i]+1,yp[i]+2);
			  if(yp[i]!=21)
			  cprintf(" ");
			  yp[i]--;
			  delay(22/flag);
		    }
		    if(yp[i]==0)
			 xp[i]=0;
	       }
	    textcolor(WHITE);
}
// this functions is to display the status
//PLAYING    status=1
//PAUSE      status=2
//STOPPED    status=3
void status(int x)
	{
	  window(66,17,79,19);
	 if(x==1)
	    {
	     textcolor(LIGHTGREEN);
	     cprintf("PLAYING ");
	    }
	 else if(x==2)
	    {
	      textcolor(RED);
	      cprintf("   PAUSED   ");
	    }
	 else
	    {
	     textcolor(LIGHTGREEN);
	     cprintf("   STOPPED   ");

	    }

}

// This function is for downward random movements of STARS  connected to functin up()

void down()
{
		 int x,i;
		 if(random(10)==1)
		      {
			  x=random(52)+7;
			  textcolor(12);
			  for(i=0;i<sz;i++)
			     {
			       if(xx[i]==0)
				{
				 xx[i]=x;
				 yy[i]=2;
				 window(xx[i],yy[i],xx[i]+1,yy[i]+1);
				 cprintf("*");
				 break;
				}
			      }
			  for(i=0;i<sz;i++)
			       {
				 if(random(2))
				   {
				       window(xx[i],yy[i],xx[i],yy[i]+2);
				       cprintf("+#");
				       if(yy[i]>=20)
				     {
				       status(3);
				       sound(100);
				       delay(210);
				       nosound();
				       sound(250);
				       delay(100);
				       nosound();
				       sound(100);
				       delay(210);
				       nosound();
				       sound(250);
				       delay(250);
				       nosound();
				       scr=0;
//				       getch();
				       break;
				     }
			      yy[i]++;
			    }
		       }
		   textcolor(WHITE);
		   delay(250);
	   }
}
void soundd()
{
 int i;
 setcolor(13);
 rectangle(0,0,6,6);
 setcolor(11);
 rectangle(0,0,6-10,6-10);
 setfillstyle(SOLID_FILL,BLACK);
 floodfill(6/2,6/2,11);
    for(i=1;i<5;i++)
	{
	   sound(i*50);
	   setcolor(i);
	   settextstyle(DEFAULT_FONT,HORIZ_DIR,i);
	   outtextxy(50,100,"J A T I N");
	   outtextxy(100,200,"G A M E S");
	   outtextxy(150,300,"P R E S E N T S");
	   setcolor(BLACK);
	   delay(1000);
	   outtextxy(50,100,"J A T I N");
	   outtextxy(100,200,"G A M E S");
	   outtextxy(150,300,"P R E S E N T S");
	   }
	   nosound();
	   cleardevice();
	   setbkcolor(BLACK);
}// starting page


void main()
{

	    START:	 randomize();
			 int gd=DETECT,gm=DETECT;
			 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
			 clrscr();

			 soundd();

			 setcolor(YELLOW);
			 settextstyle(0,0,5);
			 setbkcolor(BLACK);
			 int j;
		      for(int u=0;u<100;u+=10)                 //loop for MENU PAGE.
		      {
			  setcolor(YELLOW);
			  outtextxy(50,0+u,"SPACE SHOOTER");
			     for(j=0;j<200;j++)
				  {
				       putpixel(random(640),random(480),WHITE);
				  }
				  delay(40);

				  setcolor(BLACK);
				  outtextxy(50,0+u,"SPACE SHOOTER");

		      }
			  setcolor(YELLOW);
			  setcolor(12);
			  settextstyle(0,0,3);
			  outtextxy(75,300,"S - START");
			  setcolor(12);
			  settextstyle(0,0,3);
			  outtextxy(75,330,"E - EXIT");
			  setcolor(YELLOW);

			  settextstyle(0,0,3);
			  outtextxy(155,210,"MISSION TO...");
			  settextstyle(0,0,3);
			  outtextxy(200,240,"KILL THE MARSIONS");
			  setcolor(LIGHTGREEN);
			  settextstyle(0,0,2);
			  outtextxy(120,400,"WAIT..!LET THE MISSION BEGIN ..");
		      for(int l=35;l<255;l++)
			 {
			   setcolor(rand()%16);
			   settextstyle(0,0,5);
			   outtextxy(75,100,"SPACE SHOOTER");

			  }
			  getch();
			  char ch2;
	    while(1)
		 {
		    if(kbhit())
			{
			      ch2=getch();
			      if(ch2=='e'||ch2=='E')                // to exit the game
				   {
				      cleardevice();
				      for(int l=35;l<255;l++)
					 {
					   putpixel(random(640),random(480),WHITE);
					   setcolor(rand()%16);
					   settextstyle(0,0,5);
					   outtextxy(200,130,"THANKS");
					   outtextxy(250,180,"FOR");
					   outtextxy(200,230,"PLAYING...");
					  }
					   getch();
					   exit(0);
				   }
			      else if(ch2=='s'||ch2=='S')            // to start the  game
				   {
				       break;
				   }

			    }
		      }

	 cleardevice();
	 int y;                    // LOOP FOR THE LOADING PAGE
	 setcolor(BLACK);

		 for( y=35,j=0;y<555,j<1000;y++,j++)
			 {
			    line(25+y,170,25+y,200);
			 }
		 for(y=35;y<555;y++)
			  {
			    putpixel(random(640),random(480),WHITE);
			    delay(15);
			    setcolor(RED);
			    line(25+y,170,25+y,200);
			    delay(20);
			    setcolor(WHITE);
			    settextstyle(2,0,16);
			    outtextxy(220,220,"LOADING");
			    delay(10);
			    setcolor(rand()%16);
			    settextstyle(2,0,16);
			    outtextxy(390,220,"....");
			    delay(10);

			   }

			setcolor(WHITE);
			outtextxy(50,350,"PRESS ANY KEY TO START..");
			getch();
			closegraph();
	       //CLOSEGRAPH

		       clrscr();                       // instruction for game
		       char ch ;
		       _setcursortype(_NOCURSOR);
		       randomize();
		       cprintf("                                                               INSTRUCTIONS");
		       for(int i=0;i<18;i++);
		       cprintf("\n                                                           ");
		       window(66,2,78,24);
		       textcolor(11);
		       cprintf("Press X      ");
		       cprintf("to exit___   \n");
		       textcolor(14);
		       cprintf("Press P to   ");
		       cprintf("Pause  game__\n");
		       textcolor(14);
		       cprintf("Press r to   ");
		       cprintf("RESTART game_\n");
		       textcolor(11);
		       cprintf("Press Space  ");
		       cprintf("to shoot__   \n");
		       textcolor(14);
		       cprintf("Press Left,  ");
		       cprintf("Right to move  \n");
		       textcolor(WHITE);
		       cprintf("______    \n ");
		    //   cprintf(" Playing , Pause , Stoped    \n");
		       cprintf("Score :      ");
		       cprintf("          ");
		       //getch return ;
	    int x=0;
	    for(i=0;i<20;i++)
		    {
		      xp[i]=0;
		     }
	    for(i=0;i<sz;i++)
		    {
		     xx[i]=0;
		    }
	    bar(x);

	 while(1)                  // infinity loop generated for RANDOM AND CONTINUES MOVEMENTS FOR STARS AND SHOOTS
	 {
		      status(1);
			       while(!kbhit())
				    {
				     up();
				     down();
				     }
				ch=getch();
		 switch(tolower(ch))
			 {
			    case 'p': status(2);                //TO PAUSE THE GAME
					  sound(1500);
					  delay(110);
					  nosound();
					  sound(500);
					  delay(200);
					  nosound();
					  sound(2200);
					  delay(150);
					  nosound();
					  getch();

			    case ' ': sound(600);                  //TO SEND SHOOTS
					 delay(40);
					 nosound();
					 sound(1500);
					 delay(40);
					 nosound();
				   for(i=0;i<20;i++)
					 {
					       if(xp[i]==0)
						   {
						       xp[i]=x+6;
						       yp[i]=21;
						       break;

						   }
					 }

					 break;


			  case 0 : ch=getch();                  // FOR RIGHT-LEFT MOVEMENTS OF SPACESHIP.
					 if(ch==75 && x>0)
					    {
						x-=1;
						bar(x);
					     }
					  else if (ch==77&&x<55)
					     {
						x+=1;
						bar(x);
					     }
					   break;
			   case 'x':  randomize();
				      int gd=DETECT,gm=DETECT;
				      initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				      cleardevice();
				      for(int l=35;l<255;l++)
					 {
					   putpixel(random(640),random(480),WHITE);
					   setcolor(rand()%16);
					   settextstyle(0,0,5);
					   outtextxy(200,130,"THANKS");
					   outtextxy(250,180,"FOR");
					   outtextxy(200,230,"PLAYING...");
					  }
					   getch();
					   exit(0);	 // TO EXIT FORM THE GAME
					   closegraph;
					   break;
			   case 'r':  goto START;        // TO RESTART THE GAME.



		      }
		}

	 }
//ENDING OF THE GAME.