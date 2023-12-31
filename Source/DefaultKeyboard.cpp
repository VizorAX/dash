#include <new>
#include "Vizor/Dash/Core/DefaultKeyboard.h"

using namespace Vizor::Dash::Core;
using namespace std;

void DefaultKeyboard::Hold(Key key, Input &result)
{
    ZeroMemory(&result, sizeof result);

    auto scan = MapVirtualKeyA(key, MAPVK_VK_TO_VSC_EX);

    auto isExtended =
        0xe000 == (scan & 0xe000)   ||
        0xe000 == (key & 0xe000)    ||
        false;

    result.type = INPUT_KEYBOARD;
    result.ki.dwFlags = KEYEVENTF_EXTENDEDKEY * isExtended;
    result.ki.wScan = scan;
    result.ki.wVk = key;
}

bool DefaultKeyboard::Hold(Key key)
{
    Input hold;
    Hold(key, hold);

    auto sent = SendInput(1, &hold, sizeof hold);

    return sent == 1;
}

bool DefaultKeyboard::Release(Key key)
{
    Input release;
    Hold(key, release);
    release.ki.dwFlags |= KEYEVENTF_KEYUP;

    auto sent = SendInput(1, &release, sizeof release);

    return sent == 1;
}

bool DefaultKeyboard::Press(Key key, int32_t delay)
{
    auto success = Press(key);
    Sleep(delay);
    return success;
}

bool DefaultKeyboard::Press(Key key)
{
    Input hold;
    Hold(key, hold);

    auto release = hold;
    release.ki.dwFlags |= KEYEVENTF_KEYUP;

    Input inputGroup[2] { hold, release };
    auto sent = SendInput(2, inputGroup, sizeof Input);
    return sent == 2;
}

bool DefaultKeyboard::IsOn(Key key)
{
    auto state = GetKeyState(key);
    state &= 0x0001;
    return state;
}

bool DefaultKeyboard::WasPressed(Key key)
{
    auto state = GetAsyncKeyState(key);
    state &= 0x0001;
    return state;
}

bool DefaultKeyboard::IsDown(Key key)
{
    auto state = GetKeyState(key);
    state &= 0x8000;
    return state;
}

PROVIDE Keyboard *Vizor_Dash_Core_DefaultKeyboard_Create()
{
    auto self = new (nothrow) DefaultKeyboard;
    return self;
}
