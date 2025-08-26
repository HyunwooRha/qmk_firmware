
#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_ALT_FN,
};

enum layer_names {
    _BASE,
    _1,
	_2,
	_3,
	_4,
	_5,
};



typedef struct {
	uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
	tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
	
    if (state->pressed) {
		if (state->count == 1
			#ifndef PERMISSIVE_HOLD
            && !state->interrupted
			#endif
        ) {
			register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
			register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
	tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
	
    if (tap_hold->held) {
		unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
{                                                                               \
	.fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
	.user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
	[CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(OSL(_5), KC_LALT),
	[TD_ALT_FN] = ACTION_TAP_DANCE_DOUBLE(OSL(_5), KC_LALT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	tap_dance_action_t *action;
	
    switch (keycode) {
		case TD(CT_CLN): // list all tap dance keycodes with tap-hold configurations
		action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
		if (!record->event.pressed && action->state.count && !action->state.finished) {
			tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
			tap_code16(tap_hold->tap);
		}
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // default layer
	[_BASE] = LAYOUT_default(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, MO(_1),  TD(CT_CLN),                   KC_SPC,                      TT(_2),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // arrow key layer
	[_1] = LAYOUT_default(       
		KC_GRAVE,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_PSCR,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		MO(_3),   KC_TRNS,   KC_LGUI,                   MO(_4),                             KC_NO, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	),
    // toggle key layer
    [_2] = LAYOUT_default(
		KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_INS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, KC_NO,   KC_LALT,                   KC_SPC,                             KC_TRNS, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
	// mouse layer for the right hand
	[_3] = LAYOUT_default(
		KC_TRNS,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, TO(_BASE),
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_ACL0, KC_ACL1, KC_ACL2, KC_F,    KC_G,    KC_H,    KC_MS_LEFT,   KC_MS_DOWN,  KC_MS_RIGHT,   KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
		KC_LSFT, KC_MS_BTN2,    KC_MS_BTN1,    KC_C,    KC_V,    KC_B,    KC_WH_U,    KC_WH_D,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_TRNS, KC_NO,   KC_NO,                   KC_SPC,                             KC_NO, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
	// keypad layer
	[_4] = LAYOUT_default(
		KC_TRNS,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_HOME,
		KC_TAB,  KC_7,    KC_8,    KC_9,    KC_R,    KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_4,    KC_5,    KC_6,    KC_F,    KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_1,    KC_2,    KC_3,    KC_V,    KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_0, KC_DOT,   KC_LALT,                   KC_TRNS,                      KC_NO,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
	),
	// tap dance layer
	[_5] = LAYOUT_default(
		KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_INS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
		KC_LCTL, KC_NO,   KC_LALT,                   KC_SPC,                             KC_NO, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
};