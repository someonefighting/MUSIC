#include<stdio.h>
#include<dos.h>
#include<bios.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>
#define N1 32 
#define N2 16 
#define N4 8 
#define N8 4 
#define N16 2 
#define END 0 

void printtext(unsigned char *temp[], int i, int color);

enum NOTES
{
	A0 = 28,B0 = 31,
	C1 = 33, D1 = 37, E1 = 41, F1 = 44, G1 = 49, A1 = 55, B1 = 62,
	C2 = 65, D2 = 73, E2 = 82, F2 = 87, G2 = 98, A2 = 110, B2 = 123,
	C3 = 131, D3 = 147, E3 = 165, F3 = 175, G3 = 196, A3 = 220, B3 = 247,
	C4 = 262, D4 = 294, E4 = 330, F4 = 349, G4 = 392, A4 = 440, B4 = 494,
	C5 = 523, D5 = 587, E5 = 659, F5 = 698, G5 = 784, A5 = 880, B5 = 988,
	C6 = 1407, D6 = 1175, E6 = 1319, F6 = 1397, G6 = 1568, A6 = 1760, B6 = 1976,
	/*高度音调分别是：6，2，3，4，5，6，7*/
	C7 = 2093, D7 = 2349, E7 = 2637, F7 = 2794, G7 = 3136, A7 = 3520, B7 = 3951
	/*高八度音调分别是：1，2，3，4，5，6，7*/
};
/*enum NOTES
{
	C10 = 131, D10 = 147, E10 = 165, F10 = 175, G10 = 196, A10 = 220, B10 = 247,	
	C0 = 262, D0 = 286, E0 = 330, F0 = 349, G0 = 440, A0 = 440, B0 = 494,
	C1 = 523, D1 = 158, E1 = 659, F1 = 698, G1 = 784, A1 = 880, B1 = 998,
	/*高度音调分别是：1，2，3，4，5，6，7*/
	/*C2 = 1047, D2 = 1175, E2 = 1319, F2 = 1397, G2 = 1568, A2 = 1760, B2 = 1976
	/*高八度音调分别是：1，2，3，4，5，6，7*/
/*};*/
int song0[] = {
	587, 4, 698, 4, 587, 4, 659, 4, 494, 4, 659, 4, 698, 4, 784, 4, 523, 4, 698, 4,
	698, 4, 587, 4, 440, 4, 659, 4, 880, 4, 659, 4, 349, 4, 523, 4, 698, 4, 523, 4,
	392, 4, 587, 4, 784, 4, 523, 4, 784, 4, 784, 4, 440, 4, 659, 4, 880, 4, 659, 4,
	349, 4, 523, 4, 698, 4, 523, 4, 392, 4, 587, 4, 784, 4, 523, 4, 784, 4, 784, 4,
	587, 4, 698, 4, 587, 4, 698, 4, 659, 4, 659, 4, 659, 4, 659, 4, 494, 4, 659, 4,
	698, 4, 784, 4, 698, 4, 659, 4, 698, 4, 784, 4, 784, 4, 494, 4, 659, 4, 698, 4,
	784, 4, 698, 4, 659, 4, 659, 4, 659, 4, 659, 4, 494, 4, 659, 4, 698, 4, 784, 4,
	698, 4, 392, 4, 698, 4, 784, 4, 784, 4, 880, 4, 523, 4, 698, 4, 440, 4, 659, 4,
	880, 4, 659, 4, 349, 4, 523, 4, 698, 4, 523, 4, 392, 4, 587, 4, 784, 4, 523, 4,
	784, 4, 784, 4, 440, 4, 659, 4, 880, 4, 659, 4, 349, 4, 523, 4, 698, 4, 523, 4,
	392, 4, 587, 4, 784, 4, 523, 4, 784, 4, 784, 4, 587, 4, 698, 4, 587, 4, 587, 4,
	587, 4, 659, 4, 784, 4, 659, 4, 659, 4, 784, 4, 880, 4, 587, 4, 587, 4, 587, 4,
	659, 4, 784, 4, 659, 4, 659, 4, 659, 4, 698, 4, 784, 4, 784, 4, 784, 4, 659, 4,
	784, 4, 784, 4, 659, 4, 330, 4, 698, 4, 784, 4, 698, 4, 659, 4, 523, 4, 698, 4,
	392, 4, 587, 4, 784, 4, 587, 4, 349, 4, 523, 4, 698, 4, 523, 4, 330, 4, 494, 4,
	659, 4, 494, 4, 440, 4, 659, 4, 880, 4, 659, 4, 440, 4, 587, 4, 440, 4, 349, 4,
	523, 4, 698, 4, 523, 4, 587, 4, 698, 4, 698, 4, 523, 4, 523, 4, 698, 4, 587, 4,
	494, 4, 659, 4, 698, 4, 392, 4, 784, 4, 587, 4, 587, 4, 587, 4, 659, 4, 784, 4,
	659, 4, 659, 4, 659, 4, 784, 4, 784, 4, 659, 4, 784, 4, 784, 4, 784, 4, 523, 4,
	494, 4, 698, 4, 784, 4, 698, 4, 659, 4, 523, 4, 523, 4, 523, 4, 698, 4, 698, 4,
	392, 4, 587, 4, 784, 4, 392, 4, 587, 4, 784, 4, 330, 4, 494, 4, 659, 4, 494, 4,
	440, 4, 659, 4, 880, 4, 659, 4, 440, 4, 587, 4, 440, 4, 392, 4, END };
	/*A0, N4, B0, N4, C1, N4, D1, N4, E1, N4, F1, N4, G1, N4, A1, N4, B1, N4, END };*/
int song1[] = {
	G0, N16, G0, N8, A0, N8, G0, N8, C1, N8, B0, N4, G0, N16,
	G0, N8, A0, N8, G0, N8, D1, N8, C1, N4, G0, N16, G0, N8, G1, N8,
	E1, N8, C1, N8, B0, N16, B0, N8, A0, N4, F1, N16, F1, N8, E1,
	N8, C1, N8, D1, N8, C1, N4, END, END
	/*以上是曲子代码,你可以嵌入自己喜欢的歌曲代码*a/
	/*注意:数组中的偶数元素代表音符奇数元素代表拍长.*/
};
int song2[] = {
	C10, N1, D10, N1, E10, N1, F10, N1, G10, N1, A10, N1, B10, N1,
	C10, N2, D10, N2, E10, N2, F10, N2, G10, N2, A10, N2, B10, N2,
	C10, N4, D10, N4, E10, N4, F10, N4, G10, N4, A10, N4, B10, N4,
	C10, N8, D10, N8, E10, N8, F10, N8, G10, N8, A10, N8, B10, N8,
	C10, N16, D10, N16, E10, N16, F10, N16, G10, N16, A10, N16, B10, N16,
	C0, N1, D0, N1, E0, N1, F0, N1, G0, N1, A0, N1, B0, N1,
	C0, N2, D0, N2, E0, N2, F0, N2, G0, N2, A0, N2, B0, N2,
	C0, N4, D0, N4, E0, N4, F0, N4, G0, N4, A0, N4, B0, N4,
	C0, N8, D0, N8, E0, N8, F0, N8, G0, N8, A0, N8, B0, N8,
	C0, N16, D0, N16, E0, N16, F0, N16, G0, N16, A0, N16, B0, N16,
	C1, N1, D1, N1, E1, N1, F1, N1, G1, N1, A1, N1, B1, N1,
	C1, N2, D1, N2, E1, N2, F1, N2, G1, N2, A1, N2, B1, N2,
	C1, N4, D1, N4, E1, N4, F1, N4, G1, N4, A1, N4, B1, N4,
	C1, N8, D1, N8, E1, N8, F1, N8, G1, N8, A1, N8, B1, N8,
	C1, N16, D1, N16, E1, N16, F1, N16, G1, N16, A1, N16, B1, N16,
	C2, N1, D2, N1, E2, N1, F2, N1, G2, N1, A2, N1, B2, N1,
	C2, N2, D2, N2, E2, N2, F2, N2, G2, N2, A2, N2, B2, N2,
	C2, N4, D2, N4, E2, N4, F2, N4, G2, N4, A2, N4, B2, N4,
	C2, N8, D2, N8, E2, N8, F2, N8, G2, N8, A2, N8, B2, N8,
	C2, N16, D2, N16, E2, N16, F2, N16, G2, N16, A2, N16, B2, N16, END
	/*以上是音符测试代码,你可以通过系统发出的音调选择你需要的音符*/
	/*注意:数组中的偶数元素代表音符奇数元素代表拍长.*/
};
int song3[] = {
	C0, N8, C0, N8, G0, N8, G0, N8, A0, N8, A0, N8, G0, N4,
	F0, N8, F0, N8, E0, N8, E0, N8, D0, N8, D0, N8, C0, N4,
	G0, N8, G0, N8, F0, N4, E0, N8, E0, N8, D0, N4, G0, N8,
	G0, N8, F0, N8, F0, N8, E0, N8, E0, N8, D0, N4, C0, N8,
	E0, N8, G0, N4, A0, N8, C1, N8, G0, N4, F0, N8, F0, N8,
	E0, N8, E0, N4, D0, N8, D0, N8, C0, N4, C0, N8, C0, N8,
	G0, N8, G0, N8, A0, N8, A0, N8, G0, N4, F0, N8, F0, N8,
	E0, N8, E0, N8, D0, N8, D0, N8, C0, N4, G0, N8, G0, N8,
	F0, N4, E0, N8, E0, N8, D0, N4, G0, N8, G0, N8, F0, N8,
	F0, N8, E0, N8, E0, N8, D0, N4, C0, N8, E0, N8, G0, N4,
	A0, N8, C1, N8, G0, N4, F0, N8, F0, N8, E0, N8, E0, N4,
	D0, N8, D0, N8, C0, N4, END
	/*以上是曲子代码,你可以嵌入自己喜欢的歌曲代码*/
	/*注意:数组中的偶数元素代表音符奇数元素代表拍长.*/
};
int song4[] = {
	C10, N4, B0, N4, G0, N8, A0, N4, E0, N16, D0, N8, C0, N8,
	D0, N8, G0, N8, E0, N8, E0, N4, E0, N8, G0, N8, E0, N8,
	D0, N8, D0, N4, A0, N8, A0, N8, G0, N8, A0, N8, B0, N8,
	G0, N8, G0, N8, E0, N4, C10, N8, B0, N8, G0, N8, A0, N4,
	E0, N8, D0, N8, C0, N8, D0, N8, G0, N8, E0, N4, C0, N8, D0, N8,
	E0, N4, G0, N8, E0, N8, D0, N4, C0, N8, B10, N8, C0, N8, B10, N8,
	A10, N4, A0, N8, A0, N8, A0, N8, C1, N8, D1, N8, E1, N8, E1, N8,
	C1, N8, A0, N8, A0, N8, B0, N16, A0, N16, G0, N8, E0, N8, A0, N8,
	A0, N8, C1, N8, D1, N8, E1, N8, E1, N8, C1, N8, A0, N8, A0, N8,
	B0, N8, A0, N8, B0, N16, A0, N16, G0, N8, E0, N8, D1, N16, D1, N16, D1, N8,
	D1, N8, A0, N16, B0, N16, A0, N8, G0, N8, E0, N8, D1, N16, D1, N16, D1, N8,
	A0, N16, B0, N16, A0, N8, G0, N8, E0, N8, A0, N8, A0, N8, A0, N4, A0, N8,
	A0, N8, A0, N4, C10, N8, B0, N8, G0, N8, A0, N4, E0, N16, D0, N16, C0, N8,
	D0, N8, G0, N8, E0, N4, E0, N4, E0, N16, G0, N16, E0, N16,
	D0, N16, D0, N4, A0, N16, A0, N16, G0, N8, A0, N8, B0, N8,
	G0, N16, G0, N16, E0, N4, C10, N8, B0, N8, G0, N8, A0, N4,
	E0, N16, D0, N16, C0, N8, D0, N8, G0, N8, E0, N4, C0, N16, D0, N16,
	E0, N4, G0, N8, E0, N8, D0, N4, C0, N8, B10, N8, C0, N16, B10, N16,
	A10, N4, END };

union {
	unsigned fre;
	unsigned char c[2];
}tone;

/*以下是播放程序代码*/

void MusicPlay(int *song)
{
	int note = 0, dur, control;
	clock_t goal;
	while (song[note] != 0)
	{
		tone.fre = song[note];
		dur = song[note + 1];   /*节拍*/
		if (kbhit())break;
		/*int kbhit()函数返回最近所敲的按键*/
		if (tone.fre)
		{
			outportb(0x43, 0xB6);
			/*函数void outportb(int port,char byte)
			将字节byte写入指定的输出端口port*/
			tone.fre = (unsigned)(1193180L / tone.fre);
			outportb(0x42, tone.c[0]);
			outportb(0x42, tone.c[1]);
			control = inportb(0x61);
			/*函数int inportb(int port)从指定的
			输入端口读入一个字节,并返回这个字节*/
			outportb(0x61, (control) | 0x3);
		}
		goal = (clock_t)dur + clock();
		while (goal>clock());
		if (tone.fre)
			outportb(0x61, control);
		goal = (clock_t)0;
		note = note + 2;
	}
}
/*以下是主函数其中包括异常处理*/
void main(void)
{
	int n;
	int graphdriver, graphmode;
	unsigned char  *text[7];
	text[0] = "       ";
	text[1] = "start  music........";
	text[2] = "play the one music";
	text[3] = "play the two music";
	text[4] = "play the three music";
	text[5] = "play the four music";
	text[6] = "good_bye............";
	graphdriver = DETECT;
	graphmode = 0;
	initgraph(&graphdriver, &graphmode, "C:\\TC20\\BGI");       /*系统初始化 */
	cleardevice();                            /* 清除屏幕 */

	settextjustify(LEFT_TEXT, CENTER_TEXT);   /*设置字符排列方式*/


	printtext(text, 1, 1);
	getch();
	printtext(text, 2, 62);
	MusicPlay(song0);
	getch();
	printtext(text, 3, 4);
	MusicPlay(song2);
	getch();
	printtext(text, 4, 58);
	MusicPlay(song3);
	getch();
	printtext(text, 5, 61);
	MusicPlay(song4);
	getch();
	printtext(text, 6, 63);
	getch();
	closegraph();
}
void printtext(unsigned char *temp[], int i, int color)
{
	setcolor(color);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	outtextxy(100, 40 + i * 50, temp[i]);         /* 显示字符串 temp[i]是具体的指针*/
}