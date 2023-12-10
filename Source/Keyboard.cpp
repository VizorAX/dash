#include "Vizor/Dash/Core/Keyboard.h"

using namespace Vizor::Dash::Core;

PROVIDE bool Vizor_Dash_Core_Keyboard_Hold(Keyboard *self, Key key)
{
    auto success = self->Hold(key);
    return success;
}

PROVIDE bool Vizor_Dash_Core_Keyboard_Release(Keyboard *self, Key key)
{
    auto success = self->Release(key);
    return success;
}

PROVIDE bool Vizor_Dash_Core_Keyboard_Press(Keyboard *self, Key key)
{
    auto success = self->Press(key);
    return success;
}

PROVIDE bool Vizor_Dash_Core_Keyboard_PressWithDelay(Keyboard *self, Key key, int32_t delay)
{
    auto success = self->Press(key, delay);
    return success;
}

PROVIDE bool Vizor_Dash_Core_Keyboard_IsOn(Keyboard *self, Key key)
{
    return self->IsOn(key);
}

PROVIDE bool Vizor_Dash_Core_Keyboard_IsDown(Keyboard *self, Key key)
{
    return self->IsDown(key);
}

PROVIDE bool Vizor_Dash_Core_Keyboard_WasPressed(Keyboard *self, Key key)
{
    return self->WasPressed(key);
}

PROVIDE void Vizor_Dash_Core_Keyboard_Destroy(Keyboard *self)
{
    delete self;
}
