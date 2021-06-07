#include "t33chong.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT_LAYER] = _layout(_DEFAULT_MAP),
  [_NUMERALS_LAYER] = _layout(_NUMERALS_MAP),
  [_ARROWS_LAYER] = _layout(_ARROWS_MAP),
  [_VIM_LAYER] = _layout(_VIM_MAP),
  [_MOUSEKEYS_LAYER] = _layout(_MOUSEKEYS_MAP),
  [_FUNCTION_LAYER] = _layout(_FUNCTION_MAP),
  [_QUANTUM_LAYER] = _layout(_QUANTUM_MAP),
};
