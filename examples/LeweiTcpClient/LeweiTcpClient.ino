#include <SPI.h>
#include <Ethernet.h>
#include <LeweiTcpClient.h>
byte mac[] = {0x74,0x69,0x69,0x2D,0x30,0x31};

IPAddress ip(192,168,1, 15);
IPAddress mydns(8,8,8,8);
IPAddress gw(192,168,1,1);
IPAddress subnet(255,255,255,0);
#define LW_USERKEY "yourapikey"
#define LW_GATEWAY "01"
 
LeweiTcpClient *client;
void setup()
{
  Serial.begin(9600);
  //you can use 3 ways to init your network
  //1.simplest
  client = new LeweiTcpClient(LW_USERKEY, LW_GATEWAY);
  //2.set mac only
  //client = new LeweiTcpClient(LW_USERKEY, LW_GATEWAY,mac);
  //3.full setting for your network
  //client = new LeweiTcpClient(LW_USERKEY, LW_GATEWAY,mac,ip,mydns,gw,subnet);
  
  
  //test1 is the function you write below to handle your program
  //"testFunction" is the function name you set on website:http://www.lewei50.com/
  //on "controll command manager" menu
  //we test transfer 1-5 para from website(you defined on it) to your arduino
  //enjoy it
  
  UserFunction uf1(test1,"testFunction");
  client->addUserFunction(uf1);
  UserFunction uf2 (test2,"testFunction2");
  client->addUserFunction(uf2);
  UserFunction uf3 (test3,"testFunction3");
  client->addUserFunction(uf3);
  UserFunction uf4 (test4,"testFunction4");
  client->addUserFunction(uf4);
  UserFunction uf5 (test5,"testFunction5");
  client->addUserFunction(uf5);
  
}

void loop()
{
    client->keepOnline();
    
    //client->sendSensorValue("tcp1",129);
    //delay(1000);
}


//function test1 use 1 parameter,on the website,it point to "p1"
void test1(char * p1)
{
  client->setRevCtrlMsg("true","message to server");
  Serial.println("test function recall1");
  double pi = 3241.59;//*random(10);
  client->sendSensorValue("tcp1",pi);
  Serial.println(p1);
}
//function test2 use 2 parameter,on the website,it point to "p1,p2"
void test2(char * p1,char * p2)
{
  Serial.println("test function recall2");
  Serial.println(p1);
  client->sendSensorValue("tcp1",301);
  Serial.println(p2);
}
void test3(char * p1,char * p2,char * p3)
{
  Serial.println("test function recall3");
  Serial.println(p1);
  Serial.println(p2);
  Serial.println(p3);
}
void test4(char * p1,char * p2,char * p3,char * p4)
{
  Serial.println("test function recall4");
  Serial.println(p1);
  Serial.println(p2);
  Serial.println(p3);
  Serial.println(p4);
}
void test5(char * p1,char * p2,char * p3,char * p4,char * p5)
{
  Serial.println("test function recall5");
  Serial.println(p1);
  Serial.println(p2);
  Serial.println(p3);
  Serial.println(p4);
  Serial.println(p5);
}
