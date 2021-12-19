#ifndef PLAYERCHEAT_H
#define PLAYERCHEAT_H
#include <string>

template <typename T>
bool Add250k2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		util::AddToOffset(0, ADDR_CJMONEY, 0x3D090);
		return true;
    }
	else if (keys & KEY_X)
	{
		util::AddToOffset(0, ADDR_CJMONEY, 0x3B9AC9FF);
		util::AddToOffset(0, ADDR_CJMONEY + 4, 0x3B9AC9FF);
	}

    return false;
  });
  return true;
}

template <typename T>
bool RemoveCash2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		util::Write32(0, ADDR_CJMONEY, 0);
		util::Write32(0, ADDR_CJMONEY + 4, 0);
		return true;
    }

    return false;
  });
  return true;
}

#endif // PLAYERCHEAT_H
