# Vizor AX Dash
Windows input injection library written in C++

- Also works within DirectX context
- Interoperability with C

Exported functionality
```
bool Vizor_Dash_Core_Pointer_MoveToRaw(Pointer *self, int32_t x, int32_t y);
bool Vizor_Dash_Core_Pointer_MoveTo(Pointer *self, int32_t x, int32_t y);
bool Vizor_Dash_Core_Pointer_MoveBy(Pointer *self, int32_t xDelta, int32_t yDelta);
bool Vizor_Dash_Core_Pointer_Hold(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_Release(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_Click(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_ScrollBy(Pointer *self, int32_t amount);
bool Vizor_Dash_Core_Pointer_ScrollByWithDelay(Pointer *self, int32_t amount, int32_t delayAfter);
bool Vizor_Dash_Core_Pointer_GetPosition(Pointer *self, int32_t *x, int32_t *y);
bool Vizor_Dash_Core_Pointer_IsDown(Pointer *self, Button button);
bool Vizor_Dash_Core_Pointer_WasPressed(Pointer *self, Button button);
void Vizor_Dash_Core_Pointer_Destroy(Pointer *self);
```

C++ example
```cpp
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

    success &= pointer->MoveRaw(0x7fff, 0x7fff);

    success &= keyboard->Hold(KEY_LWIN);
    success &= keyboard->Press(KEY_R);
    success &= keyboard->Release(KEY_LWIN);

    return !success;
}
```
