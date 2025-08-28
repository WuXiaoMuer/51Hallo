// 7-seg display module: declarations only
#ifndef SMG_H
#define SMG_H

#include "public.h"

void smg_show(void);
void smg_num(unsigned long num);
void smg_fill(u8 digit);
void smg_enable(unsigned char on);

#endif