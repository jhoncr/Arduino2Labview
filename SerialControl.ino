double a;
boolean flag;
String Sinput="";

void setup(){
  Serial.begin(38400);  
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
//  for(int i=2;i<13;i++){ // lembrar de mudar para o MEGA
//    pinMode(i,OUTPUT);  
//  } // configure the PWM outputs

//  for(int i=22;i<=52;i=i+2){
//    pinMode(i,INPUT);  
//  }// configure the digital inputs
//
//  for(int i=23;i<=53;i=i+2){
//    pinMode(i,OUTPUT);  
//  } // configure the digital outputs  

}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
double str2int(String str){
 int L,k;
 double R;  
 L=str.length()-2;
 R=0;
 for(k=L;k>=0;k--){  
   R+=pow(10,k)*(str.charAt(L-k)-48);   
 }   
 return R; 
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
void Command(String str){
  int dur,k,indm,indf,inds,port,val;
  static int Fport;
  String Saux,Sout;
  
  Sout="";
  k=str.indexOf('/');
  inds=k+1;
  Saux=str.substring(0,k);
  //Serial.println(str);
  k=0;
  //---------------------Analog Outputs--------------------
  if(Saux=="PWM"){
     indf=str.indexOf('/',inds)+1;
     while(indf>0){
     indm=str.indexOf('>',inds)+1;
     port=str2int(str.substring(inds,indm));
     val=str2int(str.substring(indm,indf));
     inds=indf;
     indf=str.indexOf('/',inds)+1;
     analogWrite(port,val);     
     }
  }
 //---------------------Analog Inputs----------------------- 
  else if(Saux=="AI"){
     indf=str.indexOf('/',inds)+1;
     while(indf>0){
     port=str2int(str.substring(inds,indf));        
     inds=indf;
     indf=str.indexOf('/',inds)+1;
     Sout+=analogRead(port);
     delay(10);
     Sout+=';';
     } 
     Serial.println(Sout);
  }
  //----------------------Digital Inputs---------------------
    else if(Saux=="DI"){
     indf=str.indexOf('/',inds)+1;
     while(indf>0){
     port=str2int(str.substring(inds,indf));        
     inds=indf;
     indf=str.indexOf('/',inds)+1;
     Sout+=digitalRead(port);
     delay(10);
     Sout+=';';
     } 
     Serial.println(Sout);
  }
//-----------------------Digital Outputs---------------------
    else if(Saux=="DO"){
     indf=str.indexOf('/',inds)+1;
     while(indf>0){
     indm=str.indexOf('>',inds)+1;
     port=str2int(str.substring(inds,indm));
     val=str2int(str.substring(indm,indf));
     inds=indf;
     indf=str.indexOf('/',inds)+1;
     digitalWrite(port,val);
     }
  }
//----------------------Arduino Identification---------------
    else if(str=="*IDN?\n"){
     Serial.println("Arduino MEGA-1280 programmed by Jhonatam C. Rodrigues");
     Serial.println("****Commands****");
     Serial.println("PWM/port1>val1/port2>val2/.../\n");
     Serial.println("DO/port1>val1/port2>val2/.../\n");
     Serial.println("AI/port1/port2/port3/.../\n");
     Serial.println("DI/port1,port2,port3/.../\n"); 
     
    }
    

  }   
  
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void loop(){
char Ci;
  if(Serial.available()){
    Ci=Serial.read();    
    Sinput+=Ci;    
    if(Ci=='\n'){
    Command(Sinput);
    Sinput="";    
    }
  }
}
