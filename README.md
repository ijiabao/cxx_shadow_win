# cxx_shadow_win
无标题窗口的阴影支持

```
// 使用示例
#include "shadow_window.h"
void Test() {
	HWND hwnd = FindWindow(L"TestWindow", L"");
	if (IsSupportDwm()) {
		EnableDwmShadow(hwnd, true);
	} else {
		ShadowWnd* win = BindShadowWindow(hwnd);
		// win->Setup(10, 20, 255, 0);
	}
}
```
