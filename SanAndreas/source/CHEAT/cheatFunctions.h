#pragma once
#include <string>
#include "dmntcht.h"
#include <thread>

#ifndef CHEATFUNCTIONS_H
#define CHEATFUNCTIONS_H

namespace util
{
	u32 CopyHeapMemory(u32 read, u32 write);
	u32 AddToOffset(u8 region, u32 Address, u32 Input);
	u32 SubFromOffset(u8 region, u32 Address, u32 Input);
	u32 ConvertToMOV(u32 Address, u8 Register, u16 Value);
	//u32 EditTime(u8 Operation, u32 Address, u32 Input, u8 compare, u8 resetValue);
	//u32 EnableCustomHud();
}
#endif // CHEATFUNCTIONS_H
