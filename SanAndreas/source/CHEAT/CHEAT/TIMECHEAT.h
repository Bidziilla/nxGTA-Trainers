#ifndef TIMECHEAT_H
#define TIMECHEAT_H
#include <string>

template <typename T>
bool TimeEditHour2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::AddToOffset(0, ADDR_TIME, 0x1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::SubFromOffset(0, ADDR_TIME, 0x1);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool TimeEditMin2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::AddToOffset(0, ADDR_TIME + 0x04, 0x1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::SubFromOffset(0, ADDR_TIME + 0x04, 0x1);
		return true;		
    }

    return false;
  });
  return true;
}

#endif // TIMECHEAT_H
