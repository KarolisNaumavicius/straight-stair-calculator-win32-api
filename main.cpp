#include <windows.h>
#include <cwchar>
#include "StraightStair.h"
#include "PriceStair.h"

// Funkcija, kuri apdoroja lango įvykius
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hEditHeight, hEditLength, hEditSteps, hEditCeiling, hEditOpeningLength, hEditRun, hEditRise, hEditHeadroom, hEditPrice, hEditPriceForAStep;

    switch (uMsg) {
        case WM_CREATE:
            // Sukuriamas tekstas (Hello World)
            CreateWindowW(L"Static", L"Straight Stair Calculator", 
                        WS_VISIBLE | WS_CHILD | SS_CENTER, 
                        50, 20, 300, 20, hWnd, NULL, NULL, NULL);
            
            CreateWindowW(L"Static", L"Floor to floor height (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 60, 180, 30, hWnd, NULL, NULL, NULL);
            hEditHeight = CreateWindowW(L"Edit", L"0", 
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 
                        260, 60, 100, 30, hWnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Stair length (mm):", 
                        WS_VISIBLE | WS_CHILD,
                        75, 100, 180, 30, hWnd, NULL, NULL, NULL);
            hEditLength = CreateWindowW(L"Edit", L"0", 
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 
                        260, 100, 100, 30, hWnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Ceiling thickness (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 140, 180, 30, hWnd, NULL, NULL, NULL);
            hEditCeiling = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 
                        260, 140, 100, 30, hWnd, NULL, NULL, NULL);

            CreateWindowW(L"Static", L"Opening Length (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 180, 180, 30, hWnd, NULL, NULL, NULL);
            hEditOpeningLength = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, 
                        260, 180, 100, 30, hWnd, NULL, NULL, NULL);
            
            CreateWindowW(L"Static", L"Number of steps:",
                        WS_VISIBLE | WS_CHILD,
                        75, 220, 100, 30,
                        hWnd, NULL, NULL, NULL);
            hEditSteps = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
                        260, 220, 100, 30,
                        hWnd, NULL, NULL, NULL);
            // RESULTS
            CreateWindowW(L"Static", L"Run (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 300, 180, 30,
                        hWnd, NULL, NULL, NULL);
            hEditRun = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER,
                        260, 300, 100, 30, 
                        hWnd, NULL, NULL, NULL);
            
            CreateWindowW(L"Static", L"Rise (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 340, 180, 30,
                        hWnd, NULL, NULL, NULL);
            hEditRise = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
                        260, 340, 100, 30,
                        hWnd, NULL, NULL, NULL);
            
            CreateWindowW(L"Static", L"Headroom (mm):",
                        WS_VISIBLE | WS_CHILD,
                        75, 380, 180, 30,
                        hWnd, NULL, NULL, NULL);
            hEditHeadroom = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY,
                        260, 380, 100, 30,
                        hWnd, NULL, NULL, NULL);
            
            CreateWindowW(L"Static", L"Price for a step:",
                        WS_VISIBLE | WS_CHILD,
                        75, 420, 180, 30,
                        hWnd, NULL, NULL, NULL);
            hEditPriceForAStep = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
                        260, 420, 100, 30,
                        hWnd, NULL, NULL, NULL);
            CreateWindowW(L"Static", L"Price:",
                            WS_VISIBLE | WS_CHILD,
                            75, 460, 180, 30,
                            hWnd, NULL, NULL, NULL);
            hEditPrice = CreateWindowW(L"Edit", L"0",
                        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_READONLY,
                        260, 460, 100, 30,
                        hWnd, NULL, NULL, NULL);

            // Sukuriamas mygtukas <BUTTON>
            CreateWindowW(L"Button", L"Calculate", 
                        WS_VISIBLE | WS_CHILD, 
                        260, 260, 100, 30, 
                        hWnd, (HMENU)1, NULL, NULL);
            CreateWindowW(L"Button", L"Calculate",
                        WS_VISIBLE | WS_CHILD,
                        260, 500, 100, 30,
                        hWnd, (HMENU)2, NULL, NULL);
            break;

        case WM_COMMAND:
            // Jei paspaudžiamas mygtukas (ID 1)
            if (LOWORD(wParam) == 1) {
              //  MessageBoxW(hWnd, L"Alio", L"Pranesimas", MB_OK);
              wchar_t buffer[8];

              GetWindowTextW(hEditHeight, buffer, 8);
              double height = _wtof(buffer);

              GetWindowTextW(hEditLength, buffer, 8);
              double length = _wtof(buffer);

              GetWindowTextW(hEditCeiling, buffer, 8);
              double ceiling = _wtof(buffer);

              GetWindowTextW(hEditOpeningLength, buffer, 8);
              double openingLength = _wtof(buffer);

              GetWindowTextW(hEditSteps, buffer, 8);
              int steps = _wtof(buffer);

              GetWindowTextW(hEditRun, buffer, 8);
              double run = _wtof(buffer);

              // SKAICIAVIMAS
              double rise = 0, headroom = 0;
              
              StraightStair staircase(height, &length, steps, ceiling, openingLength, &run, &rise, &headroom);
              
              if(!run) {
                staircase.riseAndRunCalculator();
              }
           
              staircase.lengthByRunCalculator();
        

              staircase.headroomCalculator();

              wchar_t outBuffer[8];
              swprintf(outBuffer, 8, L"%.2f", run);
              SetWindowTextW(hEditRun, outBuffer);

              swprintf(outBuffer, 8, L"%.2f", rise);
              SetWindowTextW(hEditRise, outBuffer);

              swprintf(outBuffer, 8, L"%.2f", length);
              SetWindowTextW(hEditLength, outBuffer);

              swprintf(outBuffer, 8, L"%.2f", headroom);
              SetWindowTextW(hEditHeadroom, outBuffer);
            }

            if(LOWORD(wParam) == 2) {
              wchar_t buffer[8];

              GetWindowTextW(hEditPriceForAStep, buffer, 8);
              double priceForAStep = _wtof(buffer);

              GetWindowTextW(hEditSteps, buffer, 8);
              int steps = _wtof(buffer);

              wchar_t outBuffer[8];
            
              double price = 0;

              PriceStair priceCalculated(steps, priceForAStep, &price);

              priceCalculated.priceStair();

              swprintf(outBuffer, 8, L"%.2f", price);
              SetWindowTextW(hEditPrice, outBuffer);

            }

            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Pagrindinė Windows programos funkcija
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // Balta lango spalva
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    const wchar_t* myClassName = L"StairCalculatorProgram"; 
    wc.lpszClassName = myClassName;
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    // Sukuriamas pats langas
    CreateWindowW(myClassName, L"Straight staircase calculation program", 
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                  200, 200, 470, 600, NULL, NULL, NULL, NULL);

    // Žinučių ciklas (kad programa neužsidarytų)
    MSG msg = {0};
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}