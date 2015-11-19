  #include <Servo.h>
  #include<Wire.h>
  #include<LiquidCrystal_I2C.h>
  
  LiquidCrystal_I2C lcd(0x27,20,4);
  Servo vodka, rum, oj, crown, coke, liquer;
  int vod=3;
  int rm=5;
  int juc=6;
  int crow=9;
  int cok=10;
  int liq=11;
  int on=70;
  int off=162;//169 for rum/black motor
  int shot=1350;
  int vodCounter;
  int rumCounter;
  int crownCounter;
  int liqCounter;
  int jucCounter;
  int cokeCounter;
  int screwDriver=8;
  int cokeRum=2;
  int crownCoke=4;
  int liqJuice=7;
  int mode=0;
  int modeButton=12;
 
  
  boolean lastButtonScrew=LOW;
  boolean currentButtonScrew=LOW;
  boolean lastButtonCoken=LOW;
  boolean currentButtonCoken=LOW;
  boolean lastButtonCrown=LOW;
  boolean currentButtonCrown=LOW;
  boolean lastButtonLiq=LOW;
  boolean currentButtonLiq=LOW;
  boolean lastButtonMode=LOW;
  boolean currentButtonMode=LOW;
  
  
  void setup()
  {
    
    // initialize the lcd and write
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,3);
    lcd.print("Waseem's DrinkDroid");
    lcd.setCursor(0,0);
    lcd.print("Select a Drink");
    // attach servos to certain pins
    vodka.attach(vod); 
    rum.attach(rm);
    oj.attach(juc); 
    crown.attach(crow);  
    coke.attach(cok); 
    liquer.attach(liq);
   // set all servos to off position
    vodka.write(off);
    rum.write(169);
    oj.write(off);
    crown.write(off); 
    coke.write(off);
    liquer.write(off);
    vodCounter=1350;
    rumCounter=1350;
    crownCounter=1350;
    liqCounter=1350;
    jucCounter=1000;
    cokeCounter=1000;
    pinMode(screwDriver,INPUT);
    pinMode(cokeRum,INPUT);
    pinMode(crownCoke,INPUT);
    pinMode(liqJuice,INPUT);
    pinMode(modeButton,INPUT);
    delay(500);
    vodka.detach(); 
    rum.detach();
    oj.detach(); 
    crown.detach();  
    coke.detach(); 
    liquer.detach();
  }
  
  void loop() 
  {//Drinks
      currentButtonScrew = debounce(lastButtonScrew, screwDriver);
      if (lastButtonScrew == LOW && currentButtonScrew == HIGH)
      {
        if(mode==0)
        {
          vodka.attach(vod); 
          oj.attach(juc); 
          pourDrink(vodka,oj,"Screwdriver coming",off, vodCounter, jucCounter);
          vodCounter=vodCounter+100;
          jucCounter=jucCounter+100;
          vodka.detach();
          oj.detach();
        }
        else if(mode==1)
        {
          vodka.attach(vod); 
          pourShot(vodka,"Shot of vodka coming",off, vodCounter);
          vodCounter=vodCounter+50;
          vodka.detach();
        }
        else if(mode==2)
        {
          oj.attach(juc); 
          pourShot(oj,"Shot of juice coming",off, jucCounter);
          jucCounter=jucCounter+20;
          oj.detach();
        }
      }
      lastButtonScrew = currentButtonScrew;  
      
      currentButtonCoken = debounce(lastButtonCoken, cokeRum);
      if (lastButtonCoken == LOW && currentButtonCoken == HIGH)
      {
        if(mode==0)
        {
          rum.attach(rm); 
          coke.attach(cok); 
          pourDrink(rum,coke,"Rum&coke on the way", 169, rumCounter, cokeCounter);
          rumCounter=rumCounter+100;
          cokeCounter=cokeCounter+100;
          rum.detach();
          coke.detach();
        }
        else if(mode==1)
        {
          rum.attach(rm);
          pourShot(rum,"Shot of rum coming",169, rumCounter);
          rumCounter=rumCounter+50;
          rum.detach();
        }
        else if(mode==2)
        { 
          coke.attach(cok); 
          pourShot(coke,"Shot of coke coming",off,cokeCounter);
          cokeCounter=cokeCounter+20;
          coke.detach();
        }
      }
      lastButtonCoken = currentButtonCoken;  
  
      currentButtonCrown = debounce(lastButtonCrown, crownCoke);
      if (lastButtonCrown == LOW && currentButtonCrown == HIGH)
      {
        if(mode==0)
        { 
          crown.attach(crow);  
          coke.attach(cok); 
          pourDrink(crown,coke,"Crown&coke, coming",off, crownCounter, cokeCounter);
          crownCounter=crownCounter+100;
          cokeCounter=cokeCounter+100;
          crown.detach();
          coke.detach();
        }
        else if(mode==1)
        {
          crown.attach(crow);
          pourShot(crown,"Shot of crown coming",off, crownCounter);
          crownCounter=crownCounter+50;
          crown.detach();
        }
        else if(mode==2)
        {
          vodka.attach(vod); 
          oj.attach(juc); 
          liquer.attach(liq);
          pourComplexDrink(vodka,liquer,oj,"Vodka-oj sour coming",off, vodCounter, liqCounter, jucCounter);
          vodCounter=vodCounter+50;
          jucCounter=jucCounter+80;
          liqCounter=liqCounter+100;
          vodka.detach();
          oj.detach();
          liquer.detach();
        }
      }
      lastButtonCrown = currentButtonCrown;  
      
      currentButtonLiq = debounce(lastButtonLiq, liqJuice);
      if (lastButtonLiq == LOW && currentButtonLiq == HIGH)
      {
        if(mode==0)
        {
          vodka.attach(vod); 
          rum.attach(rm);
          oj.attach(juc); 
          crown.attach(crow);  
          coke.attach(cok); 
          liquer.attach(liq);
          deathDrink(coke,oj,vodka,rum,crown,liquer,"Warning Death Drink!",off, liqCounter, jucCounter);
          liqCounter=liqCounter+100;
          vodCounter=vodCounter+100;
          rumCounter=rumCounter+100;
          crownCounter=crownCounter+100;
          cokeCounter=cokeCounter+100;
          jucCounter=jucCounter+100;
          vodka.detach(); 
          rum.detach();
          oj.detach(); 
          crown.detach();  
          coke.detach(); 
          liquer.detach();
        }
        else if(mode==1)
        {
          liquer.attach(liq);
          pourShot(liquer,"Sourpuss on the way",off, liqCounter);
          liqCounter=liqCounter+50;
          liquer.detach();
        }
        else if(mode==2)
        {
          vodka.attach(vod); 
          rum.attach(rm); 
          coke.attach(cok); 
          pourComplexDrink(vodka,rum,coke,"Vod-rum coke coming",169, vodCounter, rumCounter, cokeCounter);
          vodCounter=vodCounter+50;
          rumCounter=rumCounter+100;
          cokeCounter=cokeCounter+80;
          vodka.detach();
          rum.detach();
          coke.detach();
        }
      }
      lastButtonLiq = currentButtonLiq; 
      //mode
      currentButtonMode = debounce(lastButtonMode, modeButton);
      if (lastButtonMode == LOW && currentButtonMode == HIGH)
      {
          mode++;
          if(mode>=3)
            mode=0;
          if(mode==0)
          {
            lcd.clear();
            lcd.setCursor(0,3);
            lcd.print("Waseem's DrinkDroid");
            lcd.setCursor(0,0);
            lcd.print("Select a Drink");
          }
          if(mode==1)
          {
            lcd.clear();
            lcd.setCursor(0,3);
            lcd.print("Waseem's DrinkDroid");
            lcd.setCursor(0,0);
            lcd.print("Choose a Shot!");
            
          }
          if(mode==2)
          {
            lcd.clear();
            lcd.setCursor(0,3);
            lcd.print("Waseem's DrinkDroid");
            lcd.setCursor(0,0);
            lcd.print("Chase & more Drinks");
            
          }
      }
      lastButtonMode = currentButtonMode;
  } 
  
  boolean debounce(boolean last, int pin)
  {
    boolean current = digitalRead(pin);
    if (last != current)
    {
      delay(10);
      current = digitalRead(pin);
    }
    return current;
  }
  
  void pourDrink(Servo alc, Servo chase, String words, int sec, int alccounter, int chasecounter)
  {
          shot=alccounter;
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(words);
          lcd.setCursor(0,1);
          lcd.print("Mixing...");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(on);
          chase.write(on);
          delay(shot*2);
          alc.write(175);
          delay(chasecounter*3);
          chase.write(175);
          delay(500);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Select a drink");
          lcd.setCursor(0,2);
          lcd.print("Ready, go get drunk");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(sec);
          chase.write(off);
  }
  
  void pourShot(Servo alc, String words, int sec, int counter)
  {
          shot=counter;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(words);
          lcd.setCursor(0,1);
          lcd.print("Pouring...");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(on);
          delay(shot);
          alc.write(175);
          delay(500);
          alc.write(sec);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Select a shot");
          lcd.setCursor(0,2);
          lcd.print("Ready, go get drunk");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          
  }
    
  void pourComplexDrink(Servo alc, Servo liqu, Servo chase, String words,int sec, int alccounter,int liqcounter, int chasecounter)
  {
          shot=alccounter;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(words);
          lcd.setCursor(0,1);
          lcd.print("Mixing...");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(on);
          liqu.write(on);
          chase.write(on);
          delay(shot);
          alc.write(175);
          shot=liqcounter;
          delay(shot);
          liqu.write(175);
          delay(chasecounter*2);
          chase.write(175);
          delay(500);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Select a drink");
          lcd.setCursor(0,2);
          lcd.print("Ready, go get drunk");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(off);
          chase.write(off);
          liqu.write(sec);
          
  }
  
  void deathDrink(Servo alc, Servo chase, Servo vod, Servo rum, Servo crown, Servo liq, String words, int sec, int alccounter, int chasecounter)
  {
          shot=chasecounter;
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(words);
          lcd.setCursor(0,1);
          lcd.print("Mixing...");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(on);
          chase.write(on);
          delay(shot);
          alc.write(175);
          chase.write(175);
          delay(500);
          shot=alccounter;
          vod.write(on);
          rum.write(on);
          alc.write(off);
          chase.write(off);
          delay(shot);
          vod.write(175);
          rum.write(175);
          delay(500);
          crown.write(on);
          liq.write(on);
          vod.write(off);
          rum.write(off);
          delay(shot);
          crown.write(175);
          liq.write(175);
          delay(500);   
          crown.write(off);
          liq.write(off);       
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Select a drink");
          lcd.setCursor(0,2);
          lcd.print("Ready, go get drunk");
          lcd.setCursor(0,3);
          lcd.print("Waseem's DrinkDroid");
          alc.write(sec);
          chase.write(off);
  }
  
