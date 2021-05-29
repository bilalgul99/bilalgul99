//pacaman project
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
using namespace std;
struct player   // here we make the player (defining its symbol) and also provide its position
{
	char pacman;
	unsigned short xco;
	unsigned short yco;	 
	unsigned short cxco;
	unsigned short cyco;
};
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
	"0                           O",//2
	"0      #             #      O",//3
	"0      #             #      O",//4
	"0      #             #      O",//5
	"0      #             #      O",//6
	"0      #             #      O",//7
	"0      #             #      O",//8
	"0      ###############      O",//9
	"0                           O",//10
	"0         ################# O",//11
	"0              #     #      O",//12
	"0   ########     # #        O",//13
	"0   #            # #        O",//14
	"0   # ######     # #        O",//15
	"0   #            # #        O",//16
	"0   ########     # #        O",//17
	"0                # #        O",//18
	"0                           O",//19
	"0OOOOOOOOOOOOOOOOOOOOOOOOOOOO"//20 
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
	
	do{
	pc.pacman=static_cast<char>(2);
	pc.xco=15; pc.yco=16;
	ghost1.ghost=static_cast<char>(1);
	ghost1.xco=19; ghost1.yco=6; ghost1.count=0;
	ghost2.ghost=static_cast<char>(1);
	ghost2.xco=26; ghost2.yco=15; ghost2.count=0;
	ghost3.ghost=static_cast<char>(1);
	ghost3.xco=3; ghost3.yco=18; ghost3.count=0;
	
	while("BAWA G UET")
	{
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
			gameover();
		}
	cout<<"please enter y to play again"<<endl;
	cin>>hg;
	}while(hg=='y');
}
