#include "cheatFunctions.h"

DmntCheatProcessMetadata metadata;
int Read16;
int Read32;
int MathOutput;

uint64_t FollowPointer(uint64_t initAddr, const uint64_t* offsets, const uint32_t offsetsSize) {
    uint64_t address = 0;

    DmntCheatProcessMetadata metadata;
    dmntchtGetCheatProcessMetadata(&metadata);
    dmntchtReadCheatProcessMemory(metadata.main_nso_extents.base + initAddr, &address, 8);

    for (uint32_t i = 0; i < offsetsSize; i++) {
        dmntchtReadCheatProcessMemory(address + offsets[i], &address, 8);
    }
    return address;
}

u32 util::AddToOffset(u8 region, u32 Address, u32 Input)
{
    dmntchtGetCheatProcessMetadata(&metadata);
	
	if (region == 0x00)
	{
		dmntchtReadCheatProcessMemory(metadata.main_nso_extents.base + Address, &Read32, sizeof(4));
		MathOutput = Read32 + Input;
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &MathOutput, sizeof(4));
	}
	else if (region == 0x01)
	{
		dmntchtReadCheatProcessMemory(metadata.heap_extents.base + Address, &Read32, sizeof(4));
		MathOutput = Read32 + Input;
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + Address, &MathOutput, sizeof(4));
	}
	return true;
}

u32 util::SubFromOffset(u8 region, u32 Address, u32 Input)
{
    dmntchtGetCheatProcessMetadata(&metadata);
	
	if (region == 0x00)
	{
		dmntchtReadCheatProcessMemory(metadata.main_nso_extents.base + Address, &Read32, sizeof(4));
		MathOutput = Read32 - Input;
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &MathOutput, sizeof(4));
	}
	else if (region == 0x01)
	{
		dmntchtReadCheatProcessMemory(metadata.heap_extents.base + Address, &Read32, sizeof(4));
		MathOutput = Read32 - Input;
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + Address, &MathOutput, sizeof(4));
	}
	return true;
}

u32 util::ConvertToMOV(u32 Address, u8 Register, u16 Value)
{
	uint32_t M0VV = 0x52800000 + Register;
	uint32_t M0VVPlus = 0x52900000 + Register;
    dmntchtGetCheatProcessMetadata(&metadata);
	
	if (Value <= 0x7FFF) 
	{
		uint16_t MathDo = (Value * 2) & 0xFFFF;
		uint32_t Result = M0VV + (((MathDo << 4) & 0xFFFFF));
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Result, sizeof(4));
	}
	else if (Value >= 0x8000)
	{
		uint16_t MathDo = (Value * 2) & 0xFFFF;
		uint32_t Result = M0VVPlus + (((MathDo << 4) & 0xFFFFF));
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Result, sizeof(4));
	}
	return true;
}

u32 util::Write8(u8 region, u32 Address, u8 Value)
{
	dmntchtGetCheatProcessMetadata(&metadata);
	
	if (region == 0x00)
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Value, sizeof(1));
	}
	else if (region == 0x01)
	{
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + Address, &Value, sizeof(1));
	}
	return true;
}

u32 util::Write16(u8 region, u32 Address, u16 Value)
{
	dmntchtGetCheatProcessMetadata(&metadata);
	
	if (region == 0x00)
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Value, sizeof(2));
	}
	else if (region == 0x01)
	{
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + Address, &Value, sizeof(2));
	}
	return true;
}

u32 util::Write32(u8 region, u32 Address, u32 Value)
{
	dmntchtGetCheatProcessMetadata(&metadata);
	
	if (region == 0x00)
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Value, sizeof(4));
	}
	else if (region == 0x01)
	{
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + Address, &Value, sizeof(4));
	}
	return true;
}
