//
// Created by Bradley Remedios on 11/8/24.
//
#include "gtest/gtest.h"
#include <bpl/controls/InputMap.h>

TEST(Controls_InputMap, Clear) {
    bpl::controls::InputMap inputMap;

    EXPECT_TRUE(inputMap.Clear());

} // Controls_InputMap.Clear

TEST(Controls_InputMap, KeyDown_EmptyMap) {
    bpl::controls::InputMap inputMap;

    //
    //  We allow for duplicates as a duplicate should override.
    //
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_NONE));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_UP));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_DOWN));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_LEFT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_RIGHT));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_ESCAPE));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_ENTER));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_START));
    EXPECT_FALSE(inputMap.KeyDown(bpl::controls::KeyCode::INPUT_SELECT));
} // Controls_InputMap, KeyDown_EmptyMap