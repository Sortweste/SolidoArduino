
#define DS_pin 4
#define STCP_pin 5
#define SHCP_pin 6

#define ship 0
#define solidoA1 1
#define solidoA2 2

int solido[2]={solidoA1, solidoA2};

int barrido=0;

int Arreglo[16];
int contador=0;

int Matrix[3][4][4][4]=
{
  {
    {
      {1,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    } 
  },
  {
    {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}
    },
    {
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0},
      {0,0,0,0}
    }
  },
  {
    {
      {1,1,1,1},
      {1,0,0,1},
      {1,0,0,1},
      {1,1,1,1}
    },
    {
      {1,1,1,1},
      {1,0,0,1},
      {1,0,0,1},
      {1,1,1,1}
    },
    {
      {1,1,1,1},
      {1,0,0,1},
      {1,0,0,1},
      {1,1,1,1}
    },
    {
      {1,1,1,1},
      {1,0,0,1},
      {1,0,0,1},
      {1,1,1,1}
    } 
  },
};

void setup()
{
  for(int i=0; i<7;i++){
    pinMode(i, OUTPUT);
  }
}

void ShiftRegister(){
  digitalWrite(STCP_pin, LOW);
    for(int i=15; i>=0; i--){
      digitalWrite(SHCP_pin, LOW);
        digitalWrite(DS_pin, Arreglo[i]);
        digitalWrite(SHCP_pin, HIGH);
    }
    digitalWrite(STCP_pin, HIGH);
}

void limpiar(int Nivel){
    contador=0;
    for(int x=0; x<16;x++)
      Arreglo[x]=0;
    ShiftRegister();
    digitalWrite(Nivel, HIGH);
}

void SolidoRev(){
  for(int k=0;k<2; k++){
    barrido=0;
    do{
      barrido++;
      for(int Nivel=0; Nivel<4; Nivel++){
        for(int i=0; i<4; i++)
          for(int j=0; j<4; j++){
            Arreglo[contador]=Matrix[solido[k]][Nivel][i][j];
            contador++;
          }
        ShiftRegister();
        digitalWrite(Nivel, LOW);
        limpiar(Nivel);
      }
      ShiftRegister();
    }while(barrido<200);
  }
}

void loop()
{
  SolidoRev();
}
