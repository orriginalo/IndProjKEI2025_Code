// Laba9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba9.h"

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
    LoadStringW(hInstance, IDC_LABA9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA9);
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

// Елочка
void StClausAuto(HDC hdc, int x, int y) {
    int height_top = 40;   // Верхний треугольник (самый высокий)
    int height_mid = 30;   // Средний треугольник
    int height_bot = 15;   // Нижний треугольник (самый низкий)
    int width = 50;        // Ширина всех треугольников

    MoveToEx(hdc, x, y, NULL);
    LineTo(hdc, x + width / 2, y + height_top);
    LineTo(hdc, x - width / 2, y + height_top);
    LineTo(hdc, x, y);

    MoveToEx(hdc, x, y + height_top / 2, NULL);
    LineTo(hdc, x + width / 2, y + height_top + height_mid);
    LineTo(hdc, x - width / 2, y + height_top + height_mid);
    LineTo(hdc, x, y + height_top / 2);

    MoveToEx(hdc, x, y + height_top, NULL);
    LineTo(hdc, x + width / 2, y + height_top + height_mid + height_bot);
    LineTo(hdc, x - width / 2, y + height_top + height_mid + height_bot);
    LineTo(hdc, x, y + height_top);

    // Ствол
    // !!!
    int trunk_width = 10;
    int trunk_height = 10;
    Rectangle(hdc, x - trunk_width / 2, y + height_top + height_mid + height_bot,
        x + trunk_width / 2, y + height_top + height_mid + height_bot + trunk_height);
}

// Фура
void drawTruck(HDC hdc, int x, int y) {
    // Создаем синюю ручку
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

    // Рисуем кузов и кабину
    Rectangle(hdc, x, y + 30, x + 40, y + 50);
    Rectangle(hdc, x + 10, y, x + 40, y + 30);
    Rectangle(hdc, x + 40, y + 10, x + 100, y + 50);

    // Удаляем синюю ручку
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);

    // Создаем черную ручку
    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    hOldPen = (HPEN)SelectObject(hdc, hPen);

    // Рисуем колеса
    Ellipse(hdc, x + 10, y + 30, x + 40, y + 60);
    Ellipse(hdc, x + 70, y + 40, x + 90, y + 60);

    // Удаляем черную ручку
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
}

// Снеговик
void SnowWoman(HDC hdc, int x, int y) {
    // Радиусы частей снеговика
    // !!!
    int r1 = 15;  // Голова
    int r2 = 25;  // Тело
    int r3 = 35;  // Основание

    // Рисуем круги снеговика (голова, тело, основание)
    Ellipse(hdc, x - r1, y - r1, x + r1, y + r1);
    Ellipse(hdc, x - r2, y + r1, x + r2, y + r1 + 2 * r2);
    Ellipse(hdc, x - r3, y + r1 + 2 * r2, x + r3, y + r1 + 2 * r2 + 2 * r3);

    // Руки (палочки)
    MoveToEx(hdc, x - r2, y + r1 + r2, NULL);
    LineTo(hdc, x - r2 - 20, y + r1 + r2 - 20);

    MoveToEx(hdc, x + r2, y + r1 + r2, NULL);
    LineTo(hdc, x + r2 + 20, y + r1 + r2 - 20);

    // Метла (линии)
    //MoveToEx(hdc, x + r2 + 20, y + r1 + r2 - 20, NULL);
    //LineTo(hdc, x + r2 + 30, y + r1 + r2 - 50);
    //LineTo(hdc, x + r2 + 40, y + r1 + r2 - 20);
    //LineTo(hdc, x + r2 + 20, y + r1 + r2 - 50);
}

// !!!
void drawTrucks(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}

// !!!
void drawSt(HDC hdc) {
    StClausAuto(hdc, 10 + 500, 10);
    StClausAuto(hdc, 10 + 500, 310);
    StClausAuto(hdc, 310 + 500, 10);
    StClausAuto(hdc, 310 + 500, 310);
    StClausAuto(hdc, 160 + 500, 160);
}

// !!!
void drawSnowWomen(HDC hdc) {
    SnowWoman(hdc, 1000, 40);
    SnowWoman(hdc, 1000, 195);
    SnowWoman(hdc, 1000, 350);
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

            drawTrucks(hdc);
            drawSt(hdc);
            drawSnowWomen(hdc);
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
