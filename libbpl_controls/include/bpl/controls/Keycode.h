//
// Created by Bradley Remedios on 12/4/24.
//

#ifndef BPL_CONTROLS_KEYCODE_H
#define BPL_CONTROLS_KEYCODE_H

namespace bpl::controls {
    typedef enum KeyCode_ : int {
      INPUT_NONE=0,
      INPUT_LEFT=1,
      INPUT_RIGHT=2,
      INPUT_UP=3,
      INPUT_DOWN=4,
      INPUT_ESCAPE=5,
      INPUT_ENTER=6,
      INPUT_START=7,
      INPUT_SELECT=8,
      INPUT_BUTTON_A=9,
      INPUT_BUTTON_B=10,
      INPUT_BUTTON_X=11,
      INPUT_BUTTON_Y=12,
      INPUT_BUTTON_L1=13,
      INPUT_BUTTON_L2=14,
      INPUT_BUTTON_L3=15,
      INPUT_BUTTON_L4=16,
      INPUT_BUTTON_L5=17,
      INPUT_BUTTON_R1=18,
      INPUT_BUTTON_R2=19,
      INPUT_BUTTON_R3=20,
      INPUT_BUTTON_R4=21,
      INPUT_BUTTON_R5=22,
      INPUT_BUTTON_LEFT_STICK=23,
      INPUT_BUTTON_RIGHT_STICK=24,
      INPUT_KEY_A=25,
      INPUT_KEY_B=26,
      INPUT_KEY_C=27,
      INPUT_KEY_D=28,
      INPUT_KEY_E=29,
      INPUT_KEY_F=30,
      INPUT_KEY_G=31,
      INPUT_KEY_H=32,
      INPUT_KEY_I=33,
      INPUT_KEY_J=34,
      INPUT_KEY_K=35,
      INPUT_KEY_L=36,
      INPUT_KEY_M=37,
      INPUT_KEY_N=38,
      INPUT_KEY_O=39,
      INPUT_KEY_P=40,
      INPUT_KEY_Q=41,
      INPUT_KEY_R=42,
      INPUT_KEY_S=43,
      INPUT_KEY_T=44,
      INPUT_KEY_U=45,
      INPUT_KEY_V=46,
      INPUT_KEY_W=47,
      INPUT_KEY_X=48,
      INPUT_KEY_Y=49,
      INPUT_KEY_Z=50,
      INPUT_BUTTON_FUNCTION=51
    } KeyCode;

    typedef enum AxisCode_ : int {
      AXIS_NONE=0,
      AXIS_LEFT_X =1,
      AXIS_LEFT_Y =2,
      AXIS_RIGHT_X=3,
      AXIS_RIGHT_Y=4,
      AXIS_LEFT_SHOULDER=5,
      AXIS_RIGHT_SHOULDER=6,
      AXIS_THROTTLE=7
} AxisCode;

};// bpl::controls
#endif //BPL_CONTROLS_KEYCODE_H