#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"

// Layers
enum custom_layers {
  _COLE = 0,
  _QWERTY,
  _NUM,
  _SYM,
  _NAV,
  _MACRO,
  _FN,
  _MOUSE
};

// Custom Keycodes
enum custom_keycodes {
  FN_REDDIT_S = SAFE_RANGE,
  FN_TURBO_MOUSE,
  FN_N,
  FN_MIN,
  FN_ATAB,
  FN_PSCR,
  FN_CKC,

  SH_SPOTIFY,
  SH_PEACE,
  SH_VSCODE,
  SH_STEAM,
  SH_QBIT,
  SH_FOOBAR,
  SH_EDGE,
  DCLCK
};

const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_SLSH);
const key_override_t *key_overrides[] = {&slash_key_override};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLE] = LAYOUT_split_3x6_3(
    KC_TAB , KC_Q, KC_W, KC_F, KC_P, KC_V,                              KC_J,    KC_L,      KC_U,    KC_Y,   FN_N,    KC_LGUI,
    KC_LCTL, KC_A, KC_S, KC_R, KC_T, KC_G,                              KC_H,    KC_N,      KC_E,    KC_I,   KC_O,    KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_B,                              KC_K,    KC_M,      KC_COMM, KC_DOT, KC_SLSH, KC_LALT,
        OSL(_NUM), OSL(_NAV), KC_SPC,                                   KC_BSPC, OSL(_SYM), KC_ESC
    ),
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y,    KC_U,      KC_UP,    KC_O,    KC_P,    KC_LGUI,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_H,    KC_LEFT,   KC_DOWN,  KC_RGHT, FN_N,    KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                              KC_N,    KC_M,      KC_COMM,  KC_DOT,  KC_SLSH, KC_LALT,
        OSL(_NUM), OSL(_NAV), KC_SPC,                                   KC_BSPC, OSL(_SYM), KC_ESC
    ),
  [_NUM] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______,    _______,            KC_PMNS, KC_7,   KC_8,   KC_9, KC_PSLS, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,    _______,            KC_PPLS, KC_4,   KC_5,   KC_6, KC_PAST, _______,
    _______, _______, _______, FN_CKC,  S(KC_SCLN), _______,            KC_DOT,  KC_1,   KC_2,   KC_3, KC_0,    _______,
                                _______, OSL(_NAV), _______,            _______, KC_SPC, QK_LLCK
    ),
  [_SYM] = LAYOUT_split_3x6_3(
    _______, S(KC_3), S(KC_4), S(KC_LBRC), S(KC_RBRC), KC_GRV,          _______, S(KC_EQL), KC_EQL,     S(KC_COMM), S(KC_DOT),  _______,
    _______, S(KC_1), S(KC_2), S(KC_9),    S(KC_0),    S(KC_7),         S(KC_8), KC_MINS,   S(KC_MINS), KC_QUOT,    S(KC_QUOT), _______,
    _______, S(KC_5), S(KC_6), KC_LBRC,    KC_RBRC,    S(KC_GRV),       _______, KC_SCLN,   S(KC_SCLN), KC_BSLS,    S(KC_BSLS), _______,
                                   _______, OSL(_NAV), _______,         _______, _______,   _______
  ),
  [_NAV] = LAYOUT_split_3x6_3(
    _______,    C(KC_A), C(KC_X),   C(KC_C),   C(KC_V),    FN_PSCR,                    KC_PGUP, KC_HOME,    KC_UP,   KC_END,     QK_LLCK, _______,
    MO(_MOUSE), KC_LGUI, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), _______,         KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_ESC,  _______,
    _______,    C(KC_Z), S(KC_F10), FN_MIN,    FN_ATAB,    _______,                    CW_TOGG, C(KC_TAB),  C(KC_W), C(S(KC_T)), KC_DEL,  _______,
                                         _______, _______, _______,                    _______, MO(_MACRO), MO(_FN)
    ),
  [_MACRO] = LAYOUT_split_3x6_3(
    _______, _______, _______,  _______,    _______,  _______,          _______,        KC_VOLD, KC_MUTE,     KC_VOLU,  C(G(KC_V)), _______,
    _______, KC_MYCM, KC_WHOM,  SH_SPOTIFY, KC_CALC,  SH_FOOBAR,        _______,        KC_MPRV, KC_MPLY,     KC_MNXT,  _______,    _______,
    _______, SH_QBIT, SH_STEAM, SH_VSCODE,  SH_PEACE, SH_EDGE,          FN_TURBO_MOUSE, KC_CAPS, FN_REDDIT_S, C(KC_F2), _______,    _______,
                                    _______, _______, _______,          _______,        _______, _______
  ),
  [_FN] = LAYOUT_split_3x6_3(
    QK_BOOT, _______, _______, _______, _______, _______,                        UG_SPDU, UG_VALU, UG_HUEU, UG_SATU, UG_NEXT, TG(_QWERTY),
    KC_NUM,  KC_LGUI, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), _______,      _______, _______, _______, _______, _______, QK_MUSIC_TOGGLE,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                _______, _______, _______,                       _______, _______, _______
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,               MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______,               MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,               _______, DCLCK,   _______, _______, _______, _______,
                               _______, _______, _______,               _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_mouse_turbo_click(keycode, record, FN_TURBO_MOUSE)) { return false; }

    switch(detected_host_os()) {
        case OS_MACOS:
            switch (keycode) {
                case FN_N:
                    if (record->event.pressed) {
                        tap_code16(A(KC_N));
                        tap_code16(KC_N);
                    }
                    return false;

                case FN_PSCR:
                    if (record->event.pressed) {
                        tap_code16(C(S(KC_4)));
                    }
                    return false;
            }
        default:
            switch (keycode) {
                case FN_N:
                    if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_4) SS_UP(X_LALT));
                    }
                    return false;
                case FN_REDDIT_S:
                    if (record->event.pressed) {
                        SEND_STRING("site:reddit.com");
                    }
                    return false;
                case FN_MIN:
                    if (record->event.pressed) {
                        tap_code16(A(KC_SPC));
                        wait_ms(100);
                        tap_code16(KC_N);
                    }
                    return false;
                case FN_CKC:
                    if (record->event.pressed) {
                        tap_code16(C(KC_K));
                        wait_ms(50);
                        set_oneshot_mods(MOD_BIT(KC_LCTL));
                    }
                    return false;
                case FN_ATAB:
                    if (record->event.pressed) {
                        register_code(KC_LALT);
                        tap_code16(KC_TAB);
                    } else {
                        unregister_code(KC_LALT);
                    }
                    return false;
                case FN_PSCR:
                    if (record->event.pressed) {
                        tap_code16(KC_PSCR);
                    }
                    return false;

                case DCLCK:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(50) SS_TAP(X_BTN1));
                    }
                    return false;

                    case SH_SPOTIFY:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "SPOTIFY" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_VSCODE:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "VSCODE" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_PEACE:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "PEACE" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_STEAM:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "STEAM" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_QBIT:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "QBITTORRENT" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_FOOBAR:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "FOOBAR2000" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
                case SH_EDGE:
                    if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "EDGE" SS_DELAY(150) SS_TAP(X_ENT));
                    }
                    return false;
            }
    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
    return;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }

    return rotation;
}

bool oled_task_user() {
    oled_clear();
    bool caps = host_keyboard_led_state().caps_lock || is_caps_word_on();
    uint8_t mod_status = get_mods() | get_weak_mods() | get_oneshot_mods();

    if (is_keyboard_master()) {
        caps ? oled_write_ln("CAPS", false) : oled_write_ln("caps", false);

        switch (get_highest_layer(layer_state)) {
            case _COLE:
                oled_write_ln("COLE", false);
                break;
            case _QWERTY:
                oled_write_ln("QWERT", false);
                break;
            case _NAV:
                oled_write_ln("NAV", false);
                break;
            case _NUM:
                oled_write_ln("NUM", false);
                break;
            case _SYM:
                oled_write_ln("SYM", false);
                break;
            case _MACRO:
                oled_write_ln("MACRO", false);
                break;
            case _FN:
                oled_write_ln("FN", false);
                break;
            case _MOUSE:
                oled_write_ln("MOUSE", false);
                break;
        }

        if (mod_status & MOD_MASK_CTRL) {
            oled_write("C", false);
            if (mod_status & MOD_MASK_SHIFT) {
                oled_write("+S", false);
                if (mod_status & MOD_MASK_ALT) {
                    oled_write("+A", false);
                }
            } else if (mod_status & MOD_MASK_ALT) {
                oled_write("  +A", false);
            }
        } else if (mod_status & MOD_MASK_SHIFT) {
            oled_write("  S", false);
                if (mod_status & MOD_MASK_ALT) {
                    oled_write("+A", false);
                }
        } else if (mod_status & MOD_MASK_ALT) {
            oled_write("    A", false);
        }

    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;
    }
}

// const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_split_3x6_3(
//     30, 31, 32, 33, 34, 35,    36, 37, 38, 39, 40, 41,
//     18, 19, 20, 21, 22, 23,    24, 25, 26, 27, 28, 29,
//     6,  7,  8,  9,  10, 11,    12, 13, 14, 15, 16, 17,
//                    0, 1, 2,    3, 4, 5
// );

// [_] = LAYOUT_split_3x6_3(
//    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
//                               _______, _______, _______,    _______, _______, _______
//   )

//    q, w, f, p, v,    j, l, u, y, ñ
//    a, s, r, t, g,    h, n, e, i, o
//    z, x, c, d, b,    k, m, ,, ., /

//    #, $, {, }, `,     , +, =, <, >
//    !, @, (, ), &,    *, -, _, ', "
//    %, ^, [, ], ~,     , ;, :, ,

//    , , , , ,         -, 7, 8, 9, /
//    , , , , ,         +, 4, 5, 6, *
//    , , , , ,         ., 1, 2, 3, 0
