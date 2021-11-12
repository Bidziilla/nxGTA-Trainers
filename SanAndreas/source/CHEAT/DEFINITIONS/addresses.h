#ifndef ADDRESSES_H
#define ADDRESSES_H
#include <string>

//PLAYER
//#define ADDR_CJHEALTH 0x0
//#define ADDR_CJARMOR 0x0
//#define ADDR_CJOXYGEN 0x0
#define ADDR_CJMONEY 0x69AFAD8              //MAIN
#define ADDR_CJMONEYDISPLAY 0x69AFADC       //MAIN
#define ADDR_CJRUNSPEED 0xE10160            //MAIN

//STATS
#define ADDR_CJFAT 0x69AAE68                //MAIN
#define ADDR_CJSTAMINA 0x69AAE6C            //MAIN
#define ADDR_CJMUSCLE 0x69AAE70             //MAIN
#define ADDR_CJMAXHEALTH 0x69AAE74          //MAIN
#define ADDR_CJSEXAPPEAL 0x69AAE78          //MAIN
#define ADDR_CJRESPECT 0x69AAF14            //MAIN

//TIME
#define ADDR_HOUR 0x6983264
#define ADDR_MIN 0x6983268

//GFX
//#define ADDR_DRAWDISTANCE 0x0
//#define ADDR_BRIGHTNESS 0x0
//#define ADDR_SATURATION 0x0

//AUDIO
#define ADDR_AUDIOVOL1 0x375A618            //MAIN  (SFX)
//#define ADDR_AUDIOVOL2 0x375A5B8          //MAIN  (RADIO)

//PHYSICS
//#define ADDR_GRAVITY 0x0

//HUD
#define ADDR_VEHTEXTRGB 0x69F4FF4           //MAIN
#define ADDR_STREETTEXTRGB 0x69F4FFC        //MAIN

//MISC
#define ADDR_CHEATTRASHID 0xE93CA4          //MAIN (A, R, A, R, Left, Left, R, L, A, Right)
//#define ADDR_CHEATHYDRAID 0x0
//#define ADDR_CHEATHUNTERID 0x0
//#define ADDR_VEHICLEBOOST 0x0

#endif // ADDRESSES_H
