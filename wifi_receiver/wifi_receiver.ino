void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Listening for lat,long");
}

int incoming = 0;

String serial_read = "";
float lat = 0.0;
float lon = 0.0;
void loop() {
  
  // put your main code here, to run repeatedly:
   incoming = Serial.available();

   while (incoming != 0) 
   {
     serial_read = Serial.readString();
     int split = serial_read.indexOf("\n");
     String lon_str = serial_read.substring(0,split);
     String lat_str = serial_read.substring(split+1, serial_read.length() - 1);
     lat = lat_str.toFloat();
     lon = lon_str.toFloat();
     
     
     incoming = Serial.available();
   }
   Serial.print(lat);
   Serial.println(lon);
}
