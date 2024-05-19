#include <atari_lynx/suzy.h>
#include <atari_lynx/mikey.h>

// https://www.monlynx.de/lynx/hardware.html 

void SUZY_wait()
{
	__asm {
	ldx #$00
	waitsuzy:
	stx $fd91
	lda $fc92
	lsr
	bcs waitsuzy
	};
}



void lynx_init() {
	//	vid memory to the furthest point from code 
	//	right at the top of ram 
	SUZY.scbaddr = (unsigned char*)0xc000;
	SUZY.vidadr=(unsigned char*)0xc000;
	SUZY.coladr=(unsigned char*)0xbc00; 
	SUZY.hoff = 8;
	SUZY.voff = 8;
	SUZY.sprsys = 0;
	SUZY.sprinit = 0xf3;	//	at least 100ms before sprites are drawn 
	MIKEY.dispctl = DISPCTL_4BIT | DISPCTL_COLOR | DISPCTL_ENABLE;
	SUZY.suzybusen = 1;

	MIKEY.timer0.reload = 0x9e;
	MIKEY.timer0.control = 0x18;

	MIKEY.timer2.reload = 0x68;
	MIKEY.timer2.control = 0x1f;

	MIKEY.pkbkup = 0x29;
}

int main(void)
{
	unsigned char q=0;
	unsigned char *ptr;
	ptr = (unsigned char*)0xc000;
	lynx_init();
	while(1)
	{
		SUZY_wait();
		MIKEY.palette_RB[0]=MIKEY.timer2.count;
		ptr[q++]=ptr[q-2];
	}
	return 0;
}
