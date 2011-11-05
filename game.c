// CHOCOSTICKS Simulator
// AUTHOR	: Chinmay V S
// DATE		: 02-DEC-2007

#define PLAYER 0
#define COMP 1

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

char str[10];
char x;

int i,j,gd=DETECT,gm,maxx,maxy;
int sticks=21,psticks=0,csticks=0,turn;

int x1[20]={530,540,560,580,100,120,140,160,180,200,220,220,240,260,280,300,320,340,360,400};
int y1[20]={434,435,445,453,440,434,435,445,439,435,445,434,439,440,437,446,445,439,438,440};
int dx[20]={-1,2,1,-2,-1,1,-2,1,-2,1,-2,1,-2,-1,2,-1,2,-3,1,2};
int dy[20]={-1,2,-3,1,3,-2,1,-1,3,-2,-1,2,3,1,3,3,3,2,-1,-1};


int color[20];
int area[5];
char *ball[5];

struct fillsettingstype fs;
union REGS in,out;

void getball()
{
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	circle(200,450,4);
	floodfill(200,450,GREEN);
		setcolor(LIGHTGREEN);
		setfillstyle(1,LIGHTGREEN);
		circle(200,450,2);
		floodfill(200,450,LIGHTGREEN);
			area[0]=imagesize(196,446,204,454);
			ball[0]=malloc(area[0]);
			getimage(196,446,204,454,ball[0]);

	setcolor(RED);
	setfillstyle(1,RED);
	circle(200,450,4);
	floodfill(200,450,RED);
		setcolor(LIGHTRED);
		setfillstyle(1,LIGHTRED);
		circle(200,450,2);
		floodfill(200,450,LIGHTRED);
			area[1]=imagesize(196,446,204,454);
			ball[2]=malloc(area[1]);
			getimage(196,446,204,454,ball[1]);


	setcolor(BLUE);
	setfillstyle(1,BLUE);
	circle(200,450,4);
	floodfill(200,450,BLUE);
		setcolor(LIGHTBLUE);
		setfillstyle(1,LIGHTBLUE);
		circle(200,450,2);
		floodfill(200,450,LIGHTBLUE);
			area[2]=imagesize(196,446,204,454);
			ball[2]=malloc(area[2]);
			getimage(196,446,204,454,ball[2]);

	setcolor(MAGENTA);
	setfillstyle(1,MAGENTA);
	circle(200,450,4);
	floodfill(200,450,MAGENTA);
		setcolor(LIGHTMAGENTA);
		setfillstyle(1,LIGHTMAGENTA);
		circle(200,450,2);
		floodfill(200,450,LIGHTMAGENTA);
			area[3]=imagesize(196,446,204,454);
			ball[3]=malloc(area[3]);
			getimage(196,446,204,454,ball[3]);

	setcolor(BROWN);
	setfillstyle(1,BROWN);
	circle(200,450,4);
	floodfill(200,450,BROWN);
		setcolor(YELLOW);
		setfillstyle(1,YELLOW);
		circle(200,450,2);
		floodfill(200,450,YELLOW);
			area[4]=imagesize(196,446,204,454);
			ball[4]=malloc(area[4]);
			getimage(196,446,204,454,ball[4]);

	for(i=0;i<20;i++)
		color[i]=i%5;

	setfillstyle(1,BLACK);
	bar(195,445,205,455);

}

void drawball()
{

	int j,oldx1[20],oldy1[20];

	for(j=0;j<20;j++) {
		oldx1[j]=x1[j];
		oldy1[j]=y1[j];
		x1[j]+=dx[j];
		y1[j]+=dy[j];

		if(x1[j]>615 || x1[j]<15) dx[j]=-dx[j];
		if(y1[j]>455 || y1[j]<430) dy[j]=-dy[j];

		putimage(oldx1[j],oldy1[j],ball[color[j]],OR_PUT);
		putimage(oldx1[j],oldy1[j],ball[color[j]],XOR_PUT);
		putimage(x1[j],y1[j],ball[color[j]],XOR_PUT);
	}

}

void menudraw(int choice)
{
	setfillstyle(1,BLACK);
	bar(474,203,565,342);

	setlinestyle(0,0,3);
	setcolor(LIGHTGRAY);
	rectangle(475,286,564,341);
	setlinestyle(2,0,1);
	setcolor(BLACK);
	rectangle(476,287,563,340);
	rectangle(474,285,565,342);

	settextstyle(0,0,1);
	setfillstyle(1,RED);
	setlinestyle(3,0,1);

	switch(choice) {

	case 0:
		bar(474,203,565,222);
		setcolor(WHITE);
		rectangle(474,203,565,222);
		setcolor(WHITE);
		rectangle(475,204,564,221);
		setcolor(LIGHTGRAY);
		rectangle(476,205,563,220);
		setfillstyle(1,YELLOW);
		//setfillstyle(1,BLACK);
		bar(477,206,562,219);
		setcolor(WHITE);
		outtextxy(480,300," Click to");
		outtextxy(480,320,"START GAME");
		break;

	case 1:
		bar(474,223,565,242);
		setcolor(WHITE);
		rectangle(474,223,565,242);
		setcolor(WHITE);
		rectangle(475,224,564,241);
		setcolor(LIGHTGRAY);
		rectangle(476,225,563,240);
		setfillstyle(1,YELLOW);
		//setfillstyle(1,BLACK);
		bar(477,226,562,239);
		setcolor(WHITE);
		outtextxy(503,300,"View");
		outtextxy(482,320,"MORE HINTS");
		break;

	case 2:
		bar(474,243,565,262);
		setcolor(WHITE);
		rectangle(474,243,565,262);
		setcolor(WHITE);
		rectangle(475,244,564,261);
		setcolor(LIGHTGRAY);
		rectangle(476,245,563,260);
		setfillstyle(1,YELLOW);
		//setfillstyle(1,BLACK);
		bar(477,246,562,259);
		setcolor(WHITE);
		outtextxy(489,295,"Designer");
		outtextxy(492,315,"CHINMAY");
		outtextxy(492,325,"  V.S");
		break;

	case 3:
		bar(474,263,565,282);
		setcolor(WHITE);
		rectangle(474,263,565,282);
		setcolor(WHITE);
		rectangle(475,264,564,281);
		setcolor(LIGHTGRAY);
		rectangle(476,265,563,280);
		setfillstyle(1,YELLOW);
		//setfillstyle(1,BLACK);
		bar(477,266,562,279);
		setcolor(WHITE);
		outtextxy(480,300," Click to");
		outtextxy(485,320,"EXIT GAME");
		break;
	}


	setcolor(MAGENTA);
	outtextxy(490,210,"PLAY NOW");
	outtextxy(500,230,"HINTS");
	outtextxy(490,250,"ABOUT US");
	outtextxy(505,270,"EXIT");

}

char msg(int type,const char far *_text,int blink,int wait)
{
	int prevcolor;
	struct fillsettingstype prevfs;
	struct textsettingstype prevtxt;

	getfillsettings(&prevfs);
	prevcolor=getcolor();
	gettextsettings(&prevtxt);

	settextstyle(0,0,1);

	do {
		//Draws/Clears Message Block
		if(blink!=0) {
			setcolor(YELLOW);
			for(i=0;i<18;i++) {
				line(0,maxy-i,maxx,maxy-i);
				delay(3);
			}
		}

		if(type==0) {
			sound(100);
			delay(200);
			sound(300);
			delay(50);
			sound(150);
		} else if(type==1) {
			sound(100);
			delay(250);
			sound(150);
		}

		delay(125);

		//Writes Text
		if(type==0) {
			sound(650);
			setcolor(LIGHTRED);
		} else if (type==1) {
			//sound(850);
			setcolor(BLUE);
		}

		if(blink!=0) outtextxy(5,maxy-10,_text);

		delay(400);

		if(type==2) {
			if(blink!=0) {
				setcolor(GREEN);
				outtextxy(5,maxy-10,_text);
			}

			for(i=3;i<=14;i++) {
				sound(i*100);
				delay(180-(i*10));
			}

			sound(1050);
			delay(200);
			sound(800);
			delay(750);
			sound(250);
			delay(100);
			sound(500);
			delay(300);
		}

		nosound();
		blink--;
		delay(250);

	} while(blink>0);

	settextstyle(prevtxt.font,prevtxt.direction,prevtxt.charsize);
	setfillstyle(prevfs.pattern,prevfs.color);
	setcolor(prevcolor);

	if (wait==1)
		return(getch());
	else
		return(-1);

}

/////////////////////////////////////
int initscr()
{
	int choice=0;

	clearviewport();

	setfillstyle(11,CYAN);
	bar(0,0,maxx,maxy-55);

	randomize();
	//j=random(16);
	j=BROWN;
	setlinestyle(0,0,3);
	for(i=0;i<17;i++) {
		if(i%6==0)
			setcolor(j);
		else
			setcolor(BLACK);

		rectangle(i,i,maxx-i,maxy-i);
	}

	setcolor(YELLOW);
	setfillstyle(1,BLACK);
	bar(50,30,maxx-52,44);
	outtextxy(65,33,"CVS GAME STUDIOS present");

	bar(50,98,maxx-52,112);
	outtextxy(65,101,"Designed by : Chinmay V.S");

	settextstyle(0,0,6);
	setcolor(DARKGRAY);
	outtextxy(60,50,"CHOCOSTICKS");

	setfillstyle(1,BLACK);
	bar(55,160,maxx-60,maxy-70);

	setfillstyle(1,BLUE);
	bar(65,172,460,320);

	setfillstyle(1,MAGENTA);
	bar(65,330,460,345);


	setlinestyle(0,0,1);
	setcolor(LIGHTBLUE);
	rectangle(55,160,maxx-60,maxy-70);
	setcolor(LIGHTCYAN);
	rectangle(56,161,maxx-61,maxy-71);
	setcolor(LIGHTGRAY);
	rectangle(57,162,maxx-62,maxy-72);
	setcolor(LIGHTBLUE);
	rectangle(58,163,maxx-63,maxy-73);
	rectangle(65,172,460,320);

	settextstyle(0,0,1);
	setcolor(YELLOW);
	outtextxy(70,180,"* 21 sticks on the tray");
	outtextxy(70,210,"* Player & Computer take turns Picking sticks");
	outtextxy(70,240,"* In Each Turn 1, 2, 3 or 4 sticks can be picked");
	outtextxy(70,270,"* Whoever picks the last stick loses the game");
	outtextxy(70,300,"* Toss decides who plays First");
	settextstyle(0,0,1);
	outtextxy(70,335,"Select your option & press ENTER to continue -->");

	settextstyle(1,0,3);
	setcolor(YELLOW);
	outtextxy(75,350,"\" SUCCESS is 99% EFFORT & 1% LUCK \"");
	setcolor(RED);
	outtextxy(76,351,"\" SUCCESS is 99% EFFORT & 1% LUCK \"");
	setcolor(GREEN);
	outtextxy(77,352,"\" SUCCESS is 99% EFFORT & 1% LUCK \"");

	settextstyle(0,0,1);
	setcolor(RED);
	outtextxy(398,388,"- Thomas Alva Edison");
	setcolor(GREEN);
	outtextxy(399,389,"- Thomas Alva Edison");


	setlinestyle(0,0,3);
	setcolor(LIGHTRED);
	rectangle(470,172,maxx-70,345);

	setfillstyle(1,CYAN);
	bar(474,176,565,200);
	//bar(474,285,565,342);

	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	rectangle(474,176,565,200);
	rectangle(474,285,565,342);

	setcolor(RED);
	outtextxy(494,184,"OPTIONS");
	setcolor(YELLOW);
	outtextxy(495,185,"OPTIONS");

	getball();

	MENU:

	menudraw(choice);

	settextstyle(0,0,6);
	while(!kbhit()) {
		drawball();
		i++;

		if(i<30)
			setcolor(LIGHTRED);
		else if(i<60)
			setcolor(DARKGRAY);
		else if(i<90)
			setcolor(LIGHTBLUE);
		else if(i<120)
			setcolor(DARKGRAY);
		else
			i=0;

		outtextxy(60,50,"CHOCOSTICKS");
	}


	//Get keypressed
	in.h.ah=0;
	int86(22,&in,&out);
	x=out.h.ah;

	switch(x) {
	case 72:	//UP
	case 75:	//LEFT
		choice--;
		break;

	case 80:	//DOWN
	case 77:	//RIGHT
		choice++;
		break;

	case 28:	//Enter
		return(choice);
	}

	if(choice<0) choice=256+choice;
	choice=choice%4;

	//Functions exits only after an option is selected by pressing [ENTER]

	goto MENU;

}


void gamescreen()
{
	setlinestyle(0,0,1);
	setfillstyle(10,LIGHTRED);
	bar(0,0,maxx,maxy);

	setcolor(BLUE);
	for(i=0;i<16;i++) {
	  	line(0,i,maxx,i);
		delay(10);
	}

	settextstyle(11,0,18);
	setcolor(WHITE);
	outtextxy(10,4,"CHOCOSTICKS :: CVS GAME STUDIOS");

	msg(1,"Loading Chocosticks...",1,0);

  	setfillstyle(1,CYAN);		//Draws prompt area
	bar(0,160,maxx,375);

	setfillstyle(1,GREEN);
	bar(0,375,maxx,maxy-19);

	setcolor(LIGHTMAGENTA);
	setlinestyle(0,0,3);

	rectangle(0,266,maxx,271);
	rectangle(1,160,maxx-1,375);

	line(120,160,120,375);
	line(0,375,maxx,375);

	setcolor(MAGENTA);
	line(0,maxy-21,maxx,maxy-21);
	line(maxx-1,377,maxx-1,maxy-21);
	line(1,377,1,maxy-21);


	settextstyle(4,0,3);
	setcolor(RED);
	outtextxy(40,195,"YOU");
	outtextxy(15,305,"Computer");

	settextstyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);	//Draws Tray

	bar(40,30,600,140);
	setcolor(LIGHTCYAN);
	rectangle(40,30,600,140);

	setfillstyle(1,BROWN);		//Draws Chocosticks
	for(i=1;i<=21;i++) {
		bar(37+(i*25),50,50+(i*25),110);
        	setcolor(RED);
		outtextxy(37+(i*25),120,itoa(i,&str,10));
		sound(700+(i*10));
        	delay(200-i*9);
		nosound();
	}

}

void toss()    ////TOSS
{
	setcolor(WHITE);
	outtextxy(5,385,"{TOSS}: Enter Your Choice (H)eads OR (T)ails :");
	setfillstyle(1,DARKGRAY);
	bar(360,383,370,394);

	fflush(stdin);

	do {
		x=getch();
	}while(x!='h' && x!='H'&& x!='t' && x!='T');

	setcolor(WHITE);

	if(x=='h' || x=='H')
		outtextxy(362,385,"H");
	else
		outtextxy(362,385,"T");

	outtextxy(5,400,"Coin Tossed :");

	for (i=1;i<36;i++) {
		setfillstyle(1,GREEN);
		bar(100,400,110,410);

		setcolor(YELLOW);

		if(i%4==0)
			outtextxy(100,400,"\\");
		else if(i%4==1)
			outtextxy(100,400,"|");
	        else if(i%4==2)
	        	outtextxy(100,400,"/");
		else
        		outtextxy(100,400,"-");

	        delay(40);
	}

	setcolor(WHITE);
	randomize();
	i=random(100)%2;
	line(113,403,130,403);

	if(i==0)
		outtextxy(110,400,"<  It's TAILS");
	else
		outtextxy(110,400,"<  It's HEADS");

	if( ((x=='t'||x=='T')&&i==0) || ((x=='h'||x=='H') &&i==1) ) {
		msg(1,"Player Won the TOSS",1,0);
		outtextxy(5,420,"YOU won the TOSS.Play (1)st OR (2)nd :");
		setfillstyle(1,DARKGRAY);
		bar(313,418,323,429);

		fflush(stdin);
		do {
			x=getch();
    		}while(x!='1' && x!='2');

		setcolor(WHITE);

		if(x=='1') {
			outtextxy(315,420,"1");
			turn=1;
		} else {
			outtextxy(315,420,"2");
			turn=0;
                }

        } else {
		outtextxy(5,420,"YOU lost the TOSS.");
		msg(0,"Computer Won the TOSS",1,0);
		i=random(10)%2;
		if(i==0) {
			outtextxy(150,420,"Computer chose to play First !!");
			turn=0;
		} else {
			outtextxy(150,420,"Computer chose to play Second !!");
			turn=1;
		}
        }
}

void pickstick(int who)
{

	sound(400);

	if(who==COMP) {
		setfillstyle(1,LIGHTGRAY);
		bar(37+(sticks*25),50,50+(sticks*25),110);

		setfillstyle(1,BROWN);
		bar(130+(csticks*25),290,143+(csticks*25),350);
		csticks++;
	} else {
    		setfillstyle(1,LIGHTGRAY);
	        bar(37+(sticks*25),50,50+(sticks*25),110);

        	setfillstyle(1,BROWN);
	        bar(130+(psticks*25),180,143+(psticks*25),240);
		psticks++;
	}

	sticks--;

	delay(100);
	sound(900);
	delay(40);
	nosound();
	delay(500);
}

//************************************************//
// START OF THE PROGRAM CORE ie. MAIN FUNCTION !! //
//************************************************//

void main()
{
	initgraph(&gd,&gm,"bgi");

	maxx=getmaxx();
	maxy=getmaxy();

	//for option "Play Again ??"
	do {

		splash:
		switch(initscr()) {
		case 0:
			//START GAME
			gamescreen();
			break;

		case 1:
			//HINTS
			goto splash;
			break;

		case 2:
			//about Us
			goto splash;
			break;

		case 3:
			exit(0);
		}

		msg(1,"21 Chocosticks loaded on the Tray",2,0);

		toss();


		while(sticks>1) {
			if(turn) {	//Player Move
				msg(1,"It is Players turn",1,0);

				outtextxy(5,445,"Enter No. of sticks to pick :");

				setfillstyle(1,DARKGRAY);
				bar(240,444,250,454);

				fflush(stdin);
				do {
					x=getch();
				}while(x!='1' && x!='2' && x!='3' && x!='4');

				setcolor(WHITE);

				if(x=='1')
					outtextxy(242,446,"1");
				else if(x=='2')
					outtextxy(242,446,"2");
				else if(x=='3')
					outtextxy(242,446,"3");
				else
					outtextxy(242,446,"4");


				for(i=30;i<atoi(&x);i=i+100) {
					if(sticks==0) {
						msg(1,"Chocosticks Finished !!",1,1);
						break;
					} else {
						delay(350);
						pickstick(PLAYER);
					}
				}

				turn=!turn;

			} else {	//Computer move
				msg(1,"Computer to pick Chocosticks",1,0);
				i=0;

				for(j=1;j<5;j++) {
					if((sticks-j)%5==1)
					goto LOGICAL;
				}

				randomize();
				j=1+random(4);

				for(i=1;i<=j;i++) {
					delay(400);
					pickstick(COMP);
				}

				i=5;
				turn=!turn;
				continue;

				LOGICAL:
				while(sticks%5!=1 && sticks>1 && i<4) {
					delay(600);
					pickstick(COMP);
					i++;
				}

				turn=!turn;
			}


		}

		if((turn && sticks==1) || (!turn && sticks==0))
			msg(0,"YOU Lost !! Better Luck next time",3,1);
		else
			msg(2,"Congratulations !! YOU WIN",1,1);

		cleardevice();
		setcolor(WHITE);
		outtextxy(180,235,"Play Again ?? (Y/N):");

		fflush(stdin);

		do {
		    	while(!kbhit()) {
			   	setfillstyle(1,BLACK);
				bar(335,233,340,243);
				delay(75);

				setfillstyle(1,LIGHTGREEN);
				bar(335,233,340,243);
				delay(350);

				setfillstyle(1,GREEN);
				bar(335,233,340,243);
		    		delay(150);
		    	}

			x=getche();

		}while(x!='y' && x!='Y' && x!='N' && x!='n');

		sticks=21;
		psticks=0;
		csticks=0;

	}while(x=='Y' || x=='y');

}