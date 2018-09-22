#include "stdafx.h"
#include "App.h"


App::App()
{
}


App::~App()
{
}

bool App::Init(int width, int height, bool windowMode)
{
	m_Width = width;
	m_Height = height;
	m_WindowMode = windowMode;

	if (!_CreateWindow())
		return false;
	
	if (!_CreateRenderer())
		return false;

	return true;
}

void App::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	DWORD Prev = GetTickCount();
	int FPS = 0;
	float fAccTime = 0.f;

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			float delta;
			DWORD current = GetTickCount();
			delta = (float)(current - Prev) / 1000.f;
			fAccTime += delta;
			Prev = current;

			//printf("Button : %d\n",INPUT->GetButtonDown());

			Renderer::GetInst()->Begin();
			SceneDirector::GetInst()->Update(delta);
			SceneDirector::GetInst()->Render();
			Renderer::GetInst()->End();

			++FPS;

			if (fAccTime >= 1.f)
			{
				wchar_t szFps[32];
				swprintf_s(szFps, L"FPS : %d", FPS);
				SetWindowText(m_Hwnd, szFps);
				FPS = 0;
				fAccTime = 0.f;
			}

			if (GetAsyncKeyState(VK_ESCAPE))
			{
				App::GetInst()->Release();
				exit(0);
			}
		}
	}

}

void App::Release()
{
	FreeConsole();
	Renderer::GetInst()->Release();
}

bool App::IsInWindowRect(float x, float y)
{
	if (x > 0 && x < m_Width)
	{
		if (y > 0 && y < m_Height)
			return true;
	}

	return false;
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		App::GetInst()->Release();
		break;
	//case WM_LBUTTONDOWN:
	//	INPUT->ButtonDown(true);
	//	break;

	//case WM_LBUTTONUP:
	//	INPUT->ButtonDown(false);
	//	break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool App::_CreateWindow()
{
	WNDCLASS wc = {};
	wc.lpszClassName = L"ScarSea";
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpfnWndProc = WndProc;

	RegisterClass(&wc);

	DWORD Style = 0;

	if (m_WindowMode)
		Style = WS_POPUP;
	else
		Style = WS_POPUP | WS_EX_TOPMOST;

	HWND hWnd = CreateWindow(L"ScarSea", L"ScarSea", Style, 0, 0, m_Width, m_Height, NULL, NULL, NULL, NULL);
	if (hWnd)
		m_Hwnd = hWnd;
	else
		return false;

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);


	return true;
}

bool App::_CreateRenderer()
{
	if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode)))
		return false;

	return true;
}
