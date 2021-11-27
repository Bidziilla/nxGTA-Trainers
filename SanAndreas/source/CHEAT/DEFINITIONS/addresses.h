#ifndef ADDRESSES_H
#define ADDRESSES_H
#include <string>

//PLAYER
#define ADDR_CJMONEY 0x69B6B18              //MAIN

//STATS
#define ADDR_CJFAT 0x69B1EA8                //MAIN
#define ADDR_CJSTAMINA 0x69B1EAC            //MAIN
#define ADDR_CJMUSCLE 0x69B1EB0             //MAIN
#define ADDR_CJMAXHEALTH 0x69B1EB4          //MAIN
#define ADDR_CJRESPECT 0x69B1F54            //MAIN

//TIME
#define ADDR_TIME 0x698A264                 //MAIN

//PHYSICS
#define ADDR_CJRUNSPEED 0xE13090            //MAIN

//MISC
#define ADDR_CHEATTRASHID 0xE96D84          //MAIN (A, R, A, R, Left, Left, R, L, A, Right)
#define Addr_CarID 0x40

//CHEATS     -   These are toggled as 0 = off, 1 = on. :3  All are in main
#define ADDR_InsaneHandling 0x68D3F57
#define ADDR_FlyingBoat 0x68D3F5E
#define ADDR_CarsOnWater 0x68D3F5D
#define ADDR_SportsCars 0x68D3F6B
#define ADDR_BunnyHop 0x68D3F6D
#define ADDR_FlyingCars 0x68D3F6C
#define ADDR_DeathCar 0x68D3F70 
#define ADDR_SuperJump 0x68D3F78            
#define ADDR_InfBreath 0x68D3F7A
#define ADDR_WantedLock 0x68D3F7D
#define ADDR_SuperPunch 0x68D3F7F

#endif // ADDRESSES_H
