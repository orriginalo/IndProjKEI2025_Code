// Laba14.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba14.h"

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
    LoadStringW(hInstance, IDC_LABA14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA14));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA14);
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

void Image1(HDC hdc, int cx, int cy, COLORREF color, int radius = 5) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    // Рисуем круг
    Ellipse(hdc, cx - radius, cy - radius, cx + radius, cy + radius);

    // Вычисляем вершины звезды
    POINT p1 = { cx, cy - radius };  // Верхняя точка
    POINT p2 = { cx - (int)(radius * 0.866), cy + (int)(radius * 0.5) };  // Левая точка
    POINT p3 = { cx + (int)(radius * 0.866), cy + (int)(radius * 0.5) };  // Правая точка

    // Рисуем три луча
    MoveToEx(hdc, cx, cy, NULL);
    LineTo(hdc, p1.x, p1.y);

    MoveToEx(hdc, cx, cy, NULL);
    LineTo(hdc, p2.x, p2.y);

    MoveToEx(hdc, cx, cy, NULL);
    LineTo(hdc, p3.x, p3.y);

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


struct Image {
    int x;
    int y;
    int vx;
    int vy;
    COLORREF color;
};
typedef struct Image IMAGE;

IMAGE im1 = { 100, 200, 5, 16, RGB(128, 128, 0) };
IMAGE im2 = { 50, 250, 15, 13, RGB(0, 255, 0) };
IMAGE im4 = { 200, 300, 30, -8, RGB(0, 0, 255) };
IMAGE im5 = { 400, 250, -25, 3, RGB(0, 255, 255) };
IMAGE im6 = { 300, 150, -25, 3, RGB(255, 255, 0) };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 1, 500, 0);
        break;

    case WM_TIMER:

        im1.x += im1.vx;
        im1.y += im1.vy;

        im2.x += im2.vx;
        im2.y += im2.vy;

        im4.x += im4.vx;
        im4.y += im4.vy;

        im5.x += im5.vx;
        im5.y += im5.vy;

        im6.x += im6.vx;
        im6.y += im6.vy;
        InvalidateRect(hWnd, NULL, TRUE);

        break;
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
            
            Image1(hdc, im1.x, im1.y, im1.color);
            Image2(hdc, im2.x, im2.y, im2.color);
            Image4(hdc, im4.x, im4.y, im4.color);
            Image2(hdc, im5.x, im5.y, im5.color);
            Image1(hdc, im6.x, im6.y, im6.color);
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
