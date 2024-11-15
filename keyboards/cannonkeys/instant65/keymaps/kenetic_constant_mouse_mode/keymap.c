
#include QMK_KEYBOARD_H

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

//Tap dance enums
enum {
  ALT_OSL4 = 0
};

int cur_dance (tap_dance_state_t *state);
void alt_finished (tap_dance_state_t *state, void *user_data);
void alt_reset (tap_dance_state_t *state, void *user_data);
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_default(
		// KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,KC_INS,
		// KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL,
		// KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_PGUP,
		// KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,KC_UP,KC_PGDN,
		// KC_LCTL,MO(_FN1),KC_LALT, KC_SPC,MO(_FN2),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, MO(1),   TD(ALT_OSL4),                   KC_SPC,                      TT(2),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT

    ),
	[1] = LAYOUT_default(
		KC_GRAVE, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_PSCR,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		MO(3),   KC_NO,   KC_LGUI,                   MO(5),                             KC_TRNS, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	),
    [2] = LAYOUT_default(
		KC_ESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_INS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, KC_NO,   KC_LALT,                   KC_SPC,                             KC_TRNS, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	//          ^ change this key to KC_LGUI to enable the windows key while on this layer
  ),
	//mouse layer for the right hand
	[3] = LAYOUT_default(
		KC_GRAVE,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_HOME,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_ACL0, KC_ACL1, KC_ACL2, KC_F,    KC_G,    KC_H,    KC_MS_LEFT,   KC_MS_DOWN,  KC_MS_RIGHT,   KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT, KC_MS_BTN2,    KC_MS_BTN1,    KC_C,    KC_V,    KC_B,    KC_WH_U,    KC_WH_D,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_TRNS, KC_NO,   KC_NO,                   KC_SPC,                             KC_NO, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[4] = LAYOUT_default(
		TO(1),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_HOME,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, KC_NO,   KC_LALT,                   KC_SPC,                      KC_NO,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	), // the TO(1) is a fix to get out of this layer, might not need it due to OS_OFF in config.h
  [5] = LAYOUT_default(
		KC_GRAVE,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_HOME,
		KC_TAB,  KC_7,    KC_8,    KC_9,    KC_R,    KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_4,    KC_5,    KC_6,    KC_F,    KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_1,    KC_2,    KC_3,    KC_V,    KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_0, KC_DOT,   KC_LALT,                   KC_NO,                      KC_NO,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	)
};

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}

static tap alttap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_finished (tap_dance_state_t *state, void *user_data) {
  alttap_state.state = cur_dance(state);
  switch (alttap_state.state) {
    case SINGLE_TAP: set_oneshot_layer(4, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: set_oneshot_layer(4, ONESHOT_START); set_oneshot_layer(4, ONESHOT_PRESSED); break;
    case DOUBLE_HOLD: register_code(KC_LALT); layer_on(4); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void alt_reset (tap_dance_state_t *state, void *user_data) {
  switch (alttap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: layer_off(4); unregister_code(KC_LALT); break;
  }
  alttap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [ALT_OSL4]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,alt_finished, alt_reset)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_TRNS:
    case KC_NO:
      /* Always cancel one-shot layer when another key gets pressed */
      if (record->event.pressed && is_oneshot_layer_active())
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return true;
    case KC_SPC:
      /* Don't allow reset from oneshot layer state */
      if (record->event.pressed && is_oneshot_layer_active()){
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      }
      return true;
    default:
      return true;
  }
  return true;
}
