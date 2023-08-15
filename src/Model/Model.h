#ifndef MODEL_H_
#define MODEL_H_

#include "../../include/Types.h"

typedef struct Model
{
    u8 isVisible;
    u8 disableHitbox;
} Model;

u8 isVisible(Model * param_1);

#endif
