#include<graphics.h>
//pacaman project
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<sstream>
using namespace std;
struct player   // here we make the player (defining its symbol) and also provide its position
{
	char pacman;
	unsigned short xco;
	unsigned short yco;	 
	unsigned short cxco;
	unsigned short cyco;
};
char scrw[5]={     };
player pc;
unsigned int score=0;
struct enemy
{
	char ghost;
	unsigned short xco;
	unsigned short yco;	 
	unsigned short cxco;
	unsigned short cyco;
	unsigned short count;
};
enemy ghost1;
enemy ghost2;
enemy ghost3;
char biscuit=static_cast<char>(248);
char arrena[20][30] ={          //here we defined the arfena space 
//   12345678901234567890123456789
	"OOOOOOOOOOOOOOOOOOOOOOOOOOOOO",//1
	"O                           O",//2
	"O      #             #      O",//3
	"O      #             #      O",//4
	"O      #             #      O",//5
	"O      #             #      O",//6
	"O      #             #      O",//7
	"O      #             #      O",//8
	"O      ###############      O",//9
	"O                           O",//10
	"O         ################# O",//11
	"O              #     #      O",//12
	"O   ########     # #        O",//13
	"O   #            # #        O",//14
	"O   # ######     # #        O",//15
	"O   #            # #        O",//16
	"O   ########     # #        O",//17
	"O                # #        O",//18
	"O                           O",//19
	"OOOOOOOOOOOOOOOOOOOOOOOOOOOOO"//20 
	};
void getarrena()
{
	cout<<endl<<endl<<endl;
	for(int i=0;i<20;i++)
	{	cout<<"\t\t\t";
			/*for(int j=0;j<30;j++)
		{
			if(i==pc.yco&&j==pc.xco)
			{
				cout<<pc.pacman;
			}
		}*/cout<<arrena[i];cout<<endl;
	}
}
void graphicarrena()
{
		for(int i=0;i<20;i++)
	{
		int y=50+30*i;
	outtextxy(100,y,arrena[i]);
	}
}

void fresharrena()
{
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<29;j++)
		{
			char c=arrena[i][j];
			if((c=='#')||(c=='O'))
			;
			else{arrena[i][j]=' ';}
		}
	}
}
void ghostpath(unsigned short& px,unsigned short& nx,unsigned short& py ,unsigned short& ny)
{
	if(px>pc.xco)
	{
		nx=px-1;
	}
	else if(px<pc.xco)
	{
		nx=px+1;
	}
	else
	{
		nx=px;
	}
	if(py>pc.yco)
	{
		ny=py-1;
	}
	else if(py<pc.yco)
	{
		ny=py+1;
	}
	else
	{
		ny=py;
	}
	if(py==pc.yco&&px==pc.xco) 
	{ny==pc.yco;nx==pc.xco;}
}
void getmove()
{
	if(GetAsyncKeyState(VK_DOWN))
	{
		pc.cyco=pc.yco+1;
	}
	 if(GetAsyncKeyState(VK_RIGHT))
	{
		pc.cxco=pc.xco+1;
	}
	 if(GetAsyncKeyState(VK_LEFT))
	{
		pc.cxco=pc.xco-1;
	}
	 if(GetAsyncKeyState(VK_UP))
	{
		pc.cyco=pc.yco-1;
	}
}

bool checkmove(unsigned short i,unsigned short j)
{
//	int j=pc.cxco;
//	int i=pc.cyco;
	char c=' ';
	char d=pc.pacman;
	char e=ghost1.ghost;
	if(arrena[i][j]==c||arrena[i][j]==biscuit||arrena[i][j]==d||arrena[i][j]==e)
	{return true;}
	else
	{return false;}
}
void makemove(unsigned short& px,int nx ,unsigned short& py,int ny)
{
	if((px==pc.xco)&&(py==pc.yco)&&(arrena[ny][nx]==biscuit))
	{ //cout<<"biscuit cindiotion true"<<endl; 
	score++; } 
	if(px==ghost1.xco&&py==ghost1.yco)
	{
		arrena[py][px]=biscuit;
	}
	else if(px==ghost2.xco&&py==ghost2.yco)
	{
		arrena[py][px]=biscuit;
	}
	else if(px==ghost3.xco&&py==ghost3.yco)
	{
		arrena[py][px]=biscuit;
	}
	
	else{arrena[py][px]=' ';}
	px=nx;
	py=ny;
}
void ghostsmove()
{
	if(checkmove(ghost1.cyco,ghost1.cxco)&&ghost1.count>=5)
		{
			ghost1.count=0;
			makemove(ghost1.xco,ghost1.cxco,ghost1.yco,ghost1.cyco);}
	 	else
	 	{
	 		ghost1.count++;
		 }
	
	
	if(checkmove(ghost2.cyco,ghost2.cxco)&&ghost2.count>=9)
		{
			ghost2.count=0;
			makemove(ghost2.xco,ghost2.cxco,ghost2.yco,ghost2.cyco);}
	 	else
	 	{
	 		ghost2.count++;
		 }
		 
	if(checkmove(ghost3.cyco,ghost3.cxco)&&ghost3.count>=10)
		{
			ghost3.count=0;
			makemove(ghost3.xco,ghost3.cxco,ghost3.yco,ghost3.cyco);}
	 	else
	 	{
	 		ghost3.count++;
		 }
}
void gameover()
{
	system("cls");
	for(int i=0;i<20;i++)
	{
		cout<<"\t";
		for(int j=0;j<30;j++)
		{
			if(i==0||i==19||j==0||j==29)
			{
				cout<<"#";
			}
			else if(i!=9&&i!=11)
			{
				cout<<" ";
			}
			
		}if(i==9)
			cout<<"        GAME OVER         ##";
		if(i==11)
		cout<<"        SCORE = "<<setw(4)<<score<<"      ##";
		cout<<endl;
	}Sleep(2000);
}
char hg;
int main()
{
	score=0;
	//pc.pacman=static_cast<char>(2);
	pc.pacman='X';
	pc.xco=15; pc.yco=16;
	ghost1.ghost='W';
	ghost1.xco=19; ghost1.yco=6; ghost1.count=0;
	ghost2.ghost=static_cast<char>(1);
	ghost2.xco=26; ghost2.yco=15; ghost2.count=0;
	ghost3.ghost=static_cast<char>(1);
	ghost3.xco=3; ghost3.yco=18; ghost3.count=0;
	settextstyle(8,0,4);
	initwindow(1200,980,"wdwdw");
    setbkcolor(2);
	cleardevice();
	settextstyle(8,0,4);
	
	while("BAWA G UET")
	{
		arrena[pc.yco][pc.xco]=pc.pacman;
		arrena[ghost1.yco][ghost1.xco]='W';
		arrena[ghost3.yco][ghost3.xco]='W';
		arrena[ghost2.yco][ghost2.xco]='W';
	outtextxy(800,30,"score = ");
	string scr;
	stringstream ss;
	ss<<score;
	ss>>scr;
	//char scrw[scr.size()+1];
	scr.copy(scrw,scr.size()+1);
	outtextxy(950,30,scrw);
		
		graphicarrena();	
		arrena[pc.yco][pc.xco]=pc.pacman;
		arrena[ghost1.yco][ghost1.xco]=ghost1.ghost;
		arrena[ghost2.yco][ghost2.xco]=ghost2.ghost;
		arrena[ghost3.yco][ghost3.xco]=ghost3.ghost;
		system("cls");
		getarrena();
		
		cout<<" score = "<<score<<endl;
	//	cout<<"ghost1 count"<<ghost1.count;
	//	cout<<"ghost2 count"<<ghost2.count;
	//	cout<<"ghost3 count"<<ghost3.count;
		pc.cxco=pc.xco;pc.cyco=pc.yco; //erasing ther previous proposed move , this statement prevents a clash of second axis movement
		getmove();
		if(checkmove(pc.cyco,pc.cxco))
		{
			makemove(pc.xco,pc.cxco,pc.yco,pc.cyco);
		//	graphicsmove();
		}
		ghostpath(ghost1.xco,ghost1.cxco,ghost1.yco,ghost1.cyco);
		ghostpath(ghost2.xco,ghost2.cxco,ghost2.yco,ghost2.cyco);		
		ghostpath(ghost3.xco,ghost3.cxco,ghost3.yco,ghost3.cyco);		

		if((ghost1.xco==pc.xco&&ghost1.yco==pc.yco)||(ghost2.xco==pc.xco&&ghost2.yco==pc.yco)||(ghost3.xco==pc.xco&&ghost3.yco==pc.yco))
		{goto gameover;}
		
		ghostsmove();
		Sleep(100);
		
	}
	gameover:
		{
			cleardevice();
			settextstyle(8,0,10);
			outtextxy(200,300," GAME OVER ");
			outtextxy(300,500,"SCORE= ");
			outtextxy(800,500,scrw);
			delay(1000);
			getchar();
			gameover();
			getch();
		}
	system("cls");	
}
