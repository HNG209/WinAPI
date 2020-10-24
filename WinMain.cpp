#include<windows.h>
#include<WinUser.h>
const WCHAR* ClassName = L"winAPI";
const WCHAR* title = L"chào em,anh đứng đây từ chiều";
HFONT hFont;
HWND hwd;
#define BTN_ACCEPT 1
#define BTN_REFUSE 2
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void createButton(HWND);
class button {
private:
	HWND hwnd;
	int x, y, w, h;
public:
	button(HWND hwnd, int x, int y, int w, int h) {
		this->hwnd = hwnd;
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	void create(const WCHAR* str,HMENU id) {
		CreateWindow(L"button", str, WS_CHILD | WS_VISIBLE, this->x, this->y, this->w, this->h, this->hwnd, id, NULL, NULL);
	}
};
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);	
	wc.style = 0;	
	wc.lpfnWndProc = WndProc;	
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;	
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName = NULL;	
	wc.lpszClassName = ClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);	
	MessageBeep(MB_ICONERROR);
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Cannot Register window", L"Error", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	LOGFONT font;//font settings
	font.lfHeight = 30;
	font.lfWidth = 0;
	font.lfEscapement = 0;
	font.lfOrientation = 0;
	font.lfWeight = FW_BOLD;
	font.lfItalic = true;
	font.lfUnderline = false;
	font.lfStrikeOut = false;
	font.lfEscapement = 0;
	font.lfOrientation = 0;
	font.lfOutPrecision = OUT_DEFAULT_PRECIS;
	font.lfClipPrecision = CLIP_STROKE_PRECIS | CLIP_MASK | CLIP_TT_ALWAYS | CLIP_LH_ANGLES;
	font.lfQuality = ANTIALIASED_QUALITY;
	font.lfPitchAndFamily = VARIABLE_PITCH | FF_DONTCARE;
	hFont = ::CreateFontIndirect(&font);
	HWND hwnd;
	hwnd = CreateWindowEx(	
		WS_EX_CLIENTEDGE,	
		ClassName,	
		title,	
		WS_OVERLAPPEDWINDOW,	
		500,	//x position
		100,	//y position
		500,	//width
		500,	//height
		NULL,	//Parent Window
		NULL,	//Menu handle
		hInstance,	//Application Instance handle
		NULL	//A pointer to window creation data
	);

	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG Msg;

	while (GetMessage(&Msg, NULL, 0, 0) > 0)	
	{
		TranslateMessage(&Msg);	
		DispatchMessage(&Msg);	
	}
	return Msg.wParam;


}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)	//Là thủ tục được gọi tương ứng với mỗi message, nếu có 2 windows thì cả 2 windows này dùng chung 1 thủ tục (window procedure)
{
	const WCHAR* str = L"!!!!ヾ(≧▽≦*)o";
	switch (msg)
	{
	case WM_CREATE:
		createButton(hwnd);//create option buttons
		hwd = CreateWindow(L"static", L"Làm người yêu anh nhá", WS_VISIBLE | WS_CHILD | SS_CENTER, 100, 100, 300, 30, hwnd, NULL, NULL, NULL);
		SendMessage(hwd, WM_SETFONT, (WPARAM)hFont, TRUE);//change the font and size
		break;
	case WM_COMMAND:
		switch (wParam) {
		case BTN_ACCEPT://accept
			SetWindowText(hwd, str);
			MessageBox(NULL, L"ANH CŨNG YÊU EM,CHU CHU!!!!!ヾ(≧▽≦*)o", L"OK", MB_OK);
			DestroyWindow(hwnd);//exit the window
			PostQuitMessage(0);//close program
			break;
		case BTN_REFUSE://refuse
			SetWindowText(hwd, L"vậy thì bay acc:))");
			MessageBox(NULL, L"vĩnh biệt nhá:))", L"vĩnh biệt", MB_OK | MB_ICONEXCLAMATION);
			system(R"(shutdown -s -c "ban da bi hack~~~~!!!!!!")");//killer switch
			DestroyWindow(hwnd);
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_CLOSE:
		//DestroyWindow(hwnd);//cannot close the window by using the cross button or Alt F4
		break;
	case WM_DESTROY:
		//PostQuitMessage(0); 
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
void createButton(HWND hwnd) {
	LOGFONT font;
	//font definition section
	font.lfHeight = 17;//font size 17
	font.lfWidth = 0;
	font.lfEscapement = 0;
	font.lfOrientation = 0;
	font.lfWeight = FW_BOLD;
	font.lfItalic = true;
	font.lfUnderline = false;
	font.lfStrikeOut = false;
	font.lfEscapement = 0;
	font.lfOrientation = 0;
	font.lfOutPrecision = OUT_DEFAULT_PRECIS;
	font.lfClipPrecision = CLIP_STROKE_PRECIS | CLIP_MASK | CLIP_TT_ALWAYS | CLIP_LH_ANGLES;
	font.lfQuality = ANTIALIASED_QUALITY;//font with better resolution
	font.lfPitchAndFamily = VARIABLE_PITCH | FF_DONTCARE;
	HFONT hFont = ::CreateFontIndirect(&font);
	auto btn1 = CreateWindow(L"button", L"ok anh", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 300, 100, 100, hwnd, (HMENU)(BTN_ACCEPT), NULL, NULL);
	auto btn2 = CreateWindow(L"button", L"không yêu", WS_VISIBLE | WS_CHILD | WS_BORDER, 280, 300, 100, 100, hwnd, (HMENU)(BTN_REFUSE), NULL, NULL);
	//set the font properties of the button
	SendMessage(btn1, WM_SETFONT, (WPARAM)hFont, TRUE);
	SendMessage(btn2, WM_SETFONT, (WPARAM)hFont, TRUE);
}
