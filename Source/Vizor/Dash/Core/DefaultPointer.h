#pragma once

#include <cinttypes>
#include "Pointer.h"
#include "../Utility/Provide.h"

namespace Vizor::Dash::Core
{

struct DefaultPointer: Pointer
{
	bool MoveTo(double x, double y) override;
	bool MoveTo(int32_t x, int32_t y) override;
	bool MoveBy(int32_t xDelta, int32_t yDelta) override;
	bool Hold(Button button) override;
	bool Release(Button button) override;
	bool Click(Button button) override;
	bool ScrollBy(int32_t amount, ScrollDirection direction, int32_t delayAfter) override;
	bool GetPosition(CursorPosition &output) override;
	bool IsDown(Button button) override;
	bool WasPressed(Button button) override;

private:
	bool Move(int32_t x, int32_t y, int32_t flags);
};

}

extern "C" PROVIDE Vizor::Dash::Core::Pointer *Vizor_Dash_Core_DefaultPointer_Create();
