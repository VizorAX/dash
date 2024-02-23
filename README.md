# Vizor AX Dash
\
Windows input injection library written in C++
- Also works within DirectX context
- Relative mouse movement support
- Interoperability with C

\
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
