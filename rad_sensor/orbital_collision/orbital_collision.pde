float theta=0.0;
float x=0;
float x2=150;
float k=0;

float X;
float Y;
float X2;
float Y2;

float[] rand =new float[100];




void setup(){
  size(800,400);
  smooth();
 
    for (int j=1;j<100;j++) {
  rand[j]=random(-1,1);
}
  
}

void draw(){
  background(255);
    //get results of sin function so oscillates between 0 and width
  float y = (sin(theta)+1)*0.8*height/2+(40);
  float y2= (sin(theta)+1)*0.4*height/2+(100);
  

  
  //increment theta with each cycle
  theta += 0.05;
  
  
  //draw ellipse at value defined by sin
  if(millis()<=7800){
  fill(0);
  stroke(0);
  ellipse(x,y,8,8);
  ellipse(x2,y2,8,8);
  }
    
 
  x+=10.37;
  if(x>=800){
    x=0;
  }
  
      if(x2>=800){
    x2=0;
  }
  
    x2+=6.37;


  
 if (millis()>7800){
   for(int i=1; i<100;i++){
    fill(0);
  stroke(0);
   X =x+(i)*(0.0001*(millis()-7800)*rand[i]);
   Y =y+(i)*(0.0001*(millis()-7800)*rand[i]);
   X2=x2+(i)*(0.0001*(millis()-7800)*rand[i]);
   Y2=y2+(i)*(0.0001*(millis()-7800)*rand[i]);
  ellipse(X,Y,2,2);
  ellipse(X2,Y2,2,2);


  }
  

  
  
  if(Y>=800){
    Y=0; 
  }
  
  if(Y2>=800){
    Y2=0;
  }
  
  if(Y<0){
    Y=800;
  }
  
  if(Y2<0){
    Y2=800;
  }
  

 }

}
