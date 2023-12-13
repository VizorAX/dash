#pragma once

#include <cinttypes>
#include <Windows.h>
#include "../Utility/Provide.h"

namespace Vizor::Dash::Core {

// Mouse button
enum Button
{
	LEFT	= MOUSEEVENTF_LEFTDOWN,
	RIGHT	= MOUSEEVENTF_RIGHTDOWN,
	MIDDLE	= MOUSEEVENTF_MIDDLEDOWN,
};

struct CursorPosition
{
	uint16_t x;
	uint16_t y;
};

enum ScrollDirection
{
	AWAY = +1,
	BACK = -1,
};

struct Pointer
{
	// From 0.0 to 1.0
	virtual bool MoveTo(double x, double y) = 0;

	// Pixel position
	virtual bool MoveTo(int32_t x, int32_t y) = 0;

	// Relative mode
	// Delta != pixel
	virtual bool MoveBy(int32_t xDelta, int32_t yDelta) = 0;

	virtual bool Hold(Button button) = 0;

	virtual bool Release(Button button) = 0;

	virtual bool Click(Button button) = 0;

	// Vertical scrolling
	// Delay after each click is given in milliseconds
	virtual bool ScrollBy(int32_t clickCount, ScrollDirection direction, int32_t delayAfter = 0) = 0;

	virtual bool GetPosition(CursorPosition &output) = 0;

	virtual bool IsDown(Button button) = 0;

	virtual bool WasPressed(Button button) = 0;

	virtual ~Pointer() = default;
};

} // namespace Vizor::Dash::Core

extern "C"
{
	using namespace Vizor::Dash::Core;

	PROVIDE bool Vizor_Dash_Core_Pointer_MoveToRange		( Pointer *self, double x, double y												);
	PROVIDE bool Vizor_Dash_Core_Pointer_MoveTo				( Pointer *self, int32_t x, int32_t y											);
	PROVIDE bool Vizor_Dash_Core_Pointer_MoveBy				( Pointer *self, int32_t xDelta, int32_t yDelta									);
	PROVIDE bool Vizor_Dash_Core_Pointer_Hold				( Pointer *self, Button button													);
	PROVIDE bool Vizor_Dash_Core_Pointer_Release			( Pointer *self, Button button													);
	PROVIDE bool Vizor_Dash_Core_Pointer_Click				( Pointer *self, Button button													);
	PROVIDE bool Vizor_Dash_Core_Pointer_ScrollBy			( Pointer *self, int32_t amount, ScrollDirection direction						);
	PROVIDE bool Vizor_Dash_Core_Pointer_ScrollByWithDelay	( Pointer *self, int32_t amount, ScrollDirection direction, int32_t delayAfter	);
	PROVIDE bool Vizor_Dash_Core_Pointer_GetPosition		( Pointer *self, int32_t *x, int32_t *y											);
	PROVIDE bool Vizor_Dash_Core_Pointer_IsDown				( Pointer *self, Button button													);
	PROVIDE bool Vizor_Dash_Core_Pointer_WasPressed			( Pointer *self, Button button													);

	PROVIDE void Vizor_Dash_Core_Pointer_Destroy			( Pointer *self																	);
}
