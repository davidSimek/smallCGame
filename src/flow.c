#include "i/flow.h"

#include <stdbool.h>

bool shouldRun = true;
void shouldStop() {
    shouldRun = false;
}
