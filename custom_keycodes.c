

// Misc
#define KC_EURO S(A(KC_2))
#define C_CED RALT(KC_COMM)

enum custom_keycodes {
  // Undead characters
  UD_APO = SAFE_RANGE,
  UD_GRV,
  UD_TLD,
  UD_CIRC,

  // Accented letters
  E_ACUTE,
  E_GRV,
  E_CIRC,
  A_GRV,
  U_GRV,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const bool pressed = record->event.pressed;

  switch (keycode) {

    // Undead characters
    case UD_APO: return undead(KC_QUOT, pressed);
    case UD_GRV: return undead(KC_GRV, pressed);
    case UD_TLD: return undead(S(KC_GRV), pressed);
    case UD_CIRC: return undead(S(KC_6), pressed);

    // Accented letters
    case E_ACUTE: return accented_letter(KC_QUOT, KC_E, pressed);
    case E_GRV: return accented_letter(KC_GRV, KC_E, pressed);
    case E_CIRC: return accented_letter(S(KC_6), KC_E, pressed);
    case A_GRV: return accented_letter(KC_GRV, KC_A, pressed);
    case U_GRV: return accented_letter(KC_GRV, KC_U, pressed);
    case A_CIRC: return accented_letter(S(KC_6), KC_A, pressed);
    case I_CIRC: return accented_letter(S(KC_6), KC_I, pressed);
    case O_CIRC: return accented_letter(S(KC_6), KC_O, pressed);
    case U_CIRC: return accented_letter(S(KC_6), KC_U, pressed);

    default:
      return true;

    break;
  }
}
