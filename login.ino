#include "DigiKeyboard.h"
#define KEY_DELETE 0x4C
#define KEY_TAB 0x2B
#define KEY_RIGHT_ARROW 0x4F
#define KEY_UP_ARROW 0x52
#define KEY_LEFT_ARROW 0x50
#define KEY_DOWN_ARROW 0x51

char passString[] = "XX-YYYYY283198739182739182793";


void setup() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected

//  loop actually does Secure Attention Sequence
  loop();

  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  DigiKeyboard.print(passString);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, 0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
}


void loop() { // Secure Attention Sequence
  DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_ALT_RIGHT | MOD_CONTROL_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(400);
}
