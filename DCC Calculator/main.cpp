#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commctrl.h>
#include <string>
#include <vector>

// Zorg dat deze bestanden in je projectmap staan
#include "database.h" 
#include "resource.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// --- CONFIGURATIE & IDs ---
#ifndef IDI_ICON1
#define IDI_ICON1 101 
#endif

#define IDM_FILE_EXIT 2001
#define IDM_HELP_ABOUT 2002
#define IDM_HELP_RELEASE_NOTES 2003
#define ID_BTN_CALC_CV 2
#define ID_BTN_CALC_ADDR 3
#define ID_BTN_GEN_CV29 4
#define ID_BTN_DEC_CV29 5
#define ID_BTN_LOOKUP_DEC 6
#define ID_BTN_CALC_DELAY 7
#define ID_RADIO_E 1001
#define ID_RADIO_D 1002
#define ID_RADIO_S 1003
#define ID_STATUSBAR 5001
#define ID_BTN_PRESET_STD 6001
#define ID_BTN_PRESET_LONG 6002

// --- GLOBALE VARIABELEN ---
HWND hTab, page1, page2, page3, page4, page5;
HWND hAddr, hCV17, hCV18, hCV17b, hCV18b, hResult;
HWND hCV29Input, hCV29Out, hDecodeStatus[8], hBuilderBits[8];
HWND hCV8In, hCV7In, hCV250In, hDecoderResult;
HWND hStap40In, hDelayResult;
HWND hRadioE, hRadioD, hRadioS;
HWND hStatus;
HFONT hUIFont;

const wchar_t* verbeterde_functies[8] = {
    L"Bit 0: Rijrichting (Normaal / Omgekeerd)",
    L"Bit 1: Rijstappen (14 / 28-128 stappen)",
    L"Bit 2: Analoge modus (Uit / Aan)",
    L"Bit 3: RailCom (Uit / Aan)",
    L"Bit 4: Snelheidstabel (Standaard / Eigen)",
    L"Bit 5: Adresmodus (Kort / Lang)",
    L"Bit 6: Gereserveerd",
    L"Bit 7: Gereserveerd"
};

const wchar_t* cv29_builder_labels[8] = {
    L"Bit 0: Omgekeerde rijrichting",
    L"Bit 1: 28/128 Rijstappen (Aanbevolen)",
    L"Bit 2: Analoge modus toestaan (DC)",
    L"Bit 3: RailCom inschakelen",
    L"Bit 4: Eigen snelheidstabel (CV67-94)",
    L"Bit 5: Lang adres gebruiken (CV17/18)",
    L"Bit 6: Gereserveerd",
    L"Bit 7: Gereserveerd"
};

// --- LOGICA ---
int calcCV17(int a) { return 192 + (a / 256); }
int calcCV18(int a) { return a % 256; }
int calcAddr(int a, int b) { return (a - 192) * 256 + b; }

// --- LAYOUT CONSTANTEN ---
constexpr int UI_MARGIN = 25, UI_LBL_W = 140, UI_EDIT_W = 100, UI_BTN_W = 130, UI_ROW_H = 35;

// --- PAGINA BOUWERS ---
void CreatePage1(HWND p) {
    int y = UI_MARGIN;
    CreateWindowW(L"STATIC", L"Loc Adres:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hAddr = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
    CreateWindowW(L"BUTTON", L"Bereken CV's", WS_CHILD | WS_VISIBLE, UI_LBL_W + UI_EDIT_W + 50, y - 2, UI_BTN_W, 28, p, (HMENU)ID_BTN_CALC_CV, NULL, NULL);
    y += UI_ROW_H + 10;
    CreateWindowW(L"STATIC", L"CV17 (Hoog):", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hCV17 = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
    y += UI_ROW_H;
    CreateWindowW(L"STATIC", L"CV18 (Laag):", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hCV18 = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
    y += UI_ROW_H + 30;
    CreateWindowW(L"STATIC", L"Invoer CV17:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hCV17b = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
    y += UI_ROW_H;
    CreateWindowW(L"STATIC", L"Invoer CV18:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hCV18b = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
    CreateWindowW(L"BUTTON", L"Bereken Adres", WS_CHILD | WS_VISIBLE, UI_LBL_W + UI_EDIT_W + 50, y - UI_ROW_H, UI_BTN_W, 28, p, (HMENU)ID_BTN_CALC_ADDR, NULL, NULL);
    y += UI_ROW_H + 10;
    CreateWindowW(L"STATIC", L"Resultaat Adres:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, UI_LBL_W, 22, p, NULL, NULL, NULL);
    hResult = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY, UI_LBL_W + 30, y, UI_EDIT_W, 24, p, NULL, NULL, NULL);
}

void CreatePage2(HWND p) {
    int y = UI_MARGIN;
    CreateWindowW(L"STATIC", L"Stel CV29 in of kies een preset:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 400, 22, p, NULL, NULL, NULL);
    y += 30;
    for (int i = 0; i < 8; i++) {
        hBuilderBits[i] = CreateWindowW(L"BUTTON", cv29_builder_labels[i], WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, UI_MARGIN, y, 450, 25, p, (HMENU)(UINT_PTR)(100 + i), NULL, NULL);
        y += 35;
    }
    y += 10;
    CreateWindowW(L"BUTTON", L"Preset: Kort Adres", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 150, 30, p, (HMENU)ID_BTN_PRESET_STD, NULL, NULL);
    CreateWindowW(L"BUTTON", L"Preset: Lang Adres", WS_CHILD | WS_VISIBLE, UI_MARGIN + 160, y, 150, 30, p, (HMENU)ID_BTN_PRESET_LONG, NULL, NULL);
    y += 45;
    CreateWindowW(L"BUTTON", L"Bereken CV29", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 200, 35, p, (HMENU)ID_BTN_GEN_CV29, NULL, NULL);
    hCV29Out = CreateWindowW(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY, UI_MARGIN + 220, y + 2, 80, 30, p, NULL, NULL, NULL);
}

void CreatePage3(HWND p) {
    int y = UI_MARGIN;
    CreateWindowW(L"STATIC", L"Voer de uitgelezen CV29 waarde in:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 300, 22, p, NULL, NULL, NULL);
    y += 25;
    hCV29Input = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_MARGIN, y, 100, 24, p, NULL, NULL, NULL);
    CreateWindowW(L"BUTTON", L"Decodeer", WS_CHILD | WS_VISIBLE, UI_MARGIN + 120, y - 2, 100, 28, p, (HMENU)ID_BTN_DEC_CV29, NULL, NULL);
    y += 40;
    for (int i = 0; i < 8; i++) {
        CreateWindowW(L"STATIC", verbeterde_functies[i], WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 400, 22, p, NULL, NULL, NULL);
        hDecodeStatus[i] = CreateWindowW(L"STATIC", L"---", WS_CHILD | WS_VISIBLE | SS_CENTER | WS_BORDER, UI_MARGIN + 420, y, 60, 22, p, NULL, NULL, NULL);
        y += 30;
    }
}

void CreatePage4(HWND p) {
    int y = UI_MARGIN;
    CreateWindowW(L"STATIC", L"Fabrikant (CV8):", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 150, 22, p, NULL, NULL, NULL);
    hCV8In = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_MARGIN + 160, y, 100, 24, p, NULL, NULL, NULL);
    y += UI_ROW_H;
    CreateWindowW(L"STATIC", L"Software (CV7):", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 150, 22, p, NULL, NULL, NULL);
    hCV7In = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_MARGIN + 160, y, 100, 24, p, NULL, NULL, NULL);
    y += UI_ROW_H;
    CreateWindowW(L"STATIC", L"Model CV (opt):", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 150, 22, p, NULL, NULL, NULL);
    hCV250In = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_MARGIN + 160, y, 100, 24, p, NULL, NULL, NULL);
    y += 40;
    CreateWindowW(L"BUTTON", L"Zoek Decoder Op", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 260, 32, p, (HMENU)ID_BTN_LOOKUP_DEC, NULL, NULL);
    y += 50;
    hDecoderResult = CreateWindowW(L"STATIC", L"Resultaat verschijnt hier...", WS_CHILD | WS_VISIBLE | SS_SUNKEN, UI_MARGIN, y, 480, 80, p, NULL, NULL, NULL);
}

void CreatePage5(HWND p) {
    int y = UI_MARGIN;
    CreateWindowW(L"STATIC", L"Stap 1: Decoderstap bij 40 km/u:", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 300, 22, p, NULL, NULL, NULL);
    y += 25;
    hStap40In = CreateWindowW(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, UI_MARGIN, y, 100, 24, p, NULL, NULL, NULL);
    y += 40;
    hRadioE = CreateWindowW(L"BUTTON", L"Elektrisch (5000 ms)", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, UI_MARGIN, y, 200, 25, p, (HMENU)ID_RADIO_E, NULL, NULL);
    SendMessage(hRadioE, BM_SETCHECK, BST_CHECKED, 0);
    y += 30;
    hRadioD = CreateWindowW(L"BUTTON", L"Diesel (6000 ms)", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, UI_MARGIN, y, 200, 25, p, (HMENU)ID_RADIO_D, NULL, NULL);
    y += 30;
    hRadioS = CreateWindowW(L"BUTTON", L"Stoom (7000 ms)", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, UI_MARGIN, y, 200, 25, p, (HMENU)ID_RADIO_S, NULL, NULL);
    y += 40;
    CreateWindowW(L"BUTTON", L"Bereken Vertraging", WS_CHILD | WS_VISIBLE, UI_MARGIN, y, 200, 35, p, (HMENU)ID_BTN_CALC_DELAY, NULL, NULL);
    y += 50;
    hDelayResult = CreateWindowW(L"STATIC", L"---", WS_CHILD | WS_VISIBLE | SS_SUNKEN, UI_MARGIN, y, 520, 80, p, NULL, NULL, NULL);
}

// --- CALLBACKS ---
LRESULT CALLBACK PageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_COMMAND) {
        SendMessage(GetParent(GetParent(hwnd)), msg, wParam, lParam);
        return 0;
    }
    if (msg == WM_CTLCOLORSTATIC) {
        HDC hdc = (HDC)wParam;
        SetBkMode(hdc, TRANSPARENT);
        for (int i = 0; i < 8; i++) {
            if ((HWND)lParam == hDecodeStatus[i]) {
                wchar_t txt[10]; GetWindowTextW(hDecodeStatus[i], txt, 10);
                if (wcscmp(txt, L"AAN") == 0) SetTextColor(hdc, RGB(0, 150, 0));
                else if (wcscmp(txt, L"UIT") == 0) SetTextColor(hdc, RGB(200, 0, 0));
                return (INT_PTR)GetSysColorBrush(COLOR_BTNFACE);
            }
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDM_FILE_EXIT: PostQuitMessage(0); break;
        case IDM_HELP_ABOUT: MessageBoxW(hwnd, L"DCCToolbox v0.8.0 Alpha\n\nOntwikkeld voor modelspoorders.", L"Over", MB_OK | MB_ICONINFORMATION); break;
        case IDM_HELP_RELEASE_NOTES: {
            std::wstring notes =
                L"DCCToolbox - Versiehistorie\n"
                L"------------------------------------------\n\n"
                L"Versie 0.8.0 Alpha (Huidig):\n"
                L"• [NIEUW] Naamswijziging van DCC Calculator naar DCCToolbox.\n\n"
                L"Versie 0.7.5 Alpha:\n"
                L"• [NIEUW] Verbetering van de integratie van de Vertraging-calculator.\n"
                L"• [NIEUW] CV29 Builder genereert nu direct de juiste byte.\n\n"
                L"Versie 0.7.0 Alpha:\n"
                L"• Eerste tabblad-gebaseerde interface.\n"
                L"• Vertraging-calculator toegevoegd.\n";
            MessageBoxW(hwnd, notes.c_str(), L"Release Notes", MB_OK | MB_ICONINFORMATION);
            break;
        }
        case ID_BTN_CALC_CV: {
            wchar_t buf[16]; GetWindowTextW(hAddr, buf, 16);
            int a = _wtoi(buf);
            if (a > 0) {
                SetWindowTextW(hCV17, std::to_wstring(calcCV17(a)).c_str());
                SetWindowTextW(hCV18, std::to_wstring(calcCV18(a)).c_str());
            }
            break;
        }
        case ID_BTN_CALC_ADDR: {
            wchar_t b17[16], b18[16];
            GetWindowTextW(hCV17b, b17, 16); GetWindowTextW(hCV18b, b18, 16);
            SetWindowTextW(hResult, std::to_wstring(calcAddr(_wtoi(b17), _wtoi(b18))).c_str());
            break;
        }
        case ID_BTN_GEN_CV29: {
            int cv29 = 0;
            for (int i = 0; i < 8; i++) if (SendMessage(hBuilderBits[i], BM_GETCHECK, 0, 0) == BST_CHECKED) cv29 += (1 << i);
            SetWindowTextW(hCV29Out, std::to_wstring(cv29).c_str());
            break;
        }
        case ID_BTN_PRESET_STD:
            for (int i = 0; i < 8; i++) SendMessage(hBuilderBits[i], BM_SETCHECK, (i == 1) ? BST_CHECKED : BST_UNCHECKED, 0);
            SendMessage(hwnd, WM_COMMAND, ID_BTN_GEN_CV29, 0);
            break;
        case ID_BTN_PRESET_LONG:
            for (int i = 0; i < 8; i++) SendMessage(hBuilderBits[i], BM_SETCHECK, (i == 1 || i == 5) ? BST_CHECKED : BST_UNCHECKED, 0);
            SendMessage(hwnd, WM_COMMAND, ID_BTN_GEN_CV29, 0);
            break;
        case ID_BTN_DEC_CV29: {
            wchar_t buf[16]; GetWindowTextW(hCV29Input, buf, 16);
            int v = _wtoi(buf);
            for (int i = 0; i < 8; i++) SetWindowTextW(hDecodeStatus[i], (v & (1 << i)) ? L"AAN" : L"UIT");
            break;
        }
        case ID_BTN_LOOKUP_DEC: {
            wchar_t b8[16], b7[16], b250[16];
            GetWindowTextW(hCV8In, b8, 16); GetWindowTextW(hCV7In, b7, 16); GetWindowTextW(hCV250In, b250, 16);
            SetWindowTextW(hDecoderResult, lookupManufacturer(_wtoi(b8), _wtoi(b7), _wtoi(b250)).c_str());
            break;
        }
        case ID_BTN_CALC_DELAY: {
            wchar_t buf[16]; GetWindowTextW(hStap40In, buf, 16);
            int stap40 = _wtoi(buf);
            if (stap40 <= 0 || stap40 > 126) {
                SendMessageW(hStatus, SB_SETTEXTW, 0, (LPARAM)L" Fout: Stap moet tussen 1 en 126 liggen.");
                break;
            }
            int factor = (stap40 <= 24) ? 1 : (stap40 <= 40) ? 2 : (stap40 <= 60) ? 3 : 4;
            int defTijd = SendMessage(hRadioS, BM_GETCHECK, 0, 0) ? 7000 : SendMessage(hRadioD, BM_GETCHECK, 0, 0) ? 6000 : 5000;
            int res = (int)(((double)defTijd * factor / stap40) + 0.5);
            std::wstring s = L"Vertraging: " + std::to_wstring(res) + L" ms\nFactor: " + std::to_wstring(factor);
            SetWindowTextW(hDelayResult, s.c_str());
            break;
        }
        }
        break;
    case WM_NOTIFY: {
        LPNMHDR nm = (LPNMHDR)lParam;
        if (nm->code == TCN_SELCHANGE) {
            int sel = TabCtrl_GetCurSel(hTab);
            const wchar_t* st[] = { L" Bereken CV17/18", L" CV29 Builder", L" CV29 Decoder", L" Decoder Info", L" Vertraging" };
            SendMessageW(hStatus, SB_SETTEXTW, 0, (LPARAM)st[sel]);
            ShowWindow(page1, sel == 0 ? SW_SHOW : SW_HIDE);
            ShowWindow(page2, sel == 1 ? SW_SHOW : SW_HIDE);
            ShowWindow(page3, sel == 2 ? SW_SHOW : SW_HIDE);
            ShowWindow(page4, sel == 3 ? SW_SHOW : SW_HIDE);
            ShowWindow(page5, sel == 4 ? SW_SHOW : SW_HIDE);
        }
        break;
    }
    case WM_DESTROY:
        if (hUIFont) DeleteObject(hUIFont);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// --- ENTRY MET FIX C28251 ---
int WINAPI wWinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrev, _In_ PWSTR szCmd, _In_ int nShow) {
    InitCommonControls();
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc; wc.hInstance = hInst;
    wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wc.lpszClassName = L"DCCApp";
    RegisterClass(&wc);

    WNDCLASS pc = { 0 };
    pc.lpfnWndProc = PageProc; pc.hInstance = hInst;
    pc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    pc.lpszClassName = L"PageContainer";
    RegisterClass(&pc);

    HMENU hMenu = CreateMenu();
    HMENU hFile = CreatePopupMenu(); AppendMenuW(hFile, MF_STRING, IDM_FILE_EXIT, L"Afsluiten");
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFile, L"Bestand");
    HMENU hHelp = CreatePopupMenu(); AppendMenuW(hHelp, MF_STRING, IDM_HELP_ABOUT, L"Over...");
    AppendMenuW(hHelp, MF_STRING, IDM_HELP_RELEASE_NOTES, L"Release Notes");
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hHelp, L"Help");

    HWND hwnd = CreateWindowW(L"DCCApp", L"DCCToolbox v0.8.0 alpha", WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 680, NULL, hMenu, hInst, NULL);

    hStatus = CreateStatusWindowW(WS_CHILD | WS_VISIBLE, L" Gereed.", hwnd, ID_STATUSBAR);
    hUIFont = CreateFontW(-14, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, L"Segoe UI");

    hTab = CreateWindowW(WC_TABCONTROL, L"", WS_CHILD | WS_VISIBLE, 10, 10, 565, 580, hwnd, NULL, hInst, NULL);
    SendMessage(hTab, WM_SETFONT, (WPARAM)hUIFont, TRUE);

    const wchar_t* tabs[] = { L" Adressen ", L" CV29 Build ", L" CV29 Decode ", L" Decoder Info ", L" Vertraging " };
    for (int i = 0; i < 5; i++) { TCITEM t = { TCIF_TEXT }; t.pszText = (LPWSTR)tabs[i]; TabCtrl_InsertItem(hTab, i, &t); }

    RECT rc; GetClientRect(hTab, &rc); TabCtrl_AdjustRect(hTab, FALSE, &rc);
    int w = rc.right - rc.left, h = rc.bottom - rc.top;
    page1 = CreateWindowW(L"PageContainer", NULL, WS_CHILD | WS_VISIBLE, rc.left, rc.top, w, h, hTab, NULL, hInst, NULL);
    page2 = CreateWindowW(L"PageContainer", NULL, WS_CHILD, rc.left, rc.top, w, h, hTab, NULL, hInst, NULL);
    page3 = CreateWindowW(L"PageContainer", NULL, WS_CHILD, rc.left, rc.top, w, h, hTab, NULL, hInst, NULL);
    page4 = CreateWindowW(L"PageContainer", NULL, WS_CHILD, rc.left, rc.top, w, h, hTab, NULL, hInst, NULL);
    page5 = CreateWindowW(L"PageContainer", NULL, WS_CHILD, rc.left, rc.top, w, h, hTab, NULL, hInst, NULL);

    CreatePage1(page1); CreatePage2(page2); CreatePage3(page3); CreatePage4(page4); CreatePage5(page5);

    auto SetFont = [](HWND p) { HWND c = GetWindow(p, GW_CHILD); while (c) { SendMessage(c, WM_SETFONT, (WPARAM)hUIFont, TRUE); c = GetWindow(c, GW_HWNDNEXT); } };
    SetFont(page1); SetFont(page2); SetFont(page3); SetFont(page4); SetFont(page5);

    ShowWindow(hwnd, nShow);
    MSG msg; while (GetMessage(&msg, NULL, 0, 0)) { TranslateMessage(&msg); DispatchMessage(&msg); }
    return 0;
}