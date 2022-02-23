/////////////////////////////////////////////////
//              120|-[ModBot]-V1.0             //
///////////////////////////////////////////////// 
enum {REALNICK, CONSTNICK, LETTERNICK, COMPNICK, COUNTRYNICK, UPOSNICK, FUNKYNICK};
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
typedef char * (*rnref)(char *strbuf);
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
typedef struct RNICK 
{
	char name[10];
	int type;
	rnref rnfunc;

} RNICK;
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifndef NO_REALNICK
char *rndnickreal(char *strbuf);
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
char *rndnickconst(char *strbuf);
char *rndnickletter(char *strbuf);
char *rndnickcomp(char *strbuf);
char *rndnickcountry(char *strbuf);
char *upnickos(char *strbuf);
char *prefixnick(char *strbuf);
char *rndnick(char *strbuf, int type=LETTERNICK, BOOL prefix=FALSE, char *name=NULL);
char *Dnick(char *strbuf);
