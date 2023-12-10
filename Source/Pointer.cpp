#include "Vizor/Dash/Core/Pointer.h"

using namespace Vizor::Dash::Core;

PROVIDE bool Vizor_Dash_Core_Pointer_MoveToRaw(Pointer *self, int32_t x, int32_t y)
{
	bool success = self->MoveToRaw(x, y);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_MoveTo(Pointer *self, int32_t x, int32_t y)
{
	bool success = self->MoveTo(x, y);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_MoveBy(Pointer *self, int32_t xDelta, int32_t yDelta)
{
	bool success = self->MoveBy(xDelta, yDelta);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Hold(Pointer *self, Button button)
{
	bool success = self->Hold(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Release(Pointer *self, Button button)
{
	bool success = self->Release(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_Click(Pointer *self, Button button)
{
	bool success = self->Click(button);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_ScrollBy(Pointer *self, int32_t amount)
{
	bool success = self->ScrollBy(amount);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_ScrollByWithDelay(Pointer *self, int32_t amount, int32_t delay)
{
	bool success = self->ScrollBy(amount, delay);
	return success;
}

PROVIDE bool Vizor_Dash_Core_Pointer_GetPosition(Pointer *self, int32_t *x, int32_t *y)
{
	CursorPosition output;
	bool success = self->GetPosition(output);
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
