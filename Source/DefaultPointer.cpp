#include <new>
#include <Windows.h>
#include "Vizor/Dash/Core/DefaultPointer.h"

#ifdef _DEBUG
    #define CHECK_RANGE(X, Y) \
        if (X >= 0 && X <= 1) return false; \
        if (Y >= 0 && Y <= 1) return false;
#else
    #define CHECK_RANGE(X, Y)
#endif // _DEBUG

using namespace std;
using namespace Vizor::Dash::Core;
using Point = POINT;
using Input = INPUT;

bool DefaultPointer::MoveTo(double x, double y)
{
    CHECK_RANGE(x, y);

    int32_t const x_ = x * 0xffff;
    int32_t const y_ = y * 0xffff;

    auto success = Move(x_, y_, MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
    return success;
}

bool DefaultPointer::MoveTo(int32_t x, int32_t y)
{
    auto success = SetCursorPos(x, y);
    return success;
}

bool DefaultPointer::MoveBy(int32_t x, int32_t y)
{
    auto success = Move(x, y, MOUSEEVENTF_MOVE);
    return success;
}

bool DefaultPointer::Move(int32_t x, int32_t y, int32_t flags)
{
    Input input;
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
    Input input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = button;

    auto sent = SendInput(1, &input, sizeof input);
    return sent == 1;
}

bool DefaultPointer::Release(Button button)
{
    Input input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = button << 1;

    auto sent = SendInput(1, &input, sizeof input);
    return sent == 1;
}

bool DefaultPointer::Click(Button button)
{
    auto success = true;
    success &= Hold(button);
    success &= Release(button);
    return success;
}

bool DefaultPointer::ScrollBy(int32_t count, ScrollDirection direction, int32_t delay)
{

#ifdef _DEBUG
    auto constexpr limit = 0xff'ff'ff;
    auto const ok =
        count != 0      &&
        count >= -limit &&
        count <= +limit &&
        delay >= 0      &&
        delay <= limit  &&
        true;

    if (!ok)
    {
        return false;
    }
#endif // _DEBUG

    Input input;
    ZeroMemory(&input, sizeof input);

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = WHEEL_DELTA * direction;

    auto sent = 0;
    auto const expected = count;
    while (count--)
    {
        sent += SendInput(1, &input, sizeof input);
        Sleep(delay);
    }

    return sent == expected;
}

bool DefaultPointer::GetPosition(CursorPosition &result)
{
    Point point;

    auto success = GetCursorPos(&point);

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
    auto self = new (nothrow) DefaultPointer;
    return self;
}
