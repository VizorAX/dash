#pragma once

#include <cinttypes>
#include <Windows.h>
#include "../Utility/Provide.h"
#include "Keyboard.h"

namespace Vizor::Dash::Core
{

struct DefaultKeyboard: Keyboard
{
    bool Hold(Key key) override;
    bool Release(Key key) override;
    bool Press(Key key) override;
    bool Press(Key key, int32_t delayAfter) override;
    bool IsOn(Key key) override;
    bool IsDown(Key key) override;
    bool WasPressed(Key key) override;

private:
    using Input = INPUT;

    void Hold(Key key, Input &result);
};

}

extern "C" PROVIDE Vizor::Dash::Core::Keyboard *Vizor_Dash_Core_DefaultKeyboard_Create();
