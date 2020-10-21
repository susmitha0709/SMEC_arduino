
const int  power_led = 2, power_switch = 3, led1 = 13, led2 = 12, led3 = 11, fn_switch = 10;
int  prev_sw2status = 0, pres_sw2status = 0, prev_sw1status = 0, pres_sw1status = 0, count = 0, led_status = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(power_led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(power_switch, INPUT);
  pinMode(fn_switch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   pres_sw2status = digitalRead(power_switch);
  if (prev_sw2status == 0 && pres_sw2status == 1)
  {
    led_status = (led_status == 1) ? 0 : 1 ;
    digitalWrite(power_led , led_status);
  }
  prev_sw2status=pres_sw2status;
  if(led_status==1){

  pres_sw1status= digitalRead(fn_switch);
  if(prev_sw1status==0 && pres_sw1status==1)
  {
    count++;
    switch(count){
      case 1: digitalWrite(led1,1);
      break;
      case 2: digitalWrite(led2,1);
      break;
      case 3: digitalWrite(led3,1);
      break;
      case 4: digitalWrite(led1,0);
              digitalWrite(led2,0);
              digitalWrite(led3,0);
              count=0;
              }
    
  }
  prev_sw1status=pres_sw1status;

  }
  if(led_status==0)
  {
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    count=0;
  }
}
