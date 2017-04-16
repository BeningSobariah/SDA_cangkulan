/* File :  list1.c   					*/
/* Desk :  body list  berkait dgn representasi fisik    */
/*         pointer; 					*/
/* 	   Representasi address dgn pointer 		*/
/*	   infotype adalah integer			*/
/* Oleh :  ANI RAHMANI / 23501007 	  		*/
/* Tgl  :  25/10/01					*/	 

/* body dari List1.h   */

// MODIFIKASI OLEH 

/*Program		: ADT_LinkList Integer
Deskripsi		: 
Nama			: Rhamadhaniaty Bening Sobariah
NIM				: 161524028
Tanggal/versi	: 8 April 2017
Compiler		: Dev C++ 5.11
Catatan			: 
=========================================*/

#ifndef list1_C
#define list1_C 

#include "boolean.h"
#include "list1.h"
#include <stdlib.h>
#include <stdio.h>


boolean ListEmpty(List  L){ 
   	return(First(L)==Nil);	
}

void CreateList(List *L){  
   First(*L)=Nil;
}

address Alokasi(infotype  X){
   address P;
   P=(address)malloc(sizeof(ElmtList));										//pesan memory sebesar elemenlist
   if(P!=Nil) { /* Berhasil  */												//jika alokasi berhasil, maka info(p) akan diberi value (ex=5)
         Info(P)=X;															//p = address yang menunjuk ke node baru
	 Next(P)=Nil;
   }
   return P;	   
}

void Dealokasi(address *P){
    Next(*P)=Nil; 	
    free(*P);	//adress p dibebaskan dari memori
}

address Search1(List L, infotype  X)
{ 
   address  P=First(L); 
   boolean found=false;
   
   while((P!=Nil)&&(!found))  { 
	   if(Info(P)==X) {
		{  found=true;
		   }
	   }   
           else {
	         P=Next(P);   
	   }		   
   } /*P=Nil or  found  */
   return P;		//returnnya berupa address variabel yang dicari (jika ketemu)
}	   				//jika tidak ketemu, maka returnnya NIL. tidak ketemu bisa karena lisnya kosong atau elemen yang dicari memang tidak ada di dalam list

address Search2(List L, infotype  X)
{ 
   address  P; 
   if(First(L)!=Nil){			//cek dulu kosong atau ngga
   	return Nil;
   } else {
   	P=First(L);
   	while((Next(P)!=Nil)&&(Info(P)!=X)) {
	      P=Next(P);   
   	} /* Next(P)==Nil or Info(P)==X */
   	if(Info(P)==X)  {
   	    return P;	
   	}else {
   	    return Nil;
	  }
   }
   return P;
}	   

boolean FSearch(List L, address P){ 
  address PTemp=First(L);
  boolean found=false;
  
  while((PTemp!=Nil)&&(!found)){
     if(PTemp==P) {
	 found=true;
     }	     
     else
     { 
	 PTemp=Next(PTemp);     
     }
      
  } /* PTemp==Nil or found / ketemu */
  return found;
}

address SearchPrec(List L, infotype X){ 
  address Prec;	
  address P;
  
  if(Next(P)==Nil)  { /* List hanya berisi 1 elemen */
    Prec=Nil;
  } else { 
	  P=First(L);
	  while((Next(P)!=Nil) &&(Info(P)!=X)) {
	      Prec=P;
              P=Next(P);		 	      
  	   }  /* Next(P)==Nil or Info(P)==X */
  
  	   if(Info(P)==X){ /* Ketemu Info (P)== X */
  	        return Prec;
  	   } else {
  	        return Nil;  /* tidak ada X di List */
  	   }
     } /* else */
}


void InsVFirst(List *L, infotype X){  
   address P=Alokasi(X);											//p akan berisi address jika alokasi berhasil
   if(P!=Nil) { /* Alokasi Berhasil */
      InsertFirst(&(*L),P);
    }
}

void InsVLast(List *L, infotype X){ 
     address P=Alokasi(X);
     if(P!=Nil){  
	 	InsertLast(&(*L),P);
     }
}

void DelVFirst(List *L, infotype *X){ 
  address  P;
  
  DelFirst(&(*L),&P); /* Hapus elemem pertama, blm didealokasi */
  *X=Info(P); 		/* info dari First disimpan di X       */
  Dealokasi(&P);	  
}

void DelVLast(List *L, infotype *X){  
   address P;
   DelLast(&(*L),&P); 
        /* Hapus Elemen Terakhir, addressnya disimpan di P, */
        /* Belum diDealokasi, masih bisa dibaca isinya      */
   *X=Info(P);	/* Info dari address P, ditampung  */ 
   Dealokasi(&P);
}

void InsertFirst(List *L, address P){
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter(List *L, address P, address Prec){ 
	Next(P)=Next(Prec);															//prec=prev=sebelumnya
	Next(Prec)=P;
}

void InsertLast(List  *L, address P){ 
      address Last;
      if(ListEmpty(*L)) { /* Jika kosong,Insert elemen pertama */
	   InsertFirst(&(*L),P);     
      }
      else { /* tdk kosong */
	    Last=First(*L);  
            while(Next(Last)!=Nil)  { /* menuju ke last */
	          Last=Next(Last);
	    } /* Next(Last)==Nil */
	  
	  Next(Last)=P;	  
      }
}

void DelFirst (List *L, address *P){         
      *P=First(*L);
      First(*L)=Next(First(*L));
      Next(*P)=Nil;
 }

void DelP(List *L, infotype X){
/*	address prev = First(*L);
	address  P=Next(prev);
	
    while((Next(P)!=Nil) && (Info(P)!=X)){			//Next(P)!=Nil ===== selama belum last
          prev = P;
		  P=Next(P);
    } /*Next(P)=Nil or Info(P)= X */
    
 /*   if(Info(P)==X) {
       Next(prev)=Next(P);
	   Dealokasi(&P);
    }
*/

/*
address P=First(*L),prev;
	infotype a;
	int x=0;
	while(Next(P)!=Nil){
		if(X==Info(P)){
			DelVFirst(&(*L),&a);
			P=First(*L);
		}else{
			if(X!=Info(P)){
				prev=P;
				P=Next(P);
				x++;
			}else{
				Next(prev)=Next(P);
				Next(P)=Nil;
				Dealokasi(&P);
				P=prev;
				x++;
			}
		}
		
	}
	P=Next(prev);
	if(X==Info(P)){
		Next(prev)=Nil;
		Dealokasi(&P);
	}    
*/


address  P=First(*L);
    address Prev=Nil;

    while((Next(P)!=Nil) && (Info(P)!=X)) {
          Prev = P;
	  P=Next(P);
    } /*Next(P)=Nil or Info(P)= X */
    
    if(Prev == Nil) {
    	P=First(*L);
    	First(*L)=Next(First(*L));
    } else {
    	Next(Prev) = Next(P);
	}
	Dealokasi(&P);    
}

void DelLast(List *L, address *P){     	
  address Last,PrecLast;
  Last=First(*L);
  /* dari catatan di kelas */	
  if(Next(Last)==Nil)  { /* hanya 1 elemen */
	  DelFirst(&(*L),&(Last));
  }	  
  else { /* Lebih dr 1 elemen */
	  PrecLast=Nil;
	  while(Next(Last)!=Nil){/* Maju sampai elemen terakhir */
		  PrecLast=Last;     
		  Last=Next(Last);
	  } /* Next(Last)=Nil */
	  *P=Last;
	  Next(PrecLast)=Nil;
       }
}

void DelAfter(List *L, address *Pdel, address Prec){
	*Pdel=Next(Prec);
	Next(Prec)=Next(*Pdel);
}

void PrintInfo(List L){ 
  int i;	
  address P=First(L);													//p untuk traversal=yg jalan2=indeks
  if( P==Nil) { 
  	  printf("List Kosong !\n");
  } else { /* List tidak kosong */
	    printf("[ ");
	    do { 															//kenapa pake do-while??   karena list pasti tidak kosong, berarti minimal ada satu elemen
	 	  printf("%d ",Info(P));
		  P=Next(P);
		  i++;
	    } while(P!=Nil); 
	    printf("]");
	 }
  printf("\n");
}

int NbElmt(List L){							//number of element
  address P;
  int NbEl=0;
  if(ListEmpty(L)){							//kalau list kosong berarti jumlah elemennya nol
 	return 0;
  } else { /* Tidak kosong */
	      P=First(L);
       	      do {
		    NbEl++;  						//count=count+1
		    P=Next(P);  					//P bergerak ke node selanjutnya
	      }while(P!=Nil);					//saat p=nil, maka keluar loop
  	}
       return NbEl;		      
}

infotype Max(List L){  
   address P;	
   infotype MMax;
   if(!ListEmpty(L))
   {      P=First(L);
	  MMax=Info(P);
	  while(Next(P)!=Nil) { 
	 	P=Next(P);
		if(Info(P)>MMax) {
		   MMax=Info(P);	
		}	
	  } /* Next(P)==Nil */
   }
  return MMax;	  
}

address AdrMax(List L){  
   address PMax,P;
   infotype Max;
   if(!ListEmpty(L)){
	   P=First(L);
	   Max=Info(P);
	   while(Next(P) != Nil) { 
		   P=Next(P);
		   if(Info(P)>Max) {
			   Max = Info(P);
			   PMax=P;
		   }
	   } /* Next(P)==Nil */
   }
   return PMax;
}


infotype Min(List L){
   address P;	
   infotype MMin;
   if(!ListEmpty(L))
   {      P=First(L);
	  MMin=Info(P);
	  while(Next(P)!=Nil) { 
	 	   P=Next(P);
		   if(Info(P)<MMin) {
		        MMin=Info(P);	
		   }	
	  } /* Next(P)==Nil */
    } 
    return MMin;	  
}
	

address AdrMin(List L){ 
   address PMin,P;
   infotype Min;
   if(!ListEmpty(L)){
	   P=First(L);
	   Min=Info(P);
	   while(Next(P) != Nil) { 
	      P=Next(P);
	      if(Info(P)<Min) {
			   Min = Info(P);
			   PMin=P;
		   }
  	   }
   }
   return PMin;
}

float Average(List L){  
	address P;
	infotype NbEl,Count;
	float avg;
	
	if(!ListEmpty(L)) { /* Tidak kosong */
		P=First(L);
		Count=Info(P);
		NbEl=1;
		while(Next(P)!=Nil) 
		{  P=Next(P);
		   Count=Count+Info(P);  		    
		   NbEl++;
		} /*Next(P) == Nil */
		avg= (float)Count/(float)NbEl;
	}
       return avg;		
}

void DelAll(List *L){													//2 cara== del first samapi p=nil. atau jalan traversal sampai ketemu nil, lalu hapus satu2 dari belakang sampai elemen first
   infotype X;
   while(!ListEmpty(*L)) {
	  DelVFirst(&(*L),&X);
   } /* kosong */
}

void InversList(List *L){	
	address prev,next,P;
	prev=Nil;
	P=First(*L);
	while(P!=Nil){
		next=Next(P);
		Next(P)=prev;
		prev=P;
		P=next;
	}
	First(*L)=prev;
}


List FInversList(List L){
	InversList(&L);
	return L;
}


void CopyList(List L1, List *L2){
	First(*L2)=First(L1);
}

List FCopyList(List L){
	List newList;
	address P,P1,temp;
	P=First(L);
	temp=Alokasi(Info(P));
	if(temp!=Nil){
		First(newList)=temp;
	}
	while(temp!=Nil&&Next(P)!=Nil){
		P1=temp;
		P=Next(P);
		temp=Alokasi(Info(P));
		if(temp!=Nil){
			Next(P1)=temp;
			P1=Next(P1);
		}
	}
	return newList;
}


void CpAlokList(List Lin, List  *Lout){
	*Lout=FCopyList(Lin);
	address P,P1;
	P=First(Lin);
	P1=First(*Lout);
	while(P!=Nil){
		if(Info(P)!=Info(P1)){
			DelAll(Lout);
		}else {
			P=Next(P);
			P1=Next(P1);
		}
	}
}

void konkat(List L1, List L2, List *L3){
	address P = First(L1);
	List Temp;
	
	if(First(L1) != Nil || First(L2) != Nil){
		CreateList(&(*L3));
	}
	
	if(P == Nil){
		printf("L1 merupakan list kosong!\n");
	}else{
		while(P != Nil){
			InsVLast(&(*L3),Info(P));
			P = Next(P);
		}
	}
	
	P = First(L2);
	
	if(P == Nil){
		printf("L2 merupakan list kosong!\n");
	}else{
		while(P != Nil){
			InsVLast(&(*L3),Info(P));
			P = Next(P);
		}
	}
}

void konkat1(List *L1, List *L2, List *L3){
	address P1 = First(*L1);
	if(P1 == Nil){
		printf("List kosong!\n");
	}else{
		while(Next(P1) != Nil){
			P1 = Next(P1);
		}
		Next(P1) = First(*L2);
	}
	*L3 = *L1;
	CreateList(&(*L1));
	CreateList(&(*L2));
}

void PecahList(List *L1, List *L2, List L){
	int i;
	address P = First(L);
	CreateList(&(*L1));
	CreateList(&(*L2));
	for(i = 0 ; i < NbElmt(L)/2;i++){
		InsVLast(&(*L1),Info(P));
		P = Next(P);
	}
	for(i = NbElmt(L)/2 ; i < NbElmt(L);i++){
		InsVLast(&(*L2),Info(P));
		P = Next(P);
	}
}

#endif
