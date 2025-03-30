// Laba7.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba7.h"

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
    LoadStringW(hInstance, IDC_LABA7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA7));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA7);
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

            HPEN hPenRed = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
            HPEN hPenGreen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));

            // Домик
            SelectObject(hdc, hPenRed);
            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 275, 250);
            LineTo(hdc, 400, 350);
            LineTo(hdc, 150, 350);

            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 400, 350);
            LineTo(hdc, 400, 525);
            LineTo(hdc, 150, 525);
            LineTo(hdc, 150, 350);

            MoveToEx(hdc, 225, 400, NULL);
            LineTo(hdc, 225, 475);
            LineTo(hdc, 325, 475);
            LineTo(hdc, 325, 400);
            LineTo(hdc, 225, 400);

            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);

            // Елочка
            SelectObject(hdc, hPenGreen);
            MoveToEx(hdc, 450, 525, NULL);
            LineTo(hdc, 525, 450);
            LineTo(hdc, 600, 525);
            LineTo(hdc, 450, 525);

            MoveToEx(hdc, 450, 450, NULL);
            LineTo(hdc, 525, 375);
            LineTo(hdc, 600, 450);
            LineTo(hdc, 450, 450);

            MoveToEx(hdc, 450, 375, NULL);
            LineTo(hdc, 525, 300);
            LineTo(hdc, 600, 375);
            LineTo(hdc, 450, 375);

            int x1 = 400, y1 = 150;
            int x2 = 500, y2 = 250;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 5;
            } while (x1 <= 600);

            x1 = 0, y1 = 250;
            x2 = 100, y2 = 250;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 25;
                y1 -= 50;
            } while (x1 <= 100);

            x1 = 100;
            y1 = 50;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 25;
                y1 += 50;
            } while(x1 <= 200);


            x1 = 150, y1 = 0;
            x2 = 150, y2 = 100;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);

                x1 += 5;
                x2 += 5;
            } while (x1 <= 450);
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
