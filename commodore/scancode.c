/*
  PC Scan Code to Commodore 64 and VIC-20 Column/Row translation table.
   
  Encoded as follows, 
  Each record consists of 3 bytes :-
 
  1) The prefix code, either SCAN_CODE_NO_PREFIX, or SCAN_CODE_ESCAPE
  2) The PC scan code to check for, from scancode.h
  3) The target key it represents, from constant table above.

  This table should ONLY contain mappings for which there is a valid
  output key.

  Working out this table took far too long !!!!
*/

#include "scancode.h"
#include "io.h"
#include "status.h"

const uint8_t ScancodeTableC64VIC[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			C64VIC_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			C64VIC_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			C64VIC_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			C64VIC_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			C64VIC_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			C64VIC_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			C64VIC_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			C64VIC_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			C64VIC_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			C64VIC_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			C64VIC_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			C64VIC_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			C64VIC_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			C64VIC_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			C64VIC_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			C64VIC_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			C64VIC_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			C64VIC_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			C64VIC_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			C64VIC_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			C64VIC_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			C64VIC_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			C64VIC_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			C64VIC_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			C64VIC_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			C64VIC_KEY_Z,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			C64VIC_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			C64VIC_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			C64VIC_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			C64VIC_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			C64VIC_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			C64VIC_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			C64VIC_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			C64VIC_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			C64VIC_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			C64VIC_KEY_9,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		C64VIC_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		C64VIC_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		C64VIC_KEY_LSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		C64VIC_KEY_RSHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		C64VIC_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			C64VIC_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F3,			C64VIC_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F5,			C64VIC_KEY_F5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F7,			C64VIC_KEY_F7,

SCAN_CODE_ESCAPE,		SCAN_CODE_RARROW,		C64VIC_KEY_CRSRLR,
SCAN_CODE_ESCAPE,		SCAN_CODE_DARROW,		C64VIC_KEY_CRSRUD,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	C64VIC_KEY_DEL,


SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		C64VIC_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSQBRACK,		C64VIC_KEY_AT,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		C64VIC_KEY_COLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	C64VIC_KEY_SEMI,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		C64VIC_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		C64VIC_KEY_EQUAL,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		C64VIC_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		C64VIC_KEY_SLASH,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			C64VIC_KEY_RUNSTP,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			C64VIC_KEY_CDORE,

SCAN_CODE_ESCAPE,		SCAN_CODE_HOME,			C64VIC_KEY_HOME,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};


/*
  The shift key table, this has the same format as the above standard 
  key table, however when one of these keys is pressed, the output shift 
  key will also be pressed before the key, and released after the key.
	
  This allows as single PC key to translate to a SHIFT-KEY combination 
  on the output matrix. 
  
  A similar method could be used for other modifier keys.
*/

const uint8_t ScancodeShiftTableC64VIC[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F2,			C64VIC_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F4,			C64VIC_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F6,			C64VIC_KEY_F5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F8,			C64VIC_KEY_F7,

SCAN_CODE_ESCAPE,		SCAN_CODE_LARROW,		C64VIC_KEY_CRSRLR,
SCAN_CODE_ESCAPE,		SCAN_CODE_UARROW,		C64VIC_KEY_CRSRUD,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};


const uint8_t ScancodeTableC16P4[] PROGMEM = {
// Prefix code			Scancode				Keycode
SCAN_CODE_NO_PREFIX,	SCAN_CODE_A,			C16P4_KEY_A,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_B,			C16P4_KEY_B,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_C,			C16P4_KEY_C,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_D,			C16P4_KEY_D,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_E,			C16P4_KEY_E,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F,			C16P4_KEY_F,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_G,			C16P4_KEY_G,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_H,			C16P4_KEY_H,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_I,			C16P4_KEY_I,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_J,			C16P4_KEY_J,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_K,			C16P4_KEY_K,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_L,			C16P4_KEY_L,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_M,			C16P4_KEY_M,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_N,			C16P4_KEY_N,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_O,			C16P4_KEY_O,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_P,			C16P4_KEY_P,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Q,			C16P4_KEY_Q,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_R,			C16P4_KEY_R,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_S,			C16P4_KEY_S,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_T,			C16P4_KEY_T,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_U,			C16P4_KEY_U,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_V,			C16P4_KEY_V,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_W,			C16P4_KEY_W,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_X,			C16P4_KEY_X,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Y,			C16P4_KEY_Y,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_Z,			C16P4_KEY_Z,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_0,			C16P4_KEY_0,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_1,			C16P4_KEY_1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_2,			C16P4_KEY_2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_3,			C16P4_KEY_3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_4,			C16P4_KEY_4,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_5,			C16P4_KEY_5,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_6,			C16P4_KEY_6,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_7,			C16P4_KEY_7,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_8,			C16P4_KEY_8,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_9,			C16P4_KEY_9,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ENTER,		C16P4_KEY_ENTER,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SPACE,		C16P4_KEY_SPACE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSHIFT,		C16P4_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_RSHIFT,		C16P4_KEY_SHIFT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LCTRL,		C16P4_KEY_CTRL,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_F1,			C16P4_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F2,			C16P4_KEY_F2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F3,			C16P4_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F8,			C16P4_KEY_HELP,

SCAN_CODE_ESCAPE,		SCAN_CODE_RARROW,		C16P4_KEY_RIGHT,
SCAN_CODE_ESCAPE,		SCAN_CODE_LARROW,		C16P4_KEY_LEFT,
SCAN_CODE_ESCAPE,		SCAN_CODE_DARROW,		C16P4_KEY_DOWN,
SCAN_CODE_ESCAPE,		SCAN_CODE_UARROW,		C16P4_KEY_UP,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_BACKSPACE,	C16P4_KEY_DEL,


SCAN_CODE_NO_PREFIX,	SCAN_CODE_COMMA,		C16P4_KEY_COMMA,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LSQBRACK,		C16P4_KEY_AT,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_TILDE,		C16P4_KEY_COLON,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SEMICOLON,	C16P4_KEY_SEMI,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_MINUS,		C16P4_KEY_MINUS,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_EQUAL,		C16P4_KEY_EQUAL,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_POINT,		C16P4_KEY_POINT,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_SLASH,		C16P4_KEY_SLASH,

SCAN_CODE_NO_PREFIX,	SCAN_CODE_ESC,			C16P4_KEY_ESC,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_LALT,			C16P4_KEY_CDORE,
SCAN_CODE_ESCAPE,		SCAN_CODE_RALT,			C16P4_KEY_RUNSTP,

SCAN_CODE_ESCAPE,		SCAN_CODE_HOME,			C16P4_KEY_CLRHOME,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};


/*
  The shift key table, this has the same format as the above standard 
  key table, however when one of these keys is pressed, the output shift 
  key will also be pressed before the key, and released after the key.
	
  This allows as single PC key to translate to a SHIFT-KEY combination 
  on the output matrix. 
  
  A similar method could be used for other modifier keys.
*/

const uint8_t ScancodeShiftTableC16P4[] PROGMEM = {
// Prefix code			Scancode				Keycode

SCAN_CODE_NEWSHIFT,		SCAN_CODE_NEWSHIFT,		C16P4_KEY_CDORE,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F4,			C16P4_KEY_F1,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F5,			C16P4_KEY_F2,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F6,			C16P4_KEY_F3,
SCAN_CODE_NO_PREFIX,	SCAN_CODE_F7,			C16P4_KEY_HELP,

SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE, 	SCAN_CODE_TERMINATE
};



void ScancodeInit(matrix_t *ToInit)
{
	if (IsTED) 
	{
		log0("TED machine driver selected (C16, Plus4)\n");
		ToInit->ScancodeTable=(uint8_t *)ScancodeTableC16P4;
		ToInit->ScancodeShiftTable=(uint8_t *)ScancodeShiftTableC16P4;
		ToInit->matrix_shift=C64VIC_KEY_LSHIFT;
	}
	else
	{
		log0("VIC/VICII machine driver selected (VIC-20, C64)\n");
		ToInit->ScancodeTable=(uint8_t *)ScancodeTableC64VIC;
		ToInit->ScancodeShiftTable=(uint8_t *)ScancodeShiftTableC64VIC;
		ToInit->matrix_shift=C64VIC_KEY_LSHIFT;
	}
	
	ToInit->callback=(output_key_callback_t *)&TargetKeyCallback;
	ToInit->matrix_reset=RESET_KEY;
}