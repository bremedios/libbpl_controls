//
// Created by Bradley Remedios on 11/11/24.
//
#include "gtest/gtest.h"
#include <bpl/controls/InputMap.h>

TEST(Controls_InputMap, MapAxisButton_Valid) {
    bpl::controls::InputMap inputMap;

    //
    //  All valid
    //
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, 16000, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, -16000, bpl::controls::KeyCode::INPUT_RIGHT));
} // Controls_InputMap, MapAxisButton_Valid

TEST(Controls_InputMap, MapAxisButton_Duplicates) {
    bpl::controls::InputMap inputMap;

    //
    //  We allow for duplicates as a duplicate should override.
    //
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, 16000, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, -16000, bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 2, 16000, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 2, -16000, bpl::controls::KeyCode::INPUT_RIGHT));

    EXPECT_TRUE(inputMap.InputAxis("My test device", 1, 0));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
} // Controls_InputMap, MapAxisButton_Duplicates

TEST(Controls_InputMap, InputAxisButtons) {
    bpl::controls::InputMap inputMap;

    //  We don't have anything loaded so nothing should show a value.
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    //  Map 2 devices for 2 joysticks
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, 16000, bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device", 1, -16000, bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device2", 2, 16000, bpl::controls::KeyCode::INPUT_UP));
    EXPECT_TRUE(inputMap.MapAxisToButton("My test device2", 2, -16000, bpl::controls::KeyCode::INPUT_DOWN));

    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    EXPECT_TRUE(inputMap.InputAxis("My test device", 1, 0));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    EXPECT_TRUE(inputMap.InputAxis("My test device", 1, 15999));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    EXPECT_TRUE(inputMap.InputAxis("My test device", 1, 16000));
    EXPECT_TRUE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

    EXPECT_TRUE(inputMap.InputAxis("My test device", 1, -16000));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_TRUE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));

} // Controls_InputMap, InputAxisButtons