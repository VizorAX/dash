#include "Vizor/Dash/Core/Pointer.h"

using namespace Vizor::Dash::Core;

PROVIDE bool Vizor_Dash_Core_Pointer_MoveToRange(Pointer *self, double x, double y)
{
	auto success = self->MoveTo(x, y);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_MoveTo(Pointer *self, int32_t x, int32_t y)
{
	auto success = self->MoveTo(x, y);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_MoveBy(Pointer *self, int32_t xDelta, int32_t yDelta)
{
	auto success = self->MoveBy(xDelta, yDelta);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Hold(Pointer *self, Button button)
{
	auto success = self->Hold(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Release(Pointer *self, Button button)
{
	auto success = self->Release(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Click(Pointer *self, Button button)
{
	auto success = self->Click(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_ScrollBy(Pointer *self, int32_t amount, ScrollDirection direction)
{
	auto success = self->ScrollBy(amount, direction);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_ScrollByWithDelay(Pointer *self, int32_t amount, ScrollDirection direction, int32_t delay)
{
	auto success = self->ScrollBy(amount, direction, delay);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_GetPosition(Pointer *self, int32_t *x, int32_t *y)
{
	CursorPosition output;
	auto success = self->GetPosition(output);
	*x = output.x;
	*y = output.y;
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_IsDown(Pointer *self, Button button)
{
	return self->IsDown(button);
}

PROVIDE bool Vizor_Dash_Core_Pointer_WasPressed(Pointer *self, Button button)
{
	return self->WasPressed(button);
}

PROVIDE void Vizor_Dash_Core_Pointer_Destroy(Pointer *self)
{
	delete self;
}
