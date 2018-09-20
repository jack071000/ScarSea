#pragma once
class App : public Singleton<App>
{
private:
	int m_Width;
	int m_Height;
	bool m_WindowMode;

	HWND m_Hwnd;

public:
	App();
	~App();

private:
	bool _CreateWindow();
	bool _CreateRenderer();

public:
	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

	HWND GetHwnd() {
		return m_Hwnd;
	}
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	
};

