#include <iostream>

using namespace std;

const int MAX_specification = 20 ;
const int MAX_queue = 5 ;

string nmaes[MAX_specification+1][MAX_queue+1];
int status[MAX_specification+1][MAX_queue+1];
int Lingth_queu[MAX_specification+1];



void  shift_right( int spe  ,string names[] , int status[] ){

   int len = Lingth_queu[spe] ;
   for( int i= len ; i >= 0 ; i--){
    names[ i+1]=names[ i];
    status[i+1]= status[ i];
   }
   Lingth_queu[spe]++;

     return ;
}
 void  shift_left( int check , string nmaes[] ,  int status[]  ){
   int len= Lingth_queu[check ];
   for( int i=0 ; i < len ; i++ ){
   nmaes[i]=nmaes[i+1];
   status[i]=status[i+1];
   }
  return ;
 }
 void Get_next_patient(){
 cout<<" Enter specialization  : \n" ;
  int check ;
  cin >>check ;
   int len = Lingth_queu[check] ;
  if( len  <= 0 )
    cout<<"NO patient at the moment rest , Dr \n" ;
  else {
        cout<< nmaes[check][0]<<" please go with Dr \n \n \n";
    shift_left( check , nmaes[check] , status[check]  );


  }

}
void   print_all_patients(){

 for( int i=1 ; i<=20 ; i++ ){
        int len = Lingth_queu[i] ;
           if( len > 0 )
            cout<<"There are "<<len <<" patients in specification "<<i<<"\n";
   for(int j= 0 ; j <len ; j++ ){
   cout<<" "<<nmaes[i ][j]<<"   ";
   if( status[ i ][ j] == 1 )
    cout<<"urgent\n";
   else
    cout<<"regular\n";
 }

 }
 return ;
}




bool  Add_new_patient(){

    int speci ;
    string name ;
    int st ;

    cout<<"Enter specialization , name , status \n " ;
    cin >> speci >> name >>  st ;

    int pos = Lingth_queu[ speci ];

    if( pos >=  MAX_queue ){
            cout<< " Sorry we can't add more patients for this specialization \n ";
            return false ;
    }

    if(  st == 0 ){
         nmaes[speci][pos] = name ;
         status[speci][pos]=st;
          Lingth_queu[speci]++;
    }

    else {
   shift_right( speci  ,nmaes[speci] , status[speci]  );
         nmaes[speci][0] = name ;
         status[speci][0]=st;
    }


    return true  ;
}
int  menu(){

   cout<<" 1 ) Add new patient.\n";
     cout<<" 2 ) print all patients.\n";
       cout<<" 3 ) Get next patient.\n";
         cout<<" 4 ) Exit. \n";
         int numper ;
         cin >>numper ;
         cout<<"_____________________________________\n";
         return  numper ;
}

  void System_hospital(){

     while( true ){
   int chois = menu();
  if( chois == 1)
     Add_new_patient();

   else if( chois == 2 )
    print_all_patients();
   else if( chois == 3 )
     Get_next_patient();
 /*  else
    Exit();
*/
      }
  }

int main()
{

System_hospital();



    return 0;
}
