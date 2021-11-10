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
}
#endif // CHEATFUNCTIONS_H