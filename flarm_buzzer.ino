// *****************************************
// ***	       PROYECTO FLARM		         ***
// *** 	      	 BUZZER TEST             ***
// ***   	         (v1.1)		             ***
// ***        AKAFLIEG MADRID            ***
// *** UNIVERSIDAD POLITECNICA DE MADRID ***
// *****************************************


// *** VARIABLES GLOBALES ***

  int relative_bearing = 50;           // Posicion relativa a la aeronave [-180,180]
  int relative_vertical = -100;        // Altura relativa a la aeronave
  int relative_horizontal = 350;       // Distancia horizontal relativa a la aeronave
  
  int zumbadores[6] = {2,3,4,5,6,7};   // Array pines de los zumbadores (6 uds)
  int notes[2] = {660, 990};  	       // Array de frecuencias para los zumbadores

  boolean flag_ac_detected = false;    // Flag activacion sistema de alerta sonora
  int buzzer_delay;    		             // Delay del zumbador en funcion del Relative Horizontal
  int zumbador;                        // Zumbador por donde pita
  boolean flag_2_buzzer = false;       // Flag para emision de alarma por dos zumbadores
  int freq;                            // Frecuencia que suena

// *** SETUP ***

  void setup(){

    Serial.begin(9600);

    pinMode(zumbadores[0], OUTPUT);	   // Zumbador 1
    pinMode(zumbadores[1], OUTPUT);	   // Zumbador 2
    pinMode(zumbadores[2], OUTPUT);	   // Zumbador 3
    pinMode(zumbadores[3], OUTPUT);	   // Zumbador 4
    pinMode(zumbadores[4], OUTPUT);	   // Zumbador 5
    pinMode(zumbadores[5], OUTPUT);	   // Zumbador 6

  }


// *** LOOP ***

  void loop() {

  // ANALISIS VERTICAL
  
    if (relative_vertical > 0) {

      Serial.println("Vertical analysis:    UP");
      Serial.print("Vertical distance:    ");
      Serial.print(relative_vertical);
      Serial.println(" m");
      Serial.println();

      freq = notes[1];

    }

    else {

      Serial.println("Vertcial analysis:    DOWN");
      Serial.print("Vertical distance:    ");
      Serial.print(relative_vertical);
      Serial.println(" m"); 
      Serial.println();
      
      freq = notes[0];
      
    }

  // ANALISIS ACIMUTAL

    if (relative_bearing > -15 && relative_bearing < 15) {

      Serial.println("Horizontal analysis:  -15 < x < 15");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();
      
      zumbador = 0;
      flag_2_buzzer = false;

    }

    else if (relative_bearing >= 15 && relative_bearing <= 45) {

      Serial.println("Horizontal analysis:  15 <= x <= 45");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 0;
      flag_2_buzzer = true;
      
    }

    else if (relative_bearing > 45 && relative_bearing < 75) {

      Serial.println("Horizontal analysis:  45 < x < 75");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();
      
      zumbador = 1;
      flag_2_buzzer = false;

    }

    else if (relative_bearing >= 75 && relative_bearing <= 105) {

      Serial.println("Horizontal analysis:  75 <= x <= 105");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 1;
      flag_2_buzzer = true;
      
    }

    else if (relative_bearing > 105 && relative_bearing < 135){

      Serial.println("Horizontal analysis:  105 < x < 135");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();
           
      zumbador = 2;
      flag_2_buzzer = false;
      
    }

    else if (relative_bearing >= 135 && relative_bearing <= 165){

      Serial.println("Horizontal analysis:  135 <= x <= 165");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 2;
      flag_2_buzzer = true;     
      
    }

    else if ((relative_bearing > 165 && relative_bearing <= 180) ||
    	     (relative_bearing < -165 & relative_bearing >= -180)){

      Serial.println("Horizontal analysis:  -165 < x < -180 or 165 < x < 180");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();
     
      zumbador = 3;
      flag_2_buzzer = false;
      
    }

    else if (relative_bearing >= -165 && relative_bearing <= -135){

      Serial.println("Horizontal analysis:  -165 < x < -135");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();
     
      zumbador = 3;
      flag_2_buzzer = true;
      
    }

    else if (relative_bearing > -135 && relative_bearing < -105){

      Serial.println("Horizontal analysis:  -135 < x < -105");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 4;
      flag_2_buzzer = false;

    }

    else if (relative_bearing >= -105 && relative_bearing <= -75){

      Serial.println("Horizontal analysis:  -105 < x < -75");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 4;
      flag_2_buzzer = true;
      
    }

    else if (relative_bearing > -75 && relative_bearing < -45){

      Serial.println("Horizontal analysis:  -75 < x < -45");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 5;
      flag_2_buzzer = false;

    }

    else if (relative_bearing >= -45 && relative_bearing <= -15){

      Serial.println("Horizontal analysis:  -45 < x < -15");
      Serial.print("Horizontal distance:    ");
      Serial.print(relative_horizontal);
      Serial.println(" m");
      Serial.println();

      zumbador = 5;
      flag_2_buzzer = true;
    }


  // ANALISIS HORIZONTAL

    if (relative_horizontal <= 500 && relative_horizontal > 250){
  
      buzzer_delay = 1000;  
      flag_ac_detected = true;
      
    }

    else if (relative_horizontal <= 250 && relative_horizontal > 100){

      buzzer_delay = 500; 
      flag_ac_detected = true;
      
    }

    else if (relative_horizontal <= 100 && relative_horizontal > 50){

      buzzer_delay = 100; 
      flag_ac_detected = true;
      
    }

    else if (relative_horizontal <= 50 ){

      buzzer_delay = 25; 
      flag_ac_detected = true;
      
    }

    else {
    
      flag_ac_detected = false;
      
    }

  // EMISION ALERTA SONORA

    if (flag_ac_detected == true){

      if (flag_2_buzzer == false){
 
        tone(zumbadores[zumbador], freq);
	      delay(buzzer_delay);
	
      }

      else if (flag_2_buzzer == true && zumbador != 5){

        tone(zumbadores[zumbador], freq);
	      delay(100);
	      tone(zumbadores[zumbador + 1], freq);
	      delay(buzzer_delay);

      }

      else if (flag_2_buzzer == true && zumbador == 5){

        tone(zumbadores[5], freq);
	      delay(100);
	      tone(zumbadores[0], freq);
	      delay(buzzer_delay);

      }

      else {

        noTone(zumbadores[zumbador]);

      }
    }
  }
