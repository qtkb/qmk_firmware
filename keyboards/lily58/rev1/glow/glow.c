#include "lily58.h"
#include "rgb_matrix_config.h"

extern uint8_t is_master;

void matrix_init_kb(void) {
    #ifdef RGB_MATRIX_ENABLE
    if (!is_master)
    {
      swap_matrix_hands(&g_led_config);
    }
    #endif
}
