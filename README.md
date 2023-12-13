# Vizor AX Dash
<br>
Windows input injection library written in C++
<br>
- Also works within DirectX context
- Interoperability with C
<br>
Exported functionality (shared build)
```cpp
Pointer *Vizor_Dash_Core_DefaultPointer_Create();
bool Vizor_Dash_Core_Pointer_MoveToRange(Pointer *self, double x, double y);
bool Vizor_Dash_Core_Pointer_MoveTo(Pointer *self, int32_t x, int32_t y);
bool Vizor_Dash_Core_Pointer_MoveBy(Pointer *self, int32_t xDelta, int32_t yDelta);
bool Vizor_Dash_Core_Pointer_Hold(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_Release(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_Click(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_ScrollBy(Pointer *self, int32_t amount, ScrollDirection direction);
bool Vizor_Dash_Core_Pointer_ScrollByWithDelay(Pointer *self, int32_t amount, ScrollDirection direction, int32_t delayAfter);
bool Vizor_Dash_Core_Pointer_GetPosition(Pointer *self, int32_t *x, int32_t *y);
bool Vizor_Dash_Core_Pointer_IsDown(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_WasPressed(Pointer *self, Button button);
void Vizor_Dash_Core_Pointer_Destroy(Pointer *self);

Keyboard *Vizor_Dash_Core_DefaultKeyboard_Create();
bool Vizor_Dash_Core_Keyboard_Hold(Keyboard *self, Key key);
bool Vizor_Dash_Core_Keyboard_Release(Keyboard *self, Key key);
bool Vizor_Dash_Core_Keyboard_Press(Keyboard *self, Key key);
bool Vizor_Dash_Core_Keyboard_PressWithDelay(Keyboard *self, Key key, int32_t delayAfter);
bool Vizor_Dash_Core_Keyboard_IsOn(Keyboard *self, Key key);
bool Vizor_Dash_Core_Keyboard_IsDown(Keyboard *self, Key key);
bool Vizor_Dash_Core_Keyboard_WasPressed(Keyboard *self, Key key);
void Vizor_Dash_Core_Keyboard_Destroy(Keyboard *self);
```

C++ example
```cpp
#include <memory>
#include <Vizor/Dash.h>

// Layout selected
using namespace Vizor::Dash::Layout::Default;
using namespace Vizor::Dash::Core;
using namespace std;

int main()
{
    unique_ptr<Keyboard> keyboard = make_unique<DefaultKeyboard>();
    unique_ptr<Pointer> pointer = make_unique<DefaultPointer>();

    auto success = true;

    success &= pointer->MoveTo(640, 360);

    success &= keyboard->Hold(KEY_LWIN);
    success &= keyboard->Press(KEY_R);
    success &= keyboard->Release(KEY_LWIN);

    return !success;
}
```
