#pragma once
#include <string>
#include "dmntcht.h"
#include <thread>

#ifndef CHEATFUNCTIONS_H
#define CHEATFUNCTIONS_H

uint64_t FollowPointer(uint64_t initAddr, const uint64_t* offsets, const uint32_t offsetsSize);

namespace util
{
	u32 CopyHeapMemory(u32 read, u32 write);
	u32 AddToOffset(u8 region, u32 Address, u32 Input);
	u32 SubFromOffset(u8 region, u32 Address, u32 Input);
	u32 ConvertToMOV(u32 Address, u8 Register, u16 Value);
	u32 Write8(u8 region, u32 Address, u8 Value);
	u32 Write16(u8 region, u32 Address, u16 Value);
	u32 Write32(u8 region, u32 Address, u32 Value);
}
#endif // CHEATFUNCTIONS_H
