//
// Created by Bradley Remedios on 11/8/24.
//
#include "gtest/gtest.h"
#include <bpl/controls/InputMap.h>

TEST(bpl_controls_InputMap, MapButton_Valid) {
    bpl::controls::InputMap inputMap;

    //
    //  All valid
    //
    EXPECT_TRUE(inputMap.MapButton("My test device", 1, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.MapButton("My test device", 2, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapButton("My test device", 3, bpl::controls::KeyCode::INPUT_LEFT));
} // bpl::controls_InputMap, MapButton_Valid

TEST(bpl_controls_InputMap, MapButton_Duplicates) {
    bpl::controls::InputMap inputMap;

    //
    //  We allow for duplicates as a duplicate should override.
    //
    EXPECT_TRUE(inputMap.MapButton("My test device", 1, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.MapButton("My test device", 2, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapButton("My test device", 2, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapButton("My second test device", 1, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.MapButton("My second test device", 2, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapButton("My second test device", 2, bpl::controls::KeyCode::INPUT_LEFT));
} // bpl::controls_InputMap, MapButton_Duplicates

TEST(bpl_controls_InputMap, InputButtonTest) {
    bpl::controls::InputMap inputMap;

    //  We don't have anything loaded so nothing should show as pressed.
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_NONE));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_ESCAPE));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_ENTER));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_START));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_SELECT));

    //  Map 2 devices.
    EXPECT_TRUE(inputMap.MapButton("device1", 1, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.MapButton("device1", 2, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapButton("device1", 3, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapButton("device2", 1, bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_TRUE(inputMap.MapButton("device2", 2, bpl::controls::KeyCode::INPUT_SELECT));
    EXPECT_TRUE(inputMap.MapButton("device2", 3, bpl::controls::KeyCode::INPUT_UP));

    //  Device 1: KEY_UP = PRESSED
    EXPECT_TRUE(inputMap.InputButton("device1", 1, 1));
    EXPECT_TRUE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    //  Device 1: KEY_UP = PRESSED
    //  Device 2: KEY_up = PRESSED
    EXPECT_TRUE(inputMap.InputButton("device2", 3, 1));
    EXPECT_TRUE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    //  Device 2: KEY_UP = PRESSED
    EXPECT_TRUE(inputMap.InputButton("device1", 1, 0));
    EXPECT_TRUE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    //  No keys pressed
    EXPECT_TRUE(inputMap.InputButton("device2", 3, 0));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));
} // bpl::controls_InputMap, InputButtonTest