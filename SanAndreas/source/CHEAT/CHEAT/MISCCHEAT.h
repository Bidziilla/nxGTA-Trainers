#ifndef MISCCHEAT_H
#define MISCCHEAT_H
#include <string>

template <typename T>
bool FixAudioo2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_AUDIOVOL1, &AudioFix, sizeof(4));
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_AUDIOVOL1, &DefaultFloat1, sizeof(4));
		return true;		
    }

    return false;
  });
  return true;
}

#endif // MISCCHEAT_H
