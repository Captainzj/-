#include<reg51.h>
sbit LED_1=P3^6;
sbit LED_2=P3^7;   
unsigned char buffer;
void receive() interrupt 4
{
    ES=0;
	RI=0;    //�������жϱ�־����
	buffer=SBUF;
    SBUF=buffer+1;
    while(!TI); //������buffer���ͳ�ȥ	
	TI=0;
    ES=1;
}
void main(){
             TMOD=0x20;//���ö�ʱ��1Ϊ������ʽ2
	TH1=0xd9;   //���ò�����Ϊ2400
	TR1=1;   //���ö�ʱ��1
	REN=1;  //��������
	SM0=0; //������ʽ1
	SM1=1;
	EA=1;  //CPU�ж�����λ
	ES=1;  //���п��ж�����λ
}
