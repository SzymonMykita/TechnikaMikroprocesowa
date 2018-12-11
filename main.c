#include <msp430.h>
char stansw;
int main(void)

{
WDTCTL=WDTPW+WDTHOLD;
P1DIR|=0X01;
P1OUT|=0X10;
P1REN|=0x10;
P1IE|=BIT3;
P1IES|=BIT3;
P1IFG &=~BIT3;
}
while(1)
{
while(1)
{
volatile unsigned int i;
stansw=P1IN & BIT3;

if(stansw==0)
{
P1OUT ^=BIT6;
}
else
{
P1OUT^=BIT0;
}
i=50000;
do(i--);
while(i !=0);	
}
