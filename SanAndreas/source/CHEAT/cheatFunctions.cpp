#include "cheatFunctions.h"

DmntCheatProcessMetadata metadata;
int Read32;
int MathOutput;

//                   M E M O R Y      M A N I P U L A T I O N      //////////////////////////////////////////

u32 util::CopyHeapMemory(u32 read, u32 write)
{
    int ValueToCopy;

    dmntchtGetCheatProcessMetadata(&metadata);
	
	dmntchtReadCheatProcessMemory(metadata.heap_extents.base + read, &ValueToCopy, sizeof(4));
	dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + write, &ValueToCopy, sizeof(4));
	return true;
}

//                A R I T H M A T I C      O P E R A T I O N S    //////////////////////////////////////////

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

/*

u32 util::EditTime(u8 Operation, u32 Address, u32 Input, u8 compare, u8 resetValue)
{
    dmntchtGetCheatProcessMetadata(&metadata);
	
	dmntchtReadCheatProcessMemory(metadata.main_nso_extents.base + Address, &Read32, sizeof(1));
	
	if (Operation == 0x00)
	{
		if (Read32 >= compare)
		{
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &resetValue, sizeof(1));
		}
		else
		{
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Read32, sizeof(1));
			MathOutput = Read32 + Input;
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &MathOutput, sizeof(1));
		}
	}
	else if (Operation == 0x01)
	{
		if (Read32 <= compare)
		{
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &resetValue, sizeof(1));
		}
		else
		{
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &Read32, sizeof(1));
			MathOutput = Read32 - Input;
			dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + Address, &MathOutput, sizeof(1));
		}
	}
	return true;
}*/
