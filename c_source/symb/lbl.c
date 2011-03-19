/*
 Copyright (C) 2000, Alexander Pukhov, e-mail: pukhov@theory.npi.msu.su 
*/

#include "chep_crt.h"
#include "syst2.h"
#include "lbl.h"
#include "s_files.h"

void  cheplabel(void)
{
 int  key; 
 char fname[STRSIZ];
 FILE *f;

 while(1)
 { 
/*   { int X=20,Y=1;
     scrcolor(FGmain,BGmain);
     goto_xy(X,Y);  print("Skobeltsyn Institute of Nuclear Physics,");
     goto_xy(X+8,Y+1);  print("Moscow State University.");
   }
*/
   { int Y=2;
     scrcolor(Red,LightGray);
     goto_xy(7,Y); print("CalcHEP - a package for Calculation in High Energy Physics");
     scrcolor(FGmain,BGmain);
     goto_xy(15,Y+1);  print("Version 2.5.6: Last correction May 27,2010");
   }

   { int Y=6;

     scrcolor(FGmain,BGmain); 
     goto_xy(4,Y);print("Main author:");
     scrcolor(Blue,LightGray);
     print(" Alexander Pukhov(Skobeltsyn Institute of Nuclear Physics,Moscow)");
   }

   { int Y=7;
     scrcolor(FGmain,BGmain); 
     goto_xy(4,Y);print("Batch mode :");
     scrcolor(Blue,LightGray);
     print(" Neil Chistensen (Michigan State University)");
     scrcolor(FGmain,BGmain);
     goto_xy(4,Y+1);print("PYTHIA interface and testing:");
     scrcolor(Blue,LightGray);  print("Alexander Belyaev(University of Southampton)");
   }
   
   { int Y=10;
     scrcolor(FGmain,BGmain);
     goto_xy(4,Y);print("For contacts:");
     scrcolor(Blue,LightGray);   
     goto_xy(28,Y);print("email: <pukhov@lapp.in2p3.fr>");
     goto_xy(28,Y+1);print("http://theory.sinp.msu.ru/~pukhov/calchep.html");
  
   }
   

   { 
     int Y=14;
     scrcolor(FGmain,BGmain);
     goto_xy(4,Y);print("The BSMs for CalcHEP were developed in collaboration with:");
     scrcolor(Blue,LightGray);
     goto_xy(10,Y+1); scrcolor(Blue,LightGray); 
     print("G.Belanger,A.Belyaev,F.Boudjema,A.Semenov");
   }

   { int Y=17;
     scrcolor(FGmain,BGmain);
     goto_xy(4,Y);print("The package contains codes written by:");
     scrcolor(Blue,LightGray);
     goto_xy(10,Y+1); scrcolor(Blue,LightGray); 
     print("M.Donckt,V.Edneral,V.Ilyin,D.Kovalenko,A.Kryukov,G.Lepage,A.Semenov");
   }
   

   { int X1=19, X2=61, Y1=21, Y2=Y1+2;
     scrcolor(FGmain,BGmain);
     goto_xy(X1+2,Y1-1); print("Press F9 or click the box below to get");

     scrcolor(Blue,LightGray);  
     chepbox(X1,Y1,X2,Y2);

     goto_xy(X1+3,Y1+1); print("References and Contributions ");
/*     goto_xy(X1+3,Y1+2); print("   and  relative information.      "); */
    
     scrcolor(FGmain,BGmain);
     goto_xy(3,Y2+1); print("This information is available during the session by means of the F9 key"); 
     clearTypeAhead();
     key= inkey();
     if(key==KB_F9 || ( key==KB_MOUSE  
                   && mouse_info.row>=Y1 && mouse_info.row<=Y2 
                   && mouse_info.col >=X1 &&  mouse_info.col<=X2 ) )
     { 
       sprintf(fname,"%s%cCITE",pathtocomphep,f_slash);
       f=fopen(fname,"r");
       showtext (1, 1, 80,1,"",f);
       fclose(f);
       break;
     }
     if(key !=KB_MOUSE) break;
   }
 }
 clr_scr(FGmain,BGmain);
}
