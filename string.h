typedef struct{
 char *ch;
 int length;
}HString;

bool StrAssign(HString &T,char *chars);
bool StrCopy(HString &T,HString S);
bool StrEmpty(HString S);
int StrCompare(HString S,HString T);
int StrLength(HString S);
bool ClearString(HString &S);
bool Concat(HString &T,HString S1,HString S2);
bool SubString(HString &sub,HString S,int pos,int len);
int Index(HString S,HString T,int pos);
bool Replace(HString &S,HString T,HString V);
bool StrInsert(HString &S,int pos,HString T);
bool StrDelete(HString &S,int pos,int len);
bool DestroyString(HString &S);
