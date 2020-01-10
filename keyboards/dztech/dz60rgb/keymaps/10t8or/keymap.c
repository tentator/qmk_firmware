// (Cl) 10t8or, 2ol9
//

#include QMK_KEYBOARD_H

enum dz60rgb_layers {
	_DEF,
	_FNM,
	_RGB,
	_SFN
};

enum dz60rgb_keycodes {
	REBOOT = SAFE_RANGE,
	MAS_CRM,
	MAS_PRP,
	MAS_RED,
	MAS_GRN,
	MAS_BLU,
	MAS_CYN,
	MAS_MGT,
	MAS_YEL,
	MAS_KEY,
	MAS_WHT,
};

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  QMKOTH,
  QMKJ2,
  QMKYM1,
  QMKYM2,
  QMKYM3,
  QMKYM4,
  QMKYM5,
  QMKYM6,
  QMKYM7,
  QMKYM8,
  QMKYM9
};

/*
MO(layer) - momentarily activates layer. As soon as you let go of the key, the layer is deactivated.
LM(layer, mod) - Momentarily activates layer (like MO), but with modifier(s) mod active. Only supports layers 0-15 and the left modifiers: MOD_LCTL, MOD_LSFT, MOD_LALT, MOD_LGUI (note the use of MOD_ constants instead of KC_). These modifiers can be combined using bitwise OR, e.g. LM(_RAISE, MOD_LCTL | MOD_LALT).
LT(layer, kc) - momentarily activates layer when held, and sends kc when tapped. Only supports layers 0-15.
OSL(layer) - momentarily activates layer until the next key is pressed. See One Shot Keys for details and additional functionality.
OSM(mod) - Momentarily hold down mod. You must use the MOD_* keycodes as shown in Mod Tap, not the KC_* codes
TG(layer) - toggles layer, activating it if it's inactive and vice versa
*/

extern bool autoshift_enabled;
// KC_ASTG is to enable autoshift (currently toggle with RGB+ESC)
#define _V_V_V_ KC_TRNS
#define LT_END  LT(_RGB, KC_END)
#define LT_SPC  LT(_SFN, KC_SPC)
#define MT_SLSH RSFT_T(KC_SLSH)
#define MT_UP   RSFT_T(KC_UP)
#define MT_APP  RALT_T(KC_APP)
#define LM_LALT LM(_FNM, MOD_LALT)
#define OL_LSFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEF] = LAYOUT(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           \
		OL_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MT_SLSH,          MT_UP,   LT_END,  \
		KC_LCTL, KC_LGUI, LM_LALT,                   LT_SPC,                    MT_APP,  KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
	),
	[_FNM] = LAYOUT(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
		_______, _______, _V_V_V_,                   _______,                   _______, _______,          _______, _______, _______  \
	),
	[_RGB] = LAYOUT(
		KC_ASTG, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
		KC_NLCK, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, MAS_MGT, MAS_BLU, MAS_WHT, RGB_RMOD,RGB_MOD, _______, \
		KC_CAPS, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, MAS_RED, MAS_KEY, MAS_CYN, MAS_PRP, _______, _______,          \
		KC_SLCK, RGB_TOG,  BL_TOGG, _______, _______, _______, _______, MAS_YEL, MAS_GRN, MAS_CRM, _______,          KC_VOLU, _V_V_V_, \
		_______, _______,  _______,                   _______,                   _______, _______,          KC_MUTE, KC_VOLD, KC_MPLY  \
	),
	[_SFN] = LAYOUT( // space-fn
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  \
		KC_CALC, QMKBEST, QMKJ2,   QMKYM3,  QMKYM6,  QMKYM9,  _______, KC_HOME, KC_UP,   KC_END,  _______, KC_PSCR, KC_PAUS, KC_BSPC, \
		_______, QMKURL,  QMKYM1,  QMKYM4,  QMKYM7,  _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,          \
		_______, QMKOTH,  QMKYM2,  QMKYM5,  QMKYM8,  KC_SPC,  KC_PGDN, _______, _______, _______, _______,          KC_PGUP, _______, \
		_______, _______, _______,                   _V_V_V_,                   _______, _______,          KC_HOME, KC_PGDN, KC_END   \
	),
	/*
	[_LAYER] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
		_______, _______, _______,                   _______,                   _______, _______,          _______, _______, _______  \
	),
	 [_LAYER] = LAYOUT(
		13,      12,      11,       10,      9,       8,       7,       6,       5,       4,       3,       2,       1,       0,      \
		27,      26,      25,       24,      23,      22,      21,      20,      19,      18,      17,      16,      15,      14,     \
		40,      39,      38,       37,      36,      35,      34,      33,      32,      31,      30,      29,      28,              \
		53,      52,      51,       50,      49,      48,      47,      46,      45,      44,      43,               42,      41,     \
		62,      61,      60,                         59,                        58,      57,               56,      55,      54      \
	),
	*/
/*

		[_LAYER0] = LAYOUT( // default qwert
		    KC_GESC,            KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,    KC_0,            KC_MINS,  KC_EQL,  KC_BSPC,\
		    KC_TAB,             KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,            KC_LBRC,  KC_RBRC, KC_BSLASH,\
		    CTL_T(KC_CAPS),     KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN,         KC_QUOT,           KC_ENT, \
		    KC_LSFT,            KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP,             LT(2, KC_DEL),\
		    KC_LCTL,            KC_LGUI,  LM(1, MOD_LALT),        KC_SPC,               KC_RALT, MO(1),  KC_LEFT,         KC_DOWN,           KC_RIGHT),
		[_LAYER1] = LAYOUT( // fn
		    TO(3),    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
		    KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CALC,  KC_TRNS,  KC_INS,   KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  RESET  ,\
		    KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGUP,            EEP_RST,\
		    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_END,   KC_PGDOWN,KC_VOLU,            KC_MUTE,\
			KC_TRNS,  KC_TRNS,  KC_TRNS,                      TO(4),                        KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,            KC_MNXT),
		[_LAYER2] = LAYOUT( // rgb
			KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
			KC_TRNS,  RGB_TOG,  KC_TRNS,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET  ,\
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SPI,  RGB_SPD,  KC_TRNS,  KC_TRNS,            EEP_RST,\
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
			KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS),
		[_LAYER3] = LAYOUT( // numpad
			KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_TRNS,\
			KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,  KC_TRNS,  TO(0),\
			KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,            KC_PENT,\
			KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,            KC_TRNS,\
			KC_TRNS,  KC_P0,    KC_PDOT,                      KC_PENT,                      KC_P0,    KC_PDOT,  KC_TRNS,  KC_TRNS,            KC_TRNS),
		[_LAYER4] = LAYOUT( // SWITCH LALT AND LGUI 
			KC_GESC,        KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,            KC_MINS,  KC_EQL,  KC_BSPC,\
		        KC_TAB,         KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,            KC_LBRC,  KC_RBRC, KC_BSLASH,\
			CTL_T(KC_CAPS), KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,         KC_QUOT,           KC_ENT, \
		        KC_LSFT,        KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   RSFT_T(KC_SLSH), KC_UP,             LT(2, KC_DEL),\
			KC_LCTL,        KC_LALT,  KC_LGUI,                KC_SPC,                KC_RALT, TO(0),    KC_LEFT,         KC_DOWN,           KC_RIGHT),

*/
};

void rgb_matrix_indicators_user(void) {
	uint8_t this_led = host_keyboard_leds();
	if (!g_suspend_state) {
		switch (biton32(layer_state)) {
			case _FNM:
				rgb_matrix_set_color(0,  0x00, 0x00, 0x00);
				rgb_matrix_set_color(1,  0x00, 0x00, 0x00);
				rgb_matrix_set_color(1,  0x00, 0x00, 0x00);
				rgb_matrix_set_color(2,  0x00, 0x00, 0x00);
				rgb_matrix_set_color(3,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(4,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(5,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(6,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(7,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(8,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(9,  0x00, 0xFF, 0x00);
				rgb_matrix_set_color(10, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(11, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(12, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(14, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(15, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(16, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(17, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(18, 0x00, 0x00, 0x00);  
				rgb_matrix_set_color(19, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(20, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(21, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(22, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(24, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(25, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(26, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(28, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(30, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(31, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(32, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(33, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(34, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(37, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(38, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(39, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(40, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(43, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(44, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(45, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(50, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(51, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(52, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(54, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(55, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(56, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(57, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(58, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(59, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(60, 0xFF, 0x00, 0x00);
				rgb_matrix_set_color(61, 0x00, 0x00, 0x00);
				rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
			break;
			case _RGB:
				//rgb_matrix_set_color_all(0x00, 0x00, 0x00); // tenere commentato per vedere le animazioni
				rgb_matrix_set_color(15, 0x00, 0x00, 0xFF);
				rgb_matrix_set_color(26, 0x00, 0x00, 0xFF);
				rgb_matrix_set_color(42, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(54, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(55, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(56, 0x00, 0xFF, 0x00);
				rgb_matrix_set_color(41, 0xFF, 0x00, 0x00);
			break;
			case _SFN:
				rgb_matrix_set_color_all(0x00, 0x00, 0x00);
				rgb_matrix_set_color(0,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(1,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(1,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(2,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(3,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(4,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(5,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(6,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(7,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(8,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(9,  0x88, 0x33, 0x99);
				rgb_matrix_set_color(10, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(11, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(12, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(13, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(14, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(15, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(16, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(18, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(19, 0x00, 0xFF, 0x00); //I
				rgb_matrix_set_color(20, 0x88, 0x33, 0x99);
				rgb_matrix_set_color(27, 0x88, 0x33, 0x99); 
				rgb_matrix_set_color(31, 0x00, 0xFF, 0x00); //J
				rgb_matrix_set_color(32, 0x00, 0xFF, 0x00); //K
				rgb_matrix_set_color(33, 0x00, 0xFF, 0x00); //L
				rgb_matrix_set_color(34, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(42, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(47, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(48, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(54, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(55, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(56, 0x88, 0x33, 0x99);  
				rgb_matrix_set_color(59, 0xFF, 0x00, 0x00);  
			break;
		}
    }
    if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
		rgb_matrix_set_color(40, 0x00, 0xFF, 0x00);
    }
    if ( this_led & (1<<USB_LED_NUM_LOCK)) {
		rgb_matrix_set_color(27, 0xFF, 0x00, 0x00);
	}
    if ( this_led & (1<<USB_LED_SCROLL_LOCK)) {
		rgb_matrix_set_color(53, 0x00, 0x00, 0xFF);
    }
}

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("autocmd filetype yaml setlocal ai ts=2 sw=2 et sts=2 cuc cul" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("");
      } else {
        // when keycode QMKURL is released
      }
      break;
    case QMKOTH:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKJ2:
      if (record->event.pressed) {
        SEND_STRING(""); // .j2 templ
      }
      break;
    case QMKYM1:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM2:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM3:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM4:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM5:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM6:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM7:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml templ
      }
      break;
    case QMKYM8:
      if (record->event.pressed) {
        SEND_STRING("--- \n\
"); // .yaml templ
      }
      break;
    case QMKYM9:
      if (record->event.pressed) {
        SEND_STRING(""); // .yaml temp9
      }
      break;
  }
  return true;
};


void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        rgb_matrix_set_color( i, red, green, blue );
    }
  }
}

/*
void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
	      case _LAYER1:
		    rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false); break;
	      case _LAYER2:
	        rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false); break;
	      case _LAYER3:
	        rgb_matrix_layer_helper(0x00, 0x00, 0xFF, false); break;
	      case _LAYER4:
	        rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false); break;
	    							  }
	                        }
	  if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
	        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
	  }

}
*/