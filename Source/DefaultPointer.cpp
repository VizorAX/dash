#include <Windows.h>
#include "Vizor/Dash/Core/DefaultPointer.h"

using namespace Vizor::Dash::Core;

#ifdef _DEBUG
#define CHECK_RAW_RANGE(X, Y) \
    if (X < 0 || X > 0xffff) return false; \
    if (Y < 0 || Y > 0xffff) return false;
#else
#define CHECK_RAW_RANGE(X, Y)
#endif // DEBUG

bool DefaultPointer::MoveToRaw(int32_t x, int32_t y)
{
    CHECK_RAW_RANGE(x, y);

    bool success = Move(x, y, MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
    return success;
}

bool DefaultPointer::MoveTo(int32_t x, int32_t y)
{
    bool success = SetCursorPos(x, y);
    return success;
}

bool DefaultPointer::MoveBy(int32_t x, int32_t y)
{
    bool success = Move(x, y, MOUSEEVENTF_MOVE);
    return success;
}

bool DefaultPointer::Move(int32_t x, int32_t y, int32_t flags)
{
    INPUT input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = flags;
    input.mi.dx = x;
    input.mi.dy = y;

    auto sent = SendInput(1, &input, sizeof input);
    return sent == 1;
}

bool DefaultPointer::Hold(Button button)
{
    INPUT input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = button;

    auto sent = SendInput(1, &input, sizeof input);
    return sent == 1;
}

bool DefaultPointer::Release(Button button)
{
    INPUT input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = button << 1;

    auto sent = SendInput(1, &input, sizeof input);
    return sent == 1;
}

bool DefaultPointer::Click(Button button)
{
    bool success = true;
    success &= Hold(button);
    success &= Release(button);
    return success;
}

bool DefaultPointer::ScrollBy(int32_t count, int32_t delay)
{

#ifdef _DEBUG
    if (count == 0 || count < -999'999 || count > 999'999)
    {
        return false;
    }
    if (delay < 0 || delay > 999'999)
    {
        return false;
    }
#endif

    auto absoluteCount = count * ((count > 0) - (count < 0));

    INPUT input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = WHEEL_DELTA * (count / absoluteCount);

    auto sent = 0;
    auto const expected = absoluteCount;
    while (absoluteCount--)
    {
        sent += SendInput(1, &input, sizeof input);
        Sleep(delay);
    }

    return sent == expected;
}

bool DefaultPointer::GetPosition(CursorPosition &result)
{
    POINT point;

    bool success = GetCursorPos(&point);

    result.x = point.x;
    result.y = point.y;

    return success;
}

bool DefaultPointer::IsDown(Button button)
{
    auto state = GetKeyState(button);
    state &= 0x8000;
    return state;
}

bool DefaultPointer::WasPressed(Button button)
{
    auto state = GetAsyncKeyState(button);
    state &= 0x0001;
    return state;
}

PROVIDE Pointer *Vizor_Dash_Core_DefaultPointer_Create()
{
    auto self = new DefaultPointer;
    return self;
}
