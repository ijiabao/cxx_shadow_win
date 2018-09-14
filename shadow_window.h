/**
 * Created by ijiabao<ijiabao@qq.com>
 * Home: http://www.jurlu.com/
 * Support: https://github.com/ijiabao
 * User: iJiabao
 * Date: 2018/9/10
 * Time: 0:17
 */

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// ��Ӱ���ڽӿ�
struct ShadowWnd {
	virtual void Setup(int size, int sharpness, int darkness, int offset) = 0;
	virtual void Update() = 0;
};

// ����һ����Ӱ���ڣ���Ŀ�괰�ڽ��а󶨣�����һ���ӿ�(�����ͷ�, ��������Ŀ�괰��ͬ��)
// ע��ǿ������WM_NCCALCSIZE��Ϣ��ʹ֮�����Ʊ߿�ͱ�����
ShadowWnd* BindShadowWindow(HWND hwnd_dest);

// ɾ���󶨵���Ӱ����
void UnbindShadowWindow(HWND hwnd_dest);

// ��ȡ�󶨵���Ӱ���ڣ��������ڣ�Ӧʹ��GetShadowWindow()��ȡ��ص���Ӱ�������ж��Ƿ�Ϊ��
ShadowWnd* GetShadowWindow(HWND hwnd_dest);

// ����DWM���ڹ������Դ�����Ӱ��Ч
// ǰ�᣺ ��ʽ: WS_THICKFRAME, IsCompositionActive(), �Լ�����WM_NCCALESIZE��Ϣ
// ���ָ��force_hook, ��ǿ���޸���ʽ,�Լ�����WM_NCCALESIZE��Ϣ, ������ȷ��Ŀ�괰��������ǰ��
int EnableDwmShadow(HWND hwnd, int enable, int force_hook = 1);


// ������ XP/Win7�������⣬����һ�����·���Ӱ��Ч�� ������overlapped window
// CS_DROPSHADOW
int EnableStyleShadow(HWND hwnd, int enable);

// ���֧��DWM,��ʹ�� EnableDwmShadow()��������Ӱ��
int IsSupportDwm();



// ����һ����alphaͨ������Ӱͼ��
// width,height ���δ�С���Դ˾���������չ��Ӱ
// size: -20 ~ +20 ��Ӱ���
// sharpness: ����, 0-20, 0Ϊ������
// darkness: ɫ�������0-255, Խ��Խ��
// color: ��ɫ�� 0Ϊ��ɫ
// offset: ƫ�ƣ� -20 ~ +20 ��ָ����Ϊ������������ ����Ϊ����
// rgn: ��״
HBITMAP MakeShadowImage(
	int width,
	int height,
	int size = 10,
	int sharpness = 20,
	int darkness = 30,
	COLORREF color = 0,
	int offset = 0,
	HRGN rgn = 0);


// ʹ��ʾ��
namespace test_shadow_window {
inline void Test() {
	HWND hwnd = FindWindow(L"TestWindow", L"");
	if (IsSupportDwm()) {
		EnableDwmShadow(hwnd, true);
	} else {
		ShadowWnd* win = BindShadowWindow(hwnd);
		// win->Setup(10, 20, 255, 0);
	}
}
};

