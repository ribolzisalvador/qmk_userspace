#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/mouse_turbo_click.h"

// Layers
enum custom_layers {
    _QWERTY = 0,
    _COLEMAKDH,
    _FN,
    _EXTRAS,
    _NUMPAD
};

// Custom Keycodes
enum custom_keycodes {
    CTRL_TAB = SAFE_RANGE,
    CTRL_S_TAB,
    CTRL_W,
    CTRL_Z,
    CTRL_S_T,
    CTRL_A_DEL,

    FN_REDDIT_S,
    FN_REDDIT_TAB,
    FN_RCLICK,
    FN_LLOCK,
    FN_TURBO_MOUSE,
    FN_N,

    SH_SPOTIFY,
    SH_SLACK,
    SH_VSCODE,
    SH_STEAM,
    SH_QBIT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt               Rotary
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   OSM(MOD_RSFT), KC_UP,   KC_END,
        MO(_EXTRAS), KC_LGUI, KC_LALT,                            KC_SPC,                         QK_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_COLEMAKDH] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT, KC_X,    KC_C,    KC_V,    KC_B,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,                   OSM(MOD_RSFT), KC_UP,   KC_END,
        MO(_EXTRAS), KC_LGUI, KC_LALT,                            KC_SPC,                         QK_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, SH_SPOTIFY, KC_CALC, SH_QBIT, SH_STEAM, SH_SLACK, SH_VSCODE, _______, _______, _______, _______, _______,_______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, KC_VOLU, _______, KC_VOLD, _______, DF(_QWERTY), DF(_COLEMAKDH), QK_BOOT, _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_NUM,           FN_TURBO_MOUSE,   _______,
        CW_TOGG, _______, _______, _______, _______, _______, _______, FN_REDDIT_S, _______, _______, NK_TOGG,                   KC_CAPS, RGB_MOD, _______,
        _______, AG_LNRM, AG_LSWP,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_EXTRAS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
    MO(_NUMPAD), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            _______,
        _______, KC_LGUI, KC_LALT, OSM(MOD_LSFT),  KC_LCTL, KC_ENT,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ENT,  _______, _______, _______,         _______,
        _______, CTRL_Z, CTRL_W, CTRL_S_TAB, CTRL_TAB, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______, _______,                  _______,
        _______, CTRL_A_DEL, KC_ESC , CTRL_S_T, FN_RCLICK, FN_REDDIT_TAB, FN_N, KC_MINS, KC_EQL,  _______, KC_DEL,          _______, _______, _______,
        _______, _______, _______,                           _______,                           FN_LLOCK, _______, _______, _______, _______,  _______
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LGUI, KC_LALT, OSM(MOD_LSFT),  KC_LCTL,   _______, KC_PMNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_BSPC, KC_PENT,                   _______,
        _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT,                   _______, _______, _______,
        _______, _______, _______,                            _______,                           FN_LLOCK, _______, _______, _______, _______, _______
    ),
};
// clang-format on
salvador ribolzi salvador ribolzi salvador ribolzi
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_COLEMAKDH] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]        = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_EXTRAS]    = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_NUMPAD]    = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, FN_LLOCK)) { return false; }
    if (!process_mouse_turbo_click(keycode, record, FN_TURBO_MOUSE)) { return false; }

    switch (keycode) {
        case CTRL_TAB:
            if (record->event.pressed) {
                tap_code16(C(KC_TAB));
            }
           break;
        case CTRL_S_TAB:
            if (record->event.pressed) {
                tap_code16(C(S(KC_TAB)));
            }
            break;
        case CTRL_S_T:
            if (record->event.pressed) {
                tap_code16(C(S(KC_T)));
            }
            break;
        case CTRL_W:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
            }
            break;
        case CTRL_Z:
            if (record->event.pressed) {
                tap_code16(C(KC_Z));
            }
            break;
        case CTRL_A_DEL:
            if (record->event.pressed) {
                tap_code16(C(KC_A));
                tap_code16(KC_DEL);
            }
            break;

        case FN_REDDIT_TAB:
            if (record->event.pressed) {
                tap_code16(S(KC_C));
                tap_code16(C(S(KC_TAB)));
            }
            break;
        case FN_REDDIT_S:
            if (record->event.pressed) {
                SEND_STRING("site:reddit.com");
            }
            break;
        case FN_RCLICK:
            if (record->event.pressed) {
                tap_code16(S(KC_F10));
            }
            break;
        case FN_N:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_4) SS_UP(X_LALT));
            }
            break;

        case SH_SPOTIFY:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "SPOTIFY" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case SH_VSCODE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "VSCODE" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case SH_SLACK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "slack" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case SH_STEAM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "steam" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
        case SH_QBIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "qbittorrent" SS_DELAY(100) SS_TAP(X_ENT));
            }
            break;
    }
    return true;
};

// que onda perritoooooooo, tremendo este tecladitoo
