#ifndef MODEL_H_
#define MODEL_H_

#include "../../include/Types.h"

typedef struct Model
{
    bool displayModel;
    u8 disableHitbox;
} Model;

bool isVisible(Model * param_1);

#endif
