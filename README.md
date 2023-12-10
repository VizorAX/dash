# Vizor AX Dash
Windows input injection library written in C++

- Also works within DirectX context
- Interoperability with C

Exported functionality
```
- bool Vizor_Dash_Core_Pointer_MoveToRaw(Pointer *self, int32_t x, int32_t y);
- bool Vizor_Dash_Core_Pointer_MoveTo(Pointer *self, int32_t x, int32_t y);
- bool Vizor_Dash_Core_Pointer_MoveBy(Pointer *self, int32_t xDelta, int32_t yDelta);
- bool Vizor_Dash_Core_Pointer_Hold(Pointer *self, Button button);
- bool Vizor_Dash_Core_Pointer_Release(Pointer *self, Button button);
- bool Vizor_Dash_Core_Pointer_Click(Pointer *self, Button button);
- bool Vizor_Dash_Core_Pointer_ScrollBy(Pointer *self, int32_t amount);
- bool Vizor_Dash_Core_Pointer_ScrollByWithDelay(Pointer *self, int32_t amount, int32_t delayAfter);
- bool Vizor_Dash_Core_Pointer_GetPosition(Pointer *self, int32_t *x, int32_t *y);
- bool Vizor_Dash_Core_Pointer_IsDown(Pointer *self, Button button);
- bool Vizor_Dash_Core_Pointer_WasPressed(Pointer *self, Button button);
- void Vizor_Dash_Core_Pointer_Destroy(Pointer *self);
```
