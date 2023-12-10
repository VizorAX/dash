#pragma once

#include <cinttypes>
#include "../Utility/Provide.h"

namespace Vizor::Dash::Core {

typedef int32_t Key;

struct Keyboard
{
	virtual bool Hold(Key key) = 0;

	virtual bool Release(Key key) = 0;

	// Tap a key
	virtual bool Press(Key key) = 0;

	// Delay after press given in milliseconds
	virtual bool Press(Key key, int32_t delayAfter) = 0;

	// True when toggled
	virtual bool IsOn(Key key) = 0;

	virtual bool IsDown(Key key) = 0;

	// True if pressed after last call
	virtual bool WasPressed(Key key) = 0;

	virtual ~Keyboard() {}
};

} // namespace Vizor::Dash::Core

extern "C"
{
	using namespace Vizor::Dash::Core;

	PROVIDE bool Vizor_Dash_Core_Keyboard_Hold				( Keyboard *self, Key key						);
	PROVIDE bool Vizor_Dash_Core_Keyboard_Release			( Keyboard *self, Key key						);
	PROVIDE bool Vizor_Dash_Core_Keyboard_Press				( Keyboard *self, Key key						);
	PROVIDE bool Vizor_Dash_Core_Keyboard_PressWithDelay	( Keyboard *self, Key key, int32_t delayAfter	);
	PROVIDE bool Vizor_Dash_Core_Keyboard_IsOn				( Keyboard *self, Key key						);
	PROVIDE bool Vizor_Dash_Core_Keyboard_IsDown			( Keyboard *self, Key key						);
	PROVIDE bool Vizor_Dash_Core_Keyboard_WasPressed		( Keyboard *self, Key key						);

	PROVIDE void Vizor_Dash_Core_Keyboard_Destroy			( Keyboard *self								);
}
