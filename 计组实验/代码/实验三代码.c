#include<reg51.h>
sbit LED_1=P3^6;
sbit LED_2=P3^7;   
unsigned  char  count;  
void LED_LM()  //LED����˸
{     
	LED_1=~LED_1;
	LED_2=~LED_2;
   }
   void T0_timer(void) interrupt 1 
{
    //TF0��־λ���Զ���0�����Բ��ù�
    TH0=0X00;
    TL0=0X00;
    count++;
}
void main( )
{
   TMOD=0X01;  //T0 ������ʽ1
   EA=1;       //�����ж�
   ET0=1;      //�򿪶�ʱ��0���ж�
   TH0=0X00;
   TL0=0X00;   //�Զ�ʱ��0���ó�ʼֵ�������ö�ʱʱ�� 
   TR0=1;      //��ʱ��0����λ����1ʱ��ʱ����ʼ����
   while(1){ 
     if(count==10)
     {
       count=0;
       LED_LM();
     }
   }
}

