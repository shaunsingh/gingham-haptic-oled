// whatevers required 
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

// load haptic driver
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif

// timers for alt-tab
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// declare our layers
enum gingham_layers{
    _QWERTY, // base regular qwerty
    _LOWER,  // standard macros & features
    _RAISE,  // empty dynamic
    _ADJUST, // empty dynamic
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    OS_SWAP,
    ALT_TAB,
    WN_LEFT,
    WN_RGHT,
};

// define startup tones
#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
 
  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
#endif

// set our keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_60_ansi_split_bs_rshift( /* Base */
        KC_GESC,  KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,  KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, ADJUST,
        KC_LCTL,  KC_LALT,  KC_LGUI,                       KC_SPC,                          KC_RGUI,  LOWER,    RAISE,   ADJUST),

    [_LOWER] = LAYOUT_60_ansi_split_bs_rshift( /* FN */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_EJCT, KC_EJCT,
        ALT_TAB,  WN_LEFT,  KC_UP,    WN_RGHT,  DM_PLY1,  DM_REC1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,
        KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  DM_PLY2,  DM_REC2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,            KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,  DM_RSTP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        HPT_TOG,  HPT_RST,  HPT_FBK,                                KC_TRNS,                                OS_SWAP,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [_RAISE] = LAYOUT_60_ansi_split_bs_rshift( /* Empty for dynamic keymaps */
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [_ADJUST] = LAYOUT_60_ansi_split_bs_rshift( /* Empty for dynamic keymaps */
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};

#ifdef OLED_ENABLE

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0; 

// Load icons when recording a dynamic macro
#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};

    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return; 
    }

    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return; 
    }
#endif


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
  #endif
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

// Store a shortened version of the Gingham logo on the rear cover's silkscreen
void render_logo(void) {
  static const char PROGMEM gingham_logo[] = {
    0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E,
    0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE,
    0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0x00
  };
  
  oled_write_P(gingham_logo, false);
}

// Handle the main oled displays
void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};  
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0}; 
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE  
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

    // vertical seperator 1/2
    oled_write_ln_P(sep_v, false);

    // draw 1/2 OS logo 
    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false);
    } else {
        oled_write_P(os_w_1, false);
    }

    // draw space seperator 1/2
    oled_write_P(sep_h1, false);

    // draw 1/2 of face
    oled_write_P(face_1, false);

    // draw 2/2 of OS logo 
    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false);
    } else {
        oled_write_P(os_w_2, false);
    }

    // draw space seperator 2/2
    oled_write_P(sep_h1, false);

    // draw 2/2 of face 
    oled_write_P(face_2, false);

    // draw vertical seperator 2/2
    oled_write_ln_P(sep_v, false);

    led_t led_usb_state = host_keyboard_led_state();

    // draw num/caps/scroll locks
    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) {
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

    // draw space seperator (again)
    oled_write_P(sep_h2, false);

    // draw haptic icon & audio icon
    #ifndef AUDIO_ENABLE 
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE 
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE
        if (is_audio_on()) { 
          oled_write_P(aud_en, false); 
        } else {
          oled_write_P(aud_di, false);
        }
    #endif

     #ifdef HAPTIC_ENABLE
        oled_write_P(hap_en, false); 
     #endif
}

// store the layer for future reference
int layerstate = 0;
layer_state_t layer_state_set_kb(layer_state_t state) {
      switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                strcpy ( layer_state_str, "BASE QWERTY");
                break;
            case 1:
                strcpy ( layer_state_str, "LOWER");
                break;
            case 2:
                strcpy ( layer_state_str, "RAISE");
                break;
            case 3:
                strcpy ( layer_state_str, "ADJUST");
                break;
            default:
                strcpy ( layer_state_str, "XXXXXX");
        }
      if (dmacro_num < 1) {
          strcpy ( o_text, layer_state_str );
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// rotate display
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// draw info when idling and logo when typing
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (get_current_wpm() < 60) {
      #ifdef DYNAMIC_MACRO_ENABLE
          if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
          if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
          if(dmacro_num == 3){ oled_write_P(play_ico, false); }
      #endif
      oled_write_ln(o_text, false);
      render_os_lock_status(); 
    } else {
      render_logo();
    }
    return false;
}
#endif

// disable oled when under low-power mode
void suspend_power_down_user(void) {
    oled_off();
}

void suspend_wakeup_init_user(void) {
    oled_on();
}

// macros for keymaps
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_SWAP: 
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif
                }
                else {
                  keymap_config.swap_lctl_lgui = false;
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif
              eeconfig_update_keymap(keymap_config.raw);
              clear_keyboard();
              return false;
            }
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case WN_LEFT:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_LEFT));
            }
            return false;
        case WN_RGHT:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_RGHT));
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                #ifdef HAPTIC_ENABLE
                        DRV_pulse(soft_bump);
                #endif
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                #ifdef HAPTIC_ENABLE
                        DRV_pulse(soft_bump);
                #endif
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
                #ifdef HAPTIC_ENABLE
                        DRV_pulse(lg_dblclick_str);
                #endif
            } else {
                layer_off(_ADJUST);
            }
            return false;
      case KC_MPLY:
        if (record->event.pressed) {
          #ifdef HAPTIC_ENABLE
                  DRV_pulse(sharp_click);
          #endif
        }
        break;
    }
    return true;
}