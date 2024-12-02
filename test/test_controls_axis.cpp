//
// Created by Bradley Remedios on 11/8/24.
//
#include "gtest/gtest.h"
#include <bpl/controls/InputMap.h>

TEST(Controls_InputMap, MapAxis_Valid) {
    bpl::controls::InputMap inputMap;

    //
    //  All valid
    //
    EXPECT_TRUE(inputMap.MapAxis("My test device", 1, bpl::controls::AxisCode::AXIS_NONE));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 2, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 3, bpl::controls::AxisCode::AXIS_LEFT_Y));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 4, bpl::controls::AxisCode::AXIS_RIGHT_X));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 5, bpl::controls::AxisCode::AXIS_RIGHT_Y));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 6, bpl::controls::AxisCode::AXIS_THROTTLE));
} // Controls_InputMap, MapAxis_Valid

TEST(Controls_InputMap, MapAxis_Duplicates) {
    bpl::controls::InputMap inputMap;

    //
    //  We allow for duplicates as a duplicate should override.
    //
    EXPECT_TRUE(inputMap.MapAxis("My test device", 2, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("My test device", 3, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("My different device", 4, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("My different device", 3, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("My different device", 2, bpl::controls::AxisCode::AXIS_LEFT_X));

    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.InputAxis("My test device", 3, -30000));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.InputAxis("My different device", 2, -30000));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.InputAxis("My different device", 3, -30000));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.InputAxis("My different device", 4, -30000));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
} // Controls_InputMap, MapAxis_Duplicates

TEST(Controls_InputMap, InputAxis) {
    bpl::controls::InputMap inputMap;

    //  We don't have anything loaded so nothing should show a value.
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_NONE));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_Y));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_RIGHT_X));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_RIGHT_Y));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_THROTTLE));

    //  Map 2 devices for 2 joysticks
    EXPECT_TRUE(inputMap.MapAxis("device1", 1, bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_TRUE(inputMap.MapAxis("device1", 2, bpl::controls::AxisCode::AXIS_LEFT_Y));
    EXPECT_TRUE(inputMap.MapAxis("device2", 1, bpl::controls::AxisCode::AXIS_RIGHT_X));
    EXPECT_TRUE(inputMap.MapAxis("device2", 2, bpl::controls::AxisCode::AXIS_RIGHT_Y));

    //  Device 1: Left X-Axis moved left.
    EXPECT_TRUE(inputMap.InputAxis("device1", 1, -30000));
    EXPECT_EQ(-30000, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_X));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_LEFT_Y));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_RIGHT_X));
    EXPECT_EQ(0, inputMap.Axis(bpl::controls::AxisCode::AXIS_RIGHT_Y));

} // Controls_InputMap, InputAxis