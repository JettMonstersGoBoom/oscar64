
/* Suzy Hardware Registers */
struct __suzy {
  unsigned int  tmpadr;         // 0xFC00  Temporary address
  unsigned int  tiltacc;        // 0xFC02  Tilt accumulator
  unsigned int  hoff;           // 0xFC04  Offset to H edge of screen
  unsigned int  voff;           // 0xFC06  Offset to V edge of screen
  unsigned char *sprbase;       // 0xFC08  Base address of sprite
  unsigned char *colbase;       // 0xFC0A  Base address of collision buffer
  unsigned char *vidadr;        // 0xFC0C  Current vid buffer address
  unsigned char *coladr;        // 0xFC0E  Current col buffer address
  unsigned char *scbnext;       // 0xFC10  Address of next SCB
  unsigned char *sprdline;      // 0xFC12  start of sprite data line address
  unsigned char *hposstrt;      // 0xFC14  start hpos
  unsigned char *vposstrt;      // 0xFC16  start vpos
  unsigned char *sprhsize;      // 0xFC18  sprite h size
  unsigned char *sprvsize;      // 0xFC1A  sprite v size
  unsigned int  stretchl;       // 0xFC1C  H size adder
  unsigned int  tilt;           // 0xFC1E  H pos adder
  unsigned int  sprdoff;        // 0xFC20  offset to next sprite data line
  unsigned int  sprvpos;        // 0xFC22  current vpos
  unsigned int  colloff;        // 0xFC24  offset to collision depository
  unsigned int  vsizeacc;       // 0xFC26  vertical size accumulator
  unsigned int  hsizeoff;       // 0xFC28  horizontal size offset
  unsigned int  vsizeoff;       // 0xFC2A  vertical size offset
  unsigned char *scbaddr;       // 0xFC2C  address of current SCB
  unsigned char *procaddr;      // 0xFC2E  address of current spr data proc
  unsigned char unused0[32];    // 0xFC30 - 0xFC4F  reserved/unused
  unsigned char unused1[2];     // 0xFC50 - 0xFC51  do not use
  unsigned char mathd;          // 0xFC52
  unsigned char mathc;          // 0xFC53
  unsigned char mathb;          // 0xFC54
  unsigned char matha;          // 0xFC55
  unsigned char mathp;          // 0xFC56
  unsigned char mathn;          // 0xFC57
  unsigned char unused2[8];     // 0xFC58 - 0xFC5F  do not use
  unsigned char mathh;          // 0xFC60
  unsigned char mathg;          // 0xFC61
  unsigned char mathf;          // 0xFC62
  unsigned char mathe;          // 0xFC63
  unsigned char unused3[8];     // 0xFC64 - 0xFC6B  do not use
  unsigned char mathm;          // 0xFC6C
  unsigned char mathl;          // 0xFC6D
  unsigned char mathk;          // 0xFC6E
  unsigned char mathj;          // 0xFC6F
  unsigned char unused4[16];    // 0xFC70 - 0xFC7F  do not use
  unsigned char sprctl0;        // 0xFC80  sprite control bits 0
  unsigned char sprctl1;        // 0xFC81  sprite control bits 1
  unsigned char sprcoll;        // 0xFC82  sprite collision number
  unsigned char sprinit;        // 0xFC83  sprite initialization bits
  unsigned char unused5[4];     // 0xFC84 - 0xFC87  unused
  unsigned char suzyhrev;       // 0xFC88  suzy hardware rev
  unsigned char suzysrev;       // 0xFC89  suzy software rev
  unsigned char unused6[6];     // 0xFC8A - 0xFC8F  unused
  unsigned char suzybusen;      // 0xFC90  suzy bus enable
  unsigned char sprgo;          // 0xFC91  sprite process start bit
  unsigned char sprsys;         // 0xFC92  sprite system control bits
  unsigned char unused7[29];    // 0xFC93 - 0xFCAF  unused
  unsigned char joystick;       // 0xFCB0  joystick and buttons
  unsigned char switches;       // 0xFCB1  other switches
  unsigned char cart0;          // 0xFCB2  cart0 r/w
  unsigned char cart1;          // 0xFCB3  cart1 r/w
  unsigned char unused8[8];     // 0xFCB4 - 0xFCBF  unused
  unsigned char leds;           // 0xFCC0  leds
  unsigned char unused9;        // 0xFCC1  unused
  unsigned char parstat;        // 0xFCC2  parallel port status
  unsigned char pardata;        // 0xFCC3  parallel port data
  unsigned char howie;          // 0xFCC4  howie (?)
                                // 0xFCC5 - 0xFCFF  unused
};
#define SUZY        (*(struct __suzy*)0xFC00)