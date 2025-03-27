// Laba13.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba13.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LABA13, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA13));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA13));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA13);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[4] = {
        cx,          cy - 20,
        cx + 20,    cy + 20,
        cx - 20,      cy + 20,
        cx,          cy - 20
    };
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}



void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[5] = {
        cx,          cy - 20,
        cx + 20,  cy,
        cx,          cy + 20,
        cx - 20,    cy,
        cx,         cy - 20,
    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}

void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[5] = {
        cx,          cy,
        cx + 20,  cy - 20,
        cx,          cy + 20,
        cx - 20,    cy - 20,
        cx,         cy,
    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}

void Image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[6] = {
        cx,          cy + 40,
        cx,         cy,
        cx + 60,    cy,
        cx + 40,    cy + 10,
        cx + 60,    cy + 20,
        cx,    cy + 20,
    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}

void Picture4ColorLines(HDC hdc) {
    // !!!
    unsigned char r = 255;
    unsigned char g = 0;

    int y = 40;
    char i = 0;
    while (i < 6) {
        int x = 600;
        char j = 0;

        unsigned char b = 0;

        while (j < 10) {
            Image2(hdc, x + 20, y + 20, RGB(r, g, b));
            x += 50;
            j++;

            b += 25;
        }
        y += 50;
        i++;
        g += 50;
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // !!!
            Image1(hdc, 40, 40, RGB(255, 0, 0));
            Image1(hdc, 140, 40, RGB(255, 0, 0));
            Image1(hdc, 240, 40, RGB(255, 0, 0));
            Image1(hdc, 240, 240, RGB(255, 0, 0));
            Image1(hdc, 40, 240, RGB(255, 0, 0));

            Image2(hdc, 40, 40 + 300, RGB(0, 255, 0));
            Image2(hdc, 140, 40 + 300, RGB(0, 255, 0));
            Image2(hdc, 240, 40 + 300, RGB(0, 255, 0));
            Image2(hdc, 240, 240 + 300, RGB(0, 255, 0));
            Image2(hdc, 40, 240 + 300, RGB(0, 255, 0));

            Image3(hdc, 40 + 300, 40, RGB(0, 0, 255));
            Image3(hdc, 140 + 300, 40, RGB(0, 0, 255));
            Image3(hdc, 240 + 300, 40, RGB(0, 0, 255));
            Image3(hdc, 240 + 300, 240, RGB(0, 0, 255));
            Image3(hdc, 40 + 300, 240, RGB(0, 0, 255));

            Image4(hdc, 40 + 300, 40 + 300, RGB(255, 0, 0));
            Image4(hdc, 140 + 300, 40 + 300, RGB(255, 0, 0));
            Image4(hdc, 240 + 300, 40 + 300, RGB(255, 0, 0));
            Image4(hdc, 240 + 300, 240 + 300, RGB(255, 0, 0));
            Image4(hdc, 40 + 300, 240 + 300, RGB(255, 0, 0));

            Picture4ColorLines(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
