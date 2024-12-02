//
// Created by Bradley Remedios on 11/11/24.
//
#include "gtest/gtest.h"
#include <bpl/controls/InputMap.h>

TEST(Controls_InputMap, SdlKeyboardTest) {
    bpl::controls::InputMap inputMap;

    SDL_Event eventDown;
    SDL_Event eventUp;

    eventDown.type = SDL_KEYDOWN;
    eventDown.key.keysym.sym = SDLK_DOWN;
    eventUp.type = SDL_KEYUP;
    eventUp.key.keysym.sym = SDLK_UP;

    //  Map 2 keys
    EXPECT_TRUE(inputMap.MapKey(SDLK_DOWN, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapKey(SDLK_UP, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_DOWN));

    //  Keyboard: KEY_UP = PRESSED
    eventUp.type = SDL_KEYDOWN;
    EXPECT_TRUE(inputMap.InputSdl(eventUp));
    EXPECT_TRUE(inputMap.Key(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_DOWN));

    //  Keyboard: KEY_UP = PRESSED
    //  Keyboard: KEY_DOWN = PRESSED
    eventDown.type = SDL_KEYDOWN;
    EXPECT_TRUE(inputMap.InputSdl(eventDown));
    EXPECT_TRUE(inputMap.Key(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.Key(bpl::controls::KeyCode::INPUT_DOWN));

    //  Keyboard: KEY_UP = PRESSED
    eventDown.type = SDL_KEYUP;
    EXPECT_TRUE(inputMap.InputSdl(eventDown));
    EXPECT_TRUE(inputMap.Key(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_DOWN));

    //  No keys pressed
    eventUp.type = SDL_KEYUP;
    EXPECT_TRUE(inputMap.InputSdl(eventUp));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.Key(bpl::controls::KeyCode::INPUT_DOWN));
} // Controls_InputMap, SdlKeyboardTest