#include"string.h"
#include<iostream>
using namespace std;

bool StrAssign(HString &T,char *chars){
	if(T.ch) free(T.ch);
	char *c;
	int i;
	for(i=0,c=chars;*c;++i,++c);
	if(!i) {
		T.ch=NULL; T.length=0;
	}else{
		T.ch=(char *)malloc(i*sizeof(char));
		if(!T.ch) return false;
		for(int k=0;k<i;k++) T.ch[k]=chars[k];
		T.length=i;
	}
	return true;
}

bool StrCopy(HString &T,HString S){
	if(!S.ch) return false; //s为空
	if(T.ch) free(T.ch);//防止丢失地址造成内存泄露
	T.ch=(char *)malloc(sizeof(char)*S.length);
	if(!T.ch) return false;
	for(int k=0;k<S.length;k++){
		T.ch[k]=S.ch[k];
	}
	T.length=S.length;
	return true;
}

bool StrEmpty(HString S){
   if(!S.ch) return false;
   if(S.length!=0) return false;
   else return true;
}

int StrCompare(HString S,HString T){
    int i;
	for(i=0;i<S.length&&i<T.length;i++)
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
	return S.length-T.length;
}

int StrLength(HString S){
	return S.length;
}

bool ClearString(HString &S){
	if(!S.ch) return false;
	S.length=0;
	return true;
}

bool Concat(HString &T,HString S1,HString S2){
	if(T.ch) free(T.ch);
	T.ch=(char *)malloc(sizeof(char)*(S1.length+S2.length));
	if(!T.ch) return false;
	int k;
	for(k=0;k<S1.length;k++) T.ch[k]=S1.ch[k];
	T.length=S1.length+S2.length;
	for(int i=0;k<T.length;++i,++k) T.ch[k]=S2.ch[i];
	return true;
}

bool SubString(HString &sub,HString S,int pos,int len){
	if(pos<1||pos>S.length||len<0) return false;
	if(sub.ch) free(sub.ch);
	if(!len){
		sub.ch=NULL; sub.length=0;
	}else{
		int i;
		sub.ch=(char *)malloc(len*sizeof(char));
		if(!sub.ch) return false;
		for(i=0;i<len&&i<S.length-pos+1;i++){
			sub.ch[i]=S.ch[pos-1+i];
		}
		sub.length=i;
	}
	return true;
}

int Index(HString S,HString T,int pos){
	if(pos>S.length||pos<1) return 0;
	int i=pos-1,j=0;
	while(i<S.length&&j<T.length){
		if(S.ch[i]==T.ch[j]){
		   i++;
		   j++;
		}else{
		   i=i-j+1;
		   j=0;
		}
	}
	if(j>=T.length) return i-T.length+1;
	else return 0;
}

bool Replace(HString &S,HString T,HString V){
	if(T.length==0||V.length==0) return false;
	if(!S.ch||!T.ch||!V.ch) return false;
	 int i,j,old_i,position;
	if(T.length==V.length){  //子串长度相等
		i=0;
		while(1){
			j=0;
		   while(i<S.length&&j<T.length){
				if(S.ch[i]==T.ch[j]){
				   i++;
				   j++;
				}else{
				   i=i-j+1;
				   j=0;
				}
			}
		   if(j>=T.length){  //找到相等的
			   old_i=position=i-T.length;
			   for(int k=0;k<V.length;k++) S.ch[position++]=V.ch[k];
		   }
		   if(old_i-T.length+1>=0) {
			   i=old_i-T.length+1; 
		   }else if(i>=S.length) return true;
		}
	   
	}else if(T.length<V.length){
	   int old_len;
		i=0;
		while(1){
			j=0;
		   while(i<S.length&&j<T.length){
				if(S.ch[i]==T.ch[j]){
				   i++;
				   j++;
				}else{
				   i=i-j+1;
				   j=0;
				}
			}
		   old_len=S.length;
		   if(j>=T.length){  //找到相等的
			   old_i=position=i-T.length;
			   S.ch=(char *)realloc(S.ch,sizeof(char)*(S.length+V.length-T.length));
			   for(int k=S.length-1;k>=i;k--){ S.ch[V.length-T.length+k]=S.ch[k];}
				for(int k=0;k<V.length;k++) S.ch[position++]=V.ch[k];
				S.length+=(V.length-T.length);
		   }
		   if(old_i-T.length+1>=0) {
			   i=old_i-T.length+1; 
		   }else if(i>=old_len) return true;
		}
	}else {
		int old_len;
	   i=0;
	   while(1){
		j=0;
		   while(i<S.length&&j<T.length){
				if(S.ch[i]==T.ch[j]){
				   i++;
				   j++;
				}else{
				   i=i-j+1;
				   j=0;
				}
			}
		   old_len=S.length;
		   if(j>=T.length){  //找到相等的
			   old_i=position=i-T.length;
			   int k1;
			   for(k1=0;k1<V.length;k1++) S.ch[position++]=V.ch[k1];
			   for(int k=0;k<S.length-i;k++) S.ch[k1+k]=S.ch[i+k];
			    S.length-=(T.length-V.length);
		   }
		   if(old_i-T.length+1>=0){
			   i=old_i-T.length+1;
		   }else if(i>=old_len) return true;  
	   }
	}
	return true;
}

bool StrInsert(HString &S,int pos,HString T){
	if(pos<1||pos>S.length) return false;
	if(T.length){
		S.ch=(char *)realloc(S.ch,sizeof(char)*(S.length+T.length));
		if(!S.ch) return false;
		for(int i=S.length-1;i>=pos-1;--i){
			S.ch[i+T.length]=S.ch[i];
		}
		for(int i=0;i<T.length;i++) S.ch[pos-1+i]=T.ch[i];
		S.length+=T.length;
	}
	return true;
}

bool StrDelete(HString &S,int pos,int len){
	if(pos<1||pos>S.length||len<0) return false;
    if(len==0) return true;
	if(pos-1+len>=S.length) S.length=pos-1;
	else {
		for(int i=pos+len-1;i<S.length;i++)  S.ch[i-len]=S.ch[i];
		S.length-=len;
	}
	return true;
}

bool DestroyString(HString &S){
	if(!S.ch) return false;
	free(S.ch);
	S.ch=NULL;
	S.length=0;
	return true;
}